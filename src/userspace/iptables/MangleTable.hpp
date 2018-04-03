//
// Created by oleg on 4/2/18.
//

#ifndef NETHOSCOPE_MANGLETABLE_HPP
#define NETHOSCOPE_MANGLETABLE_HPP

#include "Table.hpp"
#include "Chain.hpp"

class MangleTable : public Table
{
public:
    MangleTable();

    void dump(std::ostream& stream) const override;

private:
    Chain* prerouting_chain() override;
    Chain* input_chain() override;
    Chain* forward_chain() override;
    Chain* output_chain() override;
    Chain* postrouting_chain() override;

private:
    Chain m_prerouting_chain;
    Chain m_input_chain;
    Chain m_forward_chain;
    Chain m_output_chain;
    Chain m_postrouting_chain;
};


#endif //NETHOSCOPE_MANGLETABLE_HPP
