#include <iostream>
#include <iomanip>
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
	cout << "Type following commands to proceed:" << std::endl;
	this->displayHelp();

	while (true)
	{
		int choice;
		cout << endl << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1: {
			this->displayHelp();
			break;
		}
		case 2: {
			this->askStudentDetails();
			cout << "Student registered successfully!" << endl;
			break;
		}
		case 3: {
			vector<Student>& students = this->sm.getAllStudents();
			displayStudentTable(students);
			cout << "EDIT {E} or DELETE {D} a student by entering their Personal Code, or press ENTER to return to main menu." << endl;
			char action;
			cout << ": ";
			cin >> action;
			if (action == 'E' || action == 'e') {
				this->editStudentDetails();
			}
			else if (action == 'D' || action == 'd') {
				// delete action
			}
 			break;
		}
		case 4: {
			int option;
			string keyword;
			vector<Student> foundStudents;
			cout << "1. Seach by Personal Code" << endl;
			cout << "2. Seach by Student Code" << endl;
			cout << "3. Seach by Email" << endl;
			cout << ": ";
			cin >> option;
			cout << endl << "Enter search keyword: ";
			cin >> keyword;
			cout << endl;
			switch (option) {
				case 1: {
					foundStudents = this->sm.searchBy(SearchOption::PersonalCode, keyword);
					break;
				}
				case 2: {
					foundStudents = this->sm.searchBy(SearchOption::StudentCode, keyword);
					break;
				}
				case 3: {
					foundStudents = this->sm.searchBy(SearchOption::Email, keyword);
					break;
				}
			}
			if (foundStudents.size() == 0) {
				cout << "No students found!" << endl;
			}
			else {
				displayStudentTable(foundStudents);
			}
			break;
		}
		case 5: {
			cout << "Exiting..." << endl;
			return;
		}
		default:
			break;
		}
	}
}

void UI::displayHelp()
{
	cout << endl << "1. For Help" << endl;
	cout << "2. Register new Student" << endl;
	cout << "3. View all Students" << endl;
	cout << "4. Student Search" << endl;
	cout << "5. Exit" << endl;
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

void UI::editStudentDetails()
{
	string personalCode;
	cin >> personalCode;

	for (Student& student : sm.getAllStudents()) {
		if (student.getPersonalCode() == personalCode) {
			string firstName;
			string lastName;
			string group;
			string email;
			string studentCode;
			cout << "Enter First Name (" << student.getFirstName() << "): ";
			cin >> firstName;
			cout << "Enter Last Name (" << student.getLastName() << "): ";
			cin >> lastName;
			cout << "Enter Group (" << student.getGroup() << "): ";
			cin >> group;
			cout << "Enter Email (" << student.getEmail() << "): ";
			cin >> email;
			cout << "Enter Student Code (" << student.getStudentCode() << "): ";
			cin >> studentCode;
			student.setFirstName(firstName);
			student.setLastName(lastName);
			student.setGroup(group);
			student.setEmail(email);
			student.setStudentCode(studentCode);
			cout << "Student details updated successfully!" << endl;
			break;
		}
	}
}

void UI::displayStudentTable(vector<Student>& students)
{
	if (students.size() == 0) {
		cout << "No students found!" << endl;
	}
	else {
		const size_t UNDERLINE_WIDTH = UI::COLUMN_WIDTH * 6 + 12;
		cout << string(UNDERLINE_WIDTH, '=') << endl;
		cout << left
			<< setw(UI::COLUMN_WIDTH) << "| Personal Code "
			<< setw(UI::COLUMN_WIDTH) << "| First Name "
			<< setw(UI::COLUMN_WIDTH) << "| Last Name "
			<< setw(UI::COLUMN_WIDTH) << "| Group "
			<< setw(UI::COLUMN_WIDTH + 10) << "| Email "
			<< setw(UI::COLUMN_WIDTH) << "| Student Code |" << endl;

		cout << string(UNDERLINE_WIDTH, '=') << endl;

		// Print each student record in a new row
		for (Student& student : students) {
			cout << left
				<< setw(UI::COLUMN_WIDTH) << "| " + student.getPersonalCode()
				<< setw(UI::COLUMN_WIDTH) << " | " + student.getFirstName()
				<< setw(UI::COLUMN_WIDTH) << " | " + student.getLastName()
				<< setw(UI::COLUMN_WIDTH) << " | " + student.getGroup()
				<< setw(UI::COLUMN_WIDTH + 10) << " | " + student.getEmail()
				<< setw(UI::COLUMN_WIDTH) << " | " + student.getStudentCode() << " |" << endl;
			cout << string(UNDERLINE_WIDTH, '-') << endl;
		}
	}
}


