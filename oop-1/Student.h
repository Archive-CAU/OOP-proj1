#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string name;
	string sID;
	string bYear;
	string dept;
	string tel;

public:
	Student(string name, string sID, string bYear, string dept, string tel);

	void SetName(string name);
	string GetName();
	
	void SetSID(string sID);
	string GetSID();

	void SetBYear(string bYear);
	string GetBYear();

	void SetDept(string dept);
	string GetDept();

	void SetTel(string tel);
	string GetTel();
};

