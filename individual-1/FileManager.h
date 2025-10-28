#include <string>
#include <vector>

#pragma once
class FileManager
{
	private:
		const char* stFileName = "students.txt";
		size_t lineCount(const char* fileName);
		
	public:
		bool writeStudent(std::string studentAsString);
		std::vector<std::string> readAllStudents();
};

