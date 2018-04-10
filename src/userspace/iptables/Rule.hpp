//
// Created by oleg on 4/2/18.
//

#ifndef NETHOSCOPE_RULE_HPP
#define NETHOSCOPE_RULE_HPP

#include <memory>

class RuleFilter;
class Table;
class Chain;

class Rule
{
public:
    explicit Rule(std::unique_ptr<RuleFilter> filter);

    void add_rule(const Table& table, const Chain& chain) const;
    void remove_rule(const Table& table, const Chain& chain) const;

private:
    void toggle_rule(bool add, bool first, const Table& table, const Chain& chain) const;

private:
    std::unique_ptr<RuleFilter> m_filter;
};


#endif //NETHOSCOPE_RULE_HPP
