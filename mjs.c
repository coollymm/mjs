#include "mjs.h"
#ifdef MJS_MODULE_LINES
#line 1 "common/platform.h"
#endif
#ifndef CS_COMMON_PLATFORM_H_
#define CS_COMMON_PLATFORM_H_

/*
 * For the "custom" platform, includes and dependencies can be
 * provided through mg_locals.h.
 */
#define CS_P_CUSTOM 0
#define CS_P_UNIX 1
#define CS_P_WINDOWS 2
#define CS_P_ESP32 15
#define CS_P_ESP8266 3
#define CS_P_CC3200 4
#define CS_P_MSP432 5
#define CS_P_CC3100 6
#define CS_P_TM4C129 14
#define CS_P_MBED 7
#define CS_P_WINCE 8
#define CS_P_NXP_LPC 13
#define CS_P_NXP_KINETIS 9
#define CS_P_NRF51 12
#define CS_P_NRF52 10
#define CS_P_PIC32 11
#define CS_P_STM32 16
/* Next id: 17 */

/* If not specified explicitly, we guess platform by defines. */
#ifndef CS_PLATFORM

#if defined(TARGET_IS_MSP432P4XX) || defined(__MSP432P401R__)
#define CS_PLATFORM CS_P_MSP432
#elif defined(cc3200)
#define CS_PLATFORM CS_P_CC3200
#elif defined(__unix__) || defined(__APPLE__)
#define CS_PLATFORM CS_P_UNIX
#elif defined(WINCE)
#define CS_PLATFORM CS_P_WINCE
#elif defined(_WIN32)
#define CS_PLATFORM CS_P_WINDOWS
#elif defined(__MBED__)
#define CS_PLATFORM CS_P_MBED
#elif defined(__USE_LPCOPEN)
#define CS_PLATFORM CS_P_NXP_LPC
#elif defined(FRDM_K64F) || defined(FREEDOM)
#define CS_PLATFORM CS_P_NXP_KINETIS
#elif defined(PIC32)
#define CS_PLATFORM CS_P_PIC32
#elif defined(ESP_PLATFORM)
#define CS_PLATFORM CS_P_ESP32
#elif defined(ICACHE_FLASH)
#define CS_PLATFORM CS_P_ESP8266
#elif defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define CS_PLATFORM CS_P_TM4C129
#elif defined(STM32)
#define CS_PLATFORM CS_P_STM32
#endif

#ifndef CS_PLATFORM
#error "CS_PLATFORM is not specified and we couldn't guess it."
#endif

#endif /* !defined(CS_PLATFORM) */

#define MG_NET_IF_SOCKET 1
#define MG_NET_IF_SIMPLELINK 2
#define MG_NET_IF_LWIP_LOW_LEVEL 3
#define MG_NET_IF_PIC32 4

#define MG_SSL_IF_OPENSSL 1
#define MG_SSL_IF_MBEDTLS 2
#define MG_SSL_IF_SIMPLELINK 3

/* Amalgamated: #include "common/platforms/platform_unix.h" */
/* Amalgamated: #include "common/platforms/platform_windows.h" */
/* Amalgamated: #include "common/platforms/platform_esp32.h" */
/* Amalgamated: #include "common/platforms/platform_esp8266.h" */
/* Amalgamated: #include "common/platforms/platform_cc3200.h" */
/* Amalgamated: #include "common/platforms/platform_cc3100.h" */
/* Amalgamated: #include "common/platforms/platform_mbed.h" */
/* Amalgamated: #include "common/platforms/platform_nrf51.h" */
/* Amalgamated: #include "common/platforms/platform_nrf52.h" */
/* Amalgamated: #include "common/platforms/platform_wince.h" */
/* Amalgamated: #include "common/platforms/platform_nxp_lpc.h" */
/* Amalgamated: #include "common/platforms/platform_nxp_kinetis.h" */
/* Amalgamated: #include "common/platforms/platform_pic32.h" */
/* Amalgamated: #include "common/platforms/platform_stm32.h" */

/* Common stuff */

#if !defined(WEAK)
#if (defined(__GNUC__) || defined(__TI_COMPILER_VERSION__)) && !defined(_WIN32)
#define WEAK __attribute__((weak))
#else
#define WEAK
#endif
#endif

#ifdef __GNUC__
#define NORETURN __attribute__((noreturn))
#define NOINLINE __attribute__((noinline))
#define WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#define NOINSTR __attribute__((no_instrument_function))
#define DO_NOT_WARN_UNUSED __attribute__((unused))
#else
#define NORETURN
#define NOINLINE
#define WARN_UNUSED_RESULT
#define NOINSTR
#define DO_NOT_WARN_UNUSED
#endif /* __GNUC__ */

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))
#endif

#endif /* CS_COMMON_PLATFORM_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "common/platforms/platform_windows.h"
#endif
#ifndef CS_COMMON_PLATFORMS_PLATFORM_WINDOWS_H_
#define CS_COMMON_PLATFORMS_PLATFORM_WINDOWS_H_
#if CS_PLATFORM == CS_P_WINDOWS

/*
 * MSVC++ 14.0 _MSC_VER == 1900 (Visual Studio 2015)
 * MSVC++ 12.0 _MSC_VER == 1800 (Visual Studio 2013)
 * MSVC++ 11.0 _MSC_VER == 1700 (Visual Studio 2012)
 * MSVC++ 10.0 _MSC_VER == 1600 (Visual Studio 2010)
 * MSVC++ 9.0  _MSC_VER == 1500 (Visual Studio 2008)
 * MSVC++ 8.0  _MSC_VER == 1400 (Visual Studio 2005)
 * MSVC++ 7.1  _MSC_VER == 1310 (Visual Studio 2003)
 * MSVC++ 7.0  _MSC_VER == 1300
 * MSVC++ 6.0  _MSC_VER == 1200
 * MSVC++ 5.0  _MSC_VER == 1100
 */
#ifdef _MSC_VER
#pragma warning(disable : 4127) /* FD_SET() emits warning, disable it */
#pragma warning(disable : 4204) /* missing c99 support */
#endif

#ifndef _WINSOCK_DEPRECATED_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1
#endif

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <assert.h>
#include <direct.h>
#include <errno.h>
#include <fcntl.h>
#include <io.h>
#include <limits.h>
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <ctype.h>

#ifdef _MSC_VER
#pragma comment(lib, "ws2_32.lib") /* Linking with winsock library */
#endif

#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <process.h>

#if defined(_MSC_VER) && _MSC_VER >= 1800
#define strdup _strdup
#endif

#ifndef EINPROGRESS
#define EINPROGRESS WSAEINPROGRESS
#endif
#ifndef EWOULDBLOCK
#define EWOULDBLOCK WSAEWOULDBLOCK
#endif
#ifndef __func__
#define STRX(x) #x
#define STR(x) STRX(x)
#define __func__ __FILE__ ":" STR(__LINE__)
#endif
#define snprintf _snprintf
#define vsnprintf _vsnprintf
#define sleep(x) Sleep((x) *1000)
#define to64(x) _atoi64(x)
#if !defined(__MINGW32__) && !defined(__MINGW64__)
#define popen(x, y) _popen((x), (y))
#define pclose(x) _pclose(x)
#define fileno _fileno
#endif
#define rmdir _rmdir
#if defined(_MSC_VER) && _MSC_VER >= 1400
#define fseeko(x, y, z) _fseeki64((x), (y), (z))
#else
#define fseeko(x, y, z) fseek((x), (y), (z))
#endif
#if defined(_MSC_VER) && _MSC_VER <= 1200
typedef unsigned long uintptr_t;
typedef long intptr_t;
#endif
typedef int socklen_t;
#if _MSC_VER >= 1700
#include <stdint.h>
#else
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#endif
typedef SOCKET sock_t;
typedef uint32_t in_addr_t;
#ifndef UINT16_MAX
#define UINT16_MAX 65535
#endif
#ifndef UINT32_MAX
#define UINT32_MAX 4294967295
#endif
#ifndef pid_t
#define pid_t HANDLE
#endif
#define INT64_FMT "I64d"
#define INT64_X_FMT "I64x"
#define SIZE_T_FMT "Iu"
typedef struct _stati64 cs_stat_t;
#ifndef S_ISDIR
#define S_ISDIR(x) (((x) &_S_IFMT) == _S_IFDIR)
#endif
#ifndef S_ISREG
#define S_ISREG(x) (((x) &_S_IFMT) == _S_IFREG)
#endif
#define DIRSEP '\\'
#define CS_DEFINE_DIRENT

#ifndef va_copy
#ifdef __va_copy
#define va_copy __va_copy
#else
#define va_copy(x, y) (x) = (y)
#endif
#endif

#ifndef MG_MAX_HTTP_REQUEST_SIZE
#define MG_MAX_HTTP_REQUEST_SIZE 8192
#endif

#ifndef MG_MAX_HTTP_SEND_MBUF
#define MG_MAX_HTTP_SEND_MBUF 4096
#endif

#ifndef MG_MAX_HTTP_HEADERS
#define MG_MAX_HTTP_HEADERS 40
#endif

#ifndef CS_ENABLE_STDIO
#define CS_ENABLE_STDIO 1
#endif

#ifndef MG_ENABLE_BROADCAST
#define MG_ENABLE_BROADCAST 1
#endif

#ifndef MG_ENABLE_DIRECTORY_LISTING
#define MG_ENABLE_DIRECTORY_LISTING 1
#endif

#ifndef MG_ENABLE_FILESYSTEM
#define MG_ENABLE_FILESYSTEM 1
#endif

#ifndef MG_ENABLE_HTTP_CGI
#define MG_ENABLE_HTTP_CGI MG_ENABLE_FILESYSTEM
#endif

#ifndef MG_NET_IF
#define MG_NET_IF MG_NET_IF_SOCKET
#endif

#endif /* CS_PLATFORM == CS_P_WINDOWS */
#endif /* CS_COMMON_PLATFORMS_PLATFORM_WINDOWS_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "common/platforms/platform_unix.h"
#endif
#ifndef CS_COMMON_PLATFORMS_PLATFORM_UNIX_H_
#define CS_COMMON_PLATFORMS_PLATFORM_UNIX_H_
#if CS_PLATFORM == CS_P_UNIX

#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 600
#endif

/* <inttypes.h> wants this for C++ */
#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS
#endif

/* C++ wants that for INT64_MAX */
#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS
#endif

/* Enable fseeko() and ftello() functions */
#ifndef _LARGEFILE_SOURCE
#define _LARGEFILE_SOURCE
#endif

/* Enable 64-bit file offsets */
#ifndef _FILE_OFFSET_BITS
#define _FILE_OFFSET_BITS 64
#endif

#include <arpa/inet.h>
#include <assert.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>
#include <netdb.h>
#include <netinet/in.h>
#include <pthread.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#ifdef __APPLE__
#include <machine/endian.h>
#ifndef BYTE_ORDER
#define LITTLE_ENDIAN __DARWIN_LITTLE_ENDIAN
#define BIG_ENDIAN __DARWIN_BIG_ENDIAN
#define PDP_ENDIAN __DARWIN_PDP_ENDIAN
#define BYTE_ORDER __DARWIN_BYTE_ORDER
#endif
#endif

/*
 * osx correctly avoids defining strtoll when compiling in strict ansi mode.
 * c++ 11 standard defines strtoll as well.
 * We require strtoll, and if your embedded pre-c99 compiler lacks one, please
 * implement a shim.
 */
#if !(defined(__cplusplus) && __cplusplus >= 201103L) && \
    !(defined(__DARWIN_C_LEVEL) && __DARWIN_C_LEVEL >= 200809L)
long long strtoll(const char *, char **, int);
#endif

typedef int sock_t;
#define INVALID_SOCKET (-1)
#define SIZE_T_FMT "zu"
typedef struct stat cs_stat_t;
#define DIRSEP '/'
#define to64(x) strtoll(x, NULL, 10)
#define INT64_FMT PRId64
#define INT64_X_FMT PRIx64

#ifndef __cdecl
#define __cdecl
#endif

#ifndef va_copy
#ifdef __va_copy
#define va_copy __va_copy
#else
#define va_copy(x, y) (x) = (y)
#endif
#endif

#define closesocket(x) close(x)

#ifndef MG_MAX_HTTP_REQUEST_SIZE
#define MG_MAX_HTTP_REQUEST_SIZE 8192
#endif

#ifndef MG_MAX_HTTP_SEND_MBUF
#define MG_MAX_HTTP_SEND_MBUF 4096
#endif

#ifndef MG_MAX_HTTP_HEADERS
#define MG_MAX_HTTP_HEADERS 40
#endif

#ifndef CS_ENABLE_STDIO
#define CS_ENABLE_STDIO 1
#endif

#ifndef MG_ENABLE_BROADCAST
#define MG_ENABLE_BROADCAST 1
#endif

#ifndef MG_ENABLE_DIRECTORY_LISTING
#define MG_ENABLE_DIRECTORY_LISTING 1
#endif

#ifndef MG_ENABLE_FILESYSTEM
#define MG_ENABLE_FILESYSTEM 1
#endif

#ifndef MG_ENABLE_HTTP_CGI
#define MG_ENABLE_HTTP_CGI MG_ENABLE_FILESYSTEM
#endif

#ifndef MG_NET_IF
#define MG_NET_IF MG_NET_IF_SOCKET
#endif

#endif /* CS_PLATFORM == CS_P_UNIX */
#endif /* CS_COMMON_PLATFORMS_PLATFORM_UNIX_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "common/platforms/platform_esp32.h"
#endif
/*
 * Copyright (c) 2014-2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef CS_COMMON_PLATFORMS_PLATFORM_ESP32_H_
#define CS_COMMON_PLATFORMS_PLATFORM_ESP32_H_
#if CS_PLATFORM == CS_P_ESP32

#include <assert.h>
#include <ctype.h>
#include <dirent.h>
#include <fcntl.h>
#include <inttypes.h>
#include <machine/endian.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>

#define SIZE_T_FMT "u"
typedef struct stat cs_stat_t;
#define DIRSEP '/'
#define to64(x) strtoll(x, NULL, 10)
#define INT64_FMT PRId64
#define INT64_X_FMT PRIx64
#define __cdecl
#define _FILE_OFFSET_BITS 32

#define MG_LWIP 1

#ifndef MG_NET_IF
#define MG_NET_IF MG_NET_IF_SOCKET
#endif

#ifndef CS_ENABLE_STDIO
#define CS_ENABLE_STDIO 1
#endif

#endif /* CS_PLATFORM == CS_P_ESP32 */
#endif /* CS_COMMON_PLATFORMS_PLATFORM_ESP32_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "common/platforms/platform_esp8266.h"
#endif
/*
 * Copyright (c) 2014-2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef CS_COMMON_PLATFORMS_PLATFORM_ESP8266_H_
#define CS_COMMON_PLATFORMS_PLATFORM_ESP8266_H_
#if CS_PLATFORM == CS_P_ESP8266

#include <assert.h>
#include <ctype.h>
#include <fcntl.h>
#include <inttypes.h>
#include <machine/endian.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>

#define SIZE_T_FMT "u"
typedef struct stat cs_stat_t;
#define DIRSEP '/'
#define CS_DEFINE_DIRENT

#define to64(x) strtoll(x, NULL, 10)
#define INT64_FMT PRId64
#define INT64_X_FMT PRIx64
#define __cdecl
#define _FILE_OFFSET_BITS 32

#ifndef RTOS_SDK
#define fileno(x) -1
#endif

#define MG_LWIP 1

/* struct timeval is defined in sys/time.h. */
#define LWIP_TIMEVAL_PRIVATE 0

#ifndef MG_NET_IF
#include <lwip/opt.h>
#if LWIP_SOCKET /* RTOS SDK has LWIP sockets */
#  define MG_NET_IF MG_NET_IF_SOCKET
#else
#  define MG_NET_IF MG_NET_IF_LWIP_LOW_LEVEL
#endif
#endif

#ifndef CS_ENABLE_STDIO
#define CS_ENABLE_STDIO 1
#endif

#endif /* CS_PLATFORM == CS_P_ESP8266 */
#endif /* CS_COMMON_PLATFORMS_PLATFORM_ESP8266_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "common/platforms/simplelink/cs_simplelink.h"
#endif
/*
 * Copyright (c) 2014-2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef CS_COMMON_PLATFORMS_SIMPLELINK_CS_SIMPLELINK_H_
#define CS_COMMON_PLATFORMS_SIMPLELINK_CS_SIMPLELINK_H_

/* If simplelink.h is already included, all bets are off. */
#if defined(MG_NET_IF) && MG_NET_IF == MG_NET_IF_SIMPLELINK && \
    !defined(__SIMPLELINK_H__)

#include <stdbool.h>

#ifndef __TI_COMPILER_VERSION__
#undef __CONCAT
#undef FD_CLR
#undef FD_ISSET
#undef FD_SET
#undef FD_SETSIZE
#undef FD_ZERO
#undef fd_set
#endif

/* We want to disable SL_INC_STD_BSD_API_NAMING, so we include user.h ourselves
 * and undef it. */
#define PROVISIONING_API_H_
#include <simplelink/user.h>
#undef PROVISIONING_API_H_
#undef SL_INC_STD_BSD_API_NAMING

#include <simplelink/include/simplelink.h>
#include <simplelink/include/netapp.h>

/* Now define only the subset of the BSD API that we use.
 * Notably, close(), read() and write() are not defined. */
#define AF_INET SL_AF_INET

#define socklen_t SlSocklen_t
#define sockaddr SlSockAddr_t
#define sockaddr_in SlSockAddrIn_t
#define in_addr SlInAddr_t

#define SOCK_STREAM SL_SOCK_STREAM
#define SOCK_DGRAM SL_SOCK_DGRAM

#define htonl sl_Htonl
#define ntohl sl_Ntohl
#define htons sl_Htons
#define ntohs sl_Ntohs

#ifndef EACCES
#define EACCES SL_EACCES
#endif
#ifndef EAFNOSUPPORT
#define EAFNOSUPPORT SL_EAFNOSUPPORT
#endif
#ifndef EAGAIN
#define EAGAIN SL_EAGAIN
#endif
#ifndef EBADF
#define EBADF SL_EBADF
#endif
#ifndef EINVAL
#define EINVAL SL_EINVAL
#endif
#ifndef ENOMEM
#define ENOMEM SL_ENOMEM
#endif
#ifndef EWOULDBLOCK
#define EWOULDBLOCK SL_EWOULDBLOCK
#endif

#define SOMAXCONN 8

#ifdef __cplusplus
extern "C" {
#endif

const char *inet_ntop(int af, const void *src, char *dst, socklen_t size);
char *inet_ntoa(struct in_addr in);
int inet_pton(int af, const char *src, void *dst);

struct mg_mgr;
struct mg_connection;

typedef void (*mg_init_cb)(struct mg_mgr *mgr);
bool mg_start_task(int priority, int stack_size, mg_init_cb mg_init);

void mg_run_in_task(void (*cb)(struct mg_mgr *mgr, void *arg), void *cb_arg);

int sl_fs_init(void);

void sl_restart_cb(struct mg_mgr *mgr);

int sl_set_ssl_opts(struct mg_connection *nc);

#ifdef __cplusplus
}
#endif

#endif /* MG_NET_IF == MG_NET_IF_SIMPLELINK && !defined(__SIMPLELINK_H__) */

#endif /* CS_COMMON_PLATFORMS_SIMPLELINK_CS_SIMPLELINK_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "common/platforms/platform_cc3200.h"
#endif
/*
 * Copyright (c) 2014-2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef CS_COMMON_PLATFORMS_PLATFORM_CC3200_H_
#define CS_COMMON_PLATFORMS_PLATFORM_CC3200_H_
#if CS_PLATFORM == CS_P_CC3200

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <inttypes.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#ifndef __TI_COMPILER_VERSION__
#include <fcntl.h>
#include <sys/time.h>
#endif

#define MG_NET_IF MG_NET_IF_SIMPLELINK
#define MG_SSL_IF MG_SSL_IF_SIMPLELINK

/* Only SPIFFS supports directories, SLFS does not. */
#if defined(CC3200_FS_SPIFFS) && !defined(MG_ENABLE_DIRECTORY_LISTING)
#define MG_ENABLE_DIRECTORY_LISTING 1
#endif

/* Amalgamated: #include "common/platforms/simplelink/cs_simplelink.h" */

typedef int sock_t;
#define INVALID_SOCKET (-1)
#define SIZE_T_FMT "u"
typedef struct stat cs_stat_t;
#define DIRSEP '/'
#define to64(x) strtoll(x, NULL, 10)
#define INT64_FMT PRId64
#define INT64_X_FMT PRIx64
#define __cdecl

#define fileno(x) -1

/* Some functions we implement for Mongoose. */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __TI_COMPILER_VERSION__
struct SlTimeval_t;
#define timeval SlTimeval_t
int gettimeofday(struct timeval *t, void *tz);

int asprintf(char **strp, const char *fmt, ...);

#endif

/* TI's libc does not have stat & friends, add them. */
#ifdef __TI_COMPILER_VERSION__

#include <file.h>

typedef unsigned int mode_t;
typedef size_t _off_t;
typedef long ssize_t;

struct stat {
  int st_ino;
  mode_t st_mode;
  int st_nlink;
  time_t st_mtime;
  off_t st_size;
};

int _stat(const char *pathname, struct stat *st);
#define stat(a, b) _stat(a, b)

#define __S_IFMT 0170000

#define __S_IFDIR 0040000
#define __S_IFCHR 0020000
#define __S_IFREG 0100000

#define __S_ISTYPE(mode, mask) (((mode) &__S_IFMT) == (mask))

#define S_IFDIR __S_IFDIR
#define S_IFCHR __S_IFCHR
#define S_IFREG __S_IFREG
#define S_ISDIR(mode) __S_ISTYPE((mode), __S_IFDIR)
#define S_ISREG(mode) __S_ISTYPE((mode), __S_IFREG)

/* As of 5.2.7, TI compiler does not support va_copy() yet. */
#define va_copy(apc, ap) ((apc) = (ap))

#endif /* __TI_COMPILER_VERSION__ */

#ifdef CC3200_FS_SLFS
#define MG_FS_SLFS
#endif

#if (defined(CC3200_FS_SPIFFS) || defined(CC3200_FS_SLFS)) && \
    !defined(MG_ENABLE_FILESYSTEM)
#define MG_ENABLE_FILESYSTEM 1
#define CS_DEFINE_DIRENT
#endif

#ifndef CS_ENABLE_STDIO
#define CS_ENABLE_STDIO 1
#endif

#ifdef __cplusplus
}
#endif

#endif /* CS_PLATFORM == CS_P_CC3200 */
#endif /* CS_COMMON_PLATFORMS_PLATFORM_CC3200_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "common/platforms/platform_cc3100.h"
#endif
/*
 * Copyright (c) 2014-2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef CS_COMMON_PLATFORMS_PLATFORM_CC3100_H_
#define CS_COMMON_PLATFORMS_PLATFORM_CC3100_H_
#if CS_PLATFORM == CS_P_CC3100

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <inttypes.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define MG_NET_IF MG_NET_IF_SIMPLELINK
#define MG_SSL_IF MG_SSL_IF_SIMPLELINK

/*
 * CC3100 SDK and STM32 SDK include headers w/out path, just like
 * #include "simplelink.h". As result, we have to add all required directories
 * into Makefile IPATH and do the same thing (include w/out path)
 */

#include <simplelink.h>
#include <netapp.h>
#undef timeval 

typedef int sock_t;
#define INVALID_SOCKET (-1)

#define to64(x) strtoll(x, NULL, 10)
#define INT64_FMT PRId64
#define INT64_X_FMT PRIx64
#define SIZE_T_FMT "u"

#define SOMAXCONN 8

const char *inet_ntop(int af, const void *src, char *dst, socklen_t size);
char *inet_ntoa(struct in_addr in);
int inet_pton(int af, const char *src, void *dst);

#endif /* CS_PLATFORM == CS_P_CC3100 */
#endif /* CS_COMMON_PLATFORMS_PLATFORM_CC3100_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "common/platforms/platform_mbed.h"
#endif
/*
 * Copyright (c) 2014-2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef CS_COMMON_PLATFORMS_PLATFORM_MBED_H_
#define CS_COMMON_PLATFORMS_PLATFORM_MBED_H_
#if CS_PLATFORM == CS_P_MBED

/*
 * mbed.h contains C++ code (e.g. templates), thus, it should be processed
 * only if included directly to startup file (ex: main.cpp)
 */
#ifdef __cplusplus
/* Amalgamated: #include "mbed.h" */
#endif /* __cplusplus */

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <inttypes.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct stat cs_stat_t;
#define DIRSEP '/'

#ifndef CS_ENABLE_STDIO
#define CS_ENABLE_STDIO 1
#endif

/*
 * mbed can be compiled with the ARM compiler which
 * just doesn't come with a gettimeofday shim
 * because it's a BSD API and ARM targets embedded
 * non-unix platforms.
 */
#if defined(__ARMCC_VERSION) || defined(__ICCARM__)
#define _TIMEVAL_DEFINED
#define gettimeofday _gettimeofday

/* copied from GCC on ARM; for some reason useconds are signed */
typedef long suseconds_t; /* microseconds (signed) */
struct timeval {
  time_t tv_sec;       /* seconds */
  suseconds_t tv_usec; /* and microseconds */
};

#endif

#if MG_NET_IF == MG_NET_IF_SIMPLELINK

#define MG_SIMPLELINK_NO_OSI 1

#include <simplelink.h>

typedef int sock_t;
#define INVALID_SOCKET (-1)

#define to64(x) strtoll(x, NULL, 10)
#define INT64_FMT PRId64
#define INT64_X_FMT PRIx64
#define SIZE_T_FMT "u"

#define SOMAXCONN 8

const char *inet_ntop(int af, const void *src, char *dst, socklen_t size);
char *inet_ntoa(struct in_addr in);
int inet_pton(int af, const char *src, void *dst);
int inet_aton(const char *cp, struct in_addr *inp);
in_addr_t inet_addr(const char *cp);

#endif /* MG_NET_IF == MG_NET_IF_SIMPLELINK */

#endif /* CS_PLATFORM == CS_P_MBED */
#endif /* CS_COMMON_PLATFORMS_PLATFORM_MBED_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "common/platforms/platform_nrf51.h"
#endif
/*
 * Copyright (c) 2014-2016 Cesanta Software Limited
 * All rights reserved
 */
#ifndef CS_COMMON_PLATFORMS_PLATFORM_NRF51_H_
#define CS_COMMON_PLATFORMS_PLATFORM_NRF51_H_
#if CS_PLATFORM == CS_P_NRF51

#include <assert.h>
#include <ctype.h>
#include <inttypes.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define to64(x) strtoll(x, NULL, 10)

#define MG_NET_IF             MG_NET_IF_LWIP_LOW_LEVEL
#define MG_LWIP               1
#define MG_ENABLE_IPV6        1

/*
 * For ARM C Compiler, make lwip to export `struct timeval`; for other
 * compilers, suppress it.
 */
#if !defined(__ARMCC_VERSION)
# define LWIP_TIMEVAL_PRIVATE  0
#else
struct timeval;
int gettimeofday(struct timeval *tp, void *tzp);
#endif

#define INT64_FMT PRId64
#define SIZE_T_FMT "u"

/*
 * ARM C Compiler doesn't have strdup, so we provide it
 */
#define CS_ENABLE_STRDUP defined(__ARMCC_VERSION)

#endif /* CS_PLATFORM == CS_P_NRF51 */
#endif /* CS_COMMON_PLATFORMS_PLATFORM_NRF51_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "common/platforms/platform_nrf52.h"
#endif
/*
 * Copyright (c) 2014-2016 Cesanta Software Limited
 * All rights reserved
 */
#ifndef CS_COMMON_PLATFORMS_PLATFORM_NRF52_H_
#define CS_COMMON_PLATFORMS_PLATFORM_NRF52_H_
#if CS_PLATFORM == CS_P_NRF52

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <inttypes.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define to64(x) strtoll(x, NULL, 10)

#define MG_NET_IF             MG_NET_IF_LWIP_LOW_LEVEL
#define MG_LWIP               1
#define MG_ENABLE_IPV6        1

#if !defined(ENOSPC)
# define ENOSPC 28  /* No space left on device */
#endif

/*
 * For ARM C Compiler, make lwip to export `struct timeval`; for other
 * compilers, suppress it.
 */
#if !defined(__ARMCC_VERSION)
# define LWIP_TIMEVAL_PRIVATE  0
#endif

#define INT64_FMT PRId64
#define SIZE_T_FMT "u"

/*
 * ARM C Compiler doesn't have strdup, so we provide it
 */
#define CS_ENABLE_STRDUP defined(__ARMCC_VERSION)

#endif /* CS_PLATFORM == CS_P_NRF52 */
#endif /* CS_COMMON_PLATFORMS_PLATFORM_NRF52_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "common/platforms/platform_wince.h"
#endif
#ifndef CS_COMMON_PLATFORMS_PLATFORM_WINCE_H_
#define CS_COMMON_PLATFORMS_PLATFORM_WINCE_H_

#if CS_PLATFORM == CS_P_WINCE

/*
 * MSVC++ 14.0 _MSC_VER == 1900 (Visual Studio 2015)
 * MSVC++ 12.0 _MSC_VER == 1800 (Visual Studio 2013)
 * MSVC++ 11.0 _MSC_VER == 1700 (Visual Studio 2012)
 * MSVC++ 10.0 _MSC_VER == 1600 (Visual Studio 2010)
 * MSVC++ 9.0  _MSC_VER == 1500 (Visual Studio 2008)
 * MSVC++ 8.0  _MSC_VER == 1400 (Visual Studio 2005)
 * MSVC++ 7.1  _MSC_VER == 1310 (Visual Studio 2003)
 * MSVC++ 7.0  _MSC_VER == 1300
 * MSVC++ 6.0  _MSC_VER == 1200
 * MSVC++ 5.0  _MSC_VER == 1100
 */
#pragma warning(disable : 4127) /* FD_SET() emits warning, disable it */
#pragma warning(disable : 4204) /* missing c99 support */

#ifndef _WINSOCK_DEPRECATED_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1
#endif

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <assert.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma comment(lib, "ws2.lib") /* Linking with WinCE winsock library */

#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

#define strdup _strdup

#ifndef EINPROGRESS
#define EINPROGRESS WSAEINPROGRESS
#endif

#ifndef EWOULDBLOCK
#define EWOULDBLOCK WSAEWOULDBLOCK
#endif

#ifndef EAGAIN
#define EAGAIN EWOULDBLOCK
#endif

#ifndef __func__
#define STRX(x) #x
#define STR(x) STRX(x)
#define __func__ __FILE__ ":" STR(__LINE__)
#endif

#define snprintf _snprintf
#define fileno _fileno
#define vsnprintf _vsnprintf
#define sleep(x) Sleep((x) *1000)
#define to64(x) _atoi64(x)
#define rmdir _rmdir

#if defined(_MSC_VER) && _MSC_VER >= 1400
#define fseeko(x, y, z) _fseeki64((x), (y), (z))
#else
#define fseeko(x, y, z) fseek((x), (y), (z))
#endif

typedef int socklen_t;

#if _MSC_VER >= 1700
#include <stdint.h>
#else
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#endif

typedef SOCKET sock_t;
typedef uint32_t in_addr_t;

#ifndef UINT16_MAX
#define UINT16_MAX 65535
#endif

#ifndef UINT32_MAX
#define UINT32_MAX 4294967295
#endif

#ifndef pid_t
#define pid_t HANDLE
#endif

#define INT64_FMT "I64d"
#define INT64_X_FMT "I64x"
/* TODO(alashkin): check if this is correct */
#define SIZE_T_FMT "u"

#define DIRSEP '\\'
#define CS_DEFINE_DIRENT

#ifndef va_copy
#ifdef __va_copy
#define va_copy __va_copy
#else
#define va_copy(x, y) (x) = (y)
#endif
#endif

#ifndef MG_MAX_HTTP_REQUEST_SIZE
#define MG_MAX_HTTP_REQUEST_SIZE 8192
#endif

#ifndef MG_MAX_HTTP_SEND_MBUF
#define MG_MAX_HTTP_SEND_MBUF 4096
#endif

#ifndef MG_MAX_HTTP_HEADERS
#define MG_MAX_HTTP_HEADERS 40
#endif

#ifndef CS_ENABLE_STDIO
#define CS_ENABLE_STDIO 1
#endif

#define abort() DebugBreak();

#ifndef BUFSIZ
#define BUFSIZ 4096
#endif
/*
 * Explicitly disabling MG_ENABLE_THREADS for WinCE
 * because they are enabled for _WIN32 by default
 */
#ifndef MG_ENABLE_THREADS
#define MG_ENABLE_THREADS 0
#endif

#ifndef MG_ENABLE_FILESYSTEM
#define MG_ENABLE_FILESYSTEM 1
#endif

#ifndef MG_NET_IF
#define MG_NET_IF MG_NET_IF_SOCKET
#endif

typedef struct _stati64 {
  uint32_t st_mtime;
  uint32_t st_size;
  uint32_t st_mode;
} cs_stat_t;

/*
 * WinCE 6.0 has a lot of useful definitions in ATL (not windows.h) headers
 * use #ifdefs to avoid conflicts
 */

#ifndef ENOENT
#define ENOENT ERROR_PATH_NOT_FOUND
#endif

#ifndef EACCES
#define EACCES ERROR_ACCESS_DENIED
#endif

#ifndef ENOMEM
#define ENOMEM ERROR_NOT_ENOUGH_MEMORY
#endif

#ifndef _UINTPTR_T_DEFINED
typedef unsigned int* uintptr_t;
#endif

#define _S_IFREG 2
#define _S_IFDIR 4

#ifndef S_ISDIR
#define S_ISDIR(x) (((x) & _S_IFDIR) != 0)
#endif

#ifndef S_ISREG
#define S_ISREG(x) (((x) & _S_IFREG) != 0)
#endif

int open(const char *filename, int oflag, int pmode);
int _wstati64(const wchar_t *path, cs_stat_t *st);
const char *strerror();

#endif /* CS_PLATFORM == CS_P_WINCE */
#endif /* CS_COMMON_PLATFORMS_PLATFORM_WINCE_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "common/platforms/platform_nxp_lpc.h"
#endif
/*
 * Copyright (c) 2014-2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef CS_COMMON_PLATFORMS_PLATFORM_NXP_LPC_H_
#define CS_COMMON_PLATFORMS_PLATFORM_NXP_LPC_H_

#if CS_PLATFORM == CS_P_NXP_LPC

#include <ctype.h>
#include <stdint.h>
#include <string.h>

#define SIZE_T_FMT "u"
typedef struct stat cs_stat_t;
#define INT64_FMT "lld"
#define INT64_X_FMT "llx"
#define __cdecl

#define MG_LWIP 1

#define MG_NET_IF MG_NET_IF_LWIP_LOW_LEVEL

/*
 * LPCXpress comes with 3 C library implementations: Newlib, NewlibNano and Redlib.
 * See https://community.nxp.com/message/630860 for more details.
 *
 * Redlib is the default and lacks certain things, so we provide them.
 */
#ifdef __REDLIB_INTERFACE_VERSION__

/* Let LWIP define timeval for us. */
#define LWIP_TIMEVAL_PRIVATE 1

#define va_copy(d, s) __builtin_va_copy(d, s)

#define CS_ENABLE_TO64 1
#define to64(x) cs_to64(x)

#define CS_ENABLE_STRDUP 1

#else

#include <sys/time.h>
#define LWIP_TIMEVAL_PRIVATE 0
#define to64(x) strtoll(x, NULL, 10)

#endif

#endif /* CS_PLATFORM == CS_P_NXP_LPC */
#endif /* CS_COMMON_PLATFORMS_PLATFORM_NXP_LPC_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "common/platforms/platform_nxp_kinetis.h"
#endif
/*
 * Copyright (c) 2014-2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef CS_COMMON_PLATFORMS_PLATFORM_NXP_KINETIS_H_
#define CS_COMMON_PLATFORMS_PLATFORM_NXP_KINETIS_H_

#if CS_PLATFORM == CS_P_NXP_KINETIS

#include <ctype.h>
#include <inttypes.h>
#include <string.h>
#include <sys/time.h>

#define SIZE_T_FMT "u"
typedef struct stat cs_stat_t;
#define to64(x) strtoll(x, NULL, 10)
#define INT64_FMT "lld"
#define INT64_X_FMT "llx"
#define __cdecl

#define MG_LWIP 1

#define MG_NET_IF MG_NET_IF_LWIP_LOW_LEVEL

/* struct timeval is defined in sys/time.h. */
#define LWIP_TIMEVAL_PRIVATE 0

#endif /* CS_PLATFORM == CS_P_NXP_KINETIS */
#endif /* CS_COMMON_PLATFORMS_PLATFORM_NXP_KINETIS_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "common/platforms/platform_pic32.h"
#endif
/*
 * Copyright (c) 2014-2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef CS_COMMON_PLATFORMS_PLATFORM_PIC32_H_
#define CS_COMMON_PLATFORMS_PLATFORM_PIC32_H_

#if CS_PLATFORM == CS_P_PIC32

#define MG_NET_IF MG_NET_IF_PIC32

#include <stdint.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

#include <system_config.h>
#include <system_definitions.h>

#include <sys/types.h>

typedef TCP_SOCKET sock_t;
#define to64(x) strtoll(x, NULL, 10)

#define SIZE_T_FMT "lu"
#define INT64_FMT "lld"

#ifndef CS_ENABLE_STDIO
#define CS_ENABLE_STDIO 1
#endif

char* inet_ntoa(struct in_addr in);

#endif /* CS_PLATFORM == CS_P_PIC32 */

#endif /* CS_COMMON_PLATFORMS_PLATFORM_PIC32_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "common/platforms/platform_stm32.h"
#endif
/*
 * Copyright (c) 2014-2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef CS_COMMON_PLATFORMS_PLATFORM_STM32_H_
#define CS_COMMON_PLATFORMS_PLATFORM_STM32_H_
#if CS_PLATFORM == CS_P_STM32

#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <memory.h>
#include <fcntl.h>
#include <stm32_sdk_hal.h>

#define to64(x) strtoll(x, NULL, 10)
#define INT64_FMT PRId64
#define SIZE_T_FMT "u"
typedef struct stat cs_stat_t;
#define DIRSEP '/'

#ifndef CS_ENABLE_STDIO
#define CS_ENABLE_STDIO 1
#endif

#ifndef MG_ENABLE_FILESYSTEM
#define MG_ENABLE_FILESYSTEM 1
#endif

#define CS_DEFINE_DIRENT

#endif /* CS_PLATFORM == CS_P_STM32 */
#endif /* CS_COMMON_PLATFORMS_PLATFORM_STM32_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "common/cs_dbg.h"
#endif
/*
 * Copyright (c) 2014-2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef CS_COMMON_CS_DBG_H_
#define CS_COMMON_CS_DBG_H_

/* Amalgamated: #include "common/platform.h" */

#if CS_ENABLE_STDIO
#include <stdio.h>
#endif

#ifndef CS_ENABLE_DEBUG
#define CS_ENABLE_DEBUG 0
#endif

#ifndef CS_LOG_ENABLE_TS_DIFF
#define CS_LOG_ENABLE_TS_DIFF 0
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

enum cs_log_level {
  LL_NONE = -1,
  LL_ERROR = 0,
  LL_WARN = 1,
  LL_INFO = 2,
  LL_DEBUG = 3,
  LL_VERBOSE_DEBUG = 4,

  _LL_MIN = -2,
  _LL_MAX = 5,
};

void cs_log_set_level(enum cs_log_level level);

#if CS_ENABLE_STDIO

void cs_log_set_file(FILE *file);
extern enum cs_log_level cs_log_level;
void cs_log_print_prefix(const char *func);
void cs_log_printf(const char *fmt, ...);

#define LOG(l, x)                    \
  do {                               \
    if (cs_log_level >= l) {         \
      cs_log_print_prefix(__func__); \
      cs_log_printf x;               \
    }                                \
  } while (0)

#ifndef CS_NDEBUG

#define DBG(x)                              \
  do {                                      \
    if (cs_log_level >= LL_VERBOSE_DEBUG) { \
      cs_log_print_prefix(__func__);        \
      cs_log_printf x;                      \
    }                                       \
  } while (0)

#else /* NDEBUG */

#define DBG(x)

#endif

#else /* CS_ENABLE_STDIO */

#define LOG(l, x)
#define DBG(x)

#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CS_COMMON_CS_DBG_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "common/cs_time.h"
#endif
/*
 * Copyright (c) 2014-2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef CS_COMMON_CS_TIME_H_
#define CS_COMMON_CS_TIME_H_

/* Amalgamated: #include "common/platform.h" */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Sub-second granularity time(). */
double cs_time(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CS_COMMON_CS_TIME_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "common/cs_file.h"
#endif
/*
 * Copyright (c) 2015 Cesanta Software Limited
 * All rights reserved
 */

#ifndef CS_COMMON_CS_FILE_H_
#define CS_COMMON_CS_FILE_H_

/* Amalgamated: #include "common/platform.h" */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
 * Read whole file `path` in memory. It is responsibility of the caller
 * to `free()` allocated memory. File content is guaranteed to be
 * '\0'-terminated. File size is returned in `size` variable, which does not
 * count terminating `\0`.
 * Return: allocated memory, or NULL on error.
 */
char *cs_read_file(const char *path, size_t *size);

#ifdef CS_MMAP
char *cs_mmap_file(const char *path, size_t *size);
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CS_COMMON_CS_FILE_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "common/mbuf.h"
#endif
/*
 * Copyright (c) 2015 Cesanta Software Limited
 * All rights reserved
 */

/*
 * === Memory Buffers
 *
 * Mbufs are mutable/growing memory buffers, like C++ strings.
 * Mbuf can append data to the end of a buffer or insert data into arbitrary
 * position in the middle of a buffer. The buffer grows automatically when
 * needed.
 */

#ifndef CS_COMMON_MBUF_H_
#define CS_COMMON_MBUF_H_

#include <stdlib.h>
/* Amalgamated: #include "common/platform.h" */

#if defined(__cplusplus)
extern "C" {
#endif

#ifndef MBUF_SIZE_MULTIPLIER
#define MBUF_SIZE_MULTIPLIER 1.5
#endif

/* Memory buffer descriptor */
struct mbuf {
  char *buf;   /* Buffer pointer */
  size_t len;  /* Data length. Data is located between offset 0 and len. */
  size_t size; /* Buffer size allocated by realloc(1). Must be >= len */
};

/*
 * Initialises an Mbuf.
 * `initial_capacity` specifies the initial capacity of the mbuf.
 */
void mbuf_init(struct mbuf *, size_t initial_capacity);

/* Frees the space allocated for the mbuffer and resets the mbuf structure. */
void mbuf_free(struct mbuf *);

/*
 * Appends data to the Mbuf.
 *
 * Returns the number of bytes appended or 0 if out of memory.
 */
size_t mbuf_append(struct mbuf *, const void *data, size_t data_size);

/*
 * Inserts data at a specified offset in the Mbuf.
 *
 * Existing data will be shifted forwards and the buffer will
 * be grown if necessary.
 * Returns the number of bytes inserted.
 */
size_t mbuf_insert(struct mbuf *, size_t, const void *, size_t);

/* Removes `data_size` bytes from the beginning of the buffer. */
void mbuf_remove(struct mbuf *, size_t data_size);

/*
 * Resizes an Mbuf.
 *
 * If `new_size` is smaller than buffer's `len`, the
 * resize is not performed.
 */
void mbuf_resize(struct mbuf *, size_t new_size);

/* Shrinks an Mbuf by resizing its `size` to `len`. */
void mbuf_trim(struct mbuf *);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* CS_COMMON_MBUF_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "common/mg_mem.h"
#endif
/*
 * Copyright (c) 2014-2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef CS_COMMON_MG_MEM_H_
#define CS_COMMON_MG_MEM_H_

#ifndef MG_MALLOC
#define MG_MALLOC malloc
#endif

#ifndef MG_CALLOC
#define MG_CALLOC calloc
#endif

#ifndef MG_REALLOC
#define MG_REALLOC realloc
#endif

#ifndef MG_FREE
#define MG_FREE free
#endif

#endif /* CS_COMMON_MG_MEM_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "common/str_util.h"
#endif
/*
 * Copyright (c) 2015 Cesanta Software Limited
 * All rights reserved
 */

#ifndef CS_COMMON_STR_UTIL_H_
#define CS_COMMON_STR_UTIL_H_

#include <stdarg.h>
#include <stdlib.h>

/* Amalgamated: #include "common/platform.h" */

#ifndef CS_ENABLE_STRDUP
#define CS_ENABLE_STRDUP 0
#endif

#ifndef CS_ENABLE_TO64
#define CS_ENABLE_TO64 0
#endif

/*
 * Expands to a string representation of its argument: e.g.
 * `CS_STRINGIFY_LIT(5) expands to "5"`
 */
#define CS_STRINGIFY_LIT(x) #x

/*
 * Expands to a string representation of its argument, which is allowed
 * to be a macro: e.g.
 *
 * #define FOO 123
 * CS_STRINGIFY_MACRO(FOO)
 *
 * expands to 123.
 */
#define CS_STRINGIFY_MACRO(x) CS_STRINGIFY_LIT(x)

#ifdef __cplusplus
extern "C" {
#endif

size_t c_strnlen(const char *s, size_t maxlen);
int c_snprintf(char *buf, size_t buf_size, const char *format, ...);
int c_vsnprintf(char *buf, size_t buf_size, const char *format, va_list ap);
/*
 * Find the first occurrence of find in s, where the search is limited to the
 * first slen characters of s.
 */
const char *c_strnstr(const char *s, const char *find, size_t slen);

/*
 * Stringify binary data. Output buffer size must be 2 * size_of_input + 1
 * because each byte of input takes 2 bytes in string representation
 * plus 1 byte for the terminating \0 character.
 */
void cs_to_hex(char *to, const unsigned char *p, size_t len);

/*
 * Convert stringified binary data back to binary.
 * Does the reverse of `cs_to_hex()`.
 */
void cs_from_hex(char *to, const char *p, size_t len);

#if CS_ENABLE_STRDUP
char *strdup(const char *src);
#endif

#if CS_ENABLE_TO64
#include <stdint.h>
/*
 * Simple string -> int64 conversion routine.
 */
int64_t cs_to64(const char *s);
#endif

/*
 * Cross-platform version of `strncasecmp()`.
 */
int mg_ncasecmp(const char *s1, const char *s2, size_t len);

/*
 * Cross-platform version of `strcasecmp()`.
 */
int mg_casecmp(const char *s1, const char *s2);

/*
 * Prints message to the buffer. If the buffer is large enough to hold the
 * message, it returns buffer. If buffer is to small, it allocates a large
 * enough buffer on heap and returns allocated buffer.
 * This is a supposed use case:
 *
 *    char buf[5], *p = buf;
 *    mg_avprintf(&p, sizeof(buf), "%s", "hi there");
 *    use_p_somehow(p);
 *    if (p != buf) {
 *      free(p);
 *    }
 *
 * The purpose of this is to avoid malloc-ing if generated strings are small.
 */
int mg_asprintf(char **buf, size_t size, const char *fmt, ...);

/* Same as mg_asprintf, but takes varargs list. */
int mg_avprintf(char **buf, size_t size, const char *fmt, va_list ap);

#ifdef __cplusplus
}
#endif

#endif /* CS_COMMON_STR_UTIL_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/ffi/ffi.h"
#endif
/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_FFI_FFI_H_
#define MJS_FFI_FFI_H_

/* Amalgamated: #include "common/platform.h" */

/*
 * Maximum number of word-sized args to ffi-ed function. If at least one
 * of the args is double, only 2 args are allowed.
 */
#define FFI_MAX_ARGS_CNT 6

typedef void (*ffi_fn_t)(void);

struct ffi_arg {
  int size;
  int is_float;
  union {
    uint64_t i;
    double d;
  } v;
};

int ffi_call(ffi_fn_t func, int nargs, struct ffi_arg *res,
             struct ffi_arg *args);

void ffi_set_int32(struct ffi_arg *arg, uint32_t v);
void ffi_set_int64(struct ffi_arg *arg, uint64_t v);
void ffi_set_ptr(struct ffi_arg *arg, void *v);
void ffi_set_double(struct ffi_arg *arg, double v);

#endif /* MJS_FFI_FFI_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_internal.h"
#endif
/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_INTERNAL_H_
#define MJS_INTERNAL_H_

#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#ifndef FAST
#define FAST
#endif

#ifndef STATIC
#define STATIC
#endif

#ifndef ENDL
#define ENDL "\n"
#endif

#ifdef MJS_EXPOSE_PRIVATE
#define MJS_PRIVATE
#define MJS_EXTERN extern
#else
#define MJS_PRIVATE static
#define MJS_EXTERN static
#endif

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#endif

#if !defined(WEAK)
#if (defined(__GNUC__) || defined(__TI_COMPILER_VERSION__)) && !defined(_WIN32)
#define WEAK __attribute__((weak))
#else
#define WEAK
#endif
#endif

#ifndef CS_ENABLE_STDIO
#define CS_ENABLE_STDIO 1
#endif

/* Amalgamated: #include "common/cs_dbg.h" */
/* Amalgamated: #include "common/cs_file.h" */
/* Amalgamated: #include "common/mbuf.h" */

#if defined(_WIN32) && _MSC_VER < 1700
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef __int64 int64_t;
typedef unsigned long uintptr_t;
#define STRX(x) #x
#define STR(x) STRX(x)
#define __func__ __FILE__ ":" STR(__LINE__)
// #define snprintf _snprintf
#define vsnprintf _vsnprintf
#define isnan(x) _isnan(x)
#define va_copy(x, y) (x) = (y)
#define CS_DEFINE_DIRENT
#include <windows.h>
#else
#include <dirent.h>
#if defined(__unix__) || defined(__APPLE__)
#include <dlfcn.h>
#endif
#endif

#endif /* MJS_INTERNAL_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_license.h"
#endif
/*
 * Copyright (c) 2017 Cesanta Software Limited
 * All rights reserved
 *
 * This software is dual-licensed: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation. For the terms of this
 * license, see <http://www.gnu.org/licenses/>.
 *
 * You are free to use this software under the terms of the GNU General
 * Public License, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * Alternatively, you can license this software under a commercial
 * license, as set out in <https://www.cesanta.com/license>.
 */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_features.h"
#endif
/*
 * Copyright (c) 2017 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_FEATURES_H_
#define MJS_FEATURES_H_

#if !defined(MJS_AGGRESSIVE_GC)
#define MJS_AGGRESSIVE_GC 0
#endif

#endif /* MJS_FEATURES_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_core_public.h"
#endif
/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_CORE_PUBLIC_H_
#define MJS_CORE_PUBLIC_H_

#include <stdint.h>
#include <stddef.h>
/* Amalgamated: #include "mjs/src/mjs_license.h" */
/* Amalgamated: #include "mjs/src/mjs_features.h" */

#define MJS_ENABLE_DEBUG 1

/*
 *  Double-precision floating-point number, IEEE 754
 *
 *  64 bit (8 bytes) in total
 *  1  bit sign
 *  11 bits exponent
 *  52 bits mantissa
 *      7         6        5        4        3        2        1        0
 *  seeeeeee|eeeemmmm|mmmmmmmm|mmmmmmmm|mmmmmmmm|mmmmmmmm|mmmmmmmm|mmmmmmmm
 *
 * If an exponent is all-1 and mantissa is all-0, then it is an INFINITY:
 *  11111111|11110000|00000000|00000000|00000000|00000000|00000000|00000000
 *
 * If an exponent is all-1 and mantissa's MSB is 1, it is a quiet NaN:
 *  11111111|11111000|00000000|00000000|00000000|00000000|00000000|00000000
 *
 *  MJS NaN-packing:
 *    sign and exponent is 0xfff
 *    4 bits specify type (tag), must be non-zero
 *    48 bits specify value
 *
 *  11111111|1111tttt|vvvvvvvv|vvvvvvvv|vvvvvvvv|vvvvvvvv|vvvvvvvv|vvvvvvvv
 *   NaN marker |type|  48-bit placeholder for values: pointers, strings
 *
 * On 64-bit platforms, pointers are really 48 bit only, so they can fit,
 * provided they are sign extended
 */

typedef uint64_t mjs_val_t;

/* This if-0 is a dirty workaround to force etags to pick `struct mjs` */
#if 0
/* Opaque structure. MJS engine context. */
struct mjs {
  /* ... */
};
#endif

struct mjs;

typedef enum mjs_err {
  MJS_OK,
  MJS_SYNTAX_ERROR,
  MJS_REFERENCE_ERROR,
  MJS_TYPE_ERROR,
  MJS_OUT_OF_MEMORY,
  MJS_INTERNAL_ERROR,
  MJS_NOT_IMPLEMENTED_ERROR,
  MJS_FILE_READ_ERROR,
  MJS_BAD_ARGS_ERROR,
} mjs_err_t;
struct mjs;

/* Create MJS instance */
struct mjs *mjs_create();

struct mjs_create_opts {
  /* use non-default bytecode definition file, testing-only */
  const struct bf_code *code;
};

/*
 * Like `msj_create()`, but allows to customize initial MJS state, see `struct
 * mjs_create_opts`.
 */
struct mjs *mjs_create_opt(struct mjs_create_opts opts);

/* Destroy MJS instance */
void mjs_destroy(struct mjs *mjs);

mjs_val_t mjs_get_global(struct mjs *mjs);

/*
 * Tells the GC about an MJS value variable/field owned by C code.
 *
 * The user's C code should own mjs_val_t variables if the value's lifetime
 * crosses any invocation of `mjs_exec()` and friends, including `mjs_call()`.
 *
 * The registration of the variable prevents the GC from mistakenly treat the
 * object as garbage.
 *
 * User code should also explicitly disown the variables with `mjs_disown()`
 * once it goes out of scope or the structure containing the mjs_val_t field is
 * freed.
 *
 * Consider the following examples:
 *
 * Correct (owning is not necessary):
 * ```c
 * mjs_val_t res;
 * mjs_exec(mjs, "....some script", &res);
 * // ... use res somehow
 *
 * mjs_val_t res;
 * mjs_exec(mjs, "....some script2", &res);
 * // ... use new res somehow
 * ```
 *
 * WRONG:
 * ```c
 * mjs_val_t res1;
 * mjs_exec(mjs, "....some script", &res1);
 *
 * mjs_val_t res2;
 * mjs_exec(mjs, "....some script2", &res2);
 *
 * // ... use res1 (WRONG!) and res2
 * ```
 *
 * The code above is wrong, because after the second invocation of
 * `mjs_exec()`, the value of `res1` is invalidated.
 *
 * Correct (res1 is owned)
 * ```c
 * mjs_val_t res1 = MJS_UNDEFINED;
 * mjs_own(mjs, &res1);
 * mjs_exec(mjs, "....some script", &res1);
 *
 * mjs_val_t res2 = MJS_UNDEFINED;
 * mjs_exec(mjs, "....some script2", &res2);
 *
 * // ... use res1 and res2
 * mjs_disown(mjs, &res1);
 * ```
 *
 * NOTE that we explicly initialized `res1` to a valid value before owning it
 * (in this case, the value is `MJS_UNDEFINED`). Owning an uninitialized
 * variable is an undefined behaviour.
 *
 * Of course, it's not an error to own a variable even if it's not mandatory:
 * e.g. in the last example we could own both `res1` and `res2`. Probably it
 * would help us in the future, when we refactor the code so that `res2` has to
 * be owned, and we could forget to do that.
 *
 * Also, if the user code has some C function called from MJS, and in this C
 * function some MJS value (`mjs_val_t`) needs to be stored somewhhere and to
 * stay alive after the C function has returned, it also needs to be properly
 * owned.
 */
void mjs_own(struct mjs *mjs, mjs_val_t *v);

/*
 * Disowns the value previously owned by `mjs_own()`.
 *
 * Returns 1 if value is found, 0 otherwise.
 */
int mjs_disown(struct mjs *mjs, mjs_val_t *v);

mjs_err_t mjs_set_errorf(struct mjs *mjs, mjs_err_t err, const char *fmt, ...);

/*
 * If there is no error message already set, then it's equal to
 * `mjs_set_errorf()`.
 *
 * Otherwise, an old message gets prepended with the new one, followed by a
 * colon. (the previously set error code is kept)
 */
mjs_err_t mjs_prepend_errorf(struct mjs *mjs, mjs_err_t err, const char *fmt,
                             ...);

/*
 * return a string representation of an error.
 * the error string might be overwritten by calls to `mjs_set_errorf`.
 */
const char *mjs_strerror(struct mjs *mjs, enum mjs_err err);

#endif /* MJS_CORE_PUBLIC_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_array_public.h"
#endif
/*
 * Copyright (c) 2017 Cesanta Software Limited
 * All rights reserved
 */

/*
 * === Arrays
 */

#ifndef MJS_ARRAY_PUBLIC_H_
#define MJS_ARRAY_PUBLIC_H_

/* Amalgamated: #include "mjs/src/mjs_core_public.h" */

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/* Make an empty array object */
mjs_val_t mjs_mk_array(struct mjs *mjs);

/* Returns length on an array. If `arr` is not an array, 0 is returned. */
unsigned long mjs_array_length(struct mjs *mjs, mjs_val_t arr);

/* Insert value `v` in array `arr` at the end of the array. */
mjs_err_t mjs_array_push(struct mjs *mjs, mjs_val_t arr, mjs_val_t v);

/*
 * Return array member at index `index`. If `index` is out of bounds, undefined
 * is returned.
 */
mjs_val_t mjs_array_get(struct mjs *, mjs_val_t arr, unsigned long index);

/* Insert value `v` into `arr` at index `index`. */
mjs_err_t mjs_array_set(struct mjs *mjs, mjs_val_t arr, unsigned long index,
                        mjs_val_t v);

/* Returns true if the given value is an array */
int mjs_is_array(mjs_val_t v);

#if 0
/* Delete value in array `arr` at index `index`, if it exists. */
void mjs_array_del(struct mjs *mjs, mjs_val_t arr, unsigned long index);
#endif

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* MJS_ARRAY_PUBLIC_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_array.h"
#endif
/*
 * Copyright (c) 2014 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_ARRAY_H_
#define MJS_ARRAY_H_

/* Amalgamated: #include "mjs/src/mjs_internal.h" */
/* Amalgamated: #include "mjs/src/mjs_array_public.h" */

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

MJS_PRIVATE mjs_val_t
mjs_array_get2(struct mjs *mjs, mjs_val_t arr, unsigned long index, int *has);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* MJS_ARRAY_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_ffi_public.h"
#endif
/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_FFI_PUBLIC_H_
#define MJS_FFI_PUBLIC_H_

/* Amalgamated: #include "mjs/src/mjs_core_public.h" */

typedef void *(mjs_ffi_resolver_t)(void *handle, const char *symbol);

void mjs_set_ffi_resolver(struct mjs *mjs, mjs_ffi_resolver_t *dlsym);

#endif /* MJS_FFI_PUBLIC_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_ffi.h"
#endif
/*
 * Copyright (c) 2017 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_FFI_H_
#define MJS_FFI_H_

/* Amalgamated: #include "mjs/src/mjs_internal.h" */
/* Amalgamated: #include "mjs/src/mjs_ffi_public.h" */

mjs_ffi_resolver_t dlsym;

#define MJS_CB_ARGS_MAX_CNT 6
#define MJS_CB_SIGNATURE_MAX_SIZE (MJS_CB_ARGS_MAX_CNT + 1 /* return type */)

enum cval_type {
  CVAL_TYPE_NONE,
  CVAL_TYPE_USERDATA,
  CVAL_TYPE_INT,
  CVAL_TYPE_DOUBLE,
  CVAL_TYPE_CHAR_PTR,
  CVAL_TYPE_VOID_PTR,
  CVAL_TYPE_INVALID,
};
typedef uint8_t cval_type_t;

struct ffi_sig_stat {
  int8_t is_valid;
  int8_t userdata_idx;
  int8_t args_cnt;
  int8_t args_double_cnt;
};

struct ffi_sig {
  /*
   * The first item is the return value type (for `void`, `CVAL_TYPE_NONE` is
   * used); the rest are arguments. If some argument is `CVAL_TYPE_NONE`, it
   * means that there are no more arguments.
   */
  cval_type_t val_types[MJS_CB_SIGNATURE_MAX_SIZE];
  struct ffi_sig_stat stat;
};
typedef struct ffi_sig ffi_sig_t;

MJS_PRIVATE void mjs_ffi_sig_init(ffi_sig_t *sig);
MJS_PRIVATE int mjs_ffi_sig_set_val_type(ffi_sig_t *sig, int idx,
                                         cval_type_t type);
MJS_PRIVATE struct ffi_sig_stat mjs_ffi_sig_stat_get(struct mjs *mjs,
                                                     const ffi_sig_t *sig);
MJS_PRIVATE int mjs_ffi_is_regular_word(cval_type_t type);
MJS_PRIVATE int mjs_ffi_is_regular_word_or_void(cval_type_t type);

struct ffi_cb_args {
  struct ffi_cb_args *next;
  struct mjs *mjs;
  ffi_sig_t sig;
  mjs_val_t func;
  mjs_val_t userdata;
};
typedef struct ffi_cb_args ffi_cb_args_t;

MJS_PRIVATE mjs_err_t mjs_ffi_call(struct mjs *mjs);
MJS_PRIVATE mjs_err_t mjs_ffi_call2(struct mjs *mjs);
MJS_PRIVATE void mjs_ffi_cb_free(struct mjs *);
MJS_PRIVATE void mjs_ffi_args_free_list(struct mjs *mjs);

#endif /* MJS_FFI_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_mm.h"
#endif
/*
 * Copyright (c) 2014-2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_MM_H_
#define MJS_MM_H_

/* Amalgamated: #include "mjs/src/mjs_internal.h" */

struct mjs;

typedef void (*gc_cell_destructor_t)(struct mjs *mjs, void *);

struct gc_block {
  struct gc_block *next;
  struct gc_cell *base;
  size_t size;
};

struct gc_arena {
  struct gc_block *blocks;
  size_t size_increment;
  struct gc_cell *free; /* head of free list */
  size_t cell_size;

  gc_cell_destructor_t destructor;
};

#endif /* MJS_MM_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_gc.h"
#endif
/*
 * Copyright (c) 2014 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_GC_H_
#define MJS_GC_H_

/* Amalgamated: #include "mjs/src/mjs_core.h" */
/* Amalgamated: #include "mjs/src/mjs_mm.h" */
/* Amalgamated: #include "mjs/src/mjs_internal.h" */

/*
 * performs arithmetics on gc_cell pointers as if they were arena->cell_size
 * bytes wide
 */
#define GC_CELL_OP(arena, cell, op, arg) \
  ((struct gc_cell *) (((char *) (cell)) op((arg) * (arena)->cell_size)))

struct gc_cell {
  union {
    struct gc_cell *link;
    uintptr_t word;
  } head;
};

/*
 * Perform garbage collection.
 * Pass true to full in order to reclaim unused heap back to the OS.
 */
void mjs_gc(struct mjs *mjs, int full);

MJS_PRIVATE int gc_strings_is_gc_needed(struct mjs *mjs);

/* perform gc if not inhibited */
MJS_PRIVATE int maybe_gc(struct mjs *mjs);

MJS_PRIVATE struct mjs_object *new_object(struct mjs *);
MJS_PRIVATE struct mjs_property *new_property(struct mjs *);

MJS_PRIVATE void gc_mark(struct mjs *, mjs_val_t);

MJS_PRIVATE void gc_arena_init(struct gc_arena *, size_t, size_t, size_t);
MJS_PRIVATE void gc_arena_destroy(struct mjs *, struct gc_arena *a);
MJS_PRIVATE void gc_sweep(struct mjs *, struct gc_arena *, size_t);
MJS_PRIVATE void *gc_alloc_cell(struct mjs *, struct gc_arena *);

MJS_PRIVATE uint64_t gc_string_mjs_val_to_offset(mjs_val_t v);

/* return 0 if v is an object/function with a bad pointer */
MJS_PRIVATE int gc_check_val(struct mjs *mjs, mjs_val_t v);

/* checks whether a pointer is within the ranges of an arena */
MJS_PRIVATE int gc_check_ptr(const struct gc_arena *a, const void *p);

#endif /* MJS_GC_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_core.h"
#endif
/*
 * Copyright (c) 2017 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_CORE_H
#define MJS_CORE_H

/* Amalgamated: #include "mjs/src/mjs_ffi.h" */
/* Amalgamated: #include "mjs/src/mjs_gc.h" */
/* Amalgamated: #include "mjs/src/mjs_internal.h" */

#define JUMP_INSTRUCTION_SIZE 2

enum mjs_type {
  /* Primitive types */
  MJS_TYPE_UNDEFINED,
  MJS_TYPE_NULL,
  MJS_TYPE_BOOLEAN,
  MJS_TYPE_NUMBER,
  MJS_TYPE_STRING,
  MJS_TYPE_FOREIGN,

  /* Different classes of Object type */
  MJS_TYPE_OBJECT_GENERIC,
  MJS_TYPE_OBJECT_ARRAY,
  /*
   * TODO(dfrank): if we support prototypes, need to add items for them here
   */

  MJS_TYPES_CNT
};

/*
 * A tag is made of the sign bit and the 4 lower order bits of byte 6.
 * So in total we have 32 possible tags.
 *
 * Tag (1,0) however cannot hold a zero payload otherwise it's interpreted as an
 * INFINITY; for simplicity we're just not going to use that combination.
 */
#define MAKE_TAG(s, t) \
  ((uint64_t)(s) << 63 | (uint64_t) 0x7ff0 << 48 | (uint64_t)(t) << 48)

#define MJS_TAG_OBJECT MAKE_TAG(1, 1)
#define MJS_TAG_FOREIGN MAKE_TAG(1, 2)
#define MJS_TAG_UNDEFINED MAKE_TAG(1, 3)
#define MJS_TAG_BOOLEAN MAKE_TAG(1, 4)
#define MJS_TAG_NAN MAKE_TAG(1, 5)
#define MJS_TAG_STRING_I MAKE_TAG(1, 6)  /* Inlined string len < 5 */
#define MJS_TAG_STRING_5 MAKE_TAG(1, 7)  /* Inlined string len 5 */
#define MJS_TAG_STRING_O MAKE_TAG(1, 8)  /* Owned string */
#define MJS_TAG_STRING_F MAKE_TAG(1, 9)  /* Foreign string */
#define MJS_TAG_STRING_C MAKE_TAG(1, 10) /* String chunk */
#define MJS_TAG_STRING_D MAKE_TAG(1, 11) /* Dictionary string  */
#define MJS_TAG_ARRAY MAKE_TAG(1, 12)
#define MJS_TAG_FUNCTION MAKE_TAG(1, 13)
#define MJS_TAG_NULL MAKE_TAG(1, 14)
#define MJS_TAG_MASK MAKE_TAG(1, 15)

struct mjs_vals {
  /* Current `this` value  */
  mjs_val_t this_obj;
  mjs_val_t dataview_proto;
};

struct mjs {
  struct mbuf bcode;
  struct mbuf stack;
  struct mbuf call_stack;
  struct mbuf scopes;          /* Scope objects */
  struct mbuf loop_addresses;  /* Addresses for breaks & continues */
  struct mbuf owned_strings;   /* Sequence of (varint len, char data[]) */
  struct mbuf foreign_strings; /* Sequence of (varint len, char *data) */
  struct mbuf owned_values;
  struct mbuf json_visited_stack;
  struct mjs_vals vals;
  char *error_msg;
  enum mjs_err error;
  mjs_ffi_resolver_t *dlsym;  /* Symbol resolver function for FFI */
  ffi_cb_args_t *ffi_cb_args; /* List of FFI args descriptors */

  struct gc_arena object_arena;
  struct gc_arena property_arena;

  unsigned inhibit_gc : 1;
  unsigned need_gc : 1;
};

/*
 * Bcode header: type of the items, and item numbers.
 */
typedef uint32_t mjs_header_item_t;
enum mjs_header_items {
  MJS_HDR_ITEM_TOTAL_SIZE,   /* Total size of the bcode (not counting the
                                OP_BCODE_HEADER byte) */
  MJS_HDR_ITEM_BCODE_OFFSET, /* Offset to the start of the actual bcode (not
                                counting the OP_BCODE_HEADER byte) */
  MJS_HDR_ITEM_MAP_OFFSET,   /* Offset to the start of offset-to-line_no mapping
                                k*/

  MJS_HDR_ITEMS_CNT
};

MJS_PRIVATE size_t mjs_get_func_addr(mjs_val_t v);

MJS_PRIVATE int mjs_getretvalpos(struct mjs *mjs);
MJS_PRIVATE mjs_val_t mjs_arg(struct mjs *mjs, int arg_index);
MJS_PRIVATE int mjs_nargs(struct mjs *mjs);
MJS_PRIVATE void mjs_return(struct mjs *mjs, mjs_val_t);

MJS_PRIVATE enum mjs_type mjs_get_type(struct mjs *mjs, mjs_val_t v);

/*
 * Returns offset of the bcode header (see enum mjs_header_items) which
 * contains given bcode offset, or -1 in case the offset is too large.
 */
MJS_PRIVATE int mjs_get_bcode_header_offset(struct mjs *mjs, size_t offset);

/*
 * Returns the filename of the bcode by the bcode offset.
 */
MJS_PRIVATE const char *mjs_get_bcode_filename_by_offset(struct mjs *mjs,
                                                         int offset);

/*
 * Returns the line
 */
MJS_PRIVATE int mjs_get_lineno_by_offset(struct mjs *mjs, int offset);

/*
 * Prints stack trace starting from the given bcode offset; other offsets
 * (if any) will be fetched from the call_stack.
 */
MJS_PRIVATE void mjs_print_stack_trace(struct mjs *mjs, size_t offset);

MJS_PRIVATE mjs_val_t vtop(struct mbuf *m);
MJS_PRIVATE size_t mjs_stack_size(const struct mbuf *m);
MJS_PRIVATE mjs_val_t *vptr(struct mbuf *m, int idx);
MJS_PRIVATE void push_mjs_val(struct mbuf *m, mjs_val_t v);
MJS_PRIVATE mjs_val_t mjs_pop_val(struct mbuf *m);
MJS_PRIVATE mjs_val_t mjs_pop(struct mjs *mjs);
MJS_PRIVATE void mjs_push(struct mjs *mjs, mjs_val_t v);
#endif /* MJS_CORE_H */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_conversion.h"
#endif
/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_CONVERSION_H_
#define MJS_CONVERSION_H_

/* Amalgamated: #include "mjs/src/mjs_internal.h" */
/* Amalgamated: #include "mjs/src/mjs_core.h" */

/*
 * Tries to convert `mjs_val_t` to a string, returns MJS_OK if successful.
 * String is returned as a pair of pointers: `char **p, size_t *sizep`.
 *
 * Caller must also provide a non-null `need_free`, and if it is non-zero,
 * then the string `*p` should be freed by the caller.
 *
 * MJS does not support `toString()` and `valueOf()`, so, passing an object
 * always results in `MJS_TYPE_ERROR`.
 */
MJS_PRIVATE mjs_err_t mjs_to_string(struct mjs *mjs, mjs_val_t *v, char **p,
                                    size_t *sizep, int *need_free);

/*
 * Converts value to boolean as in the expression `if (v)`.
 */
MJS_PRIVATE mjs_val_t mjs_to_boolean_v(struct mjs *mjs, mjs_val_t v);

MJS_PRIVATE int mjs_is_truthy(struct mjs *mjs, mjs_val_t v);

#endif /* MJS_CONVERSION_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_object_public.h"
#endif
/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_OBJECT_PUBLIC_H_
#define MJS_OBJECT_PUBLIC_H_

/* Amalgamated: #include "mjs/src/mjs_core_public.h" */
#include <stddef.h>

/*
 * Returns true if the given value is an object or array.
 */
int mjs_is_object(mjs_val_t v);

/* Make an empty object */
mjs_val_t mjs_mk_object(struct mjs *mjs);

/*
 * Lookup property `name` in object `obj`. If `obj` holds no such property,
 * an `undefined` value is returned.
 *
 * If `name_len` is ~0, `name` is assumed to be NUL-terminated and
 * `strlen(name)` is used.
 */
mjs_val_t mjs_get(struct mjs *mjs, mjs_val_t obj, const char *name,
                  size_t name_len);

/*
 * Like mjs_get but with a JS string.
 */
mjs_val_t mjs_get_v(struct mjs *mjs, mjs_val_t obj, mjs_val_t name);

/*
 * Like mjs_get_v but lookup the prototype chain.
 */
mjs_val_t mjs_get_v_proto(struct mjs *mjs, mjs_val_t obj, mjs_val_t key);

/*
 * Set object property. Behaves just like JavaScript assignment.
 */
mjs_err_t mjs_set(struct mjs *mjs, mjs_val_t obj, const char *name, size_t len,
                  mjs_val_t val);

/*
 * Like mjs_set but the name is already a JS string.
 */
mjs_err_t mjs_set_v(struct mjs *mjs, mjs_val_t obj, mjs_val_t name,
                    mjs_val_t val);

/*
 * Iterate over `obj` properties.
 * First call should set `iterator` to MJS_UNDEFINED.
 * Return object's key (a string), or MJS_UNDEFINED when no more keys left.
 * Do not mutate the object during iteration.
 *
 * Example:
 *   mjs_val_t key, iter = MJS_UNDEFINED;
 *   while ((key = mjs_next(mjs, obj, &iter)) != MJS_UNDEFINED) {
 *     // Do something with the obj/key ...
 *   }
 */
mjs_val_t mjs_next(struct mjs *mjs, mjs_val_t obj, mjs_val_t *iterator);

#endif /* MJS_OBJECT_PUBLIC_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_object.h"
#endif
/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_OBJECT_H_
#define MJS_OBJECT_H_

/* Amalgamated: #include "mjs/src/mjs_object_public.h" */
/* Amalgamated: #include "mjs/src/mjs_internal.h" */

struct mjs;

struct mjs_property {
  struct mjs_property *next; /* Linkage in struct mjs_object::properties */
  mjs_val_t name;            /* Property name (a string) */
  mjs_val_t value;           /* Property value */
};

struct mjs_object {
  struct mjs_property *properties;
};

MJS_PRIVATE struct mjs_object *get_object_struct(mjs_val_t v);
MJS_PRIVATE struct mjs_property *mjs_get_own_property(struct mjs *mjs,
                                                      mjs_val_t obj,
                                                      const char *name,
                                                      size_t len);

MJS_PRIVATE struct mjs_property *mjs_get_own_property_v(struct mjs *mjs,
                                                        mjs_val_t obj,
                                                        mjs_val_t key);

#define MJS_PROTO_PROP_NAME "__p" /* Make it < 5 chars */

#endif /* MJS_OBJECT_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_primitive_public.h"
#endif
/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_PRIMITIVE_PUBLIC_H_
#define MJS_PRIMITIVE_PUBLIC_H_

/* Amalgamated: #include "mjs/src/mjs_core_public.h" */

/* JavaScript `null` value */
#define MJS_NULL MJS_TAG_NULL

/* JavaScript `undefined` value */
#define MJS_UNDEFINED MJS_TAG_UNDEFINED

/*
 * Make `null` primitive value.
 *
 * NOTE: this function is deprecated and will be removed in future releases.
 * Use `MJS_NULL` instead.
 */
mjs_val_t mjs_mk_null(void);

/* Returns true if given value is a primitive `null` value */
int mjs_is_null(mjs_val_t v);

/*
 * Make `undefined` primitive value.
 *
 * NOTE: this function is deprecated and will be removed in future releases.
 * Use `MJS_UNDEFINED` instead.
 */
mjs_val_t mjs_mk_undefined(void);

/* Returns true if given value is a primitive `undefined` value */
int mjs_is_undefined(mjs_val_t v);

/* Make numeric primitive value */
mjs_val_t mjs_mk_number(struct mjs *mjs, double num);

/*
 * Returns number value stored in `mjs_val_t` as `double`.
 *
 * Returns NaN for non-numbers.
 */
double mjs_get_double(struct mjs *mjs, mjs_val_t v);

/*
 * Returns number value stored in `mjs_val_t` as `int`. If the number value is
 * not an integer, the fraction part will be discarded.
 *
 * If the given value is a non-number, or NaN, the result is undefined.
 */
int mjs_get_int(struct mjs *mjs, mjs_val_t v);

/*
 * Like mjs_get_int but ensures that the returned type
 * is a 32-bit signed integer.
 */
int32_t mjs_get_int32(struct mjs *mjs, mjs_val_t v);

/* Returns true if given value is a primitive number value */
int mjs_is_number(mjs_val_t v);

/*
 * Make JavaScript value that holds C/C++ `void *` pointer.
 *
 * A foreign value is completely opaque and JS code cannot do anything useful
 * with it except holding it in properties and passing it around.
 * It behaves like a sealed object with no properties.
 *
 * NOTE:
 * Only valid pointers (as defined by each supported architecture) will fully
 * preserved. In particular, all supported 64-bit architectures (x86_64, ARM-64)
 * actually define a 48-bit virtual address space.
 * Foreign values will be sign-extended as required, i.e creating a foreign
 * value of something like `(void *) -1` will work as expected. This is
 * important because in some 64-bit OSs (e.g. Solaris) the user stack grows
 * downwards from the end of the address space.
 *
 * If you need to store exactly sizeof(void*) bytes of raw data where
 * `sizeof(void*)` >= 8, please use byte arrays instead.
 */
mjs_val_t mjs_mk_foreign(struct mjs *mjs, void *ptr);

/*
 * Returns `void *` pointer stored in `mjs_val_t`.
 *
 * Returns NULL if the value is not a foreign pointer.
 */
void *mjs_get_ptr(struct mjs *mjs, mjs_val_t v);

/* Returns true if given value holds `void *` pointer */
int mjs_is_foreign(mjs_val_t v);

mjs_val_t mjs_mk_boolean(struct mjs *mjs, int v);
int mjs_get_bool(struct mjs *mjs, mjs_val_t v);
int mjs_is_boolean(mjs_val_t v);

mjs_val_t mjs_mk_function(struct mjs *mjs, size_t off);
int mjs_is_function(mjs_val_t v);

#endif /* MJS_PRIMITIVE_PUBLIC_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_primitive.h"
#endif
/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_PRIMITIVE_H
#define MJS_PRIMITIVE_H

/* Amalgamated: #include "mjs/src/mjs_primitive_public.h" */
/* Amalgamated: #include "mjs/src/mjs_internal.h" */

MJS_PRIVATE mjs_val_t pointer_to_value(void *p);
MJS_PRIVATE void *get_ptr(mjs_val_t v);

#endif /* MJS_PRIMITIVE_H */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_string_public.h"
#endif
/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_STRING_PUBLIC_H_
#define MJS_STRING_PUBLIC_H_

/* Amalgamated: #include "mjs/src/mjs_core_public.h" */

#define MJS_STRING_LITERAL_MAX_LEN 128

/*
 * Creates a string primitive value.
 * `str` must point to the utf8 string of length `len`.
 * If `len` is ~0, `str` is assumed to be NUL-terminated and `strlen(str)` is
 * used.
 *
 * If `copy` is non-zero, the string data is copied and owned by the GC. The
 * caller can free the string data afterwards. Otherwise (`copy` is zero), the
 * caller owns the string data, and is responsible for not freeing it while it
 * is used.
 */
mjs_val_t mjs_mk_string(struct mjs *mjs, const char *str, size_t len, int copy);

/* Returns true if given value is a primitive string value */
int mjs_is_string(mjs_val_t v);

/*
 * Returns a pointer to the string stored in `mjs_val_t`.
 *
 * String length returned in `len`, which is allowed to be NULL. Returns NULL
 * if the value is not a string.
 *
 * JS strings can contain embedded NUL chars and may or may not be NUL
 * terminated.
 *
 * CAUTION: creating new JavaScript object, array, or string may kick in a
 * garbage collector, which in turn may relocate string data and invalidate
 * pointer returned by `mjs_get_string()`.
 *
 * Short JS strings are embedded inside the `mjs_val_t` value itself. This
 * is why a pointer to a `mjs_val_t` is required. It also means that the string
 * data will become invalid once that `mjs_val_t` value goes out of scope.
 */
const char *mjs_get_string(struct mjs *mjs, mjs_val_t *v, size_t *len);

/*
 * Returns a pointer to the string stored in `mjs_val_t`.
 *
 * Returns NULL if the value is not a string or if the string is not compatible
 * with a C string.
 *
 * C compatible strings contain exactly one NUL char, in terminal position.
 *
 * All strings owned by the MJS engine (see `mjs_mk_string()`) are guaranteed to
 * be NUL terminated. Out of these, those that don't include embedded NUL chars
 * are guaranteed to be C compatible.
 */
const char *mjs_get_cstring(struct mjs *mjs, mjs_val_t *v);

/*
 * Returns the standard strcmp comparison code after comparing a JS string a
 * with a possibly non null-terminated string b. NOTE: the strings are equal
 * only if their length is equal, i.e. the len field doesn't imply strncmp
 * behaviour.
 */
int mjs_strcmp(struct mjs *mjs, mjs_val_t *a, const char *b, size_t len);

#endif /* MJS_STRING_PUBLIC_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_string.h"
#endif
/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_STRING_H_
#define MJS_STRING_H_

/* Amalgamated: #include "mjs/src/mjs_internal.h" */
/* Amalgamated: #include "mjs/src/mjs_string_public.h" */

/*
 * Size of the extra space for strings mbuf that is needed to avoid frequent
 * reallocations
 */
#define _MJS_STRING_BUF_RESERVE 100

MJS_PRIVATE unsigned long cstr_to_ulong(const char *s, size_t len, int *ok);
MJS_PRIVATE mjs_err_t
str_to_ulong(struct mjs *mjs, mjs_val_t v, int *ok, unsigned long *res);
MJS_PRIVATE int s_cmp(struct mjs *mjs, mjs_val_t a, mjs_val_t b);
MJS_PRIVATE mjs_val_t s_concat(struct mjs *mjs, mjs_val_t a, mjs_val_t b);

MJS_PRIVATE void embed_string(struct mbuf *m, size_t offset, const char *p,
                              size_t len, uint8_t /*enum embstr_flags*/ flags);

// MJS_PRIVATE void mjs_string_slice(struct mjs *);
// MJS_PRIVATE void mjs_string_char_code_at(struct mjs *);
// MJS_PRIVATE void mjs_fstr(struct mjs *);

#define EMBSTR_ZERO_TERM 1
#define EMBSTR_UNESCAPE 2

#endif /* MJS_STRING_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_internal.h"
#endif
/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_INTERNAL_H_
#define MJS_INTERNAL_H_

#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#ifndef FAST
#define FAST
#endif

#ifndef STATIC
#define STATIC
#endif

#ifndef ENDL
#define ENDL "\n"
#endif

#ifdef MJS_EXPOSE_PRIVATE
#define MJS_PRIVATE
#define MJS_EXTERN extern
#else
#define MJS_PRIVATE static
#define MJS_EXTERN static
#endif

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#endif

#if !defined(WEAK)
#if (defined(__GNUC__) || defined(__TI_COMPILER_VERSION__)) && !defined(_WIN32)
#define WEAK __attribute__((weak))
#else
#define WEAK
#endif
#endif

#ifndef CS_ENABLE_STDIO
#define CS_ENABLE_STDIO 1
#endif

/* Amalgamated: #include "common/cs_dbg.h" */
/* Amalgamated: #include "common/cs_file.h" */
/* Amalgamated: #include "common/mbuf.h" */

#if defined(_WIN32) && _MSC_VER < 1700
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef __int64 int64_t;
typedef unsigned long uintptr_t;
#define STRX(x) #x
#define STR(x) STRX(x)
#define __func__ __FILE__ ":" STR(__LINE__)
// #define snprintf _snprintf
#define vsnprintf _vsnprintf
#define isnan(x) _isnan(x)
#define va_copy(x, y) (x) = (y)
#define CS_DEFINE_DIRENT
#include <windows.h>
#else
#include <dirent.h>
#if defined(__unix__) || defined(__APPLE__)
#include <dlfcn.h>
#endif
#endif

#endif /* MJS_INTERNAL_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_tok.h"
#endif
/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_TOK_H_
#define MJS_TOK_H_

/* Amalgamated: #include "mjs_internal.h" */

struct tok {
  int tok;
  int len;
  const char *ptr;
};

struct pstate {
  const char *file_name; /* Source code file name */
  const char *buf;       /* Nul-terminated source code buffer */
  const char *pos;       /* Current position */
  int line_no;           /* Line number */
  int last_emitted_line_no;
  struct mbuf offset_lineno_map;
  int prev_tok;   /* Previous token, for prefix increment / decrement */
  struct tok tok; /* Parsed token */
  struct mjs *mjs;
  int start_bcode_idx; /* Index in mjs->bcode at which parsing was started */
};

enum {
  TOK_EOF,

  TOK_COLON,
  TOK_SEMICOLON,
  TOK_COMMA,
  TOK_ASSIGN,
  TOK_OPEN_CURLY,
  TOK_CLOSE_CURLY,
  TOK_OPEN_PAREN,
  TOK_CLOSE_PAREN,
  TOK_OPEN_BRACKET,
  TOK_CLOSE_BRACKET,
  TOK_MUL,
  TOK_PLUS,
  TOK_MINUS,
  TOK_DIV,
  TOK_REM,
  TOK_AND,
  TOK_OR,
  TOK_XOR,
  TOK_DOT,
  TOK_QUESTION,
  TOK_NOT,
  TOK_TILDA,
  TOK_LT,
  TOK_GT,
  TOK_LSHIFT,
  TOK_RSHIFT,
  TOK_MINUS_MINUS,
  TOK_PLUS_PLUS,
  TOK_PLUS_ASSIGN,
  TOK_MINUS_ASSIGN,
  TOK_MUL_ASSIGN,
  TOK_DIV_ASSIGN,
  TOK_AND_ASSIGN,
  TOK_OR_ASSIGN,
  TOK_REM_ASSIGN,
  TOK_XOR_ASSIGN,
  TOK_EQ,
  TOK_NE,
  TOK_LE,
  TOK_GE,
  TOK_LOGICAL_AND,
  TOK_LOGICAL_OR,
  TOK_EQ_EQ,
  TOK_NE_NE,
  TOK_LSHIFT_ASSIGN,
  TOK_RSHIFT_ASSIGN,
  TOK_URSHIFT,
  TOK_URSHIFT_ASSIGN,

  TOK_UNARY_PLUS,
  TOK_UNARY_MINUS,
  TOK_POSTFIX_PLUS,
  TOK_POSTFIX_MINUS,

  TOK_NUM = 200, /* Make sure they don't clash with ascii '+', '{', etc */
  TOK_STR,
  TOK_IDENT,
  TOK_KEYWORD_BREAK,
  TOK_KEYWORD_CASE,
  TOK_KEYWORD_CATCH,
  TOK_KEYWORD_CONTINUE,
  TOK_KEYWORD_DEBUGGER,
  TOK_KEYWORD_DEFAULT,
  TOK_KEYWORD_DELETE,
  TOK_KEYWORD_DO,
  TOK_KEYWORD_ELSE,
  TOK_KEYWORD_FALSE,
  TOK_KEYWORD_FINALLY,
  TOK_KEYWORD_FOR,
  TOK_KEYWORD_FUNCTION,
  TOK_KEYWORD_IF,
  TOK_KEYWORD_IN,
  TOK_KEYWORD_INSTANCEOF,
  TOK_KEYWORD_NEW,
  TOK_KEYWORD_NULL,
  TOK_KEYWORD_RETURN,
  TOK_KEYWORD_SWITCH,
  TOK_KEYWORD_THIS,
  TOK_KEYWORD_THROW,
  TOK_KEYWORD_TRUE,
  TOK_KEYWORD_TRY,
  TOK_KEYWORD_TYPEOF,
  TOK_KEYWORD_VAR,
  TOK_KEYWORD_VOID,
  TOK_KEYWORD_WHILE,
  TOK_KEYWORD_WITH,
  TOK_KEYWORD_LET,
  TOK_KEYWORD_UNDEFINED,
  TOK_MAX
};

MJS_PRIVATE void pinit(const char *file_name, const char *buf, struct pstate *);
MJS_PRIVATE int pnext(struct pstate *);
MJS_PRIVATE int mjs_is_ident(int c);
MJS_PRIVATE int mjs_is_digit(int c);

#endif /* MJS_TOK_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_varint.h"
#endif
/*
 * Copyright (c) 2017 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_VARINT_H_
#define MJS_VARINT_H_

/* Amalgamated: #include "mjs/src/mjs_internal.h" */

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

MJS_PRIVATE int varint_encode(int64_t num, uint8_t *to);
MJS_PRIVATE int64_t varint_decode(const uint8_t *from, int *llen);
MJS_PRIVATE int varint_llen(int64_t num);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* MJS_VARINT_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_dataview.h"
#endif
/*
 * Copyright (c) 2017 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_DATAVIEW_H_
#define MJS_DATAVIEW_H_

/*
 * Functions for memory introspection.
 * These are supposed to be FFI-ed and used from the JS environment.
 */

void *mjs_mem_get_ptr(void *base, int offset);
void mjs_mem_set_ptr(void *ptr, void *val);
double mjs_mem_get_dbl(void *ptr);
void mjs_mem_set_dbl(void *ptr, double val);
unsigned mjs_mem_get_uint(void *ptr, int size, int bigendian);
void mjs_mem_set_uint(void *ptr, unsigned val, int size, int bigendian);
int mjs_mem_get_int(void *ptr, int size, int bigendian);
void mjs_mem_set_int(void *ptr, int val, int size, int bigendian);

#endif /* MJS_DATAVIEW_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_exec_public.h"
#endif
/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_EXEC_PUBLIC_H_
#define MJS_EXEC_PUBLIC_H_

/* Amalgamated: #include "mjs/src/mjs_core_public.h" */
#include <stdio.h>

mjs_err_t mjs_exec(struct mjs *, const char *src, mjs_val_t *res);
mjs_err_t mjs_exec_buf(struct mjs *, const char *src, size_t, mjs_val_t *res);
mjs_err_t mjs_exec_file(struct mjs *mjs, const char *path, mjs_val_t *res);
mjs_err_t mjs_apply(struct mjs *mjs, mjs_val_t *res, mjs_val_t func,
                    mjs_val_t this_val, int nargs, mjs_val_t *args);
mjs_err_t mjs_call(struct mjs *mjs, mjs_val_t *res, mjs_val_t func,
                   mjs_val_t this_val, int nargs, ...);
mjs_val_t mjs_get_this(struct mjs *mjs);

#endif /* MJS_EXEC_PUBLIC_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_exec.h"
#endif
/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_EXEC_H_
#define MJS_EXEC_H_

/* Amalgamated: #include "mjs/src/mjs_exec_public.h" */

/*
 * At the moment, all exec-related functions are public, and are declared in
 * mjs_exec_public.h
 */

#endif /* MJS_EXEC_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_json.h"
#endif
/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_JSON_H_
#define MJS_JSON_H_

MJS_PRIVATE mjs_err_t to_json_or_debug(struct mjs *mjs, mjs_val_t v, char *buf,
                                       size_t size, size_t *res_len,
                                       uint8_t is_debug);

MJS_PRIVATE mjs_err_t mjs_json_stringify(struct mjs *mjs, mjs_val_t v,
                                         char *buf, size_t size, char **res);
MJS_PRIVATE void mjs_op_json_stringify(struct mjs *mjs);
MJS_PRIVATE void mjs_op_json_parse(struct mjs *mjs);

MJS_PRIVATE mjs_err_t
mjs_json_parse(struct mjs *mjs, const char *str, size_t len, mjs_val_t *res);

#endif /* MJS_JSON_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_util_public.h"
#endif
/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_UTIL_PUBLIC_H_
#define MJS_UTIL_PUBLIC_H_

/* Amalgamated: #include "mjs/src/mjs_core_public.h" */
#include <stdio.h>

const char *mjs_typeof(mjs_val_t v);

void mjs_fprintf(mjs_val_t v, struct mjs *mjs, FILE *fp);

#if MJS_ENABLE_DEBUG

void mjs_disasm(const uint8_t *code, size_t len, FILE *fp);
void mjs_dump(struct mjs *mjs, int do_disasm, FILE *fp);

#endif

#endif /* MJS_UTIL_PUBLIC_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_util.h"
#endif
/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_UTIL_H_
#define MJS_UTIL_H_

/* Amalgamated: #include "mjs/src/mjs_util_public.h" */

MJS_PRIVATE const char *opcodetostr(uint8_t opcode);

#endif /* MJS_UTIL_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_bcode.h"
#endif
/*
 * Copyright (c) 2017 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_BCODE_H_
#define MJS_BCODE_H_

/* Amalgamated: #include "mjs/src/mjs_internal.h" */

enum mjs_opcode {
  OP_NOP,          /* ( -- ) */
  OP_DROP,         /* ( a -- ) */
  OP_DUP,          /* ( a -- a a ) */
  OP_SWAP,         /* ( a b -- b a ) */
  OP_JMP,          /* ( -- ) */
  OP_JMP_BACK,     /* ( -- ) */
  OP_JMP_TRUE,     /* ( -- ) */
  OP_JMP_FALSE,    /* ( -- ) */
  OP_FIND_SCOPE,   /* ( a -- a b ) */
  OP_PUSH_SCOPE,   /* ( -- a ) */
  OP_PUSH_STR,     /* ( -- a ) */
  OP_PUSH_TRUE,    /* ( -- a ) */
  OP_PUSH_FALSE,   /* ( -- a ) */
  OP_PUSH_INT,     /* ( -- a ) */
  OP_PUSH_DBL,     /* ( -- a ) */
  OP_PUSH_NULL,    /* ( -- a ) */
  OP_PUSH_UNDEF,   /* ( -- a ) */
  OP_PUSH_OBJ,     /* ( -- a ) */
  OP_PUSH_ARRAY,   /* ( -- a ) */
  OP_PUSH_FUNC,    /* ( -- a ) */
  OP_PUSH_THIS,    /* ( -- a ) */
  OP_GET,          /* ( key obj  -- obj[key] ) */
  OP_CREATE,       /* ( key obj -- ) */
  OP_EXPR,         /* ( ... -- a ) */
  OP_APPEND,       /* ( a b -- ) */
  OP_SET_ARG,      /* ( a -- a ) */
  OP_NEW_SCOPE,    /* ( -- ) */
  OP_DEL_SCOPE,    /* ( -- ) */
  OP_CALL,         /* ( func param1 param2 ... num_params -- result ) */
  OP_RETURN,       /* ( -- ) */
  OP_LOOP,         /* ( -- ) Push break & continue addresses to loop_labels */
  OP_BREAK,        /* ( -- ) */
  OP_CONTINUE,     /* ( -- ) */
  OP_SETRETVAL,    /* ( a -- ) */
  OP_EXIT,         /* ( -- ) */
  OP_BCODE_HEADER, /* ( -- ) */
  OP_SET_THIS,     /* ( -- ) */
  OP_ARGS,         /* ( -- ) Mark the beginning of function call arguments */
  OP_FOR_IN_NEXT,  /* ( name obj iter_ptr -- name obj iter_ptr_next ) */
  OP_MAX
};

struct pstate;
struct mjs;

MJS_PRIVATE void emit_byte(struct pstate *pstate, uint8_t byte);
MJS_PRIVATE void emit_int(struct pstate *pstate, int64_t n);
MJS_PRIVATE void emit_str(struct pstate *pstate, const char *ptr, size_t len);
MJS_PRIVATE size_t mjs_bcode_size(const struct mbuf *mbuf);
MJS_PRIVATE void mjs_bcode_mutate_byte(struct mjs *mbuf, size_t offset,
                                       size_t byte);

#endif /* MJS_BCODE_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_builtin.h"
#endif
/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_BUILTIN_H_
#define MJS_BUILTIN_H_

/* Amalgamated: #include "mjs/src/mjs_internal.h" */

void mjs_init_builtin(struct mjs *mjs, mjs_val_t obj);

#endif /* MJS_BUILTIN_H_ */
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_parser.h"
#endif
/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_PARSER_H
#define MJS_PARSER_H

/* Amalgamated: #include "mjs/src/mjs_internal.h" */

MJS_PRIVATE mjs_err_t
mjs_parse(const char *path, const char *buf, struct mjs *);

#endif /* MJS_PARSER_H */
#ifdef MJS_MODULE_LINES
#line 1 "frozen/frozen.h"
#endif
/*
 * Copyright (c) 2004-2013 Sergey Lyubka <valenok@gmail.com>
 * Copyright (c) 2013 Cesanta Software Limited
 * All rights reserved
 *
 * This library is dual-licensed: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation. For the terms of this
 * license, see <http: *www.gnu.org/licenses/>.
 *
 * You are free to use this library under the terms of the GNU General
 * Public License, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * Alternatively, you can license this library under a commercial
 * license, as set out in <http://cesanta.com/products.html>.
 */

#ifndef CS_FROZEN_FROZEN_H_
#define CS_FROZEN_FROZEN_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

/* JSON token type */
enum json_token_type {
  JSON_TYPE_INVALID = 0, /* memsetting to 0 should create INVALID value */
  JSON_TYPE_STRING,
  JSON_TYPE_NUMBER,
  JSON_TYPE_TRUE,
  JSON_TYPE_FALSE,
  JSON_TYPE_NULL,
  JSON_TYPE_OBJECT_START,
  JSON_TYPE_OBJECT_END,
  JSON_TYPE_ARRAY_START,
  JSON_TYPE_ARRAY_END,

  JSON_TYPES_CNT
};

/*
 * Structure containing token type and value. Used in `json_walk()` and
 * `json_scanf()` with the format specifier `%T`.
 */
struct json_token {
  const char *ptr;           /* Points to the beginning of the value */
  int len;                   /* Value length */
  enum json_token_type type; /* Type of the token, possible values are above */
};

#define JSON_INVALID_TOKEN \
  { 0, 0, JSON_TYPE_INVALID }

/* Error codes */
#define JSON_STRING_INVALID -1
#define JSON_STRING_INCOMPLETE -2

/*
 * Callback-based SAX-like API.
 *
 * Property name and length is given only if it's available: i.e. if current
 * event is an object's property. In other cases, `name` is `NULL`. For
 * example, name is never given:
 *   - For the first value in the JSON string;
 *   - For events JSON_TYPE_OBJECT_END and JSON_TYPE_ARRAY_END
 *
 * E.g. for the input `{ "foo": 123, "bar": [ 1, 2, { "baz": true } ] }`,
 * the sequence of callback invocations will be as follows:
 *
 * - type: JSON_TYPE_OBJECT_START, name: NULL, path: "", value: NULL
 * - type: JSON_TYPE_NUMBER, name: "foo", path: ".foo", value: "123"
 * - type: JSON_TYPE_ARRAY_START,  name: "bar", path: ".bar", value: NULL
 * - type: JSON_TYPE_NUMBER, name: "0", path: ".bar[0]", value: "1"
 * - type: JSON_TYPE_NUMBER, name: "1", path: ".bar[1]", value: "2"
 * - type: JSON_TYPE_OBJECT_START, name: "2", path: ".bar[2]", value: NULL
 * - type: JSON_TYPE_TRUE, name: "baz", path: ".bar[2].baz", value: "true"
 * - type: JSON_TYPE_OBJECT_END, name: NULL, path: ".bar[2]", value: "{ \"baz\":
 *true }"
 * - type: JSON_TYPE_ARRAY_END, name: NULL, path: ".bar", value: "[ 1, 2, {
 *\"baz\": true } ]"
 * - type: JSON_TYPE_OBJECT_END, name: NULL, path: "", value: "{ \"foo\": 123,
 *\"bar\": [ 1, 2, { \"baz\": true } ] }"
 */
typedef void (*json_walk_callback_t)(void *callback_data, const char *name,
                                     size_t name_len, const char *path,
                                     const struct json_token *token);

/*
 * Parse `json_string`, invoking `callback` in a way similar to SAX parsers;
 * see `json_walk_callback_t`.
 */
int json_walk(const char *json_string, int json_string_length,
              json_walk_callback_t callback, void *callback_data);

/*
 * JSON generation API.
 * struct json_out abstracts output, allowing alternative printing plugins.
 */
struct json_out {
  int (*printer)(struct json_out *, const char *str, size_t len);
  union {
    struct {
      char *buf;
      size_t size;
      size_t len;
    } buf;
    void *data;
    FILE *fp;
  } u;
};

extern int json_printer_buf(struct json_out *, const char *, size_t);
extern int json_printer_file(struct json_out *, const char *, size_t);

#define JSON_OUT_BUF(buf, len) \
  {                            \
    json_printer_buf, {        \
      { buf, len, 0 }          \
    }                          \
  }
#define JSON_OUT_FILE(fp)   \
  {                         \
    json_printer_file, {    \
      { (void *) fp, 0, 0 } \
    }                       \
  }

typedef int (*json_printf_callback_t)(struct json_out *, va_list *ap);

/*
 * Generate formatted output into a given sting buffer.
 * This is a superset of printf() function, with extra format specifiers:
 *  - `%B` print json boolean, `true` or `false`. Accepts an `int`.
 *  - `%Q` print quoted escaped string or `null`. Accepts a `const char *`.
 *  - `%.*Q` same as `%Q`, but with length. Accepts `int`, `const char *`
 *  - `%V` print quoted base64-encoded string. Accepts a `const char *`, `int`.
 *  - `%H` print quoted hex-encoded string. Accepts a `int`, `const char *`.
 *  - `%M` invokes a json_printf_callback_t function. That callback function
 *  can consume more parameters.
 *
 * Return number of bytes printed. If the return value is bigger then the
 * supplied buffer, that is an indicator of overflow. In the overflow case,
 * overflown bytes are not printed.
 */
int json_printf(struct json_out *, const char *fmt, ...);
int json_vprintf(struct json_out *, const char *fmt, va_list ap);

/*
 * Helper %M callback that prints contiguous C arrays.
 * Consumes void *array_ptr, size_t array_size, size_t elem_size, char *fmt
 * Return number of bytes printed.
 */
int json_printf_array(struct json_out *, va_list *ap);

/*
 * Scan JSON string `str`, performing scanf-like conversions according to `fmt`.
 * This is a `scanf()` - like function, with following differences:
 *
 * 1. Object keys in the format string may be not quoted, e.g. "{key: %d}"
 * 2. Order of keys in an object is irrelevant.
 * 3. Several extra format specifiers are supported:
 *    - %B: consumes `int *`, expects boolean `true` or `false`.
 *    - %Q: consumes `char **`, expects quoted, JSON-encoded string. Scanned
 *       string is malloc-ed, caller must free() the string.
 *    - %V: consumes `char **`, `int *`. Expects base64-encoded string.
 *       Result string is base64-decoded, malloced and NUL-terminated.
 *       The length of result string is stored in `int *` placeholder.
 *       Caller must free() the result.
 *    - %H: consumes `int *`, `char **`.
 *       Expects a hex-encoded string, e.g. "fa014f".
 *       Result string is hex-decoded, malloced and NUL-terminated.
 *       The length of the result string is stored in `int *` placeholder.
 *       Caller must free() the result.
 *    - %M: consumes custom scanning function pointer and
 *       `void *user_data` parameter - see json_scanner_t definition.
 *    - %T: consumes `struct json_token *`, fills it out with matched token.
 *
 * Return number of elements successfully scanned & converted.
 * Negative number means scan error.
 */
int json_scanf(const char *str, int str_len, const char *fmt, ...);
int json_vscanf(const char *str, int str_len, const char *fmt, va_list ap);

/* json_scanf's %M handler  */
typedef void (*json_scanner_t)(const char *str, int len, void *user_data);

/*
 * Helper function to scan array item with given path and index.
 * Fills `token` with the matched JSON token.
 * Return 0 if no array element found, otherwise non-0.
 */
int json_scanf_array_elem(const char *s, int len, const char *path, int index,
                          struct json_token *token);

/*
 * Unescape JSON-encoded string src,slen into dst, dlen.
 * src and dst may overlap.
 * If destination buffer is too small (or zero-length), result string is not
 * written but the length is counted nevertheless (similar to snprintf).
 * Return the length of unescaped string in bytes.
 */
int json_unescape(const char *src, int slen, char *dst, int dlen);

/*
 * Escape a string `str`, `str_len` into the printer `out`.
 * Return the number of bytes printed.
 */
int json_escape(struct json_out *out, const char *str, size_t str_len);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CS_FROZEN_FROZEN_H_ */
#ifndef MJS_EXPORT_INTERNAL_HEADERS
#ifdef MJS_MODULE_LINES
#line 1 "common/cs_dbg.c"
#endif
/*
 * Copyright (c) 2014-2016 Cesanta Software Limited
 * All rights reserved
 */

/* Amalgamated: #include "common/cs_dbg.h" */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/* Amalgamated: #include "common/cs_time.h" */

enum cs_log_level cs_log_level WEAK =
#if CS_ENABLE_DEBUG
    LL_VERBOSE_DEBUG;
#else
    LL_ERROR;
#endif

#if CS_ENABLE_STDIO

FILE *cs_log_file WEAK = NULL;

#if CS_LOG_ENABLE_TS_DIFF
double cs_log_ts WEAK;
#endif

void cs_log_print_prefix(const char *func) WEAK;
void cs_log_print_prefix(const char *func) {
  char prefix[21];
  strncpy(prefix, func, 20);
  prefix[20] = '\0';
  if (cs_log_file == NULL) cs_log_file = stderr;
  fprintf(cs_log_file, "%-20s ", prefix);
#if CS_LOG_ENABLE_TS_DIFF
  {
    double now = cs_time();
    fprintf(cs_log_file, "%7u ", (unsigned int) ((now - cs_log_ts) * 1000000));
    cs_log_ts = now;
  }
#endif
}

void cs_log_printf(const char *fmt, ...) WEAK;
void cs_log_printf(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  vfprintf(cs_log_file, fmt, ap);
  va_end(ap);
  fputc('\n', cs_log_file);
  fflush(cs_log_file);
}

void cs_log_set_file(FILE *file) WEAK;
void cs_log_set_file(FILE *file) {
  cs_log_file = file;
}

#endif /* CS_ENABLE_STDIO */

void cs_log_set_level(enum cs_log_level level) WEAK;
void cs_log_set_level(enum cs_log_level level) {
  cs_log_level = level;
#if CS_LOG_ENABLE_TS_DIFF && CS_ENABLE_STDIO
  cs_log_ts = cs_time();
#endif
}
#ifdef MJS_MODULE_LINES
#line 1 "common/cs_file.c"
#endif
/*
 * Copyright (c) 2015 Cesanta Software Limited
 * All rights reserved
 */

/* Amalgamated: #include "common/cs_file.h" */

#include <stdio.h>
#include <stdlib.h>

#ifdef CS_MMAP
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#endif

#ifndef EXCLUDE_COMMON
char *cs_read_file(const char *path, size_t *size) WEAK;
char *cs_read_file(const char *path, size_t *size) {
  FILE *fp;
  char *data = NULL;
  if ((fp = fopen(path, "rb")) == NULL) {
  } else if (fseek(fp, 0, SEEK_END) != 0) {
    fclose(fp);
  } else {
    *size = ftell(fp);
    data = (char *) malloc(*size + 1);
    if (data != NULL) {
      fseek(fp, 0, SEEK_SET); /* Some platforms might not have rewind(), Oo */
      if (fread(data, 1, *size, fp) != *size) {
        free(data);
        return NULL;
      }
      data[*size] = '\0';
    }
    fclose(fp);
  }
  return data;
}
#endif /* EXCLUDE_COMMON */

#ifdef CS_MMAP
char *cs_mmap_file(const char *path, size_t *size) WEAK;
char *cs_mmap_file(const char *path, size_t *size) {
  char *r;
  int fd = open(path, O_RDONLY);
  struct stat st;
  if (fd == -1) return NULL;
  fstat(fd, &st);
  *size = (size_t) st.st_size;
  r = (char *) mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  if (r == MAP_FAILED) return NULL;
  return r;
}
#endif
#ifdef MJS_MODULE_LINES
#line 1 "common/mbuf.c"
#endif
/*
 * Copyright (c) 2014 Cesanta Software Limited
 * All rights reserved
 */

#ifndef EXCLUDE_COMMON

#include <assert.h>
#include <string.h>
/* Amalgamated: #include "common/mbuf.h" */

#ifndef MBUF_REALLOC
#define MBUF_REALLOC realloc
#endif

#ifndef MBUF_FREE
#define MBUF_FREE free
#endif

void mbuf_init(struct mbuf *mbuf, size_t initial_size) WEAK;
void mbuf_init(struct mbuf *mbuf, size_t initial_size) {
  mbuf->len = mbuf->size = 0;
  mbuf->buf = NULL;
  mbuf_resize(mbuf, initial_size);
}

void mbuf_free(struct mbuf *mbuf) WEAK;
void mbuf_free(struct mbuf *mbuf) {
  if (mbuf->buf != NULL) {
    MBUF_FREE(mbuf->buf);
    mbuf_init(mbuf, 0);
  }
}

void mbuf_resize(struct mbuf *a, size_t new_size) WEAK;
void mbuf_resize(struct mbuf *a, size_t new_size) {
  if (new_size > a->size || (new_size < a->size && new_size >= a->len)) {
    char *buf = (char *) MBUF_REALLOC(a->buf, new_size);
    /*
     * In case realloc fails, there's not much we can do, except keep things as
     * they are. Note that NULL is a valid return value from realloc when
     * size == 0, but that is covered too.
     */
    if (buf == NULL && new_size != 0) return;
    a->buf = buf;
    a->size = new_size;
  }
}

void mbuf_trim(struct mbuf *mbuf) WEAK;
void mbuf_trim(struct mbuf *mbuf) {
  mbuf_resize(mbuf, mbuf->len);
}

size_t mbuf_insert(struct mbuf *a, size_t off, const void *buf, size_t) WEAK;
size_t mbuf_insert(struct mbuf *a, size_t off, const void *buf, size_t len) {
  char *p = NULL;

  assert(a != NULL);
  assert(a->len <= a->size);
  assert(off <= a->len);

  /* check overflow */
  if (~(size_t) 0 - (size_t) a->buf < len) return 0;

  if (a->len + len <= a->size) {
    memmove(a->buf + off + len, a->buf + off, a->len - off);
    if (buf != NULL) {
      memcpy(a->buf + off, buf, len);
    }
    a->len += len;
  } else {
    size_t new_size = (size_t)((a->len + len) * MBUF_SIZE_MULTIPLIER);
    if ((p = (char *) MBUF_REALLOC(a->buf, new_size)) != NULL) {
      a->buf = p;
      memmove(a->buf + off + len, a->buf + off, a->len - off);
      if (buf != NULL) memcpy(a->buf + off, buf, len);
      a->len += len;
      a->size = new_size;
    } else {
      len = 0;
    }
  }

  return len;
}

size_t mbuf_append(struct mbuf *a, const void *buf, size_t len) WEAK;
size_t mbuf_append(struct mbuf *a, const void *buf, size_t len) {
  return mbuf_insert(a, a->len, buf, len);
}

void mbuf_remove(struct mbuf *mb, size_t n) WEAK;
void mbuf_remove(struct mbuf *mb, size_t n) {
  if (n > 0 && n <= mb->len) {
    memmove(mb->buf, mb->buf + n, mb->len - n);
    mb->len -= n;
  }
}

#endif /* EXCLUDE_COMMON */
#ifdef MJS_MODULE_LINES
#line 1 "common/str_util.c"
#endif
/*
 * Copyright (c) 2015 Cesanta Software Limited
 * All rights reserved
 */

#ifndef EXCLUDE_COMMON

/* Amalgamated: #include "common/mg_mem.h" */
/* Amalgamated: #include "common/platform.h" */
/* Amalgamated: #include "common/str_util.h" */

#ifndef C_DISABLE_BUILTIN_SNPRINTF
#define C_DISABLE_BUILTIN_SNPRINTF 0
#endif

/* Amalgamated: #include "common/mg_mem.h" */

size_t c_strnlen(const char *s, size_t maxlen) WEAK;
size_t c_strnlen(const char *s, size_t maxlen) {
  size_t l = 0;
  for (; l < maxlen && s[l] != '\0'; l++) {
  }
  return l;
}

#define C_SNPRINTF_APPEND_CHAR(ch)       \
  do {                                   \
    if (i < (int) buf_size) buf[i] = ch; \
    i++;                                 \
  } while (0)

#define C_SNPRINTF_FLAG_ZERO 1

#if C_DISABLE_BUILTIN_SNPRINTF
int c_vsnprintf(char *buf, size_t buf_size, const char *fmt, va_list ap) WEAK;
int c_vsnprintf(char *buf, size_t buf_size, const char *fmt, va_list ap) {
  return vsnprintf(buf, buf_size, fmt, ap);
}
#else
static int c_itoa(char *buf, size_t buf_size, int64_t num, int base, int flags,
                  int field_width) {
  char tmp[40];
  int i = 0, k = 0, neg = 0;

  if (num < 0) {
    neg++;
    num = -num;
  }

  /* Print into temporary buffer - in reverse order */
  do {
    int rem = num % base;
    if (rem < 10) {
      tmp[k++] = '0' + rem;
    } else {
      tmp[k++] = 'a' + (rem - 10);
    }
    num /= base;
  } while (num > 0);

  /* Zero padding */
  if (flags && C_SNPRINTF_FLAG_ZERO) {
    while (k < field_width && k < (int) sizeof(tmp) - 1) {
      tmp[k++] = '0';
    }
  }

  /* And sign */
  if (neg) {
    tmp[k++] = '-';
  }

  /* Now output */
  while (--k >= 0) {
    C_SNPRINTF_APPEND_CHAR(tmp[k]);
  }

  return i;
}

int c_vsnprintf(char *buf, size_t buf_size, const char *fmt, va_list ap) WEAK;
int c_vsnprintf(char *buf, size_t buf_size, const char *fmt, va_list ap) {
  int ch, i = 0, len_mod, flags, precision, field_width;

  while ((ch = *fmt++) != '\0') {
    if (ch != '%') {
      C_SNPRINTF_APPEND_CHAR(ch);
    } else {
      /*
       * Conversion specification:
       *   zero or more flags (one of: # 0 - <space> + ')
       *   an optional minimum  field  width (digits)
       *   an  optional precision (. followed by digits, or *)
       *   an optional length modifier (one of: hh h l ll L q j z t)
       *   conversion specifier (one of: d i o u x X e E f F g G a A c s p n)
       */
      flags = field_width = precision = len_mod = 0;

      /* Flags. only zero-pad flag is supported. */
      if (*fmt == '0') {
        flags |= C_SNPRINTF_FLAG_ZERO;
      }

      /* Field width */
      while (*fmt >= '0' && *fmt <= '9') {
        field_width *= 10;
        field_width += *fmt++ - '0';
      }
      /* Dynamic field width */
      if (*fmt == '*') {
        field_width = va_arg(ap, int);
        fmt++;
      }

      /* Precision */
      if (*fmt == '.') {
        fmt++;
        if (*fmt == '*') {
          precision = va_arg(ap, int);
          fmt++;
        } else {
          while (*fmt >= '0' && *fmt <= '9') {
            precision *= 10;
            precision += *fmt++ - '0';
          }
        }
      }

      /* Length modifier */
      switch (*fmt) {
        case 'h':
        case 'l':
        case 'L':
        case 'I':
        case 'q':
        case 'j':
        case 'z':
        case 't':
          len_mod = *fmt++;
          if (*fmt == 'h') {
            len_mod = 'H';
            fmt++;
          }
          if (*fmt == 'l') {
            len_mod = 'q';
            fmt++;
          }
          break;
      }

      ch = *fmt++;
      if (ch == 's') {
        const char *s = va_arg(ap, const char *); /* Always fetch parameter */
        int j;
        int pad = field_width - (precision >= 0 ? c_strnlen(s, precision) : 0);
        for (j = 0; j < pad; j++) {
          C_SNPRINTF_APPEND_CHAR(' ');
        }

        /* `s` may be NULL in case of %.*s */
        if (s != NULL) {
          /* Ignore negative and 0 precisions */
          for (j = 0; (precision <= 0 || j < precision) && s[j] != '\0'; j++) {
            C_SNPRINTF_APPEND_CHAR(s[j]);
          }
        }
      } else if (ch == 'c') {
        ch = va_arg(ap, int); /* Always fetch parameter */
        C_SNPRINTF_APPEND_CHAR(ch);
      } else if (ch == 'd' && len_mod == 0) {
        i += c_itoa(buf + i, buf_size - i, va_arg(ap, int), 10, flags,
                    field_width);
      } else if (ch == 'd' && len_mod == 'l') {
        i += c_itoa(buf + i, buf_size - i, va_arg(ap, long), 10, flags,
                    field_width);
#ifdef SSIZE_MAX
      } else if (ch == 'd' && len_mod == 'z') {
        i += c_itoa(buf + i, buf_size - i, va_arg(ap, ssize_t), 10, flags,
                    field_width);
#endif
      } else if (ch == 'd' && len_mod == 'q') {
        i += c_itoa(buf + i, buf_size - i, va_arg(ap, int64_t), 10, flags,
                    field_width);
      } else if ((ch == 'x' || ch == 'u') && len_mod == 0) {
        i += c_itoa(buf + i, buf_size - i, va_arg(ap, unsigned),
                    ch == 'x' ? 16 : 10, flags, field_width);
      } else if ((ch == 'x' || ch == 'u') && len_mod == 'l') {
        i += c_itoa(buf + i, buf_size - i, va_arg(ap, unsigned long),
                    ch == 'x' ? 16 : 10, flags, field_width);
      } else if ((ch == 'x' || ch == 'u') && len_mod == 'z') {
        i += c_itoa(buf + i, buf_size - i, va_arg(ap, size_t),
                    ch == 'x' ? 16 : 10, flags, field_width);
      } else if (ch == 'p') {
        unsigned long num = (unsigned long) (uintptr_t) va_arg(ap, void *);
        C_SNPRINTF_APPEND_CHAR('0');
        C_SNPRINTF_APPEND_CHAR('x');
        i += c_itoa(buf + i, buf_size - i, num, 16, flags, 0);
      } else {
#ifndef NO_LIBC
        /*
         * TODO(lsm): abort is not nice in a library, remove it
         * Also, ESP8266 SDK doesn't have it
         */
        abort();
#endif
      }
    }
  }

  /* Zero-terminate the result */
  if (buf_size > 0) {
    buf[i < (int) buf_size ? i : (int) buf_size - 1] = '\0';
  }

  return i;
}
#endif

int c_snprintf(char *buf, size_t buf_size, const char *fmt, ...) WEAK;
int c_snprintf(char *buf, size_t buf_size, const char *fmt, ...) {
  int result;
  va_list ap;
  va_start(ap, fmt);
  result = c_vsnprintf(buf, buf_size, fmt, ap);
  va_end(ap);
  return result;
}

#ifdef _WIN32
int to_wchar(const char *path, wchar_t *wbuf, size_t wbuf_len) {
  int ret;
  char buf[MAX_PATH * 2], buf2[MAX_PATH * 2], *p;

  strncpy(buf, path, sizeof(buf));
  buf[sizeof(buf) - 1] = '\0';

  /* Trim trailing slashes. Leave backslash for paths like "X:\" */
  p = buf + strlen(buf) - 1;
  while (p > buf && p[-1] != ':' && (p[0] == '\\' || p[0] == '/')) *p-- = '\0';

  memset(wbuf, 0, wbuf_len * sizeof(wchar_t));
  ret = MultiByteToWideChar(CP_UTF8, 0, buf, -1, wbuf, (int) wbuf_len);

  /*
   * Convert back to Unicode. If doubly-converted string does not match the
   * original, something is fishy, reject.
   */
  WideCharToMultiByte(CP_UTF8, 0, wbuf, (int) wbuf_len, buf2, sizeof(buf2),
                      NULL, NULL);
  if (strcmp(buf, buf2) != 0) {
    wbuf[0] = L'\0';
    ret = 0;
  }

  return ret;
}
#endif /* _WIN32 */

/* The simplest O(mn) algorithm. Better implementation are GPLed */
const char *c_strnstr(const char *s, const char *find, size_t slen) WEAK;
const char *c_strnstr(const char *s, const char *find, size_t slen) {
  size_t find_length = strlen(find);
  size_t i;

  for (i = 0; i < slen; i++) {
    if (i + find_length > slen) {
      return NULL;
    }

    if (strncmp(&s[i], find, find_length) == 0) {
      return &s[i];
    }
  }

  return NULL;
}

#if CS_ENABLE_STRDUP
char *strdup(const char *src) WEAK;
char *strdup(const char *src) {
  size_t len = strlen(src) + 1;
  char *ret = MG_MALLOC(len);
  if (ret != NULL) {
    strcpy(ret, src);
  }
  return ret;
}
#endif

void cs_to_hex(char *to, const unsigned char *p, size_t len) WEAK;
void cs_to_hex(char *to, const unsigned char *p, size_t len) {
  static const char *hex = "0123456789abcdef";

  for (; len--; p++) {
    *to++ = hex[p[0] >> 4];
    *to++ = hex[p[0] & 0x0f];
  }
  *to = '\0';
}

static int fourbit(int ch) {
  if (ch >= '0' && ch <= '9') {
    return ch - '0';
  } else if (ch >= 'a' && ch <= 'f') {
    return ch - 'a' + 10;
  } else if (ch >= 'A' && ch <= 'F') {
    return ch - 'A' + 10;
  }
  return 0;
}

void cs_from_hex(char *to, const char *p, size_t len) WEAK;
void cs_from_hex(char *to, const char *p, size_t len) {
  size_t i;

  for (i = 0; i < len; i += 2) {
    *to++ = (fourbit(p[i]) << 4) + fourbit(p[i + 1]);
  }
  *to = '\0';
}

#if CS_ENABLE_TO64
int64_t cs_to64(const char *s) WEAK;
int64_t cs_to64(const char *s) {
  int64_t result = 0;
  int64_t neg = 1;
  while (*s && isspace((unsigned char) *s)) s++;
  if (*s == '-') {
    neg = -1;
    s++;
  }
  while (isdigit((unsigned char) *s)) {
    result *= 10;
    result += (*s - '0');
    s++;
  }
  return result * neg;
}
#endif

static int str_util_lowercase(const char *s) {
  return tolower(*(const unsigned char *) s);
}

int mg_ncasecmp(const char *s1, const char *s2, size_t len) WEAK;
int mg_ncasecmp(const char *s1, const char *s2, size_t len) {
  int diff = 0;

  if (len > 0) do {
      diff = str_util_lowercase(s1++) - str_util_lowercase(s2++);
    } while (diff == 0 && s1[-1] != '\0' && --len > 0);

  return diff;
}

int mg_casecmp(const char *s1, const char *s2) WEAK;
int mg_casecmp(const char *s1, const char *s2) {
  return mg_ncasecmp(s1, s2, (size_t) ~0);
}

int mg_asprintf(char **buf, size_t size, const char *fmt, ...) WEAK;
int mg_asprintf(char **buf, size_t size, const char *fmt, ...) {
  int ret;
  va_list ap;
  va_start(ap, fmt);
  ret = mg_avprintf(buf, size, fmt, ap);
  va_end(ap);
  return ret;
}

int mg_avprintf(char **buf, size_t size, const char *fmt, va_list ap) WEAK;
int mg_avprintf(char **buf, size_t size, const char *fmt, va_list ap) {
  va_list ap_copy;
  int len;

  va_copy(ap_copy, ap);
  len = vsnprintf(*buf, size, fmt, ap_copy);
  va_end(ap_copy);

  if (len < 0) {
    /* eCos and Windows are not standard-compliant and return -1 when
     * the buffer is too small. Keep allocating larger buffers until we
     * succeed or out of memory. */
    *buf = NULL; /* LCOV_EXCL_START */
    while (len < 0) {
      MG_FREE(*buf);
      size *= 2;
      if ((*buf = (char *) MG_MALLOC(size)) == NULL) break;
      va_copy(ap_copy, ap);
      len = vsnprintf(*buf, size, fmt, ap_copy);
      va_end(ap_copy);
    }
    /* LCOV_EXCL_STOP */
  } else if (len >= (int) size) {
    /* Standard-compliant code path. Allocate a buffer that is large enough. */
    if ((*buf = (char *) MG_MALLOC(len + 1)) == NULL) {
      len = -1; /* LCOV_EXCL_LINE */
    } else {    /* LCOV_EXCL_LINE */
      va_copy(ap_copy, ap);
      len = vsnprintf(*buf, len + 1, fmt, ap_copy);
      va_end(ap_copy);
    }
  }

  return len;
}

#endif /* EXCLUDE_COMMON */
#ifdef MJS_MODULE_LINES
#line 1 "frozen/frozen.c"
#endif
/*
 * Copyright (c) 2004-2013 Sergey Lyubka <valenok@gmail.com>
 * Copyright (c) 2013 Cesanta Software Limited
 * All rights reserved
 *
 * This library is dual-licensed: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation. For the terms of this
 * license, see <http: *www.gnu.org/licenses/>.
 *
 * You are free to use this library under the terms of the GNU General
 * Public License, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * Alternatively, you can license this library under a commercial
 * license, as set out in <http://cesanta.com/products.html>.
 */

#define _CRT_SECURE_NO_WARNINGS /* Disable deprecation warning in VS2005+ */

/* Amalgamated: #include "frozen.h" */
#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if !defined(WEAK)
#if (defined(__GNUC__) || defined(__TI_COMPILER_VERSION__)) && !defined(_WIN32)
#define WEAK __attribute__((weak))
#else
#define WEAK
#endif
#endif

#ifdef _WIN32
#define snprintf cs_win_snprintf
#define vsnprintf cs_win_vsnprintf
int cs_win_snprintf(char *str, size_t size, const char *format, ...);
int cs_win_vsnprintf(char *str, size_t size, const char *format, va_list ap);
#if _MSC_VER >= 1700
#include <stdint.h>
#else
typedef _int64 int64_t;
typedef unsigned _int64 uint64_t;
#endif
#define PRId64 "I64d"
#define PRIu64 "I64u"
#if !defined(SIZE_T_FMT)
#if _MSC_VER >= 1310
#define SIZE_T_FMT "Iu"
#else
#define SIZE_T_FMT "u"
#endif
#endif
#else /* _WIN32 */
/* <inttypes.h> wants this for C++ */
#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS
#endif
#include <inttypes.h>
#if !defined(SIZE_T_FMT)
#define SIZE_T_FMT "zu"
#endif
#endif /* _WIN32 */

#define INT64_FMT PRId64
#define UINT64_FMT PRIu64

#ifndef va_copy
#define va_copy(x, y) x = y
#endif

#ifndef JSON_MAX_PATH_LEN
#define JSON_MAX_PATH_LEN 60
#endif

struct frozen {
  const char *end;
  const char *cur;

  const char *cur_name;
  size_t cur_name_len;

  /* For callback API */
  char path[JSON_MAX_PATH_LEN];
  size_t path_len;
  void *callback_data;
  json_walk_callback_t callback;
};

struct fstate {
  const char *ptr;
  size_t path_len;
};

#define SET_STATE(fr, ptr, str, len)              \
  struct fstate fstate = {(ptr), (fr)->path_len}; \
  append_to_path((fr), (str), (len));

#define CALL_BACK(fr, tok, value, len)                                        \
  do {                                                                        \
    if ((fr)->callback &&                                                     \
        ((fr)->path_len == 0 || (fr)->path[(fr)->path_len - 1] != '.')) {     \
      struct json_token t = {(value), (len), (tok)};                          \
                                                                              \
      /* Call the callback with the given value and current name */           \
      (fr)->callback((fr)->callback_data, (fr)->cur_name, (fr)->cur_name_len, \
                     (fr)->path, &t);                                         \
                                                                              \
      /* Reset the name */                                                    \
      (fr)->cur_name = NULL;                                                  \
      (fr)->cur_name_len = 0;                                                 \
    }                                                                         \
  } while (0)

static int append_to_path(struct frozen *f, const char *str, int size) {
  int n = f->path_len;
  f->path_len +=
      snprintf(f->path + f->path_len, sizeof(f->path) - (f->path_len), "%.*s", size, str);
  if (f->path_len > sizeof(f->path) - 1) {
    f->path_len = sizeof(f->path) - 1;
  }

  return n;
}

static void truncate_path(struct frozen *f, size_t len) {
  f->path_len = len;
  f->path[len] = '\0';
}

static int parse_object(struct frozen *f);
static int parse_value(struct frozen *f);

#define EXPECT(cond, err_code)      \
  do {                              \
    if (!(cond)) return (err_code); \
  } while (0)

#define TRY(expr)          \
  do {                     \
    int _n = expr;         \
    if (_n < 0) return _n; \
  } while (0)

#define END_OF_STRING (-1)

static int left(const struct frozen *f) {
  return f->end - f->cur;
}

static int is_space(int ch) {
  return ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n';
}

static void skip_whitespaces(struct frozen *f) {
  while (f->cur < f->end && is_space(*f->cur)) f->cur++;
}

static int cur(struct frozen *f) {
  skip_whitespaces(f);
  return f->cur >= f->end ? END_OF_STRING : *(unsigned char *) f->cur;
}

static int test_and_skip(struct frozen *f, int expected) {
  int ch = cur(f);
  if (ch == expected) {
    f->cur++;
    return 0;
  }
  return ch == END_OF_STRING ? JSON_STRING_INCOMPLETE : JSON_STRING_INVALID;
}

static int is_alpha(int ch) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

static int is_digit(int ch) {
  return ch >= '0' && ch <= '9';
}

static int is_hex_digit(int ch) {
  return is_digit(ch) || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F');
}

static int get_escape_len(const char *s, int len) {
  switch (*s) {
    case 'u':
      return len < 6 ? JSON_STRING_INCOMPLETE
                     : is_hex_digit(s[1]) && is_hex_digit(s[2]) &&
                               is_hex_digit(s[3]) && is_hex_digit(s[4])
                           ? 5
                           : JSON_STRING_INVALID;
    case '"':
    case '\\':
    case '/':
    case 'b':
    case 'f':
    case 'n':
    case 'r':
    case 't':
      return len < 2 ? JSON_STRING_INCOMPLETE : 1;
    default:
      return JSON_STRING_INVALID;
  }
}

/* identifier = letter { letter | digit | '_' } */
static int parse_identifier(struct frozen *f) {
  EXPECT(is_alpha(cur(f)), JSON_STRING_INVALID);
  {
    SET_STATE(f, f->cur, "", 0);
    while (f->cur < f->end &&
           (*f->cur == '_' || is_alpha(*f->cur) || is_digit(*f->cur))) {
      f->cur++;
    }
    truncate_path(f, fstate.path_len);
    CALL_BACK(f, JSON_TYPE_STRING, fstate.ptr, f->cur - fstate.ptr);
  }
  return 0;
}

static int get_utf8_char_len(unsigned char ch) {
  if ((ch & 0x80) == 0) return 1;
  switch (ch & 0xf0) {
    case 0xf0:
      return 4;
    case 0xe0:
      return 3;
    default:
      return 2;
  }
}

/* string = '"' { quoted_printable_chars } '"' */
static int parse_string(struct frozen *f) {
  int n, ch = 0, len = 0;
  TRY(test_and_skip(f, '"'));
  {
    SET_STATE(f, f->cur, "", 0);
    for (; f->cur < f->end; f->cur += len) {
      ch = *(unsigned char *) f->cur;
      len = get_utf8_char_len((unsigned char) ch);
      EXPECT(ch >= 32 && len > 0, JSON_STRING_INVALID); /* No control chars */
      EXPECT(len < left(f), JSON_STRING_INCOMPLETE);
      if (ch == '\\') {
        EXPECT((n = get_escape_len(f->cur + 1, left(f))) > 0, n);
        len += n;
      } else if (ch == '"') {
        truncate_path(f, fstate.path_len);
        CALL_BACK(f, JSON_TYPE_STRING, fstate.ptr, f->cur - fstate.ptr);
        f->cur++;
        break;
      };
    }
  }
  return ch == '"' ? 0 : JSON_STRING_INCOMPLETE;
}

/* number = [ '-' ] digit+ [ '.' digit+ ] [ ['e'|'E'] ['+'|'-'] digit+ ] */
static int parse_number(struct frozen *f) {
  int ch = cur(f);
  SET_STATE(f, f->cur, "", 0);
  if (ch == '-') f->cur++;
  EXPECT(f->cur < f->end, JSON_STRING_INCOMPLETE);
  EXPECT(is_digit(f->cur[0]), JSON_STRING_INVALID);
  while (f->cur < f->end && is_digit(f->cur[0])) f->cur++;
  if (f->cur < f->end && f->cur[0] == '.') {
    f->cur++;
    EXPECT(f->cur < f->end, JSON_STRING_INCOMPLETE);
    EXPECT(is_digit(f->cur[0]), JSON_STRING_INVALID);
    while (f->cur < f->end && is_digit(f->cur[0])) f->cur++;
  }
  if (f->cur < f->end && (f->cur[0] == 'e' || f->cur[0] == 'E')) {
    f->cur++;
    EXPECT(f->cur < f->end, JSON_STRING_INCOMPLETE);
    if ((f->cur[0] == '+' || f->cur[0] == '-')) f->cur++;
    EXPECT(f->cur < f->end, JSON_STRING_INCOMPLETE);
    EXPECT(is_digit(f->cur[0]), JSON_STRING_INVALID);
    while (f->cur < f->end && is_digit(f->cur[0])) f->cur++;
  }
  truncate_path(f, fstate.path_len);
  CALL_BACK(f, JSON_TYPE_NUMBER, fstate.ptr, f->cur - fstate.ptr);
  return 0;
}

/* array = '[' [ value { ',' value } ] ']' */
static int parse_array(struct frozen *f) {
  int i = 0, current_path_len;
  char buf[20];
  TRY(test_and_skip(f, '['));
  {
    CALL_BACK(f, JSON_TYPE_ARRAY_START, NULL, 0);
    {
      SET_STATE(f, f->cur - 1, "", 0);
      while (cur(f) != ']') {
        snprintf(buf, sizeof(buf), "[%d]", i);
        i++;
        current_path_len = append_to_path(f, buf, strlen(buf));
        f->cur_name =
            f->path + strlen(f->path) - strlen(buf) + 1 /*opening brace*/;
        f->cur_name_len = strlen(buf) - 2 /*braces*/;
        TRY(parse_value(f));
        truncate_path(f, current_path_len);
        if (cur(f) == ',') f->cur++;
      }
      TRY(test_and_skip(f, ']'));
      truncate_path(f, fstate.path_len);
      CALL_BACK(f, JSON_TYPE_ARRAY_END, fstate.ptr, f->cur - fstate.ptr);
    }
  }
  return 0;
}

static int expect(struct frozen *f, const char *s, int len,
                  enum json_token_type tok_type) {
  int i, n = left(f);
  SET_STATE(f, f->cur, "", 0);
  for (i = 0; i < len; i++) {
    if (i >= n) return JSON_STRING_INCOMPLETE;
    if (f->cur[i] != s[i]) return JSON_STRING_INVALID;
  }
  f->cur += len;
  truncate_path(f, fstate.path_len);

  CALL_BACK(f, tok_type, fstate.ptr, f->cur - fstate.ptr);

  return 0;
}

/* value = 'null' | 'true' | 'false' | number | string | array | object */
static int parse_value(struct frozen *f) {
  int ch = cur(f);

  switch (ch) {
    case '"':
      TRY(parse_string(f));
      break;
    case '{':
      TRY(parse_object(f));
      break;
    case '[':
      TRY(parse_array(f));
      break;
    case 'n':
      TRY(expect(f, "null", 4, JSON_TYPE_NULL));
      break;
    case 't':
      TRY(expect(f, "true", 4, JSON_TYPE_TRUE));
      break;
    case 'f':
      TRY(expect(f, "false", 5, JSON_TYPE_FALSE));
      break;
    case '-':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      TRY(parse_number(f));
      break;
    default:
      return ch == END_OF_STRING ? JSON_STRING_INCOMPLETE : JSON_STRING_INVALID;
  }

  return 0;
}

/* key = identifier | string */
static int parse_key(struct frozen *f) {
  int ch = cur(f);
#if 0
  printf("%s [%.*s]\n", __func__, (int) (f->end - f->cur), f->cur);
#endif
  if (is_alpha(ch)) {
    TRY(parse_identifier(f));
  } else if (ch == '"') {
    TRY(parse_string(f));
  } else {
    return ch == END_OF_STRING ? JSON_STRING_INCOMPLETE : JSON_STRING_INVALID;
  }
  return 0;
}

/* pair = key ':' value */
static int parse_pair(struct frozen *f) {
  int current_path_len;
  const char *tok;
  skip_whitespaces(f);
  tok = f->cur;
  TRY(parse_key(f));
  {
    f->cur_name = *tok == '"' ? tok + 1 : tok;
    f->cur_name_len = *tok == '"' ? f->cur - tok - 2 : f->cur - tok;
    current_path_len = append_to_path(f, f->cur_name, f->cur_name_len);
  }
  TRY(test_and_skip(f, ':'));
  TRY(parse_value(f));
  truncate_path(f, current_path_len);
  return 0;
}

/* object = '{' pair { ',' pair } '}' */
static int parse_object(struct frozen *f) {
  TRY(test_and_skip(f, '{'));
  {
    CALL_BACK(f, JSON_TYPE_OBJECT_START, NULL, 0);
    {
      SET_STATE(f, f->cur - 1, ".", 1);
      while (cur(f) != '}') {
        TRY(parse_pair(f));
        if (cur(f) == ',') f->cur++;
      }
      TRY(test_and_skip(f, '}'));
      truncate_path(f, fstate.path_len);
      CALL_BACK(f, JSON_TYPE_OBJECT_END, fstate.ptr, f->cur - fstate.ptr);
    }
  }
  return 0;
}

static int doit(struct frozen *f) {
  if (f->cur == 0 || f->end < f->cur) return JSON_STRING_INVALID;
  if (f->end == f->cur) return JSON_STRING_INCOMPLETE;
  return parse_value(f);
}

int json_escape(struct json_out *out, const char *p, size_t len) WEAK;
int json_escape(struct json_out *out, const char *p, size_t len) {
  size_t i, cl, n = 0;
  const char *hex_digits = "0123456789abcdef";
  const char *specials = "btnvfr";

  for (i = 0; i < len; i++) {
    unsigned char ch = ((unsigned char *) p)[i];
    if (ch == '"' || ch == '\\') {
      n += out->printer(out, "\\", 1);
      n += out->printer(out, p + i, 1);
    } else if (ch >= '\b' && ch <= '\r') {
      n += out->printer(out, "\\", 1);
      n += out->printer(out, &specials[ch - '\b'], 1);
    } else if (isprint(ch)) {
      n += out->printer(out, p + i, 1);
    } else if ((cl = get_utf8_char_len(ch)) == 1) {
      n += out->printer(out, "\\u00", 4);
      n += out->printer(out, &hex_digits[(ch >> 4) % 0xf], 1);
      n += out->printer(out, &hex_digits[ch % 0xf], 1);
    } else {
      n += out->printer(out, p + i, cl);
      i += cl - 1;
    }
  }

  return n;
}

int json_printer_buf(struct json_out *out, const char *buf, size_t len) WEAK;
int json_printer_buf(struct json_out *out, const char *buf, size_t len) {
  size_t avail = out->u.buf.size - out->u.buf.len;
  size_t n = len < avail ? len : avail;
  memcpy(out->u.buf.buf + out->u.buf.len, buf, n);
  out->u.buf.len += n;
  if (out->u.buf.size > 0) {
    size_t idx = out->u.buf.len;
    if (idx >= out->u.buf.size) idx = out->u.buf.size - 1;
    out->u.buf.buf[idx] = '\0';
  }
  return len;
}

int json_printer_file(struct json_out *out, const char *buf, size_t len) WEAK;
int json_printer_file(struct json_out *out, const char *buf, size_t len) {
  return fwrite(buf, 1, len, out->u.fp);
}

static int b64idx(int c) {
  if (c < 26) {
    return c + 'A';
  } else if (c < 52) {
    return c - 26 + 'a';
  } else if (c < 62) {
    return c - 52 + '0';
  } else {
    return c == 62 ? '+' : '/';
  }
}

static int b64rev(int c) {
  if (c >= 'A' && c <= 'Z') {
    return c - 'A';
  } else if (c >= 'a' && c <= 'z') {
    return c + 26 - 'a';
  } else if (c >= '0' && c <= '9') {
    return c + 52 - '0';
  } else if (c == '+') {
    return 62;
  } else if (c == '/') {
    return 63;
  } else {
    return 64;
  }
}

static uint8_t hexdec(const char *s) {
#define HEXTOI(x) (x >= '0' && x <= '9' ? x - '0' : x - 'W')
  int a = tolower(*(const unsigned char *) s);
  int b = tolower(*(const unsigned char *) (s + 1));
  return (HEXTOI(a) << 4) | HEXTOI(b);
}

static int b64enc(struct json_out *out, const unsigned char *p, int n) {
  char buf[4];
  int i, len = 0;
  for (i = 0; i < n; i += 3) {
    int a = p[i], b = i + 1 < n ? p[i + 1] : 0, c = i + 2 < n ? p[i + 2] : 0;
    buf[0] = b64idx(a >> 2);
    buf[1] = b64idx((a & 3) << 4 | (b >> 4));
    buf[2] = b64idx((b & 15) << 2 | (c >> 6));
    buf[3] = b64idx(c & 63);
    if (i + 1 >= n) buf[2] = '=';
    if (i + 2 >= n) buf[3] = '=';
    len += out->printer(out, buf, sizeof(buf));
  }
  return len;
}

static int b64dec(const char *src, int n, char *dst) {
  const char *end = src + n;
  int len = 0;
  while (src + 3 < end) {
    int a = b64rev(src[0]), b = b64rev(src[1]), c = b64rev(src[2]),
        d = b64rev(src[3]);
    dst[len++] = (a << 2) | (b >> 4);
    if (src[2] != '=') {
      dst[len++] = (b << 4) | (c >> 2);
      if (src[3] != '=') {
        dst[len++] = (c << 6) | d;
      }
    }
    src += 4;
  }
  return len;
}

int json_vprintf(struct json_out *out, const char *fmt, va_list xap) WEAK;
int json_vprintf(struct json_out *out, const char *fmt, va_list xap) {
  int len = 0;
  const char *quote = "\"", *null = "null";
  va_list ap;
  va_copy(ap, xap);

  while (*fmt != '\0') {
    if (strchr(":, \r\n\t[]{}\"", *fmt) != NULL) {
      len += out->printer(out, fmt, 1);
      fmt++;
    } else if (fmt[0] == '%') {
      char buf[21];
      size_t skip = 2;

      if (fmt[1] == 'l' && fmt[2] == 'l' && (fmt[3] == 'd' || fmt[3] == 'u')) {
        int64_t val = va_arg(ap, int64_t);
        const char *fmt2 = fmt[3] == 'u' ? "%" UINT64_FMT : "%" INT64_FMT;
        snprintf(buf, sizeof(buf), fmt2, val);
        len += out->printer(out, buf, strlen(buf));
        skip += 2;
      } else if (fmt[1] == 'z' && fmt[2] == 'u') {
        size_t val = va_arg(ap, size_t);
        snprintf(buf, sizeof(buf), "%" SIZE_T_FMT, val);
        len += out->printer(out, buf, strlen(buf));
        skip += 1;
      } else if (fmt[1] == 'M') {
        json_printf_callback_t f = va_arg(ap, json_printf_callback_t);
        len += f(out, &ap);
      } else if (fmt[1] == 'B') {
        int val = va_arg(ap, int);
        const char *str = val ? "true" : "false";
        len += out->printer(out, str, strlen(str));
      } else if (fmt[1] == 'H') {
        const char *hex = "0123456789abcdef";
        int i, n = va_arg(ap, int);
        const unsigned char *p = va_arg(ap, const unsigned char *);
        len += out->printer(out, quote, 1);
        for (i = 0; i < n; i++) {
          len += out->printer(out, &hex[(p[i] >> 4) & 0xf], 1);
          len += out->printer(out, &hex[p[i] & 0xf], 1);
        }
        len += out->printer(out, quote, 1);
      } else if (fmt[1] == 'V') {
        const unsigned char *p = va_arg(ap, const unsigned char *);
        int n = va_arg(ap, int);
        len += out->printer(out, quote, 1);
        len += b64enc(out, p, n);
        len += out->printer(out, quote, 1);
      } else if (fmt[1] == 'Q' ||
                 (fmt[1] == '.' && fmt[2] == '*' && fmt[3] == 'Q')) {
        size_t l = 0;
        const char *p;

        if (fmt[1] == '.') {
          l = (size_t) va_arg(ap, int);
          skip += 2;
        }
        p = va_arg(ap, char *);

        if (p == NULL) {
          len += out->printer(out, null, 4);
        } else {
          if (fmt[1] == 'Q') {
            l = strlen(p);
          }
          len += out->printer(out, quote, 1);
          len += json_escape(out, p, l);
          len += out->printer(out, quote, 1);
        }
      } else {
        /*
         * we delegate printing to the system printf.
         * The goal here is to delegate all modifiers parsing to the system
         * printf, as you can see below we still have to parse the format
         * types.
         *
         * Currently, %s with strings longer than 20 chars will require
         * double-buffering (an auxiliary buffer will be allocated from heap).
         * TODO(dfrank): reimplement %s and %.*s in order to avoid that.
         */

        const char *end_of_format_specifier = "sdfFgGlhuI.*-0123456789";
        size_t n = strspn(fmt + 1, end_of_format_specifier);
        char *pbuf = buf;
        size_t need_len;
        char fmt2[20];
        va_list sub_ap;
        strncpy(fmt2, fmt, n + 1 > sizeof(fmt2) ? sizeof(fmt2) : n + 1);
        fmt2[n + 1] = '\0';

        va_copy(sub_ap, ap);
        need_len =
            vsnprintf(buf, sizeof(buf), fmt2, sub_ap) + 1 /* null-term */;
        /*
         * TODO(lsm): Fix windows & eCos code path here. Their vsnprintf
         * implementation returns -1 on overflow rather needed size.
         */
        if (need_len > sizeof(buf)) {
          /*
           * resulting string doesn't fit into a stack-allocated buffer `buf`,
           * so we need to allocate a new buffer from heap and use it
           */
          pbuf = (char *) malloc(need_len);
          va_copy(sub_ap, ap);
          vsnprintf(pbuf, need_len, fmt2, sub_ap);
        }

        /*
         * however we need to parse the type ourselves in order to advance
         * the va_list by the correct amount; there is no portable way to
         * inherit the advancement made by vprintf.
         * 32-bit (linux or windows) passes va_list by value.
         */
        if ((n + 1 == strlen("%" PRId64) && strcmp(fmt2, "%" PRId64) == 0) ||
            (n + 1 == strlen("%" PRIu64) && strcmp(fmt2, "%" PRIu64) == 0)) {
          (void) va_arg(ap, int64_t);
          skip += strlen(PRIu64) - 1;
        } else if (strcmp(fmt2, "%.*s") == 0) {
          (void) va_arg(ap, int);
          (void) va_arg(ap, char *);
        } else {
          switch (fmt2[n]) {
            case 'u':
            case 'd':
              (void) va_arg(ap, int);
              break;
            case 'g':
            case 'f':
              (void) va_arg(ap, double);
              break;
            case 'p':
              (void) va_arg(ap, void *);
              break;
            default:
              /* many types are promoted to int */
              (void) va_arg(ap, int);
          }
        }

        len += out->printer(out, pbuf, strlen(pbuf));
        skip = n + 1;

        /* If buffer was allocated from heap, free it */
        if (pbuf != buf) {
          free(pbuf);
          pbuf = NULL;
        }
      }
      fmt += skip;
    } else if (*fmt == '_' || is_alpha(*fmt)) {
      len += out->printer(out, quote, 1);
      while (*fmt == '_' || is_alpha(*fmt) || is_digit(*fmt)) {
        len += out->printer(out, fmt, 1);
        fmt++;
      }
      len += out->printer(out, quote, 1);
    } else {
      fmt++;
    }
  }
  va_end(ap);

  return len;
}

int json_printf(struct json_out *out, const char *fmt, ...) WEAK;
int json_printf(struct json_out *out, const char *fmt, ...) {
  int n;
  va_list ap;
  va_start(ap, fmt);
  n = json_vprintf(out, fmt, ap);
  va_end(ap);
  return n;
}

int json_printf_array(struct json_out *out, va_list *ap) WEAK;
int json_printf_array(struct json_out *out, va_list *ap) {
  int len = 0;
  char *arr = va_arg(*ap, char *);
  size_t i, arr_size = va_arg(*ap, size_t);
  size_t elem_size = va_arg(*ap, size_t);
  const char *fmt = va_arg(*ap, char *);
  len += json_printf(out, "[", 1);
  for (i = 0; arr != NULL && i < arr_size / elem_size; i++) {
    union {
      int64_t i;
      double d;
    } val;
    memcpy(&val, arr + i * elem_size,
           elem_size > sizeof(val) ? sizeof(val) : elem_size);
    if (i > 0) len += json_printf(out, ", ");
    if (strchr(fmt, 'f') != NULL) {
      len += json_printf(out, fmt, val.d);
    } else {
      len += json_printf(out, fmt, val.i);
    }
  }
  len += json_printf(out, "]", 1);
  return len;
}

#ifdef _WIN32
int cs_win_vsnprintf(char *str, size_t size, const char *format, va_list ap) WEAK;
int cs_win_vsnprintf(char *str, size_t size, const char *format, va_list ap) {
  int res = _vsnprintf(str, size, format, ap);
  va_end(ap);
  if (res >= size) {
    str[size - 1] = '\0';
  }
  return res;
}

int cs_win_snprintf(char *str, size_t size, const char *format, ...) WEAK;
int cs_win_snprintf(char *str, size_t size, const char *format, ...) {
  int res;
  va_list ap;
  va_start(ap, format);
  res = vsnprintf(str, size, format, ap);
  va_end(ap);
  return res;
}
#endif /* _WIN32 */

int json_walk(const char *json_string, int json_string_length,
              json_walk_callback_t callback, void *callback_data) WEAK;
int json_walk(const char *json_string, int json_string_length,
              json_walk_callback_t callback, void *callback_data) {
  struct frozen frozen;

  memset(&frozen, 0, sizeof(frozen));
  frozen.end = json_string + json_string_length;
  frozen.cur = json_string;
  frozen.callback_data = callback_data;
  frozen.callback = callback;

  TRY(doit(&frozen));

  return frozen.cur - json_string;
}

struct scan_array_info {
  char path[JSON_MAX_PATH_LEN];
  struct json_token *token;
};

static void json_scanf_array_elem_cb(void *callback_data, const char *name,
                                     size_t name_len, const char *path,
                                     const struct json_token *token) {
  struct scan_array_info *info = (struct scan_array_info *) callback_data;

  (void) name;
  (void) name_len;

  if (strcmp(path, info->path) == 0) {
    *info->token = *token;
  }
}

int json_scanf_array_elem(const char *s, int len, const char *path, int idx,
                          struct json_token *token) WEAK;
int json_scanf_array_elem(const char *s, int len, const char *path, int idx,
                          struct json_token *token) {
  struct scan_array_info info;
  info.token = token;
  memset(token, 0, sizeof(*token));
  snprintf(info.path, sizeof(info.path), "%s[%d]", path, idx);
  json_walk(s, len, json_scanf_array_elem_cb, &info);
  return token->len;
}

struct json_scanf_info {
  int num_conversions;
  char *path;
  const char *fmt;
  void *target;
  void *user_data;
  int type;
};

int json_unescape(const char *src, int slen, char *dst, int dlen) WEAK;
int json_unescape(const char *src, int slen, char *dst, int dlen) {
  char *send = (char *) src + slen, *dend = dst + dlen, *orig_dst = dst, *p;
  const char *esc1 = "\"\\/bfnrt", *esc2 = "\"\\/\b\f\n\r\t";

  while (src < send) {
    if (*src == '\\') {
      if (++src >= send) return JSON_STRING_INCOMPLETE;
      if (*src == 'u') {
        /* TODO(lsm): \uXXXX escapes drag utf8 lib... Do it at some stage */
        return JSON_STRING_INVALID;
      } else if ((p = (char *) strchr(esc1, *src)) != NULL) {
        if (dst < dend) *dst = esc2[p - esc1];
      } else {
        return JSON_STRING_INVALID;
      }
    } else {
      if (dst < dend) *dst = *src;
    }
    dst++;
    src++;
  }

  return dst - orig_dst;
}

static void json_scanf_cb(void *callback_data, const char *name,
                          size_t name_len, const char *path,
                          const struct json_token *token) {
  struct json_scanf_info *info = (struct json_scanf_info *) callback_data;

  (void) name;
  (void) name_len;

  if (strcmp(path, info->path) != 0) {
    /* It's not the path we're looking for, so, just ignore this callback */
    return;
  }

  if (token->ptr == NULL) {
    /*
     * We're not interested here in the events for which we have no value;
     * namely, JSON_TYPE_OBJECT_START and JSON_TYPE_ARRAY_START
     */
    return;
  }

  switch (info->type) {
    case 'B':
      info->num_conversions++;
      *(int *) info->target = (token->type == JSON_TYPE_TRUE ? 1 : 0);
      break;
    case 'M': {
      union {
        void *p;
        json_scanner_t f;
      } u = {info->target};
      info->num_conversions++;
      u.f(token->ptr, token->len, info->user_data);
      break;
    }
    case 'Q': {
      char **dst = (char **) info->target;
      if (token->type == JSON_TYPE_NULL) {
        *dst = NULL;
      } else {
        int unescaped_len = json_unescape(token->ptr, token->len, NULL, 0);
        if (unescaped_len >= 0 &&
            (*dst = (char *) malloc(unescaped_len + 1)) != NULL) {
          info->num_conversions++;
          json_unescape(token->ptr, token->len, *dst, unescaped_len);
          (*dst)[unescaped_len] = '\0';
        }
      }
      break;
    }
    case 'H': {
      char **dst = (char **) info->user_data;
      int i, len = token->len / 2;
      *(int *) info->target = len;
      if ((*dst = (char *) malloc(len + 1)) != NULL) {
        for (i = 0; i < len; i++) {
          (*dst)[i] = hexdec(token->ptr + 2 * i);
        }
        (*dst)[len] = '\0';
        info->num_conversions++;
      }
      break;
    }
    case 'V': {
      char **dst = (char **) info->target;
      int len = token->len * 4 / 3 + 2;
      if ((*dst = (char *) malloc(len + 1)) != NULL) {
        int n = b64dec(token->ptr, token->len, *dst);
        (*dst)[n] = '\0';
        *(int *) info->user_data = n;
        info->num_conversions++;
      }
      break;
    }
    case 'T':
      info->num_conversions++;
      *(struct json_token *) info->target = *token;
      break;
    default:
      info->num_conversions += sscanf(token->ptr, info->fmt, info->target);
      break;
  }
}

int json_vscanf(const char *s, int len, const char *fmt, va_list ap) WEAK;
int json_vscanf(const char *s, int len, const char *fmt, va_list ap) {
  char path[JSON_MAX_PATH_LEN] = "", fmtbuf[20];
  int i = 0;
  char *p = NULL;
  struct json_scanf_info info = {0, path, fmtbuf, NULL, NULL, 0};

  while (fmt[i] != '\0') {
    if (fmt[i] == '{') {
      strcat(path, ".");
      i++;
    } else if (fmt[i] == '}') {
      if ((p = strrchr(path, '.')) != NULL) *p = '\0';
      i++;
    } else if (fmt[i] == '%') {
      info.target = va_arg(ap, void *);
      info.type = fmt[i + 1];
      switch (fmt[i + 1]) {
        case 'M':
        case 'V':
        case 'H':
          info.user_data = va_arg(ap, void *);
        /* FALLTHROUGH */
        case 'B':
        case 'Q':
        case 'T':
          i += 2;
          break;
        default: {
          const char *delims = ", \t\r\n]}";
          int conv_len = strcspn(fmt + i + 1, delims) + 1;
          snprintf(fmtbuf, sizeof(fmtbuf), "%.*s", conv_len, fmt + i);
          i += conv_len;
          i += strspn(fmt + i, delims);
          break;
        }
      }
      json_walk(s, len, json_scanf_cb, &info);
    } else if (is_alpha(fmt[i]) || get_utf8_char_len(fmt[i]) > 1) {
      const char *delims = ": \r\n\t";
      int key_len = strcspn(&fmt[i], delims);
      if ((p = strrchr(path, '.')) != NULL) p[1] = '\0';
      sprintf(path + strlen(path), "%.*s", key_len, &fmt[i]);
      i += key_len + strspn(fmt + i + key_len, delims);
    } else {
      i++;
    }
  }
  return info.num_conversions;
}

int json_scanf(const char *str, int len, const char *fmt, ...) WEAK;
int json_scanf(const char *str, int len, const char *fmt, ...) {
  int result;
  va_list ap;
  va_start(ap, fmt);
  result = json_vscanf(str, len, fmt, ap);
  va_end(ap);
  return result;
}
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/ffi/ffi.c"
#endif
/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

/* Amalgamated: #include "mjs/src/ffi/ffi.h" */

typedef uintptr_t word_t;

void ffi_set_int32(struct ffi_arg *arg, uint32_t v) {
  arg->size = 4;
  arg->is_float = 0;
  arg->v.i = v;
}

void ffi_set_int64(struct ffi_arg *arg, uint64_t v) {
  arg->size = 8;
  arg->is_float = 0;
  arg->v.i = v;
}

void ffi_set_ptr(struct ffi_arg *arg, void *v) {
  if (sizeof(v) == 8) {
    ffi_set_int64(arg, (uint64_t)(uintptr_t) v);
  } else {
    ffi_set_int32(arg, (uint32_t)(uintptr_t) v);
  }
}

void ffi_set_double(struct ffi_arg *arg, double v) {
  arg->size = 8;
  arg->is_float = 1;
  arg->v.d = v;
}

/*
 * The ARM ABI uses only 4 32-bit registers for paramter passing.
 * Xtensa call0 calling-convention (as used by Espressif) has 6.
 *
 * Focusing only on implementing FFI with registers means we can simplify a lot.
 *
 * ARM has some quasi-alignment rules when mixing double and integers as
 * arguments. Only:
 *   a) double, int32_t, int32_t
 *   b) int32_t, double
 * would fit in 4 registers. (the same goes for uint64_t).
 *
 * In order to simplify further, when a double-width argument is present, we
 * allow only two arguments.
 */

/*
 * We need to support x86_64 in order to support local tests.
 * x86_64 has more and wider registers, but unlike the two main
 * embedded platforms we target it has a separate register file for
 * integer values and for floating point values (both for passing args and
 * return values). E.g. if a double value is passed as a second argument
 * it gets passed in the first available floating point register.
 *
 * I.e, the compiler generates exactly the same code for:
 *
 * void foo(int a, double b) {...}
 *
 * and
 *
 * void foo(double b, int a) {...}
 *
 *
 */

typedef word_t (*w4w_t)(word_t, word_t, word_t, word_t);
typedef word_t (*w5w_t)(word_t, word_t, word_t, word_t, word_t);
typedef word_t (*w6w_t)(word_t, word_t, word_t, word_t, word_t, word_t);
typedef word_t (*wdw_t)(double, word_t);
typedef word_t (*wdd_t)(double, double);

typedef double (*d4w_t)(word_t, word_t, word_t, word_t);
typedef double (*d5w_t)(word_t, word_t, word_t, word_t, word_t);
typedef double (*d6w_t)(word_t, word_t, word_t, word_t, word_t, word_t);
typedef double (*ddw_t)(double, word_t);
typedef double (*ddd_t)(double, double);

int ffi_call(ffi_fn_t func, int nargs, struct ffi_arg *res,
             struct ffi_arg *args) {
  int i, doubles = 0;

  if (nargs > 6) return -1;
  for (i = 0; i < nargs; i++) {
    doubles += !!args[i].is_float;
  }
  if (doubles > 0 && nargs > 2) return -1;

  if (!res->is_float) {
    word_t r;
    switch (doubles) {
      case 0: {
        /* No double args: we currently support up to 6 word-sized arguments */
        if (nargs <= 4) {
          w4w_t f = (w4w_t) func;
          r = f((word_t) args[0].v.i, (word_t) args[1].v.i,
                (word_t) args[2].v.i, (word_t) args[3].v.i);
        } else if (nargs == 5) {
          w5w_t f = (w5w_t) func;
          r = f((word_t) args[0].v.i, (word_t) args[1].v.i,
                (word_t) args[2].v.i, (word_t) args[3].v.i,
                (word_t) args[4].v.i);
        } else if (nargs == 6) {
          w6w_t f = (w6w_t) func;
          r = f((word_t) args[0].v.i, (word_t) args[1].v.i,
                (word_t) args[2].v.i, (word_t) args[3].v.i,
                (word_t) args[4].v.i, (word_t) args[5].v.i);
        } else {
          abort();
        }
        break;
      }
      case 1: {
        wdw_t f = (wdw_t) func;
        if (args[0].is_float) {
          r = f(args[0].v.d, (word_t) args[1].v.i);
        } else {
          r = f(args[1].v.d, (word_t) args[0].v.i);
        }
        break;
      }
      case 2: {
        wdd_t f = (wdd_t) func;
        r = f(args[0].v.d, args[1].v.d);
      } break;
      default:
        return -1;
    }
    res->v.i = (uint64_t) r;
  } else {
    double r;
    switch (doubles) {
      case 0: {
        /* No double args: we currently support up to 6 word-sized arguments */
        if (nargs <= 4) {
          d4w_t f = (d4w_t) func;
          r = f((word_t) args[0].v.i, (word_t) args[1].v.i,
                (word_t) args[2].v.i, (word_t) args[3].v.i);
        } else if (nargs == 5) {
          d5w_t f = (d5w_t) func;
          r = f((word_t) args[0].v.i, (word_t) args[1].v.i,
                (word_t) args[2].v.i, (word_t) args[3].v.i,
                (word_t) args[4].v.i);
        } else if (nargs == 6) {
          d6w_t f = (d6w_t) func;
          r = f((word_t) args[0].v.i, (word_t) args[1].v.i,
                (word_t) args[2].v.i, (word_t) args[3].v.i,
                (word_t) args[4].v.i, (word_t) args[5].v.i);
        } else {
          abort();
        }
        break;
      }
      case 1: {
        ddw_t f = (ddw_t) func;
        if (args[0].is_float) {
          r = f(args[0].v.d, (word_t) args[1].v.i);
        } else {
          r = f(args[1].v.d, (word_t) args[0].v.i);
        }
        break;
      }
      case 2: {
        ddd_t f = (ddd_t) func;
        r = f(args[0].v.d, args[1].v.d);
      } break;
      default:
        return -1;
    }
    res->v.d = r;
  }

  return 0;
}
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_array.c"
#endif
/*
 * Copyright (c) 2017 Cesanta Software Limited
 * All rights reserved
 */

#include <stdio.h>
/* Amalgamated: #include "common/str_util.h" */
/* Amalgamated: #include "mjs/src/mjs_array.h" */
/* Amalgamated: #include "mjs/src/mjs_conversion.h" */
/* Amalgamated: #include "mjs/src/mjs_core.h" */
/* Amalgamated: #include "mjs/src/mjs_internal.h" */
/* Amalgamated: #include "mjs/src/mjs_object.h" */
/* Amalgamated: #include "mjs/src/mjs_primitive.h" */
/* Amalgamated: #include "mjs/src/mjs_string.h" */

/* like c_snprintf but returns `size` if write is truncated */
static int v_sprintf_s(char *buf, size_t size, const char *fmt, ...) {
  size_t n;
  va_list ap;
  va_start(ap, fmt);
  n = c_vsnprintf(buf, size, fmt, ap);
  if (n > size) {
    return size;
  }
  return n;
}

mjs_val_t mjs_mk_array(struct mjs *mjs) {
  mjs_val_t ret = mjs_mk_object(mjs);
  /* change the tag to MJS_TAG_ARRAY */
  ret &= ~MJS_TAG_MASK;
  ret |= MJS_TAG_ARRAY;
  return ret;
}

int mjs_is_array(mjs_val_t v) {
  return (v & MJS_TAG_MASK) == MJS_TAG_ARRAY;
}

mjs_val_t mjs_array_get(struct mjs *mjs, mjs_val_t arr, unsigned long index) {
  return mjs_array_get2(mjs, arr, index, NULL);
}

mjs_val_t mjs_array_get2(struct mjs *mjs, mjs_val_t arr, unsigned long index,
                         int *has) {
  mjs_val_t res = MJS_UNDEFINED;

  if (has != NULL) {
    *has = 0;
  }

  if (mjs_is_object(arr)) {
    struct mjs_property *p;
    char buf[20];
    int n = v_sprintf_s(buf, sizeof(buf), "%lu", index);
    p = mjs_get_own_property(mjs, arr, buf, n);
    if (p != NULL) {
      if (has != NULL) {
        *has = 1;
      }
      res = p->value;
    }
  }

  return res;
}

unsigned long mjs_array_length(struct mjs *mjs, mjs_val_t v) {
  struct mjs_property *p;
  unsigned long len = 0;

  if (!mjs_is_object(v)) {
    len = 0;
    goto clean;
  }

  for (p = get_object_struct(v)->properties; p != NULL; p = p->next) {
    int ok = 0;
    unsigned long n = 0;
    str_to_ulong(mjs, p->name, &ok, &n);
    if (ok && n >= len && n < 0xffffffff) {
      len = n + 1;
    }
  }

clean:
  return len;
}

mjs_err_t mjs_array_set(struct mjs *mjs, mjs_val_t arr, unsigned long index,
                        mjs_val_t v) {
  mjs_err_t ret = MJS_OK;

  if (mjs_is_object(arr)) {
    char buf[20];
    int n = v_sprintf_s(buf, sizeof(buf), "%lu", index);
    ret = mjs_set(mjs, arr, buf, n, v);
  } else {
    ret = MJS_TYPE_ERROR;
  }

  return ret;
}

#if 0
void mjs_array_del(struct mjs *mjs, mjs_val_t arr, unsigned long index) {
  char buf[20];
  int n = v_sprintf_s(buf, sizeof(buf), "%lu", index);
  mjs_del(mjs, arr, buf, n);
}
#endif

mjs_err_t mjs_array_push(struct mjs *mjs, mjs_val_t arr, mjs_val_t v) {
  return mjs_array_set(mjs, arr, mjs_array_length(mjs, arr), v);
}
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_bcode.c"
#endif
/*
 * Copyright (c) 2017 Cesanta Software Limited
 * All rights reserved
 */

/* Amalgamated: #include "mjs/src/mjs_internal.h" */
/* Amalgamated: #include "mjs/src/mjs_core.h" */
/* Amalgamated: #include "mjs/src/mjs_tok.h" */
/* Amalgamated: #include "mjs/src/mjs_varint.h" */

static void add_lineno_map_item(struct pstate *pstate) {
  if (pstate->last_emitted_line_no < pstate->line_no) {
    int offset = pstate->mjs->bcode.len - pstate->start_bcode_idx;
    size_t offset_llen = varint_llen(offset);
    size_t lineno_llen = varint_llen(pstate->line_no);
    mbuf_resize(&pstate->offset_lineno_map,
                pstate->offset_lineno_map.size + offset_llen + lineno_llen);

    /* put offset */
    varint_encode(offset, (uint8_t *) pstate->offset_lineno_map.buf +
                              pstate->offset_lineno_map.len);
    pstate->offset_lineno_map.len += offset_llen;

    /* put line_no */
    varint_encode(pstate->line_no, (uint8_t *) pstate->offset_lineno_map.buf +
                                       pstate->offset_lineno_map.len);
    pstate->offset_lineno_map.len += lineno_llen;

    pstate->last_emitted_line_no = pstate->line_no;
  }
}

MJS_PRIVATE void emit_byte(struct pstate *pstate, uint8_t byte) {
  add_lineno_map_item(pstate);
  mbuf_append(&pstate->mjs->bcode, &byte, sizeof(byte));
}

MJS_PRIVATE void emit_int(struct pstate *pstate, int64_t n) {
  add_lineno_map_item(pstate);
  struct mbuf *b = &pstate->mjs->bcode;
  size_t llen = varint_llen(n);
  mbuf_resize(b, b->size + llen);
  varint_encode(n, (uint8_t *) b->buf + b->len);
  b->len += llen;
}

MJS_PRIVATE void emit_str(struct pstate *pstate, const char *ptr, size_t len) {
  add_lineno_map_item(pstate);
  struct mbuf *b = &pstate->mjs->bcode;
  size_t llen = varint_llen(len);
  mbuf_resize(b, b->size + llen + len);
  varint_encode(len, (uint8_t *) b->buf + b->len);
  memcpy(b->buf + b->len + llen, ptr, len);
  b->len += llen + len;
}

MJS_PRIVATE size_t mjs_bcode_size(const struct mbuf *bcode) {
  return bcode->len;
}

MJS_PRIVATE void mjs_bcode_mutate_byte(struct mjs *mjs, size_t offset,
                                       size_t v) {
  if (v > 0xff) {
    mjs_set_errorf(mjs, MJS_INTERNAL_ERROR, "loop/cond body too long");
  } else if (offset >= mjs->bcode.len) {
    mjs_set_errorf(mjs, MJS_INTERNAL_ERROR, "oob offset");
  } else if (offset < mjs->bcode.len) {
    mjs->bcode.buf[offset] = v;
  }
}
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_builtin.c"
#endif
/*
 * Copyright (c) 2017 Cesanta Software Limited
 * All rights reserved
 */

/* Amalgamated: #include "mjs/src/mjs_core.h" */
/* Amalgamated: #include "mjs/src/mjs_dataview.h" */
/* Amalgamated: #include "mjs/src/mjs_exec.h" */
/* Amalgamated: #include "mjs/src/mjs_internal.h" */
/* Amalgamated: #include "mjs/src/mjs_json.h" */
/* Amalgamated: #include "mjs/src/mjs_object.h" */
/* Amalgamated: #include "mjs/src/mjs_primitive.h" */
/* Amalgamated: #include "mjs/src/mjs_string.h" */
/* Amalgamated: #include "mjs/src/mjs_util.h" */

static void mjs_print(struct mjs *mjs) {
  size_t i, num_args = mjs_nargs(mjs);
  for (i = 0; i < num_args; i++) {
    mjs_fprintf(mjs_arg(mjs, i), mjs, stdout);
    putchar(' ');
  }
  putchar('\n');
  mjs_return(mjs, MJS_UNDEFINED);
}

static void mjs_load(struct mjs *mjs) {
  mjs_val_t res = MJS_UNDEFINED;
  mjs_val_t arg0 = mjs_arg(mjs, 0);
  mjs_val_t arg1 = mjs_arg(mjs, 1);

  if (mjs_is_string(arg0)) {
    const char *path = mjs_get_cstring(mjs, &arg0);
    mjs_val_t *bottom = vptr(&mjs->scopes, 0), global = *bottom;
    mjs_own(mjs, &global);
    if (mjs_is_object(arg1)) *bottom = arg1;
    mjs_exec_file(mjs, path, &res);
    if (mjs_is_object(arg1)) *bottom = global;
    mjs_disown(mjs, &global);
  }
  mjs_return(mjs, res);
}

void mjs_init_builtin(struct mjs *mjs, mjs_val_t obj) {
  mjs_val_t v;

  mjs_set(mjs, obj, "global", ~0, obj);

  mjs_set(mjs, obj, "load", ~0, mjs_mk_foreign(mjs, mjs_load));
  mjs_set(mjs, obj, "print", ~0, mjs_mk_foreign(mjs, mjs_print));
  mjs_set(mjs, obj, "ffi", ~0, mjs_mk_foreign(mjs, mjs_ffi_call));
  mjs_set(mjs, obj, "ffi_cb_free", ~0, mjs_mk_foreign(mjs, mjs_ffi_cb_free));

  v = mjs_mk_object(mjs);
  mjs_set(mjs, v, "stringify", ~0, mjs_mk_foreign(mjs, mjs_op_json_stringify));
  mjs_set(mjs, v, "parse", ~0, mjs_mk_foreign(mjs, mjs_op_json_parse));
  mjs_set(mjs, obj, "JSON", ~0, v);
}
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_conversion.c"
#endif
/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

/* Amalgamated: #include "mjs/src/mjs_conversion.h" */
/* Amalgamated: #include "mjs/src/mjs_object.h" */
/* Amalgamated: #include "mjs/src/mjs_primitive.h" */
/* Amalgamated: #include "mjs/src/mjs_string.h" */

MJS_PRIVATE mjs_err_t mjs_to_string(struct mjs *mjs, mjs_val_t *v, char **p,
                                    size_t *sizep, int *need_free) {
  mjs_err_t ret = MJS_OK;

  *p = NULL;
  *sizep = 0;
  *need_free = 0;

  if (mjs_is_string(*v)) {
    *p = (char *) mjs_get_string(mjs, v, sizep);
  } else if (mjs_is_number(*v)) {
    double num = mjs_get_double(mjs, *v);
    const char *fmt = num > 1e10 ? "%.21g" : "%.10g";
    (void) num;
    (void) fmt;
    *sizep = snprintf(NULL, 0, fmt, num);
    *p = malloc(*sizep + 1 /*null term*/);
    if (*p == NULL) {
      ret = MJS_OUT_OF_MEMORY;
      goto clean;
    }
    snprintf(*p, *sizep + 1, fmt, num);
    *need_free = 1;
  } else if (mjs_is_boolean(*v)) {
    if (mjs_get_bool(mjs, *v)) {
      *p = "true";
      *sizep = 4;
    } else {
      *p = "false";
      *sizep = 5;
    }
  } else if (mjs_is_undefined(*v)) {
    *p = "undefined";
    *sizep = 9;
  } else if (mjs_is_null(*v)) {
    *p = "null";
    *sizep = 4;
  } else if (mjs_is_object(*v)) {
    ret = MJS_TYPE_ERROR;
    mjs_set_errorf(mjs, ret,
                   "conversion from object to string is not supported");
  } else if (mjs_is_foreign(*v)) {
    *p = "TODO_foreign";
    *sizep = 12;
  } else {
    ret = MJS_TYPE_ERROR;
    mjs_set_errorf(mjs, ret, "unknown type to convert to string");
  }

clean:
  return ret;
}

MJS_PRIVATE mjs_val_t mjs_to_boolean_v(struct mjs *mjs, mjs_val_t v) {
  size_t len;
  int is_truthy;

  is_truthy =
      ((mjs_is_boolean(v) && mjs_get_bool(mjs, v)) ||
       (mjs_is_number(v) && mjs_get_double(mjs, v) != 0.0) ||
       (mjs_is_string(v) && mjs_get_string(mjs, &v, &len) && len > 0) ||
       (mjs_is_function(v)) || (mjs_is_foreign(v)) || (mjs_is_object(v))) &&
      v != MJS_TAG_NAN;

  return mjs_mk_boolean(mjs, is_truthy);
}

MJS_PRIVATE int mjs_is_truthy(struct mjs *mjs, mjs_val_t v) {
  return mjs_get_bool(mjs, mjs_to_boolean_v(mjs, v));
}
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_core.c"
#endif
/*
 * Copyright (c) 2017 Cesanta Software Limited
 * All rights reserved
 */

/* Amalgamated: #include "mjs/src/mjs_core.h" */
/* Amalgamated: #include "common/str_util.h" */
/* Amalgamated: #include "mjs/src/mjs_bcode.h" */
/* Amalgamated: #include "mjs/src/mjs_builtin.h" */
/* Amalgamated: #include "mjs/src/mjs_internal.h" */
/* Amalgamated: #include "mjs/src/mjs_license.h" */
/* Amalgamated: #include "mjs/src/mjs_object.h" */
/* Amalgamated: #include "mjs/src/mjs_primitive.h" */
/* Amalgamated: #include "mjs/src/mjs_varint.h" */

#ifndef MJS_DEFAULT_OBJECT_ARENA_SIZE
#define MJS_DEFAULT_OBJECT_ARENA_SIZE 20
#endif
#ifndef MJS_DEFAULT_PROPERTY_ARENA_SIZE
#define MJS_DEFAULT_PROPERTY_ARENA_SIZE 20
#endif

void mjs_destroy(struct mjs *mjs) {
  mbuf_free(&mjs->bcode);
  mbuf_free(&mjs->stack);
  mbuf_free(&mjs->call_stack);
  mbuf_free(&mjs->owned_strings);
  mbuf_free(&mjs->foreign_strings);
  mbuf_free(&mjs->owned_values);
  mbuf_free(&mjs->scopes);
  mbuf_free(&mjs->loop_addresses);
  mbuf_free(&mjs->json_visited_stack);
  free(mjs->error_msg);
  mjs_ffi_args_free_list(mjs);
  gc_arena_destroy(mjs, &mjs->object_arena);
  gc_arena_destroy(mjs, &mjs->property_arena);
  free(mjs);
}

struct mjs *mjs_create(void) {
  struct mjs *mjs = calloc(1, sizeof(*mjs));
  mbuf_init(&mjs->stack, 0);
  mbuf_init(&mjs->call_stack, 0);
  mbuf_init(&mjs->owned_strings, 0);
  mbuf_init(&mjs->foreign_strings, 0);
  mbuf_init(&mjs->bcode, 0);
  mbuf_init(&mjs->owned_values, 0);
  mbuf_init(&mjs->scopes, 0);
  mbuf_init(&mjs->loop_addresses, 0);
  mbuf_init(&mjs->json_visited_stack, 0);

  /*
   * The compacting GC exploits the null terminator of the previous string as a
   * marker.
   */
  {
    char z = 0;
    mbuf_append(&mjs->owned_strings, &z, 1);
  }

  gc_arena_init(&mjs->object_arena, sizeof(struct mjs_object),
                MJS_DEFAULT_OBJECT_ARENA_SIZE, 10);
  gc_arena_init(&mjs->property_arena, sizeof(struct mjs_property),
                MJS_DEFAULT_PROPERTY_ARENA_SIZE, 10);

  mjs_val_t global_object = mjs_mk_object(mjs);
  mjs_init_builtin(mjs, global_object);
  mjs_set_ffi_resolver(mjs, dlsym);
  push_mjs_val(&mjs->scopes, global_object);
  mjs->vals.this_obj = MJS_UNDEFINED;
  mjs->vals.dataview_proto = MJS_UNDEFINED;

  return mjs;
}

mjs_err_t mjs_set_errorf(struct mjs *mjs, mjs_err_t err, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  free(mjs->error_msg);
  mjs->error_msg = NULL;
  mjs->error = err;
  if (fmt != NULL) {
    mg_avprintf(&mjs->error_msg, 0, fmt, ap);
  }
  va_end(ap);
  return err;
}

mjs_err_t mjs_prepend_errorf(struct mjs *mjs, mjs_err_t err, const char *fmt,
                             ...) {
  va_list ap;
  va_start(ap, fmt);
  char *old_error_msg = mjs->error_msg;
  char *new_error_msg = NULL;
  mjs->error_msg = NULL;
  /* set error if only it wasn't already set to some error */
  if (mjs->error == MJS_OK) {
    mjs->error = err;
  }
  mg_avprintf(&new_error_msg, 0, fmt, ap);
  va_end(ap);

  if (old_error_msg != NULL) {
    mg_asprintf(&mjs->error_msg, 0, "%s: %s", new_error_msg, old_error_msg);
    free(new_error_msg);
    free(old_error_msg);
  } else {
    mjs->error_msg = new_error_msg;
  }
  return err;
}

const char *mjs_strerror(struct mjs *mjs, enum mjs_err err) {
  const char *err_names[] = {
      "NO_ERROR",        "SYNTAX_ERROR",    "REFERENCE_ERROR",
      "TYPE_ERROR",      "OUT_OF_MEMORY",   "INTERNAL_ERROR",
      "NOT_IMPLEMENTED", "FILE_OPEN_ERROR", "BAD_ARGUMENTS"};
  return mjs->error_msg == NULL || mjs->error_msg[0] == '\0' ? err_names[err]
                                                             : mjs->error_msg;
}

MJS_PRIVATE size_t mjs_get_func_addr(mjs_val_t v) {
  return v & ~MJS_TAG_MASK;
}

MJS_PRIVATE enum mjs_type mjs_get_type(struct mjs *mjs, mjs_val_t v) {
  int tag;
  (void) mjs;
  if (mjs_is_number(v)) {
    return MJS_TYPE_NUMBER;
  }
  tag = (v & MJS_TAG_MASK) >> 48;
  switch (tag) {
    case MJS_TAG_FOREIGN >> 48:
      return MJS_TYPE_FOREIGN;
    case MJS_TAG_UNDEFINED >> 48:
      return MJS_TYPE_UNDEFINED;
    case MJS_TAG_OBJECT >> 48:
      return MJS_TYPE_OBJECT_GENERIC;
    case MJS_TAG_ARRAY >> 48:
      return MJS_TYPE_OBJECT_ARRAY;
    case MJS_TAG_STRING_I >> 48:
    case MJS_TAG_STRING_O >> 48:
    case MJS_TAG_STRING_F >> 48:
    case MJS_TAG_STRING_D >> 48:
    case MJS_TAG_STRING_5 >> 48:
      return MJS_TYPE_STRING;
    case MJS_TAG_BOOLEAN >> 48:
      return MJS_TYPE_BOOLEAN;
    case MJS_TAG_NULL >> 48:
      return MJS_TYPE_NULL;
    default:
      abort();
      return MJS_TYPE_UNDEFINED;
  }
}

mjs_val_t mjs_get_global(struct mjs *mjs) {
  return *vptr(&mjs->scopes, 0);
}

MJS_PRIVATE int mjs_get_bcode_header_offset(struct mjs *mjs, size_t offset) {
  int32_t total_size, ret = -1, cur_idx = 0;

  while ((size_t) cur_idx < mjs->bcode.len) {
    assert(mjs->bcode.buf[cur_idx] == OP_BCODE_HEADER);
    cur_idx++;
    memcpy(&total_size, mjs->bcode.buf + cur_idx, sizeof(total_size));
    if (offset < (size_t) cur_idx + total_size) {
      ret = cur_idx;
      break;
    }
    cur_idx += total_size;
  }

  return ret;
}

MJS_PRIVATE const char *mjs_get_bcode_filename_by_offset(struct mjs *mjs,
                                                         int offset) {
  const char *ret = NULL;
  int header_idx = mjs_get_bcode_header_offset(mjs, offset);
  if (header_idx >= 0) {
    ret = mjs->bcode.buf + header_idx +
          sizeof(mjs_header_item_t) * MJS_HDR_ITEMS_CNT;
  }
  return ret;
}

MJS_PRIVATE int mjs_get_lineno_by_offset(struct mjs *mjs, int offset) {
  int ret = 1;
  int header_idx = mjs_get_bcode_header_offset(mjs, offset);
  if (header_idx >= 0) {
    mjs_header_item_t map_offset;
    memcpy(&map_offset, mjs->bcode.buf + header_idx +
                            sizeof(mjs_header_item_t) * MJS_HDR_ITEM_MAP_OFFSET,
           sizeof(map_offset));

    mjs_header_item_t bcode_offset;
    memcpy(&bcode_offset,
           mjs->bcode.buf + header_idx +
               sizeof(mjs_header_item_t) * MJS_HDR_ITEM_BCODE_OFFSET,
           sizeof(bcode_offset));

    offset -= (header_idx + bcode_offset);

    /* get pointer to the length of the map followed by the map itself */
    uint8_t *p = (uint8_t *) mjs->bcode.buf + header_idx + map_offset;

    int llen, map_len = varint_decode(p, &llen);
    p += llen;
    uint8_t *pe = p + map_len;

    int prev_line_no = 1;
    while (p < pe) {
      int llen;
      int cur_offset = varint_decode(p, &llen);
      p += llen;
      int line_no = varint_decode(p, &llen);
      p += llen;

      if (cur_offset >= offset) {
        ret = prev_line_no;
        break;
      }
      prev_line_no = line_no;
    }
  }
  return ret;
}

static void mjs_print_stack_trace_line(struct mjs *mjs, size_t offset) {
  const char *filename = mjs_get_bcode_filename_by_offset(mjs, offset);
  int line_no = mjs_get_lineno_by_offset(mjs, offset);
  if (filename == NULL) {
    fprintf(stderr, "ERROR: wrong bcode offset %d\n", (int) offset);
    filename = "<unknown-filename>";
  }
  fprintf(stderr, "  at %s:%d\n", filename, line_no);
}

MJS_PRIVATE void mjs_print_stack_trace(struct mjs *mjs, size_t offset) {
  mjs_print_stack_trace_line(mjs, offset);
  while (mjs->call_stack.len >= sizeof(mjs_val_t) * 3) {
    /* pop retval_stack_idx */
    mjs_pop_val(&mjs->call_stack);
    /* pop scope_index */
    mjs_pop_val(&mjs->call_stack);
    /* pop return_address and set current offset to it */
    offset = mjs_get_int(mjs, mjs_pop_val(&mjs->call_stack));
    mjs_print_stack_trace_line(mjs, offset);
  }
}

void mjs_own(struct mjs *mjs, mjs_val_t *v) {
  mbuf_append(&mjs->owned_values, &v, sizeof(v));
}

int mjs_disown(struct mjs *mjs, mjs_val_t *v) {
  mjs_val_t **vp = (mjs_val_t **) (mjs->owned_values.buf +
                                   mjs->owned_values.len - sizeof(v));

  for (; (char *) vp >= mjs->owned_values.buf; vp--) {
    if (*vp == v) {
      *vp = *(mjs_val_t **) (mjs->owned_values.buf + mjs->owned_values.len -
                             sizeof(v));
      mjs->owned_values.len -= sizeof(v);
      return 1;
    }
  }

  return 0;
}

/*
 * Returns position in the data stack at which the called function is located,
 * and which should be later replaced with the returned value.
 */
MJS_PRIVATE int mjs_getretvalpos(struct mjs *mjs) {
  int pos;
  mjs_val_t *ppos = vptr(&mjs->call_stack, -1);
  // LOG(LL_INFO, ("ppos: %p %d", ppos, mjs_stack_size(&mjs->call_stack)));
  assert(ppos != NULL && mjs_is_number(*ppos));
  pos = mjs_get_int(mjs, *ppos) - 1;
  assert(pos < (int) mjs_stack_size(&mjs->stack));
  return pos;
}

MJS_PRIVATE int mjs_nargs(struct mjs *mjs) {
  int top = mjs_stack_size(&mjs->stack);
  int pos = mjs_getretvalpos(mjs) + 1;
  // LOG(LL_INFO, ("top: %d pos: %d", top, pos));
  return pos > 0 && pos < top ? top - pos : 0;
}

MJS_PRIVATE mjs_val_t mjs_arg(struct mjs *mjs, int arg_index) {
  mjs_val_t res = MJS_UNDEFINED;
  int top = mjs_stack_size(&mjs->stack);
  int pos = mjs_getretvalpos(mjs) + 1;
  // LOG(LL_INFO, ("idx %d pos: %d", arg_index, pos));
  if (pos > 0 && pos + arg_index < top) {
    res = *vptr(&mjs->stack, pos + arg_index);
  }
  return res;
}

MJS_PRIVATE void mjs_return(struct mjs *mjs, mjs_val_t v) {
  int pos = mjs_getretvalpos(mjs);
  // LOG(LL_INFO, ("pos: %d", pos));
  mjs->stack.len = sizeof(mjs_val_t) * pos;
  mjs_push(mjs, v);
}

MJS_PRIVATE mjs_val_t vtop(struct mbuf *m) {
  size_t size = mjs_stack_size(m);
  return size > 0 ? *vptr(m, size - 1) : MJS_UNDEFINED;
}

MJS_PRIVATE size_t mjs_stack_size(const struct mbuf *m) {
  return m->len / sizeof(mjs_val_t);
}

MJS_PRIVATE mjs_val_t *vptr(struct mbuf *m, int idx) {
  int size = mjs_stack_size(m);
  if (idx < 0) idx = size + idx;
  return idx >= 0 && idx < size ? &((mjs_val_t *) m->buf)[idx] : NULL;
}

MJS_PRIVATE mjs_val_t mjs_pop(struct mjs *mjs) {
  if (mjs->stack.len == 0) {
    mjs_set_errorf(mjs, MJS_INTERNAL_ERROR, "stack underflow");
    return MJS_UNDEFINED;
  } else {
    return mjs_pop_val(&mjs->stack);
  }
}

MJS_PRIVATE void push_mjs_val(struct mbuf *m, mjs_val_t v) {
  mbuf_append(m, &v, sizeof(v));
}

MJS_PRIVATE mjs_val_t mjs_pop_val(struct mbuf *m) {
  mjs_val_t v = MJS_UNDEFINED;
  assert(m->len >= sizeof(v));
  if (m->len >= sizeof(v)) {
    memcpy(&v, m->buf + m->len - sizeof(v), sizeof(v));
    m->len -= sizeof(v);
  }
  return v;
}

MJS_PRIVATE void mjs_push(struct mjs *mjs, mjs_val_t v) {
  push_mjs_val(&mjs->stack, v);
}
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_dataview.c"
#endif
/*
 * Copyright (c) 2017 Cesanta Software Limited
 * All rights reserved
 */

/* Amalgamated: #include "mjs/src/mjs_exec_public.h" */
/* Amalgamated: #include "mjs/src/mjs_internal.h" */
/* Amalgamated: #include "mjs/src/mjs_object.h" */
/* Amalgamated: #include "mjs/src/mjs_primitive.h" */
/* Amalgamated: #include "mjs/src/mjs_util.h" */

void *mjs_mem_get_ptr(void *base, int offset) {
  return (char *) base + offset;
}

void mjs_mem_set_ptr(void *ptr, void *val) {
  *(void **) ptr = val;
}

double mjs_mem_get_dbl(void *ptr) {
  double v;
  memcpy(&v, ptr, sizeof(v));
  return v;
}

void mjs_mem_set_dbl(void *ptr, double val) {
  memcpy(ptr, &val, sizeof(val));
}

unsigned mjs_mem_get_uint(void *ptr, int size, int bigendian) {
  uint8_t *p = (uint8_t *) ptr;
  int i, inc = bigendian ? 1 : -1;
  unsigned res = 0;
  p += bigendian ? 0 : size - 1;
  for (i = 0; i < size; i++, p += inc) {
    res <<= 8;
    res |= *p;
  }
  return res;
}

void mjs_mem_set_uint(void *ptr, unsigned val, int size, int bigendian) {
  uint8_t *p = (uint8_t *) ptr + (bigendian ? 0 : size - 1);
  int i, inc = bigendian ? 1 : -1;
  for (i = 0; i < size; i++, p += inc) {
    *p = val & 0xff;
    val >>= 8;
  }
}

int mjs_mem_get_int(void *ptr, int size, int bigendian) {
  int8_t *p = (int8_t *) ptr + (bigendian ? 0 : size - 1);
  int i, inc = bigendian ? 1 : -1, res = 0;
  for (i = 0; i < size; i++, p += inc) {
    res <<= 8;
    res |= *p;
  }
  return res;
}

void mjs_mem_set_int(void *ptr, int val, int size, int bigendian) {
  mjs_mem_set_uint(ptr, val, size, bigendian);
}
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_exec.c"
#endif
/*
 * Copyright (c) 2017 Cesanta Software Limited
 * All rights reserved
 */

/* Amalgamated: #include "mjs/src/mjs_array.h" */
/* Amalgamated: #include "mjs/src/mjs_bcode.h" */
/* Amalgamated: #include "mjs/src/mjs_conversion.h" */
/* Amalgamated: #include "mjs/src/mjs_core.h" */
/* Amalgamated: #include "mjs/src/mjs_exec.h" */
/* Amalgamated: #include "mjs/src/mjs_internal.h" */
/* Amalgamated: #include "mjs/src/mjs_object.h" */
/* Amalgamated: #include "mjs/src/mjs_parser.h" */
/* Amalgamated: #include "mjs/src/mjs_primitive.h" */
/* Amalgamated: #include "mjs/src/mjs_string.h" */
/* Amalgamated: #include "mjs/src/mjs_tok.h" */
/* Amalgamated: #include "mjs/src/mjs_util.h" */
/* Amalgamated: #include "mjs/src/mjs_varint.h" */

static mjs_val_t mjs_find_scope(struct mjs *mjs, mjs_val_t key) {
  size_t num_scopes = mjs_stack_size(&mjs->scopes);
  while (num_scopes > 0) {
    mjs_val_t scope = *vptr(&mjs->scopes, num_scopes - 1);
    num_scopes--;
    if (mjs_get_own_property_v(mjs, scope, key) != NULL) return scope;
  }
  mjs_set_errorf(mjs, MJS_REFERENCE_ERROR, "[%s] is not defined",
                 mjs_get_cstring(mjs, &key));
  return MJS_UNDEFINED;
}

mjs_val_t mjs_get_this(struct mjs *mjs) {
  return mjs->vals.this_obj;
}

static mjs_val_t mjs_get_this_for_js_call(struct mjs *mjs) {
  int top = mjs_stack_size(&mjs->call_stack);
  if (top == 0) return MJS_UNDEFINED;
  assert(top >= 4 && (top % 4) == 0);
  return *vptr(&mjs->call_stack, top - 4);
}

static double do_arith_op(double da, double db, int op) {
  /* clang-format off */
  switch (op) {
    case TOK_MINUS:   return da - db;
    case TOK_PLUS:    return da + db;
    case TOK_MUL:     return da * db;
    case TOK_DIV:     return da / db;
    case TOK_REM:     return (int64_t) da % (int64_t) db;
    case TOK_AND:     return (int64_t) da & (int64_t) db;
    case TOK_OR:      return (int64_t) da | (int64_t) db;
    case TOK_XOR:     return (int64_t) da ^ (int64_t) db;
    case TOK_LSHIFT:  return (int64_t) da << (int64_t) db;
    case TOK_RSHIFT:  return (int64_t) da >> (int64_t) db;
    case TOK_URSHIFT: return (uint32_t) da >> (uint32_t) db;
  }
  /* clang-format on */
  return (int64_t) MJS_TAG_NAN;
}

static void op_assign(struct mjs *mjs, int op) {
  mjs_val_t val = mjs_pop(mjs);
  mjs_val_t obj = mjs_pop(mjs);
  mjs_val_t key = mjs_pop(mjs);
  if (mjs_is_object(obj) && mjs_is_string(key)) {
    mjs_val_t v = mjs_get_v(mjs, obj, key);
    double da = mjs_get_double(mjs, v);
    double db = mjs_get_double(mjs, val);
    double result = do_arith_op(da, db, op);
    mjs_set_v(mjs, obj, key, mjs_mk_number(mjs, result));
    mjs_push(mjs, v);
  } else {
    mjs_set_errorf(mjs, MJS_TYPE_ERROR, "invalid operand");
  }
}

static void exec_expr(struct mjs *mjs, int op) {
  switch (op) {
    case TOK_DOT:
      break;
    case TOK_MINUS:
    case TOK_PLUS:
    case TOK_MUL:
    case TOK_DIV:
    case TOK_REM:
    case TOK_XOR:
    case TOK_AND:
    case TOK_OR:
    case TOK_LSHIFT:
    case TOK_RSHIFT:
    case TOK_URSHIFT: {
      mjs_val_t a = mjs_pop(mjs);
      mjs_val_t b = mjs_pop(mjs);
      if (mjs_is_number(a) && mjs_is_number(b)) {
        double da = mjs_get_double(mjs, a);
        double db = mjs_get_double(mjs, b);
        mjs_push(mjs, mjs_mk_number(mjs, do_arith_op(db, da, op)));
      } else if (mjs_is_string(a) && mjs_is_string(b) && (op == TOK_PLUS)) {
        mjs_push(mjs, s_concat(mjs, b, a));
      } else {
        mjs_push(mjs, MJS_UNDEFINED);
        mjs_set_errorf(mjs, MJS_TYPE_ERROR, NULL);
      }
      break;
    }
    case TOK_UNARY_MINUS: {
      double a = mjs_get_double(mjs, mjs_pop(mjs));
      mjs_push(mjs, mjs_mk_number(mjs, -a));
      break;
    }
    case TOK_TILDA: {
      double a = mjs_get_double(mjs, mjs_pop(mjs));
      mjs_push(mjs, mjs_mk_number(mjs, ~(int64_t) a));
      break;
    }
    case TOK_UNARY_PLUS:
      break;
    case TOK_EQ:
      mjs_set_errorf(mjs, MJS_NOT_IMPLEMENTED_ERROR, "Use ===, not ==");
      break;
    case TOK_NE:
      mjs_set_errorf(mjs, MJS_NOT_IMPLEMENTED_ERROR, "Use !==, not !=");
      break;
    case TOK_EQ_EQ: {
      mjs_val_t a = mjs_pop(mjs);
      mjs_val_t b = mjs_pop(mjs);
      if (a == b) {
        mjs_push(mjs, mjs_mk_boolean(mjs, 1));
      } else if (mjs_is_number(a) && mjs_is_number(b)) {
        mjs_push(mjs, mjs_mk_boolean(mjs, 0));
      } else if (mjs_is_string(a) && mjs_is_string(b)) {
        mjs_push(mjs, mjs_mk_boolean(mjs, s_cmp(mjs, a, b) == 0));
      } else {
        mjs_push(mjs, mjs_mk_boolean(mjs, 0));
      }
      break;
    }
    case TOK_NE_NE: {
      mjs_val_t a = mjs_pop(mjs);
      mjs_val_t b = mjs_pop(mjs);
      if (a == b) {
        mjs_push(mjs, mjs_mk_boolean(mjs, 0));
      } else if (mjs_is_number(a) && mjs_is_number(b)) {
        mjs_push(mjs, mjs_mk_boolean(mjs, 1));
      } else if (mjs_is_string(a) && mjs_is_string(b)) {
        mjs_push(mjs, mjs_mk_boolean(mjs, s_cmp(mjs, a, b) != 0));
      } else {
        mjs_push(mjs, mjs_mk_boolean(mjs, 1));
      }
      break;
    }
    case TOK_LT: {
      double b = mjs_get_double(mjs, mjs_pop(mjs));
      double a = mjs_get_double(mjs, mjs_pop(mjs));
      mjs_push(mjs, mjs_mk_boolean(mjs, a < b));
      break;
    }
    case TOK_GT: {
      double b = mjs_get_double(mjs, mjs_pop(mjs));
      double a = mjs_get_double(mjs, mjs_pop(mjs));
      mjs_push(mjs, mjs_mk_boolean(mjs, a > b));
      break;
    }
    case TOK_ASSIGN: {
      mjs_val_t val = mjs_pop(mjs);
      mjs_val_t obj = mjs_pop(mjs);
      mjs_val_t key = mjs_pop(mjs);
      mjs_set_v(mjs, obj, key, val);
      mjs_push(mjs, val);
      break;
    }
    case TOK_POSTFIX_PLUS: {
      mjs_val_t obj = mjs_pop(mjs);
      mjs_val_t key = mjs_pop(mjs);
      if (mjs_is_object(obj) && mjs_is_string(key)) {
        mjs_val_t v = mjs_get_v(mjs, obj, key);
        mjs_val_t v1 = mjs_mk_number(mjs, mjs_get_double(mjs, v) + 1);
        mjs_set_v(mjs, obj, key, v1);
        mjs_push(mjs, v);
      } else {
        mjs_set_errorf(mjs, MJS_TYPE_ERROR, "invalid operand for ++");
      }
      break;
    }
    case TOK_POSTFIX_MINUS: {
      mjs_val_t obj = mjs_pop(mjs);
      mjs_val_t key = mjs_pop(mjs);
      if (mjs_is_object(obj) && mjs_is_string(key)) {
        mjs_val_t v = mjs_get_v(mjs, obj, key);
        mjs_val_t v1 = mjs_mk_number(mjs, mjs_get_double(mjs, v) - 1);
        mjs_set_v(mjs, obj, key, v1);
        mjs_push(mjs, v);
      } else {
        mjs_set_errorf(mjs, MJS_TYPE_ERROR, "invalid operand for --");
      }
      break;
    }
    case TOK_MINUS_MINUS: {
      mjs_val_t obj = mjs_pop(mjs);
      mjs_val_t key = mjs_pop(mjs);
      if (mjs_is_object(obj) && mjs_is_string(key)) {
        mjs_val_t v = mjs_get_v(mjs, obj, key);
        v = mjs_mk_number(mjs, mjs_get_double(mjs, v) - 1);
        mjs_set_v(mjs, obj, key, v);
        mjs_push(mjs, v);
      } else {
        mjs_set_errorf(mjs, MJS_TYPE_ERROR, "invalid operand for --");
      }
      break;
    }
    case TOK_PLUS_PLUS: {
      mjs_val_t obj = mjs_pop(mjs);
      mjs_val_t key = mjs_pop(mjs);
      if (mjs_is_object(obj) && mjs_is_string(key)) {
        mjs_val_t v = mjs_get_v(mjs, obj, key);
        v = mjs_mk_number(mjs, mjs_get_double(mjs, v) + 1);
        mjs_set_v(mjs, obj, key, v);
        mjs_push(mjs, v);
      } else {
        mjs_set_errorf(mjs, MJS_TYPE_ERROR, "invalid operand for ++");
      }
      break;
    }
    case TOK_LOGICAL_AND: {
      mjs_val_t a = mjs_pop(mjs);
      mjs_val_t b = mjs_pop(mjs);
      if (mjs_is_boolean(a) && mjs_is_boolean(b)) {
        mjs_push(mjs, mjs_mk_boolean(mjs, (a & 1) && (b & 1)));
      } else {
        mjs_set_errorf(mjs, MJS_TYPE_ERROR, NULL);
      }
      break;
    }
    case TOK_LOGICAL_OR: {
      mjs_val_t a = mjs_pop(mjs);
      mjs_val_t b = mjs_pop(mjs);
      if (mjs_is_boolean(a) && mjs_is_boolean(b)) {
        mjs_push(mjs, mjs_mk_boolean(mjs, (a & 1) || (b & 1)));
      } else {
        mjs_set_errorf(mjs, MJS_TYPE_ERROR, NULL);
      }
      break;
    }
    /* clang-format off */
    case TOK_MINUS_ASSIGN:    op_assign(mjs, TOK_MINUS);    break;
    case TOK_PLUS_ASSIGN:     op_assign(mjs, TOK_PLUS);     break;
    case TOK_MUL_ASSIGN:      op_assign(mjs, TOK_MUL);      break;
    case TOK_DIV_ASSIGN:      op_assign(mjs, TOK_DIV);      break;
    case TOK_REM_ASSIGN:      op_assign(mjs, TOK_REM);      break;
    case TOK_AND_ASSIGN:      op_assign(mjs, TOK_AND);      break;
    case TOK_OR_ASSIGN:       op_assign(mjs, TOK_OR);       break;
    case TOK_XOR_ASSIGN:      op_assign(mjs, TOK_XOR);      break;
    case TOK_LSHIFT_ASSIGN:   op_assign(mjs, TOK_LSHIFT);   break;
    case TOK_RSHIFT_ASSIGN:   op_assign(mjs, TOK_RSHIFT);   break;
    case TOK_URSHIFT_ASSIGN:  op_assign(mjs, TOK_URSHIFT);  break;
    case TOK_COMMA: break;
    /* clang-format on */
    case TOK_KEYWORD_TYPEOF:
      mjs_push(mjs, mjs_mk_string(mjs, mjs_typeof(mjs_pop(mjs)), ~0, 1));
      break;
    default:
      LOG(LL_ERROR, ("Unknown expr: %d", op));
      break;
  }
}

static void mjs_execute(struct mjs *mjs, size_t off) {
  size_t i;
  mjs_set_errorf(mjs, MJS_OK, NULL);
  for (i = off; i < mjs->bcode.len; i++) {
    if (mjs->need_gc) {
      if (maybe_gc(mjs)) {
        mjs->need_gc = 0;
      }
    }
#if MJS_AGGRESSIVE_GC
    maybe_gc(mjs);
#endif
    const uint8_t *code = (const uint8_t *) mjs->bcode.buf;
    LOG(LL_VERBOSE_DEBUG, ("%d %s", (int) i, opcodetostr(code[i])));
    switch (code[i]) {
      case OP_BCODE_HEADER: {
        mjs_header_item_t bcode_offset;
        memcpy(&bcode_offset,
               code + i + 1 +
                   sizeof(mjs_header_item_t) * MJS_HDR_ITEM_BCODE_OFFSET,
               sizeof(bcode_offset));
        i += bcode_offset;
      } break;
      case OP_PUSH_NULL:
        mjs_push(mjs, mjs_mk_null());
        break;
      case OP_PUSH_UNDEF:
        mjs_push(mjs, mjs_mk_undefined());
        break;
      case OP_PUSH_FALSE:
        mjs_push(mjs, mjs_mk_boolean(mjs, 0));
        break;
      case OP_PUSH_TRUE:
        mjs_push(mjs, mjs_mk_boolean(mjs, 1));
        break;
      case OP_PUSH_OBJ:
        mjs_push(mjs, mjs_mk_object(mjs));
        break;
      case OP_PUSH_ARRAY:
        mjs_push(mjs, mjs_mk_array(mjs));
        break;
      case OP_PUSH_FUNC: {
        int llen, n = varint_decode(&code[i + 1], &llen);
        mjs_push(mjs, mjs_mk_function(mjs, n));
        i += llen;
        break;
      }
      case OP_PUSH_THIS:
        mjs_push(mjs, mjs_get_this_for_js_call(mjs));
        break;
      case OP_JMP:
        i += code[i + 1] - 1;
        break;
      case OP_JMP_BACK:
        i -= code[i + 1] + 1;
        break;
      case OP_JMP_FALSE: {
        if (mjs_is_truthy(mjs, mjs_pop(mjs))) {
          i++;
        } else {
          mjs_push(mjs, MJS_UNDEFINED);
          i += code[i + 1] - 1;
        }
        break;
      }
      case OP_FIND_SCOPE: {
        mjs_val_t key = vtop(&mjs->stack);
        mjs_push(mjs, mjs_find_scope(mjs, key));
        break;
      }
      case OP_CREATE: {
        mjs_val_t obj = mjs_pop(mjs);
        mjs_val_t key = mjs_pop(mjs);
        if (mjs_get_own_property_v(mjs, obj, key) == NULL) {
          mjs_set_v(mjs, obj, key, MJS_UNDEFINED);
        }
        break;
      }
      case OP_APPEND: {
        mjs_val_t val = mjs_pop(mjs);
        mjs_val_t arr = mjs_pop(mjs);
        mjs_err_t err = mjs_array_push(mjs, arr, val);
        if (err != MJS_OK) {
          mjs_set_errorf(mjs, MJS_TYPE_ERROR, "append to non-array");
        }
        break;
      }
      case OP_SET_THIS:
        mjs->vals.this_obj = vtop(&mjs->stack);
        break;
      case OP_GET: {
        mjs_val_t obj = mjs_pop(mjs);
        mjs_val_t key = mjs_pop(mjs);
        mjs_val_t val = MJS_UNDEFINED;
        if (!mjs_is_object(obj)) {
          mjs_set_errorf(mjs, MJS_TYPE_ERROR, "type error");
        } else {
          val = mjs_get_v_proto(mjs, obj, key);
        }
        mjs_push(mjs, val);
        break;
      }
      case OP_DEL_SCOPE:
        if (mjs->scopes.len <= 1) {
          mjs_set_errorf(mjs, MJS_INTERNAL_ERROR, "scopes underflow");
        } else {
          mjs_pop_val(&mjs->scopes);
        }
        break;
      case OP_NEW_SCOPE:
        push_mjs_val(&mjs->scopes, mjs_mk_object(mjs));
        break;
      case OP_PUSH_SCOPE:
        assert(mjs_stack_size(&mjs->scopes) > 0);
        mjs_push(mjs, vtop(&mjs->scopes));
        break;
      case OP_PUSH_STR: {
        int llen, n = varint_decode(&code[i + 1], &llen);
        mjs_push(mjs, mjs_mk_string(mjs, (char *) code + i + 1 + llen, n, 1));
        i += llen + n;
        break;
      }
      case OP_PUSH_INT: {
        int llen;
        int64_t n = varint_decode(&code[i + 1], &llen);
        mjs_push(mjs, mjs_mk_number(mjs, n));
        i += llen;
        break;
      }
      case OP_PUSH_DBL: {
        int llen, n = varint_decode(&code[i + 1], &llen);
        mjs_push(mjs, mjs_mk_number(
                          mjs, strtod((char *) code + i + 1 + llen, NULL)));
        i += llen + n;
        break;
      }
      case OP_FOR_IN_NEXT: {
        /*
         * Data stack layout:
         * ...                                    <-- Bottom of the data stack
         * <iterator_variable_name>   (string)
         * <object_that_is_iterated>  (object)
         * <iterator_foreign_ptr>                 <-- Top of the data stack
         */
        mjs_val_t *iterator = vptr(&mjs->stack, -1);
        mjs_val_t obj = *vptr(&mjs->stack, -2);
        mjs_val_t var_name = *vptr(&mjs->stack, -3);
        mjs_val_t key = mjs_next(mjs, obj, iterator);
        if (key != MJS_UNDEFINED) {
          mjs_val_t scope = mjs_find_scope(mjs, var_name);
          mjs_set_v(mjs, scope, var_name, key);
        }
        break;
      }
      case OP_RETURN: {
        size_t retval_stack_idx, return_address, scope_index;
        assert(mjs_stack_size(&mjs->call_stack) >= 4);

        retval_stack_idx = mjs_get_int(mjs, mjs_pop_val(&mjs->call_stack));
        scope_index = mjs_get_int(mjs, mjs_pop_val(&mjs->call_stack));
        return_address = mjs_get_int(mjs, mjs_pop_val(&mjs->call_stack));
        mjs_pop_val(&mjs->call_stack);  //  Remove `this` value
        mjs->vals.this_obj = MJS_UNDEFINED;

        // Remove created scopes
        while (mjs_stack_size(&mjs->scopes) > scope_index) {
          mjs_pop_val(&mjs->scopes);
        }

        // Shrink stack, leave return value on top
        mjs->stack.len = retval_stack_idx * sizeof(mjs_val_t);

        // Jump to the return address
        i = return_address - 1;
        LOG(LL_VERBOSE_DEBUG, ("RETURNING TO %d", i + 1));
        // mjs_dump(mjs, 0, stdout);
        break;
      }
      case OP_ARGS: {
        push_mjs_val(&mjs->call_stack,
                     mjs_mk_number(mjs, mjs_stack_size(&mjs->stack)));
        break;
      }
      case OP_CALL: {
        // LOG(LL_INFO, ("BEFORE CALL"));
        // mjs_dump(mjs, 0, stdout);
        mjs_val_t retpos = vtop(&mjs->call_stack);
        int func_pos = mjs_get_int(mjs, retpos) - 1;
        mjs_val_t *func = vptr(&mjs->stack, func_pos);
        if (mjs_is_function(*func)) {
          mjs_pop_val(&mjs->call_stack);
          push_mjs_val(&mjs->call_stack, mjs->vals.this_obj);
          push_mjs_val(&mjs->call_stack, mjs_mk_number(mjs, i + 1));
          push_mjs_val(&mjs->call_stack,
                       mjs_mk_number(mjs, mjs_stack_size(&mjs->scopes)));
          push_mjs_val(&mjs->call_stack, retpos);
          i = mjs_get_func_addr(*func) - 1;
          *func = MJS_UNDEFINED;  // Return value
          // LOG(LL_DEBUG, ("CALLING  %d", i + 1));
        } else if (mjs_is_string(*func)) {
          mjs_ffi_call2(mjs);
          /* Pop the value pushed by OP_ARGS */
          mjs_pop_val(&mjs->call_stack);
        } else if (mjs_is_foreign(*func)) {
          /* Call cfunction */
          ((void (*) (struct mjs *)) mjs_get_ptr(mjs, *func))(mjs);
          /* Pop the value pushed by OP_ARGS */
          mjs_pop_val(&mjs->call_stack);
        } else {
          mjs_set_errorf(mjs, MJS_TYPE_ERROR, "calling non-callable");
        }
        break;
      }
      case OP_SET_ARG: {
        int llen1, llen2, n, arg_no = varint_decode(&code[i + 1], &llen1);
        n = varint_decode(&code[i + llen1 + 1], &llen2);
        mjs_val_t key =
            mjs_mk_string(mjs, (char *) code + i + 1 + llen1 + llen2, n, 1);
        mjs_val_t obj = vtop(&mjs->scopes);
        mjs_val_t v = mjs_arg(mjs, arg_no);
        mjs_set_v(mjs, obj, key, v);
        i += llen1 + llen2 + n;
        break;
      }
      case OP_SETRETVAL: {
        if (mjs_stack_size(&mjs->call_stack) < 4) {
          mjs_set_errorf(mjs, MJS_INTERNAL_ERROR, "cannot return");
        } else {
          size_t retval_pos = mjs_get_int(mjs, *vptr(&mjs->call_stack, -1));
          *vptr(&mjs->stack, retval_pos - 1) = mjs_pop(mjs);
        }
        // LOG(LL_INFO, ("AFTER SETRETVAL"));
        // mjs_dump(mjs, 0, stdout);
        break;
      }
      case OP_EXPR: {
        int op = code[i + 1];
        exec_expr(mjs, op);
        i++;
        break;
      }
      case OP_DROP: {
        mjs_pop(mjs);
        break;
      }
      case OP_DUP: {
        mjs_push(mjs, vtop(&mjs->stack));
        break;
      }
      case OP_SWAP: {
        mjs_val_t a = mjs_pop(mjs);
        mjs_val_t b = mjs_pop(mjs);
        mjs_push(mjs, a);
        mjs_push(mjs, b);
        break;
      }
      case OP_LOOP: {
        int l1, l2, off = varint_decode(&code[i + 1], &l1);
        push_mjs_val(&mjs->loop_addresses, mjs_mk_number(mjs, i + off));
        off = varint_decode(&code[i + 1 + l1], &l2);
        push_mjs_val(&mjs->loop_addresses, mjs_mk_number(mjs, i + off));
        i += l1 + l2;
        break;
      }
      case OP_CONTINUE:
        i = mjs_get_int(mjs, vtop(&mjs->loop_addresses)) - 1;
        break;
      case OP_BREAK:
        mjs_pop_val(&mjs->loop_addresses);
        i = mjs_get_int(mjs, mjs_pop_val(&mjs->loop_addresses)) - 1;
        LOG(LL_DEBUG, ("BREAKING TO %d", (int) i + 1));
        break;
      case OP_NOP:
        break;
      case OP_EXIT:
        i = mjs->bcode.len;
        break;
      default:
#if MJS_ENABLE_DEBUG
        mjs_dump(mjs, 1, stdout);
#endif
        mjs_set_errorf(mjs, MJS_INTERNAL_ERROR, "Unknown opcode: %d, off %d",
                       (int) code[i], (int) i);
        i = mjs->bcode.len;
        break;
    }
    if (mjs->error != MJS_OK) {
      mjs_print_stack_trace(mjs, i - 1 /* undo the i++ */);
      break;
    }
  }
}

mjs_err_t mjs_exec2(struct mjs *mjs, const char *path, const char *src,
                    mjs_val_t *res) {
  size_t off = mjs->bcode.len;
  mjs_val_t r = MJS_UNDEFINED;
  mjs->error = mjs_parse(path, src, mjs);
  if (cs_log_level >= LL_DEBUG) mjs_dump(mjs, 1, stderr);
  if (mjs->error != MJS_OK) {
  } else {
    mjs_execute(mjs, off);
    r = mjs_pop(mjs);
  }
  if (res != NULL) *res = r;
  return mjs->error;
}

mjs_err_t mjs_exec(struct mjs *mjs, const char *src, mjs_val_t *res) {
  return mjs_exec2(mjs, "<stdin>", src, res);
}

mjs_err_t mjs_exec_file(struct mjs *mjs, const char *path, mjs_val_t *res) {
  mjs_err_t error = MJS_FILE_READ_ERROR;
  mjs_val_t r = MJS_UNDEFINED;
  size_t size;
  char *source_code = cs_read_file(path, &size);
  r = MJS_UNDEFINED;
  if (source_code != NULL) {
    error = mjs_exec2(mjs, path, source_code, &r);
    free(source_code);
  }
  if (res != NULL) *res = r;
  return error;
}

mjs_err_t mjs_call(struct mjs *mjs, mjs_val_t *res, mjs_val_t func,
                   mjs_val_t this_val, int nargs, ...) {
  va_list ap;
  int i;
  mjs_err_t ret;
  va_start(ap, nargs);
  mjs_val_t *args = calloc(1, sizeof(mjs_val_t) * nargs);
  for (i = 0; i < nargs; i++) {
    args[i] = va_arg(ap, mjs_val_t);
  }

  ret = mjs_apply(mjs, res, func, this_val, nargs, args);
  /*
   * NOTE: calling `bf_run()` invalidates `func` and `this_val`. If you ever
   * need to use them afterwards, you need to own them before.
   */

  free(args);
  return ret;
}

mjs_err_t mjs_apply(struct mjs *mjs, mjs_val_t *res, mjs_val_t func,
                    mjs_val_t this_val, int nargs, mjs_val_t *args) {
  mjs_val_t r;
  int i;
  size_t addr = mjs_get_func_addr(func);

  LOG(LL_VERBOSE_DEBUG, ("applying func %d", mjs_get_func_addr(func)));

  push_mjs_val(&mjs->call_stack, this_val);

  // Push return address: returning to the end of bcode causes execution
  // to stop
  // TODO(dfrank): make special return value for that, because mjs->bcode.len
  // might change after function invocation (if function parses some new code)
  push_mjs_val(&mjs->call_stack, mjs_mk_number(mjs, mjs->bcode.len));
  push_mjs_val(&mjs->call_stack,
               mjs_mk_number(mjs, mjs_stack_size(&mjs->scopes)));
  // Push undefined which will be later replaced with the return value
  mjs_push(mjs, MJS_UNDEFINED);
  push_mjs_val(&mjs->call_stack,
               mjs_mk_number(mjs, mjs_stack_size(&mjs->stack)));

  // Push all arguments
  for (i = 0; i < nargs; i++) {
    mjs_push(mjs, args[i]);
  }

  mjs_execute(mjs, addr);
  r = mjs_pop(mjs);

  if (res != NULL) *res = r;
  return mjs->error;
}
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_ffi.c"
#endif
/*
 * Copyright (c) 2017 Cesanta Software Limited
 * All rights reserved
 */

/* Amalgamated: #include "mjs/src/mjs_core.h" */
/* Amalgamated: #include "mjs/src/mjs_exec.h" */
/* Amalgamated: #include "mjs/src/mjs_internal.h" */
/* Amalgamated: #include "mjs/src/mjs_primitive.h" */
/* Amalgamated: #include "mjs/src/mjs_string.h" */
/* Amalgamated: #include "mjs/src/mjs_util.h" */
/* Amalgamated: #include "mjs/src/ffi/ffi.h" */

/*
 * on linux this is enabled only if __USE_GNU is defined, but we cannot set it
 * because dlfcn could have been included already.
 */
#ifndef RTLD_DEFAULT
#define RTLD_DEFAULT NULL
#endif

typedef void(cb_fn_t)(void);

/*
 * Data of the two related arguments: callback function pointer and the
 * userdata for it
 */
struct cbdata {
  /* JS callback function */
  mjs_val_t func;
  /* JS userdata */
  mjs_val_t userdata;

  /* C function signature source */
  const char *signature;
  size_t signature_len;
  /*
   * Descriptor of the C callback function signature.
   */
  ffi_sig_t sig;
  /* index of the function pointer param */
  int8_t func_idx;
  /* index of the userdata param */
  int8_t userdata_idx;
};

void mjs_set_ffi_resolver(struct mjs *mjs, mjs_ffi_resolver_t *dlsym) {
  mjs->dlsym = dlsym;
}

static cval_type_t parse_cval_type(struct mjs *mjs, const char *s,
                                   const char *e) {
  while (e > s && e[-1] == ' ') e--; /* Trim trailing spaces */
  if (strncmp(s, "void", e - s) == 0) {
    return CVAL_TYPE_NONE;
  } else if (strncmp(s, "userdata", e - s) == 0) {
    return CVAL_TYPE_USERDATA;
  } else if (strncmp(s, "int", e - s) == 0) {
    return CVAL_TYPE_INT;
  } else if (strncmp(s, "double", e - s) == 0) {
    return CVAL_TYPE_DOUBLE;
  } else if (strncmp(s, "char*", 5) == 0 || strncmp(s, "char *", 6) == 0) {
    return CVAL_TYPE_CHAR_PTR;
  } else if (strncmp(s, "void*", 5) == 0 || strncmp(s, "void *", 6) == 0) {
    return CVAL_TYPE_VOID_PTR;
  } else {
    mjs_prepend_errorf(mjs, MJS_TYPE_ERROR, "failed to parse val type \"%.*s\"",
                       (e - s), s);
    return CVAL_TYPE_INVALID;
  }
}

static int parse_cb_signature(struct mjs *mjs, const char *s, const char *e,
                              ffi_sig_t *sig) {
  int ret = 1;
  int vtidx = 0;
  const char *cur = s;
  cval_type_t val_type = CVAL_TYPE_INVALID;
  const char *tmp_e = NULL;

  mjs_ffi_sig_init(sig);

  /* Parse return value type */
  tmp_e = strchr(cur, '(');
  if (tmp_e == NULL) {
    ret = 0;
    goto clean;
  }
  val_type = parse_cval_type(mjs, cur, tmp_e);
  if (val_type == CVAL_TYPE_INVALID) {
    ret = 0;
    goto clean;
  }
  mjs_ffi_sig_set_val_type(sig, vtidx++, val_type);

  /* Advance cur to the beginning of the arg list */
  tmp_e = strchr(tmp_e, ')');
  if (tmp_e == NULL) {
    ret = 0;
    goto clean;
  }
  tmp_e = strchr(tmp_e, '(');
  if (tmp_e == NULL) {
    ret = 0;
    goto clean;
  }
  cur = tmp_e + 1;

  /* Parse all args */
  while (*tmp_e && *tmp_e != ')') {
    tmp_e = cur;

    /* Advance tmp_e until the next arg separator */
    while (*tmp_e && *tmp_e != ',' && *tmp_e != ')') tmp_e++;

    /* Parse current arg */
    val_type = parse_cval_type(mjs, cur, tmp_e);
    if (val_type == CVAL_TYPE_INVALID) {
      /* parse_cval_type() has already set error message */
      ret = 0;
      goto clean;
    }
    if (!mjs_ffi_sig_set_val_type(sig, vtidx++, val_type)) {
      mjs_prepend_errorf(mjs, MJS_TYPE_ERROR, "too many callback args");
      ret = 0;
      goto clean;
    }

    if (*tmp_e == ',') {
      /* Advance cur to the next argument */
      cur = tmp_e + 1;
      while (*cur == ' ') cur++;
    } else {
      /* No more arguments */
      break;
    }
  }

  sig->stat = mjs_ffi_sig_stat_get(mjs, sig);
  if (!sig->stat.is_valid) {
    ret = 0;
    goto clean;
  }

clean:
  if (!ret) {
    mjs_prepend_errorf(mjs, MJS_TYPE_ERROR, "bad callback signature: \"%.*s\"",
                       e - s, s);
  }
  return ret;
}

/* C callbacks implementation {{{ */

/* An argument or a return value for C callback impl */
union ffi_cb_data_val {
  void *p;
  uintptr_t w;
  double d;
};

struct ffi_cb_data {
  union ffi_cb_data_val args[MJS_CB_ARGS_MAX_CNT];
};

static union ffi_cb_data_val ffi_cb_impl_generic(void *param,
                                                 struct ffi_cb_data *data) {
  struct ffi_cb_args *cbargs = (struct ffi_cb_args *) param;
  mjs_val_t res = MJS_UNDEFINED;
  union ffi_cb_data_val ret;
  int i;
  memset(&ret, 0, sizeof(ret));
  mjs_own(cbargs->mjs, &res);

  /* There must be at least one argument: a userdata */
  assert(cbargs->sig.stat.args_cnt > 0);

  /* Create JS arguments */
  mjs_val_t *args = calloc(1, sizeof(mjs_val_t) * cbargs->sig.stat.args_cnt);
  for (i = 0; i < cbargs->sig.stat.args_cnt; i++) {
    cval_type_t val_type =
        cbargs->sig.val_types[i + 1 /* first val_type is return value type */];
    switch (val_type) {
      case CVAL_TYPE_USERDATA:
        args[i] = cbargs->userdata;
        break;
      case CVAL_TYPE_INT:
        args[i] = mjs_mk_number(cbargs->mjs, data->args[i].w);
        break;
      case CVAL_TYPE_CHAR_PTR: {
        const char *s = (char *) data->args[i].w;
        if (s == NULL) s = "";
        args[i] = mjs_mk_string(cbargs->mjs, s, ~0, 1);
        break;
      }
      case CVAL_TYPE_VOID_PTR:
        args[i] = mjs_mk_foreign(cbargs->mjs, (void *) data->args[i].w);
        break;
      case CVAL_TYPE_DOUBLE:
        args[i] = mjs_mk_number(cbargs->mjs, data->args[i].d);
        break;
      default:
        /* should never be here */
        LOG(LL_ERROR, ("unexpected val type for arg #%d: %d\n", i, val_type));
        abort();
    }
  }

  /* Call JS function */
  LOG(LL_VERBOSE_DEBUG, ("calling JS callback void-void %d from C",
                         mjs_get_int(cbargs->mjs, cbargs->func)));
  mjs_err_t err = mjs_apply(cbargs->mjs, &res, cbargs->func, MJS_UNDEFINED,
                            cbargs->sig.stat.args_cnt, args);
  if (err != MJS_OK) {
    /*
     * There's not much we can do about the error here; let's at least print it
     */
    fprintf(stderr, "MJS callback error: %s\n", mjs_strerror(cbargs->mjs, err));

    goto clean;
  }

  /* Get return value, if needed */
  switch (cbargs->sig.val_types[0]) {
    case CVAL_TYPE_NONE:
      /* do nothing */
      break;
    case CVAL_TYPE_INT:
      ret.w = mjs_get_int(cbargs->mjs, res);
      break;
    case CVAL_TYPE_VOID_PTR:
      ret.p = mjs_get_ptr(cbargs->mjs, res);
      break;
    case CVAL_TYPE_DOUBLE:
      ret.d = mjs_get_double(cbargs->mjs, res);
      break;
    default:
      /* should never be here */
      LOG(LL_ERROR,
          ("unexpected return val type %d\n", cbargs->sig.val_types[0]));
      abort();
  }

clean:
  free(args);
  mjs_disown(cbargs->mjs, &res);
  return ret;
}

static void ffi_init_cb_data_wwww(struct ffi_cb_data *data, uintptr_t w0,
                                  uintptr_t w1, uintptr_t w2, uintptr_t w3,
                                  uintptr_t w4, uintptr_t w5) {
  memset(data, 0, sizeof(*data));
  data->args[0].w = w0;
  data->args[1].w = w1;
  data->args[2].w = w2;
  data->args[3].w = w3;
  data->args[4].w = w4;
  data->args[5].w = w5;
}

static uintptr_t ffi_cb_impl_wpwwwww(uintptr_t w0, uintptr_t w1, uintptr_t w2,
                                     uintptr_t w3, uintptr_t w4, uintptr_t w5) {
  struct ffi_cb_data data;
  ffi_init_cb_data_wwww(&data, w0, w1, w2, w3, w4, w5);
  return ffi_cb_impl_generic((void *) w0, &data).w;
}

static uintptr_t ffi_cb_impl_wwpwwww(uintptr_t w0, uintptr_t w1, uintptr_t w2,
                                     uintptr_t w3, uintptr_t w4, uintptr_t w5) {
  struct ffi_cb_data data;
  ffi_init_cb_data_wwww(&data, w0, w1, w2, w3, w4, w5);
  return ffi_cb_impl_generic((void *) w1, &data).w;
}

static uintptr_t ffi_cb_impl_wwwpwww(uintptr_t w0, uintptr_t w1, uintptr_t w2,
                                     uintptr_t w3, uintptr_t w4, uintptr_t w5) {
  struct ffi_cb_data data;
  ffi_init_cb_data_wwww(&data, w0, w1, w2, w3, w4, w5);
  return ffi_cb_impl_generic((void *) w2, &data).w;
}

static uintptr_t ffi_cb_impl_wwwwpww(uintptr_t w0, uintptr_t w1, uintptr_t w2,
                                     uintptr_t w3, uintptr_t w4, uintptr_t w5) {
  struct ffi_cb_data data;
  ffi_init_cb_data_wwww(&data, w0, w1, w2, w3, w4, w5);
  return ffi_cb_impl_generic((void *) w3, &data).w;
}

static uintptr_t ffi_cb_impl_wwwwwpw(uintptr_t w0, uintptr_t w1, uintptr_t w2,
                                     uintptr_t w3, uintptr_t w4, uintptr_t w5) {
  struct ffi_cb_data data;
  ffi_init_cb_data_wwww(&data, w0, w1, w2, w3, w4, w5);
  return ffi_cb_impl_generic((void *) w4, &data).w;
}

static uintptr_t ffi_cb_impl_wwwwwwp(uintptr_t w0, uintptr_t w1, uintptr_t w2,
                                     uintptr_t w3, uintptr_t w4, uintptr_t w5) {
  struct ffi_cb_data data;
  ffi_init_cb_data_wwww(&data, w0, w1, w2, w3, w4, w5);
  return ffi_cb_impl_generic((void *) w5, &data).w;
}
/* }}} */

static struct ffi_cb_args **ffi_get_matching(struct ffi_cb_args **plist,
                                             mjs_val_t func,
                                             mjs_val_t userdata) {
  for (; *plist != NULL; plist = &((*plist)->next)) {
    if ((*plist)->func == func && (*plist)->userdata == userdata) {
      break;
    }
  }
  return plist;
}

static cb_fn_t *get_cb_impl_by_signature(const ffi_sig_t *sig) {
  if (sig->stat.is_valid) {
    if (sig->stat.args_cnt <= MJS_CB_ARGS_MAX_CNT) {
      if (mjs_ffi_is_regular_word_or_void(sig->val_types[0])) {
        /* Return type is a word or void */
        if (sig->stat.args_double_cnt == 0) {
          /* No double arguments */
          switch (sig->stat.userdata_idx) {
            case 1:
              return (cb_fn_t *) ffi_cb_impl_wpwwwww;
            case 2:
              return (cb_fn_t *) ffi_cb_impl_wwpwwww;
            case 3:
              return (cb_fn_t *) ffi_cb_impl_wwwpwww;
            case 4:
              return (cb_fn_t *) ffi_cb_impl_wwwwpww;
            case 5:
              return (cb_fn_t *) ffi_cb_impl_wwwwwpw;
            case 6:
              return (cb_fn_t *) ffi_cb_impl_wwwwwwp;
            default:
              /* should never be here */
              abort();
          }
        }
      }
    } else {
      /* Too many arguments for the built-in callback impls */
      /* TODO(dfrank): add support for custom app-dependent resolver */
    }
  }

  return NULL;
}

MJS_PRIVATE mjs_err_t mjs_ffi_call(struct mjs *mjs) {
  mjs_return(mjs, mjs_arg(mjs, 0));
  return MJS_OK;
}

MJS_PRIVATE mjs_err_t mjs_ffi_call2(struct mjs *mjs) {
  mjs_err_t ret = MJS_OK;
  mjs_val_t sig = *vptr(&mjs->stack, mjs_getretvalpos(mjs));
  const char *s = mjs_get_cstring(mjs, &sig);
  const char *n, *e, *a = NULL;
  ffi_fn_t fn;
  int i, nargs;
  struct ffi_arg res;
  struct ffi_arg args[FFI_MAX_ARGS_CNT];
  struct cbdata cbdata;
  cval_type_t rtype;

  /* TODO(dfrank): support multiple callbacks */
  mjs_val_t resv = mjs_mk_undefined();
  mjs_val_t argvs[FFI_MAX_ARGS_CNT];

  memset(&cbdata, 0, sizeof(cbdata));
  cbdata.func_idx = -1;
  cbdata.userdata_idx = -1;

  for (n = s; *n && *n >= 'a' && *n <= 'z';) n++; /* Skip type name */
  while (*n == ' ' || *n == '*') n++;             /* Skip to function name */
  for (e = n; *e && *e != '(';) e++;              /* Skip function name */
  if (*e == '(') a = e + 1;

  rtype = parse_cval_type(mjs, s, n);
  if (rtype == CVAL_TYPE_INVALID) {
    ret = MJS_TYPE_ERROR;
    mjs_prepend_errorf(mjs, ret, "wrong ffi return type");
    goto clean;
  }

  res.size = rtype == CVAL_TYPE_DOUBLE ? 8 : 4;
  res.is_float = rtype == CVAL_TYPE_DOUBLE;
  res.v.i = 0;

  nargs =
      mjs_stack_size(&mjs->stack) - mjs_get_int(mjs, vtop(&mjs->call_stack));
  for (i = 0; i < nargs; i++) {
    const char *ae; /* pointer to the one-past-end character */
    int level = 0;  /* nested parens level */
    int is_fp = 0;  /* set to 1 is current arg is a callback function ptr */
    mjs_val_t arg = mjs_arg(mjs, i);
    if (a == NULL) {
      ret = MJS_TYPE_ERROR;
      mjs_prepend_errorf(mjs, ret, "got %d actuals", nargs);
      goto clean;
    }
    while (*a == ' ') a++;
    ae = a;
    while (*ae && (level > 0 || (*ae != ',' && *ae != ')'))) {
      switch (*ae) {
        case '(':
          level++;
          /*
           * only function pointer params can have parens, so, set the flag
           * that it's going to be a function pointer
           */
          is_fp = 1;
          break;
        case ')':
          level--;
          break;
      }
      ae++;
    }

    if (is_fp) {
      /*
       * Current argument is a callback function pointer: remember the given JS
       * function and the argument index
       */
      cbdata.func = arg;
      cbdata.func_idx = i;
      cbdata.signature = a;
      cbdata.signature_len = (size_t)(ae - a);
      if (!parse_cb_signature(mjs, a, ae, &cbdata.sig)) {
        ret = MJS_TYPE_ERROR;
        goto clean;
      }
    } else {
      /* Some non-function argument */
      cval_type_t ctype = parse_cval_type(mjs, a, ae);
      switch (ctype) {
        case CVAL_TYPE_NONE:
          /*
           * Void argument: in any case, it's an error, because if C function
           * takes no arguments, then the FFI-ed JS function should be called
           * without any arguments, and thus we'll not face "void" here.
           */
          ret = MJS_TYPE_ERROR;
          if (i == 0) {
            /* FFI signature is correct, but invocation is wrong */
            mjs_prepend_errorf(mjs, ret, "ffi-ed function takes no arguments");
          } else {
            /*
             * FFI signature is wrong: we can't have "void" as a non-first
             * "argument"
             */
            mjs_prepend_errorf(mjs, ret, "bad ffi arg #%d type: \"void\"", i);
          }

          goto clean;
        case CVAL_TYPE_USERDATA:
          /* Userdata for the callback */
          if (cbdata.userdata_idx != -1) {
            ret = MJS_TYPE_ERROR;
            mjs_prepend_errorf(mjs, ret,
                               "two or more userdata args: #%d and %d",
                               cbdata.userdata_idx, i);

            goto clean;
          }
          cbdata.userdata = arg;
          cbdata.userdata_idx = i;
          break;
        case CVAL_TYPE_INT:
          ffi_set_int32(&args[i], mjs_get_int(mjs, arg));
          break;
        case CVAL_TYPE_DOUBLE:
          ffi_set_double(&args[i], mjs_get_double(mjs, arg));
          break;
        case CVAL_TYPE_CHAR_PTR: {
          size_t s;
          if (!mjs_is_string(arg)) {
            ret = MJS_TYPE_ERROR;
            mjs_prepend_errorf(
                mjs, ret,
                "actual arg #%d is not a string (the type idx is: %s)", i,
                mjs_typeof(arg));
            goto clean;
          }
          argvs[i] = arg;
          ffi_set_ptr(&args[i], (void *) mjs_get_string(mjs, &argvs[i], &s));
        } break;
        case CVAL_TYPE_VOID_PTR:
          if (!mjs_is_foreign(arg) && !mjs_is_string(arg)) {
            ret = MJS_TYPE_ERROR;
            mjs_prepend_errorf(mjs, ret, "actual arg #%d is not a ptr", i);
            goto clean;
          }
          if (mjs_is_string(arg)) {
            size_t n;
            ffi_set_ptr(&args[i], (void *) mjs_get_string(mjs, &arg, &n));
          } else {
            ffi_set_ptr(&args[i], (void *) mjs_get_ptr(mjs, arg));
          }
          break;
        case CVAL_TYPE_INVALID:
          /* parse_cval_type() has already set a more detailed error */
          ret = MJS_TYPE_ERROR;
          mjs_prepend_errorf(mjs, ret, "wrong arg type");
          goto clean;
        default:
          abort();
          break;
      }
    }

    a = ae + 1;
    if (*a == '\0') a = NULL;
  }

  if (mjs->dlsym == NULL) {
    ret = MJS_TYPE_ERROR;
    mjs_prepend_errorf(mjs, ret,
                       "resolver is not set, call mjs_set_ffi_resolver");
    goto clean;
  }

  {
    char buf[100];
    snprintf(buf, sizeof(buf), "%.*s", (int) (e - n), n);
    fn = (ffi_fn_t) mjs->dlsym(RTLD_DEFAULT, buf);
    if (fn == NULL) {
      ret = MJS_TYPE_ERROR;
      mjs_prepend_errorf(mjs, ret, "dlsym('%s') failed", buf);
      goto clean;
    }
  }

  if (cbdata.userdata_idx >= 0 && cbdata.func_idx >= 0) {
    struct ffi_cb_args *cbargs = NULL;
    struct ffi_cb_args **pitem = NULL;

    /* the function takes a callback */

    /* Get C callback implementation by the given signature */
    cb_fn_t *cb_fn = get_cb_impl_by_signature(&cbdata.sig);
    if (cb_fn == NULL) {
      ret = MJS_TYPE_ERROR;
      mjs_prepend_errorf(mjs, ret,
                         "the callback signature '%.*s' is valid, but there's "
                         "no existing callback implementation for it",
                         cbdata.signature_len, cbdata.signature);
      goto clean;
    }

    /*
     * Get cbargs: either reuse the existing one (if the matching item exists),
     * or create a new one.
     */
    pitem = ffi_get_matching(&mjs->ffi_cb_args, cbdata.func, cbdata.userdata);
    if (*pitem == NULL) {
      /* No matching cbargs item; we need to add a new one */
      cbargs = calloc(1, sizeof(*cbargs));
      cbargs->mjs = mjs;
      cbargs->func = cbdata.func;
      cbargs->userdata = cbdata.userdata;
      memcpy(&cbargs->sig, &cbdata.sig, sizeof(cbargs->sig));

      /* Establish a link to the newly allocated item */
      *pitem = cbargs;
    } else {
      /* Found matching item: reuse it */
      cbargs = *pitem;
    }

    ffi_set_ptr(&args[cbdata.func_idx], cb_fn);
    ffi_set_ptr(&args[cbdata.userdata_idx], cbargs);
  } else if (!(cbdata.userdata_idx == -1 && cbdata.func_idx == -1)) {
    /*
     * incomplete signature: it contains either the function pointer or
     * userdata. It should contain both or none.
     */
    ret = MJS_TYPE_ERROR;
    mjs_prepend_errorf(mjs, ret, "need both function and userdata");
    goto clean;
  }

  ffi_call(fn, nargs, &res, args);

  switch (rtype) {
    case CVAL_TYPE_CHAR_PTR: {
      const char *s = (const char *) (uintptr_t) res.v.i;
      resv = mjs_mk_string(mjs, s, ~0, 1);
      break;
    }
    case CVAL_TYPE_VOID_PTR:
      resv = mjs_mk_foreign(mjs, (void *) (uintptr_t) res.v.i);
      break;
    case CVAL_TYPE_INT:
      resv = mjs_mk_number(mjs, (int) res.v.i);
      break;
    case CVAL_TYPE_DOUBLE:
      resv = mjs_mk_number(mjs, res.v.d);
      break;
    default:
      resv = mjs_mk_undefined();
      break;
  }
clean:
  /*
   * If there was some error, prepend an error message with the subject
   * signature
   */
  if (ret != MJS_OK) {
    mjs_prepend_errorf(mjs, ret, "failed to call FFI signature \"%s\"", s);
  }
  mjs_return(mjs, resv);
  return ret;
}

/*
 * TODO(dfrank): make it return boolean (when booleans are supported), instead
 * of a number
 */
MJS_PRIVATE void mjs_ffi_cb_free(struct mjs *mjs) {
  mjs_val_t ret = mjs_mk_number(mjs, 0);
  mjs_val_t func = mjs_arg(mjs, 0);
  mjs_val_t userdata = mjs_arg(mjs, 1);

  if (mjs_is_function(func)) {
    struct ffi_cb_args **pitem =
        ffi_get_matching(&mjs->ffi_cb_args, func, userdata);
    if (*pitem != NULL) {
      /* Found matching item: remove it from the linked list, and free */
      struct ffi_cb_args *cbargs = *pitem;
      *pitem = cbargs->next;
      free(cbargs);
      ret = mjs_mk_number(mjs, 1);
    }
  } else {
    mjs_prepend_errorf(mjs, MJS_TYPE_ERROR, "missing argument 'func'");
  }

  mjs_return(mjs, ret);
}

void mjs_ffi_args_free_list(struct mjs *mjs) {
  ffi_cb_args_t *next = mjs->ffi_cb_args;

  while (next != NULL) {
    ffi_cb_args_t *cur = next;
    next = next->next;
    free(cur);
  }
}

MJS_PRIVATE void mjs_ffi_sig_init(ffi_sig_t *sig) {
  memset(sig->val_types, CVAL_TYPE_NONE, MJS_CB_SIGNATURE_MAX_SIZE);
}

MJS_PRIVATE int mjs_ffi_sig_set_val_type(ffi_sig_t *sig, int idx,
                                         cval_type_t type) {
  if (idx < MJS_CB_SIGNATURE_MAX_SIZE) {
    sig->val_types[idx] = type;
    return 1;
  } else {
    /* Index is too large */
    return 0;
  }
}

MJS_PRIVATE struct ffi_sig_stat mjs_ffi_sig_stat_get(struct mjs *mjs,
                                                     const ffi_sig_t *sig) {
  struct ffi_sig_stat ret;
  int i;

  memset(&ret, 0, sizeof(ret));
  ret.is_valid = 1;

  /* Make sure return type is fine */
  if (sig->val_types[0] != CVAL_TYPE_NONE &&
      sig->val_types[0] != CVAL_TYPE_INT &&
      sig->val_types[0] != CVAL_TYPE_DOUBLE) {
    mjs_prepend_errorf(mjs, MJS_TYPE_ERROR, "wrong return value type");
    ret.is_valid = 0;
    goto clean;
  }

  /* Handle argument types */
  for (i = 1; i < MJS_CB_SIGNATURE_MAX_SIZE; i++) {
    cval_type_t type = sig->val_types[i];
    switch (type) {
      case CVAL_TYPE_USERDATA:
        if (ret.userdata_idx != 0) {
          /* There must be exactly one userdata arg, but we have more */
          mjs_prepend_errorf(mjs, MJS_TYPE_ERROR,
                             "more than one userdata arg: #%d and #%d",
                             (ret.userdata_idx - 1), (i - 1));
          ret.is_valid = 0;
          goto clean;
        }
        ret.userdata_idx = i;
        break;
      case CVAL_TYPE_INT:
      case CVAL_TYPE_VOID_PTR:
      case CVAL_TYPE_CHAR_PTR:
        /* Do nothing */
        break;
      case CVAL_TYPE_DOUBLE:
        ret.args_double_cnt++;
        break;
      case CVAL_TYPE_NONE:
        /* No more arguments */
        goto args_over;
      default:
        ret.is_valid = 0;
        goto clean;
    }

    ret.args_cnt++;
  }
args_over:

  if (ret.userdata_idx == 0) {
    /* No userdata arg */
    mjs_prepend_errorf(mjs, MJS_TYPE_ERROR, "no userdata arg");
    ret.is_valid = 0;
    goto clean;
  }

clean:
  return ret;
}

MJS_PRIVATE int mjs_ffi_is_regular_word(cval_type_t type) {
  switch (type) {
    case CVAL_TYPE_INT:
      return 1;
    default:
      return 0;
  }
}

MJS_PRIVATE int mjs_ffi_is_regular_word_or_void(cval_type_t type) {
  return (type == CVAL_TYPE_NONE || mjs_ffi_is_regular_word(type));
}

#ifdef _WIN32
void *dlsym(void *handle, const char *name) {
  return GetProcAddress(GetModuleHandle(NULL), name);
}
#elif !defined(__unix__) && !defined(__APPLE__)
void *dlsym(void *handle, const char *name) {
  (void) handle;
  (void) name;
  return NULL;
}
#endif
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_gc.c"
#endif
/*
 * Copyright (c) 2014 Cesanta Software Limited
 * All rights reserved
 */

#include <stdio.h>
/* Amalgamated: #include "common/mbuf.h" */
/* Amalgamated: #include "mjs/src/mjs_core.h" */
/* Amalgamated: #include "mjs/src/mjs_gc.h" */
/* Amalgamated: #include "mjs/src/mjs_internal.h" */
/* Amalgamated: #include "mjs/src/mjs_object.h" */
/* Amalgamated: #include "mjs/src/mjs_primitive.h" */
/* Amalgamated: #include "mjs/src/mjs_string.h" */
/* Amalgamated: #include "mjs/src/mjs_varint.h" */
/* Amalgamated: #include "mjs/src/mjs_ffi.h" */

/*
 * Macros for marking reachable things: use bit 0.
 */
#define MARK(p) (((struct gc_cell *) (p))->head.word |= 1)
#define UNMARK(p) (((struct gc_cell *) (p))->head.word &= ~1)
#define MARKED(p) (((struct gc_cell *) (p))->head.word & 1)

/*
 * Similar to `MARK()` / `UNMARK()` / `MARKED()`, but `.._FREE` counterparts
 * are intended to mark free cells (as opposed to used ones), so they use
 * bit 1.
 */
#define MARK_FREE(p) (((struct gc_cell *) (p))->head.word |= 2)
#define UNMARK_FREE(p) (((struct gc_cell *) (p))->head.word &= ~2)
#define MARKED_FREE(p) (((struct gc_cell *) (p))->head.word & 2)

/*
 * When each arena has that or less free cells, GC will be scheduled
 */
#define GC_ARENA_CELLS_RESERVE 2

void gc_mark_string(struct mjs *, mjs_val_t *);

static struct gc_block *gc_new_block(struct gc_arena *a, size_t size);
static void gc_free_block(struct gc_block *b);
static void gc_mark_mbuf_pt(struct mjs *mjs, const struct mbuf *mbuf);

MJS_PRIVATE struct mjs_object *new_object(struct mjs *mjs) {
  return (struct mjs_object *) gc_alloc_cell(mjs, &mjs->object_arena);
}

MJS_PRIVATE struct mjs_property *new_property(struct mjs *mjs) {
  return (struct mjs_property *) gc_alloc_cell(mjs, &mjs->property_arena);
}

/* Initializes a new arena. */
MJS_PRIVATE void gc_arena_init(struct gc_arena *a, size_t cell_size,
                               size_t initial_size, size_t size_increment) {
  assert(cell_size >= sizeof(uintptr_t));

  memset(a, 0, sizeof(*a));
  a->cell_size = cell_size;
  a->size_increment = size_increment;
  a->blocks = gc_new_block(a, initial_size);
}

MJS_PRIVATE void gc_arena_destroy(struct mjs *mjs, struct gc_arena *a) {
  struct gc_block *b;

  if (a->blocks != NULL) {
    gc_sweep(mjs, a, 0);
    for (b = a->blocks; b != NULL;) {
      struct gc_block *tmp;
      tmp = b;
      b = b->next;
      gc_free_block(tmp);
    }
  }
}

static void gc_free_block(struct gc_block *b) {
  free(b->base);
  free(b);
}

static struct gc_block *gc_new_block(struct gc_arena *a, size_t size) {
  struct gc_cell *cur;
  struct gc_block *b;

  b = (struct gc_block *) calloc(1, sizeof(*b));
  if (b == NULL) abort();

  b->size = size;
  b->base = (struct gc_cell *) calloc(a->cell_size, b->size);
  if (b->base == NULL) abort();

  for (cur = GC_CELL_OP(a, b->base, +, 0);
       cur < GC_CELL_OP(a, b->base, +, b->size);
       cur = GC_CELL_OP(a, cur, +, 1)) {
    cur->head.link = a->free;
    a->free = cur;
  }

  return b;
}

/*
 * Returns whether the given arena has GC_ARENA_CELLS_RESERVE or less free
 * cells
 */
static int gc_arena_is_gc_needed(struct gc_arena *a) {
  struct gc_cell *r = a->free;
  int i;

  for (i = 0; i <= GC_ARENA_CELLS_RESERVE; i++, r = r->head.link) {
    if (r == NULL) {
      return 1;
    }
  }

  return 0;
}

MJS_PRIVATE int gc_strings_is_gc_needed(struct mjs *mjs) {
  struct mbuf *m = &mjs->owned_strings;
  return (double) m->len / (double) m->size > 0.9;
}

MJS_PRIVATE void *gc_alloc_cell(struct mjs *mjs, struct gc_arena *a) {
  struct gc_cell *r;

  if (a->free == NULL) {
    struct gc_block *b = gc_new_block(a, a->size_increment);
    b->next = a->blocks;
    a->blocks = b;
  }
  r = a->free;

  UNMARK(r);

  a->free = r->head.link;

  /* Schedule GC if needed */
  if (gc_arena_is_gc_needed(a)) {
    mjs->need_gc = 1;
  }

  /*
   * TODO(mkm): minor opt possible since most of the fields
   * are overwritten downstream, but not worth the yak shave time
   * when fields are added to GC-able structures */
  memset(r, 0, a->cell_size);
  return (void *) r;
}

/*
 * Scans the arena and add all unmarked cells to the free list.
 *
 * Empty blocks get deallocated. The head of the free list will contais cells
 * from the last (oldest) block. Cells will thus be allocated in block order.
 */
void gc_sweep(struct mjs *mjs, struct gc_arena *a, size_t start) {
  struct gc_block *b;
  struct gc_cell *cur;
  struct gc_block **prevp = &a->blocks;

  /*
   * Before we sweep, we should mark all free cells in a way that is
   * distinguishable from marked used cells.
   */
  {
    struct gc_cell *next;
    for (cur = a->free; cur != NULL; cur = next) {
      next = cur->head.link;
      MARK_FREE(cur);
    }
  }

  /*
   * We'll rebuild the whole `free` list, so initially we just reset it
   */
  a->free = NULL;

  for (b = a->blocks; b != NULL;) {
    size_t freed_in_block = 0;
    /*
     * if it turns out that this block is 100% garbage
     * we can release the whole block, but the addition
     * of it's cells to the free list has to be undone.
     */
    struct gc_cell *prev_free = a->free;

    for (cur = GC_CELL_OP(a, b->base, +, start);
         cur < GC_CELL_OP(a, b->base, +, b->size);
         cur = GC_CELL_OP(a, cur, +, 1)) {
      if (MARKED(cur)) {
        /* The cell is used and marked  */
        UNMARK(cur);
      } else {
        /*
         * The cell is either:
         * - free
         * - garbage that's about to be freed
         */

        if (MARKED_FREE(cur)) {
          /* The cell is free, so, just unmark it */
          UNMARK_FREE(cur);
        } else {
          /*
           * The cell is used and should be freed: call the destructor and
           * reset the memory
           */
          if (a->destructor != NULL) {
            a->destructor(mjs, cur);
          }
          memset(cur, 0, a->cell_size);
        }

        /* Add this cell to the `free` list */
        cur->head.link = a->free;
        a->free = cur;
        freed_in_block++;
      }
    }

    /*
     * don't free the initial block, which is at the tail
     * because it has a special size aimed at reducing waste
     * and simplifying initial startup. TODO(mkm): improve
     * */
    if (b->next != NULL && freed_in_block == b->size) {
      *prevp = b->next;
      gc_free_block(b);
      b = *prevp;
      a->free = prev_free;
    } else {
      prevp = &b->next;
      b = b->next;
    }
  }
}

MJS_PRIVATE void gc_mark(struct mjs *mjs, mjs_val_t v) {
  struct mjs_object *obj_base;
  struct mjs_property *prop;
  struct mjs_property *next;

  if (!mjs_is_object(v)) {
    return;
  }
  obj_base = get_object_struct(v);

  /*
   * we treat all object like things like objects but they might be functions,
   * gc_gheck_val checks the appropriate arena per actual value type.
   */
  if (!gc_check_val(mjs, v)) {
    abort();
  }

  if (MARKED(obj_base)) return;

  /* mark object itself, and its properties */
  for ((prop = obj_base->properties), MARK(obj_base); prop != NULL;
       prop = next) {
    if (!gc_check_ptr(&mjs->property_arena, prop)) {
      abort();
    }

    gc_mark_string(mjs, &prop->value);
    gc_mark_string(mjs, &prop->name);
    gc_mark(mjs, prop->value);

    next = prop->next;
    MARK(prop);
  }

  /* mark object's prototype */
  /*
   * We dropped support for object prototypes in MJS.
   * If we ever bring it back, don't forget to mark it
   */
  /* gc_mark(mjs, mjs_get_proto(mjs, v)); */
}

MJS_PRIVATE uint64_t gc_string_mjs_val_to_offset(mjs_val_t v) {
  return (((uint64_t)(uintptr_t) get_ptr(v)) & ~MJS_TAG_MASK);
}

MJS_PRIVATE mjs_val_t gc_string_val_from_offset(uint64_t s) {
  return s | MJS_TAG_STRING_O;
}

/* Mark a string value */
void gc_mark_string(struct mjs *mjs, mjs_val_t *v) {
  mjs_val_t h, tmp = 0;
  char *s;

  /* clang-format off */

  /*
   * If a value points to an unmarked string we shall:
   *  1. save the first 6 bytes of the string
   *     since we need to be able to distinguish real values from
   *     the saved first 6 bytes of the string, we need to tag the chunk
   *     as MJS_TAG_STRING_C
   *  2. encode value's address (v) into the first 6 bytes of the string.
   *  3. put the saved 8 bytes (tag + chunk) back into the value.
   *  4. mark the string by putting '\1' in the NUL terminator of the previous
   *     string chunk.
   *
   * If a value points to an already marked string we shall:
   *     (0, <6 bytes of a pointer to a mjs_val_t>), hence we have to skip
   *     the first byte. We tag the value pointer as a MJS_TAG_FOREIGN
   *     so that it won't be followed during recursive mark.
   *
   *  ... the rest is the same
   *
   *  Note: 64-bit pointers can be represented with 48-bits
   */

  /* clang-format on */

  if ((*v & MJS_TAG_MASK) != MJS_TAG_STRING_O) {
    return;
  }

  s = mjs->owned_strings.buf + gc_string_mjs_val_to_offset(*v);
  assert(s < mjs->owned_strings.buf + mjs->owned_strings.len);
  if (s[-1] == '\0') {
    memcpy(&tmp, s, sizeof(tmp) - 2);
    tmp |= MJS_TAG_STRING_C;
  } else {
    memcpy(&tmp, s, sizeof(tmp) - 2);
    tmp |= MJS_TAG_FOREIGN;
  }

  h = (mjs_val_t)(uintptr_t) v;
  s[-1] = 1;
  memcpy(s, &h, sizeof(h) - 2);
  memcpy(v, &tmp, sizeof(tmp));
}

void gc_compact_strings(struct mjs *mjs) {
  char *p = mjs->owned_strings.buf + 1;
  uint64_t h, next, head = 1;
  int len, llen;

  while (p < mjs->owned_strings.buf + mjs->owned_strings.len) {
    if (p[-1] == '\1') {
      /* relocate and update ptrs */
      h = 0;
      memcpy(&h, p, sizeof(h) - 2);

      /*
       * relocate pointers until we find the tail.
       * The tail is marked with MJS_TAG_STRING_C,
       * while mjs_val_t link pointers are tagged with MJS_TAG_FOREIGN
       */
      for (; (h & MJS_TAG_MASK) != MJS_TAG_STRING_C; h = next) {
        h &= ~MJS_TAG_MASK;
        memcpy(&next, (char *) (uintptr_t) h, sizeof(h));

        *(mjs_val_t *) (uintptr_t) h = gc_string_val_from_offset(head);
      }
      h &= ~MJS_TAG_MASK;

      /*
       * the tail contains the first 6 bytes we stole from
       * the actual string.
       */
      len = varint_decode((unsigned char *) &h, &llen);
      len += llen + 1;

      /*
       * restore the saved 6 bytes
       * TODO(mkm): think about endianness
       */
      memcpy(p, &h, sizeof(h) - 2);

      /*
       * and relocate the string data by packing it to the left.
       */
      memmove(mjs->owned_strings.buf + head, p, len);
      mjs->owned_strings.buf[head - 1] = 0x0;
      p += len;
      head += len;
    } else {
      len = varint_decode((unsigned char *) p, &llen);
      len += llen + 1;

      p += len;
    }
  }

  mjs->owned_strings.len = head;
}

MJS_PRIVATE int maybe_gc(struct mjs *mjs) {
  if (!mjs->inhibit_gc) {
    mjs_gc(mjs, 0);
    return 1;
  }
  return 0;
}

/*
 * mark an array of `mjs_val_t` values (*not pointers* to them)
 */
static void gc_mark_val_array(struct mjs *mjs, mjs_val_t *vals, size_t len) {
  mjs_val_t *vp;
  for (vp = vals; vp < vals + len; vp++) {
    gc_mark(mjs, *vp);
    gc_mark_string(mjs, vp);
  }
}

/*
 * mark an mbuf containing *pointers* to `mjs_val_t` values
 */
static void gc_mark_mbuf_pt(struct mjs *mjs, const struct mbuf *mbuf) {
  mjs_val_t **vp;
  for (vp = (mjs_val_t **) mbuf->buf; (char *) vp < mbuf->buf + mbuf->len;
       vp++) {
    gc_mark(mjs, **vp);
    gc_mark_string(mjs, *vp);
  }
}

/*
 * mark an mbuf containing `mjs_val_t` values (*not pointers* to them)
 */
static void gc_mark_mbuf_val(struct mjs *mjs, const struct mbuf *mbuf) {
  gc_mark_val_array(mjs, (mjs_val_t *) mbuf->buf,
                    mbuf->len / sizeof(mjs_val_t));
}

static void gc_mark_ffi_cbargs_list(struct mjs *mjs, ffi_cb_args_t *cbargs) {
  for (; cbargs != NULL; cbargs = cbargs->next) {
    gc_mark(mjs, cbargs->func);
    gc_mark_string(mjs, &cbargs->func);
    gc_mark(mjs, cbargs->userdata);
    gc_mark_string(mjs, &cbargs->userdata);
  }
}

/* Perform garbage collection */
void mjs_gc(struct mjs *mjs, int full) {
  gc_mark_val_array(mjs, (mjs_val_t *) &mjs->vals,
                    sizeof(mjs->vals) / sizeof(mjs_val_t));

  gc_mark_mbuf_pt(mjs, &mjs->owned_values);
  gc_mark_mbuf_val(mjs, &mjs->scopes);
  gc_mark_mbuf_val(mjs, &mjs->stack);
  gc_mark_mbuf_val(mjs, &mjs->call_stack);

  gc_mark_ffi_cbargs_list(mjs, mjs->ffi_cb_args);

  gc_compact_strings(mjs);

  gc_sweep(mjs, &mjs->object_arena, 0);
  gc_sweep(mjs, &mjs->property_arena, 0);

  if (full) {
    /*
     * In case of full GC, we also resize strings buffer, but we still leave
     * some extra space (at most, `_MJS_STRING_BUF_RESERVE`) in order to avoid
     * frequent reallocations
     */
    size_t trimmed_size = mjs->owned_strings.len + _MJS_STRING_BUF_RESERVE;
    if (trimmed_size < mjs->owned_strings.size) {
      mbuf_resize(&mjs->owned_strings, trimmed_size);
    }
  }
}

MJS_PRIVATE int gc_check_val(struct mjs *mjs, mjs_val_t v) {
  if (mjs_is_object(v)) {
    return gc_check_ptr(&mjs->object_arena, get_object_struct(v));
  }
  return 1;
}

MJS_PRIVATE int gc_check_ptr(const struct gc_arena *a, const void *ptr) {
  const struct gc_cell *p = (const struct gc_cell *) ptr;
  struct gc_block *b;
  for (b = a->blocks; b != NULL; b = b->next) {
    if (p >= b->base && p < GC_CELL_OP(a, b->base, +, b->size)) {
      return 1;
    }
  }
  return 0;
}
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_json.c"
#endif
/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

/* Amalgamated: #include "common/str_util.h" */
/* Amalgamated: #include "frozen/frozen.h" */
/* Amalgamated: #include "mjs/src/mjs_array.h" */
/* Amalgamated: #include "mjs/src/mjs_internal.h" */
/* Amalgamated: #include "mjs/src/mjs_conversion.h" */
/* Amalgamated: #include "mjs/src/mjs_core.h" */
/* Amalgamated: #include "mjs/src/mjs_object.h" */
/* Amalgamated: #include "mjs/src/mjs_primitive.h" */
/* Amalgamated: #include "mjs/src/mjs_string.h" */

#define BUF_LEFT(size, used) (((size_t)(used) < (size)) ? ((size) - (used)) : 0)

/*
 * Returns whether the value of given type should be skipped when generating
 * JSON output
 *
 * So far it always returns 0, but we might add some logic later, if we
 * implement some non-jsonnable objects
 */
static int should_skip_for_json(enum mjs_type type) {
  int ret;
  switch (type) {
    /* All permitted values */
    case MJS_TYPE_NULL:
    case MJS_TYPE_BOOLEAN:
    case MJS_TYPE_NUMBER:
    case MJS_TYPE_STRING:
    case MJS_TYPE_OBJECT_GENERIC:
    case MJS_TYPE_OBJECT_ARRAY:
      ret = 0;
      break;
    default:
      ret = 1;
      break;
  }
  return ret;
}

static const char *hex_digits = "0123456789abcdef";
static char *append_hex(char *buf, char *limit, uint8_t c) {
  if (buf < limit) *buf++ = 'u';
  if (buf < limit) *buf++ = '0';
  if (buf < limit) *buf++ = '0';
  if (buf < limit) *buf++ = hex_digits[(int) ((c >> 4) % 0xf)];
  if (buf < limit) *buf++ = hex_digits[(int) (c & 0xf)];
  return buf;
}

/*
 * Appends quoted s to buf. Any double quote contained in s will be escaped.
 * Returns the number of characters that would have been added,
 * like snprintf.
 * If size is zero it doesn't output anything but keeps counting.
 */
static int snquote(char *buf, size_t size, const char *s, size_t len) {
  char *limit = buf + size - 1;
  const char *end;
  /*
   * String single character escape sequence:
   * http://www.ecma-international.org/ecma-262/6.0/index.html#table-34
   *
   * 0x8 -> \b
   * 0x9 -> \t
   * 0xa -> \n
   * 0xb -> \v
   * 0xc -> \f
   * 0xd -> \r
   */
  const char *specials = "btnvfr";
  size_t i = 0;

  i++;
  if (buf < limit) *buf++ = '"';

  for (end = s + len; s < end; s++) {
    if (*s == '"' || *s == '\\') {
      i++;
      if (buf < limit) *buf++ = '\\';
    } else if (*s >= '\b' && *s <= '\r') {
      i += 2;
      if (buf < limit) *buf++ = '\\';
      if (buf < limit) *buf++ = specials[*s - '\b'];
      continue;
    } else if ((unsigned char) *s < '\b' || (*s > '\r' && *s < ' ')) {
      i += 6 /* \uXXXX */;
      if (buf < limit) *buf++ = '\\';
      buf = append_hex(buf, limit, (uint8_t) *s);
      continue;
    }
    i++;
    if (buf < limit) *buf++ = *s;
  }

  i++;
  if (buf < limit) *buf++ = '"';

  if (size != 0) {
    *buf = '\0';
  }
  return i;
}

MJS_PRIVATE mjs_err_t to_json_or_debug(struct mjs *mjs, mjs_val_t v, char *buf,
                                       size_t size, size_t *res_len,
                                       uint8_t is_debug) {
  mjs_val_t el;
  char *vp;
  mjs_err_t rcode = MJS_OK;
  size_t len = 0;
  /*
   * TODO(dfrank) : also push all `mjs_val_t`s that are declared below
   */

  if (size > 0) *buf = '\0';

  if (!is_debug && should_skip_for_json(mjs_get_type(mjs, v))) {
    goto clean;
  }

  for (vp = mjs->json_visited_stack.buf;
       vp < mjs->json_visited_stack.buf + mjs->json_visited_stack.len;
       vp += sizeof(mjs_val_t)) {
    if (*(mjs_val_t *) vp == v) {
      strncpy(buf, "[Circular]", size);
      len = 10;
      goto clean;
    }
  }

  switch (mjs_get_type(mjs, v)) {
    case MJS_TYPE_NULL:
    case MJS_TYPE_BOOLEAN:
    case MJS_TYPE_NUMBER:
    case MJS_TYPE_UNDEFINED:
    case MJS_TYPE_FOREIGN:
      /* For those types, regular `mjs_to_string()` works */
      {
        /* TODO: refactor: mjs_to_string allocates memory every time */
        char *p = NULL;
        int need_free = 0;
        rcode = mjs_to_string(mjs, &v, &p, &len, &need_free);
        c_snprintf(buf, size, "%.*s", (int) len, p);
        if (need_free) {
          free(p);
        }
      }
      goto clean;

    case MJS_TYPE_STRING: {
      /*
       * For strings we can't just use `primitive_to_str()`, because we need
       * quoted value
       */
      size_t n;
      const char *str = mjs_get_string(mjs, &v, &n);
      len = snquote(buf, size, str, n);
      goto clean;
    }

    case MJS_TYPE_OBJECT_GENERIC: {
      char *b = buf;
      struct mjs_property *prop = NULL;
      struct mjs_object *o = NULL;

      mbuf_append(&mjs->json_visited_stack, (char *) &v, sizeof(v));
      b += c_snprintf(b, BUF_LEFT(size, b - buf), "{");
      o = get_object_struct(v);
      for (prop = o->properties; prop != NULL; prop = prop->next) {
        size_t n;
        const char *s;
        if (!is_debug && should_skip_for_json(mjs_get_type(mjs, prop->value))) {
          continue;
        }
        if (b - buf != 1) { /* Not the first property to be printed */
          b += c_snprintf(b, BUF_LEFT(size, b - buf), ",");
        }
        s = mjs_get_string(mjs, &prop->name, &n);
        b += c_snprintf(b, BUF_LEFT(size, b - buf), "\"%.*s\":", (int) n, s);
        {
          size_t tmp = 0;
          rcode = to_json_or_debug(mjs, prop->value, b, BUF_LEFT(size, b - buf),
                                   &tmp, is_debug);
          if (rcode != MJS_OK) {
            goto clean_iter;
          }
          b += tmp;
        }
      }

      b += c_snprintf(b, BUF_LEFT(size, b - buf), "}");
      mjs->json_visited_stack.len -= sizeof(v);

    clean_iter:
      len = b - buf;
      goto clean;
    }
    case MJS_TYPE_OBJECT_ARRAY: {
      int has;
      char *b = buf;
      size_t i, alen = mjs_array_length(mjs, v);
      mbuf_append(&mjs->json_visited_stack, (char *) &v, sizeof(v));
      b += c_snprintf(b, BUF_LEFT(size, b - buf), "[");
      for (i = 0; i < alen; i++) {
        el = mjs_array_get2(mjs, v, i, &has);
        if (has) {
          size_t tmp = 0;
          if (!is_debug && should_skip_for_json(mjs_get_type(mjs, el))) {
            b += c_snprintf(b, BUF_LEFT(size, b - buf), "null");
          } else {
            rcode = to_json_or_debug(mjs, el, b, BUF_LEFT(size, b - buf), &tmp,
                                     is_debug);
            if (rcode != MJS_OK) {
              goto clean;
            }
          }
          b += tmp;
        } else {
          b += c_snprintf(b, BUF_LEFT(size, b - buf), "null");
        }
        if (i != alen - 1) {
          b += c_snprintf(b, BUF_LEFT(size, b - buf), ",");
        }
      }
      b += c_snprintf(b, BUF_LEFT(size, b - buf), "]");
      mjs->json_visited_stack.len -= sizeof(v);
      len = b - buf;
      goto clean;
    }

    case MJS_TYPES_CNT:
      abort();
  }

  abort();

  len = 0; /* for compilers that don't know about abort() */
  goto clean;

clean:
  if (rcode != MJS_OK) {
    len = 0;
  }
  if (res_len != NULL) {
    *res_len = len;
  }
  return rcode;
}

MJS_PRIVATE mjs_err_t mjs_json_stringify(struct mjs *mjs, mjs_val_t v,
                                         char *buf, size_t size, char **res) {
  mjs_err_t rcode = MJS_OK;
  char *p = buf;
  size_t len;

  to_json_or_debug(mjs, v, buf, size, &len, 0);

  if (len >= size) {
    /* Buffer is not large enough. Allocate a bigger one */
    p = (char *) malloc(len + 1);
    rcode = mjs_json_stringify(mjs, v, p, len + 1, res);
    assert(*res == p);
    goto clean;
  } else {
    *res = p;
    goto clean;
  }

clean:
  /*
   * If we're going to return an error, and we allocated a buffer, then free
   * it. Otherwise, caller should free it.
   */
  if (rcode != MJS_OK && p != buf) {
    free(p);
  }
  return rcode;
}

/*
 * JSON parsing frame: a separate frame is allocated for each nested
 * object/array during parsing
 */
struct json_parse_frame {
  mjs_val_t val;
  struct json_parse_frame *up;
};

/*
 * Context for JSON parsing by means of json_walk()
 */
struct json_parse_ctx {
  struct mjs *mjs;
  mjs_val_t result;
  struct json_parse_frame *frame;
};

/* Allocate JSON parse frame */
static struct json_parse_frame *alloc_json_frame(struct json_parse_ctx *ctx,
                                                 mjs_val_t v) {
  struct json_parse_frame *frame =
      (struct json_parse_frame *) calloc(sizeof(struct json_parse_frame), 1);
  frame->val = v;
  mjs_own(ctx->mjs, &frame->val);
  return frame;
}

/* Free JSON parse frame, return the previous one (which may be NULL) */
static struct json_parse_frame *free_json_frame(
    struct json_parse_ctx *ctx, struct json_parse_frame *frame) {
  struct json_parse_frame *up = frame->up;
  mjs_disown(ctx->mjs, &frame->val);
  free(frame);
  return up;
}

/* Callback for json_walk() */
static void frozen_cb(void *data, const char *name, size_t name_len,
                      const char *path, const struct json_token *token) {
  struct json_parse_ctx *ctx = (struct json_parse_ctx *) data;
  mjs_val_t v = MJS_UNDEFINED;

  (void) path;

  mjs_own(ctx->mjs, &v);

  switch (token->type) {
    case JSON_TYPE_STRING:
      v = mjs_mk_string(ctx->mjs, token->ptr, token->len, 1 /* copy */);
      break;
    case JSON_TYPE_NUMBER:
      v = mjs_mk_number(ctx->mjs, strtod(token->ptr, NULL));
      break;
    case JSON_TYPE_TRUE:
      v = mjs_mk_boolean(ctx->mjs, 1);
      break;
    case JSON_TYPE_FALSE:
      v = mjs_mk_boolean(ctx->mjs, 0);
      break;
    case JSON_TYPE_NULL:
      v = MJS_NULL;
      break;
    case JSON_TYPE_OBJECT_START:
      v = mjs_mk_object(ctx->mjs);
      break;
    case JSON_TYPE_ARRAY_START:
      v = mjs_mk_array(ctx->mjs);
      break;

    case JSON_TYPE_OBJECT_END:
    case JSON_TYPE_ARRAY_END: {
      /* Object or array has finished: deallocate its frame */
      ctx->frame = free_json_frame(ctx, ctx->frame);
    } break;

    default:
      LOG(LL_ERROR, ("Wrong token type %d\n", token->type));
      break;
  }

  if (!mjs_is_undefined(v)) {
    if (name != NULL && name_len != 0) {
      /* Need to define a property on the current object/array */
      if (mjs_is_object(ctx->frame->val)) {
        mjs_set(ctx->mjs, ctx->frame->val, name, name_len, v);
      } else if (mjs_is_array(ctx->frame->val)) {
        /*
         * TODO(dfrank): consult name_len. Currently it's not a problem due to
         * the implementation details of frozen, but it might change
         */
        int idx = (int) strtod(name, NULL);
        mjs_array_set(ctx->mjs, ctx->frame->val, idx, v);
      } else {
        LOG(LL_ERROR, ("Current value is neither object nor array\n"));
      }
    } else {
      /* This is a root value */
      assert(ctx->frame == NULL);

      /*
       * This value will also be the overall result of JSON parsing
       * (it's already owned by the `mjs_alt_json_parse()`)
       */
      ctx->result = v;
    }

    if (token->type == JSON_TYPE_OBJECT_START ||
        token->type == JSON_TYPE_ARRAY_START) {
      /* New object or array has just started, so we need to allocate a frame
       * for it */
      struct json_parse_frame *new_frame = alloc_json_frame(ctx, v);
      new_frame->up = ctx->frame;
      ctx->frame = new_frame;
    }
  }

  mjs_disown(ctx->mjs, &v);
}

MJS_PRIVATE mjs_err_t
mjs_json_parse(struct mjs *mjs, const char *str, size_t len, mjs_val_t *res) {
  struct json_parse_ctx *ctx =
      (struct json_parse_ctx *) calloc(sizeof(struct json_parse_ctx), 1);
  int json_res;
  enum mjs_err rcode = MJS_OK;

  ctx->mjs = mjs;
  ctx->result = MJS_UNDEFINED;
  ctx->frame = NULL;

  mjs_own(mjs, &ctx->result);

  json_res = json_walk(str, len, frozen_cb, ctx);

  if (json_res >= 0) {
    /* Expression is parsed successfully */
    *res = ctx->result;

    /* There should be no allocated frames */
    assert(ctx->frame == NULL);
  } else {
    /* There was an error during parsing */
    rcode = MJS_TYPE_ERROR;
    mjs_prepend_errorf(mjs, rcode, "invalid JSON string");

    /* There might be some allocated frames in case of malformed JSON */
    while (ctx->frame != NULL) {
      ctx->frame = free_json_frame(ctx, ctx->frame);
    }
  }

  mjs_disown(mjs, &ctx->result);
  free(ctx);

  return rcode;
}

MJS_PRIVATE void mjs_op_json_stringify(struct mjs *mjs) {
  mjs_val_t ret = MJS_UNDEFINED;
  mjs_val_t val = mjs_arg(mjs, 0);

  if (mjs_nargs(mjs) < 1) {
    mjs_prepend_errorf(mjs, MJS_TYPE_ERROR, "missing a value to stringify");
  } else {
    char *p = NULL;
    if (mjs_json_stringify(mjs, val, NULL, 0, &p) == MJS_OK) {
      ret = mjs_mk_string(mjs, p, ~0, 1 /* copy */);
      free(p);
    }
  }

  mjs_return(mjs, ret);
}

MJS_PRIVATE void mjs_op_json_parse(struct mjs *mjs) {
  mjs_val_t ret = MJS_UNDEFINED;
  mjs_val_t arg0 = mjs_arg(mjs, 0);

  if (mjs_is_string(arg0)) {
    size_t len;
    const char *str = mjs_get_string(mjs, &arg0, &len);
    mjs_json_parse(mjs, str, len, &ret);
  } else {
    mjs_prepend_errorf(mjs, MJS_TYPE_ERROR, "string argument required");
  }

  mjs_return(mjs, ret);
}
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_main.c"
#endif
/*
 * Copyright (c) 2014-2017 Cesanta Software Limited
 * All rights reserved
 */

#ifdef MJS_MAIN

// #include <dlfcn.h>

/* Amalgamated: #include "mjs/src/mjs_core.h" */
/* Amalgamated: #include "mjs/src/mjs_exec.h" */
/* Amalgamated: #include "mjs/src/mjs_internal.h" */
/* Amalgamated: #include "mjs/src/mjs_primitive.h" */
/* Amalgamated: #include "mjs/src/mjs_util.h" */

int main(int argc, char *argv[]) {
  struct mjs *mjs = mjs_create();
  mjs_val_t res = MJS_UNDEFINED;
  mjs_err_t err = MJS_OK;
  int i;

  for (i = 1; i < argc && argv[i][0] == '-'; i++) {
    if (strcmp(argv[i], "-l") == 0 && i + 1 < argc) {
      cs_log_set_level(atoi(argv[++i]));
    } else if (strcmp(argv[i], "-e") == 0 && i + 1 < argc) {
      err = mjs_exec(mjs, argv[++i], &res);
    } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
      printf("mJS (c) Cesanta, built: " __DATE__ "\n");
      printf("Usage:\n  ");
      printf("%s [-l debug_level] [-e expression] js_file ...\n", argv[0]);
      return EXIT_SUCCESS;
    } else {
      fprintf(stderr, "Unknown flag: [%s]\n", argv[i]);
      return EXIT_FAILURE;
    }
  }
  for (; i < argc; i++) {
    mjs_exec_file(mjs, argv[i], &res);
  }

  if (err == MJS_OK) {
    mjs_fprintf(res, mjs, stdout);
    putchar('\n');
  } else {
    printf("Error: %d: %s\n", err, mjs_strerror(mjs, mjs->error));
  }
  mjs_destroy(mjs);

  return EXIT_SUCCESS;
}
#endif
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_object.c"
#endif
/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

/* Amalgamated: #include "mjs/src/mjs_conversion.h" */
/* Amalgamated: #include "mjs/src/mjs_core.h" */
/* Amalgamated: #include "mjs/src/mjs_internal.h" */
/* Amalgamated: #include "mjs/src/mjs_object.h" */
/* Amalgamated: #include "mjs/src/mjs_primitive.h" */
/* Amalgamated: #include "mjs/src/mjs_string.h" */

MJS_PRIVATE mjs_val_t mjs_object_to_value(struct mjs_object *o) {
  if (o == NULL) {
    return MJS_NULL;
  } else {
    return pointer_to_value(o) | MJS_TAG_OBJECT;
  }
}

MJS_PRIVATE struct mjs_object *get_object_struct(mjs_val_t v) {
  struct mjs_object *ret = NULL;
  if (mjs_is_null(v)) {
    ret = NULL;
  } else {
    assert(mjs_is_object(v));
    ret = (struct mjs_object *) get_ptr(v);
  }
  return ret;
}

mjs_val_t mjs_mk_object(struct mjs *mjs) {
  struct mjs_object *o = new_object(mjs);
  if (o == NULL) {
    return MJS_NULL;
  }
  (void) mjs;
  o->properties = NULL;
  return mjs_object_to_value(o);
}

int mjs_is_object(mjs_val_t v) {
  return (v & MJS_TAG_MASK) == MJS_TAG_OBJECT ||
         (v & MJS_TAG_MASK) == MJS_TAG_ARRAY;
}

MJS_PRIVATE struct mjs_property *mjs_get_own_property(struct mjs *mjs,
                                                      mjs_val_t obj,
                                                      const char *name,
                                                      size_t len) {
  struct mjs_property *p;
  struct mjs_object *o;

  if (!mjs_is_object(obj)) {
    return NULL;
  }

  o = get_object_struct(obj);

  if (len <= 5) {
    mjs_val_t ss = mjs_mk_string(mjs, name, len, 1);
    for (p = o->properties; p != NULL; p = p->next) {
      if (p->name == ss) return p;
    }
  } else {
    for (p = o->properties; p != NULL; p = p->next) {
      if (mjs_strcmp(mjs, &p->name, name, len) == 0) return p;
    }
    return p;
  }

  return NULL;
}

MJS_PRIVATE struct mjs_property *mjs_get_own_property_v(struct mjs *mjs,
                                                        mjs_val_t obj,
                                                        mjs_val_t key) {
  size_t n;
  char *s = NULL;
  int need_free = 0;
  struct mjs_property *p = NULL;
  mjs_err_t err = mjs_to_string(mjs, &key, &s, &n, &need_free);
  if (err == MJS_OK) {
    p = mjs_get_own_property(mjs, obj, s, n);
  }
  if (need_free) free(s);
  return p;
}

MJS_PRIVATE struct mjs_property *mjs_mk_property(struct mjs *mjs,
                                                 mjs_val_t name,
                                                 mjs_val_t value) {
  struct mjs_property *p = new_property(mjs);
  p->next = NULL;
  p->name = name;
  p->value = value;
  return p;
}

mjs_val_t mjs_get(struct mjs *mjs, mjs_val_t obj, const char *name,
                  size_t name_len) {
  struct mjs_property *p;

  if (name_len == (size_t) ~0) {
    name_len = strlen(name);
  }

  p = mjs_get_own_property(mjs, obj, name, name_len);
  if (p == NULL) {
    return MJS_UNDEFINED;
  } else {
    return p->value;
  }
}

mjs_val_t mjs_get_v(struct mjs *mjs, mjs_val_t obj, mjs_val_t name) {
  size_t n;
  char *s = NULL;
  int need_free = 0;
  mjs_val_t ret = MJS_UNDEFINED;

  mjs_err_t err = mjs_to_string(mjs, &name, &s, &n, &need_free);

  if (err == MJS_OK) {
    /* Successfully converted name value to string: get the property */
    ret = mjs_get(mjs, obj, s, n);
  }

  if (need_free) {
    free(s);
    s = NULL;
  }
  return ret;
}

mjs_val_t mjs_get_v_proto(struct mjs *mjs, mjs_val_t obj, mjs_val_t key) {
  struct mjs_property *p;
  mjs_val_t pn = mjs_mk_string(mjs, MJS_PROTO_PROP_NAME, ~0, 1);
  if ((p = mjs_get_own_property_v(mjs, obj, key)) != NULL) return p->value;
  if ((p = mjs_get_own_property_v(mjs, obj, pn)) == NULL) return MJS_UNDEFINED;
  return mjs_get_v_proto(mjs, p->value, key);
}

mjs_err_t mjs_set(struct mjs *mjs, mjs_val_t obj, const char *name,
                  size_t name_len, mjs_val_t val) {
  struct mjs_property *p;

  if (name_len == (size_t) ~0) {
    name_len = strlen(name);
  }

  p = mjs_get_own_property(mjs, obj, name, name_len);
  if (p == NULL) {
    mjs_val_t namestr;
    struct mjs_object *o;
    if (!mjs_is_object(obj)) {
      return MJS_REFERENCE_ERROR;
    }

    namestr = mjs_mk_string(mjs, name, name_len, 1);
    p = mjs_mk_property(mjs, namestr, val);

    o = get_object_struct(obj);
    p->next = o->properties;
    o->properties = p;
  }

  p->value = val;
  return MJS_OK;
}

mjs_err_t mjs_set_v(struct mjs *mjs, mjs_val_t obj, mjs_val_t name,
                    mjs_val_t val) {
  size_t n;
  char *s = NULL;
  int need_free = 0;

  mjs_err_t err = mjs_to_string(mjs, &name, &s, &n, &need_free);

  if (err == MJS_OK) {
    /* Successfully converted name value to string: set the property */
    err = mjs_set(mjs, obj, s, n, val);
  }

  if (need_free) {
    free(s);
    s = NULL;
  }

  return err;
}

mjs_val_t mjs_next(struct mjs *mjs, mjs_val_t obj, mjs_val_t *iterator) {
  struct mjs_property *p = NULL;
  mjs_val_t key = MJS_UNDEFINED;

  if (*iterator == MJS_UNDEFINED) {
    struct mjs_object *o = get_object_struct(obj);
    p = o->properties;
  } else {
    p = ((struct mjs_property *) get_ptr(*iterator))->next;
  }

  if (p == NULL) {
    *iterator = MJS_UNDEFINED;
  } else {
    key = p->name;
    *iterator = mjs_mk_foreign(mjs, p);
  }

  return key;
}
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_parser.c"
#endif
/*
 * Copyright (c) 2017 Cesanta Software Limited
 * All rights reserved
 */

/* Amalgamated: #include "mjs/src/mjs_bcode.h" */
/* Amalgamated: #include "mjs/src/mjs_core.h" */
/* Amalgamated: #include "mjs/src/mjs_internal.h" */
/* Amalgamated: #include "mjs/src/mjs_parser.h" */
/* Amalgamated: #include "mjs/src/mjs_string.h" */
/* Amalgamated: #include "mjs/src/mjs_tok.h" */
/* Amalgamated: #include "mjs/src/mjs_varint.h" */

#ifndef MAX_TOKS_IN_EXPR
#define MAX_TOKS_IN_EXPR 40
#endif

#define FAIL_ERR(p, code)                                                  \
  do {                                                                     \
    p->mjs->error = code;                                                  \
    LOG(LL_DEBUG, ("ERROR line %d, [%.*s...]", __LINE__, 10, p->tok.ptr)); \
    return code;                                                           \
  } while (0)

#define pnext1(p)                            \
  do {                                       \
    LOG(LL_DEBUG, ("  PNEXT %d", __LINE__)); \
    pnext(p);                                \
  } while (0)

#define SYNTAX_ERROR(p) FAIL_ERR(p, MJS_SYNTAX_ERROR)
#undef EXPECT
#define EXPECT(p, t)       \
  if ((p)->tok.tok != (t)) \
    SYNTAX_ERROR(p);       \
  else                     \
    pnext1(p);

static mjs_err_t parse_statement(struct pstate *p);
static mjs_err_t parse_expr(struct pstate *p);

static int ptest(struct pstate *p) {
  struct pstate saved = *p;
  int tok = pnext(p);
  *p = saved;
  return tok;
}

static int s_unary_ops[] = {TOK_NOT, TOK_TILDA, TOK_PLUS_PLUS, TOK_MINUS_MINUS,
                            TOK_KEYWORD_TYPEOF, TOK_MINUS, TOK_PLUS, TOK_EOF};
static int s_comparison_ops[] = {TOK_LT, TOK_LE, TOK_GT, TOK_GE, TOK_EOF};
static int s_postfix_ops[] = {TOK_PLUS_PLUS, TOK_MINUS_MINUS, TOK_EOF};
static int s_equality_ops[] = {TOK_EQ, TOK_NE, TOK_EQ_EQ, TOK_NE_NE, TOK_EOF};
static int s_assign_ops[] = {
    TOK_ASSIGN,         TOK_PLUS_ASSIGN, TOK_MINUS_ASSIGN,  TOK_MUL_ASSIGN,
    TOK_DIV_ASSIGN,     TOK_REM_ASSIGN,  TOK_LSHIFT_ASSIGN, TOK_RSHIFT_ASSIGN,
    TOK_URSHIFT_ASSIGN, TOK_AND_ASSIGN,  TOK_XOR_ASSIGN,    TOK_OR_ASSIGN,
    TOK_EOF};

static int findtok(int *toks, int tok) {
  int i = 0;
  while (tok != toks[i] && toks[i] != TOK_EOF) i++;
  return toks[i];
}

static void emit_op(struct pstate *pstate, int tok) {
  assert(tok >= 0 && tok <= 255);
  emit_byte(pstate, OP_EXPR);
  emit_byte(pstate, tok);
}

// Intentionally left as macro rather than a function, to let the
// compiler to inline calls and mimimize runtime stack usage.
#define PARSE_LTR_BINOP(p, f1, f2, ops, prev_op)      \
  do {                                                \
    mjs_err_t res = MJS_OK;                           \
    if ((res = f1(p, TOK_EOF)) != MJS_OK) return res; \
    if (prev_op != TOK_EOF) emit_op(p, prev_op);      \
    if (findtok(ops, p->tok.tok) != TOK_EOF) {        \
      int op = p->tok.tok;                            \
      pnext1(p);                                      \
      if ((res = f2(p, op)) != MJS_OK) return res;    \
    }                                                 \
    return res;                                       \
  } while (0)

#define PARSE_RTL_BINOP(p, f1, f2, ops, prev_op)        \
  do {                                                  \
    mjs_err_t res = MJS_OK;                             \
    (void) prev_op;                                     \
    if ((res = f1(p, TOK_EOF)) != MJS_OK) return res;   \
    if (findtok(ops, p->tok.tok) != TOK_EOF) {          \
      int op = p->tok.tok;                              \
      pnext1(p);                                        \
      if ((res = f2(p, TOK_EOF)) != MJS_OK) return res; \
      emit_op(p, op);                                   \
    }                                                   \
    return res;                                         \
  } while (0)

static mjs_err_t parse_statement_list(struct pstate *p, int et) {
  mjs_err_t res = MJS_OK;
  int drop = 0;
  pnext1(p);
  while (res == MJS_OK && p->tok.tok != TOK_EOF && p->tok.tok != et) {
    if (drop) emit_byte(p, OP_DROP);
    res = parse_statement(p);
    drop = 1;
    while (p->tok.tok == TOK_SEMICOLON) pnext1(p);
  }
  return res;
}

static mjs_err_t parse_block(struct pstate *p, int mkscope) {
  mjs_err_t res = MJS_OK;
  LOG(LL_DEBUG, ("[%.*s]", 10, p->tok.ptr));
  if (mkscope) emit_byte(p, OP_NEW_SCOPE);
  res = parse_statement_list(p, TOK_CLOSE_CURLY);
  EXPECT(p, TOK_CLOSE_CURLY);
  if (mkscope) emit_byte(p, OP_DEL_SCOPE);
  return res;
}

static mjs_err_t parse_function(struct pstate *p) {
  struct mbuf *bcode = &p->mjs->bcode;
  size_t prologue, off;
  int arg_no = 0;
  int name_provided = 0;
  mjs_err_t res = MJS_OK;

  EXPECT(p, TOK_KEYWORD_FUNCTION);

  if (p->tok.tok == TOK_IDENT) {
    /* Function name was provided */
    struct tok tmp = p->tok;
    name_provided = 1;
    emit_byte(p, OP_PUSH_STR);
    emit_str(p, tmp.ptr, tmp.len);
    emit_byte(p, OP_PUSH_SCOPE);
    emit_byte(p, OP_CREATE);
    emit_byte(p, OP_PUSH_STR);
    emit_str(p, tmp.ptr, tmp.len);
    emit_byte(p, OP_FIND_SCOPE);
    pnext1(p);
  }

  off = mjs_bcode_size(bcode);

  emit_byte(p, OP_JMP);
  emit_byte(p, 0);

  prologue = mjs_bcode_size(bcode);

  EXPECT(p, TOK_OPEN_PAREN);
  emit_byte(p, OP_NEW_SCOPE);
  // Emit names of function arguments
  while (p->tok.tok != TOK_CLOSE_PAREN) {
    if (p->tok.tok != TOK_IDENT) SYNTAX_ERROR(p);
    emit_byte(p, OP_SET_ARG);
    emit_int(p, arg_no);
    arg_no++;
    emit_str(p, p->tok.ptr, p->tok.len);
    if (ptest(p) == TOK_COMMA) pnext1(p);
    pnext1(p);
  }
  EXPECT(p, TOK_CLOSE_PAREN);
  if ((res = parse_block(p, 0)) != MJS_OK) return res;
  emit_byte(p, OP_RETURN);
  mjs_bcode_mutate_byte(p->mjs, off + 1, mjs_bcode_size(bcode) - off);
  emit_byte(p, OP_PUSH_FUNC);
  emit_int(p, prologue);
  if (name_provided) {
    emit_op(p, TOK_ASSIGN);
  }

  return res;
}

static mjs_err_t parse_object_literal(struct pstate *p) {
  mjs_err_t res = MJS_OK;
  EXPECT(p, TOK_OPEN_CURLY);
  emit_byte(p, OP_PUSH_OBJ);
  while (p->tok.tok != TOK_CLOSE_CURLY) {
    if (p->tok.tok != TOK_IDENT && p->tok.tok != TOK_STR) SYNTAX_ERROR(p);
    emit_byte(p, OP_DUP);
    emit_byte(p, OP_PUSH_STR);
    emit_str(p, p->tok.ptr, p->tok.len);
    emit_byte(p, OP_SWAP);
    pnext1(p);
    EXPECT(p, TOK_COLON);
    if ((res = parse_expr(p)) != MJS_OK) return res;
    emit_op(p, TOK_ASSIGN);
    emit_byte(p, OP_DROP);
    if (p->tok.tok == TOK_COMMA) pnext1(p);
  }
  return res;
}

static mjs_err_t parse_array_literal(struct pstate *p) {
  mjs_err_t res = MJS_OK;
  EXPECT(p, TOK_OPEN_BRACKET);
  emit_byte(p, OP_PUSH_ARRAY);
  while (p->tok.tok != TOK_CLOSE_BRACKET) {
    emit_byte(p, OP_DUP);
    if ((res = parse_expr(p)) != MJS_OK) return res;
    emit_byte(p, OP_APPEND);
    if (p->tok.tok == TOK_COMMA) pnext1(p);
  }
  return res;
}

static enum mjs_err parse_literal(struct pstate *p, const struct tok *t) {
  struct mbuf *bcode = &p->mjs->bcode;
  enum mjs_err res = MJS_OK;
  int tok = t->tok;
  LOG(LL_DEBUG, ("[%.*s] %p", p->tok.len, p->tok.ptr, &t));
  switch (t->tok) {
    case TOK_KEYWORD_FALSE:
      emit_byte(p, OP_PUSH_FALSE);
      break;
    case TOK_KEYWORD_TRUE:
      emit_byte(p, OP_PUSH_TRUE);
      break;
    case TOK_KEYWORD_UNDEFINED:
      emit_byte(p, OP_PUSH_UNDEF);
      break;
    case TOK_KEYWORD_NULL:
      emit_byte(p, OP_PUSH_NULL);
      break;
    case TOK_IDENT: {
      int prev_tok = p->prev_tok;
      int next_tok = ptest(p);
      emit_byte(p, OP_PUSH_STR);
      emit_str(p, t->ptr, t->len);
      emit_byte(p, prev_tok == TOK_DOT ? OP_SWAP : OP_FIND_SCOPE);
      if (!findtok(s_assign_ops, next_tok) &&
          !findtok(s_postfix_ops, next_tok) &&
          !findtok(s_postfix_ops, prev_tok)) {
        if (prev_tok == TOK_DOT) emit_byte(p, OP_SET_THIS);
        emit_byte(p, OP_GET);
      }
      break;
    }
    case TOK_NUM: {
      double iv, d = strtod(t->ptr, NULL);
      unsigned long uv = strtoul(t->ptr + 2, NULL, 16);
      if (t->ptr[0] == '0' && t->ptr[1] == 'x') d = uv;
      if (modf(d, &iv) == 0) {
        emit_byte(p, OP_PUSH_INT);
        emit_int(p, (int64_t) d);
      } else {
        emit_byte(p, OP_PUSH_DBL);
        emit_str(p, t->ptr, t->len);
      }
      break;
    }
    case TOK_STR:
      emit_byte(p, OP_PUSH_STR);
      embed_string(bcode, bcode->len, t->ptr, t->len, EMBSTR_UNESCAPE);
      break;
    case TOK_OPEN_BRACKET:
      res = parse_array_literal(p);
      break;
    case TOK_OPEN_CURLY:
      res = parse_object_literal(p);
      break;
    case TOK_OPEN_PAREN:
      pnext1(p);
      res = parse_expr(p);
      break;
    case TOK_KEYWORD_FUNCTION:
      res = parse_function(p);
      break;
    case TOK_KEYWORD_THIS:
      emit_byte(p, OP_PUSH_THIS);
      break;
    default:
      SYNTAX_ERROR(p);
  }
  if (tok != TOK_KEYWORD_FUNCTION) pnext1(p);
  return res;
}

static mjs_err_t parse_call_dot_mem(struct pstate *p, int prev_op) {
  int ops[] = {TOK_DOT, TOK_OPEN_PAREN, TOK_OPEN_BRACKET, TOK_EOF};
  mjs_err_t res = MJS_OK;
  if ((res = parse_literal(p, &p->tok)) != MJS_OK) return res;
  while (findtok(ops, p->tok.tok) != TOK_EOF) {
    if (p->tok.tok == TOK_OPEN_BRACKET) {
      EXPECT(p, TOK_OPEN_BRACKET);
      if ((res = parse_expr(p)) != MJS_OK) return res;
      emit_byte(p, OP_SWAP);
      emit_byte(p, OP_SET_THIS);
      emit_byte(p, OP_GET);
      EXPECT(p, TOK_CLOSE_BRACKET);
    } else if (p->tok.tok == TOK_OPEN_PAREN) {
      EXPECT(p, TOK_OPEN_PAREN);
      emit_byte(p, OP_ARGS);
      while (p->tok.tok != TOK_CLOSE_PAREN) {
        if ((res = parse_expr(p)) != MJS_OK) return res;
        if (p->tok.tok == TOK_COMMA) pnext1(p);
      }
      emit_byte(p, OP_CALL);
      EXPECT(p, TOK_CLOSE_PAREN);
    } else if (p->tok.tok == TOK_DOT) {
      EXPECT(p, TOK_DOT);
      if ((res = parse_call_dot_mem(p, TOK_DOT)) != MJS_OK) return res;
    }
  }
  (void) prev_op;
  return res;
}

static mjs_err_t parse_postfix(struct pstate *p, int prev_op) {
  mjs_err_t res = MJS_OK;
  if ((res = parse_call_dot_mem(p, prev_op)) != MJS_OK) return res;
  if (p->tok.tok == TOK_PLUS_PLUS || p->tok.tok == TOK_MINUS_MINUS) {
    int op = p->tok.tok == TOK_PLUS_PLUS ? TOK_POSTFIX_PLUS : TOK_POSTFIX_MINUS;
    emit_op(p, op);
    pnext1(p);
  }
  return res;
}

static mjs_err_t parse_unary(struct pstate *p, int prev_op) {
  mjs_err_t res = MJS_OK;
  int op = TOK_EOF;
  if (findtok(s_unary_ops, p->tok.tok) != TOK_EOF) {
    op = p->tok.tok;
    pnext1(p);
  }
  if ((res = parse_postfix(p, prev_op)) != MJS_OK) return res;
  if (op != TOK_EOF) {
    if (op == TOK_MINUS) op = TOK_UNARY_MINUS;
    if (op == TOK_PLUS) op = TOK_UNARY_PLUS;
    emit_op(p, op);
  }
  return res;
}

static mjs_err_t parse_mul_div_rem(struct pstate *p, int prev_op) {
  int ops[] = {TOK_MUL, TOK_DIV, TOK_REM, TOK_EOF};
  PARSE_LTR_BINOP(p, parse_unary, parse_mul_div_rem, ops, prev_op);
}

static mjs_err_t parse_plus_minus(struct pstate *p, int prev_op) {
  int ops[] = {TOK_PLUS, TOK_MINUS, TOK_EOF};
  PARSE_LTR_BINOP(p, parse_mul_div_rem, parse_plus_minus, ops, prev_op);
}

static mjs_err_t parse_shifts(struct pstate *p, int prev_op) {
  int ops[] = {TOK_LSHIFT, TOK_RSHIFT, TOK_URSHIFT, TOK_EOF};
  PARSE_LTR_BINOP(p, parse_plus_minus, parse_shifts, ops, prev_op);
}

static mjs_err_t parse_comparison(struct pstate *p, int prev_op) {
  PARSE_LTR_BINOP(p, parse_shifts, parse_comparison, s_comparison_ops, prev_op);
}

static mjs_err_t parse_equality(struct pstate *p, int prev_op) {
  PARSE_LTR_BINOP(p, parse_comparison, parse_equality, s_equality_ops, prev_op);
}

static mjs_err_t parse_bitwise_and(struct pstate *p, int prev_op) {
  int ops[] = {TOK_AND, TOK_EOF};
  PARSE_LTR_BINOP(p, parse_equality, parse_bitwise_and, ops, prev_op);
}

static mjs_err_t parse_bitwise_xor(struct pstate *p, int prev_op) {
  int ops[] = {TOK_XOR, TOK_EOF};
  PARSE_LTR_BINOP(p, parse_bitwise_and, parse_bitwise_xor, ops, prev_op);
}

static mjs_err_t parse_bitwise_or(struct pstate *p, int prev_op) {
  int ops[] = {TOK_OR, TOK_EOF};
  PARSE_LTR_BINOP(p, parse_bitwise_xor, parse_bitwise_or, ops, prev_op);
}

static mjs_err_t parse_logical_and(struct pstate *p, int prev_op) {
  int ops[] = {TOK_LOGICAL_AND, TOK_EOF};
  PARSE_LTR_BINOP(p, parse_bitwise_or, parse_logical_and, ops, prev_op);
}

static mjs_err_t parse_logical_or(struct pstate *p, int prev_op) {
  int ops[] = {TOK_LOGICAL_OR, TOK_EOF};
  PARSE_LTR_BINOP(p, parse_logical_and, parse_logical_or, ops, prev_op);
}

static mjs_err_t parse_ternary(struct pstate *p, int prev_op) {
  struct mbuf *bcode = &p->mjs->bcode;
  mjs_err_t res = MJS_OK;
  if ((res = parse_logical_or(p, TOK_EOF)) != MJS_OK) return res;
  if (prev_op != TOK_EOF) emit_op(p, prev_op);
  if (p->tok.tok == TOK_QUESTION) {
    size_t off1, off2, off3;
    EXPECT(p, TOK_QUESTION);

    off1 = mjs_bcode_size(bcode);
    emit_byte(p, OP_JMP_FALSE);
    emit_byte(p, 0);

    if ((res = parse_ternary(p, TOK_EOF)) != MJS_OK) return res;

    emit_byte(p, OP_JMP);
    emit_byte(p, 0);
    off2 = mjs_bcode_size(bcode);

    emit_byte(p, OP_DROP);
    if (off2 - off1 >= 255) FAIL_ERR(p, MJS_INTERNAL_ERROR);
    mjs_bcode_mutate_byte(p->mjs, off1 + 1, off2 - off1);

    EXPECT(p, TOK_COLON);
    if ((res = parse_ternary(p, TOK_EOF)) != MJS_OK) return res;

    off3 = mjs_bcode_size(bcode);
    if (off3 - off2 >= 255) FAIL_ERR(p, MJS_INTERNAL_ERROR);
    mjs_bcode_mutate_byte(p->mjs, off2 - 1,
                          off3 - off2 + JUMP_INSTRUCTION_SIZE);
  }
  return res;
}

static mjs_err_t parse_assignment(struct pstate *p, int prev_op) {
  PARSE_RTL_BINOP(p, parse_ternary, parse_assignment, s_assign_ops, prev_op);
}

static mjs_err_t parse_expr(struct pstate *p) {
  return parse_assignment(p, TOK_EOF);
}

static mjs_err_t parse_let(struct pstate *p) {
  mjs_err_t res = MJS_OK;
  LOG(LL_DEBUG, ("[%.*s]", 10, p->tok.ptr));
  EXPECT(p, TOK_KEYWORD_LET);
  for (;;) {
    struct tok tmp = p->tok;
    EXPECT(p, TOK_IDENT);

    emit_byte(p, OP_PUSH_STR);
    emit_str(p, tmp.ptr, tmp.len);
    emit_byte(p, OP_PUSH_SCOPE);
    emit_byte(p, OP_CREATE);

    if (p->tok.tok == TOK_ASSIGN) {
      pnext1(p);
      emit_byte(p, OP_PUSH_STR);
      emit_str(p, tmp.ptr, tmp.len);
      emit_byte(p, OP_FIND_SCOPE);
      if ((res = parse_expr(p)) != MJS_OK) return res;
      emit_op(p, TOK_ASSIGN);
    } else {
      emit_byte(p, OP_PUSH_UNDEF);
    }
    if (p->tok.tok == TOK_COMMA) {
      emit_byte(p, OP_DROP);
      pnext1(p);
    }
    if (p->tok.tok == TOK_SEMICOLON || p->tok.tok == TOK_EOF) break;
  }
  return res;
}

static mjs_err_t parse_block_or_stmt(struct pstate *p, int cs) {
  if (ptest(p) == TOK_OPEN_CURLY) {
    return parse_block(p, cs);
  } else {
    return parse_statement(p);
  }
}

static mjs_err_t parse_for_in(struct pstate *p) {
  mjs_err_t res = MJS_OK;
  size_t off_iter, off_done;
  struct mbuf *bcode = &p->mjs->bcode;

  emit_byte(p, OP_NEW_SCOPE);

  /* Put iterator variable name to the stack */
  if (p->tok.tok == TOK_KEYWORD_LET) {
    EXPECT(p, TOK_KEYWORD_LET);
    emit_byte(p, OP_PUSH_STR);
    emit_str(p, p->tok.ptr, p->tok.len);
    emit_byte(p, OP_PUSH_SCOPE);
    emit_byte(p, OP_CREATE);
  }
  emit_byte(p, OP_PUSH_STR);
  emit_str(p, p->tok.ptr, p->tok.len);

  /* Put object to the stack */
  EXPECT(p, TOK_IDENT);
  EXPECT(p, TOK_KEYWORD_IN);
  parse_expr(p);
  EXPECT(p, TOK_CLOSE_PAREN);

  emit_byte(p, OP_PUSH_UNDEF); /* Push iterator */

  off_iter = mjs_bcode_size(bcode);

  /* Before parsing condition statement, push break/continue offsets  */
  emit_byte(p, OP_LOOP);
  emit_byte(p, 0); /* Fill out OP_BREAK address later  */
  emit_byte(p, 3); /* Point OP_CONTINUE to the next instruction */

  emit_byte(p, OP_FOR_IN_NEXT);
  emit_byte(p, OP_DUP);
  emit_byte(p, OP_JMP_FALSE);
  emit_byte(p, 0);

  // Parse loop body
  if (p->tok.tok == TOK_OPEN_CURLY) {
    if ((res = parse_statement_list(p, TOK_CLOSE_CURLY)) != MJS_OK) return res;
    pnext1(p);
  } else {
    if ((res = parse_statement(p)) != MJS_OK) return res;
  }
  emit_byte(p, OP_DROP);
  emit_byte(p, OP_CONTINUE);

  off_done = mjs_bcode_size(bcode);

  mjs_bcode_mutate_byte(p->mjs, off_iter + 1, off_done - off_iter + 1);
  mjs_bcode_mutate_byte(p->mjs, off_iter + 6, off_done - off_iter - 5);
  emit_byte(p, OP_BREAK);
  emit_byte(p, OP_DROP);
  emit_byte(p, OP_DROP);
  emit_byte(p, OP_DROP);
  emit_byte(p, OP_DEL_SCOPE);

  return res;
}

static int check_for_in(struct pstate *p) {
  struct pstate saved = *p;
  int forin = 0;
  if (p->tok.tok == TOK_KEYWORD_LET) pnext1(p);
  if (p->tok.tok == TOK_IDENT) {
    pnext1(p);
    if (p->tok.tok == TOK_KEYWORD_IN) forin = 1;
  }
  *p = saved;
  return forin;
}

static mjs_err_t parse_for(struct pstate *p) {
  size_t off_cond, off_post, off_body, off_done;
  struct mbuf *bcode = &p->mjs->bcode;
  mjs_err_t res = MJS_OK;

  LOG(LL_DEBUG, ("[%.*s]", 10, p->tok.ptr));
  EXPECT(p, TOK_KEYWORD_FOR);
  EXPECT(p, TOK_OPEN_PAREN);

  /* Look forward - is it for..in ? */
  if (check_for_in(p)) return parse_for_in(p);

  /* Parse pre-condition */
  emit_byte(p, OP_NEW_SCOPE);
  if (p->tok.tok == TOK_KEYWORD_LET) {
    if ((res = parse_let(p)) != MJS_OK) return res;
  } else {
    if ((res = parse_expr(p)) != MJS_OK) return res;
  }
  EXPECT(p, TOK_SEMICOLON);

  /* Before parsing condition statement, push break/continue offsets  */
  emit_byte(p, OP_LOOP);
  emit_byte(p, 0);
  emit_byte(p, 0);

  // parse condition statement
  off_cond = mjs_bcode_size(bcode);
  if ((res = parse_expr(p)) != MJS_OK) return res;
  EXPECT(p, TOK_SEMICOLON);

  // Exit the loop if false
  off_post = mjs_bcode_size(bcode);
  emit_byte(p, OP_JMP_FALSE);
  emit_byte(p, 0);

  // Jump to the loop body
  emit_byte(p, OP_JMP);
  emit_byte(p, 0);

  // Parse post-condition statement
  if ((res = parse_expr(p)) != MJS_OK) return res;
  EXPECT(p, TOK_CLOSE_PAREN);
  emit_byte(p, OP_DROP);

  // Post-condition statement done. Jump to the condition statement.
  off_body = mjs_bcode_size(bcode);
  emit_byte(p, OP_JMP_BACK);
  emit_byte(p, off_body - off_cond);

  // Parse loop body
  if (p->tok.tok == TOK_OPEN_CURLY) {
    if ((res = parse_statement_list(p, TOK_CLOSE_CURLY)) != MJS_OK) return res;
    pnext1(p);
  } else {
    if ((res = parse_statement(p)) != MJS_OK) return res;
  }
  emit_byte(p, OP_DROP);
  emit_byte(p, OP_CONTINUE);

  off_done = mjs_bcode_size(bcode);
  mjs_bcode_mutate_byte(p->mjs, off_cond - 2, off_done - off_cond + 5);
  mjs_bcode_mutate_byte(p->mjs, off_cond - 1, off_post + 7 - off_cond);
  mjs_bcode_mutate_byte(p->mjs, off_post + 1, off_done - off_post);
  mjs_bcode_mutate_byte(p->mjs, off_post + 3, off_body - off_post);

  emit_byte(p, OP_DROP); /* remove JMP_FALSE value left by cond stmt */
  emit_byte(p, OP_BREAK);
  emit_byte(p, OP_DEL_SCOPE);

  return res;
}

static mjs_err_t parse_while(struct pstate *p) {
  size_t off_cond, off_body, off_done;
  mjs_err_t res = MJS_OK;

  EXPECT(p, TOK_KEYWORD_WHILE);
  EXPECT(p, TOK_OPEN_PAREN);

  emit_byte(p, OP_NEW_SCOPE);
  emit_byte(p, OP_LOOP);
  emit_byte(p, 0); /* Fill out OP_BREAK address later  */
  emit_byte(p, 3); /* Point OP_CONTINUE to the next instruction */

  // parse condition statement
  off_cond = mjs_bcode_size(&p->mjs->bcode);
  if ((res = parse_expr(p)) != MJS_OK) return res;
  EXPECT(p, TOK_CLOSE_PAREN);

  // Exit the loop if false
  off_body = mjs_bcode_size(&p->mjs->bcode);
  emit_byte(p, OP_JMP_FALSE);
  emit_byte(p, 0);

  // Parse loop body
  if (p->tok.tok == TOK_OPEN_CURLY) {
    if ((res = parse_statement_list(p, TOK_CLOSE_CURLY)) != MJS_OK) return res;
    pnext1(p);
  } else {
    if ((res = parse_statement(p)) != MJS_OK) return res;
  }
  emit_byte(p, OP_DROP);
  emit_byte(p, OP_CONTINUE);

  off_done = mjs_bcode_size(&p->mjs->bcode);
  mjs_bcode_mutate_byte(p->mjs, off_cond - 2, off_done - off_cond + 4);
  mjs_bcode_mutate_byte(p->mjs, off_body + 1, off_done - off_body);
  emit_byte(p, OP_BREAK);
  emit_byte(p, OP_DEL_SCOPE);
  return res;
}

static mjs_err_t parse_if(struct pstate *p) {
  size_t off_if, off_endif;
  mjs_err_t res = MJS_OK;
  LOG(LL_DEBUG, ("[%.*s]", 10, p->tok.ptr));
  EXPECT(p, TOK_KEYWORD_IF);
  EXPECT(p, TOK_OPEN_PAREN);
  if ((res = parse_expr(p)) != MJS_OK) return res;

  off_if = mjs_bcode_size(&p->mjs->bcode);
  emit_byte(p, OP_JMP_FALSE);
  emit_byte(p, 0);

  EXPECT(p, TOK_CLOSE_PAREN);
  if ((res = parse_block_or_stmt(p, 1)) != MJS_OK) return res;

  if (p->tok.tok == TOK_KEYWORD_ELSE) {
    /*
     * Else clause is present, so, if the condition is not true, the jump
     * target (off_endif) should be not the current offset, but the offset
     * after jump-over-else opcode
     */
    size_t off_else, off_endelse;
    pnext1(p);
    off_else = mjs_bcode_size(&p->mjs->bcode);
    emit_byte(p, OP_JMP);
    emit_byte(p, 0);
    off_endif = mjs_bcode_size(&p->mjs->bcode);

    emit_byte(p, OP_DROP);
    if ((res = parse_block_or_stmt(p, 1)) != MJS_OK) return res;
    off_endelse = mjs_bcode_size(&p->mjs->bcode);
    if (off_endelse - off_else >= 255) FAIL_ERR(p, MJS_INTERNAL_ERROR);
    mjs_bcode_mutate_byte(p->mjs, off_else + 1 /*OP_JMP*/,
                          off_endelse - off_else);
  } else {
    /* Else clause is not present, so, current offset is a jump target
     * (off_endif) */
    off_endif = mjs_bcode_size(&p->mjs->bcode);
  }

  if (off_endif - off_if >= 255) FAIL_ERR(p, MJS_INTERNAL_ERROR);
  mjs_bcode_mutate_byte(p->mjs, off_if + 1 /*OP_JMP_FALSE*/,
                        off_endif - off_if);

  return res;
}

static mjs_err_t parse_return(struct pstate *p) {
  EXPECT(p, TOK_KEYWORD_RETURN);
  parse_expr(p);
  emit_byte(p, OP_SETRETVAL);
  emit_byte(p, OP_RETURN);
  return MJS_OK;
}

static mjs_err_t parse_statement(struct pstate *p) {
  LOG(LL_DEBUG, ("[%.*s]", 10, p->tok.ptr));
  switch (p->tok.tok) {
    case TOK_KEYWORD_LET:
      return parse_let(p);
    case TOK_OPEN_CURLY:
      return parse_block(p, 1);
    case TOK_KEYWORD_RETURN:
      return parse_return(p);
    case TOK_KEYWORD_FOR:
      return parse_for(p);
    case TOK_KEYWORD_WHILE:
      return parse_while(p);
    case TOK_KEYWORD_BREAK:
      emit_byte(p, OP_PUSH_UNDEF);
      emit_byte(p, OP_BREAK);
      pnext1(p);
      return MJS_OK;
    case TOK_KEYWORD_CONTINUE:
      emit_byte(p, OP_CONTINUE);
      pnext1(p);
      return MJS_OK;
    case TOK_KEYWORD_IF:
      return parse_if(p);
    case TOK_KEYWORD_CASE:
    case TOK_KEYWORD_CATCH:
    case TOK_KEYWORD_DELETE:
    case TOK_KEYWORD_DO:
    case TOK_KEYWORD_INSTANCEOF:
    case TOK_KEYWORD_NEW:
    case TOK_KEYWORD_SWITCH:
    case TOK_KEYWORD_THROW:
    case TOK_KEYWORD_TRY:
    case TOK_KEYWORD_VAR:
    case TOK_KEYWORD_VOID:
    case TOK_KEYWORD_WITH:
      mjs_set_errorf(p->mjs, MJS_SYNTAX_ERROR, "[%.*s] is not implemented",
                     p->tok.len, p->tok.ptr);
      return MJS_SYNTAX_ERROR;
    default:
      return parse_expr(p);
  }
}

MJS_PRIVATE mjs_err_t
mjs_parse(const char *path, const char *buf, struct mjs *mjs) {
  mjs_err_t res = MJS_OK;
  struct pstate p;
  pinit(path, buf, &p);
  p.mjs = mjs;
  emit_byte(&p, OP_BCODE_HEADER);

  /* Remember starting bcode position, and reserve the room for bcode header */
  size_t start_idx = p.mjs->bcode.len;
  mbuf_append(&p.mjs->bcode, NULL,
              sizeof(mjs_header_item_t) * MJS_HDR_ITEMS_CNT);

  /* Append NULL-terminated filename */
  mbuf_append(&p.mjs->bcode, path, strlen(path) + 1 /* null-terminate */);

  mjs_header_item_t bcode_offset = p.mjs->bcode.len - start_idx;
  memcpy(p.mjs->bcode.buf + start_idx +
             sizeof(mjs_header_item_t) * MJS_HDR_ITEM_BCODE_OFFSET,
         &bcode_offset, sizeof(mjs_header_item_t));

  p.start_bcode_idx = p.mjs->bcode.len;

  res = parse_statement_list(&p, TOK_EOF);
  emit_byte(&p, OP_EXIT);

  /* remember map offset */
  mjs_header_item_t map_offset = p.mjs->bcode.len - start_idx;
  memcpy(p.mjs->bcode.buf + start_idx +
             sizeof(mjs_header_item_t) * MJS_HDR_ITEM_MAP_OFFSET,
         &map_offset, sizeof(mjs_header_item_t));

  /* put map length varint */
  int map_len = p.offset_lineno_map.len;
  size_t llen = varint_llen(map_len);
  mbuf_resize(&p.mjs->bcode, p.mjs->bcode.size + llen);
  varint_encode(map_len, (uint8_t *) p.mjs->bcode.buf + p.mjs->bcode.len);
  p.mjs->bcode.len += llen;

  /* put the map itself */
  mbuf_append(&p.mjs->bcode, p.offset_lineno_map.buf, p.offset_lineno_map.len);

  mjs_header_item_t total_size = p.mjs->bcode.len - start_idx;
  memcpy(p.mjs->bcode.buf + start_idx +
             sizeof(mjs_header_item_t) * MJS_HDR_ITEM_TOTAL_SIZE,
         &total_size, sizeof(mjs_header_item_t));

  mbuf_free(&p.offset_lineno_map);

  return res;
}
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_primitive.c"
#endif
/*
 * Copyright (c) 2017 Cesanta Software Limited
 * All rights reserved
 */

/* Amalgamated: #include "mjs/src/mjs_core.h" */
/* Amalgamated: #include "mjs/src/mjs_internal.h" */
/* Amalgamated: #include "mjs/src/mjs_primitive.h" */

mjs_val_t mjs_mk_null(void) {
  return MJS_NULL;
}

int mjs_is_null(mjs_val_t v) {
  return v == MJS_NULL;
}

mjs_val_t mjs_mk_undefined(void) {
  return MJS_UNDEFINED;
}

int mjs_is_undefined(mjs_val_t v) {
  return v == MJS_UNDEFINED;
}

mjs_val_t mjs_mk_number(struct mjs *mjs, double v) {
  mjs_val_t res;
  (void) mjs;
  /* not every NaN is a JS NaN */
  if (isnan(v)) {
    res = MJS_TAG_NAN;
  } else {
    union {
      double d;
      mjs_val_t r;
    } u;
    u.d = v;
    res = u.r;
  }
  return res;
}

static double get_double(mjs_val_t v) {
  union {
    double d;
    mjs_val_t v;
  } u;
  u.v = v;
  /* Due to NaN packing, any non-numeric value is already a valid NaN value */
  return u.d;
}

double mjs_get_double(struct mjs *mjs, mjs_val_t v) {
  (void) mjs;
  return get_double(v);
}

int mjs_get_int(struct mjs *mjs, mjs_val_t v) {
  (void) mjs;
  return (int) get_double(v);
}

int32_t mjs_get_int32(struct mjs *mjs, mjs_val_t v) {
  (void) mjs;
  return (int32_t) get_double(v);
}

int mjs_is_number(mjs_val_t v) {
  return v == MJS_TAG_NAN || !isnan(get_double(v));
}

mjs_val_t mjs_mk_boolean(struct mjs *mjs, int v) {
  (void) mjs;
  return (v ? 1 : 0) | MJS_TAG_BOOLEAN;
}

int mjs_get_bool(struct mjs *mjs, mjs_val_t v) {
  (void) mjs;
  if (mjs_is_boolean(v)) {
    return v & 1;
  } else {
    return 0;
  }
}

int mjs_is_boolean(mjs_val_t v) {
  return (v & MJS_TAG_MASK) == MJS_TAG_BOOLEAN;
}

MJS_PRIVATE mjs_val_t pointer_to_value(void *p) {
  uint64_t n = ((uint64_t)(uintptr_t) p);

  assert((n & MJS_TAG_MASK) == 0 || (n & MJS_TAG_MASK) == (~0 & MJS_TAG_MASK));
  return n & ~MJS_TAG_MASK;
}

MJS_PRIVATE void *get_ptr(mjs_val_t v) {
  return (void *) (uintptr_t)(v & 0xFFFFFFFFFFFFUL);
}

void *mjs_get_ptr(struct mjs *mjs, mjs_val_t v) {
  (void) mjs;
  if (!mjs_is_foreign(v)) {
    return NULL;
  }
  return get_ptr(v);
}

mjs_val_t mjs_mk_foreign(struct mjs *mjs, void *p) {
  (void) mjs;
  return pointer_to_value(p) | MJS_TAG_FOREIGN;
}

int mjs_is_foreign(mjs_val_t v) {
  return (v & MJS_TAG_MASK) == MJS_TAG_FOREIGN;
}

mjs_val_t mjs_mk_function(struct mjs *mjs, size_t off) {
  (void) mjs;
  return (mjs_val_t) off | MJS_TAG_FUNCTION;
}

int mjs_is_function(mjs_val_t v) {
  return (v & MJS_TAG_MASK) == MJS_TAG_FUNCTION;
}
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_string.c"
#endif
/*
 * Copyright (c) 2017 Cesanta Software Limited
 * All rights reserved
 */

/* Amalgamated: #include "mjs/src/mjs_core.h" */
/* Amalgamated: #include "mjs/src/mjs_internal.h" */
/* Amalgamated: #include "mjs/src/mjs_string.h" */
/* Amalgamated: #include "mjs/src/mjs_varint.h" */

// No UTF
typedef unsigned short Rune;
static int chartorune(Rune *rune, const char *str) {
  *rune = *(unsigned char *) str;
  return 1;
}
static int runetochar(char *str, Rune *rune) {
  str[0] = (char) *rune;
  return 1;
}

#define _MJS_STRING_BUF_RESERVE 100

MJS_PRIVATE size_t unescape(const char *s, size_t len, char *to);

MJS_PRIVATE void embed_string(struct mbuf *m, size_t offset, const char *p,
                              size_t len, uint8_t /*enum embstr_flags*/ flags);

/* TODO(lsm): NaN payload location depends on endianness, make crossplatform */
#define GET_VAL_NAN_PAYLOAD(v) ((char *) &(v))

int mjs_is_string(mjs_val_t v) {
  uint64_t t = v & MJS_TAG_MASK;
  return t == MJS_TAG_STRING_I || t == MJS_TAG_STRING_F ||
         t == MJS_TAG_STRING_O || t == MJS_TAG_STRING_5 ||
         t == MJS_TAG_STRING_D;
}

mjs_val_t mjs_mk_string(struct mjs *mjs, const char *p, size_t len, int copy) {
  struct mbuf *m = copy ? &mjs->owned_strings : &mjs->foreign_strings;
  mjs_val_t offset = m->len, tag = MJS_TAG_STRING_F;

  if (len == ~((size_t) 0)) len = strlen(p);

  if (copy) {
    /* owned string */
    if (len <= 4) {
      char *s = GET_VAL_NAN_PAYLOAD(offset) + 1;
      offset = 0;
      if (p != 0) {
        memcpy(s, p, len);
      }
      s[-1] = len;
      tag = MJS_TAG_STRING_I;
    } else if (len == 5) {
      char *s = GET_VAL_NAN_PAYLOAD(offset);
      offset = 0;
      if (p != 0) {
        memcpy(s, p, len);
      }
      tag = MJS_TAG_STRING_5;
      // } else if ((dict_index = v_find_string_in_dictionary(p, len)) >= 0) {
      //   offset = 0;
      //   GET_VAL_NAN_PAYLOAD(offset)[0] = dict_index;
      //   tag = MJS_TAG_STRING_D;
    } else {
      if (gc_strings_is_gc_needed(mjs)) {
        mjs->need_gc = 1;
      }

      /*
       * Before embedding new string, check if the reallocation is needed.  If
       * so, perform the reallocation by calling `mbuf_resize` manually, since
       * we
       * need to preallocate some extra space (`_MJS_STRING_BUF_RESERVE`)
       */
      if ((m->len + len) > m->size) {
        mbuf_resize(m, m->len + len + _MJS_STRING_BUF_RESERVE);
      }
      embed_string(m, m->len, p, len, EMBSTR_ZERO_TERM);
      tag = MJS_TAG_STRING_O;
    }
  } else {
    /* foreign string */
    if (sizeof(void *) <= 4 && len <= (1 << 15)) {
      /* small foreign strings can fit length and ptr in the mjs_val_t */
      offset = (uint64_t) len << 32 | (uint64_t)(uintptr_t) p;
    } else {
      /* bigger strings need indirection that uses ram */
      size_t pos = m->len;
      int llen = varint_llen(len);

      /* allocate space for len and ptr */
      mbuf_insert(m, pos, NULL, llen + sizeof(p));

      varint_encode(len, (uint8_t *) (m->buf + pos));
      memcpy(m->buf + pos + llen, &p, sizeof(p));
    }
    tag = MJS_TAG_STRING_F;
  }

  /* NOTE(lsm): don't use pointer_to_value, 32-bit ptrs will truncate */
  return (offset & ~MJS_TAG_MASK) | tag;
}

/* Get a pointer to string and string length. */
const char *mjs_get_string(struct mjs *mjs, mjs_val_t *v, size_t *sizep) {
  uint64_t tag = v[0] & MJS_TAG_MASK;
  const char *p = NULL;
  int llen;
  size_t size = 0;

  if (!mjs_is_string(*v)) {
    goto clean;
  }

  if (tag == MJS_TAG_STRING_I) {
    p = GET_VAL_NAN_PAYLOAD(*v) + 1;
    size = p[-1];
  } else if (tag == MJS_TAG_STRING_5) {
    p = GET_VAL_NAN_PAYLOAD(*v);
    size = 5;
    // } else if (tag == MJS_TAG_STRING_D) {
    //   int index = ((unsigned char *) GET_VAL_NAN_PAYLOAD(*v))[0];
    //   size = v_dictionary_strings[index].len;
    //   p = v_dictionary_strings[index].p;
  } else if (tag == MJS_TAG_STRING_O) {
    size_t offset = (size_t) gc_string_mjs_val_to_offset(*v);
    char *s = mjs->owned_strings.buf + offset;
    size = varint_decode((uint8_t *) s, &llen);
    p = s + llen;
    // } else if (tag == MJS_TAG_STRING_F) {
    //   /*
    //    * short foreign strings on <=32-bit machines can be encoded in a
    //    compact
    //    * form:
    //    *
    //    *     7         6        5        4        3        2        1 0
    //    *
    //    11111111|1111tttt|llllllll|llllllll|ssssssss|ssssssss|ssssssss|ssssssss
    //    *
    //    * Strings longer than 2^26 will be indireceted through the
    //    foreign_strings
    //    * mbuf.
    //    *
    //    * We don't use a different tag to represent those two cases. Instead,
    //    all
    //    * foreign strings represented with the help of the foreign_strings
    //    mbuf
    //    * will have the upper 16-bits of the payload set to zero. This allows
    //    us to
    //    * represent up to 477 million foreign strings longer than 64k.
    //    */
    //   uint16_t len = (*v >> 32) & 0xFFFF;
    //   if (sizeof(void *) <= 4 && len != 0) {
    //     size = (size_t) len;
    //     p = (const char *) (uintptr_t) *v;
    //   } else {
    //     size_t offset = (size_t) gc_string_mjs_val_to_offset(*v);
    //     char *s = mjs->foreign_strings.buf + offset;
    //
    //     size = decode_varint((uint8_t *) s, &llen);
    //     memcpy(&p, s + llen, sizeof(p));
    //   }
  } else {
    assert(0);
  }

clean:
  if (sizep != NULL) {
    *sizep = size;
  }
  return p;
}

const char *mjs_get_cstring(struct mjs *mjs, mjs_val_t *value) {
  size_t size;
  const char *s = mjs_get_string(mjs, value, &size);
  if (s == NULL) return NULL;
  if (s[size] != 0 || strlen(s) != size) {
    return NULL;
  }
  return s;
}

int mjs_strcmp(struct mjs *mjs, mjs_val_t *a, const char *b, size_t len) {
  size_t n;
  const char *s;
  if (len == (size_t) ~0) len = strlen(b);
  s = mjs_get_string(mjs, a, &n);
  if (n != len) {
    return n - len;
  }
  return strncmp(s, b, len);
}

MJS_PRIVATE unsigned long cstr_to_ulong(const char *s, size_t len, int *ok) {
  char *e;
  unsigned long res = strtoul(s, &e, 10);
  *ok = (e == s + len) && len != 0;
  return res;
}

MJS_PRIVATE mjs_err_t
str_to_ulong(struct mjs *mjs, mjs_val_t v, int *ok, unsigned long *res) {
  enum mjs_err ret = MJS_OK;
  size_t len = 0;
  const char *p = mjs_get_string(mjs, &v, &len);
  *res = cstr_to_ulong(p, len, ok);

  return ret;
}

MJS_PRIVATE int s_cmp(struct mjs *mjs, mjs_val_t a, mjs_val_t b) {
  size_t a_len, b_len;
  const char *a_ptr, *b_ptr;

  a_ptr = mjs_get_string(mjs, &a, &a_len);
  b_ptr = mjs_get_string(mjs, &b, &b_len);

  if (a_len == b_len) {
    return memcmp(a_ptr, b_ptr, a_len);
  }
  if (a_len > b_len) {
    return 1;
  } else if (a_len < b_len) {
    return -1;
  } else {
    return 0;
  }
}

MJS_PRIVATE mjs_val_t s_concat(struct mjs *mjs, mjs_val_t a, mjs_val_t b) {
  size_t a_len, b_len, res_len;
  const char *a_ptr, *b_ptr, *res_ptr;
  mjs_val_t res;

  /* Find out lengths of both srtings */
  a_ptr = mjs_get_string(mjs, &a, &a_len);
  b_ptr = mjs_get_string(mjs, &b, &b_len);

  /* Create a placeholder string */
  res = mjs_mk_string(mjs, NULL, a_len + b_len, 1);

  /* mjs_mk_string() may have reallocated mbuf - revalidate pointers */
  a_ptr = mjs_get_string(mjs, &a, &a_len);
  b_ptr = mjs_get_string(mjs, &b, &b_len);

  /* Copy strings into the placeholder */
  res_ptr = mjs_get_string(mjs, &res, &res_len);
  memcpy((char *) res_ptr, a_ptr, a_len);
  memcpy((char *) res_ptr + a_len, b_ptr, b_len);

  return res;
}

/*
 * string_idx takes and index in the string and the string size, and returns
 * the index which is >= 0 and <= size. Negative index is interpreted as
 * size + index.
 */
// static int string_idx(int idx, int size) {
//   if (idx < 0) {
//     idx = size + idx;
//     if (idx < 0) {
//       idx = 0;
//     }
//   }
//   if (idx > size) {
//     idx = size;
//   }
//   return idx;
// }

// MJS_PRIVATE void mjs_string_slice(struct bf_vm *vm) {
//   struct mjs *mjs = (struct mjs *) vm->user_data;
//   int nargs = mjs_get_int(mjs, mjs_pop(mjs));
//   mjs_val_t ret = mjs_mk_number(mjs, 0);
//   mjs_val_t beginSlice_v = MJS_UNDEFINED;
//   mjs_val_t endSlice_v = MJS_UNDEFINED;
//   int beginSlice = 0;
//   int endSlice = 0;
//   size_t size;
//   const char *s = NULL;
//
//   if (!mjs_is_string(mjs->vals.this_val)) {
//     mjs_prepend_errorf(mjs, MJS_TYPE_ERROR, "this should be a string");
//     goto clean;
//   }
//
//   s = mjs_get_string(mjs, &mjs->vals.this_val, &size);
//
//   if (nargs < 1) {
//     mjs_prepend_errorf(mjs, MJS_TYPE_ERROR, "missing argument
//     'beginSlice'");
//     goto clean;
//   }
//
//   beginSlice_v = mjs_pop(mjs);
//
//   if (!mjs_is_number(beginSlice_v)) {
//     mjs_prepend_errorf(mjs, MJS_TYPE_ERROR, "beginSlice should be a
//     number");
//     goto clean;
//   }
//
//   beginSlice = string_idx(mjs_get_int(mjs, beginSlice_v), size);
//
//   if (nargs >= 2) {
//     /* endSlice is given; use it */
//     endSlice_v = mjs_pop(mjs);
//     if (!mjs_is_number(endSlice_v)) {
//       mjs_prepend_errorf(mjs, MJS_TYPE_ERROR, "endSlice should be a
//       number");
//       goto clean;
//     }
//
//     endSlice = string_idx(mjs_get_int(mjs, endSlice_v), size);
//   } else {
//     /* endSlice is not given; assume the end of the string */
//     endSlice = size;
//   }
//
//   if (endSlice < beginSlice) {
//     endSlice = beginSlice;
//   }
//
//   ret = mjs_mk_string(mjs, s + beginSlice, endSlice - beginSlice, 1);
//
// clean:
//   mjs_push(mjs, ret);
// }
//
// MJS_PRIVATE void mjs_string_char_code_at(struct bf_vm *vm) {
//   struct mjs *mjs = (struct mjs *) vm->user_data;
//   int nargs = mjs_get_int(mjs, mjs_pop(mjs));
//   mjs_val_t ret = MJS_UNDEFINED;
//   mjs_val_t idx_v = MJS_UNDEFINED;
//   int idx = 0;
//   size_t size;
//   const char *s = NULL;
//
//   if (!mjs_is_string(mjs->vals.this_val)) {
//     mjs_prepend_errorf(mjs, MJS_TYPE_ERROR, "this should be a string");
//     goto clean;
//   }
//
//   s = mjs_get_string(mjs, &mjs->vals.this_val, &size);
//
//   if (nargs < 1) {
//     mjs_prepend_errorf(mjs, MJS_TYPE_ERROR, "missing argument 'index'");
//     goto clean;
//   }
//
//   idx_v = mjs_pop(mjs);
//
//   if (!mjs_is_number(idx_v)) {
//     mjs_prepend_errorf(mjs, MJS_TYPE_ERROR, "index should be a number");
//     goto clean;
//   }
//
//   idx = string_idx(mjs_get_int(mjs, idx_v), size);
//   if (idx >= 0 && idx < (int) size) {
//     ret = mjs_mk_number(mjs, ((unsigned char *) s)[idx]);
//   }
//
// clean:
//   mjs_push(mjs, ret);
// }

// MJS_PRIVATE void mjs_fstr(struct bf_vm *vm) {
//   struct mjs *mjs = (struct mjs *) vm->user_data;
//   int nargs = mjs_get_int(mjs, mjs_pop(mjs));
//   mjs_val_t ret = MJS_UNDEFINED;
//
//   char *ptr = NULL;
//   int offset = 0;
//   int len = 0;
//
//   mjs_val_t ptr_v = MJS_UNDEFINED;
//   mjs_val_t offset_v = MJS_UNDEFINED;
//   mjs_val_t len_v = MJS_UNDEFINED;
//
//   if (nargs == 2) {
//     ptr_v = mjs_pop(mjs);
//     len_v = mjs_pop(mjs);
//   } else if (nargs == 3) {
//     ptr_v = mjs_pop(mjs);
//     offset_v = mjs_pop(mjs);
//     len_v = mjs_pop(mjs);
//   } else {
//     mjs_prepend_errorf(
//         mjs, MJS_TYPE_ERROR,
//         "fstr takes 2 or 3 arguments: (ptr, len) or (ptr, offset, len)");
//     goto clean;
//   }
//
//   if (!mjs_is_foreign(ptr_v)) {
//     mjs_prepend_errorf(mjs, MJS_TYPE_ERROR, "ptr should be a foreign
//     pointer");
//     goto clean;
//   }
//
//   if (offset_v != MJS_UNDEFINED && !mjs_is_number(offset_v)) {
//     mjs_prepend_errorf(mjs, MJS_TYPE_ERROR, "offset should be a number");
//     goto clean;
//   }
//
//   if (!mjs_is_number(len_v)) {
//     mjs_prepend_errorf(mjs, MJS_TYPE_ERROR, "len should be a number");
//     goto clean;
//   }
//
//   /* all arguments are fine */
//
//   ptr = (char *) mjs_get_ptr(mjs, ptr_v);
//   if (offset_v != MJS_UNDEFINED) {
//     offset = mjs_get_int(mjs, offset_v);
//   }
//   len = mjs_get_int(mjs, len_v);
//
//   ret = mjs_mk_string(mjs, ptr + offset, len, 0 /* don't copy */);
//
// clean:
//   mjs_push(mjs, ret);
// }

enum unescape_error {
  SLRE_INVALID_HEX_DIGIT,
  SLRE_INVALID_ESC_CHAR,
  SLRE_UNTERM_ESC_SEQ,
};

static int hex(int c) {
  if (c >= '0' && c <= '9') return c - '0';
  if (c >= 'a' && c <= 'f') return c - 'a' + 10;
  if (c >= 'A' && c <= 'F') return c - 'A' + 10;
  return -SLRE_INVALID_HEX_DIGIT;
}

static int nextesc(const char **p) {
  const unsigned char *s = (unsigned char *) (*p)++;
  switch (*s) {
    case 0:
      return -SLRE_UNTERM_ESC_SEQ;
    case 'c':
      ++*p;
      return *s & 31;
    case 'b':
      return '\b';
    case 't':
      return '\t';
    case 'n':
      return '\n';
    case 'v':
      return '\v';
    case 'f':
      return '\f';
    case 'r':
      return '\r';
    case '\\':
      return '\\';
    case 'u':
      if (isxdigit(s[1]) && isxdigit(s[2]) && isxdigit(s[3]) &&
          isxdigit(s[4])) {
        (*p) += 4;
        return hex(s[1]) << 12 | hex(s[2]) << 8 | hex(s[3]) << 4 | hex(s[4]);
      }
      return -SLRE_INVALID_HEX_DIGIT;
    case 'x':
      if (isxdigit(s[1]) && isxdigit(s[2])) {
        (*p) += 2;
        return (hex(s[1]) << 4) | hex(s[2]);
      }
      return -SLRE_INVALID_HEX_DIGIT;
    default:
      return -SLRE_INVALID_ESC_CHAR;
  }
}

MJS_PRIVATE size_t unescape(const char *s, size_t len, char *to) {
  const char *end = s + len;
  size_t n = 0;
  char tmp[4];
  Rune r;

  while (s < end) {
    s += chartorune(&r, s);
    if (r == '\\' && s < end) {
      switch (*s) {
        case '"':
          s++, r = '"';
          break;
        case '\'':
          s++, r = '\'';
          break;
        case '\n':
          s++, r = '\n';
          break;
        default: {
          const char *tmp_s = s;
          int i = nextesc(&s);
          switch (i) {
            case -SLRE_INVALID_ESC_CHAR:
              r = '\\';
              s = tmp_s;
              n += runetochar(to == NULL ? tmp : to + n, &r);
              s += chartorune(&r, s);
              break;
            case -SLRE_INVALID_HEX_DIGIT:
            default:
              r = i;
          }
        }
      }
    }
    n += runetochar(to == NULL ? tmp : to + n, &r);
  }

  return n;
}

MJS_PRIVATE void embed_string(struct mbuf *m, size_t offset, const char *p,
                              size_t len, uint8_t /*enum embstr_flags*/ flags) {
  char *old_base = m->buf;
  uint8_t p_backed_by_mbuf = p >= old_base && p < old_base + m->len;
  size_t n = (flags & EMBSTR_UNESCAPE) ? unescape(p, len, NULL) : len;

  /* Calculate how many bytes length takes */
  int k = varint_llen(n);

  /* total length: varing length + string len + zero-term */
  size_t tot_len = k + n + !!(flags & EMBSTR_ZERO_TERM);

  /* Allocate buffer */
  mbuf_insert(m, offset, NULL, tot_len);

  /* Fixup p if it was relocated by mbuf_insert() above */
  if (p_backed_by_mbuf) {
    p += m->buf - old_base;
  }

  /* Write length */
  varint_encode(n, (unsigned char *) m->buf + offset);

  /* Write string */
  if (p != 0) {
    if (flags & EMBSTR_UNESCAPE) {
      unescape(p, len, m->buf + offset + k);
    } else {
      memcpy(m->buf + offset + k, p, len);
    }
  }

  /* add NULL-terminator if needed */
  if (flags & EMBSTR_ZERO_TERM) {
    m->buf[offset + tot_len - 1] = '\0';
  }
}
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_tok.c"
#endif
/*
 * Copyright (c) 2017 Cesanta Software Limited
 * All rights reserved
 */

#include <stdlib.h>
#include <string.h>

/* Amalgamated: #include "common/cs_dbg.h" */
/* Amalgamated: #include "mjs/src/mjs_tok.h" */

MJS_PRIVATE void pinit(const char *file_name, const char *buf,
                       struct pstate *p) {
  memset(p, 0, sizeof(*p));
  p->line_no = 1;
  p->last_emitted_line_no = 1;
  p->file_name = file_name;
  p->buf = p->pos = buf;
  mbuf_init(&p->offset_lineno_map, 0);
}

// We're not relying on the target libc ctype, as it may incorrectly
// handle negative arguments, e.g. isspace(-1).
static int mjs_is_space(int c) {
  return c == ' ' || c == '\r' || c == '\n' || c == '\t';
}

MJS_PRIVATE int mjs_is_digit(int c) {
  return c >= '0' && c <= '9';
}

static int mjs_is_alpha(int c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

MJS_PRIVATE int mjs_is_ident(int c) {
  return c == '_' || c == '$' || mjs_is_alpha(c);
}

// Try to parse a token that can take one or two chars.
static int longtok(struct pstate *p, const char *first_chars,
                   const char *second_chars) {
  if (strchr(first_chars, p->pos[0]) == NULL) return TOK_EOF;
  if (p->pos[1] != '\0' && strchr(second_chars, p->pos[1]) != NULL) {
    p->tok.len++;
    p->pos++;
    return p->pos[-1] << 8 | p->pos[0];
  }
  return p->pos[0];
}

// Try to parse a token that takes exactly 3 chars.
static int longtok3(struct pstate *p, char a, char b, char c) {
  if (p->pos[0] == a && p->pos[1] == b && p->pos[2] == c) {
    p->tok.len += 2;
    p->pos += 2;
    return p->pos[-2] << 16 | p->pos[-1] << 8 | p->pos[0];
  }
  return TOK_EOF;
}

// Try to parse a token that takes exactly 4 chars.
static int longtok4(struct pstate *p, char a, char b, char c, char d) {
  if (p->pos[0] == a && p->pos[1] == b && p->pos[2] == c && p->pos[3] == d) {
    p->tok.len += 3;
    p->pos += 3;
    return p->pos[-3] << 24 | p->pos[-2] << 16 | p->pos[-1] << 8 | p->pos[0];
  }
  return TOK_EOF;
}

static int getnum(struct pstate *p) {
  if (p->pos[0] == '0' && p->pos[1] == 'x') {
    // MSVC6 strtod cannot parse 0x... numbers, thus this ugly workaround.
    strtoul(p->pos + 2, (char **) &p->pos, 16);
  } else {
    strtod(p->pos, (char **) &p->pos);
  }
  p->tok.len = p->pos - p->tok.ptr;
  p->pos--;
  return TOK_NUM;
}

static int is_reserved_word_token(const char *s, int len) {
  const char *reserved[] = {
      "break",     "case",   "catch", "continue",   "debugger", "default",
      "delete",    "do",     "else",  "false",      "finally",  "for",
      "function",  "if",     "in",    "instanceof", "new",      "null",
      "return",    "switch", "this",  "throw",      "true",     "try",
      "typeof",    "var",    "void",  "while",      "with",     "let",
      "undefined", NULL};
  int i;
  if (!mjs_is_alpha(s[0])) return 0;
  for (i = 0; reserved[i] != NULL; i++) {
    if (len == (int) strlen(reserved[i]) && strncmp(s, reserved[i], len) == 0)
      return i + 1;
  }
  return 0;
}

static int getident(struct pstate *p) {
  while (mjs_is_ident(p->pos[0]) || mjs_is_digit(p->pos[0])) p->pos++;
  p->tok.len = p->pos - p->tok.ptr;
  p->pos--;
  return TOK_IDENT;
}

static int getstr(struct pstate *p) {
  int quote = *p->pos++;
  p->tok.ptr++;
  while (p->pos[0] != '\0' && p->pos[0] != quote) {
    if (p->pos[0] == '\\' && p->pos[1] != '\0' &&
        (p->pos[1] == quote || strchr("bfnrtv\\", p->pos[1]) != NULL)) {
      p->pos += 2;
    } else {
      p->pos++;
    }
  }
  p->tok.len = p->pos - p->tok.ptr;
  return TOK_STR;
}

static void skip_spaces_and_comments(struct pstate *p) {
  const char *pos;
  do {
    pos = p->pos;
    while (mjs_is_space(p->pos[0])) {
      if (p->pos[0] == '\n') p->line_no++;
      p->pos++;
    }
    if (p->pos[0] == '/' && p->pos[1] == '/') {
      while (p->pos[0] != '\0' && p->pos[0] != '\n') p->pos++;
      if (p->pos[0] == '\n') p->line_no++;
    }
    if (p->pos[0] == '/' && p->pos[1] == '*') {
      p->pos += 2;
      while (p->pos[0] != '\0') {
        if (p->pos[0] == '\n') p->line_no++;
        if (p->pos[0] == '*' && p->pos[1] == '/') {
          p->pos += 2;
          break;
        }
        p->pos++;
      }
    }
  } while (pos < p->pos);
}

static int ptranslate(int tok) {
#define DT(a, b) ((a) << 8 | (b))
#define TT(a, b, c) ((a) << 16 | (b) << 8 | (c))
#define QT(a, b, c, d) ((a) << 24 | (b) << 16 | (c) << 8 | (d))
  /* Map token ID produced by mjs_tok.c to token ID produced by lemon */
  /* clang-format off */
  switch (tok) {
    case ':': return TOK_COLON;
    case ';': return TOK_SEMICOLON;
    case ',': return TOK_COMMA;
    case '=': return TOK_ASSIGN;
    case '{': return TOK_OPEN_CURLY;
    case '}': return TOK_CLOSE_CURLY;
    case '(': return TOK_OPEN_PAREN;
    case ')': return TOK_CLOSE_PAREN;
    case '[': return TOK_OPEN_BRACKET;
    case ']': return TOK_CLOSE_BRACKET;
    case '*': return TOK_MUL;
    case '+': return TOK_PLUS;
    case '-': return TOK_MINUS;
    case '/': return TOK_DIV;
    case '%': return TOK_REM;
    case '&': return TOK_AND;
    case '|': return TOK_OR;
    case '^': return TOK_XOR;
    case '.': return TOK_DOT;
    case '?': return TOK_QUESTION;
    case '!': return TOK_NOT;
    case '~': return TOK_TILDA;
    case '<': return TOK_LT;
    case '>': return TOK_GT;
    case DT('<','<'): return TOK_LSHIFT;
    case DT('>','>'): return TOK_RSHIFT;
    case DT('-','-'): return TOK_MINUS_MINUS;
    case DT('+','+'): return TOK_PLUS_PLUS;
    case DT('+','='): return TOK_PLUS_ASSIGN;
    case DT('-','='): return TOK_MINUS_ASSIGN;
    case DT('*','='): return TOK_MUL_ASSIGN;
    case DT('/','='): return TOK_DIV_ASSIGN;
    case DT('&','='): return TOK_AND_ASSIGN;
    case DT('|','='): return TOK_OR_ASSIGN;
    case DT('%','='): return TOK_REM_ASSIGN;
    case DT('^','='): return TOK_XOR_ASSIGN;
    case DT('=','='): return TOK_EQ;
    case DT('!','='): return TOK_NE;
    case DT('<','='): return TOK_LE;
    case DT('>','='): return TOK_GE;
    case DT('&','&'): return TOK_LOGICAL_AND;
    case DT('|','|'): return TOK_LOGICAL_OR;
    case TT('=','=','='): return TOK_EQ_EQ;
    case TT('!','=','='): return TOK_NE_NE;
    case TT('<','<','='): return TOK_LSHIFT_ASSIGN;
    case TT('>','>','='): return TOK_RSHIFT_ASSIGN;
    case TT('>','>','>'): return TOK_URSHIFT;
    case QT('>','>','>','='): return TOK_URSHIFT_ASSIGN;
  }
  /* clang-format on */
  return tok;
}

MJS_PRIVATE int pnext(struct pstate *p) {
  int tmp, tok = TOK_EOF;

  skip_spaces_and_comments(p);
  p->tok.ptr = p->pos;
  p->tok.len = 1;

  if (mjs_is_digit(p->pos[0])) {
    tok = getnum(p);
  } else if (p->pos[0] == '\'' || p->pos[0] == '"') {
    tok = getstr(p);
  } else if (mjs_is_ident(p->pos[0])) {
    tok = getident(p);
    /*
     * NOTE: getident() has side effects on `p`, and `is_reserved_word_token()`
     * relies on them. Since in C the order of evaluation of the operands is
     * undefined, `is_reserved_word_token()` should be called in a separate
     * statement.
     */
    tok += is_reserved_word_token(p->tok.ptr, p->tok.len);
  } else if (strchr(",.:;{}[]()?", p->pos[0]) != NULL) {
    tok = p->pos[0];
  } else if ((tmp = longtok3(p, '<', '<', '=')) != TOK_EOF ||
             (tmp = longtok3(p, '>', '>', '=')) != TOK_EOF ||
             (tmp = longtok4(p, '>', '>', '>', '=')) != TOK_EOF ||
             (tmp = longtok3(p, '>', '>', '>')) != TOK_EOF ||
             (tmp = longtok3(p, '=', '=', '=')) != TOK_EOF ||
             (tmp = longtok3(p, '!', '=', '=')) != TOK_EOF ||
             (tmp = longtok(p, "&", "&=")) != TOK_EOF ||
             (tmp = longtok(p, "|", "|=")) != TOK_EOF ||
             (tmp = longtok(p, "<", "<=")) != TOK_EOF ||
             (tmp = longtok(p, ">", ">=")) != TOK_EOF ||
             (tmp = longtok(p, "-", "-=")) != TOK_EOF ||
             (tmp = longtok(p, "+", "+=")) != TOK_EOF) {
    tok = tmp;
  } else if ((tmp = longtok(p, "^~+-%/*<>=!|&", "=")) != TOK_EOF) {
    tok = tmp;
  }
  if (p->pos[0] != '\0') p->pos++;
  LOG(LL_DEBUG, ("  --> [%.*s]", p->tok.len, p->tok.ptr));
  p->prev_tok = p->tok.tok;
  p->tok.tok = ptranslate(tok);
  return p->tok.tok;
}
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_util.c"
#endif
/*
 * Copyright (c) 2017 Cesanta Software Limited
 * All rights reserved
 */

/* Amalgamated: #include "mjs/src/mjs_array.h" */
/* Amalgamated: #include "mjs/src/mjs_bcode.h" */
/* Amalgamated: #include "mjs/src/mjs_core.h" */
/* Amalgamated: #include "mjs/src/mjs_internal.h" */
/* Amalgamated: #include "mjs/src/mjs_object.h" */
/* Amalgamated: #include "mjs/src/mjs_primitive.h" */
/* Amalgamated: #include "mjs/src/mjs_string.h" */
/* Amalgamated: #include "mjs/src/mjs_tok.h" */
/* Amalgamated: #include "mjs/src/mjs_varint.h" */

const char *mjs_typeof(mjs_val_t v) {
  if (mjs_is_number(v)) {
    return "number";
  } else if (mjs_is_boolean(v)) {
    return "boolean";
  } else if (mjs_is_string(v)) {
    return "string";
  } else if (mjs_is_array(v)) {
    return "array";
  } else if (mjs_is_object(v)) {
    return "object";
  } else if (mjs_is_foreign(v)) {
    return "foreign_ptr";
  } else if (mjs_is_function(v)) {
    return "function";
  } else if (mjs_is_null(v)) {
    return "null";
  } else if (mjs_is_undefined(v)) {
    return "undefined";
  } else {
    return "???";
  }
}

void mjs_fprintf(mjs_val_t v, struct mjs *mjs, FILE *fp) {
  if (mjs_is_number(v)) {
    double iv, d = mjs_get_double(mjs, v);
    if (modf(d, &iv) == 0) {
      fprintf(fp, "%" INT64_FMT, (int64_t) d);
    } else {
      fprintf(fp, "%lg", mjs_get_double(mjs, v));
    }
  } else if (mjs_is_boolean(v)) {
    fprintf(fp, "%s", mjs_get_bool(mjs, v) ? "true" : "false");
  } else if (mjs_is_string(v)) {
    size_t size;
    const char *s = mjs_get_string(mjs, &v, &size);
    printf("%.*s", (int) size, s);
  } else if (mjs_is_array(v)) {
    fprintf(fp, "<array>");
  } else if (mjs_is_object(v)) {
    fprintf(fp, "<object>");
  } else if (mjs_is_foreign(v)) {
    fprintf(fp, "<foreign_ptr@%lx>", (unsigned long) mjs_get_ptr(mjs, v));
  } else if (mjs_is_function(v)) {
    fprintf(fp, "<function@%d>", (int) mjs_get_func_addr(v));
  } else if (mjs_is_null(v)) {
    fprintf(fp, "null");
  } else if (mjs_is_undefined(v)) {
    fprintf(fp, "undefined");
  } else {
    fprintf(fp, "(unknown value type %" INT64_FMT ") ", (int64_t) v);
  }
}

#if MJS_ENABLE_DEBUG

MJS_PRIVATE const char *opcodetostr(uint8_t opcode) {
  static const char *names[] = {
      "NOP",       "DROP",       "DUP",        "SWAP",        "JMP",
      "JMP_BACK",  "JMP_TRUE",   "JMP_FALSE",  "FIND_SCOPE",  "PUSH_SCOPE",
      "PUSH_STR",  "PUSH_TRUE",  "PUSH_FALSE", "PUSH_INT",    "PUSH_DBL",
      "PUSH_NULL", "PUSH_UNDEF", "PUSH_OBJ",   "PUSH_ARRAY",  "PUSH_FUNC",
      "PUSH_THIS", "GET",        "CREATE",     "EXPR",        "APPEND",
      "SET_ARG",   "NEW_SCOPE",  "DEL_SCOPE",  "CALL",        "RETURN",
      "LOOP_ADDR", "BREAK",      "CONTINUE",   "SETRETVAL",   "EXIT",
      "BCODE_HDR", "SET_THIS",   "ARGS",       "FOR_IN_NEXT",
  };
  const char *name = "UNKNOWN OPCODE";
  assert(ARRAY_SIZE(names) == OP_MAX);
  if (opcode < ARRAY_SIZE(names)) name = names[opcode];
  return name;
}

void mjs_disasm(const uint8_t *code, size_t len, FILE *fp) {
  size_t i, start = 0;
  mjs_header_item_t map_offset = 0, total_size = 0;

  for (i = 0; i < len; i++) {
    fprintf(fp, "\t%-3u %-8s", (unsigned) i, opcodetostr(code[i]));

    if (map_offset > 0 && i == start + map_offset) {
      i = start + total_size - 1;
      fputc('\n', fp);
      continue;
    }

    switch (code[i]) {
      case OP_PUSH_FUNC: {
        int llen, n = varint_decode(&code[i + 1], &llen);
        fprintf(fp, " %04u", (unsigned) n);
        i += llen;
        break;
      }
      case OP_PUSH_INT: {
        int llen;
        unsigned long n = varint_decode(&code[i + 1], &llen);
        fprintf(fp, "\t%lu", n);
        i += llen;
        break;
      }
      case OP_SET_ARG: {
        int llen1, llen2, n, arg_no = varint_decode(&code[i + 1], &llen1);
        n = varint_decode(&code[i + llen1 + 1], &llen2);
        fprintf(fp, "\t[%.*s] %d", n, code + i + 1 + llen1 + llen2, arg_no);
        i += llen1 + llen2 + n;
        break;
      }
      case OP_PUSH_STR:
      case OP_PUSH_DBL: {
        int llen, n = varint_decode(&code[i + 1], &llen);
        fprintf(fp, "\t[%.*s]", n, code + i + 1 + llen);
        i += llen + n;
        break;
      }
      case OP_JMP_BACK:
        fprintf(fp, "\t%04u", (unsigned) i - code[i + 1]);
        i++;
        break;
      case OP_JMP:
      case OP_JMP_TRUE:
      case OP_JMP_FALSE: {
        fprintf(fp, "\t%u", (unsigned) i + code[i + 1]);
        i++;
        break;
      }
      case OP_LOOP: {
        int l1, l2, n2, n1 = varint_decode(&code[i + 1], &l1);
        n2 = varint_decode(&code[i + l1 + 1], &l2);
        fprintf(fp, "\t%lu %lu", (unsigned long) i + n1,
                (unsigned long) i + n2);
        i += l1 + l2;
        break;
      }
      case OP_EXPR: {
        int op = code[i + 1];
        const char *name = "???";
        /* clang-format off */
        switch (op) {
          case TOK_DOT:       name = "."; break;
          case TOK_MINUS:     name = "-"; break;
          case TOK_PLUS:      name = "+"; break;
          case TOK_MUL:       name = "*"; break;
          case TOK_DIV:       name = "/"; break;
          case TOK_REM:       name = "%"; break;
          case TOK_XOR:       name = "^"; break;
          case TOK_AND:       name = "&"; break;
          case TOK_OR:        name = "|"; break;
          case TOK_LSHIFT:    name = "<<"; break;
          case TOK_RSHIFT:    name = ">>"; break;
          case TOK_URSHIFT:   name = ">>>"; break;
          case TOK_UNARY_MINUS:   name = "- (unary)"; break;
          case TOK_UNARY_PLUS:    name = "+ (unary)"; break;
          case TOK_TILDA:     name = "~"; break;
          case TOK_EQ:        name = "=="; break;
          case TOK_NE:        name = "!="; break;
          case TOK_EQ_EQ:     name = "==="; break;
          case TOK_NE_NE:     name = "!=="; break;
          case TOK_LT:        name = "<"; break;
          case TOK_GT:        name = ">"; break;
          case TOK_LE:        name = "<="; break;
          case TOK_GE:        name = ">="; break;
          case TOK_ASSIGN:    name = "="; break;
          case TOK_POSTFIX_PLUS:  name = "++ (postfix)"; break;
          case TOK_POSTFIX_MINUS: name = "-- (postfix)"; break;
          case TOK_MINUS_MINUS:   name = "--"; break;
          case TOK_PLUS_PLUS:     name = "++"; break;
          case TOK_LOGICAL_AND:   name = "&&"; break;
          case TOK_LOGICAL_OR:    name = "||"; break;
          case TOK_KEYWORD_TYPEOF:  name = "typeof"; break;
          case TOK_PLUS_ASSIGN:     name = "+="; break;
          case TOK_MINUS_ASSIGN:    name = "-="; break;
          case TOK_MUL_ASSIGN:      name = "*="; break;
          case TOK_DIV_ASSIGN:      name = "/="; break;
          case TOK_REM_ASSIGN:      name = "%="; break;
          case TOK_XOR_ASSIGN:      name = "^="; break;
          case TOK_AND_ASSIGN:      name = "&="; break;
          case TOK_OR_ASSIGN:       name = "|="; break;
          case TOK_LSHIFT_ASSIGN:   name = "<<="; break;
          case TOK_RSHIFT_ASSIGN:   name = ">>="; break;
          case TOK_URSHIFT_ASSIGN:  name = ">>>="; break;
        }
        /* clang-format on */
        fprintf(fp, "\t%s", name);
        i++;
        break;
      }
      case OP_BCODE_HEADER: {
        start = i;
        memcpy(&total_size, &code[i + 1], sizeof(total_size));
        memcpy(&map_offset,
               &code[i + 1 + MJS_HDR_ITEM_MAP_OFFSET * sizeof(total_size)],
               sizeof(map_offset));
        i += sizeof(mjs_header_item_t) * MJS_HDR_ITEMS_CNT;
        fprintf(fp, "\t[%s] end:%lu map_offset: %lu", &code[i + 1],
                (unsigned long) start + total_size,
                (unsigned long) start + map_offset);
        i += strlen((char *) (code + i + 1)) + 1;
        break;
      }
    }
    fputc('\n', fp);
  }
}

static void mjs_dump_obj_stack(const char *name, const struct mbuf *m,
                               struct mjs *mjs, FILE *fp) {
  size_t i, n;
  n = mjs_stack_size(m);
  fprintf(fp, "  %12s (%d elems): ", name, (int) n);
  for (i = 0; i < n; i++) {
    fprintf(fp, " [");
    mjs_fprintf(((mjs_val_t *) m->buf)[i], mjs, fp);
    fprintf(fp, "]");
  }
  fprintf(fp, "\n");
}

void mjs_dump(struct mjs *mjs, int do_disasm, FILE *fp) {
  fprintf(fp, "------- MJS VM DUMP BEGIN\n");
  mjs_dump_obj_stack("DATA_STACK", &mjs->stack, mjs, fp);
  mjs_dump_obj_stack("CALL_STACK", &mjs->call_stack, mjs, fp);
  mjs_dump_obj_stack("SCOPES", &mjs->scopes, mjs, fp);
  mjs_dump_obj_stack("LOOP_OFFSETS", &mjs->loop_addresses, mjs, fp);
  if (do_disasm) {
    fprintf(fp, "  CODE:\n");
    mjs_disasm((uint8_t *) mjs->bcode.buf, mjs->bcode.len, fp);
  }
  fprintf(fp, "------- MJS VM DUMP END\n");
}
#endif
#ifdef MJS_MODULE_LINES
#line 1 "mjs/src/mjs_varint.c"
#endif
/*
 * Copyright (c) 2014 Cesanta Software Limited
 * All rights reserved
 */

/* Amalgamated: #include "mjs/src/mjs_varint.h" */
/* Amalgamated: #include "mjs/src/mjs_internal.h" */

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*
 * Strings in AST are encoded as tuples (length, string).
 * Length is variable-length: if high bit is set in a byte, next byte is used.
 * Small string length (less then 128 bytes) is encoded in 1 byte.
 */
MJS_PRIVATE int64_t varint_decode(const uint8_t *p, int *llen) {
  int64_t i = 0, num = 0;

  do {
    /*
     * Each byte of varint contains 7 bits, in little endian order.
     * MSB is a continuation bit: it tells whether next byte is used.
     */
    num |= ((int64_t)(p[i] & 0x7f)) << (7 * i);
    /*
     * First we increment i, then check whether it is within boundary and
     * whether decoded byte had continuation bit set.
     */
  } while ((size_t) ++i < sizeof(int64_t) && (p[i - 1] & 0x80));
  *llen = i;

  return num;
}

/* Return number of bytes to store length */
MJS_PRIVATE int varint_llen(int64_t num) {
  int n = 0;

  do {
    n++;
  } while (num >>= 7);

  return n;
}

MJS_PRIVATE int varint_encode(int64_t num, uint8_t *p) {
  int i, llen = varint_llen(num);

  for (i = 0; i < llen; i++) {
    p[i] = (num & 0x7f) | (i < llen - 1 ? 0x80 : 0);
    num >>= 7;
  }

  return llen;
}

#if defined(__cplusplus)
}
#endif /* __cplusplus */
#endif /* MJS_EXPORT_INTERNAL_HEADERS */
