//
// Created by oleg on 3/30/18.
//

#ifndef NETHOSCOPE_TCPRULEFILTER_HPP
#define NETHOSCOPE_TCPRULEFILTER_HPP

#include "L4RuleFilter.hpp"

constexpr const char tcp_proto_name[] = "tcp";

using TCPRuleFilter = L4RuleFilter<tcp_proto_name>;

#endif //NETHOSCOPE_TCPRULEFILTER_HPP
