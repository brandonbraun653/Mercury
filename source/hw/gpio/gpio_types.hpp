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
}  // namespace Mercury::GPIO

#endif  /* !MERCURY_GPIO_TYPES_HPP */
