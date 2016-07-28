#include "LogMsg.hh"

LogMsg::LogMsg()
{
   mLogStr.clear();
   print(INFO, "LogMsg::Default Constructor");
}

LogMsg::LogMsg( unsigned int i ):
   MsgBase( MESSAGE_TYPE_LOG, i ),
   msgId( i )
{
   mLogStr.clear( );
   print(INFO, "LogMsg::Constructor-->%d",msgId);
}

LogMsg::~LogMsg()
{
   mLogStr.clear();
   print(INFO, "LogMsg::Destructor");
}

void
LogMsg::reset()
{
   mLogStr.clear( );
}

void
LogMsg::setStr( const Char< MAX_LOG_SIZE >&logStr )
{
   mLogStr = logStr;
}

const Char<MAX_LOG_SIZE>& 
LogMsg::getStr( ) const
{
   return mLogStr;
}

unsigned int
LogMsg::getMsgId( )
{
   return msgId;
}


