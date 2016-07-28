#ifndef __LOGMSG_POOL_HH__
#define __LOGMSG_POOL_HH__

#include "MsgBasePool.hh"
#include "LogMsg.hh"

//class LogMsg;

class LogMsgPool: 
   	public MsgBasePool
{
   private:
      LogMsgPool( );
      ~LogMsgPool( );
      
      static LogMsgPool *mInstance;

      LogMsg *LogMsgObj[MAX_NUMBER_OF_OBJECTS];
      bool isLogMsgObjAvailable[MAX_NUMBER_OF_OBJECTS];

   public:
      static LogMsgPool *getInstance( );
      static void destroyInstance( );

      void createObjects( );
      MsgBase *getObj( );
      bool releaseObj( MsgBase *pObj );
      bool releaseObj( unsigned int msgId );
};

#define LOG_MSG_POOL LogMsgPool::getInstance()

#endif
