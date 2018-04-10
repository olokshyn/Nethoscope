//
// Created by oleg on 4/2/18.
//

#include "NatTable.hpp"

#include "common/SystemCommand.hpp"

NatTable::NatTable()
        : m_prerouting_chain(Chain::ChainType::PREROUTING),
          m_input_chain(Chain::ChainType::INPUT),
          m_output_chain(Chain::ChainType::OUTPUT),
          m_postrouting_chain(Chain::ChainType::POSTROUTING)
{}

void NatTable::dump(SystemCommand& stream) const
{
    stream << "-t " << table_name(TableType::NAT) << " ";
}

Chain* NatTable::prerouting_chain()
{
    return &m_prerouting_chain;
}

Chain* NatTable::input_chain()
{
    return &m_input_chain;
}

Chain* NatTable::output_chain()
{
    return &m_output_chain;
}

Chain* NatTable::postrouting_chain()
{
    return &m_postrouting_chain;
}
