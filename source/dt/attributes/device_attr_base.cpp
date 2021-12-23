/******************************************************************************
 *  File Name:
 *    device_attr_base.cpp
 *
 *  Description:
 *    Base attribute implementation details
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *****************************************************************************/

/*-----------------------------------------------------------------------------
Includes
-----------------------------------------------------------------------------*/
#include <Mercury/device>


namespace Mercury::Device::Info
{
  /*---------------------------------------------------------------------------
  Class -- Versions
  ---------------------------------------------------------------------------*/
  Versions::Versions() : mLoadedVersion( 0 )
  {
  }


  bool Versions::isCompatibleVersion( const size_t version )
  {
    return ( this->minVersion() <= version ) && ( version <= this->maxVersion() );
  }

}  // namespace Mercury::Device::Attribute
