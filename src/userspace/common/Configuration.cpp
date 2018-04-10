//
// Created by oleg on 4/3/18.
//

#include "Configuration.hpp"

#include "common/SystemCommand.hpp"

#define USE_SUDO 1

const Configuration& Configuration::instance(std::string iptables_cmd,
                                             std::string netns)
{

    return _instance(std::move(iptables_cmd), std::move(netns));
}

void Configuration::set_iptables_cmd(std::string iptables_cmd)
{
    _instance().m_iptables_cmd = std::move(iptables_cmd);
}

void Configuration::set_netns(std::string netns)
{
    _instance().m_netns = std::move(netns);
}

void Configuration::prepare_iptables_command(SystemCommand& command) const
{
#if defined(USE_SUDO) && USE_SUDO
    command << "sudo ";
#endif

    if (!m_netns.empty())
    {
        command << "ip netns exec " << m_netns << " ";
    }
    command << m_iptables_cmd << " ";
}

Configuration& Configuration::_instance(std::string iptables_cmd, std::string netns)
{
    static Configuration configuration(std::move(iptables_cmd),
                                       std::move(netns));
    return configuration;
}

Configuration::Configuration(std::string iptables_cmd,
                             std::string netns)
        : m_iptables_cmd(std::move(iptables_cmd)),
          m_netns(std::move(netns))
{}
