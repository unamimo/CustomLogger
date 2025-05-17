#pragma once
#include <iostream>		// std::string	
#include <fstream>		// file writing
#include <chrono>		// getting current time
#include <format>		// time formatting
#include <cstdio>		// c functions
#include <cstdarg>		// for va_start

class CustomLogger
{
public:
	CustomLogger(const std::string fileName) {
		outfile.open(fileName, std::ios_base::app);
		if (!outfile.is_open())
		{
			std::cerr << "Cannot open log file" << "\n";
		}
	}

	~CustomLogger() {
		outfile.close();
	}

	// include a space between arguments, but can be removed
	template <typename ... Types>
	void LogToConsole(Types&&... types) {
		((std::cout << types << " "), ...);	// fold expression
		std::cout << "\n";
	}

	// creates a new file with fileName
	// include a space between arguments, but can be removed
	template <typename ... Types>
	void LogToFile(Types&&... types) {
		((outfile << types << " "), ...);
		std::cout << "\n";
		outfile.close();
	}

	// an example of unsafe logging using va_list
	void unsafeLogger(const char* format, ...)
	{
		va_list args;
		va_start(args, format);
		vprintf(format, args);
		va_end(args);
	}

	int testVal = 8;
private:
	std::ofstream outfile;
};