/********************************************************************************
 *  File Name:
 *    m_sys.cpp
 *
 *  Description:
 *    Implements system interface functions for Mercury
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

/*-----------------------------------------------------------------------------
Includes
-----------------------------------------------------------------------------*/
#include <cstdlib>
#include <filesystem>
#include <mutex>
#include <Aurora/logging>
#include <Chimera/common>
#include <Chimera/system>
#include <Mercury/system>


namespace Mercury::System
{
  /*---------------------------------------------------------------------------
  Static Data
  ---------------------------------------------------------------------------*/
  static std::mutex s_module_lock;
  static Chimera::System::Information s_system_info;
  static std::filesystem::path s_platform_path;

  /*---------------------------------------------------------------------------
  Chimera Public Functions
  ---------------------------------------------------------------------------*/
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

  /*---------------------------------------------------------------------------
  Mercury Public Functions
  ---------------------------------------------------------------------------*/
  void setPlatformFile( const std::filesystem::path &path )
  {
    std::lock_guard<std::mutex> _lock( s_module_lock );
    if( std::filesystem::exists( path ) )
    {
      s_platform_path = path;
    }
    else
    {
      LOG_ERROR( "Platform configuration file doesn't exist: %s\r\n", path.c_str() );
    }
  }


  std::filesystem::path getPlatformFile()
  {
    std::lock_guard<std::mutex> _lock( s_module_lock );
    return s_platform_path;
  }

}  // namespace Mercury::System
