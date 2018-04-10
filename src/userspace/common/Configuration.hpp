//
// Created by oleg on 4/3/18.
//

#ifndef NETHOSCOPE_CONFIGURATION_HPP
#define NETHOSCOPE_CONFIGURATION_HPP

#include <string>

class SystemCommand;

class Configuration
{
public:
    static const Configuration& instance(std::string iptables_cmd = "",
                                         std::string netns = "");

    static void set_iptables_cmd(std::string iptables_cmd);
    static void set_netns(std::string netns);

public:
    void prepare_iptables_command(SystemCommand& command) const;

private:
    static Configuration& _instance(std::string iptables_cmd = "",
                                    std::string netns = "");

private:
    Configuration(std::string iptables_cmd = "",
                  std::string netns = "");

private:
    std::string m_iptables_cmd;
    std::string m_netns;
};


#endif //NETHOSCOPE_CONFIGURATION_HPP
