//
// Created by oleg on 4/2/18.
//

#include "Rule.hpp"

#include <cstdlib>

#include <sstream>

#include "common/rulefilters/RuleFilter.hpp"
#include "common/SystemCommand.hpp"
#include "common/Configuration.hpp"
#include "Table.hpp"
#include "Chain.hpp"

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
    SystemCommand command;
    Configuration::instance().prepare_iptables_command(command);

    table.dump(command);
    command << (add ? (first ? "-I " : "-A ") : "-D ");
    chain.dump(command);
    if (first)
    {
        command << "1 ";
    }

    if (m_filter)
    {
        m_filter->dump_iptables(command);
    }

    command << "-j LOG";

    command.execute();
}
