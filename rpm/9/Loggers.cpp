#include "Loggers.hpp"
#include <chrono>
#include <ctime> 

void ConsoleLogger::log(const std::string &msg)
{
    std::cout << msg << std::endl;
    return;
}

void SimpleFileLogger::log(const std::string &msg)
{
    os << msg << std::endl;
    return;
}

void TimedFileLogger::log(const std::string &msg)
{
    auto start = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(start);
    os << "time: " << std::ctime(&end_time) << "message: "
        << msg << std::endl;
    return;
}