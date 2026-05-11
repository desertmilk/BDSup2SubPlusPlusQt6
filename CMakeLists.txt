# BDSup2Sub++ 核心静态库（不含主窗口 / CLI / Qxt），供 SubtitleTool 等宿主链接。
# 由宿主工程在 find_package(Qt6 ...) 与 qt_standard_project_setup() 之后 add_subdirectory 本目录。

set(BDSUP_SRC_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/src")

if(NOT EXISTS "${BDSUP_SRC_ROOT}/Subtitles/supbd.cpp")
    message(FATAL_ERROR "未找到 BDSup2Sub++ 源码目录 src/Subtitles（仓库不完整）")
endif()

file(GLOB BDSUP_FILTERS CONFIGURE_DEPENDS "${BDSUP_SRC_ROOT}/Filters/*.cpp")
file(GLOB BDSUP_SUBTITLES CONFIGURE_DEPENDS "${BDSUP_SRC_ROOT}/Subtitles/*.cpp")
file(GLOB BDSUP_TOOLS CONFIGURE_DEPENDS "${BDSUP_SRC_ROOT}/Tools/*.cpp")

qt_add_library(bdsup2subplusplus_core STATIC
    ${BDSUP_FILTERS}
    ${BDSUP_SUBTITLES}
    ${BDSUP_TOOLS}
)

target_include_directories(bdsup2subplusplus_core PUBLIC
    "${BDSUP_SRC_ROOT}"
    "${BDSUP_SRC_ROOT}/Subtitles"
    "${BDSUP_SRC_ROOT}/Filters"
    "${BDSUP_SRC_ROOT}/Tools"
)

target_link_libraries(bdsup2subplusplus_core PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Widgets
    Qt::Xml
    Qt6::Core5Compat
)

set_target_properties(bdsup2subplusplus_core PROPERTIES AUTOMOC ON)
