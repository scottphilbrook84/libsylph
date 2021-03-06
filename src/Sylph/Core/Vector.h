/*
 * LibSylph Class Library
 * Copyright (C) 2009 Frank "SeySayux" Erens <seysayux@gmail.com>
 * Copyright (C) 2010 Scott "ernieballsep" Philbrook <ernieballsep@gmail.com>
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
 * Created on 6 december 2008, 12:07
 */

#ifndef VECTOR_H_
#define	VECTOR_H_

#include "Array.h"
#include "Util.h"
#include "Equals.h"
#include "Iterator.h"

#include <vector>
#include <initializer_list>

SYLPH_BEGIN_NAMESPACE

SYLPH_PUBLIC

/**
 * @todo Write documentation!
 */
template<class T>
class Vector : public Object {
public:

    class iterator : public RandomAccessIterator<T, iterator> {
    public:
        typedef RandomAccessIterator<T, iterator> super;

        iterator(bool begin = false, Vector<T>* obj = NULL)
        : super(begin), _obj(obj) {
            _currentIndex = begin ? 0 : _obj->size() - 1;
        }

        iterator(bool begin = false, const Vector<T>* obj = NULL)
        : super(begin), _obj(const_cast<Vector<T>*> (obj)) {
            _currentIndex = begin ? 0 : _obj->size() - 1;
        }

        bool equals(const iterator& other) const {
            return _currentIndex == other._currentIndex &&
                    _obj == other._obj;
        }

        iterator(const iterator& other) {
            _currentIndex = other._currentIndex;
            _obj = other._obj;
        }

        typename super::reference current() const {
            return (*_obj)[_currentIndex];
        }

        bool hasNext() const {
            return _currentIndex < _obj->size() - 1;
        }

        void next() const {
            _currentIndex++;
        }

        bool hasPrevious() const {
            return _currentIndex > 0;
        }

        void previous() const {
            _currentIndex--;
        }

        idx_t currentIndex() const {
            return _currentIndex;
        }

        size_t length() const {
            return _obj->size() - 1;
        }
    private:
        mutable idx_t _currentIndex;
        Vector<T>* _obj;
    };

    S_ITERABLE(T)


    explicit Vector(std::size_t initialCount = 16) :
            elements((std::size_t)initialCount), _size(0) {
    }

    virtual ~Vector() {
    }

    void add(const T & t) {
        ensureCapacity(_size + 1);
        _size++;
        set(_size - 1, t);
    }

    void addAll(Vector<T> & c) {
        for (Vector<T>::iterator it = c.begin();
                it != c.end(); ++it) {
            add(*it);
        }
    }

    std::size_t capacity() const {
        return elements.length;
    }

    void clear() {
        _size = 0;
        elements.clear();
    }

    bool contains(const T & t) {
        return indexOf(t) != -1;
    }

    bool empty() {
        return _size == 0;
    }

    const T & get(std::size_t idx) const {
        try {
            checkIfOutOfBounds(idx);
            return elements[idx];
        }
        straced;
    }

    T & get(std::size_t idx) {
        try {
            checkIfOutOfBounds(idx);
            return elements[idx];
        }
        straced;
    }

    sidx_t indexOf(const T & t, std::idx_t idx = 0) {
        static Equals<T> equf;
        for (std::size_t i = idx; i < _size; i++) {
            if (equf(get(i), t)) {
                return i;
            }
        }
        return -1;
    }

    int lastIndexOf(const T & t) {
        return lastIndexOf(t, _size - 1);
    }

    sidx_t lastIndexOf(const T & t, std::size_t idx) {
        static Equals<T> equf;
        checkIfOutOfBounds(idx);
        for (std::size_t i = idx; i >= 0; i--) {
            if (equf(get(i), t)) {
                return i;
            }
        }
        return -1;
    }

    void remove(const T & t) {
        removeAt(indexOf(t));
    }

    void removeAt(std::size_t idx) {
        _size--;
        if (idx < (elements.length - 1))
            arraycopy(elements, idx + 1, elements, idx,
                elements.length - 1 - idx);
    }

    void set(std::size_t idx, const T & t) {
        try {
            checkIfOutOfBounds(idx);
            elements[idx] = t;
        }
        straced;
    }

    std::size_t size() const {
        return _size;
    }

    Array<T> toArray() const {
        Array<T> toReturn(size());
        for(idx_t i = 0; i < size(); ++i) {
            toReturn[i] = elements[i];
        }
        return toReturn;
    }

    bool operator==(const Vector<T> & c) const {
        if (_size != c.size()) return false;
        else {
            for (std::size_t x = 0; x < c.size(); x++) {
                if (get(x) != c.get(x)) return false;
            }
            return true;
        }
    }

    T & operator[](std::idx_t idx) {
        return get(idx);
    }

    const T & operator[](std::idx_t idx) const {
        return get(idx);
    }

    Vector& operator=(const Vector<T> & rhs) {
        elements = Array<T > (rhs.elements.length);
        _size = rhs.size();
        arraycopy(rhs.elements, 0, elements, 0, rhs.elements.length);
        return *this;
    }

private:
    Array<T> elements;
    std::size_t _size;

    void ensureCapacity(std::size_t capacity) {
        if (capacity > elements.length) {
            std::size_t newsize;
            newsize = elements.length << 1;
            Array<T> oldElements = elements;
            elements = Array<T > (newsize);
            arraycopy(oldElements, 0, elements, 0, oldElements.length);
        }
    }

    inline void checkIfOutOfBounds(std::size_t idx) {
        if (idx >= _size) sthrow(ArrayException, "Vector out of bounds");
    }

};



SYLPH_END_NAMESPACE
#endif	/* VECTOR_H_ */
