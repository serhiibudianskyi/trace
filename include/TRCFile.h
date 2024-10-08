#pragma once

#include <fstream>

namespace TRC
{
    class File final
    {
    public:
        explicit File(const std::string &name);
        ~File() = default;

        void setName(const std::string &name);
        std::string getName() const;

        void write(const std::string &text);

        File(File &&) = delete;
        File(const File &) = delete;
        File &operator=(File &&) = delete;
        File &operator=(const File &) = delete;
    
    protected:
        bool open();
        void close();

    private:
        std::string name_;

        std::ofstream file_;
    };
};