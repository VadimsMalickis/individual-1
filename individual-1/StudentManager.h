#pragma once
#include "Student.h"
#include <string>
class StudentManager
{
	public:
		Student createStudent(std::string personalCode, std::string firstName, std::string lastName, std::string group, std::string email, std::string studentCode);
		void addStudent(Student student);
};

