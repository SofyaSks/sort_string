#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <io.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

class Student
{
private:
	string name_;
	string surname;
	//int* marks;
	double avg;
public:
	Student() {}

	Student(string _name, string _surname)
	{
		name_ = _name;
		surname = _surname;
	}
	Student(string _name, string _surname, double _avg)
	{
		name_ = _name;
		surname = _surname;
		avg = _avg;
	}
	friend ostream& operator<<(ostream& os, Student& st)
	{
		os << setw(10) << st.name_ << setw(18) << st.surname << setw(5) << st.avg;
		return os;
	}
	void SetAvg()
	{
		avg = (rand() % 12 + 1) + (rand() % 100 / 100.0);
	}
	double GetAvg()
	{
		return avg;
	}
	void Read_file(vector<Student>& v)
	{
		ifstream is("Students.txt");
		Student tmp;
		for (string l; getline(is, l);)
		{
			is >> tmp.name_ >> tmp.surname >> tmp.avg;
			v.push_back(tmp);
		}
		is.close();

		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << endl;
		}
	}
	
	friend void sortSurname(Student* st, int size);
};



void sortSurname(Student *st, int size) {
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i+1; i < size - i - 1; j++)
		{
			if (_stricmp(st[j].surname.c_str(), st[j+1].surname.c_str()) < 0)
				swap(st[j], st[j+1]);
		}
	}
}

void main()
{
	srand(time(0));
	//vector <Student> students;

	const int size = 4;
	Student st1("s1", "Petrov");
	Student st2("s2", "Pavlov");
	Student st3("s3", "petrov");
	Student st4("s4", "Sidorov");
	Student st_all[size] = { st1,st2,st3,st4 };
	for (int i = 0; i < 4; i++)
	{
		st_all[i].SetAvg();
		cout << st_all[i] << endl;
	}

	sortSurname(st_all, size);
	cout << "*****************************" << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << st_all[i] << endl;
	}

	

}
