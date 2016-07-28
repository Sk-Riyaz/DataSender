#include "CommonDefines.hh"
#include "CommonIncludes.hh"

long int getCurrentTimeInSec( )
{
   struct timeval t;
   ::gettimeofday( &t, NULL );
   return t.tv_sec;
}

double getCurrentTimeWithMicroSec( )
{
   struct timeval t;
   ::gettimeofday( &t, NULL );
   return ((t.tv_sec * 1000000 + t.tv_usec)* 1.0)/1000000;
}

double getCurrentTimeWithMilliSec( )
{
   struct timeval t;
   ::gettimeofday( &t, NULL );
   return ((t.tv_sec * 1000 + t.tv_usec/1000)* 1.0)/1000;
}

long long int getCurrentTimeInMicroSec( )
{
   struct timeval t;
   ::gettimeofday( &t, NULL );
   return ((t.tv_sec * 1000000 + t.tv_usec)* 1.0);
}

long long int getCurrentTimeInMilliSec( )
{
   struct timeval t;
   ::gettimeofday( &t, NULL );
   return (t.tv_sec * 1000 + t.tv_usec/1000);
}


