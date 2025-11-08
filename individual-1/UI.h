#pragma once
#include "StudentManager.h"

using namespace std;

class UI
{
	private:
		StudentManager sm;
		vector<Student> students;
		void displayHelp();
		void askStudentDetails();
	public:
		UI();
		void start();
};

