if(NOT TARGET Qt::Test)
    find_package(Qt6 COMPONENTS Test REQUIRED)
endif()

qt_add_executable(bdsup2subplusplus_tests
    test_palette.cpp
)

target_include_directories(bdsup2subplusplus_tests PRIVATE
    "${BDSUP_SRC_ROOT}"
    "${BDSUP_SRC_ROOT}/Subtitles"
)

target_link_libraries(bdsup2subplusplus_tests PRIVATE
    Qt::Test
    bdsup2subplusplus_core
)

add_test(NAME PaletteTest COMMAND bdsup2subplusplus_tests)
