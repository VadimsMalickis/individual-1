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

vector<Student> StudentManager::searchBy(SearchOption opt, string& keyword)
{
	vector<Student>& students = this->getAllStudents();
	vector<Student> foundStudents;

	if (opt == SearchOption::PersonalCode) {
		for (Student& st : students) {
			if (st.getPersonalCode().find(keyword) != string::npos) {
				foundStudents.push_back(st);
			}
		}
	}
	else if (opt == SearchOption::StudentCode) {
		for (Student& st : students) {
			if (st.getStudentCode().find(keyword) != string::npos) {
				foundStudents.push_back(st);
			}
		}
	}
	else if (opt == SearchOption::Email) {
		for (Student& st : students) {
			if (st.getEmail().find(keyword) != string::npos) {
				foundStudents.push_back(st);
			}
		}
	}
	
	return foundStudents;
}

void StudentManager::updateStudentList(vector<Student>& studentList)
{
	ofstream file;
	file.open(StudentManager::STUDENT_FILE, ios::trunc);
	if (file.is_open()) {
		for (Student& student : studentList) {
			file << student.studentToString() << endl;
		}
		file.close();
	}
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
