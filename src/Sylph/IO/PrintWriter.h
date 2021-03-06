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
 * Created on 30 juni 2009, 12:06
 */

#ifndef PRINTWRITER_H_
#define	PRINTWRITER_H_

#include "../Core/Primitives.h"
#include "../Core/String.h"
#include "OutputStream.h"

SYLPH_BEGIN_NAMESPACE
SYLPH_PUBLIC

class PrintWriter : public virtual Object {
    friend PrintWriter& dec(PrintWriter&);
    friend PrintWriter& hex(PrintWriter&);
    friend PrintWriter& oct(PrintWriter&);
private:
    enum NumberType {
        DEC,
        HEX,
        OCT
    };
    
public:
    PrintWriter(OutputStream& _out) : out(_out), _uc(false), _nt(DEC) {}

    OutputStream& outputStream();
    const OutputStream& outputStream() const;

    bool uppercase() const;
    void setUppercase(bool);

    bool toBool() const;

    PrintWriter& operator<<(bool b);
    PrintWriter& operator<<(char c);
    PrintWriter& operator<<(sint i);
    PrintWriter& operator<<(suint i);
    PrintWriter& operator<<(slong l);
    PrintWriter& operator<<(sulong l);
    PrintWriter& operator<<(float f);
    PrintWriter& operator<<(String s);
    PrintWriter& operator<<(PrintWriter&(*f)(PrintWriter&));
private:
    OutputStream& out;
    bool _uc;
    NumberType _nt;
};

PrintWriter& flush(PrintWriter&);
PrintWriter& endl(PrintWriter&);
PrintWriter& ends(PrintWriter&);
PrintWriter& dec(PrintWriter&);
PrintWriter& hex(PrintWriter&);
PrintWriter& oct(PrintWriter&);
PrintWriter& uppercase(PrintWriter&);
PrintWriter& nouppercase(PrintWriter&);

SYLPH_END_NAMESPACE

#endif	/* PRINTWRITER_H_ */

