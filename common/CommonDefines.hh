#ifndef __COMMON_DEFINES_HH__
#define __COMMON_DEFINES_HH__

#define UNUSED_ARG( arg ) (void) arg

#define STRNCPY( dest, src, maxLen ) \
{\
   if( 0 != dest || 0 != src )\
   {\
      unsigned int srcLen = strlen( src );\
      if( srcLen )\
      {\
         if( srcLen < maxLen )\
         {\
            strncpy( dest, src, maxLen );\
            dest[strlen(dest)] = '\0';\
         }\
         else\
         {\
            strncpy( dest, src, maxLen-1 );\
            dest[strlen(dest)] = '\0';\
         }\
      }\
      else\
      {\
         dest[strlen(dest)] = '\0';\
      }\
   }\
}

#define STRNCAT( dest, src, maxLen ) \
{\
   if( 0 != dest || 0 != src )\
   {\
      unsigned int srcLen = strlen( src );\
      unsigned int destLen = strlen( dest );\
      if( srcLen )\
      {\
	 unsigned int canCpyLen = maxLen-destLen;\
         if( srcLen < canCpyLen )\
         {\
            strncat( dest, src, canCpyLen );\
            dest[strlen(dest)] = '\0';\
         }\
         else\
         {\
            strncpy( dest, src, canCpyLen-1 );\
            dest[strlen(dest)] = '\0';\
         }\
      }\
      else\
      {\
         dest[destLen] = '\0';\
      }\
   }\
}

#define MAX_NUMBER_OF_OBJECTS 50
#define MAX_FILE_NAME 100
#define MAX_DATA_SIZE 30000

//commonEnumns
enum MESSAGE_TYPE
{
   MESSAGE_TYPE_UNKNOWN = 0,
   MESSAGE_TYPE_LOG = 1,
   MESSAGE_TYPE_DATA = 2,
   MESSAGE_TYPE_END
};

//commonUsageFunctions

long int getCurrentTimeInSec( );
double getCurrentTimeWithMicroSec( );
double getCurrentTimeWithMilliSec( );
long long int getCurrentTimeInMicroSec( );
long long int getCurrentTimeInMilliSec( );

#endif
