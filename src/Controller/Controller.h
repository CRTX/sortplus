#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>

class Controller
{
    public:
        Controller(int argc, char ** argv);
        void call(std::string flag, std::function<void(std::string flagData)> f);

    private:
        std::map<std::string, std::function<void(std::string flagData)>> callbackList;
        std::string flagValue(std::string flag);
        std::vector<std::string> arguments;
};
