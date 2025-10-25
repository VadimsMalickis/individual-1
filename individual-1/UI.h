#pragma once
#include "Student.h"
class UI
{
private:
	std::string eto;
	public:
		void start();
		void displayHelp();
		Student askStudentDetails();
};

