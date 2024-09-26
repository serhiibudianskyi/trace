#include "common.hpp"

int main(int argc, char *argv[])
{
    std::string defaultFileName = TRC::Trace::getTraceFileName();
    
    for (std::size_t i = 0; i < 5; ++i)
    {
        TRC::Trace block(TRC::Type::BLOCK, "Block %d %s", i, __PRETTY_FUNCTION__);
        TRC::Trace info(TRC::Type::INFO, "Info %d", i);
        TRC::Trace warrning(TRC::Type::WARRNING, "Warrning %d", i);
        TRC::Trace error(TRC::Type::ERROR, "Error %d", i);
    }

    bool fileExistsWithContent = Common::checkFileExistsWithContent(defaultFileName, {TRC::toString(TRC::Type::BLOCK), TRC::toString(TRC::Type::INFO), TRC::toString(TRC::Type::WARRNING), TRC::toString(TRC::Type::ERROR)});
    bool fileDeleted = Common::deleteFile(defaultFileName);

    return !(fileExistsWithContent && fileDeleted);
}