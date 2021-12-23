include("${COMMON_TOOL_ROOT}/cmake/utility/embedded.cmake")

# ====================================================
# Drivers
# ====================================================
add_subdirectory(gpio)

# ====================================================
# Composite Library
# ====================================================
gen_intf_lib_variants(
  TARGET
    mercury_lib_hw
  LIBRARIES
    mercury_lib_hw_gpio
  EXPORT_DIR
  "${PROJECT_BINARY_DIR}/Mercury"
)
