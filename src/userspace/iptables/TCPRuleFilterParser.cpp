//
// Created by oleg on 3/30/18.
//

#include "TCPRuleFilterParser.hpp"

#include <sstream>
#include <iterator>
#include <limits>

#include "TCPRuleFilter.hpp"

namespace
{

TCPRuleFilter::port_t parse_port(const std::string& port_str)
{
    size_t idx = 0;
    int port = std::stoi(port_str, &idx);
    if (idx != port_str.size()
        || port < std::numeric_limits<TCPRuleFilter::port_t>::min()
        || port > std::numeric_limits<TCPRuleFilter::port_t>::max()
        || port == static_cast<int>(TCPRuleFilter::no_port))
    {
        throw std::runtime_error("Invalid TCP port value: " + port_str);
    }
    return static_cast<TCPRuleFilter::port_t>(port);
}

}

TCPRuleFilterParser::TCPRuleFilterParser(std::unique_ptr<RuleFilterParser> next_parser)
        : RuleFilterParser(std::move(next_parser))
{}

bool TCPRuleFilterParser::can_parse(const std::string& rule) const
{
    return rule.find("tcp ") == 0;
}

std::unique_ptr<RuleFilter> TCPRuleFilterParser::do_parse(const std::string& rule) const
{
    std::istringstream stream(rule);
    auto iter = std::istream_iterator<std::string>(stream);
    auto end = std::istream_iterator<std::string>();
    if (iter == end || *iter++ != "tcp")
    {
        throw std::runtime_error("Invalid tcp filter rule");
    }

    TCPRuleFilter::port_t source_port = TCPRuleFilter::no_port;
    TCPRuleFilter::port_t destination_port = TCPRuleFilter::no_port;
    while (iter != end)
    {
        if (*iter++ == "src")
        {
            if (iter == end)
            {
                throw std::runtime_error("Source port is not specified");
            }
            source_port = parse_port(*iter);
        }
        else if (*iter++ == "dst")
        {
            if (iter == end)
            {
                throw std::runtime_error("Destination port is not specified");
            }
            destination_port = parse_port(*iter);
        }
    }

    return std::make_unique<TCPRuleFilter>(source_port, destination_port);
}
