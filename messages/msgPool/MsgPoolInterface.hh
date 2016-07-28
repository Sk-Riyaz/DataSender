#ifndef __MSG_POOL_INTERFACE_HH__
#define __MSG_POOL_INTERFACE_HH__

#include "MsgBasePool.hh"
#include "MsgBase.hh"

class MsgBase;

class MsgPoolInterface
{
   private:
      MsgPoolInterface( );
      ~MsgPoolInterface( );

      static MsgPoolInterface *mInstance;

   public:
      static MsgPoolInterface *getInstance( );
      static void destroyInstance( );
      MsgBase *getMsg( MESSAGE_TYPE mType );
      void createAllTypesOfMessages( );
      bool releaseMsg( MsgBase *obj );
      bool releaseMsg( MESSAGE_TYPE mType, unsigned int msgId );
};

#define MSG_POOL_INTERFACE MsgPoolInterface::getInstance( )

#endif
