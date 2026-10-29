cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(lvgl_display_simulation)



# The Editor-generated UI includes LVGL as `#include "lvgl.h"`.
zephyr_compile_definitions(LV_LVGL_H_INCLUDE_SIMPLE)
zephyr_compile_definitions(LV_EDITOR_PREVIEW)

target_sources(app PRIVATE src/main.c)


add_subdirectory(lvgl_zephyr_project/ui)
target_link_libraries(lib-ui PUBLIC zephyr_interface)
target_link_libraries(app PRIVATE lib-ui)
