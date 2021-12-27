/******************************************************************************
 *  File Name:
 *    device_attr_gpio.hpp
 *
 *  Description:
 *    Attributes for a Mercury peripheral configuration
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *****************************************************************************/

#pragma once
#ifndef MERCURY_DEVICE_ATTRIBUTES_GPIO_HPP
#define MERCURY_DEVICE_ATTRIBUTES_GPIO_HPP

/*-----------------------------------------------------------------------------
Includes
-----------------------------------------------------------------------------*/
#include <string>
#include <Mercury/source/dt/attributes/device_attr_base.hpp>


namespace Mercury::Device::GPIO
{
  /*---------------------------------------------------------------------------
  Constants
  ---------------------------------------------------------------------------*/
  static constexpr size_t VersionMin = 0;
  static constexpr size_t VersionCur = 0;
  static constexpr size_t VersionMax = VersionCur;

  /*---------------------------------------------------------------------------
  Classes
  ---------------------------------------------------------------------------*/
  /**
   * Single line inside a GPIO chip controller
   */
  class PinAttribute
  {
  public:
    size_t mLineNumber; /**< Line number inside the chip controller */
    std::string mName;  /**< User name of the line */
  };


  /**
   * Each Linux GPIO controller is termed a 'chip', with each controlling a
   * number of discrete I/O pins. This class describes some attributes needed
   * at the 'chip' level.
   */
  class ChipAttribute
  {
  public:
    std::string mDeviceName;       /**< Character device name as registered Linux */
    size_t mLineCapacity;          /**< Possible number of I/O lines */
    std::list<PinAttribute> mPins; /**< Individual pin attributes */
  };


  /**
   * High level descriptors for the entire GPIO stack. This isn't really Linux
   * specific information as it is some custom housekeeping information.
   */
  class ModuleAttributes : public Info::Versions
  {
  public:
    std::map<std::string, ChipAttribute> mChips;  /**< Chip controller info, keyed by name */

    size_t minVersion() const
    {
      return VersionMin;
    }

    size_t maxVersion() const
    {
      return VersionMax;
    }

    size_t version() const
    {
      return VersionCur;
    }

  };

}  // namespace Mercury::Device::Attribute::GPIO

#endif /* !MERCURY_DEVICE_ATTRIBUTES_GPIO_HPP */
