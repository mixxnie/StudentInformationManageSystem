#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "student.h"
using namespace std;

class StudentList {
private:
	int sortBy;

public:
	vector<Student> studentList;
	StudentList(string filename);

	int GetSize();
	Student GetStudent(int num);
	int GetSortBy();
	void SetSortBy(int sortBy);

	void PushStudent(Student student);
	void LoadFile(string filename);
	vector<string> split(string line);

	void Write(Student student);
	void Write();
	void Print();

	void SortName();
	void SortStudentID();
	void SortAdmissionYear();
	void SortDepartmentName();
};