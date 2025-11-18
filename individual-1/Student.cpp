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

string Student::getPersonalCode()
{
	return this->personalCode;
}

string Student::getStudentCode()
{
	return this->studentCode;
}

string Student::getEmail()
{
	return this->email;
}

string Student::getFirstName()
{
	return this->firstName;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

string Student::getLastName()
{
	return this->lastName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

string Student::getGroup()
{
	return this->group;
}

void Student::setGroup(string group)
{
	this->group = group;
}

void Student::setEmail(string email)
{
	this->email = email;
}

void Student::setStudentCode(string studentCode)
{
	this->studentCode = studentCode;
}
