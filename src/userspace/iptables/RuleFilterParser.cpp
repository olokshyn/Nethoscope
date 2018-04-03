//
// Created by oleg on 3/30/18.
//

#include "RuleFilterParser.hpp"

#include "RuleFilter.hpp"
#include "TCPRuleFilterParser.hpp"

std::unique_ptr<RuleFilterParser> RuleFilterParser::build_parser()
{
    return std::unique_ptr<RuleFilterParser>(new TCPRuleFilterParser());
}

RuleFilterParser::RuleFilterParser(std::unique_ptr<RuleFilterParser> next_parser)
        : m_next_parser(std::move(next_parser))
{}

std::unique_ptr<RuleFilter> RuleFilterParser::parse(const std::string& rule) const
{
    if (can_parse(rule))
    {
        return do_parse(rule);
    }
    else if (m_next_parser)
    {
        return m_next_parser->parse(rule);
    }
    else
    {
        throw std::runtime_error("Cannot parse rule");
    }
}
