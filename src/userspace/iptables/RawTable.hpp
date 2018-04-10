//
// Created by oleg on 4/2/18.
//

#ifndef NETHOSCOPE_RAWTABLE_HPP
#define NETHOSCOPE_RAWTABLE_HPP

#include "Table.hpp"
#include "Chain.hpp"

class RawTable : public Table
{
public:
    RawTable();

    void dump(SystemCommand& stream) const override;

private:
    Chain* prerouting_chain() override;
    Chain* output_chain() override;

private:
    Chain m_prerouting_chain;
    Chain m_output_chain;
};


#endif //NETHOSCOPE_RAWTABLE_HPP
