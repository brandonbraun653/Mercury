/******************************************************************************
 *  File Name:
 *    device_attr_base.hpp
 *
 *  Description:
 *    Base classes for common functionality
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *****************************************************************************/

#pragma once
#ifndef MERCURY_DEVICE_ATTRIBUTES_BASE_HPP
#define MERCURY_DEVICE_ATTRIBUTES_BASE_HPP

/*-----------------------------------------------------------------------------
Includes
-----------------------------------------------------------------------------*/
#include <cstddef>

namespace Mercury::Device::Info
{
  /**
   * @brief Peripheral Configuration Versions
   */
  class Versions
  {
  public:
    Versions();

    /**
     * @brief Minimum compatible version
     *
     * @return size_t
     */
    virtual size_t minVersion() const = 0;

    /**
     * @brief Maximum compatible version
     *
     * @return size_t
     */
    virtual size_t maxVersion() const = 0;

    /**
     * @brief Current (loaded) version of the config
     *
     * @return size_t
     */
    virtual size_t version() const = 0;

    /**
     * @brief Checks if the given version is compatible with the versions this class understands.
     *
     * @param version     Version to check
     * @return true
     * @return false
     */
    bool isCompatibleVersion( const size_t version );

  protected:
    size_t mLoadedVersion;
  };


}  // namespace Mercury::Device::Attribute

#endif  /* !MERCURY_DEVICE_ATTRIBUTES_BASE_HPP */
