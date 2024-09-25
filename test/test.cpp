#include "TRC.h"

class A
{
public:
    A()
    {
        TRC::Trace(TRC::Type::INFO, "%s", __PRETTY_FUNCTION__);
    }
};

int main(int argc, char *argv[])
{
    TRC::Trace::setTraceFile("");

    A a;
    
    for (std::size_t i = 0; i < 5; ++i)
    {
        TRC::Trace block(TRC::BLOCK, "Block %d %s", i, __PRETTY_FUNCTION__);

        TRC::Trace info(TRC::BLOCK, "Info %d", i);
        TRC::Trace warrning(TRC::WARRNING, "Warrning %d", i);
        TRC::Trace error(TRC::ERROR, "Error %d", i);
    }

    return 0;
}