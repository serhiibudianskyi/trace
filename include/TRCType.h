#pragma once

#include <iostream>

namespace TRC
{
    enum Type
    {
        INFO = 0,
        WARRNING,
        ERROR,
        BLOCK
    };

    std::string toString(Type type);
};