#include "LogHandler.hh"
#include "ProcessHandler.hh"
#include "MsgPoolInterface.hh"
#include "LogMsg.hh"

#undef __THREAD_NAME__
#define __THREAD_NAME__ "LOG"

LogHandler *
LogHandler::m_pInstance = 0;

LogHandler::LogHandler( )
{
   queueObj = new Queue< MsgBase * >( );
   fp = fopen( "logfile.log", "a+" );
   print(DEBUG, "Constructor");
}

LogHandler::~LogHandler( )
{
   if( queueObj )
   {
      delete queueObj;
   }
   if( NULL != fp )
   {
      fclose( fp );
   }
   print(DEBUG, "Destructor");
}

LogHandler *
LogHandler::getInstance( )
{
   if( 0 == m_pInstance )
   {
      m_pInstance = new LogHandler;
   }
   return m_pInstance;
}

void
LogHandler::destroyInstance( )
{
   if( m_pInstance )
   {
      delete m_pInstance;
   }
}

void
LogHandler::putq( MsgBase *msg, int waitTime )
{
   queueObj->putq( msg, waitTime );
}

MsgBase *
LogHandler::getq( )
{
   return queueObj->getq( );
}

void *
LogHandler::process( void *arg )
{
   UNUSED_ARG( arg );
   LOG_HANDLER->start( );
   return 0;
}

int
LogHandler::start( )
{
   while( true )
   {
      MsgBase *incomingMsg = getq( );
      if( NULL != incomingMsg || 0 != incomingMsg )
      {
         processMsg( incomingMsg );
         MSG_POOL_INTERFACE->releaseMsg( incomingMsg );
         sleep( 2 );
      }
      else
      {
         print(CRITICAL, "msgQueueCount:%u", queueObj->size( ) );
         sleep( 2 );
      }
   }
   return 0;
}

int
LogHandler::processMsg( MsgBase *incomingMsg )
{
   if( incomingMsg != 0 )
   {
      LogMsg *logMsg = dynamic_cast< LogMsg * >( incomingMsg );
      if( 0 == logMsg )
      {
         printf("Unable to cast the Message:%d\n", 
               incomingMsg->getMsgType( ) );
         return 0;
      }
      writeToFile( logMsg->getStr( ) );
   }
   return 0;
}

int
LogHandler::writeToFile( Char<MAX_LOG_SIZE> logMsg )
{
   int retVal = 0;
   if( NULL != fp )
   {
      fprintf( fp, "%s", logMsg.get( ) );
      fflush( fp );
   }
   else
   {
      printf( "File pointer is null\n" );
      retVal = -1;
   }
   return retVal;
}



