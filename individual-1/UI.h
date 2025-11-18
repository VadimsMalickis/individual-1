#pragma once
#include "StudentManager.h"

using namespace std;

class UI
{
	private:
		StudentManager sm;
		void displayHelp();
		void askStudentDetails();
	public:
		UI();
		void start();
};

