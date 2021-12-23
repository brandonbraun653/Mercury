/******************************************************************************
 *  File Name:
 *    device_attr.hpp
 *
 *  Description:
 *    Attributes for various peripheral types
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *****************************************************************************/

#pragma once
#ifndef MERCURY_DEVICE_ATTRIBUTES_HPP
#define MERCURY_DEVICE_ATTRIBUTES_HPP

/*-----------------------------------------------------------------------------
Includes
-----------------------------------------------------------------------------*/
#include <any>
#include <map>
#include <list>
#include <Chimera/peripheral>

namespace Mercury::Device
{
  /*---------------------------------------------------------------------------
  Aliases
  ---------------------------------------------------------------------------*/
  using AttrType  = std::any;
  using AttrList  = std::list<AttrType>;
  using PeriphMap = std::map<Chimera::Peripheral::Type, AttrList>;
}  // namespace Mercury::Device

#endif /* !MERCURY_DEVICE_ATTRIBUTES_HPP */
