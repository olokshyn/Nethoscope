//
// Created by oleg on 4/3/18.
//

#ifndef NETHOSCOPE_SYSTEMCOMMAND_HPP
#define NETHOSCOPE_SYSTEMCOMMAND_HPP

#include <sstream>

class SystemCommand
{
public:
    SystemCommand() = default;
    SystemCommand(SystemCommand&& other) = default;

    int execute(bool throw_on_error = true) const;

    template <typename T>
    void append(const T& command)
    {
        m_stream << command;
    }

private:
    std::stringstream m_stream;
};

template <typename T>
SystemCommand& operator<<(SystemCommand& system_command, const T& command)
{
    system_command.append(command);
    return system_command;
}

#endif //NETHOSCOPE_SYSTEMCOMMAND_HPP
