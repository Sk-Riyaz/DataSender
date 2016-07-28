#include "DataMsgPool.hh"

DataMsgPool *
DataMsgPool::mInstance = 0;

DataMsgPool::DataMsgPool():
            MsgBasePool( )
{
   print(DEBUG, "Constructor");
   createObjects( );
}

DataMsgPool::~DataMsgPool()
{
   print(DEBUG, "Destructor");
}

DataMsgPool *
DataMsgPool::getInstance()
{
   if( 0 == mInstance )
   {
      mInstance = new DataMsgPool( ); 
   }
   return mInstance;
}

void
DataMsgPool::destroyInstance( )
{
   if( mInstance )
   {
      delete mInstance;
   }
}

void
DataMsgPool::createObjects( )
{
   for( static int i=0; i<MAX_NUMBER_OF_OBJECTS; i++ )
   {
      DataMsg *temp = new DataMsg(i);
      DataMsgObj[i] = temp;
      isDataMsgObjAvailable[i] = true;
   }
}

MsgBase *
DataMsgPool::getObj( )
{
   MsgBase *retObj = 0;
   for( int i=0; i<MAX_NUMBER_OF_OBJECTS; i++ )
   {
      if( isDataMsgObjAvailable[i] )
      {
         retObj = DataMsgObj[i];
         isDataMsgObjAvailable[i] = false;
         break;
      }
   }
   return retObj;
}

bool
DataMsgPool::releaseObj( MsgBase *pObj )
{
   if( !isDataMsgObjAvailable[pObj->getMsgId()] )
   {
      pObj->reset();
      isDataMsgObjAvailable[pObj->getMsgId()] = true;
      return true;
   }
   else
   {
      std::cout<< "Message is already released:"<< pObj << std::endl;
   }
   return false;
}

bool
DataMsgPool::releaseObj( unsigned int msgId )
{
   if( msgId < MAX_NUMBER_OF_OBJECTS )
   {
      return releaseObj( DataMsgObj[msgId] );
   }
   else
   {
      std::cout<< "Unknown msgId:"<< msgId << std::endl;
   }
   return false;
}
