#ifndef USERPAGEWIDGET_GLOBAL_H
#define USERPAGEWIDGET_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(USERPAGEWIDGET_LIBRARY)
#  define USERPAGEWIDGET_EXPORT Q_DECL_EXPORT
#else
#  define USERPAGEWIDGET_EXPORT Q_DECL_IMPORT
#endif

#endif // USERPAGEWIDGET_GLOBAL_H
