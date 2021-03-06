/*
 * LibSylph Class Library
 * Copyright (C) 2009 Frank "SeySayux" Erens <seysayux@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the LibSylph Pulbic License as published
 * by the LibSylph Developers; either version 1.0 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the LibSylph
 * Public License for more details.
 *
 * You should have received a copy of the LibSylph Public License
 * along with this Library, if not, contact the LibSylph Developers.
 *
 * Created on 9 november 2008, 11:48
 */

#ifndef APPLICATION_H_
#define	APPLICATION_H_

#include "Object.h"
#include "Array.h"
#include "String.h"

#include "AppType.h"

#include "../OS/GuessOS.h"


#define thisapp ::Sylph::Application::self_app

SYLPH_BEGIN_NAMESPACE

class ApplicationSelf;
class File;

template<class T> class Array;
class String;

SYLPH_PUBLIC

/**
 * Class representing an application. An application is any file containing
 * executable object code that can be directly invoked by the operating system
 * through a well-defined entry point. Probably the most famous example is the
 * @c thisapp instance of this class, a pointer to an Application object
 * representing the application accessing the pointer.<p>
 * It is not possible to directly instantiate an Application object. Future
 * releases may contain functions to create Application objects and run the
 * accompanying object code.
 */
class Application : public Object {
    friend class ApplicationSelf;
public:

    /**
     * Returns the location of the file containing the object code of the
     * application.<p>
     * In case the application for which the location is requested is
     * @c thisapp, he exact method used to determine the location is
     * platform-dependant and may fail. In this case, the value is either set
     * to an empty string or a garbage value. Depending on the implementation,
     * an error may be raised as well during initialisation.
     * @return the application's location.
     */
    const String location() {
        return _location;
    }

    static ApplicationSelf * self_app;

    /**
     * Initialize the current application. This function will give the correct
     * value to @c thisapp. Note that if you use int SylphMain(Array<String>)
     * as the entry point for your application (the default), you do not need
     * to call this function explicitly. Instead, it will be called for you
     * before the SylphMain function. Depending on the implementation, this
     * function may or may not set up other important resources.
     * @param argc The number of arguments passed to the entry point designated
     * by the platform.
     * @param argv An array of C strings containing the arguments passed to
     * the entry point designated by the platform. This array is expected to
     * have a length of argc or more. If argc is larger than the actual length
     * of argv, undefined behaviour may occur.
     * @param apple The so-called 'apple-vector', an array of chars unique to
     * the Mac OS X-platform. This array is used to determine the location of
     * the binary solely on the Mac platform and is the fourth argument to the
     * @c main entry function. On other platforms, this array may be substituted
     * by a @c null pointer. Substituting this array on the Mac platform for
     * anything else than the actual apple vector passed to the @c main function
     * may lead to undefined behaviour.
     * @param type An enumerated type representing the implementation to use
     * for resource retrieval.
     * @param name The name of the application. Used in debug messages and for
     * retrieving configuration files.
     */
    static void init(int argc, char * argv[], char * apple[], AppType type,
            String name);

protected:
    String _location;

private:
    Application();
    virtual ~Application();


};

/**
 * An Application representing the currently running application. You cannot
 * directly instantiate this class. You need to implement this classes' methods
 * and use Application::init for correct initialisation. The constant @c thisapp
 * is of the type ApplicationSelf. It contains some extra methods that are not
 * available for ordinary applications.
 */
class ApplicationSelf : public Application {
    friend class Application;
public:
    const String appName() {
        return _appName;
    }

    /**
     * Returns an enumerated type representing the implementation used to back
     * this ApplicationSelf. The returned value is set by Application::init.
     * @return an enumeration corresponding to the implementation of
     * ApplicationSelf used.
     */
    AppType appType();

    void fail(const String reason, bool exit = true);
    void fail(const String reason, const String file, unsigned int line,
        bool exit = true);


    virtual const File& bundle() = 0;
    virtual const File& resourceDir() = 0;
    virtual const File resource(String rsc) = 0;
    virtual const File& libraryDir() = 0;
    virtual const File& pluginDir() = 0;
    virtual const File& plugindisabledDir() = 0;

    virtual const File& systemLibraryDir() = 0;
    virtual const File& systemSettings() = 0;
    virtual const File& systemSettingsDir() = 0;
    virtual const File& systemPluginDir() = 0;
    virtual const File& systemPluginDisabledDir() = 0;
    virtual const File& systemResourceDir() = 0;
    virtual const File systemResource(String rsc) = 0;

    virtual const File& userHome() = 0;

    virtual const File& userLibraryDir() = 0;
    virtual const File& userSettings() = 0;
    virtual const File& userSettingsDir() = 0;
    virtual const File& userPluginDir() = 0;
    virtual const File& userPluginDisabledDir() = 0;
    virtual const File& userResourceDir() = 0;
    virtual const File userResource(String rsc) = 0;

    virtual const File& prefix() = 0;

protected:
    ApplicationSelf() {
        _preconstruct();
    }
    virtual ~ApplicationSelf();

    void _fail(const String appName, const String reason, bool exit = true);
    void _fail(const String appName, const String reason,
            const String file, unsigned int line, bool exit = true);

private:
    void _preconstruct();
    String _appName;
    AppType _appType;


};

SYLPH_END_NAMESPACE

#endif	/* APPLICATION_H_ */

