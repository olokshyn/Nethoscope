//
// Created by oleg on 4/3/18.
//

#include "SystemCommand.hpp"

#include <cstdlib>

#include "common/Utils.hpp"

int SystemCommand::execute(bool throw_on_error) const
{
    std::string command = m_stream.str();
    int status = system(command.c_str());
    if (status != 0 && throw_on_error)
    {
        THROW_SYSTEM_ERRNO_EXCEPTION("Failed to run command \"" << command << "\"");
    }
    return status;
}
