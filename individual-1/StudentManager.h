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
	void loadAllStudents();
	vector<Student>& getAllStudents();
	Student* searchBy(SearchOption opt, string searchKeyword, vector<Student>& studentList);

private:
	vector<Student> students;

	const char* STUDENT_FILE = "students.txt";

	size_t lineCount(const char* fileName);

	bool saveStudent(Student& student);

	vector<string> split(const std::string& s, char delimiter);

};