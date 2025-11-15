#include "StudentManager.h"
#include "Student.h"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

void StudentManager::processNewStudent(
	string personalCode,
	string firstName,
	string lastName,
	string group,
	string email,
	string studentCode)
{   
	Student st = Student(personalCode, firstName, lastName, group, email, studentCode);
	this->saveStudent(st);
}


bool StudentManager::saveStudent(Student& student)
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

vector<Student> StudentManager::readAllStudents()
{
	const size_t lines = lineCount(StudentManager::stFileName);

	vector<Student> students;

	ifstream file;
	file.open(StudentManager::stFileName);

	if (file.is_open())
	{
		string line;
		vector<string> tokens;
		Student student;
		for (size_t i = 0; i < lines && getline(file, line); i++) {
			tokens = this->split(line, ',');
			student = Student(
				tokens[0],
				tokens[1],
				tokens[2],
				tokens[3],
				tokens[4],
				tokens[5]
			);
			students.push_back(student);
		}
		file.close();
	}
	return students;
}

vector<Student> StudentManager::filterStudents(FilterOption opt, vector<Student>& studentList)
{
	vector<Student> filteredList;
	switch (opt) {
		case FilterOption::PersonalCode:
			for (Student& st : studentList) {
				
			}
		case FilterOption::StudentCode:
			for (Student& st : studentList) {

			}
		case FilterOption::Email:
			for (Student& st : studentList) {

			}
	
	default:
		break;
	}
	return filteredList;
}

vector<string> StudentManager::split(const std::string& s, char delimiter) {
	vector<string> tokens;
	string token;
	istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}
