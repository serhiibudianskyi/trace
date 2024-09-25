#include "TRCFile.h"

TRC::File::File(const std::string &name) : name_(name)
{
}

void TRC::File::setName(const std::string &name)
{
    name_ = name;
}

std::string TRC::File::getName() const
{
    return name_;
}

void TRC::File::write(const std::string &text)
{
    if (!open())
    {
        return;
    }

    file_ << text << std::endl;

    close();
}

bool TRC::File::open()
{
    if (!file_.is_open())
    {
        file_.open(name_, std::ios::app);
    }

    return file_.is_open();
}

void TRC::File::close()
{
    if (file_.is_open())
    {
        file_.close();
    }
}