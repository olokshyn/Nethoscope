cmake_minimum_required(VERSION 3.6)
project(nethoscope)

set(CMAKE_C_STANDARD  11)
set(CMAKE_CXX_STANDARD 14)

include_directories(src/userspace)

file(GLOB common src/userspace/common/*.*pp)
file(GLOB rulefilters src/userspace/common/rulefilters/*.*pp)

set(SOURCE_FILES
        main.cpp
        ${common}
        ${rulefilters}
        src/userspace/iptables/Chain.cpp
        src/userspace/iptables/Chain.hpp
        src/userspace/iptables/Table.cpp
        src/userspace/iptables/Table.hpp
        src/userspace/iptables/RawTable.cpp
        src/userspace/iptables/RawTable.hpp
        src/userspace/iptables/FilterTable.cpp
        src/userspace/iptables/FilterTable.hpp
        src/userspace/iptables/NatTable.cpp
        src/userspace/iptables/NatTable.hpp
        src/userspace/iptables/MangleTable.cpp
        src/userspace/iptables/MangleTable.hpp
        src/userspace/iptables/Conductor.cpp
        src/userspace/iptables/Conductor.hpp
        src/userspace/iptables/Rule.cpp
        src/userspace/iptables/Rule.hpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})