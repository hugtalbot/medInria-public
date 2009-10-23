/* medCore.i --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Sat Oct  3 18:27:33 2009 (+0200)
 * Version: $Id$
 * Last-Updated: Sat Oct  3 18:56:14 2009 (+0200)
 *           By: Julien Wintz
 *     Update #: 6
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#ifndef MEDCORE_I
#define MEDCORE_I

%module medcore
%{
#include <QtDebug>
#include <QtCore>

#include <medCore/medAbstractDataImage.h>
%}

// /////////////////////////////////////////////////////////////////
// Preprocessing setup
// /////////////////////////////////////////////////////////////////

// 401:
// 509:
// 801:
#pragma SWIG nowarn=401, 509, 801, 472

// /////////////////////////////////////////////////////////////////
// Macro undefinition
// /////////////////////////////////////////////////////////////////

#undef Q_OBJECT
#undef signals
#undef slots

#define Q_OBJECT
#define signals public
#define slots

#undef  Q_PROPERTY(Type type MODE mode)
#define Q_PROPERTY(Type type MODE mode)

#undef  Q_DECLARE_INTERFACE(IFace, IId)
#define Q_DECLARE_INTERFACE(IFace, IId)

#undef  MEDCORE_EXPORT
#define MEDCORE_EXPORT

// /////////////////////////////////////////////////////////////////
// Ignore rules for operators
// /////////////////////////////////////////////////////////////////

%ignore operator<<;
%ignore operator==;

// /////////////////////////////////////////////////////////////////
// Typemaps
// /////////////////////////////////////////////////////////////////

#ifdef SWIGPYTHON

%typecheck(SWIG_TYPECHECK_STRING) char * {
  $1 = PyString_Check($input) ? 1 : 0;
}

%typemap(typecheck) QString = char *;

%typemap(in) QString { // Python -> C++
    if (PyString_Check($input)) {
         $1 = QString(PyString_AsString($input));
     } else {
         qDebug("QString expected");
     }
}

%typemap(out) QString { // C++ -> Python
    $result = PyString_FromString($1.toAscii().constData());
}
#elif SWIGTCL
%typemap(in) QString { // Tcl -> C++
    $1 = QString(Tcl_GetString($input));
}

%typemap(out) QString { // C++ -> Tcl
    Tcl_SetStringObj($result, $1.toAscii().constData(), $1.size());
}
#endif

// /////////////////////////////////////////////////////////////////
// Wrapper input
// /////////////////////////////////////////////////////////////////

%include "medAbstractDataImage.h"

#endif