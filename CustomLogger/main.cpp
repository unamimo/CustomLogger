#include <iostream>
#include "CustomLogger.h"

int main()
{
    CustomLogger mCustomLogger("LogFile.txt");

    mCustomLogger.LogToConsole("Hello world!", 1, 2.4, 33333, true);
    mCustomLogger.LogToFile("Hello", "World", "!", 1, 2, 4.4, 56745674);
    mCustomLogger.LogToConsole(mCustomLogger.getCurrentTime());
    mCustomLogger.LogToConsole(mCustomLogger.getCurrentTime(), "Log with timestamp");

    for (size_t i = 0; i < 11; i++)
    {
        mCustomLogger.LogToConsole("Logging in a loop:", i);
    }
}
