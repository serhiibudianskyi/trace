#pragma once

#include <ctime>
#include <vector>
#include <iomanip>
#include <cstdarg>
#include <sstream>

#include "TRCType.h"
#include "TRCFile.h"

namespace TRC
{
    class Trace
    {
        friend class File;
    public:
        explicit Trace(Type type, const char *format, ...);
        ~Trace();

        virtual void print() const;

        static void setTraceFile(const std::string &name);

        Trace(Trace &&) = delete;
        Trace(const Trace &) = delete;
        Trace &operator=(Trace &&) = delete;
        Trace &operator=(const Trace &) = delete;

    protected:
        std::string getCurrentDateTime() const;

    private:
        Type type_;
        std::string buffer_;

        static File file_;

        static std::size_t tabs_;
    };
};