#include "Loggers.hpp"

int main()
{
    std::ofstream myfile;
    myfile.open ("example.txt", std::ios::out);

    std::ofstream myfile2;
    myfile2.open ("example2.txt", std::ios::out);
    Logger *loggers[3] =
        {
            new ConsoleLogger(),
            new SimpleFileLogger(myfile), // file cerr
            new TimedFileLogger(myfile2) // file cerr
        };

    for (int i = 0; i < 10; i++)
    {
        (loggers[0])->log("hello, std::cout");
        (loggers[1])->log("hello, file");
        (loggers[2])->log("hello, file with time");
    }
    myfile.close();
    myfile2.close();
}