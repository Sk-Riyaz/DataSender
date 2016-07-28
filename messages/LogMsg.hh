#ifndef __LOGMSG_HH__
#define __LOGMSG_HH__

#include "MsgBase.hh"

class LogMsg: public MsgBase
{
   private:
      LogMsg( );

      unsigned int msgId;
      Char< MAX_LOG_SIZE > mLogStr;

   public:
      LogMsg( unsigned int i );
      ~LogMsg( );
      void reset( );
      void setStr( const Char< MAX_LOG_SIZE >&logStr );
      const Char< MAX_LOG_SIZE >& getStr( ) const;
      unsigned int getMsgId( );
};

#endif
