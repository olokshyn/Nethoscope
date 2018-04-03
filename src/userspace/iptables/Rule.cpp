//
// Created by oleg on 4/2/18.
//

#include "Rule.hpp"

#include <cstdlib>

#include <sstream>

#include "RuleFilter.hpp"
#include "Table.hpp"
#include "Chain.hpp"

namespace
{

const char* const rule_prefix = "sudo ip netns exec test iptables ";

}

Rule::Rule(std::unique_ptr<RuleFilter> filter)
        : m_filter(std::move(filter))
{}

void Rule::add_rule(const Table& table, const Chain& chain) const
{
    toggle_rule(true, true, table, chain);
    toggle_rule(true, false, table, chain);
}

void Rule::remove_rule(const Table& table, const Chain& chain) const
{
    toggle_rule(false, false, table, chain);
    toggle_rule(false, false, table, chain);
}

void Rule::toggle_rule(bool add, bool first, const Table& table, const Chain& chain) const
{
    std::stringstream stream;

    stream << rule_prefix;

    table.dump(stream);
    stream << (add ? (first ? "-I " : "-A ") : "-D ");
    chain.dump(stream);
    if (first)
    {
        stream << "1 ";
    }

    if (m_filter)
    {
        m_filter->dump(stream);
    }

    stream << "-j LOG";

    std::string iptables_rule = stream.str();
    if (system(iptables_rule.c_str()) != 0)
    {
        throw std::runtime_error("Failed to toggle rule: " + iptables_rule);
    }
}
