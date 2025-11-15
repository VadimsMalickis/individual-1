#pragma once
#include "Student.h"
#include "SearchOption.h"
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
	Student* searchBy(SearchOption opt, string searchKeyword, vector<Student>& studentList);

private:
	const char* stFileName = "students.txt";
	size_t lineCount(const char* fileName);
	bool saveStudent(Student& student);
	vector<string> split(const std::string& s, char delimiter);

};