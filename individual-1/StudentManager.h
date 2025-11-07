#pragma once
#include "Student.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class StudentManager
{
	public:
		void processNewStudent(
			std::string personalCode,
			std::string firstName,
			std::string lastName,
			std::string group,
			std::string email,
			std::string studentCode);
		bool writeStudent(std::string studentAsString);
		std::vector<std::string> readAllStudents();

	private:
		const char* stFileName = "students.txt";
		size_t lineCount(const char* fileName);
		bool saveStudent(Student student);

};

