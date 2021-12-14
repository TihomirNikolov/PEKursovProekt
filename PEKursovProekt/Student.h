#ifndef Student_H
#define Student_H
#include <string>
#include "Date.h"

using std::string;

class Student
{

private:
	/// <summary>
	/// Име на студента
	/// </summary>
	string name;

	/// <summary>
	/// Факултетен номер на студента
	/// </summary>
	string facNumber;

	/// <summary>
	/// Рожденна дата на студента
	/// </summary>
	Date birthDate;

	/// <summary>
	/// Среден успех на студента
	/// </summary>
	double avrGrade;

public:
	/// <summary>
	/// Конструктор по подразбиране 
	/// </summary>
	Student();

	/// <summary>
	/// Конструктор с параметри
	/// </summary>
	/// <param name="name"></param>
	/// <param name="facNumber"></param>
	/// <param name="birthDate"></param>
	/// <param name="avrGrade"></param>
	Student(string name, string facNumber, Date birthDate, double avrGrade);

	/// <summary>
	/// Метод за промяна на името
	/// </summary>
	/// <param name="name"></param>
	void setName(string name);

	/// <summary>
	/// Метод за взимане на името
	/// </summary>
	/// <returns></returns>
	string getName();

	/// <summary>
	/// Метод за промяна на факултетния номер
	/// </summary>
	/// <param name="facNumber"></param>
	void setFakNumber(string facNumber);

	/// <summary>
	/// Метод за взимане на факултетния номер
	/// </summary>
	/// <returns></returns>
	string getFakNumber();

	/// <summary>
	/// Метод за промяна на датата
	/// </summary>
	/// <param name="birthDate"></param>
	void setBirthDate(Date birthDate);

	/// <summary>
	/// Метод за взимане на датата
	/// </summary>
	/// <returns></returns>
	Date getBirthDate();

	/// <summary>
	/// Метод за промяна на средния успех
	/// </summary>
	/// <param name="avrGrade"></param>
	void setAvrGrade(double avrGrade);

	/// <summary>
	/// Метод за взимане на успеха
	/// </summary>
	/// <returns></returns>
	double getAvrGrade();

	/// <summary>
	/// Метод който връща възрастта на студента в години
	/// </summary>
	/// <param name="date"></param>
	/// <returns></returns>
	int getStudentAge(Date date);

	/// <summary>
	/// Предефиниран оператор << за извеждане на данните на класа Student
	/// </summary>
	/// <param name="out"></param>
	/// <param name="stud"></param>
	/// <returns></returns>
	friend std::ostream& operator << (std::ostream& out, const Student& stud);
};

#endif