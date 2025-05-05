//		Functional Requirements: 
// Accept any number of arguments of any type at runtime.
// Output the arguments in order(preserving the sequence they are passed in).
// Write to a log destination, such as : The console(standard output), A file(e.g.log.txt)
// Support repeated logging calls with different types and numbers of arguments.
// Demonstrate runtime behavior clearly(e.g.logging during loops or based on runtime conditions).

//		Technical Requirements:
// Use C++ variadic templates to handle an arbitrary number of arguments.
// Use parameter pack expansion to process the arguments dynamically at runtime.
// Avoid printf or similar C - style techniques in the implementation.
// Illustrate dynamic behavior, such as :
//	- Log content changing based on runtime values
//	- Runtime branching(e.g., logging only on certain conditions)
#pragma once
#include <iostream>
#include <fstream>

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

	template <typename ... Types>
	void LogToConsole(Types&&... types) {
		(std::cout << ... << types);
	}

	// creates a new file with fileName
	template <typename ... Types>
	void LogToFile(Types&&... types) {
		//std::ofstream outfile;
		//// "LogFile.txt"
		//outfile.open(fileName, std::ios_base::app);
		(outfile << ... << types);
		outfile.close();
	}

private:
	std::ofstream outfile;
};