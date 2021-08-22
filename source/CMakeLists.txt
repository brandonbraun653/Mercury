include("${COMMON_TOOL_ROOT}/cmake/utility/embedded.cmake")

add_subdirectory(dt)
add_subdirectory(hw)
add_subdirectory(sys)

# ====================================================
# Core Library
# ====================================================
gen_intf_lib_variants(
  TARGET
    mercury_core
  LIBRARIES
    mercury_lib_sys
  EXPORT_DIR
  "${PROJECT_BINARY_DIR}/Mercury"
)
