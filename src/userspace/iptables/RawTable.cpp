//
// Created by oleg on 4/2/18.
//

#include "RawTable.hpp"

#include <iostream>

RawTable::RawTable()
        : m_prerouting_chain(Chain::ChainType::PREROUTING),
          m_output_chain(Chain::ChainType::OUTPUT)
{}

void RawTable::dump(std::ostream& stream) const
{
    stream << "-t " << table_name(TableType::RAW) << " ";
}

Chain* RawTable::prerouting_chain()
{
    return &m_prerouting_chain;
}

Chain* RawTable::output_chain()
{
    return &m_output_chain;
}
