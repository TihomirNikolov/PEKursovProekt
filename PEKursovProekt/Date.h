#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>

class Date
{

private:
	/// <summary>
	/// ��� �� ������
	/// </summary>
	int day;

	/// <summary>
	/// ����� �� ������
	/// </summary>
	int month;

	/// <summary>
	/// ������ �� ������
	/// </summary>
	int year;

public:
	/// <summary>
	/// ����������� �� ������������
	/// </summary>
	Date();

	/// <summary>
	/// ����������� � ���������
	/// </summary>
	/// <param name="day"></param>
	/// <param name="month"></param>
	/// <param name="year"></param>
	Date(int day, int month, int year);

	/// <summary>
	/// ����� �� ������� �� ����
	/// </summary>
	/// <param name="day"></param>
	void setDay(int day);

	/// <summary>
	/// ����� �� ������� �� ����
	/// </summary>
	/// <returns></returns>
	int getDay();

	/// <summary>
	/// ����� �� ������� �� ������
	/// </summary>
	/// <param name="month"></param>
	void setMonth(int month);

	/// <summary>
	/// ����� �� ������� �� ������
	/// </summary>
	/// <returns></returns>
	int getMonth();

	/// <summary>
	/// ����� �� ������� �� ��������
	/// </summary>
	/// <param name="year"></param>
	void setYear(int year);

	/// <summary>
	/// ����� �� ������� �� ��������
	/// </summary>
	/// <returns></returns>
	int getYear();

	/// <summary>
	/// ����� �� ������� �� ������ ��� ������ ��.��.����.
	/// </summary>
	/// <returns></returns>
	std::string getDate();

	/// <summary>
	/// P����������� �������� << �� ��������� �� ������� �� ����� Date
	/// </summary>
	/// <param name="out"></param>
	/// <param name="date"></param>
	/// <returns></returns>
	friend std::ostream& operator << (std::ostream& out, const Date& date);
};

#endif