#ifndef __LOG_HANDLER_HH__
#define __LOG_HANDLER_HH__

#include "CommonIncludes.hh"

class LogHandler
{
   private:
      LogHandler( );
      ~LogHandler( );

      static LogHandler* m_pInstance;
      Queue< MsgBase * > *queueObj;

      FILE *fp;

   private:
      int writeToFile( Char< MAX_LOG_SIZE> logMsg );

   public:
      static LogHandler* getInstance( );
      static void destroyInstance( );
      static void *process( void *arg );
      int start( );
      int processMsg( MsgBase *incomingMsg );
      void putq( MsgBase *msg, int waitTime = 0 );
      MsgBase *getq( );
};

#define LOG_HANDLER LogHandler::getInstance( )

#endif
