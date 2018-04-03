//
// Created by oleg on 4/2/18.
//

#ifndef NETHOSCOPE_NATTABLE_HPP
#define NETHOSCOPE_NATTABLE_HPP

#include "Table.hpp"
#include "Chain.hpp"

class NatTable : public Table
{
public:
    NatTable();

    void dump(std::ostream& stream) const override;

private:
    Chain* prerouting_chain() override;
    Chain* input_chain() override;
    Chain* output_chain() override;
    Chain* postrouting_chain() override;

private:
    Chain m_prerouting_chain;
    Chain m_input_chain;
    Chain m_output_chain;
    Chain m_postrouting_chain;
};


#endif //NETHOSCOPE_NATTABLE_HPP
