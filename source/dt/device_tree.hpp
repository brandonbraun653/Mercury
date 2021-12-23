/******************************************************************************
 *  File Name:
 *    device_tree.hpp
 *
 *  Description:
 *    Device tree parser that meshes with the Chimera notion of HW peripheral
 *    devices (SPI, I2C, UART, etc). Instead of a typical Linux device tree
 *    that understands register level attributes, the Mercury device tree knows
 *    the high level peripheral specific attributes needed to interact with HW
 *    from a user space or kernel driver.
 *
 *    Configurations are provided on a per-platform basis via JSON files. These
 *    are parsed to allow Chimera to initialize drivers properly at runtime.
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *****************************************************************************/

#pragma once
#ifndef MERCURY_DEVICE_TREE_HPP
#define MERCURY_DEVICE_TREE_HPP

/*-----------------------------------------------------------------------------
Includes
-----------------------------------------------------------------------------*/
#include <Chimera/peripheral>
#include <Mercury/source/dt/device_attr.hpp>
#include <filesystem>
#include <memory>

namespace Mercury::Device
{
  /*---------------------------------------------------------------------------
  Classes
  ---------------------------------------------------------------------------*/
  /**
   * Parsing module for inspecting peripheral configuration files. Helps extract
   * information about a platform's supported hardware.
   */
  class Parser
  {
  public:
    Parser();

    /**
     * @brief Loads a configuration file from disk.
     *
     * @param file    Full path to the file
     * @return true
     * @return false
     */
    bool loadFile( const std::filesystem::path &file );

    /**
     * @brief Provides the full attribute map loaded from disk
     *
     * @param map
     * @return true
     * @return false
     */
    bool attributeMap( PeriphMap &map );

    /**
     * @brief Retrieves the attribute definitions associated with a peripheral
     *
     * @param type  Which type to look up
     * @return const AttrType&
     */
    const AttrList& getAttributes( const Chimera::Peripheral::Type type );

  private:
    std::unique_ptr<PeriphMap> mPeriphMap;
    std::filesystem::path mConfigFile;
  };


  /*---------------------------------------------------------------------------
  Public Functions
  ---------------------------------------------------------------------------*/
  AttrList loadAttributes( const Chimera::Peripheral::Type &type );

}  // namespace Mercury::Device

#endif  /* !MERCURY_DEVICE_TREE_HPP */
