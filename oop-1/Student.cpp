#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

Student::Student(string name, string sID, string bYear, string dept, string tel) {
	this->name = name;
	this->sID = sID;
	this->bYear = bYear;
	this->dept = dept;
	this->tel = tel;
}

void Student::SetName(string name) {
	name = name;
}
string Student::GetName() {
	return name;
}

void Student::SetSID(string sID) {
	sID = sID;
}
string Student::GetSID() {
	return sID;
}

void Student::SetBYear(string bYear) {
	bYear = bYear;
}
string Student::GetBYear() {
	return bYear;
}

void Student::SetDept(string dept) {
	dept = dept;
}
string Student::GetDept() {
	return dept;
}

void Student::SetTel(string tel) {
	tel = tel;
}
string Student::GetTel() {
	return tel;
}