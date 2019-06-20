#include "Controller.h"

Controller::Controller(int argc, char ** argv)
{
    arguments.assign(argv, argv + argc);
}

void Controller::call(std::string flag, std::function<void(std::string flagData)> f)
{
    callbackList[flag] = f;
    if (std::find(arguments.begin(), arguments.end(), flag) != arguments.end()) {
        callbackList[flag](flagValue(flag));
    }
}

std::string Controller::flagValue(std::string flag)
{
    for(auto it = arguments.begin(); it != arguments.end(); ++it)
    {
        if(flag.compare(*it) == 0) {
            if(std::next(it) != arguments.end()) {
                return *std::next(it);
            }
        }
    }
    return "";
}
