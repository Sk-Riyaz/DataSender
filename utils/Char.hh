#ifndef _TOKENIZE_HH_
#define _TOKENIZE_HH_

#include<vector>
#include<cstring>
#include<stdio.h>
#include<iostream>

#include "CommonDefines.hh"

#define DEFAULT_ARRAY_LENGTH 50
#define MAX_ARRAY_LENGTH 100

static unsigned int Default = 0;

using namespace std;

template < size_t size = DEFAULT_ARRAY_LENGTH >
class Char
{
   private:
      size_t mSize;
      char array[ size ];

   public:
 
      Char( );
      Char( const char *str );
      template< size_t n >
      Char( const Char< n > &rhsObj );
      Char( const char *pStart, const char *pEnd );
      template< size_t n >
      Char( const char *pStart, const char *pEnd );
      ~Char( );

      template< size_t n >
      Char< size > &operator = ( const Char< n > &rhsObj );
      Char< size > &operator = ( const char *rhsString );
      template< size_t n >
      bool operator == ( const Char< n > &rhsObj );
      bool operator == ( const char *rhsObj );
      template < size_t n >
      Char< size > operator + ( const Char< n > &rhsObj );
      Char< size > operator + ( const char *rhsObj );
      template < size_t n >
      void operator += ( const Char< n > &rhsObj );
      void operator += ( const char *rhsObj );
      char operator [] ( unsigned int i );
      template < size_t n >
      bool operator< ( const Char<n> &rhsObj ) const;
      bool operator< ( const Char &rhsObj ) const;
      template < size_t n >
      bool operator> ( const Char<n> &rhsObj ) const;

      size_t len( ) const;
      Char< size > &clear( );
      bool compareString( const char *compareArray );
      #if 1
      template < size_t n >
      int tokenize( const char token, vector < Char < n > > &tokenList );
      #endif
      void reset( );
      void setString( const char *str );
      template< size_t n >
      void setString( Char< n > &str );
      const char * get( ) const;
      void readString( const char *str=NULL );
      bool isSubStr( const char *supStr, 
                     unsigned int &start = Default,
                     unsigned int &end = Default );
      template < size_t n >
      bool isSubStr( const Char < n > &supStr,
                     unsigned int &start = Default,
                     unsigned int &end = Default );
      Char< size > subStr( int start, int end );
      void printString( ) const;
      template < size_t n >
      void printVector( vector < Char < n > > &tokenList ) const;
      int pos( const char inp, int start = 0, int end = -1 );
      int pos( const char *inpStr, int start = 0, int end = -1 );
      template < size_t n >
      int pos( const Char< n > &inpStr, int start = 0, int end = -1 );
      Char< size > trim( const char trimVal = ' ' );
      Char< size > ltrim( const char trimVal = ' ' );
      Char< size > rtrim( const char trimVal = ' ' );
};

#include "Char.tt"

#endif // _TOKENIZE_HH_
