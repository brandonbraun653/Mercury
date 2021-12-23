/******************************************************************************
 *  File Name:
 *    gpio.cpp
 *
 *  Description:
 *    Mercury GPIO driver
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *****************************************************************************/

/*-----------------------------------------------------------------------------
Includes
-----------------------------------------------------------------------------*/
#include <Mercury/device>
#include <Mercury/gpio>

namespace Mercury::GPIO
{
  /*---------------------------------------------------------------------------
  Public Functions
  ---------------------------------------------------------------------------*/
  Chimera::Status_t initialize()
  {
    return Chimera::Status::NOT_SUPPORTED;
  }


  Chimera::Status_t reset()
  {
    return Chimera::Status::NOT_SUPPORTED;
  }


  Driver_rPtr getDriver( const Chimera::GPIO::Port port, const Chimera::GPIO::Pin pin )
  {
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
