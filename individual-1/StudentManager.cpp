#include "StudentManager.h"
#include "Student.h"
#include <string>

Student StudentManager::createStudent(std::string personalCode, std::string firstName, std::string lastName, std::string group, std::string email, std::string studentCode)
{   
	return Student(personalCode, firstName, lastName, group, email, studentCode);
}
