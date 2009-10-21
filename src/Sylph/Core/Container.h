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
 * Created on 10 oktober 2009, 15:37
 */

#ifndef CONTAINER_H_
#define	CONTAINER_H_

#include "Object.h"
#include "Primitives.h"

SYLPH_BEGIN_NAMESPACE
SYLPH_PUBLIC

template<class T, class I>
class Container : public virtual Object {
public:
    typedef T Type;
public:
    Container() {}
    Container(const Container&) {}
    virtual ~Container() {}
    virtual T& front() = 0;
    virtual const T& front() const = 0;
    virtual T& back() = 0;
    virtual const T& back() const = 0;
    virtual const T& get(idx_t) const = 0;
    virtual T& get(idx_t) = 0;
    virtual void put(idx_t, const T&) = 0;
    virtual void add(const T&) = 0;
    virtual size_t size() const = 0;
    size_t length() { return size(); }
    virtual bool empty() { return size() == 0; }

    virtual void clear() = 0;

    virtual T& operator[] const = 0;
    virtual const T& operator[] const = 0;
};
        
template<class T, class I>
class Sequence : public Container<T,I> {

};

template<class T, class I>
class FifoSequence : public virtual Sequence<T,I> {

};

template<class T, class I>
class LifoSequence : public virtual Sequence<T,I> {

};

template<class T, class I>
class DoubleEndedSequence : public FifoSequence<T,I>, public LifoSequence<T,I> {

};

SYLPH_END_NAMESPACE

#endif	/* CONTAINER_H_ */

