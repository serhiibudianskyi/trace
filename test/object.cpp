#include "TRC.h"

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
    Object object;

    return 0;
}