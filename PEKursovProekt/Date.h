#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>

class Date
{

private:
	/// <summary>
	/// Ден на датата
	/// </summary>
	int day;

	/// <summary>
	/// Месец на датата
	/// </summary>
	int month;

	/// <summary>
	/// Година на датата
	/// </summary>
	int year;

public:
	/// <summary>
	/// Конструктор по подразбиране
	/// </summary>
	Date();

	/// <summary>
	/// Конструктор с параматри
	/// </summary>
	/// <param name="day"></param>
	/// <param name="month"></param>
	/// <param name="year"></param>
	Date(int day, int month, int year);

	/// <summary>
	/// Метод за промяна на деня
	/// </summary>
	/// <param name="day"></param>
	void setDay(int day);

	/// <summary>
	/// Метод за взимане на деня
	/// </summary>
	/// <returns></returns>
	int getDay();

	/// <summary>
	/// Метод за промяна на месеца
	/// </summary>
	/// <param name="month"></param>
	void setMonth(int month);

	/// <summary>
	/// Метод за взимане на месеца
	/// </summary>
	/// <returns></returns>
	int getMonth();

	/// <summary>
	/// Метод за промяна на годината
	/// </summary>
	/// <param name="year"></param>
	void setYear(int year);

	/// <summary>
	/// Метод за взимане на годината
	/// </summary>
	/// <returns></returns>
	int getYear();

	/// <summary>
	/// Метод за взимане на датата във формат дд.мм.гггг.
	/// </summary>
	/// <returns></returns>
	std::string getDate();

	/// <summary>
	/// Pредефиниран оператор << за извеждане на данните на класа Date
	/// </summary>
	/// <param name="out"></param>
	/// <param name="date"></param>
	/// <returns></returns>
	friend std::ostream& operator << (std::ostream& out, const Date& date);
};

#endif