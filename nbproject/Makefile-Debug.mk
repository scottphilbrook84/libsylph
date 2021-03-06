#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/test/String.o \
	${OBJECTDIR}/src/Sylph/OS/MacOSAppSelf.o \
	${OBJECTDIR}/src/Sylph/IO/PrintWriter.o \
	${OBJECTDIR}/src/Sylph/Core/Object.o \
	${OBJECTDIR}/src/Sylph/IO/BufferedInputStream.o \
	${OBJECTDIR}/src/Sylph/IO/BufferedOutputStream.o \
	${OBJECTDIR}/src/Sylph/OS/MacOSFHSAppSelf.o \
	${OBJECTDIR}/src/Sylph/OS/LinuxBundleAppSelf.o \
	${OBJECTDIR}/src/Sylph/Core/ByteBuffer.o \
	${OBJECTDIR}/test/Array.o \
	${OBJECTDIR}/src/Sylph/OS/LinuxFHSAppSelf.o \
	${OBJECTDIR}/src/Sylph/IO/FileInputStream.o \
	${OBJECTDIR}/src/Sylph/Core/Application.o \
	${OBJECTDIR}/src/Sylph/Core/Array.o \
	${OBJECTDIR}/src/Sylph/Core/HashMap.o \
	${OBJECTDIR}/test/Vector.o \
	${OBJECTDIR}/src/Sylph/IO/FileOutputStream.o \
	${OBJECTDIR}/src/Sylph/Core/UncaughtExceptionHandler.o \
	${OBJECTDIR}/test/Application.o \
	${OBJECTDIR}/src/Sylph/Core/String.o \
	${OBJECTDIR}/test/main.o \
	${OBJECTDIR}/src/Sylph/Core/Vector.o \
	${OBJECTDIR}/src/Sylph/Core/File.o \
	${OBJECTDIR}/test/HashMap.o \
	${OBJECTDIR}/src/Sylph/Core/StringBuffer.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=c++0x
CXXFLAGS=-std=c++0x

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-Llib -lboost -lcord -lgc -lpthread -lbinreloc

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/libsylph.so

dist/Debug/GNU-Linux-x86/libsylph.so: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.cc} -shared -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsylph.so -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/test/String.o: nbproject/Makefile-${CND_CONF}.mk test/String.cpp 
	${MKDIR} -p ${OBJECTDIR}/test
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/test/String.o test/String.cpp

${OBJECTDIR}/src/Sylph/OS/MacOSAppSelf.o: nbproject/Makefile-${CND_CONF}.mk src/Sylph/OS/MacOSAppSelf.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Sylph/OS
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Sylph/OS/MacOSAppSelf.o src/Sylph/OS/MacOSAppSelf.cpp

${OBJECTDIR}/src/Sylph/IO/PrintWriter.o: nbproject/Makefile-${CND_CONF}.mk src/Sylph/IO/PrintWriter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Sylph/IO
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Sylph/IO/PrintWriter.o src/Sylph/IO/PrintWriter.cpp

${OBJECTDIR}/src/Sylph/Core/Object.o: nbproject/Makefile-${CND_CONF}.mk src/Sylph/Core/Object.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Sylph/Core
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Sylph/Core/Object.o src/Sylph/Core/Object.cpp

${OBJECTDIR}/src/Sylph/IO/BufferedInputStream.o: nbproject/Makefile-${CND_CONF}.mk src/Sylph/IO/BufferedInputStream.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Sylph/IO
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Sylph/IO/BufferedInputStream.o src/Sylph/IO/BufferedInputStream.cpp

${OBJECTDIR}/src/Sylph/IO/BufferedOutputStream.o: nbproject/Makefile-${CND_CONF}.mk src/Sylph/IO/BufferedOutputStream.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Sylph/IO
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Sylph/IO/BufferedOutputStream.o src/Sylph/IO/BufferedOutputStream.cpp

${OBJECTDIR}/src/Sylph/OS/MacOSFHSAppSelf.o: nbproject/Makefile-${CND_CONF}.mk src/Sylph/OS/MacOSFHSAppSelf.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Sylph/OS
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Sylph/OS/MacOSFHSAppSelf.o src/Sylph/OS/MacOSFHSAppSelf.cpp

${OBJECTDIR}/src/Sylph/OS/LinuxBundleAppSelf.o: nbproject/Makefile-${CND_CONF}.mk src/Sylph/OS/LinuxBundleAppSelf.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Sylph/OS
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Sylph/OS/LinuxBundleAppSelf.o src/Sylph/OS/LinuxBundleAppSelf.cpp

${OBJECTDIR}/src/Sylph/Core/ByteBuffer.o: nbproject/Makefile-${CND_CONF}.mk src/Sylph/Core/ByteBuffer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Sylph/Core
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Sylph/Core/ByteBuffer.o src/Sylph/Core/ByteBuffer.cpp

${OBJECTDIR}/test/Array.o: nbproject/Makefile-${CND_CONF}.mk test/Array.cpp 
	${MKDIR} -p ${OBJECTDIR}/test
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/test/Array.o test/Array.cpp

${OBJECTDIR}/src/Sylph/OS/LinuxFHSAppSelf.o: nbproject/Makefile-${CND_CONF}.mk src/Sylph/OS/LinuxFHSAppSelf.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Sylph/OS
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Sylph/OS/LinuxFHSAppSelf.o src/Sylph/OS/LinuxFHSAppSelf.cpp

${OBJECTDIR}/src/Sylph/IO/FileInputStream.o: nbproject/Makefile-${CND_CONF}.mk src/Sylph/IO/FileInputStream.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Sylph/IO
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Sylph/IO/FileInputStream.o src/Sylph/IO/FileInputStream.cpp

${OBJECTDIR}/src/Sylph/Core/Application.o: nbproject/Makefile-${CND_CONF}.mk src/Sylph/Core/Application.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Sylph/Core
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Sylph/Core/Application.o src/Sylph/Core/Application.cpp

${OBJECTDIR}/src/Sylph/Core/Array.o: nbproject/Makefile-${CND_CONF}.mk src/Sylph/Core/Array.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Sylph/Core
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Sylph/Core/Array.o src/Sylph/Core/Array.cpp

${OBJECTDIR}/src/Sylph/Core/HashMap.o: nbproject/Makefile-${CND_CONF}.mk src/Sylph/Core/HashMap.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Sylph/Core
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Sylph/Core/HashMap.o src/Sylph/Core/HashMap.cpp

${OBJECTDIR}/test/Vector.o: nbproject/Makefile-${CND_CONF}.mk test/Vector.cpp 
	${MKDIR} -p ${OBJECTDIR}/test
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/test/Vector.o test/Vector.cpp

${OBJECTDIR}/src/Sylph/IO/FileOutputStream.o: nbproject/Makefile-${CND_CONF}.mk src/Sylph/IO/FileOutputStream.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Sylph/IO
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Sylph/IO/FileOutputStream.o src/Sylph/IO/FileOutputStream.cpp

${OBJECTDIR}/src/Sylph/Core/UncaughtExceptionHandler.o: nbproject/Makefile-${CND_CONF}.mk src/Sylph/Core/UncaughtExceptionHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Sylph/Core
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Sylph/Core/UncaughtExceptionHandler.o src/Sylph/Core/UncaughtExceptionHandler.cpp

${OBJECTDIR}/test/Application.o: nbproject/Makefile-${CND_CONF}.mk test/Application.cpp 
	${MKDIR} -p ${OBJECTDIR}/test
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/test/Application.o test/Application.cpp

${OBJECTDIR}/src/Sylph/Core/String.o: nbproject/Makefile-${CND_CONF}.mk src/Sylph/Core/String.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Sylph/Core
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Sylph/Core/String.o src/Sylph/Core/String.cpp

${OBJECTDIR}/test/main.o: nbproject/Makefile-${CND_CONF}.mk test/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/test
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/test/main.o test/main.cpp

${OBJECTDIR}/src/Sylph/Core/Vector.o: nbproject/Makefile-${CND_CONF}.mk src/Sylph/Core/Vector.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Sylph/Core
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Sylph/Core/Vector.o src/Sylph/Core/Vector.cpp

${OBJECTDIR}/src/Sylph/Core/File.o: nbproject/Makefile-${CND_CONF}.mk src/Sylph/Core/File.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Sylph/Core
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Sylph/Core/File.o src/Sylph/Core/File.cpp

${OBJECTDIR}/test/HashMap.o: nbproject/Makefile-${CND_CONF}.mk test/HashMap.cpp 
	${MKDIR} -p ${OBJECTDIR}/test
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/test/HashMap.o test/HashMap.cpp

${OBJECTDIR}/src/Sylph/Core/StringBuffer.o: nbproject/Makefile-${CND_CONF}.mk src/Sylph/Core/StringBuffer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Sylph/Core
	${RM} $@.d
	$(COMPILE.cc) -g -DSYLPH_DEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Sylph/Core/StringBuffer.o src/Sylph/Core/StringBuffer.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/libsylph.so

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
