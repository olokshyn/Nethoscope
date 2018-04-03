#include <iostream>
#include <fstream>

#include "iptables/Conductor.hpp"

int main(int argc, char* argv[])
{
    try
    {
        if (argc < 2)
        {
            std::cerr << "Rules file is not specified" << std::endl;
        }
        const char* rules_filename = argv[1];

        std::ifstream rule_stream;
        rule_stream.exceptions(std::ios::failbit | std::ios::badbit);
        rule_stream.open(rules_filename);

        Conductor conductor(rule_stream);

        return 0;
    }
    catch (const std::exception& exc)
    {
        std::cerr << "Error: " << exc.what();
    }
    return 1;
}