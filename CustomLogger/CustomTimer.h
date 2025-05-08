#pragma once

#include <chrono>		// getting current time

class Timer
{
public:
    // Starts a timer
    // must call stopTimer after using start
    void startTimer()
    {
        start = std::chrono::high_resolution_clock::now();
    }

    // stops the timer
    void stopTimer()
    {
        end = std::chrono::high_resolution_clock::now();
    }

    // outputs time taken in microseconds
    void outputTimeTaken()
    {
        std::cout << "took " << duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds" << "\n\n";
    }

private:
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;
};

//template<typename func, typename... Args>
//void getFunctionTime(func f, Args&&... args)
//{
//    auto start = std::chrono::high_resolution_clock::now();
//    f(std::forward<Args>(args)...);
//    auto end = std::chrono::high_resolution_clock::now();
//
//    std::cout << "took " << duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds" << std::endl;
//}