cmake_minimum_required(VERSION 2.8)

set(WITH_MYSQL "/usr/local/mariadb" CACHE STRING "mysql install directory")
option(WITH_TESTING OFF)

project(MyDiamond)
enable_testing()

find_package(GTest)
find_package(Boost REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/src ${WITH_MYSQL}/include/mysql/private ${WITH_MYSQL}/include/mysql ${WITH_MYSQL}/include)
file(GLOB HEADERS ${PROJECT_SOURCE_DIR}/src/*.h)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SOURCES)
add_library(ha_diamond MODULE ${SOURCES} ${HEADERS})
set_target_properties(ha_diamond PROPERTIES PREFIX "")

if(WITH_TESTING)
        include_directories(${PROJECT_SOURCE_DIR}/test
                            ${PROJECT_SOURCE_DIR}/test/gtest ${PROJECT_SOURCE_DIR}/test/gtest/include
                            ${PROJECT_SOURCE_DIR}/test/gmock ${PROJECT_SOURCE_DIR}/test/gmock/include)
	file(GLOB HEADERS ${PROJECT_SOURCE_DIR}/test/*.h)
	aux_source_directory(${PROJECT_SOURCE_DIR}/src TEST_SOURCES)
        add_executable(diamond_test ${PROJECT_SOURCE_DIR}/test/gtest/src/gtest-all.cc ${PROJECT_SOURCE_DIR}/test/gmock/src/gmock-all.cc
                                    ${TEST_SOURCES} ${SOURCES} ${HEADERS})
	gtest_add_tests(diamond_test "" ${TEST_SOURCES})
endif(WITH_TESTING)

