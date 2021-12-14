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
	/// ������ ��� �������� � ������
	/// </summary>
	vector<Student> students;

public:
	/// <summary>
	/// ����������� �� ������������
	/// </summary>
	StudentFlow();

	/// <summary>
	/// ����������� � ���������
	/// </summary>
	/// <param name="students"></param>
	StudentFlow(vector<Student> students);

	/// <summary>
	/// ����� �� ������� �� ����������
	/// </summary>
	/// <param name="students"></param>
	void setStudents(vector<Student> students);

	/// <summary>
	/// ����� �� ������� �� ����������
	/// </summary>
	/// <returns></returns>
	vector<Student> getStudents();

	/// <summary>
	/// ����� �� ������� �� ������� ����� �� ������
	/// </summary>
	/// <returns></returns>
	double getAvrGrades();

	/// <summary>
	/// ������������ �������� << �� ��������� �� ������� �� ����� StudentFlow
	/// </summary>
	/// <param name="out"></param>
	/// <param name="sf"></param>
	/// <returns></returns>
	friend std::ostream& operator << (std::ostream& out, const StudentFlow& sf);
};

#endif