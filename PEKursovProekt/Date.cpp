#include "Date.h"
#include <string.h>
#include <iostream>

using namespace std;

Date::Date()
{
	day = 1;
	month = 1;
	year = 1;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

void Date::setDay(int day)
{
	while (day > 31 || day < 1)
	{
		cout << "Invalid day. Please Enter another day: " << endl;
		cin >> day;
	}
	this->day = day;
}

int Date::getDay()
{
	return day;
}

void Date::setMonth(int month)
{
	while (month > 12 || month < 1)
	{
		cout << "Invalid month. Please Enter another month: " << endl;
		cin >> month;
	}
	this->month = month;
}

int Date::getMonth()
{
	return month;
}

void Date::setYear(int year)
{
	while (year > 2005 || year < 1950)
	{
		cout << "Invalid year. Please Enter another year: " << endl;
		cin >> year;
	}
	this->year = year;
}

int Date::getYear()
{
	return year;
}


std::string Date::getDate()
{
	return std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
}

std::ostream& operator << (std::ostream& out, const Date& date)
{
	out << std::to_string(date.day) + "." + std::to_string(date.month) + "." + std::to_string(date.year);
	return out;
}
