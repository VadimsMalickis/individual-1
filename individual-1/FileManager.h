#include <string>

#pragma once
class FileManager
{
	private:
		const std::string stFileName = "students.txt";
	public:
		void  writeStudent(std::string studentAsString);
};

