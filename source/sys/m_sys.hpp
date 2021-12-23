/********************************************************************************
 *  File Name:
 *    m_sys.hpp
 *
 *  Description:
 *    Mercury system interface, derived from the Chimera spec.
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef MERCURY_SYSTEM_HPP
#define MERCURY_SYSTEM_HPP

/*-----------------------------------------------------------------------------
Includes
-----------------------------------------------------------------------------*/
#include <filesystem>
#include <Chimera/common>
#include <Chimera/system>

namespace Mercury::System
{
  /*---------------------------------------------------------------------------
  Chimera Public Functions
  ---------------------------------------------------------------------------*/
  Chimera::Status_t initialize();
  Chimera::Status_t reset();
  Chimera::Status_t systemStartup();
  Chimera::System::InterruptMask disableInterrupts();
  void enableInterrupts( Chimera::System::InterruptMask &interruptMask );
  int maxConcurrentThreads();
  Chimera::System::ResetEvent getResetReason();
  void getSystemInformation( Chimera::System::Information *&info );
  void softwareReset();
  bool inISR();

  /*---------------------------------------------------------------------------
  Mercury Public functions
  ---------------------------------------------------------------------------*/
  /**
   * @brief Assigns the platform configuration file for hardware resources
   * See available platforms under source/dt/platforms.
   *
   * @param path  Path to the platform file
   */
  void setPlatformFile( const std::filesystem::path &path );

  /**
   * @brief Retrieves the configured platform file
   *
   * @return std::filesystem::path
   */
  std::filesystem::path getPlatformFile();
}  // namespace Mercury::System

#endif /* !MERCURY_SYSTEM_HPP */
