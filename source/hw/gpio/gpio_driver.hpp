/******************************************************************************
 *  File Name:
 *    gpio.hpp
 *
 *  Description:
 *    Mercury GPIO driver
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *****************************************************************************/

#pragma once
#ifndef MERCURY_GPIO_HPP
#define MERCURY_GPIO_HPP

/*-----------------------------------------------------------------------------
Includes
-----------------------------------------------------------------------------*/
#include <Chimera/common>
#include <Chimera/exti>
#include <Chimera/gpio>
#include <Chimera/thread>
#include <Mercury/source/hw/gpio/gpio_types.hpp>

namespace Mercury::GPIO
{
  /*---------------------------------------------------------------------------
  Public Functions
  ---------------------------------------------------------------------------*/
  Chimera::Status_t initialize();
  Chimera::Status_t reset();
  Driver_rPtr getDriver( const Chimera::GPIO::Port port, const Chimera::GPIO::Pin pin );
  size_t getPinResourceIndex( const Chimera::GPIO::Port port, const Chimera::GPIO::Pin pin );

  /*---------------------------------------------------------------------------
  Classes
  ---------------------------------------------------------------------------*/
  class Driver : virtual public Chimera::GPIO::HWInterface, public Chimera::Thread::Lockable<Driver>
  {
  public:
    Driver();
    ~Driver();

    Chimera::Status_t init( const Chimera::GPIO::PinInit &pinInit ) final override;
    Chimera::Status_t init( const Chimera::GPIO::Port port, const uint8_t pin ) final override;
    Chimera::Status_t setMode( const Chimera::GPIO::Drive drive, const Chimera::GPIO::Pull pull ) final override;
    Chimera::Status_t setState( const Chimera::GPIO::State state ) final override;
    Chimera::Status_t getState( Chimera::GPIO::State &state ) final override;
    Chimera::Status_t toggle() final override;
    Chimera::Status_t attachInterrupt( Chimera::Function::vGeneric &func, const Chimera::EXTI::EdgeTrigger trigger ) final override;
    void detachInterrupt() final override;
    Chimera::EXTI::EventLine_t getInterruptLine() final override;

  private:
    friend Chimera::Thread::Lockable<Driver>;

    Chimera::GPIO::Alternate mAlternate;
    Chimera::GPIO::Pin mPin;
    Chimera::GPIO::Port mPort;
  };
}  // namespace Mercury::GPIO

#endif  /* !MERCURY_GPIO_HPP */
