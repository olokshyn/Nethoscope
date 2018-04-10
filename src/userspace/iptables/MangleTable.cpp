//
// Created by oleg on 4/2/18.
//

#include "MangleTable.hpp"

#include "common/SystemCommand.hpp"

MangleTable::MangleTable()
        : m_prerouting_chain(Chain::ChainType::PREROUTING),
          m_input_chain(Chain::ChainType::INPUT),
          m_forward_chain(Chain::ChainType::FORWARD),
          m_output_chain(Chain::ChainType::OUTPUT),
          m_postrouting_chain(Chain::ChainType::POSTROUTING)
{}

void MangleTable::dump(SystemCommand& stream) const
{
    stream << "-t " << table_name(TableType::MANGLE) << " ";
}

Chain* MangleTable::prerouting_chain()
{
    return &m_prerouting_chain;
}

Chain* MangleTable::input_chain()
{
    return &m_input_chain;
}

Chain* MangleTable::forward_chain()
{
    return &m_forward_chain;
}

Chain* MangleTable::output_chain()
{
    return &m_output_chain;
}

Chain* MangleTable::postrouting_chain()
{
    return &m_postrouting_chain;
}
