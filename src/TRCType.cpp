#include "TRCType.h"

std::string TRC::toString(TRC::Type type)
{
    std::string result;

    switch (type)
    {
    case TRC::Type::WARRNING:
        result = "WARRNING";
        break;
    case TRC::Type::ERROR:
        result = "ERROR";
        break;
    case TRC::Type::BLOCK:
        result = "BLOCK";
        break;
    case TRC::Type::INFO:
    default:
        result = "INFO";
        break;
    }

    return result;
}