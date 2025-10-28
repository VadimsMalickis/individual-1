#include "StudentManager.h"
#include "Student.h"
#include <string>
#include "FileManager.h"
#include <iostream>
#include <vector>

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

void StudentManager::getAllStudents()
{
	FileManager fm = FileManager();
	std::vector<std::string> students = fm.readAllStudents();
	for (size_t i = 0;  i < students.size(); i++) {
		std::cout << students[i] << std::endl;
	}
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
