#pragma once
#include <string>

using namespace std;

class Student
{
	private:
		string personalCode;
		string firstName;
		string lastName;
		string group;
		string email;
		string studentCode;

	public:
		void setPersonalCode(string personalCode);
		Student() {}
		Student(string personalCode, string firstName, string lastName, string group, string email, string studentCode);
		string studentToString();
};

