cmake_minimum_required(VERSION 2.8)

set(WITH_MYSQL "/usr/local/mariadb" CACHE STRING "mysql install directory")
option(WITH_TESTING OFF)

project(MyDiamond)
enable_testing()

find_package(GTest)
find_package(Boost REQUIRED)
find_package(Threads)

add_subdirectory(diamond)
add_subdirectory(ha_diamond)
if(WITH_TESTING)
add_subdirectory(test)
endif(WITH_TESTING)

