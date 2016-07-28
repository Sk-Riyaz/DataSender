#ifndef __PROCESS_HANDLER__
#define __PROCESS_HANDLER__

#include "CommonIncludes.hh"
#include "CommonDefines.hh"

class ProcessHandler
{
   private:
      ProcessHandler( );
      ~ProcessHandler( );

      static ProcessHandler* m_pInstance;
      Queue< MsgBase * > *queueObj;

      MsgBase *getq( );
   public:
      static ProcessHandler* getInstance( );
      static void destroyInstance( );
      static void* process( void * );
      void start( );
      void processMsg( MsgBase *incomingMsg );
      void hello( const char *str );
      int sendData( Char<MAX_FILE_NAME>&fileName );
      void putq( MsgBase *msgObj, int waitTime = 0 );
};


#define PROCESS_HANDLER ProcessHandler::getInstance( )


#endif
