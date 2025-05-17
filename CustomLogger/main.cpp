#include <iostream>
#include "CustomLogger.h"
#include "CustomTimer.h"

int main()
{
    // Choose file to log to
    CustomLogger mCustomLogger("LogFile.txt");
    Timer mTimer;


    // Logging with different variable types
    mTimer.startTimer();
    mCustomLogger.LogToConsole("Hello world!", 1, 2.4, 33333, true, "a");
    mTimer.stopTimer();
    mTimer.outputTimeTaken();


    // Logging to file
    mTimer.startTimer();
    mCustomLogger.LogToFile("Hello", "World", "!", 1, 2, 4.4, 56745674);
    mTimer.stopTimer();
    mTimer.outputTimeTaken();


    // Log current time
    mTimer.startTimer();
    mCustomLogger.LogToConsole(mTimer.getCurrentTime());
    mTimer.stopTimer();
    mTimer.outputTimeTaken();


    // Log current time and message
    mTimer.startTimer();
    mCustomLogger.LogToConsole(mTimer.getCurrentTime(), "Log with timestamp");
    mTimer.stopTimer();
    mTimer.outputTimeTaken();


    // Logging with iteration
    mTimer.startTimer();
    for (size_t i = 0; i < 11; i++)
    {
        mCustomLogger.LogToConsole("Logging in a loop:", i);
    }
    mTimer.stopTimer();
    mTimer.outputTimeTaken();


    // Logging based on condition
    // https://cplusplus.com/reference/cstdio/vprintf/
    mTimer.startTimer();
    mCustomLogger.LogToConsole(mCustomLogger.testVal == 8 ? "True" : "False");
    mTimer.stopTimer();
    mTimer.outputTimeTaken();

    // Unsafe logger test
    mCustomLogger.unsafeLogger("Log: %i %s \n", 1, "hello");
    mCustomLogger.unsafeLogger("Log: %i %s %s \n", 2, "hello", "world");
    mCustomLogger.unsafeLogger("Log: %d %s \n", 2, "hello", "world", "how", "are", "you?");
    mCustomLogger.unsafeLogger("Log: %f %s \n");
    mCustomLogger.unsafeLogger("Log: %f%f %s \n");
    mCustomLogger.unsafeLogger("Log: %f%f%f %s \n");
    mCustomLogger.unsafeLogger("Log: %f%f%f%f %s \n");
    mCustomLogger.unsafeLogger("Log: %f%f%f%f%f %s \n");
    const char* pass = "psswrd";
    mCustomLogger.unsafeLogger("Log: %f %s \n");
}
