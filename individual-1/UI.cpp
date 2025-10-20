#include <iostream>
#include "UI.h"
#include "StudentManager.h"

void UI::mainLoop()
{
	while (true)
	{
		this->displayMenu();
		int choice;
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		if (choice == 1) {
			this->displayMenu();
		}
		else if (choice == 2)
		{
			
		}
		else if (choice == 4)
		{
			std::cout << "Exiting..." << std::endl;
			break;
		}
		else
		{
			std::cout << "You selected option " << choice << std::endl;
		}
	}
}

void UI::displayMenu()
{
	std::cout << "Welcome to Student managment system!" << std::endl << std::endl;
	std::cout << "Type following commands to proceed:" << std::endl;
	std::cout << "1. For Help" << std::endl;
	std::cout << "2. Register new Student" << std::endl;
	std::cout << "3. View all Students" << std::endl;
	std::cout << "4. Exit" << std::endl;
	
}

void UI::askStudentDetails()
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
	
	StudentManager sm = StudentManager();
	sm.createStudent(personalCode, firstName, lastName, group, email, studentCode);
}
