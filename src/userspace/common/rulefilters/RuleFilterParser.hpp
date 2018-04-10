//
// Created by oleg on 3/30/18.
//

#ifndef NETHOSCOPE_RULEFILTERPARSER_HPP
#define NETHOSCOPE_RULEFILTERPARSER_HPP

#include <memory>
#include <string>

class RuleFilter;

class RuleFilterParser
{
public:
    static std::unique_ptr<RuleFilterParser> build_parser();

public:
    explicit RuleFilterParser(std::unique_ptr<RuleFilterParser> next_parser = nullptr);
    virtual ~RuleFilterParser() = default;

    std::unique_ptr<RuleFilter> parse(const std::string& rule) const;

private:
    virtual bool can_parse(const std::string& rule) const = 0;
    virtual std::unique_ptr<RuleFilter> do_parse(const std::string& rule) const = 0;

private:
    std::unique_ptr<RuleFilterParser> m_next_parser;
};

#endif //NETHOSCOPE_RULEFILTERPARSER_HPP
