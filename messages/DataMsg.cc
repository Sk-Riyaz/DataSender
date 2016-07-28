#include "DataMsg.hh"

DataMsg::DataMsg()
{
   mFileName.clear();
   memset( mFileData, 0, MAX_DATA_SIZE );
   print(INFO, "DataMsg::Default Constructor");
}

DataMsg::DataMsg( unsigned int i ):
   MsgBase( MESSAGE_TYPE_DATA, i ),
   msgId( i )
{
   mFileName.clear( );
   memset( mFileData, 0, MAX_DATA_SIZE );
   print(INFO, "DataMsg::Constructor-->%d",msgId);
}

DataMsg::~DataMsg()
{
   mFileName.clear();
   memset( mFileData, 0, MAX_DATA_SIZE );
   print(INFO, "DataMsg::Destructor");
}

void
DataMsg::reset()
{
   mFileName.clear( );
   memset( mFileData, 0, MAX_DATA_SIZE );
}

unsigned int
DataMsg::getMsgId( )
{
   return msgId;
}

void
DataMsg::setFileName( const Char< MAX_FILE_NAME >&fileName )
{
   mFileName = fileName;
}

const Char<MAX_FILE_NAME>& 
DataMsg::getFileName( ) const
{
   return mFileName;
}

void
DataMsg::setFileData( char *ptr, size_t size )
{
   if( NULL != ptr )
   {
      memcpy( mFileData, ptr, size );
   }
}

const char *
DataMsg::getFileData( ) const
{
   return mFileData;
}

