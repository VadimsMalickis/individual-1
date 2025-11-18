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
	ofstream file;
	file.open(StudentManager::STUDENT_FILE, ios::app);
	if (file.is_open())
	{
		file << student.studentToString() << endl;
		file.close();
		return true;
	}
	return false;
}

size_t StudentManager::lineCount(const char* fileName)
{
	size_t count = 0;
	ifstream file;
	file.open(fileName);
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			count++;
		}
		file.close();
	}
	return count;
}

void StudentManager::loadAllStudents()
{
	const size_t lines = lineCount(StudentManager::STUDENT_FILE);

	vector<Student> students;

	ifstream file;
	file.open(StudentManager::STUDENT_FILE);

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
	this->students = students;
}

vector<Student>& StudentManager::getAllStudents()
{
	if (this->students.empty())
	{
		this->loadAllStudents();
	}
	return this->students;
}

Student* StudentManager::searchBy(
	SearchOption opt,
	string searchKeyword,
	vector<Student>& studentList
)
{
	Student* foundStudent = nullptr;
	switch (opt) {
		case SearchOption::PersonalCode:
			for (Student& st : studentList) {
				if (st.getPersonalCode() == searchKeyword) {
					foundStudent = &st;
					return foundStudent;
				}
			}
		case SearchOption::StudentCode:
			for (Student& st : studentList) {
				if (st.getStudentCode() == searchKeyword) {
					foundStudent = &st;
					return foundStudent;
				}
			}
		case SearchOption::Email:
			for (Student& st : studentList) {
				if (st.getEmail() == searchKeyword) {
					foundStudent = &st;
					return foundStudent;
				}
			}
	}
	return nullptr;
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
