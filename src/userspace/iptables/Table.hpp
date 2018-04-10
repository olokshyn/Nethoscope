//
// Created by oleg on 3/30/18.
//

#ifndef NETHOSCOPE_TABLE_HPP
#define NETHOSCOPE_TABLE_HPP

#include <iosfwd>

#include "Chain.hpp"

class Rule;
class SystemCommand;

class Table
{
public:
    enum class TableType
    {
        RAW,
        FILTER,
        NAT,
        MANGLE
    };

public:
    virtual ~Table() = default;

    void add_rule(Chain::ChainType chain_type, const Rule& rule);
    void remove_rule(Chain::ChainType chain_type, const Rule& rule);
    void add_rule(const Rule& rule);
    void remove_rule(const Rule& rule);

    virtual void dump(SystemCommand& stream) const = 0;

protected:
    const char* table_name(TableType table_type) const;

private:
    virtual Chain* prerouting_chain();
    virtual Chain* input_chain();
    virtual Chain* forward_chain();
    virtual Chain* output_chain();
    virtual Chain* postrouting_chain();

    Chain* find_chain(Chain::ChainType chain_type);

    template <typename Func>
    void apply_to_all_chains(Func func, const Rule& rule)
    {
        func(Chain::ChainType::PREROUTING, rule);
        func(Chain::ChainType::INPUT, rule);
        func(Chain::ChainType::FORWARD, rule);
        func(Chain::ChainType::OUTPUT, rule);
        func(Chain::ChainType::POSTROUTING, rule);
    }
};

namespace std
{

template<>
struct hash<Table::TableType>
{
    typedef Table::TableType argument_type;
    typedef std::size_t result_type;

    result_type operator()(argument_type value) const noexcept
    {
        return static_cast<result_type>(value);
    }
};

}

#endif //NETHOSCOPE_TABLE_HPP
