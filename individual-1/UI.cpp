#include <iostream>
#include "UI.h"
#include "StudentManager.h"
#include "Student.h"

void UI::start()
{
	std::cout << "Welcome to Student managment system!" << std::endl << std::endl;
	std::cout << "Type following commands to proceed:" << std::endl << std::endl;
	this->displayHelp();

	while (true)
	{
		int choice;
		StudentManager sm = StudentManager();
		Student student;
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		switch (choice)
		{
			case 1:	
				this->displayHelp();
				break;
			case 2:
				student = this->askStudentDetails();
				sm.addStudent(student);
				break;
			case 3:
				std::cout << "Viewing all students is not implemented yet." << std::endl;
				break;
			case 4:
				std::cout << "Exiting..." << std::endl;
				return;

		default:
			break;
		}
	}
}

void UI::displayHelp()
{
	std::cout << "1. For Help" << std::endl;
	std::cout << "2. Register new Student" << std::endl;
	std::cout << "3. View all Students" << std::endl;
	std::cout << "4. Exit" << std::endl;
	
}

Student UI::askStudentDetails()
{
	std::string personalCode;
	std::string firstName;
	std::string lastName;
	std::string group;
	std::string email;
	std::string studentCode;
	std::cout << "Enter Personal Code: ";
	std::cin >> personalCode;
	std::cout << "Enter First Name: ";
	std::cin >> firstName;
	std::cout << "Enter Last Name: ";
	std::cin >> lastName;
	std::cout << "Enter Group: ";
	std::cin >> group;
	std::cout << "Enter Email: ";
	std::cin >> email;
	std::cout << "Enter Student Code: ";
	std::cin >> studentCode;
	this->eto = "done";
	
	StudentManager sm = StudentManager();
	return sm.createStudent(personalCode, firstName, lastName, group, email, studentCode);
}
