/******************************************************************************
 *  File Name:
 *    device_tree.cpp
 *
 *  Description:
 *    Implementation details for the device tree manager
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *****************************************************************************/

/*-----------------------------------------------------------------------------
Includes
-----------------------------------------------------------------------------*/
#include <Aurora/logging>
#include <Mercury/device>
#include <Mercury/system>

namespace Mercury::Device
{
  /*---------------------------------------------------------------------------
  Parser Class
  ---------------------------------------------------------------------------*/
  Parser::Parser() : mPeriphMap( nullptr ), mConfigFile( "" )
  {
  }


  bool Parser::loadFile( const std::filesystem::path &file )
  {
  }


  bool Parser::attributeMap( PeriphMap &map )
  {
  }


  const AttrList &Parser::getAttributes( const Chimera::Peripheral::Type type )
  {
  }


  /*---------------------------------------------------------------------------
  Public Functions
  ---------------------------------------------------------------------------*/
  AttrList loadAttributes( const Chimera::Peripheral::Type &type )
  {
    Parser parser;
    if ( !parser.loadFile( Mercury::System::getPlatformFile() ) )
    {
      LOG_ERROR( "Failed loading platform file\r\n" );
      return {};
    }

    auto cfg = parser.getAttributes( type );
    if ( !cfg.size() )
    {
      LOG_ERROR( "Missing attribute data for peripheral %d\r\n", static_cast<size_t>( type ) );
      return {};
    }

    return cfg;
  }

}  // namespace Mercury::Device
