//
// Created by oleg on 3/30/18.
//

#include "Chain.hpp"

#include <unordered_map>
#include <sstream>

#include "Rule.hpp"

namespace
{

std::unordered_map<Chain::ChainType, const char* const> chain_names = {
        {Chain::ChainType::PREROUTING, "PREROUTING"},
        {Chain::ChainType::INPUT, "INPUT"},
        {Chain::ChainType::FORWARD, "FORWARD"},
        {Chain::ChainType::OUTPUT, "OUTPUT"},
        {Chain::ChainType::POSTROUTING, "POSTROUTING"}
};

const char* chain_name(Chain::ChainType chain_type)
{
    auto iter = chain_names.find(chain_type);
    if (iter == chain_names.end())
    {
        throw std::runtime_error("Invalid chain type");
    }
    return iter->second;
}

}

Chain::Chain(ChainType type)
        : m_type(type)
{}

void Chain::dump(std::ostream& stream) const
{
    stream << chain_name(m_type) << " ";
}

Chain::ChainType Chain::type() const
{
    return m_type;
}