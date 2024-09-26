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
    constexpr std::size_t TRACE_FILE_SIZE = 1024;
    constexpr const char *TRACE_FILE_NAME = "trace.txt";
    constexpr const char *TRACE_DATETIME_FORMAT = "%Y-%m-%d %H:%M:%S";

    class Trace final
    {
        friend class File;

    public:
        explicit Trace(const Type &type, const char *format, ...);
        ~Trace();

        static void setTraceFileName(const std::string &name);
        static std::string getTraceFileName();

        Trace(Trace &&) = delete;
        Trace(const Trace &) = delete;
        Trace &operator=(Trace &&) = delete;
        Trace &operator=(const Trace &) = delete;

    protected:
        void print() const;

        std::string getCurrentDateTime() const;

    private:
        Type type_;
        std::string buffer_;

        static File file_;
        static std::size_t tabs_;
    };
};