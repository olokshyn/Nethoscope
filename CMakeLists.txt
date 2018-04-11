cmake_minimum_required(VERSION 3.6)
project(nethoscope)

set(CMAKE_C_STANDARD  11)
set(CMAKE_CXX_STANDARD 14)

include_directories(src/userspace)

file(GLOB common src/userspace/common/*.*pp)
file(GLOB rulefilters src/userspace/common/rulefilters/*.*pp)

file(GLOB iptables src/userspace/iptables/*.*pp)

set(SOURCE_FILES
        main.cpp
        ${common}
        ${rulefilters}
        ${iptables})
add_executable(${PROJECT_NAME} ${SOURCE_FILES})