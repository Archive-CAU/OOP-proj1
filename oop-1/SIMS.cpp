#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <algorithm>
#include <sstream>
#include "SIMS.h"
using namespace std;

SIMS::SIMS() {
	// file processing
	ifstream fin("file1.txt");

	if (fin.fail()) { // have to create file1.txt 
		cout << "file doesn't exist" << endl;
		ofstream fout("file1.txt");
	}
	else if (fin.is_open()) { // use file1.txt already existed
		cout << "file exists !" << endl;

		string line;
		while (getline(fin, line)) { // 
			vector<string> tempStudent = split(line, ',');
			studentList.push_back(Student(tempStudent[0], tempStudent[1], tempStudent[2], tempStudent[3], tempStudent[4]));
		}
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
		SortStudent();
		break;
	case 4:
		Exit();
		break;
	default:
		cin >> input;
	}
}

void SIMS::InsertStudent() {
	int flag = 0;

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

	// checking for already existed sID
	for (int i = 0; i < studentList.size(); i++) {
		if (studentList[i].GetSID() == sID)
			flag = 1;
	}

	if (flag == 1) {
		cout << "Error: Already inserted" << endl;
	}
	else {
		studentList.push_back(Student(name, sID, bYear, dept, tel));
		cout << "adding new student..." << endl;
		FileWrite();
	}

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
	cout.setf(ios::left);
	cout << endl;
	cout << setw(15) <<"Name";
	cout << setw(15) << "StudentID";
	cout << setw(25) << "Dept";
	cout << setw(15) << "Birth Year";
	cout << setw(15) << "Tel" << endl;
}

void SIMS::SearchByName(string keyword) {
	PrintSearchFormat();
	for (int i = 0; i < studentList.size(); i++) {
		if (studentList[i].GetName() == keyword) {
			cout << setw(15) << studentList[i].GetName();
			cout << setw(15) << studentList[i].GetSID();
			cout << setw(25) << studentList[i].GetDept();
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
			cout << setw(25) << studentList[i].GetDept();
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
			cout << setw(25) << studentList[i].GetDept();
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
			cout << setw(25) << studentList[i].GetDept();
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
		cout.setf(ios::left);
		cout << setw(15) << studentList[i].GetName();
		cout << setw(15) << studentList[i].GetSID();
		cout << setw(25) << studentList[i].GetDept();
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

	switch (input) {
	case 1:
		SortByName();
		break;
	case 2:
		SortBySID();
		break;
	case 3:
		SortByAdYear();
		break;
	case 4:
		SortByDept();
		break;
	default:
		cin >> input;
		break;
	}

}

void SIMS::SortByName() {
	vector<pair <string, string>> tempList; // SID, keyword
	vector<Student> sortedList;

	for (int i = 0; i < studentList.size(); i++)
		tempList.push_back(pair <string, string>(studentList[i].GetSID(), studentList[i].GetName()));
	sort(tempList.begin(), tempList.end());
	for (int i = 0; i < tempList.size(); i++) {
		for (int j = 0; j < studentList.size(); j++) {
			if (tempList[i].first == studentList[j].GetSID()) {
				sortedList.push_back(studentList[j]);
			}
		}
	}

	studentList = sortedList;
	cout << endl << "Press any key for next step ";
	FileWrite();
	_getch();
	system("cls");
	ShowMainMenu();
}
void SIMS::SortBySID() {
	vector<string> tempList; // SID
	vector<Student> sortedList;

	for (int i = 0; i < studentList.size(); i++)
		tempList.push_back(studentList[i].GetSID());
	sort(tempList.begin(), tempList.end());
	for (int i = 0; i < tempList.size(); i++) {
		for (int j = 0; j < studentList.size(); j++) {
			if (tempList[i] == studentList[j].GetSID()) {
				sortedList.push_back(studentList[j]);
			}
		}
	}

	studentList = sortedList;
	cout << endl << "Press any key for next step ";
	FileWrite();
	_getch();
	system("cls");
	ShowMainMenu();
}
void SIMS::SortByAdYear() {
	vector<pair <string, string>> tempList; // SID, keyword
	vector<Student> sortedList;

	for (int i = 0; i < studentList.size(); i++)
		tempList.push_back(pair <string, string>(studentList[i].GetSID(), studentList[i].GetBYear()));
	sort(tempList.begin(), tempList.end());
	for (int i = 0; i < tempList.size(); i++) {
		for (int j = 0; j < studentList.size(); j++) {
			if (tempList[i].first == studentList[j].GetBYear()) {
				sortedList.push_back(studentList[j]);
			}
		}
	}

	studentList = sortedList;
	cout << endl << "Press any key for next step ";
	FileWrite();
	_getch();
	system("cls");
	ShowMainMenu();
}
void SIMS::SortByDept() {
	vector<pair <string, string>> tempList; // SID, keyword
	vector<Student> sortedList;

	for (int i = 0; i < studentList.size(); i++)
		tempList.push_back(pair <string, string>(studentList[i].GetSID(), studentList[i].GetDept()));
	sort(tempList.begin(), tempList.end());
	for (int i = 0; i < tempList.size(); i++) {
		for (int j = 0; j < studentList.size(); j++) {
			if (tempList[i].first == studentList[j].GetDept()) {
				sortedList.push_back(studentList[j]);
			}
		}
	}

	studentList = sortedList;
	cout << endl << "Press any key for next step ";
	FileWrite();
	_getch();
	system("cls");
	ShowMainMenu();
}

void SIMS::Exit() {
	exit(1);
}

vector<string> SIMS::split(string str, char Delimiter) {
	istringstream iss(str);             // istringstream에 str을 담는다.
	string buffer;                      // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼

	vector<string> result;

	// istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
	while (getline(iss, buffer, Delimiter)) {
		result.push_back(buffer);               // 절삭된 문자열을 vector에 저장
	}

	return result;
}

void SIMS::FileWrite() {
	ofstream fout("file1.txt");
	for (int i = 0; i < studentList.size(); i++) {
		fout << studentList[i].GetName() << ',';
		fout << studentList[i].GetSID() << ',';
		fout << studentList[i].GetBYear() << ',';
		fout << studentList[i].GetDept() << ',';
		fout << studentList[i].GetTel() << endl;
	}
}