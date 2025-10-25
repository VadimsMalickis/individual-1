#pragma once
#include "Student.h"
#include <string>

class StudentManager
{
	public:
		void processNewStudent(std::string personalCode, std::string firstName, std::string lastName, std::string group, std::string email, std::string studentCode);
	private:
		bool saveStudent(Student student);

};

