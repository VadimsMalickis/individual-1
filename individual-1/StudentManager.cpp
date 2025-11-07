#include "StudentManager.h"
#include "Student.h"
#include <string>
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


bool StudentManager::saveStudent(Student student)
{
	std::ofstream file;
	file.open(StudentManager::stFileName, std::ios::app);
	if (file.is_open())
	{
		file << student.studentToString() << std::endl;
		file.close();
		return true;
	}
	return false;
}
size_t StudentManager::lineCount(const char* fileName)
{
	size_t count = 0;
	std::ifstream file;
	file.open(fileName);
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			count++;
		}
		file.close();
	}
	return count;
}

std::vector<std::string> StudentManager::readAllStudents()
{
	const size_t lines = lineCount(StudentManager::stFileName);

	std::vector<std::string> students;

	std::ifstream file;
	file.open(StudentManager::stFileName);

	if (file.is_open())
	{
		std::string line;
		for (size_t i = 0; i < lines && std::getline(file, line); i++) {
			students.push_back(line);
		}
		file.close();
	}
	return students;
}
