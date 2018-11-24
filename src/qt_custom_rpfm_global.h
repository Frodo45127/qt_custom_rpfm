#ifndef QT_CUSTOM_RPFM_GLOBAL_H
#define QT_CUSTOM_RPFM_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QT_CUSTOM_RPFM_LIBRARY)
#  define QT_CUSTOM_RPFMSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QT_CUSTOM_RPFMSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QT_CUSTOM_RPFM_GLOBAL_H