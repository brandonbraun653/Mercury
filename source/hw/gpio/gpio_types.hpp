/******************************************************************************
 *  File Name:
 *    gpio_types.hpp
 *
 *  Description:
 *    Mercury GPIO types
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *****************************************************************************/

#pragma once
#ifndef MERCURY_GPIO_TYPES_HPP
#define MERCURY_GPIO_TYPES_HPP

/*-----------------------------------------------------------------------------
Includes
-----------------------------------------------------------------------------*/
#include <Chimera/gpio>
#include <map>

namespace Mercury::GPIO
{
  /*---------------------------------------------------------------------------
  Forward Declarations
  ---------------------------------------------------------------------------*/
  class Driver;

  /*---------------------------------------------------------------------------
  Aliases
  ---------------------------------------------------------------------------*/
  using Driver_rPtr = Driver *;

  template<typename DriverClass>
  using PinDriverMap = std::map<size_t, DriverClass>;

  template<typename DriverClass>
  using DriverMap = std::map<Chimera::GPIO::Port, PinDriverMap<DriverClass>>;

}  // namespace Mercury::GPIO

#endif  /* !MERCURY_GPIO_TYPES_HPP */
