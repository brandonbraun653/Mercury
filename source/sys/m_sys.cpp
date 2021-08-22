/********************************************************************************
 *  File Name:
 *    m_sys.cpp
 *
 *  Description:
 *    Implements system interface functions for Mercury
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

/* STL Includes */
#include <cstdlib>

/* Chimera Includes */
#include <Chimera/common>
#include <Chimera/system>

/* Mercury Includes */
#include <Mercury/system>


namespace Mercury::System
{
  /*-------------------------------------------------------------------------------
  Static Data
  -------------------------------------------------------------------------------*/
  static Chimera::System::Information s_system_info;

  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  Chimera::Status_t initialize()
  {
    s_system_info = {};
    return Chimera::Status::OK;
  }


  Chimera::Status_t reset()
  {
    return Chimera::Status::OK;
  }


  Chimera::Status_t systemStartup()
  {
    return Chimera::Status::OK;
  }


  Chimera::System::InterruptMask disableInterrupts()
  {
    return {};
  }


  void enableInterrupts( Chimera::System::InterruptMask &interruptMask )
  {
  }


  int maxConcurrentThreads()
  {
    return 1;
  }


  Chimera::System::ResetEvent getResetReason()
  {
    return Chimera::System::ResetEvent::NOT_SUPPORTED;
  }


  void getSystemInformation( Chimera::System::Information *&info )
  {
  }


  bool inISR()
  {
    return false;
  }


  void softwareReset()
  {
    /*-----------------------------------------------------------------
    If you reach this, check the call stack for any execution errors.
    -----------------------------------------------------------------*/
    Chimera::insert_debug_breakpoint();
    exit( -1 );
  }

}  // namespace Mercury::System
