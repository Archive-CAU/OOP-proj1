#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include "Student.h"
using namespace std;

class SIMS {
private:
	int input; // variable that contain every input
	vector<Student> studentList; // vector that contain Student obj

public:
	SIMS();

	vector<string> split(string str, char Delimiter);

	void ShowMainMenu();

	void InsertStudent();

	void SearchStudent();
	void PrintSearchFormat();
	void SearchByName(string keyword);
	void SearchBySID(string keyword);
	void SearchByAdYear(string keyword);
	void SearchByDept(string keyword);
	void ShowAll();

	void SortStudent();
	void SortByName();
	void SortBySID();
	void SortByAdYear();
	void SortByDept();

	void Exit();

	void FileWrite();
};

