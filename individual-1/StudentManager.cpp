#include "StudentManager.h"
#include "Student.h"
#include <string>
#include "FileManager.h"

Student StudentManager::processNewStudent(std::string personalCode, std::string firstName, std::string lastName, std::string group, std::string email, std::string studentCode)
{   
	return Student(personalCode, firstName, lastName, group, email, studentCode);
}

void StudentManager::addStudent(Student student)
{
	FileManager fm = FileManager();
	fm.writeStudent(student.studentToString());
}
