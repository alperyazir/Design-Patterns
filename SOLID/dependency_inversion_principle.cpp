/*
 High level modules should not depend upon low level modules. Both should depend upon abstractions.
*/
#include <bits/stdc++.h>

using namespace std;

/*
struct FileLogger
{
    void log();
};

struct DBLogger
{
    void log();
};
// This class is  depend on Low level classes. violate the Dependency inversion Principle.
struct LogManager
{
    FileLogger fl;
    DBLogger dl;
    LogManager(FileLogger fl, DBLogger dl) : fl(fl), dl(dl) {}
    void log()
    {
        fl.log();
        dl.log();
    }
};
*/
struct ILogger
{
    virtual void log() = 0;
};
struct FileLogger : ILogger
{
    void log();
};

struct DBLogger : ILogger
{
    void log();
};

struct LogManager
{
    ILogger *logger;
    LogManager(ILogger *logger) : logger(logger) {}
    void log()
    {
        logger->log();
    }
};

int main()
{
    FileLogger fl;
    DBLogger dl;
    LogManager lm(&fl);
    lm.log();

    return 0;
}