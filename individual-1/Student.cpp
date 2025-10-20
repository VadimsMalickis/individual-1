#include "Student.h"
#include <string>

Student::Student(std::string personalCode, std::string firstName, std::string lastName, std::string group, std::string email, std::string studentCode)
{
	this->personalCode = personalCode;
	this->firstName = firstName;
	this->lastName = lastName;
	this->group = group;
	this->email = email;
	this->studentCode = studentCode;
}
