include("${COMMON_TOOL_ROOT}/cmake/utility/embedded.cmake")

gen_static_lib_variants(
  TARGET
    mercury_lib_device_tree
  SOURCES
    device_tree.cpp
    attributes/device_attr_base.cpp
  PRV_LIBRARIES
    mercury_intf_inc
  EXPORT_DIR
    "${PROJECT_BINARY_DIR}/Mercury/dt"
)
