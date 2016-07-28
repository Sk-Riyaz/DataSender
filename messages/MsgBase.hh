#ifndef __MSGBASE_HH__
#define __MSGBASE_HH__

#include "CommonIncludes.hh"

class MsgBase
{
   protected:
      MsgBase( );
      MsgBase( MESSAGE_TYPE msgType, unsigned int msgId );
      ~MsgBase( );

      MESSAGE_TYPE mMsgType;
      unsigned int mMsgId;

   public:
      MESSAGE_TYPE getMsgType( ) const;
      virtual void reset( ) = 0;
      virtual unsigned int getMsgId( ) = 0;
};

#endif
