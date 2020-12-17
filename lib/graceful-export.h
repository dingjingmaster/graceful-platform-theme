#ifndef GRACEFULEXPORT_H
#define GRACEFULEXPORT_H
#include "csyslog.h"

#if defined(_WIN32)
#define GRACEFUL_EXPORT     __declspec(dllexport)
#elif defined(__GNUC__)
#define GRACEFUL_EXPORT     __attribute__((visibility("default")))
#else
#define GRACEFUL_EXPORT
#endif

#ifndef GRACEFUL_NO_EXPORT
#define GRACEFUL_NO_EXPORT  __attribute__((visibility("hidden")))
#endif

#ifndef GRACEFUL_DEPRECATED
#define GRACEFUL_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef GRACEFUL_DEPRECATED_EXPORT
#define GRACEFUL_DEPRECATED_EXPORT      GRACEFUL_EXPORT     GRACEFUL_DEPRECATED
#endif

#ifndef GRACEFUL_DEPRECATED_NO_EXPORT
#define GRACEFUL_DEPRECATED_NO_EXPORT   GRACEFUL_NO_EXPORT  GRACEFUL_DEPRECATED
#endif



#endif // GRACEFULEXPORT_H
