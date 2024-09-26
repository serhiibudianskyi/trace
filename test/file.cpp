#include "common.hpp"

int main(int argc, char *argv[])
{
    std::string firstFileName = "first.txt";
    std::string secondFileName = "second.txt";
    std::string firstFileLine = "This is line in " + firstFileName;
    std::string secondFileLine = "This is line in " + secondFileName;

    TRC::File file(firstFileName);
    file.write(firstFileLine);
    file.setName(secondFileName);
    file.write(secondFileLine);

    bool filesExistWithContent = Common::checkFileExistsWithContent(firstFileName, {firstFileLine}) && Common::checkFileExistsWithContent(secondFileName, {secondFileLine});
    bool filesDeleted = Common::deleteFile(firstFileName) && Common::deleteFile(secondFileName);

    return !(filesExistWithContent && filesDeleted);
}