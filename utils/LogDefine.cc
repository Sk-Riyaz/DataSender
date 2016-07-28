#include<stdio.h>
#include<stdarg.h>
#include<cstring>
#include<sys/time.h>
#include<time.h>

#include "LogDefine.hh"
#include "LogHandler.hh"
#include "MsgPoolInterface.hh"
#include "MsgBase.hh"
#include "LogMsg.hh"

LOG_TYPE iLoglevel = CRITICAL;

void logInfo( LOG_TYPE eLogType, const char *functionName, const char *format, ... )
{
   if( eLogType < iLoglevel )
   {
      return;
   }

   char logStr[MAX_LOG_SIZE];
   memset( logStr, 0, MAX_LOG_SIZE );

   char tempTimeStr[MAX_TIME_LEN_STR_SIZE];
   memset( tempTimeStr, 0, MAX_TIME_LEN_STR_SIZE );
   struct timeval microSec;
   time_t nowTime;
   nowTime = time(NULL);
   ::gettimeofday( &microSec, NULL );
   strftime( tempTimeStr, MAX_TIME_LEN_STR_SIZE, 
         "%d-%m-%Y %H:%M:%S", localtime(&nowTime) );
   long int millisecs = microSec.tv_usec/1000;
   snprintf( logStr, MAX_LOG_SIZE, "%s.%ld", tempTimeStr, millisecs );

   char logLevel[MAX_LOG_LEVEL_STR_SIZE];
   memset( logLevel, 0, MAX_LOG_LEVEL_STR_SIZE );
   switch( eLogType )
   {
      case INFO:
         strncpy( logLevel, ":INFO:", MAX_LOG_LEVEL_STR_SIZE );
         break;

      case DEBUG:
         strncpy( logLevel, ":DEBUG:", MAX_LOG_LEVEL_STR_SIZE );
         break;

      case CRITICAL:
         strncpy( logLevel, ":DEBUG:", MAX_LOG_LEVEL_STR_SIZE );
         break;

      default:
         break;
   }
   STRNCAT( logStr, logLevel, MAX_LOG_SIZE );
   STRNCAT( logStr, functionName, MAX_LOG_SIZE );

   va_list vl;
   va_start( vl, format );
   char tempBuf[MAX_LOG_SIZE];
   memset( tempBuf, 0, MAX_LOG_SIZE );
   vsprintf ( tempBuf, format, vl );
   va_end(vl);

   STRNCAT( logStr, tempBuf, MAX_LOG_SIZE );
   STRNCAT( logStr, "\n", MAX_LOG_SIZE );
   LogMsg *logMsgObj = dynamic_cast< LogMsg * >
      (MSG_POOL_INTERFACE->getMsg( MESSAGE_TYPE_LOG ));
   if( 0 != logMsgObj )
   {
      logMsgObj->setStr( logStr );
      LOG_HANDLER->putq( logMsgObj );
   }
   else
   {
      std::cout<< "Unable to get the LogMsg" << std::endl;
   }
}

#if 0
int main()
{
   print( DEBUG, "Hello darlz");
}
#endif
