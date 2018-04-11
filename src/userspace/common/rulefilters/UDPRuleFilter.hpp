//
// Created by oleg on 4/11/18.
//

#ifndef NETHOSCOPE_UDPRULEFILTER_HPP
#define NETHOSCOPE_UDPRULEFILTER_HPP

#include "L4RuleFilter.hpp"

constexpr const char udp_proto_name[] = "udp";

using UDPRuleFilter = L4RuleFilter<udp_proto_name>;

#endif //NETHOSCOPE_UDPRULEFILTER_HPP
