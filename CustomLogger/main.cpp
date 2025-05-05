#include <iostream>
#include "CustomLogger.h"

int main()
{
    // Choose file to log to
    CustomLogger mCustomLogger("LogFile.txt");

    // Logging with different variable types
    mCustomLogger.LogToConsole("Hello world!", 1, 2.4, 33333, true, "a");
    // Logging to file
    mCustomLogger.LogToFile("Hello", "World", "!", 1, 2, 4.4, 56745674);
    // Log current time
    mCustomLogger.LogToConsole(mCustomLogger.getCurrentTime());
    // Log current time and message
    mCustomLogger.LogToConsole(mCustomLogger.getCurrentTime(), "Log with timestamp");

    // Logging with iteration
    for (size_t i = 0; i < 11; i++)
    {
        mCustomLogger.LogToConsole("Logging in a loop:", i);
    }

    // Logging based on condition 
    mCustomLogger.LogToConsole(mCustomLogger.testVal == 8 ? "True" : "False");
}
