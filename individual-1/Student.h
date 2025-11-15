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
		string getPersonalCode();
		void setPersonalCode(string personalCode);
		string getFirstName();
		void setFirstName(string firstName);
		string getLastName();
		void setLastName(string lastName);
		string getGroup();
		void setGroup(string group);
		string getEmail();
		void setEmail(string email);
		string getStudentCode();
		void setStudentCode(string studentCode);

		Student() {}
		Student(string personalCode, string firstName, string lastName, string group, string email, string studentCode);
		string studentToString();
};

