#include <iostream>
#include "UI.h"
#include "StudentManager.h"
#include "Student.h"

UI::UI()
{
	this->sm = StudentManager();
}

void UI::start()
{
	cout << "Welcome to Student managment system!" << std::endl << std::endl;
	cout << "Type following commands to proceed:" << std::endl << std::endl;
	this->displayHelp();

	while (true)
	{
		int choice;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1: {
			this->displayHelp();
			break;
		}
		case 2: {
			this->askStudentDetails();
			break;
		}
		case 3: {
			vector<Student>& students = this->sm.getAllStudents();
			if (students.size() == 0) {
				cout << "No students found!" << endl;
			} else {
				for (Student& student : students) {
					cout << student.studentToString() << endl;
				}
			}
			break;
		}
			case 4:
				cout << "Exiting..." << endl;
				return;

		default:
			break;
		}
	}
}

void UI::displayHelp()
{
	cout << "1. For Help" << endl;
	cout << "2. Register new Student" << endl;
	cout << "3. View all Students" << endl;
	cout << "4. Exit" << endl;
}



void UI::askStudentDetails()
{
	string personalCode;
	string firstName;
	string lastName;
	string group;
	string email;
	string studentCode;
	cout << "Enter Personal Code: ";
	cin >> personalCode;
	cout << "Enter First Name: ";
	cin >> firstName;
	cout << "Enter Last Name: ";
	cin >> lastName;
	cout << "Enter Group: ";
	cin >> group;
	cout << "Enter Email: ";
	cin >> email;
	cout << "Enter Student Code: ";
	cin >> studentCode;
	
	sm.processNewStudent(personalCode, firstName, lastName, group, email, studentCode);
}


