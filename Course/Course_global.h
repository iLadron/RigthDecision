#ifndef COURSE_GLOBAL_H
#define COURSE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(COURSE_LIBRARY)
#  define COURSE_EXPORT Q_DECL_EXPORT
#else
#  define COURSE_EXPORT Q_DECL_IMPORT
#endif

#endif // COURSE_GLOBAL_H
