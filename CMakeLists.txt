# =============================================================================
# Description:
#   Primary CMake entry point for building Mercury
#
# Exports:
#   mercury_intf_inc: Interface target for getting public headers and macro defs
#
# 2021 | Brandon Braun | brandonbraun653@gmail.com
# =============================================================================

# ====================================================
# Import sub-projects
# ====================================================
add_subdirectory("source")

# ====================================================
# Library Exports
# ====================================================
set(MercuryExportDir "${PROJECT_BINARY_DIR}/Mercury")

# ====================================================
# Public Headers
# ====================================================
gen_intf_lib(
  TARGET
    mercury_intf_inc
  INTF_INCLUDES
    "./../"
    "./include"
    "/usr/include"  # Linux Headers
  INTF_LIBRARIES
    aurora_intf_inc
    chimera_intf_inc
    etl_inc
    project_inc
  EXPORT_DIR
    ${MercuryExportDir}
)
