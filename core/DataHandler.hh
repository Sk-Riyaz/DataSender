#ifndef __DATA_HANDLER__
#define __DATA_HANDLER__

#include "CommonIncludes.hh"
#include "CommonDefines.hh"
#include "DataMsg.hh"

class DataHandler
{
   private:
      DataHandler( );
      ~DataHandler( );

      static DataHandler* m_pInstance;
      Queue< MsgBase * > *queueObj;

      MsgBase *getq( );

      typedef std::map< Char< MAX_FILE_NAME >, Char< MAX_DATA_SIZE > >Name2Data;
      Name2Data mName2Data;
   public:
      static DataHandler* getInstance( );
      static void destroyInstance( );
      void putq( MsgBase *msgObj, int waitTime = 0 );
      static void* process( void * );
      void start( );
      void processMsg( MsgBase *incomingMsg );
      int processDataMessage( DataMsg *pDataMsg );
      int writeDatatoFile( Char< MAX_FILE_NAME >fileName, const char *data, size_t dataSize );
};


#define DATA_HANDLER DataHandler::getInstance( )


#endif
