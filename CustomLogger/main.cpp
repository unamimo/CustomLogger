#include <iostream>
#include "CustomLogger.h"
#include "CustomTimer.h"

int main()
{
    // Choose file to log to
    CustomLogger mCustomLogger("LogFile.txt");


    // Logging with different variable types
    auto start1 = std::chrono::high_resolution_clock::now();

    mCustomLogger.LogToConsole("Hello world!", 1, 2.4, 33333, true, "a");

    auto end1 = std::chrono::high_resolution_clock::now();
    std::cout << "took " << duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;


    // Logging to file
    auto start2 = std::chrono::high_resolution_clock::now();
    
    mCustomLogger.LogToFile("Hello", "World", "!", 1, 2, 4.4, 56745674);

    auto end2 = std::chrono::high_resolution_clock::now();
    std::cout << "took " << duration_cast<std::chrono::microseconds>(end2 - start2).count() << " microseconds" << std::endl;


    // Log current time
    auto start3 = std::chrono::high_resolution_clock::now();
    
    mCustomLogger.LogToConsole(mCustomLogger.getCurrentTime());

    auto end3 = std::chrono::high_resolution_clock::now();
    std::cout << "took " << duration_cast<std::chrono::microseconds>(end3 - start3).count() << " microseconds" << std::endl;


    // Log current time and message
    auto start4 = std::chrono::high_resolution_clock::now();

    mCustomLogger.LogToConsole(mCustomLogger.getCurrentTime(), "Log with timestamp");

    auto end4 = std::chrono::high_resolution_clock::now();
    std::cout << "took " << duration_cast<std::chrono::microseconds>(end4 - start4).count() << " microseconds" << std::endl;    auto start = std::chrono::high_resolution_clock::now();


    // Logging with iteration
    auto start5 = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < 11; i++)
    {
        mCustomLogger.LogToConsole("Logging in a loop:", i);
    }

    auto end5 = std::chrono::high_resolution_clock::now();
    std::cout << "took " << duration_cast<std::chrono::microseconds>(end5 - start5).count() << " microseconds" << std::endl;    


    // Logging based on condition
    auto start6 = std::chrono::high_resolution_clock::now();
 
    mCustomLogger.LogToConsole(mCustomLogger.testVal == 8 ? "True" : "False");

    auto end6 = std::chrono::high_resolution_clock::now();
    std::cout << "took " << duration_cast<std::chrono::microseconds>(end6 - start6).count() << " microseconds" << std::endl;
}
