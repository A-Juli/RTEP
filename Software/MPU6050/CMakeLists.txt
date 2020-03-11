cmake_minimum_required(VERSION 3.0.0)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

project(MPU6050_RaspberryPi_Library LANGUAGES CXX)
include(GNUInstallDirs)
add_subdirectory(Example)

# add_compile_options(-Wall -Wconversion -Wextra -pedantic)

set(LIBSRC MPU6050.cpp)
set(LIBINCLUDE MPU6050.h MPU6050Registers.h)

add_library(MPU6050
  SHARED
  ${LIBSRC}
  )

set_target_properties(MPU6050 PROPERTIES
  SOVERSION 1
  PUBLIC_HEADER "${LIBINCLUDE}")

target_link_libraries(MPU6050 wiringPi)

install(TARGETS MPU6050 EXPORT MPU6050-targets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})



add_library(MPU6050_static
  STATIC
  ${LIBSRC}
  )

set_target_properties(MPU6050_static PROPERTIES
  PUBLIC_HEADER "${LIBINCLUDE}")

target_link_libraries(MPU6050_static wiringPi)

install(TARGETS MPU6050_static EXPORT MPU6050_static-targets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
