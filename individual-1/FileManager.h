#include <string>

#pragma once
class FileManager
{
	private:
		const std::string stFileName = "students.txt";
	public:
		bool writeStudent(std::string studentAsString);
		void readAllStudents();
};

