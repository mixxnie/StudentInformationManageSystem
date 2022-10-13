#include <iostream>
#include <string>
#include <iomanip> 
#include "Student.h"
using namespace std;

Student::Student(string name, string studentID) {//Name and Student ID should not be blank
	SetName(name);
	SetStudentID(studentID);
}

Student::Student(string name, string studentID, string birthYear, string department, string tel) {
	SetName(name);
	SetStudentID(studentID);
	SetBirthYear(birthYear);
	SetDepartment(department);
	SetTel(tel);
}

string Student::GetName() {
	return name;
}
string Student::GetStudentID() {
	return studentID;
}
string Student::GetBirthYear() {
	return birthYear;
}
string Student::GetDepartment() {
	return department;
}
string Student::GetTel() {
	return tel;
}

void Student::SetName(string name) { //up to 15 (English) characters
	if (IsNameVaild(name) == true) {
		this->name = name;
	}
}
void Student::SetStudentID(string studentID) { //exactly 10 digits where first 4 digits represent admission year
	if (IsStudentIDVaild(studentID) == true) {
		this->studentID = studentID;
	}
}
void Student::SetBirthYear(string birthYear) { //exactly 4 digits
	if (IsBirthYearVaild(birthYear) == true) {
		this->birthYear = birthYear;
	}
}
void Student::SetDepartment(string department) {
	this->department = department;
}
void Student::SetTel(string tel) { //up to 12 digits
	if (IsTelVaild(studentID) == true) {
		this->tel = tel;
	}
}

void Student::Print() {
	cout.setf(ios::left);
	cout << setw(15) << GetName();
	cout << setw(15) << GetStudentID();
	cout << setw(15) << GetDepartment();
	cout << setw(15) << GetBirthYear();
	cout << setw(15) << GetTel() << endl;
}