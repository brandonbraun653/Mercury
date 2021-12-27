/******************************************************************************
 *  File Name:
 *    gpio.cpp
 *
 *  Description:
 *    Mercury GPIO driver based on libgpiod. Will require installation of apt
 *    package libgpiod-dev for compiling.
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *****************************************************************************/

/*-----------------------------------------------------------------------------
Includes
-----------------------------------------------------------------------------*/
#include </usr/include/gpiod.h>
#include <Mercury/device>
#include <Mercury/gpio>

/*-----------------------------------------------------------------------------
Variables
-----------------------------------------------------------------------------*/
static Mercury::GPIO::DriverMap<Mercury::GPIO::Driver> s_raw_drivers;

namespace Mercury::GPIO
{
  /*---------------------------------------------------------------------------
  Public Functions
  ---------------------------------------------------------------------------*/
  Chimera::Status_t initialize()
  {
    /*-------------------------------------------------------------------------
    Load the device tree configuration
    -------------------------------------------------------------------------*/
    auto cfg = Mercury::Device::loadAttributes( Chimera::Peripheral::Type::PERIPH_GPIO );
    if( !cfg.size() )
    {
      return Chimera::Status::FAIL;
    }

    /*-------------------------------------------------------------------------
    Resize and reinitialize the driver objects
    -------------------------------------------------------------------------*/


    return Chimera::Status::OK;
  }


  Chimera::Status_t reset()
  {
    return Chimera::Status::OK;
  }


  Driver_rPtr getDriver( const Chimera::GPIO::Port port, const Chimera::GPIO::Pin pin )
  {
    auto portMap = s_raw_drivers.find( port );
    if( portMap != s_raw_drivers.end() )
    {
      auto pinMap = portMap->second.find( pin );
      if( pinMap != portMap->second.end() )
      {
        return &portMap->second.at( pin );
      }
    }

    return nullptr;
  }


  size_t getPinResourceIndex( const Chimera::GPIO::Port port, const Chimera::GPIO::Pin pin )
  {
    return 0;
  }


  /*---------------------------------------------------------------------------
  GPIO Driver Class
  ---------------------------------------------------------------------------*/
  Driver::Driver()
  {
  }


  Driver::~Driver()
  {
  }


  Chimera::Status_t Driver::init( const Chimera::GPIO::PinInit &pinInit )
  {
    return Chimera::Status::NOT_SUPPORTED;
  }


  Chimera::Status_t Driver::init( const Chimera::GPIO::Port port, const uint8_t pin )
  {
    // Look up the configuration from file...
    // Grab the correct GPIO chip by name
    // Get the line by pin
    return Chimera::Status::NOT_SUPPORTED;
  }


  Chimera::Status_t Driver::setMode( const Chimera::GPIO::Drive drive, const Chimera::GPIO::Pull pull )
  {
    return Chimera::Status::NOT_SUPPORTED;
  }


  Chimera::Status_t Driver::setState( const Chimera::GPIO::State state )
  {
    return Chimera::Status::NOT_SUPPORTED;
  }


  Chimera::Status_t Driver::getState( Chimera::GPIO::State &state )
  {
    return Chimera::Status::NOT_SUPPORTED;
  }


  Chimera::Status_t Driver::toggle()
  {
    return Chimera::Status::NOT_SUPPORTED;
  }


  Chimera::Status_t Driver::attachInterrupt( Chimera::Function::vGeneric &func, const Chimera::EXTI::EdgeTrigger trigger )
  {
    return Chimera::Status::NOT_SUPPORTED;
  }


  void Driver::detachInterrupt()
  {
  }


  Chimera::EXTI::EventLine_t Driver::getInterruptLine()
  {
    return 0;
  }

}  // namespace Mercury::GPIO
