#include "LogMsgPool.hh"

LogMsgPool *
LogMsgPool::mInstance = 0;

LogMsgPool::LogMsgPool():
            MsgBasePool( )
{
   print(DEBUG, "Constructor");
   createObjects( );
}

LogMsgPool::~LogMsgPool()
{
   print(DEBUG, "Destructor");
}

LogMsgPool *
LogMsgPool::getInstance()
{
   if( 0 == mInstance )
   {
      mInstance = new LogMsgPool( ); 
   }
   return mInstance;
}

void
LogMsgPool::destroyInstance( )
{
   if( mInstance )
   {
      delete mInstance;
   }
}

void
LogMsgPool::createObjects( )
{
   for( static int i=0; i<MAX_NUMBER_OF_OBJECTS; i++ )
   {
      LogMsg *temp = new LogMsg(i);
      LogMsgObj[i] = temp;
      isLogMsgObjAvailable[i] = true;
   }
}

MsgBase *
LogMsgPool::getObj( )
{
   MsgBase *retObj = 0;
   for( int i=0; i<MAX_NUMBER_OF_OBJECTS; i++ )
   {
      if( isLogMsgObjAvailable[i] )
      {
         retObj = LogMsgObj[i];
         isLogMsgObjAvailable[i] = false;
         break;
      }
   }
   return retObj;
}

bool
LogMsgPool::releaseObj( MsgBase *pObj )
{
   if( !isLogMsgObjAvailable[pObj->getMsgId()] )
   {
      pObj->reset();
      isLogMsgObjAvailable[pObj->getMsgId()] = true;
      return true;
   }
   else
   {
      std::cout<< "LOG Message is already released:"<< pObj << std::endl;
   }
   return false;
}

bool
LogMsgPool::releaseObj( unsigned int msgId )
{
   if( msgId < MAX_NUMBER_OF_OBJECTS )
   {
      return releaseObj( LogMsgObj[msgId] );
   }
   else
   {
      std::cout<< "Unknown msgId:"<< msgId << std::endl;
   }
   return false;
}
