cmake_minimum_required(VERSION 3.0)

project(satellite_constellation_viewer)

add_executable(satellite_constellation_viewer main.cpp)

install(TARGETS satellite_constellation_viewer RUNTIME DESTINATION bin)
