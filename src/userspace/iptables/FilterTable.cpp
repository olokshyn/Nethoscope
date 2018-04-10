//
// Created by oleg on 4/2/18.
//

#include "FilterTable.hpp"

#include "common/SystemCommand.hpp"

FilterTable::FilterTable()
        : m_input_chain(Chain::ChainType::INPUT),
          m_forward_chain(Chain::ChainType::FORWARD),
          m_output_chain(Chain::ChainType::OUTPUT)
{}

void FilterTable::dump(SystemCommand& stream) const
{
    stream << "-t " << table_name(TableType::FILTER) << " ";
}

Chain* FilterTable::input_chain()
{
    return &m_input_chain;
}

Chain* FilterTable::forward_chain()
{
    return &m_forward_chain;
}

Chain* FilterTable::output_chain()
{
    return &m_output_chain;
}
