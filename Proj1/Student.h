#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	string name;
	string studentID;
	string birthYear;
	string department;
	string tel;

	void SetName(string name);
	void SetStudentID(string studentID);
	void SetBirthYear(string birthYear);
	void SetDepartment(string department);
	void SetTel(string tel);


public:
	Student(string name, string studentID); //Name and Student ID should not be blank
	Student(string name, string studentID, string birthYear, string department, string tel);

	string GetName();
	string GetStudentID();
	string GetBirthYear();
	string GetDepartment();
	string GetTel();

	void Print();

	static bool IsNameVaild(string name) {
		if ((name.length() <= 15) && (name.empty() == 0)) {
			return true;
		}
		else {
			cout << "Error : Name should not be empty and it's length should be under 15!" << endl;
			return false;
		}
	}

	static bool IsStudentIDVaild(string studentID) {
		if ((studentID.length() == 10) && (studentID.empty() == 0)) {
			return true;
		}
		else {
			cout << "Error : studentID should not be empty and it should be exactly 10 digits!" << endl;
			return false;
		}
	}

	static bool IsBirthYearVaild(string BirthYear) {
		if ((BirthYear.length() == 4)) {
			return true;
		}
		else {
			cout << "Error : BirthYear should be exactly 4 digits!" << endl;
			return false;
		}
	}

	static bool IsTelVaild(string Tel) {
		if ((Tel.length() <= 12)) {
			return true;
		}
		else {
			cout << "Error : Tel's length should be under 12!" << endl;
			return false;
		}
	}
};