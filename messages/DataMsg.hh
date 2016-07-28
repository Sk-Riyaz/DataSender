#ifndef __LOGMSG_HH__
#define __LOGMSG_HH__

#include "MsgBase.hh"

class DataMsg: public MsgBase
{
   private:
      DataMsg( );

      unsigned int msgId;
      Char< MAX_FILE_NAME > mFileName;
      char mFileData[MAX_DATA_SIZE];
      size_t mDataSize;

   public:
      DataMsg( unsigned int i );
      ~DataMsg( );
      void reset( );
      unsigned int getMsgId( );
      void setFileName( const Char< MAX_FILE_NAME >&fileName );
      const Char< MAX_FILE_NAME >& getFileName( ) const;
      void setFileData( char *ptr, size_t size );
      const char *getFileData( ) const;
      void setDataSize( size_t size );
      size_t getDataSize( ) const;
};

#endif
