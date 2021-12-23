/******************************************************************************
 *  File Name:
 *    gpio_chimera.hpp
 *
 *  Description:
 *    Chimera hooks for implementing the hardware driver
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *****************************************************************************/

#pragma once
#ifndef MERCURY_GPIO_CHIMERA_HOOKS_HPP
#define MERCURY_GPIO_CHIMERA_HOOKS_HPP

/*-----------------------------------------------------------------------------
Includes
-----------------------------------------------------------------------------*/
#include <Chimera/common>
#include <Chimera/gpio>

namespace Chimera::GPIO::Backend
{
  /*---------------------------------------------------------------------------
  Public Functions
  ---------------------------------------------------------------------------*/
  Chimera::Status_t initialize();
  Chimera::Status_t reset();
  Driver_rPtr getDriver( const Port port, const Pin pin );
}  // namespace Chimera::GPIO::Backend

#endif /* !MERCURY_GPIO_CHIMERA_HOOKS_HPP */
