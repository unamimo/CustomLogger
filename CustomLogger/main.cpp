#include <iostream>
#include "CustomLogger.h"

int main()
{
    CustomLogger mCustomLogger;

    mCustomLogger.LogToConsole("Hello world!", 1, 2.4, 33333);
}
