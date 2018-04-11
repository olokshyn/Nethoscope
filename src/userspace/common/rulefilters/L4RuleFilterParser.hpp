//
// Created by oleg on 4/10/18.
//

#ifndef NETHOSCOPE_L4RULEFILTERPARSER_HPP
#define NETHOSCOPE_L4RULEFILTERPARSER_HPP

#include <string>
#include <sstream>
#include <iterator>
#include <limits>

#include "RuleFilterParser.hpp"
#include "common/Utils.hpp"

template <typename ProtoType>
class L4RuleFilterParser : public RuleFilterParser
{
public:
    explicit L4RuleFilterParser(std::unique_ptr<RuleFilterParser> next_parser = nullptr);

private:
    bool can_parse(const std::string& rule) const override;
    std::unique_ptr<RuleFilter> do_parse(const std::string& rule) const override;
};


template <typename ProtoType>
L4RuleFilterParser<ProtoType>::L4RuleFilterParser(std::unique_ptr<RuleFilterParser> next_parser)
        : RuleFilterParser(std::move(next_parser))
{}

template <typename ProtoType>
bool L4RuleFilterParser<ProtoType>::can_parse(const std::string& rule) const
{
    return rule.find(std::string(ProtoType::proto_name) + " ") == 0;
}

template <typename ProtoType>
typename ProtoType::port_t parse_port(const std::string& port_str)
{
    size_t idx = 0;
    int port = std::stoi(port_str, &idx);
    if (idx != port_str.size()
        || port < std::numeric_limits<typename ProtoType::port_t>::min()
        || port > std::numeric_limits<typename ProtoType::port_t>::max()
        || port == static_cast<int>(ProtoType::no_port))
    {
        THROW_EXCEPTION("Invalid " << ProtoType::proto_name << " port value: " << port_str);
    }
    return static_cast<typename ProtoType::port_t>(port);
}

template <typename ProtoType>
std::unique_ptr<RuleFilter> L4RuleFilterParser<ProtoType>::do_parse(const std::string& rule) const
{
    std::istringstream stream(rule);
    auto iter = std::istream_iterator<std::string>(stream);
    auto end = std::istream_iterator<std::string>();
    if (iter == end || *iter++ != ProtoType::proto_name)
    {
        THROW_EXCEPTION("Invalid " << ProtoType::proto_name << " filter rule");
    }

    typename ProtoType::port_t source_port = ProtoType::no_port;
    typename ProtoType::port_t destination_port = ProtoType::no_port;
    while (iter != end)
    {
        const std::string token = *iter++;
        if (token == "src")
        {
            if (iter == end)
            {
                THROW_EXCEPTION("Source port is not specified");
            }
            source_port = parse_port<ProtoType>(*iter++);
        }
        else if (token == "dst")
        {
            if (iter == end)
            {
                THROW_EXCEPTION("Destination port is not specified");
            }
            destination_port = parse_port<ProtoType>(*iter++);
        }
    }

    return std::make_unique<ProtoType>(source_port, destination_port);
}

#endif //NETHOSCOPE_L4RULEFILTERPARSER_HPP
