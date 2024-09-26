#include "TRCType.h"

std::string TRC::toString(const TRC::Type &type)
{
    std::string result;

    switch (type)
    {
    case TRC::Type::WARRNING:
        result = TRC::TYPE_WARRNING_STR;
        break;
    case TRC::Type::ERROR:
        result = TRC::TYPE_ERROR_STR;
        break;
    case TRC::Type::BLOCK:
        result = TRC::TYPE_BLOCK_STR;
        break;
    case TRC::Type::INFO:
    default:
        result = TRC::TYPE_INFO_STR;
        break;
    }

    return result;
}