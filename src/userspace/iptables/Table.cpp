//
// Created by oleg on 3/30/18.
//

#include "Table.hpp"

#include <unordered_map>

#include "Rule.hpp"

namespace
{

std::unordered_map<Table::TableType, const char* const> table_names = {
        {Table::TableType::RAW,    "raw"},
        {Table::TableType::FILTER, "filter"},
        {Table::TableType::NAT,    "nat"},
        {Table::TableType::MANGLE, "mangle"}
};

}

void Table::add_rule(Chain::ChainType chain_type, const Rule& rule)
{
    Chain* chain = find_chain(chain_type);
    if (chain)
    {
        rule.add_rule(*this, *chain);
    }
}

void Table::remove_rule(Chain::ChainType chain_type, const Rule& rule)
{
    Chain* chain = find_chain(chain_type);
    if (chain)
    {
        rule.remove_rule(*this, *chain);
    }
}

void Table::add_rule(const Rule& rule)
{
    apply_to_all_chains([this](auto&&... args) -> decltype(auto)
                        {
                            return add_rule(std::forward<decltype(args)>(args)...);
                        },
                        rule);
}

void Table::remove_rule(const Rule& rule)
{
    apply_to_all_chains([this](auto&&... args) -> decltype(auto)
                        {
                            return remove_rule(std::forward<decltype(args)>(args)...);
                        },
                        rule);
}

const char* Table::table_name(TableType table_type) const
{
    auto iter = table_names.find(table_type);
    if (iter == table_names.end())
    {
        throw std::runtime_error("Invalid table type");
    }
    return iter->second;
}

Chain* Table::prerouting_chain()
{
    return nullptr;
}

Chain* Table::input_chain()
{
    return nullptr;
}

Chain* Table::forward_chain()
{
    return nullptr;
}

Chain* Table::output_chain()
{
    return nullptr;
}

Chain* Table::postrouting_chain()
{
    return nullptr;
}

Chain* Table::find_chain(Chain::ChainType chain_type)
{
    switch (chain_type)
    {
    case Chain::ChainType::PREROUTING:
        return prerouting_chain();
    case Chain::ChainType::INPUT:
        return input_chain();
    case Chain::ChainType::FORWARD:
        return forward_chain();
    case Chain::ChainType::OUTPUT:
        return output_chain();
    case Chain::ChainType::POSTROUTING:
        return postrouting_chain();
    }
    return nullptr;
}
