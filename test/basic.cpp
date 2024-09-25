#include "TRC.h"

int main(int argc, char *argv[])
{
    TRC::Trace::setTraceFile("");
    
    for (std::size_t i = 0; i < 5; ++i)
    {
        TRC::Trace block(TRC::BLOCK, "Block %d %s", i, __PRETTY_FUNCTION__);

        TRC::Trace info(TRC::BLOCK, "Info %d", i);
        TRC::Trace warrning(TRC::WARRNING, "Warrning %d", i);
        TRC::Trace error(TRC::ERROR, "Error %d", i);
    }

    return 0;
}