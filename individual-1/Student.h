#pragma once
#include <string>

class Student
{
	private:
		std::string personalCode;
		std::string firstName;
		std::string lastName;
		std::string group;
		std::string email;
		std::string studentCode;

	public:
		Student() {}
		Student(std::string personalCode, std::string firstName, std::string lastName, std::string group, std::string email, std::string studentCode);
		std::string studentToString();
};

