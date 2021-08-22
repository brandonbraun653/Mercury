include("${COMMON_TOOL_ROOT}/cmake/utility/embedded.cmake")

gen_static_lib_variants(
  TARGET
    mercury_lib_sys
  SOURCES
    m_sys_chimera.cpp
    m_sys.cpp
  PRV_LIBRARIES
    aurora_intf_inc
    chimera_intf_inc
    mercury_intf_inc
  EXPORT_DIR
    "${PROJECT_BINARY_DIR}/Mercury"
)
