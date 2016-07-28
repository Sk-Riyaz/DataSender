#include "MsgPoolInterface.hh"
#include "LogMsgPool.hh"
#include "DataMsgPool.hh"

MsgPoolInterface *
MsgPoolInterface::mInstance = 0;

MsgPoolInterface::MsgPoolInterface( )
{
   print(DEBUG, "Constructor");
   createAllTypesOfMessages( );
}

MsgPoolInterface::~MsgPoolInterface( )
{
   print(DEBUG, "Destructor");
}

MsgPoolInterface *
MsgPoolInterface::getInstance( )
{
   if( 0 == mInstance )
   {
      mInstance = new MsgPoolInterface;
   }
   return mInstance;
}

void
MsgPoolInterface::destroyInstance( )
{
   if( mInstance )
      delete mInstance;
}

void
MsgPoolInterface::createAllTypesOfMessages( )
{
   std::cout<<__FUNCTION__<<":"<<__LINE__<<std::endl;
   LOG_MSG_POOL;
   std::cout<<__FUNCTION__<<":"<<__LINE__<<std::endl;
   DATA_MSG_POOL;
   std::cout<<__FUNCTION__<<":"<<__LINE__<<std::endl;
}

MsgBase *
MsgPoolInterface::getMsg( MESSAGE_TYPE mType )
{
   MsgBase *pRetVal = 0;
   switch( mType )
   {
      case MESSAGE_TYPE_LOG:
         pRetVal = LOG_MSG_POOL->getObj( );
         break;

      case MESSAGE_TYPE_DATA:
         pRetVal = DATA_MSG_POOL->getObj( );
         break;

      default:
         print(CRITICAL, "Unhadled type");
   }
   return pRetVal;
}

bool
MsgPoolInterface::releaseMsg( MsgBase *releaseObject )
{
   bool retVal = false;
   if( 0 != releaseObject )
   {
      switch( releaseObject->getMsgType( ) )
      {
         case MESSAGE_TYPE_LOG:
            retVal = LOG_MSG_POOL->releaseObj( releaseObject );
         std::cout<<__FUNCTION__<<":"<<__LINE__<<"relase 1"<<std::endl;
            break;

         case MESSAGE_TYPE_DATA:
            retVal = DATA_MSG_POOL->releaseObj( releaseObject );
         std::cout<<__FUNCTION__<<":"<<__LINE__<<"relase 2"<<std::endl;
            break;

         default:
            print(CRITICAL, "Unhadled type");
      }
   }
   return retVal;
}

bool
MsgPoolInterface::releaseMsg( MESSAGE_TYPE eType, unsigned int msgId )
{
   bool retVal = false;
   switch( eType )
   {
      case MESSAGE_TYPE_LOG:
         retVal = LOG_MSG_POOL->releaseObj( msgId );
         std::cout<<__FUNCTION__<<":"<<__LINE__<<"relase 1"<<std::endl;
         break;

      case MESSAGE_TYPE_DATA:
         retVal = DATA_MSG_POOL->releaseObj( msgId );
         std::cout<<__FUNCTION__<<":"<<__LINE__<<"relase 2"<<std::endl;
         break;

      default:
         print(CRITICAL, "Unhadled type");
   }
   return retVal;
}

