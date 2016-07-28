#ifndef __DATA_MSG_POOL_HH__
#define __DATA_MSG_POOL_HH__

#include "MsgBasePool.hh"
#include "DataMsg.hh"

class DataMsg;

class DataMsgPool: 
   	public MsgBasePool
{
   private:
      DataMsgPool( );
      ~DataMsgPool( );
      
      static DataMsgPool *mInstance;

      DataMsg *DataMsgObj[MAX_NUMBER_OF_OBJECTS];
      bool isDataMsgObjAvailable[MAX_NUMBER_OF_OBJECTS];

   public:
      static DataMsgPool *getInstance( );
      static void destroyInstance( );

      void createObjects( );
      MsgBase *getObj( );
      bool releaseObj( MsgBase *pObj );
      bool releaseObj( unsigned int msgId );
};

#define DATA_MSG_POOL DataMsgPool::getInstance()

#endif
