#include "Student.h"

using namespace std;

Student::Student()
{
	name = "";
	facNumber = "";
	birthDate = Date();
	avrGrade = 0;
}

Student::Student(string name, string facNumber, Date birthDate, double avrGrade)
{
	this->name = name;
	this->facNumber = facNumber;
	this->birthDate = birthDate;

	while (avrGrade < 2 && avrGrade > 6)
	{
		cout << "Invalid average grade. Please enter another grade: ";
		cin >> avrGrade;
	}
	this->avrGrade = avrGrade;
}

void Student::setName(string name)
{
	this->name = name;
}

string Student::getName() 
{
	return name;
}

void Student::setFakNumber(string facNumber)
{
	this->facNumber = facNumber;
}

string Student::getFakNumber()
{
	return facNumber;
}

void Student::setBirthDate(Date birthDate)
{
	this->birthDate = birthDate;
}

Date Student::getBirthDate() 
{
	return birthDate;
}

void Student::setAvrGrade(double avrGrade)
{
	while (avrGrade < 2 && avrGrade > 6)
	{
		cout << "Invalid average grade. Please enter another grade: ";
		cin >> avrGrade;
	}
	this->avrGrade = avrGrade;
}

double Student::getAvrGrade() 
{
	return avrGrade;
}

int Student::getStudentAge(Date date)
{
	return date.getYear() - birthDate.getYear();
}

std::ostream& operator << (std::ostream& out, const Student& stud)
{
	out << stud.name << " " << stud.facNumber << " " << stud.birthDate << " " << stud.avrGrade << std::endl;

	return out;
}
