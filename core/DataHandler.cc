#include "DataHandler.hh"

#undef __THREAD_NAME__ 
#define __THREAD_NAME__ "DATA" 

DataHandler *
DataHandler::m_pInstance = 0;

DataHandler::DataHandler( )
{
   queueObj = new Queue< MsgBase * >( );
   print(DEBUG, "Constructor");
}

DataHandler::~DataHandler( )
{
   if( queueObj )
   {
      delete queueObj;
   }
   print(DEBUG, "Destructor");
}

DataHandler *
DataHandler::getInstance( )
{
   if( 0 == m_pInstance )
   {
      m_pInstance = new DataHandler;
   }
   return m_pInstance;
}

void
DataHandler::destroyInstance( )
{
   if( m_pInstance )
   {
      delete m_pInstance;
   }
}

void
DataHandler::putq( MsgBase *msg, int waitTime )
{
   queueObj->putq( msg, waitTime );
}

MsgBase *
DataHandler::getq( )
{
   return queueObj->getq( );
}

void *
DataHandler::process( void * )
{
   DATA_HANDLER->start( );
   pthread_exit(NULL);
   return 0;
}

void
DataHandler::start( )
{
   while( true )
   {
      MsgBase *incomingMsg = getq( );
      if( NULL != incomingMsg || 0 != incomingMsg )
      {
         processMsg( incomingMsg );
         MSG_POOL_INTERFACE->releaseMsg( incomingMsg );
      }
      else
      {
         print( CRITICAL, "msgQueueCount:%u", queueObj->size( ) );
         sleep( 1 );
      }
   }
}

void
DataHandler::processMsg( MsgBase *incomingMsg )
{
   if( incomingMsg != 0 )
   {
      DataMsg *pDataMsg = dynamic_cast< DataMsg * >( incomingMsg );
      if( 0 == pDataMsg )
      {
         print( CRITICAL, "unable to cast the Message:%d", incomingMsg->getMsgType( ) );
      }
      else
      {
         processDataMessage( pDataMsg );
      }
   }
}

int
DataHandler::processDataMessage( DataMsg *pDataMsg )
{
   print(CRITICAL, "function called-->");
   //printf("processDataMessage::function called-->\n");
   if( 0 == pDataMsg )
   {
      print( CRITICAL, "pDataMsg is NULL" );
      return -1;
   }
   writeDatatoFile( pDataMsg->getFileName( ), 
         pDataMsg->getFileData( ), pDataMsg->getDataSize( ) );
#if 0
   Name2Data::iterator it = mName2Data.find( pDataMsg->getFileName( ) );
   if( it != mName2Data.end( ) )
   {
      writeDatatoFile( it->first, it->second );
   }
   else
   {
      print( CRITICAL, "New File:%s", pDataMsg->getFileName( ).get( ) );
      mName2Data.insert( std::pair< Char< MAX_FILE_NAME >, 
            Char< MAX_DATA_SIZE >>( pDataMsg->getFileName( ), 
                               pDataMsg->getFileData( ) ) );
      writeDatatoFile( pDataMsg->getFileName( ), 
            pDataMsg->getFileData( ) );
   }
#endif
   return 0;
}

int
DataHandler::writeDatatoFile( Char< MAX_FILE_NAME >fileName, const char *data, size_t dataSize )
{
   print( DEBUG, "function called" );
   FILE *fp = fopen( fileName.get( ), "ab" );
   if( NULL == fp )
   {
      print( ERROR, "unable to open file: %s", fileName.get( ) );
      return -1;
   }

   unsigned char charData[MAX_DATA_SIZE];
   memset( charData, 0, MAX_DATA_SIZE );
   memcpy( charData, data, dataSize );
   unsigned int i = fwrite( charData, sizeof(char), dataSize, fp );
   print( DEBUG, "Data written:%u", i );
   fclose( fp );
   return 0;
}


