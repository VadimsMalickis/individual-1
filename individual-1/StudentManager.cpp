#include "StudentManager.h"
#include "Student.h"
#include <string>
#include "FileManager.h"

void StudentManager::processNewStudent(
	std::string personalCode,
	std::string firstName,
	std::string lastName,
	std::string group,
	std::string email,
	std::string studentCode)
{   
	Student st = Student(personalCode, firstName, lastName, group, email, studentCode);
	this->saveStudent(st);
}

bool StudentManager::saveStudent(Student student)
{
	FileManager fm = FileManager();
	if (fm.writeStudent(student.studentToString())) {
		return true;
	}
	else {
		return false;
	}
}
