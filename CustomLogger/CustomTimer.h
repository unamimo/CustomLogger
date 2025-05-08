#pragma once

#include <chrono>		// getting current time
#include "CustomLogger.h"

template<typename func, typename... Args>

void getFunctionTime(func f, Args&&... args)
{
    auto start = std::chrono::high_resolution_clock::now();
    f(std::forward<Args>(args)...);
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "took " << duration_cast<std::chrono::seconds>(end - start).count() << " seconds" << std::endl;
}