#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip> 
#include <algorithm>
#include "Student.h"
#include "StudentList.h"

using namespace std;



StudentList::StudentList(string filename) {
	LoadFile(filename);
	SetSortBy(1); //The Default is "Sort by Name".
}


int StudentList::GetSize() {
	return studentList.size();
}

Student StudentList::GetStudent(int num) {
	return studentList.at(num);
}

int StudentList::GetSortBy() {
	return sortBy;
}

void StudentList::SetSortBy(int sortBy) {
	this->sortBy = sortBy;
	if (GetSize() != 0) {
		switch (sortBy) {
		case 1:
			SortName();
			break;
		case 2:
			SortStudentID();
			break;
		case 3:
			SortAdmissionYear();
			break;
		case 4:
			SortDepartmentName();
			break;
		}
	}
}

void StudentList::PushStudent(Student student) {
	studentList.push_back(student);
}


void StudentList::LoadFile(string filename) {
	studentList.clear();
	string line;
	ifstream file(filename); //open file1.txt, or create.
	vector<string> studentInfo;
	if (file.is_open()) {
		while (getline(file, line)) {
			studentInfo = split(line);
			Student student = Student(studentInfo.at(0), studentInfo.at(1), studentInfo.at(2), studentInfo.at(3), studentInfo.at(4));
			PushStudent(student);
		}
		file.close();
	}
}



vector<string> StudentList::split(string line) {
	istringstream iss(line);
	string buffer;

	vector<string> result;

	while (getline(iss, buffer, ',')) {
		result.push_back(buffer);
	}

	return result;
}

void StudentList::Write(Student student) {
	string line;
	ofstream file("file1.txt", ios::app);
	if (file.is_open()) {
		file << student.GetName() << "," << student.GetStudentID() << "," << student.GetBirthYear() << "," << student.GetDepartment() << "," << student.GetTel() << "\n";
		file.close();
	}
	else {
		cout << "error" << endl;
	}
}

void StudentList::Write() { //rewrite file based on object
	string line;
	ofstream file("file1.txt");
	if (file.is_open()) {
		int ListSize = GetSize();
		for (int i = 0; i < ListSize; i++) {
			file << GetStudent(i).GetName() << "," << GetStudent(i).GetStudentID() << "," << GetStudent(i).GetBirthYear() << "," << GetStudent(i).GetDepartment() << "," << GetStudent(i).GetTel() << "\n";
		}

		file.close();
	}
	else {
		cout << "error" << endl;
	}
}

void StudentList::Print() {
	cout.setf(ios::left);
	cout << setw(15) << "Name" << setw(15) << "StudentID" << setw(15) << "Dept" << setw(15) << "Birth Year" << setw(15) << "Tel" << endl;
	int ListSize = GetSize();
	for (int i = 0; i < ListSize; i++) {
		Student student = GetStudent(i);
		student.Print();
	}
	cout << endl;
}




void StudentList::SortName() {
	vector<pair<string, string>> compareList;
	Student tmpStudent = GetStudent(0);
	int listSize = GetSize();
	for (int i = 0; i < listSize; i++) {
		tmpStudent = GetStudent(i);
		compareList.push_back(pair<string, string>(tmpStudent.GetName(), tmpStudent.GetStudentID()));
	}

	sort(compareList.begin(), compareList.end());

	vector<Student> sortedStudentList;

	for (int i = 0; i < compareList.size(); i++) {
		for (int j = 0; j < listSize; j++) {
			tmpStudent = GetStudent(j);
			if ((compareList[i].second) == (tmpStudent.GetStudentID())) {
				sortedStudentList.push_back(tmpStudent);
			}

		}
	}

	 studentList = sortedStudentList;
	 Write();
}

void StudentList::SortStudentID() {
	vector<string> compareList;
	Student tmpStudent =  GetStudent(0);
	int listSize =  GetSize();
	for (int i = 0; i < listSize; i++) {
		tmpStudent =  GetStudent(i);
		compareList.push_back(tmpStudent.GetStudentID());
	}

	sort(compareList.begin(), compareList.end());

	vector<Student> sortedStudentList;

	for (int i = 0; i < compareList.size(); i++) {
		for (int j = 0; j < listSize; j++) {
			tmpStudent = GetStudent(j);
			if ((compareList[i]) == (tmpStudent.GetStudentID())) {
				sortedStudentList.push_back(tmpStudent);
			}

		}
	}

	studentList = sortedStudentList;
	
	Write();
}

void StudentList::SortAdmissionYear() {

	vector<pair<string, string>> compareList;
	Student tmpStudent = GetStudent(0);
	int listSize = GetSize();
	for (int i = 0; i < listSize; i++) {
		tmpStudent = GetStudent(i);
		string newAdmissionYear = tmpStudent.GetStudentID().substr(0, 4);
		compareList.push_back(pair<string, string>(newAdmissionYear, tmpStudent.GetStudentID()));
	}

	sort(compareList.begin(), compareList.end());

	vector<Student> sortedStudentList;

	for (int i = 0; i < compareList.size(); i++) {
		for (int j = 0; j < listSize; j++) {
			tmpStudent = GetStudent(j);
			if ((compareList[i].second) == (tmpStudent.GetStudentID())) {
				sortedStudentList.push_back(tmpStudent);
			}

		}
	}

	studentList = sortedStudentList;
	Write();
}
void StudentList::SortDepartmentName() {
	vector<pair<string, string>> compareList;
	Student tmpStudent = GetStudent(0);
	int listSize = GetSize();
	for (int i = 0; i < listSize; i++) {
		tmpStudent = GetStudent(i);
		compareList.push_back(pair<string, string>(tmpStudent.GetDepartment(), tmpStudent.GetStudentID()));
	}

	sort(compareList.begin(), compareList.end());

	vector<Student> sortedStudentList;

	for (int i = 0; i < compareList.size(); i++) {
		for (int j = 0; j < listSize; j++) {
			tmpStudent = GetStudent(j);
			if ((compareList[i].second) == (tmpStudent.GetStudentID())) {
				sortedStudentList.push_back(tmpStudent);
			}

		}
	}

	studentList = sortedStudentList;
	Write();
}