#pragma once

#include <filesystem>

#include "TRC.h"

namespace Common
{
    bool checkFileExists(const std::string &fileName)
    {
        return std::filesystem::exists(fileName);
    }

    bool checkFileContent(const std::string &fileName, const std::string &expectedLine)
    {
        std::ifstream file(fileName);
        if (!file.is_open())
        {
            std::cerr << "Could not open file: " << fileName << std::endl;
            return false;
        }

        std::string line;
        if (std::getline(file, line))
        {
            return line == expectedLine;
        }

        return false;
    }
};