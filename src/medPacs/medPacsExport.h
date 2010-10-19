/* medPacsExport.h --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Wed Oct 21 15:14:27 2009 (+0200)
 * Version: $Id$
 * Last-Updated: Wed Oct 21 15:14:45 2009 (+0200)
 *           By: Julien Wintz
 *     Update #: 2
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#ifdef WIN32
    #ifdef medPacs_EXPORTS
        #define MEDPACS_EXPORT __declspec(dllexport) 
    #else
        #define MEDPACS_EXPORT __declspec(dllimport) 
    #endif
#else
    #define MEDPACS_EXPORT
#endif