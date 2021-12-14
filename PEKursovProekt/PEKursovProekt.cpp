#include <iostream>
#include <string>
#include <fstream>
#include "StudentFlow.h"
#include <regex>

using namespace std;

/// <summary>
/// Чете данните на студентите от текстов файл
/// </summary>
/// <returns></returns>
vector<Student> readStudentsFromFile();

void writeStudentInFile();

int main()
{
	try
	{
		int selectedOperation;
		do
		{
			cout << "Menu:" << endl << "1. Print average grade of the flow" << endl <<
				"2. Print the students between 18 and 26 years old" << endl <<
				"3. Create new student" << endl <<
				"4. Exit" << endl;

			cin >> selectedOperation;
			while (cin.fail())
			{
				cout << "Wrong input. Please choose a digit:" << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> selectedOperation;
			}
			switch (selectedOperation)
			{
			case 1:
			{
				StudentFlow flow(readStudentsFromFile());
				cout << "Average grade of the flow is " << flow.getAvrGrades() << endl;
				break;
			}
			case 2:
			{
				StudentFlow flow(readStudentsFromFile());
				cout << endl << "Student in the flow between 18 and 26 are " << endl << flow;
				break;
			}
			case 3:
			{
				writeStudentInFile();
				break;
			}
			case 4:
				exit(0);
			default:
				cout << "Invalid chosen operation. Please pick a valid option." << endl;
			}
			cout << endl;
		} while (selectedOperation != 4);
	}
	catch (exception e)
	{
	}
	return 0;
}

vector<Student> readStudentsFromFile()
{
	Student st; //Обект от тип студент за запазване на студента при четене от файл

	fstream myFile("StudentsFile.txt", std::ios_base::in); //Отваря файл за четене

	string fileRow; //String за запазване на информацията от ред от файла

	vector<Student> studs; //Списък със студентите

	try
	{
		int i = 0;

		int counter = 0;

		while (getline(myFile, fileRow))
		{
			string fileRowArr[5]; //Масив от String, елементите му се подават за създаване на обект от тип Student

			while (i < fileRow.length())
			{
				if (fileRow[i] != ' ')
				{
					fileRowArr[counter] += fileRow[i];
				}
				else
				{
					counter++;
				}
				i++;
			}
			i = 0;
			counter = 0;
			string dateArr[3]; //Масив от String, елементите му се подават за създаване на обект от тип Date

			while (i < fileRowArr[3].length())
			{
				if (fileRowArr[3][i] != '.')
				{
					dateArr[counter] += fileRowArr[3][i];
				}
				else
				{
					counter++;
				}
				i++;
			}

			Date tempDate = Date(stoi(dateArr[0]), stoi(dateArr[1]), stoi(dateArr[2]));
			i = 0;
			counter = 0;

			string studentName = fileRowArr[0] + " " + fileRowArr[1];

			st = Student(studentName, fileRowArr[2], tempDate, stod(fileRowArr[4]));
			studs.push_back(st);

		}

		myFile.close();
		return studs;
	}
	catch (exception e)
	{
		myFile.close();
		return studs;
	}
}

void writeStudentInFile()
{
	cin.clear(); //Изчиства cin оператора
	cin.ignore();
	Student st;

	fstream myFile("StudentsFile.txt", std::ios_base::app); //Отваря текстов файл за писане в него

	try
	{
		string name;
		const regex namePattern("^[a-zA-Z]+\s[a-zA-Z]+$"); // Името трябва да е във формат Име Фамилия
		cout << "Enter student name: ";
		getline(cin, name);

		while (regex_match(name, namePattern))
		{
			cout << "Invalid name. Please enter a valid name: ";
			cin.clear();
			cin.ignore(256, '\n');
			getline(cin, name);
		}

		st.setName(name);
		string facNumber;
		cout << "Enter faculty number: ";
		getline(cin, facNumber);

		const regex facNumberPattern("^(?:[1-9]{1}+[0-9]{8})$"); //Факултетния номер трябва да започва с 1 и да е 9 цифри

		while (regex_match(facNumber, facNumberPattern))
		{
			cout << "Invalid faculty number. Please enter a 9 digit faculcy number: " << endl;
			cin >> facNumber;
		}

		st.setFakNumber(facNumber);

		int day;
		cout << "Enter birth day: ";
		cin >> day;

		while (cin.fail() || day > 31 || day < 1)
		{
			cout << "Invalid day. Please enter a valid day: ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> day;
		}

		int month;
		cout << "Enter birth month: ";
		cin >> month;

		while (cin.fail() || month > 12 || month < 1)
		{
			cout << "Invalid month. Please enter a valid month: ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> month;
		}

		int year;
		cout << "Enter birth year: ";
		cin >> year;

		while (cin.fail() || year > 2006 || year < 1930)
		{
			cout << "Invalid year. Please enter a valid year: ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> year;
		}

		Date date(day, month, year);

		st.setBirthDate(date);

		double avrGrade;
		cout << "Enter average grade: ";
		cin >> avrGrade;

		while (cin.fail())
		{
			cout << "Invalid average grade. Please enter a valid number: ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> avrGrade;
		}
		st.setAvrGrade(avrGrade);

		myFile << st.getName() << " " << st.getFakNumber() << " " << st.getBirthDate().getDate() << " " << st.getAvrGrade() << endl;
		myFile.close();
	}
	catch (exception e)
	{
		myFile.close();
	}
}