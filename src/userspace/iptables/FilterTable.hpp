//
// Created by oleg on 4/2/18.
//

#ifndef NETHOSCOPE_FILTERTABLE_HPP
#define NETHOSCOPE_FILTERTABLE_HPP

#include "Table.hpp"
#include "Chain.hpp"

class FilterTable : public Table
{
public:
    FilterTable();

    void dump(SystemCommand& stream) const override;

private:
    Chain* input_chain() override;
    Chain* forward_chain() override;
    Chain* output_chain() override;

private:
    Chain m_input_chain;
    Chain m_forward_chain;
    Chain m_output_chain;
};

#endif //NETHOSCOPE_FILTERTABLE_HPP
