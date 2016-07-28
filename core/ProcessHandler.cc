#include "ProcessHandler.hh"
#include "DataHandler.hh"

#undef __THREAD_NAME__ 
#define __THREAD_NAME__ "PCH" 

ProcessHandler *
ProcessHandler::m_pInstance = 0;

ProcessHandler::ProcessHandler( )
{
   queueObj = new Queue< MsgBase * >( );
   print(DEBUG, "Constructor");
}

ProcessHandler::~ProcessHandler( )
{
   if( queueObj )
   {
      delete queueObj;
   }
   print(DEBUG, "Destructor");
}

ProcessHandler *
ProcessHandler::getInstance( )
{
   if( 0 == m_pInstance )
   {
      m_pInstance = new ProcessHandler;
   }
   return m_pInstance;
}

void
ProcessHandler::destroyInstance( )
{
   if( m_pInstance )
   {
      delete m_pInstance;
   }
}

void *
ProcessHandler::process( void * )
{
   PROCESS_HANDLER->start( );
   pthread_exit(NULL);
}

void
ProcessHandler::start( )
{
   while( true )
   {
      Char< MAX_FILE_NAME >fileName = "0001.mp3";
      sendData( fileName );
      pthread_exit((void*)0);
#if 1
      MsgBase *incomingMsg = getq( );
      if( NULL != incomingMsg || 0 != incomingMsg )
      {
         processMsg( incomingMsg );
         MSG_POOL_INTERFACE->releaseMsg( incomingMsg );
         //sleep( 2 );
      }
      else
      {
         print( CRITICAL, "msgQueueCount:%u", queueObj->size( ) );
         sleep( 12 );
      }
#endif
   }
}

void
ProcessHandler::processMsg( MsgBase *incomingMsg )
{
   if( incomingMsg != 0 )
   {
      //print( CRITICAL, "Message:%d", incomingMsg->getMsgType( ) );
   }
}

int
ProcessHandler::sendData( Char<MAX_FILE_NAME>&fileName )
{
   FILE *in;
   Char< MAX_FILE_NAME >ofileName="001.mp3";
   in = fopen(ofileName.get( ), "rb");
   if( in == NULL )
   {   
      print( ERROR, "unable ot open file" );
      return -1;
   }   
   fseek (in , 0 , SEEK_END);
   size_t lSize = ftell (in);
   rewind (in);
   unsigned char buffer[481000];
   memset(buffer, 0, 481000 );
   cout<<lSize<<endl;
   //while( in != NULL )
   {   
      if( fread (buffer,1,lSize, in) != lSize )
      {
         print( CRITICAL, "readError of file:%s", ofileName.get( ) );
      }
      //memset(buffer, 0, lSize );
      //in = in+i;
      //i++;
   }
   unsigned long i = 0;
   while( i < lSize )
   {
      //out = fopen("0012.mp3", "ab");
      char temp[MAX_DATA_SIZE];
      memset( temp, 0, MAX_DATA_SIZE );
      unsigned int max = MAX_DATA_SIZE;
      if( lSize -i < max )
      {
         max = lSize -i;
      }
      memcpy( temp, buffer+i, max );
      i += max;
      //i = i+fwrite( temp, sizeof(char), MAX_DATA_SIZE, out );
      //fclose(out);
      DataMsg *pDataMsg = dynamic_cast< DataMsg * >
         ( MSG_POOL_INTERFACE->getMsg( MESSAGE_TYPE_DATA ) );
      if( 0 == pDataMsg )
      {
         print( ERROR, "unable to get pDataMsg from pool" );
         return 0;
      }
      pDataMsg->setFileName( fileName );
      pDataMsg->setFileData( temp, MAX_DATA_SIZE );
      pDataMsg->setDataSize( max );
      std::cout<<"allcoated msg:"<<pDataMsg
         <<"msgId:"<<pDataMsg->getMsgId( )
         //<<"data.len( ):"<<pDataMsg->getFileData( ).len( )
         <<"templen:"<<strlen(temp)<<std::endl;
      DATA_HANDLER->putq( pDataMsg );
   }
#if 0
   while( buffer[i] != '\0' && i < lSize)
   {
      Char< MAX_DATA_SIZE >data( (char*)buffer+i, (char*)buffer+i+MAX_DATA_SIZE-1 );
      i = i+MAX_DATA_SIZE;
      DataMsg *pDataMsg = dynamic_cast< DataMsg * >
         ( MSG_POOL_INTERFACE->getMsg( MESSAGE_TYPE_DATA ) );
      if( 0 == pDataMsg )
      {
         print( ERROR, "unable to get pDataMsg from pool" );
         return 0;
      }
      pDataMsg->setFileName( fileName );
      pDataMsg->setFileData( data );
      std::cout<<"allcoated msg:"<<pDataMsg<<std::endl;
      DATA_HANDLER->putq( pDataMsg );
      //sleep(1);
   }
#endif
   //size_t i = lSize-128;
   //size_t i = lSize-128+3;
   //cout<<buffer+lSize-128<<endl;
   //while( i < lSize-128+33 )
   {   
      //cout<<buffer[i]<<"";
      //++i;
   } 
   cout<<endl;
   fclose(in);
   return 0;
}

void
ProcessHandler::putq( MsgBase *msg, int waitTime )
{
   queueObj->putq( msg, waitTime );
}

MsgBase *
ProcessHandler::getq( )
{
   return queueObj->getq( );
}
