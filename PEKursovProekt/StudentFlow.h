#ifndef StudentFlow_H
#define StudentFlow_H

#include <vector>
#include <iostream>
#include "Student.h"

using std::vector;

class StudentFlow
{

private:
	/// <summary>
	/// Списък със студенти в потока
	/// </summary>
	vector<Student> students;

public:
	/// <summary>
	/// Конструктор по подразбиране
	/// </summary>
	StudentFlow();

	/// <summary>
	/// Конструктор с параметри
	/// </summary>
	/// <param name="students"></param>
	StudentFlow(vector<Student> students);

	/// <summary>
	/// Метод за промяна на студентите
	/// </summary>
	/// <param name="students"></param>
	void setStudents(vector<Student> students);

	/// <summary>
	/// Метод за взимане на студентите
	/// </summary>
	/// <returns></returns>
	vector<Student> getStudents();

	/// <summary>
	/// Метод за взимане на средния успех на потока
	/// </summary>
	/// <returns></returns>
	double getAvrGrades();

	/// <summary>
	/// Предефиниран оператор << за извеждане на данните на класа StudentFlow
	/// </summary>
	/// <param name="out"></param>
	/// <param name="sf"></param>
	/// <returns></returns>
	friend std::ostream& operator << (std::ostream& out, const StudentFlow& sf);
};

#endif