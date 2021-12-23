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

  class Attribute : public Info::Versions
  {
  public:
    size_t minVersion() const final override
    {
      return VersionMin;
    }

    size_t maxVersion() const final override
    {
      return VersionMax;
    }

    size_t version() const final override
    {
      return VersionCur;
    }

  };


}  // namespace Mercury::Device::Attribute::GPIO

#endif /* !MERCURY_DEVICE_ATTRIBUTES_GPIO_HPP */
