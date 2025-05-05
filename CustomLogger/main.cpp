#include <iostream>
#include "CustomLogger.h"

int main()
{
    CustomLogger mCustomLogger("LogFile.txt");

    mCustomLogger.LogToConsole("Hello world!", 1, 2.4, 33333);
    mCustomLogger.LogToFile("Hello", "World", "!", 1, 2, 4.4, 56745674);
    mCustomLogger.LogToConsole(mCustomLogger.getCurrentTime());
}
