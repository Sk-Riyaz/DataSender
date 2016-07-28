#ifndef __MSG_BASE_POOL_HH__
#define __MSG_BASE_POOL_HH__

#include "MsgBase.hh"
#include "CommonIncludes.hh"
#include "Char.hh"

class MsgBase;

class MsgBasePool
{
   protected:
      MsgBasePool( );
      virtual ~MsgBasePool( );

   public:

      virtual MsgBase *getObj( ) = 0;
      virtual bool releaseObj( MsgBase *pObj ) = 0;
      virtual bool releaseObj( unsigned int msgId ) = 0;
};

#endif
