/********************************************************************************
 *  File Name:
 *    version.hpp
 *
 *  Description:
 *    Mercury versioning information
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef MERCURY_HLD_VERSION_HPP
#define MERCURY_HLD_VERSION_HPP

/* STL Includes */
#include <string>

namespace Mercury
{
  /**
   *  CHANGELOG:
   *
   *  v0.0.0: Initial creation
   */
  static constexpr std::string_view VersionString = "0.0.0";

  static constexpr size_t VersionMajor = 0;
  static constexpr size_t VersionMinor = 0;
  static constexpr size_t VersionPatch = 0;
}  // namespace Mercury

#endif /* !MERCURY_HLD_VERSION_HPP */
