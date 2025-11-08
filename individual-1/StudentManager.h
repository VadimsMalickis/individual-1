#pragma once
#include "Student.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class StudentManager
{
public:
	void processNewStudent(
		string personalCode,
		string firstName,
		string lastName,
		string group,
		string email,
		string studentCode
	);
	vector<Student> readAllStudents();

private:
	const char* stFileName = "students.txt";
	size_t lineCount(const char* fileName);
	bool saveStudent(Student& student);
	vector<string> split(const std::string& s, char delimiter);

};