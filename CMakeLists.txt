cmake_minimum_required(VERSION 3.6)
project(nethoscope)

set(CMAKE_C_STANDARD  11)
set(CMAKE_CXX_STANDARD 14)

include_directories(src/userspace)

set(SOURCE_FILES
        main.cpp
        src/userspace/iptables/RuleFilter.hpp
        src/userspace/iptables/TCPRuleFilter.cpp
        src/userspace/iptables/TCPRuleFilter.hpp
        src/userspace/iptables/RuleFilterParser.cpp
        src/userspace/iptables/RuleFilterParser.hpp
        src/userspace/iptables/TCPRuleFilterParser.cpp
        src/userspace/iptables/TCPRuleFilterParser.hpp
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