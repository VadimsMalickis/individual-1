#pragma once
#include "StudentManager.h"
class UI
{
	private:
		StudentManager sm;
		void displayHelp();
		void askStudentDetails();
	public:
		UI() {}
		void start();
};

