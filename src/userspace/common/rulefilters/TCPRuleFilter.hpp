//
// Created by oleg on 3/30/18.
//

#ifndef NETHOSCOPE_TCPRULEFILTER_HPP
#define NETHOSCOPE_TCPRULEFILTER_HPP

#include "RuleFilter.hpp"

class TCPRuleFilter : public RuleFilter
{
public:
    typedef unsigned short int port_t;

public:
    static const port_t no_port = 0;

public:
    explicit TCPRuleFilter(port_t source_port = no_port,
                           port_t destination_port = no_port);

    void dump_iptables(SystemCommand& stream) const override;

private:
    const port_t m_source_port;
    const port_t m_destination_port;
};


#endif //NETHOSCOPE_TCPRULEFILTER_HPP
