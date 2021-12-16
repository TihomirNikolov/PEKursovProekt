#include <iostream>
#include <string>
#include <fstream>
#include "StudentFlow.h"
#include <regex>

using namespace std;

/// <summary>
/// ���� ������� �� ���������� �� ������� ����
/// </summary>
/// <returns></returns>
vector<Student> readStudentsFromFile();

/// <summary>
/// ������� ������������ �� ������� ��� �����
/// </summary>
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

			cout << "Choose an option: ";
			cin >> selectedOperation;
			while (cin.fail()) //��������� �� ������� ��� ������ �����
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Wrong input. Please choose a valid option: " << endl;
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
				cout << endl << "Student in the flow between 18 and 26 are " << endl << flow << endl;
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
	Student st; //����� �� ��� ������� �� ��������� �� �������� ��� ������ �� ����

	fstream myFile("StudentsFile.txt", std::ios_base::in); //������ ���� �� ������

	string fileRow; //String �� ��������� �� ������������ �� ��� �� �����

	vector<Student> studs; //������ ��� ����������

	try
	{
		int i = 0;

		int counter = 0;

		while (getline(myFile, fileRow))
		{
			string fileRowArr[5]; //����� �� String, ���������� �� �� ������� �� ��������� �� ����� �� ��� Student

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
			string dateArr[3]; //����� �� String, ���������� �� �� ������� �� ��������� �� ����� �� ��� Date

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
	cin.clear(); //�������� cin ���������
	cin.ignore();
	Student st;

	fstream myFile("StudentsFile.txt", std::ios_base::app); //������ ������� ���� �� ������ � ����

	try
	{
		string name;
		const regex namePattern(R"(^(?:[a-zA-Z]+\s[a-zA-Z]+)$)"); // ����� ������ �� � ��� ������ ��� �������
		cout << "Enter student name: ";
		getline(cin, name);

		while (!regex_match(name, namePattern))
		{
			cout << "Invalid name. Please enter a valid name in format Name FamilyName: ";
			getline(cin, name);
		}

		st.setName(name);
		string facNumber;
		cout << "Enter faculty number: ";
		getline(cin, facNumber);

		const regex facNumberPattern(R"(^(?:[1-9]{1}[0-9]{8})$)"); //����������� ����� ������ �� ������� � 1 � �� � 9 �����

		while (!regex_match(facNumber, facNumberPattern))
		{
			cout << "Invalid faculty number. Please enter a 9 digit faculcy number: ";
			getline(cin, facNumber);
		}

		st.setFakNumber(facNumber);

		int day;
		cout << "Enter birth day: ";
		cin >> day;

		while (cin.fail() || day > 31 || day < 1)
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid day. Please enter a valid day: ";
			cin >> day;
		}

		int month;
		cout << "Enter birth month: ";
		cin >> month;

		while (cin.fail() || month > 12 || month < 1)
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid month. Please enter a valid month: ";
			cin >> month;
		}

		int year;
		cout << "Enter birth year: ";
		cin >> year;

		while (cin.fail() || year > 2006 || year < 1930)
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid year. Please enter a valid year: ";
			cin >> year;
		}

		Date date(day, month, year);

		st.setBirthDate(date);

		double avrGrade;
		cout << "Enter average grade: ";
		cin >> avrGrade;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid average grade. Please enter a valid number: ";
			cin >> avrGrade;
		}
		st.setAvrGrade(avrGrade);

		myFile << st.getName() << " " << st.getFakNumber() << " " << st.getBirthDate().getDate() << " " << st.getAvrGrade() << endl;
		myFile.close();

		cout << "Added " << st;
	}
	catch (exception e)
	{
		cout << "There was an error " << e.what() << endl;
		myFile.close();
	}
}