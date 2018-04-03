//
// Created by oleg on 3/30/18.
//

#ifndef NETHOSCOPE_RULEFILTER_HPP
#define NETHOSCOPE_RULEFILTER_HPP

#include <ostream>

class RuleFilter
{
public:
    virtual ~RuleFilter() = default;

    virtual void dump(std::ostream& stream) const = 0;
};


#endif //NETHOSCOPE_RULEFILTER_HPP
