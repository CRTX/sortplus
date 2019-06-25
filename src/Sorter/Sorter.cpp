#include "Sorter.h"

Sorter::Sorter(std::string newDirectory)
{
    rootDirectory = newDirectory;
    for(auto & filename : std::filesystem::recursive_directory_iterator(rootDirectory)) {
    std::string extension(getExtension(filename.path()));
    extensionList[extension][filename.path()] = getFilename(filename.path());
    }
    std::map<std::string, std::map<std::string, std::string>>::iterator empty;
    empty = extensionList.find("");
    if(empty != extensionList.end()) {
        extensionList.erase(empty);
    }
    renameDuplicates();
}

void Sorter::renameDuplicates()
{
    for(auto itm = extensionList.begin(); itm != extensionList.end(); ++itm)
    {
        for(auto filename = itm->second.begin(); filename != itm->second.end(); ++filename)
        {
            unsigned int duplicateCounter = 0;
            for(auto isDuplicate = itm->second.begin();
                isDuplicate != itm->second.end();
                ++isDuplicate
            ) {
                if(filename->second == isDuplicate->second) {
                    if(duplicateCounter >= 1) {
                        std::string suffix(" (");
                        suffix.append(std::to_string(duplicateCounter+1));
                        suffix.append(")");
                        isDuplicate->second.append(suffix);
                    }
                    duplicateCounter++;
                }
            }
        }
    }
}

void Sorter::organizeFiles()
{
    for(auto extension = extensionList.begin(); extension != extensionList.end(); ++extension)
    {
        std::filesystem::path extensionDirectory = rootDirectory + "/" + extension->first;
        std::filesystem::create_directory(extensionDirectory);
        for(auto filename = extension->second.begin(); filename != extension->second.end(); ++filename)
        {
            std::filesystem::rename(filename->first, extensionDirectory/filename->second);
        }
    }
}

void Sorter::testRun()
{
    for(auto extension = extensionList.begin(); extension != extensionList.end(); ++extension)
    {
        std::cout << extension->first << "/" << std::endl;
        for(auto filename = extension->second.begin(); filename != extension->second.end(); ++filename)
        {
            std::cout << "    "  << filename->second << std::endl;
        }
    }
}

std::string Sorter::getExtension(const std::string & filename)
{
    if(filename.find_last_of(".") != std::string::npos) {
        return filename.substr(filename.find_last_of(".")+1);
    }
    return "";
}

std::string Sorter::getFilename(const std::string & filename)
{
    return filename.substr(filename.find_last_of("/\\") + 1);
}
