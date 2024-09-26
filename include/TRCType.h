#pragma once

#include <iostream>

namespace TRC
{
    constexpr const char *TYPE_INFO_STR = "INFO";
    constexpr const char *TYPE_WARRNING_STR = "WARRNING";
    constexpr const char *TYPE_ERROR_STR = "ERROR";
    constexpr const char *TYPE_BLOCK_STR = "BLOCK";

    enum Type
    {
        INFO = 0,
        WARRNING,
        ERROR,
        BLOCK
    };

    std::string toString(const Type &type);
};