find_package(OpenMVG REQUIRED)
include_directories(${OPENMVG_INCLUDE_DIRS})
add_executable(main main.cpp)
target_link_libraries(main ${OPENMVG_LIBRARIES})