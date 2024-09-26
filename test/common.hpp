#pragma once

#include <cstdio>
#include <filesystem>

#include "TRC.h"

namespace Common
{
    bool deleteFile(const std::string &name)
    {
        return !std::remove(name.c_str());
    }

    bool checkFileExists(const std::string &name)
    {
        return std::filesystem::exists(name);
    }

    bool checkFileExistsWithContent(const std::string &name, const std::vector<std::string> &texts)
    {
        if (!checkFileExists(name))
        {
            return false;
        }

        std::ifstream file(name);
        if (!file.is_open())
        {
            return false;
        }

        bool found = true;
        std::string line;
        
        while (std::getline(file, line) && found)
        {
            found = false;
            for (const auto &text : texts)
            {
                if (std::string::npos != line.find(text))
                {
                    found = true;
                    break;
                }
            }
        }

        return found;
    }
};