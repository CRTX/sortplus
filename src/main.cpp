#include <string>
#include <iostream>
#include "Controller/Controller.cpp"
#include "Sorter/Sorter.cpp"

int main(int argc, char ** argv)
{
    Controller c = Controller(argc, argv);
    c.call("-h", [](std::string flagData) {
        std::cout <<
        "File sort version 0.1\n"
        "Created by github.com/CRTX\n"
        "Usage: sortplus [-h help menu] [-t dry test run] [-o organize files] [directory]"
        << std::endl;
    });
    c.call("-t", [](std::string directory) {
        Sorter s = Sorter(directory);
        s.testRun();
    });
    c.call("-o", [](std::string directory) {
        Sorter s = Sorter(directory);
        s.organizeFiles();
    });
    return 0;
}
