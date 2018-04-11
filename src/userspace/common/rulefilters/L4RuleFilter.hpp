//
// Created by oleg on 4/10/18.
//

#ifndef NETHOSCOPE_L4RULEFILTER_HPP
#define NETHOSCOPE_L4RULEFILTER_HPP

#include <string>

#include "RuleFilter.hpp"
#include "common/SystemCommand.hpp"

template <const char* const ProtoName>
class L4RuleFilter : public RuleFilter
{
public:
    typedef unsigned short int port_t;

public:
    static const port_t no_port = 0;
    static constexpr const char* const proto_name = ProtoName;

public:
    explicit L4RuleFilter(port_t source_port = no_port,
                          port_t destination_port = no_port);

    void dump_iptables(SystemCommand& stream) const override;

private:
    const port_t m_source_port;
    const port_t m_destination_port;
};

template <const char* const ProtoName>
L4RuleFilter<ProtoName>::L4RuleFilter(port_t source_port, port_t destination_port)
        : m_source_port(source_port),
          m_destination_port(destination_port)
{}

template <const char* const ProtoName>
void L4RuleFilter<ProtoName>::dump_iptables(SystemCommand& stream) const
{
    stream << "-p " << ProtoName << " ";
    if (m_source_port != no_port)
    {
        stream << "--sport " << m_source_port << " ";
    }
    if (m_destination_port != no_port)
    {
        stream << "--dport " << m_destination_port << " ";
    }
}

#endif //NETHOSCOPE_L4RULEFILTER_HPP
