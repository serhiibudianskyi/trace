#include "common.hpp"

class Object
{
public:
    Object()
    {
        TRC::Trace(TRC::Type::INFO, "%s", __PRETTY_FUNCTION__);
    }

    ~Object()
    {
        TRC::Trace(TRC::Type::INFO, "%s", __PRETTY_FUNCTION__);
    }
};

int main(int argc, char *argv[])
{
    std::string fileName = "file.txt";
    TRC::Trace::setTraceFileName(fileName);

    Object object;

    return !Common::checkFileExists(fileName);
}