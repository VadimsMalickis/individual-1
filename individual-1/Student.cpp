#include "Student.h"
#include <string>

Student::Student(
	std::string personalCode,
	std::string firstName,
	std::string lastName,
	std::string group,
	std::string email,
	std::string studentCode
) : personalCode(personalCode),
	firstName(firstName),
	lastName(lastName),
	group(group),
	email(email),
	studentCode(studentCode)
{}

std::string Student::studentToString()
{
	return this->personalCode + "," +
		this->firstName + "," +
		this->lastName + "," +
		this->group + "," +
		this->email + "," +
		this->studentCode;
}
