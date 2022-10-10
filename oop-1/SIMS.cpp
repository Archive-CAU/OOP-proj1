#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include "SIMS.h"
using namespace std;

SIMS::SIMS() {
	// file processing
	ifstream fin("file1.txt");

	if (fin.fail()) { // have to create file1.txt 
		cout << "file doesn't exist" << endl;
	}
	else { // use file1.txt already existed
		cout << "file exists !" << endl;
	}

	// Initiating window
	Sleep(700);
	system("cls");
	ShowMainMenu();
}

void SIMS::ShowMainMenu() {
	cout << studentList.size() << endl;
	// Initiating window
	cout << "1. Insertion" << endl;
	cout << "2. Search" << endl;
	cout << "3. Sorting Option" << endl;
	cout << "4. Exit" << endl;
	cout << "> ";
	cin >> input;

	switch (input) {
	case 1:
		InsertStudent();
		break;
	case 2:
		SearchStudent();
		break;
	case 3:
	case 4:
		Exit();
		break;
	default:
		cin >> input;
	}
}

void SIMS::InsertStudent() {
	system("cls");

	string name;
	string sID;
	string bYear;
	string dept;
	string tel;

	cin.ignore();

	cout << "Name ? ";
	getline(cin, name);

	cout << "Student ID (10 digits) ? ";
	getline(cin, sID);

	cout << "Birth Year (4 digits) ? ";
	getline(cin, bYear);

	cout << "Department ? ";
	getline(cin, dept);

	cout << "Tel ? ";
	getline(cin, tel);

	studentList.push_back(Student(name, sID, bYear, dept, tel));

	cout << "adding new student..." << endl;

	Sleep(700);
	system("cls");
	ShowMainMenu();
}

void SIMS::SearchStudent() {
	system("cls");

	string keyword;

	cout << "1. Search by name" << endl;
	cout << "2. Search by student ID (10 numbers)" << endl;
	cout << "3. Search by admission year (4 numbers)" << endl;
	cout << "4. Search by department name" << endl;
	cout << "5. List All" << endl;
	cout << "> ";
	cin >> input;

	cin.ignore();
	switch (input) {
	case 1:
		cout << endl << "Name keyword ? ";
		getline(cin, keyword);
		SearchByName(keyword);
		break;
	case 2:
		cout << endl << "Student ID keyword ? ";
		getline(cin, keyword);
		SearchBySID(keyword);
		break;
	case 3:
		cout << endl << "Admission year keyword ? ";
		getline(cin, keyword);
		SearchByAdYear(keyword);
		break;
	case 4:
		cout << endl << "Department name keyword ? ";
		getline(cin, keyword);
		SearchByDept(keyword);
		break;
	case 5:
		ShowAll();
		break;
	default:
		cin >> input;
	}
}
void SIMS::PrintSearchFormat() {
	cout << endl;
	cout << setw(15) <<"Name";
	cout << setw(15) << "StudentID";
	cout << setw(15) << "Dept";
	cout << setw(15) << "Birth Year";
	cout << setw(15) << "Tel" << endl;
}

void SIMS::SearchByName(string keyword) {
	PrintSearchFormat();
	for (int i = 0; i < studentList.size(); i++) {
		if (studentList[i].GetName() == keyword) {
			cout << setw(15) << studentList[i].GetName();
			cout << setw(15) << studentList[i].GetSID();
			cout << setw(15) << studentList[i].GetDept();
			cout << setw(15) << studentList[i].GetBYear();
			cout << setw(15) << studentList[i].GetTel() << endl;
		}
	}

	cout << endl << "Press any key for next step ";
	_getch();
	system("cls");
	ShowMainMenu();
}
void SIMS::SearchBySID(string keyword) {
	PrintSearchFormat();
	for (int i = 0; i < studentList.size(); i++) {
		if (studentList[i].GetSID() == keyword) {
			cout << setw(15) << studentList[i].GetName();
			cout << setw(15) << studentList[i].GetSID();
			cout << setw(15) << studentList[i].GetDept();
			cout << setw(15) << studentList[i].GetBYear();
			cout << setw(15) << studentList[i].GetTel() << endl;
		}
	}

	cout << endl << "Press any key for next step ";
	_getch();
	system("cls");
	ShowMainMenu();
}
void SIMS::SearchByAdYear(string keyword) {
	PrintSearchFormat();
	for (int i = 0; i < studentList.size(); i++) {
		if (studentList[i].GetSID().substr(0,4) == keyword) {
			cout << setw(15) << studentList[i].GetName();
			cout << setw(15) << studentList[i].GetSID();
			cout << setw(15) << studentList[i].GetDept();
			cout << setw(15) << studentList[i].GetBYear();
			cout << setw(15) << studentList[i].GetTel() << endl;
		}
	}

	cout << endl << "Press any key for next step ";
	_getch();
	system("cls");
	ShowMainMenu();
}
void SIMS::SearchByDept(string keyword) {
	PrintSearchFormat();
	for (int i = 0; i < studentList.size(); i++) {
		if (studentList[i].GetDept() == keyword) {
			cout << setw(15) << studentList[i].GetName();
			cout << setw(15) << studentList[i].GetSID();
			cout << setw(15) << studentList[i].GetDept();
			cout << setw(15) << studentList[i].GetBYear();
			cout << setw(15) << studentList[i].GetTel() << endl;
		}
	}

	cout << endl << "Press any key for next step ";
	_getch();
	system("cls");
	ShowMainMenu();
}
void SIMS::ShowAll() {
	PrintSearchFormat();
	for (int i = 0; i < studentList.size(); i++) {
		cout << setw(15) << studentList[i].GetName();
		cout << setw(15) << studentList[i].GetSID();
		cout << setw(15) << studentList[i].GetDept();
		cout << setw(15) << studentList[i].GetBYear();
		cout << setw(15) << studentList[i].GetTel() << endl;
	}

	cout << endl << "Press any key for next step ";
	_getch();
	system("cls");
	ShowMainMenu();
}

void SIMS::SortStudent() {
	system("cls");

	cout << "1. Sort by Name" << endl;
	cout << "2. Sort by Student ID" << endl;
	cout << "3. Sort by Admission year" << endl;
	cout << "4. Sort by Department name" << endl;
	cout << "> ";
	cin >> input;
}

void SIMS::Exit() {
	exit(1);
}