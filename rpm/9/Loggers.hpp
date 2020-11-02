#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Logger 
{
protected:
    Logger() = default;
public:
    virtual ~Logger() = default;
    virtual void log(const std::string &msg) = 0; 
};

class ConsoleLogger : public Logger
{
public:
    ConsoleLogger() = default;
    void log(const std::string &msg) override; 
};

class SimpleFileLogger : public Logger
{
private:
    std::ofstream &os; 
public:
    SimpleFileLogger(std::ofstream &f)
        : os(f) { }

    void log(const std::string &msg) override; 
};

class TimedFileLogger : public Logger
{
private:
    std::ofstream &os; 
public:
    TimedFileLogger(std::ofstream &f)
        :os(f) { }

    void log(const std::string &msg) override; 
};