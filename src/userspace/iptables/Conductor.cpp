//
// Created by oleg on 4/2/18.
//

#include "Conductor.hpp"

#include <cassert>

#include <iostream>
#include <iterator>

#include "RawTable.hpp"
#include "FilterTable.hpp"
#include "NatTable.hpp"
#include "MangleTable.hpp"

#include "common/rulefilters/RuleFilterParser.hpp"
#include "common/rulefilters/RuleFilter.hpp"

Conductor::Conductor(std::istream& rule_stream)
        : m_raw_table(new RawTable()),
          m_filter_table(new FilterTable()),
          m_nat_table(new NatTable()),
          m_mangle_table(new MangleTable())
{
    auto filter_parser = RuleFilterParser::build_parser();

    std::string line;
    rule_stream.exceptions(std::ios::badbit);
    while (std::getline(rule_stream, line))
    {
        rule_stream.exceptions(std::ios::failbit | std::ios::badbit);
        Rule rule(filter_parser->parse(line));

        m_raw_table->add_rule(rule);
        m_filter_table->add_rule(rule);
        m_nat_table->add_rule(rule);
        m_mangle_table->add_rule(rule);

        m_rules.push_back(std::move(rule));

        rule_stream.exceptions(std::ios::badbit);
    }
}

Conductor::~Conductor()
{
    for (auto iter = m_rules.rbegin(); iter != m_rules.rend(); ++iter)
    {
        try
        {
            m_raw_table->remove_rule(*iter);
            m_filter_table->remove_rule(*iter);
            m_nat_table->remove_rule(*iter);
            m_mangle_table->remove_rule(*iter);
        }
        catch (const std::exception& exc)
        {
            std::cerr << "Failed to remove rule" << std::endl;
        }
    }
}

void Conductor::add_rule(Table::TableType table_type, const Rule& rule)
{
    Table* table = nullptr;
    switch (table_type)
    {
    case Table::TableType::RAW:
        table = m_raw_table.get();
        break;
    case Table::TableType::FILTER:
        table = m_filter_table.get();
        break;
    case Table::TableType::NAT:
        table = m_nat_table.get();
        break;
    case Table::TableType::MANGLE:
        table = m_mangle_table.get();
        break;
    }

    assert(table);
    table->add_rule(rule);
}

void Conductor::add_rule(const Rule& rule)
{
    add_rule(Table::TableType::RAW, rule);
    add_rule(Table::TableType::FILTER, rule);
    add_rule(Table::TableType::NAT, rule);
    add_rule(Table::TableType::MANGLE, rule);
}
