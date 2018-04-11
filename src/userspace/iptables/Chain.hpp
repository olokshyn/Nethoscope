//
// Created by oleg on 3/30/18.
//

#ifndef NETHOSCOPE_CHAIN_HPP
#define NETHOSCOPE_CHAIN_HPP

#include <string>

class Rule;
class SystemCommand;

class Chain
{
public:
    enum class ChainType
    {
        PREROUTING,
        INPUT,
        FORWARD,
        OUTPUT,
        POSTROUTING
    };

public:
    explicit Chain(ChainType type);

    void dump(SystemCommand& stream) const;

private:
    const ChainType m_type;
};

namespace std
{

template<>
struct hash<Chain::ChainType>
{
    typedef Chain::ChainType argument_type;
    typedef std::size_t result_type;

    result_type operator()(argument_type value) const noexcept
    {
        return static_cast<result_type>(value);
    }
};

}

#endif //NETHOSCOPE_CHAIN_HPP
