#include "Student.h"
#include <string>

Student::Student(
	string personalCode,
	string firstName,
	string lastName,
	string group,
	string email,
	string studentCode
) {
	this->personalCode = personalCode;
	this->firstName = firstName;
	this->lastName = lastName;
	this->group = group;
	this->email = email;
	this->studentCode = studentCode;
}

void Student::setPersonalCode(string personalCode)
{
	this->personalCode = personalCode;
}

string Student::studentToString()
{
	return this->personalCode + "," +
			this->firstName + "," +
			this->lastName + "," +
			this->group + "," +
			this->email + "," +
			this->studentCode;
}
