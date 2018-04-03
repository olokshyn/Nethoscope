//
// Created by oleg on 4/2/18.
//

#ifndef NETHOSCOPE_CONDUCTOR_HPP
#define NETHOSCOPE_CONDUCTOR_HPP

#include <memory>
#include <list>
#include <istream>

#include "Table.hpp"
#include "Rule.hpp"

class Conductor
{
public:
    Conductor(std::istream& rule_stream);
    ~Conductor();

    void add_rule(Table::TableType table_type, const Rule& rule);
    void add_rule(const Rule& rule);

private:
    std::unique_ptr<Table> m_raw_table;
    std::unique_ptr<Table> m_filter_table;
    std::unique_ptr<Table> m_nat_table;
    std::unique_ptr<Table> m_mangle_table;

    std::list<Rule> m_rules;
};


#endif //NETHOSCOPE_CONDUCTOR_HPP
