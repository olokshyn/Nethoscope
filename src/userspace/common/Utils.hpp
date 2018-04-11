//
// Created by oleg on 4/10/18.
//

#ifndef NETHOSCOPE_UTILS_HPP
#define NETHOSCOPE_UTILS_HPP

#include <cstring>
#include <cerrno>

#include <sstream>
#include <stdexcept>

#define THROW_EXCEPTION(message) \
    { \
        std::stringstream stream; \
        stream << message; \
        throw std::runtime_error(stream.str()); \
    }

#define THROW_SYSTEM_EXCEPTION(message, status) \
    if (status != 0) THROW_EXCEPTION(message << ": " << strerror(status)) \
    THROW_EXCEPTION(message)

#define THROW_SYSTEM_ERRNO_EXCEPTION(message) \
    int err = errno; \
    THROW_SYSTEM_EXCEPTION(message, err)

#endif //NETHOSCOPE_UTILS_HPP
