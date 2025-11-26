#pragma once
#include <iostream>
#include "UI.h"
#include "StudentManager.h"
#include "Student.h"
using namespace std;

class UI
{
	private:
		const size_t COLUMN_WIDTH = 15;
		StudentManager sm;
		void displayHelp();
		void askStudentDetails();
		void editStudentDetails();
		void displayStudentTable(vector<Student>& students);
	public:
		UI();
		void start();
};

