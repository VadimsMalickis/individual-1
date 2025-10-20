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
		Student(std::string personalCode, std::string firstName, std::string lastName, std::string group, std::string email, std::string studentCode);
		void study();
};

