#ifndef __MSG_QUEUE_HH__
#define __MSG_QUEUE_HH__

#include <deque>
#include <pthread.h>

#include "CommonIncludes.hh"

template < class T >
class Queue
{
   private:
      std::deque< T > mQueue;
      pthread_mutex_t lock_queue;

   public:
      Queue( );
      ~Queue( );

      int putq( T msg, int waitTime = 0 );
      T getq( );
      unsigned int size( );
};

#include "MsgQueue.tt"

#endif
