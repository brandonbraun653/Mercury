/******************************************************************************
 *  File Name:
 *    gpio_chimera.cpp
 *
 *  Description:
 *    Chimera GPIO driver hooks
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *****************************************************************************/

/*-----------------------------------------------------------------------------
Includes
-----------------------------------------------------------------------------*/
#include <Aurora/logging>
#include <Chimera/assert>
#include <Chimera/common>
#include <Chimera/peripheral>
#include <Chimera/gpio>
#include <Mercury/device>
#include <Mercury/gpio>
#include <Mercury/system>
#include <vector>

/*-----------------------------------------------------------------------------
Variables
-----------------------------------------------------------------------------*/
static std::vector<Chimera::GPIO::Driver> s_raw_drivers;


namespace Chimera::GPIO::Backend
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
    s_raw_drivers.resize( cfg.size() );
    for( auto &driver : s_raw_drivers )
    {
      driver = {};
    }

    return Mercury::GPIO::initialize();
  }


  Chimera::Status_t reset()
  {
    return Mercury::GPIO::reset();
  }


  Chimera::GPIO::Driver_rPtr getDriver( const Port port, const Pin pin )
  {
    const auto idx = Mercury::GPIO::getPinResourceIndex( port, pin );
    if ( idx < s_raw_drivers.size() )
    {
      return &s_raw_drivers[ idx ];
    }
    else
    {
      return nullptr;
    }
  }

  Chimera::Status_t registerDriver( Chimera::GPIO::Backend::DriverConfig &registry )
  {
    registry.isSupported = true;
    registry.getDriver   = getDriver;
    registry.initialize  = initialize;
    registry.reset       = reset;
    return Chimera::Status::OK;
  }
}  // namespace Chimera::GPIO::Backend


namespace Chimera::GPIO
{
  Driver::Driver() : mDriver( nullptr )
  {
  }


  Driver::~Driver()
  {
  }


  /*---------------------------------------------------------------------------
  Interface: Hardware
  ---------------------------------------------------------------------------*/
  Chimera::Status_t Driver::init( const Chimera::GPIO::PinInit &pinInit )
  {
    mDriver = Mercury::GPIO::getDriver( pinInit.port, pinInit.pin );

    RT_HARD_ASSERT( mDriver );
    return static_cast<Mercury::GPIO::Driver_rPtr>( mDriver )->init( pinInit );
  }


  Chimera::Status_t Driver::init( const Chimera::GPIO::Port port, const uint8_t pin )
  {
    mDriver = Mercury::GPIO::getDriver( port, pin );

    RT_HARD_ASSERT( mDriver );
    return static_cast<Mercury::GPIO::Driver_rPtr>( mDriver )->init( port, pin );
  }


  Chimera::Status_t Driver::setMode( const Chimera::GPIO::Drive drive, const Chimera::GPIO::Pull pull )
  {
    RT_HARD_ASSERT( mDriver );
    return static_cast<Mercury::GPIO::Driver_rPtr>( mDriver )->setMode( drive, pull );
  }


  Chimera::Status_t Driver::setState( const Chimera::GPIO::State state )
  {
    RT_HARD_ASSERT( mDriver );
    return static_cast<Mercury::GPIO::Driver_rPtr>( mDriver )->setState( state );
  }


  Chimera::Status_t Driver::getState( Chimera::GPIO::State &state )
  {
    RT_HARD_ASSERT( mDriver );
    return static_cast<Mercury::GPIO::Driver_rPtr>( mDriver )->getState( state );
  }


  Chimera::Status_t Driver::toggle()
  {
    RT_HARD_ASSERT( mDriver );
    return static_cast<Mercury::GPIO::Driver_rPtr>( mDriver )->toggle();
  }


  Chimera::Status_t Driver::attachInterrupt( Chimera::Function::vGeneric &func, const Chimera::EXTI::EdgeTrigger trigger )
  {
    RT_HARD_ASSERT( mDriver );
    return static_cast<Mercury::GPIO::Driver_rPtr>( mDriver )->attachInterrupt( func, trigger );
  }


  void Driver::detachInterrupt()
  {
    RT_HARD_ASSERT( mDriver );
    static_cast<Mercury::GPIO::Driver_rPtr>( mDriver )->detachInterrupt();
  }


  Chimera::EXTI::EventLine_t Driver::getInterruptLine()
  {
    RT_HARD_ASSERT( mDriver );
    return static_cast<Mercury::GPIO::Driver_rPtr>( mDriver )->getInterruptLine();
  }

  /*---------------------------------------------------------------------------
  Interface: Lockable
  ---------------------------------------------------------------------------*/
  void Driver::lock()
  {
    RT_HARD_ASSERT( mDriver );
    static_cast<Mercury::GPIO::Driver_rPtr>( mDriver )->lock();
  }


  void Driver::lockFromISR()
  {
    RT_HARD_ASSERT( mDriver );
    static_cast<Mercury::GPIO::Driver_rPtr>( mDriver )->lockFromISR();
  }


  bool Driver::try_lock_for( const size_t timeout )
  {
    RT_HARD_ASSERT( mDriver );
    return static_cast<Mercury::GPIO::Driver_rPtr>( mDriver )->try_lock_for( timeout );
  }


  void Driver::unlock()
  {
    RT_HARD_ASSERT( mDriver );
    static_cast<Mercury::GPIO::Driver_rPtr>( mDriver )->unlock();
  }


  void Driver::unlockFromISR()
  {
    RT_HARD_ASSERT( mDriver );
    static_cast<Mercury::GPIO::Driver_rPtr>( mDriver )->unlockFromISR();
  }
}
