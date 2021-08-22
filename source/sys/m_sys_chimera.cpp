/********************************************************************************
 *  File Name:
 *    m_sys_chimera.cpp
 *
 *  Description:
 *    Mercury system registration hooks for Chimera
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Chimera Includes */
#include <Chimera/system>

/* Mercury Includes */
#include <Mercury/system>
#include <Mercury/source/version.hpp>

namespace Chimera::System::Backend
{
  /*-------------------------------------------------------------------------------
  Static Data
  -------------------------------------------------------------------------------*/
  static bool s_system_initialized        = false;
  static ResetEvent s_system_reset_reason = ResetEvent::UNKNOWN;

  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  static Chimera::Status_t initialize()
  {
    if ( !s_system_initialized )
    {
      s_system_initialized = true;
      getResetReason();

      return Mercury::System::initialize();
    }

    return Chimera::Status::OK;
  }


  static Chimera::Status_t reset()
  {
    auto lld_reset_result = Mercury::System::reset();

    if ( lld_reset_result == Chimera::Status::OK )
    {
      s_system_initialized = false;
    }

    return lld_reset_result;
  }


  static Chimera::Status_t systemStartup()
  {
    return Mercury::System::systemStartup();
  }


  static Chimera::System::InterruptMask disableInterrupts()
  {
    return Mercury::System::disableInterrupts();
  }


  static void enableInterrupts( Chimera::System::InterruptMask &interruptMask )
  {
    return Mercury::System::enableInterrupts( interruptMask );
  }


  static int maxConcurrentThreads()
  {
    return Mercury::System::maxConcurrentThreads();
  }


  static Chimera::System::ResetEvent getResetReason()
  {
    auto reason = Mercury::System::getResetReason();

    /*------------------------------------------------
    If the flags were cleared, use the cached reset
    ------------------------------------------------*/
    if ( reason == ResetEvent::CLEARED )
    {
      return s_system_reset_reason;
    }

    /*------------------------------------------------
    Otherwise cache off the reset code
    ------------------------------------------------*/
    s_system_reset_reason = reason;
    return reason;
  }


  static void getSystemInformation( Chimera::System::Information *&info )
  {
    Mercury::System::getSystemInformation( info );
  }


  static void softwareReset()
  {
    Mercury::System::softwareReset();
  }


  static bool inISR()
  {
    return Mercury::System::inISR();
  }


  namespace Version
  {
    static std::string_view asString()
    {
      return Mercury::VersionString;
    }


    static size_t major()
    {
      return Mercury::VersionMajor;
    }


    static size_t minor()
    {
      return Mercury::VersionMinor;
    }


    static size_t patch()
    {
      return Mercury::VersionPatch;
    }
  }    // namespace Version


  namespace Description
  {
    static std::string_view about()
    {
      return "Hardware abstraction layer built on top of Linux";
    }


    static std::string_view backendDriverName()
    {
      return "Mercury";
    }


    static std::string_view documentationLink()
    {
      return "https://github.com/brandonbraun653/Mercury";
    }
  }    // namespace Description


  Chimera::Status_t registerDriver( DriverConfig &registry )
  {
    registry.isSupported            = true;
    registry.disableInterrupts      = disableInterrupts;
    registry.enableInterrupts       = enableInterrupts;
    registry.getResetReason         = getResetReason;
    registry.getSystemInformation   = getSystemInformation;
    registry.initialize             = initialize;
    registry.maxConcurrentThreads   = maxConcurrentThreads;
    registry.reset                  = reset;
    registry.systemStartup          = systemStartup;
    registry.inISR                  = inISR;
    registry.softwareReset          = softwareReset;
    registry.desc_About             = Description::about;
    registry.desc_BackendDriverName = Description::backendDriverName;
    registry.desc_DocumentationLink = Description::documentationLink;
    registry.version_AsString       = Version::asString;
    registry.version_Major          = Version::major;
    registry.version_Minor          = Version::minor;
    registry.version_Patch          = Version::patch;
    return Chimera::Status::OK;
  }
}    // namespace Chimera::System::Backend
