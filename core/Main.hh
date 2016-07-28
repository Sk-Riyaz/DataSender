#ifndef __MAIN_HH__
#define __MAIN_HH__

#include "CommonIncludes.hh"

class Main
{
   private:
      Main( );
      ~Main( );

      static Main * m_pInstance;
   public:
      static Main * getInstance( );
      static void destroyInstance( );

      int start( );
      int killAll( );
      int process( );
      void instantiateProcessess( );
      void destroyProcessess( );
};

#define MAIN Main::getInstance()

#endif
