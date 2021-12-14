#ifndef Student_H
#define Student_H
#include <string>
#include "Date.h"

using std::string;

class Student
{

private:
	/// <summary>
	/// ��� �� ��������
	/// </summary>
	string name;

	/// <summary>
	/// ���������� ����� �� ��������
	/// </summary>
	string facNumber;

	/// <summary>
	/// �������� ���� �� ��������
	/// </summary>
	Date birthDate;

	/// <summary>
	/// ������ ����� �� ��������
	/// </summary>
	double avrGrade;

public:
	/// <summary>
	/// ����������� �� ������������ 
	/// </summary>
	Student();

	/// <summary>
	/// ����������� � ���������
	/// </summary>
	/// <param name="name"></param>
	/// <param name="facNumber"></param>
	/// <param name="birthDate"></param>
	/// <param name="avrGrade"></param>
	Student(string name, string facNumber, Date birthDate, double avrGrade);

	/// <summary>
	/// ����� �� ������� �� �����
	/// </summary>
	/// <param name="name"></param>
	void setName(string name);

	/// <summary>
	/// ����� �� ������� �� �����
	/// </summary>
	/// <returns></returns>
	string getName();

	/// <summary>
	/// ����� �� ������� �� ����������� �����
	/// </summary>
	/// <param name="facNumber"></param>
	void setFakNumber(string facNumber);

	/// <summary>
	/// ����� �� ������� �� ����������� �����
	/// </summary>
	/// <returns></returns>
	string getFakNumber();

	/// <summary>
	/// ����� �� ������� �� ������
	/// </summary>
	/// <param name="birthDate"></param>
	void setBirthDate(Date birthDate);

	/// <summary>
	/// ����� �� ������� �� ������
	/// </summary>
	/// <returns></returns>
	Date getBirthDate();

	/// <summary>
	/// ����� �� ������� �� ������� �����
	/// </summary>
	/// <param name="avrGrade"></param>
	void setAvrGrade(double avrGrade);

	/// <summary>
	/// ����� �� ������� �� ������
	/// </summary>
	/// <returns></returns>
	double getAvrGrade();

	/// <summary>
	/// ����� ����� ����� ��������� �� �������� � ������
	/// </summary>
	/// <param name="date"></param>
	/// <returns></returns>
	int getStudentAge(Date date);

	/// <summary>
	/// ������������ �������� << �� ��������� �� ������� �� ����� Student
	/// </summary>
	/// <param name="out"></param>
	/// <param name="stud"></param>
	/// <returns></returns>
	friend std::ostream& operator << (std::ostream& out, const Student& stud);
};

#endif