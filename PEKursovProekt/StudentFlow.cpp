#include "StudentFlow.h"

StudentFlow::StudentFlow()
{

}

StudentFlow::StudentFlow(vector<Student> students)
{
	this->students = students;
}

void StudentFlow::setStudents(vector<Student> students)
{
	this->students = students;
}

vector<Student> StudentFlow::getStudents()
{
	return students;
}

double StudentFlow::getAvrGrades()
{
	double avrGrade = 0;

	for (int i = 0; i < students.size(); i++) {
		avrGrade += students[i].getAvrGrade();
	}

	avrGrade /= students.size();

	return avrGrade;
}

std::ostream& operator << (std::ostream& out, const StudentFlow& sf)
{
	time_t theTime = time(NULL);
	struct tm aTime;

	localtime_s(&aTime, &theTime);

	for (Student stud : sf.students)
	{
		if (stud.getStudentAge(Date(aTime.tm_mday, aTime.tm_mon + 1, aTime.tm_year + 1900)) >= 18
			&& stud.getStudentAge(Date(aTime.tm_mday, aTime.tm_mon + 1, aTime.tm_year + 1900)) <= 26)
		{
			out << stud;
		}
	}

	return out;
}
