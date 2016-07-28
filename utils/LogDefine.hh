#ifndef __LOG_DEFINE_HH__
#define  __LOG_DEFINE_HH__
#include "CommonIncludes.hh"

enum LOG_TYPE
{
   INFO=0,
   DEBUG=1,
   CRITICAL=2,
   ERROR=3
};

#define MAX_LOG_SIZE 1000
#define MAX_LOG_LEVEL_STR_SIZE 20
#define MAX_TIME_LEN_STR_SIZE 30
#define MAX_FUNCTION_NAME 50
#define MAX_LINE_NUMBER_LEN 20

#undef __THREAD_NAME__
#define __THREAD_NAME__ ""

void logInfo( LOG_TYPE, const char *functionName, const char *format, ... );

#define print( logType, ... )\
{\
   char functionName[MAX_FUNCTION_NAME];\
   memset( functionName, 0, MAX_FUNCTION_NAME );\
   char lineStr[MAX_LINE_NUMBER_LEN];\
   memset( lineStr, 0, MAX_LINE_NUMBER_LEN );\
   snprintf( lineStr, MAX_LINE_NUMBER_LEN, "%d", __LINE__ );\
   char threadName[10];\
   memset( threadName, 0, 10 );\
   strncpy( threadName, __THREAD_NAME__, 10 );\
   snprintf( functionName, MAX_FUNCTION_NAME, "%s:%s:%s:", threadName, __FUNCTION__, lineStr );\
   logInfo( logType, functionName, __VA_ARGS__ );\
}


#endif
