#include "ProcessHandler.hh"
#include "LogHandler.hh"
#include "DataHandler.hh"
#include "Main.hh"

Main *
Main::m_pInstance = 0;

Main::Main( )
{
   std::cout<<"constructor"<<std::endl;
   print(DEBUG, "constructor");
   std::cout<<"constructorin"<<std::endl;
}

Main::~Main( )
{
   print(DEBUG, "destructor");
}

Main *
Main::getInstance( )
{
   if( 0 == m_pInstance )
   {
   std::cout<<"constructorin"<<std::endl;
      m_pInstance = new Main( );
   }
   return m_pInstance;
}

void
Main::destroyInstance( )
{
   if( m_pInstance )
      delete m_pInstance;
}

void
Main::instantiateProcessess( )
{
   MSG_POOL_INTERFACE;
   std::cout<<"constructorout"<<std::endl;
   LOG_HANDLER;
   PROCESS_HANDLER;
   DATA_HANDLER;
}

void
Main::destroyProcessess( )
{
   MsgPoolInterface::destroyInstance( );
   LogHandler::destroyInstance( );
   ProcessHandler::destroyInstance( );
   DataHandler::destroyInstance( );
}

int
Main::start( )
{
   instantiateProcessess( );
   print( DEBUG, "Done" );
   return 0;
}

int
Main::killAll( )
{
   destroyProcessess( );
   return 0;
}

int
Main::process( )
{
   pthread_t processHandler,logHandler, dataHandler;
   void* (*call)( void * );
   call = LOG_HANDLER->process;
   pthread_create( &logHandler, NULL, call, NULL );

   call = PROCESS_HANDLER->process;
   pthread_create( &processHandler, NULL, call, NULL );

   call = DATA_HANDLER->process;
   pthread_create( &dataHandler, NULL, call, NULL );
   
#if 0
   call = DUMMY_HANDLER->process;
   pthread_create( &dummyHandler, NULL, call, NULL );
   pthread_join(dummyHandler, NULL);
#endif

   pthread_join(processHandler, NULL);
   pthread_join(logHandler, NULL);
   print(DEBUG, "--------done-----");

   //while( true );
   return 0;
}

void signalHandler ( int signum )
{
   if ( signum == SIGINT || signum == SIGTERM )
   {   
      MAIN->killAll( );
      exit(EXIT_SUCCESS);
   }   
}

int main()
{
   signal(SIGINT, signalHandler);
   prctl ( PR_SET_NAME, "Main", 0, 0, 0 );
   MAIN->start( );
   MAIN->process( );
   raise ( SIGKILL );
   return 0;
}

