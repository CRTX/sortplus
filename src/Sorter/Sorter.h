#include <filesystem>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Sorter
{
    public:
        Sorter(std::string newDirectory);
        void testRun();
        void organizeFiles();
        void renameDuplicates();

    private:
        std::map<std::string, std::map<std::string, std::string>> extensionList;
        std::string rootDirectory;
        std::string getExtension(const std::string & filename);
        std::string getFilename(const std::string & filename);
};
