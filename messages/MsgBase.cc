#include "MsgBase.hh"

MsgBase::MsgBase( )
{
   print(INFO, "MsgBase::Constructor");
}

MsgBase::MsgBase(MESSAGE_TYPE msgType, unsigned int msgId):
               mMsgType( msgType ),
               mMsgId( msgId )
{
   print(INFO, "MsgBase::Constructor MessageType = %u, MsgId = %d",
         mMsgType, mMsgId);
}

MsgBase::~MsgBase( )
{
   print(INFO, "MsgBase::Destructor");
}

MESSAGE_TYPE
MsgBase::getMsgType( ) const
{
   return mMsgType;
}

#if 0
void
MsgBase::setMsgType( MESSAGE_TYPE msgType )
{
   mMsgType = msgType;
}
#endif

