include("${COMMON_TOOL_ROOT}/cmake/utility/embedded.cmake")

find_library(LIB_GPIOD gpiod REQUIRED)

gen_static_lib_variants(
  TARGET
    mercury_lib_hw_gpio
  SOURCES
    gpio_chimera.cpp
    gpio_driver.cpp
  PRV_LIBRARIES
    mercury_intf_inc
    ${LIB_GPIOD}
  EXPORT_DIR
    "${PROJECT_BINARY_DIR}/Mercury/dt"
)
