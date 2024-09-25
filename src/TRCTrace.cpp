#include "TRCTrace.h"

TRC::File TRC::Trace::file_("trace.txt");
std::size_t TRC::Trace::tabs_ = 0;

TRC::Trace::Trace(TRC::Type type, const char *format, ...) : type_(type)
{
    va_list args;
    va_start(args, format);

    std::size_t size = 1024;
    std::vector<char> buffer(size);

    int needed = vsnprintf(buffer.data(), size, format, args);

    if (needed >= size)
    {
        buffer.resize(needed + 1);
        vsnprintf(buffer.data(), buffer.size(), format, args);
    }

    va_end(args);

    buffer_ = std::string(buffer.data());

    if (TRC::Type::BLOCK == type_)
    {
        tabs_++;
    }

    print();
}

TRC::Trace::~Trace()
{
    if (TRC::Type::BLOCK == type_)
    {
        print();
        tabs_--;
    }
}

void TRC::Trace::print() const
{
    std::ostringstream oss;
    if (tabs_)
    {
        oss << std::string(tabs_ - 1, '\t');
    }
    oss << "[" << TRC::toString(type_) << " - " << getCurrentDateTime() << "]: ";
    oss << buffer_;

    std::string text = oss.str();
    
    std::cout << text << std::endl;
    file_.write(text);
}

void TRC::Trace::setTraceFileName(const std::string &name)
{
    file_.setName(name);
}

std::string TRC::Trace::getTraceFileName()
{
    return file_.getName();
}

std::string TRC::Trace::getCurrentDateTime() const
{
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");

    return oss.str();
}