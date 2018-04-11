//
// Created by oleg on 3/30/18.
//

#include "RuleFilterParser.hpp"

#include "RuleFilter.hpp"
#include "TCPRuleFilterParser.hpp"
#include "UDPRuleFilterParser.hpp"
#include "common/Utils.hpp"

std::unique_ptr<RuleFilterParser> RuleFilterParser::build_parser()
{
    return std::unique_ptr<RuleFilterParser>(
            std::make_unique<TCPRuleFilterParser>(
                    std::make_unique<UDPRuleFilterParser>()));
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
        THROW_EXCEPTION("Cannot parse rule: " << rule);
    }
}
