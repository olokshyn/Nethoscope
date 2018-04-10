//
// Created by oleg on 3/30/18.
//

#ifndef NETHOSCOPE_TCPRULEFILTERPARSER_HPP
#define NETHOSCOPE_TCPRULEFILTERPARSER_HPP

#include "RuleFilterParser.hpp"

class TCPRuleFilterParser : public RuleFilterParser
{
public:
    explicit TCPRuleFilterParser(std::unique_ptr<RuleFilterParser> next_parser = nullptr);

private:
    bool can_parse(const std::string& rule) const override;
    std::unique_ptr<RuleFilter> do_parse(const std::string& rule) const override;
};


#endif //NETHOSCOPE_TCPRULEFILTERPARSER_HPP
