//
// Created by oleg on 3/30/18.
//

#include "TCPRuleFilter.hpp"

#include "common/SystemCommand.hpp"

TCPRuleFilter::TCPRuleFilter(port_t source_port, port_t destination_port)
        : m_source_port(source_port),
          m_destination_port(destination_port)
{}

void TCPRuleFilter::dump_iptables(SystemCommand& stream) const
{
    stream << "-p tcp ";
    if (m_source_port != no_port)
    {
        stream << "--sport " << m_source_port << " ";
    }
    if (m_destination_port != no_port)
    {
        stream << "--dport " << m_destination_port << " ";
    }
}
