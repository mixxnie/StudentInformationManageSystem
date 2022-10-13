#include <iostream>
#include "SIMS.h"
#include "Student.h"
#include "StudentList.h"
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
#include <iomanip> 
#include <string>


using namespace std;

SIMS::SIMS(string filePath) {
	StudentList studentList = StudentList(filePath);
	while (1) {
		studentList.LoadFile(filePath);
		ShowMenu();
		int menu;
		menu = Input();
		SelectMenu(studentList, menu);
	}
}

/* Main Page */

void SIMS::ShowMenu() { //display the main menu
	cout << "1. Insertion" << endl;
	cout << "2. Search" << endl;
	cout << "3. Sorting Option" << endl;
	cout << "4. Exit" << endl;
}

int SIMS::Input() {
	int menu;
	cin >> menu;
	system("cls");
	cin.ignore();

	return menu;
}

void SIMS::SelectMenu(StudentList studentList, int menu) { //메뉴선택
	switch (menu) {
	case 1: //Insertion
		InsertStudent(studentList);
		break;
	case 2: //Search
		SearhStudent(studentList);
		break;
	case 3: //Sorting Option
		SortStudent(studentList);
		break;
	case 4: //Exit
		exit(1);
		break;
	}
}

/* Page1. Insertion */

void SIMS::InsertStudent(StudentList studentList) {
	vector<string> studentInfo;
	studentInfo = InputStudent(studentList);

	Student student = Student(studentInfo.at(0), studentInfo.at(1), studentInfo.at(2), studentInfo.at(3), studentInfo.at(4));
	studentList.PushStudent(student);

	studentList.Write(student);

	int sortBy;
	sortBy = studentList.GetSortBy();
	SelectSortMenu(studentList, sortBy);

	Sleep(100);
	system("cls");
}

vector<string> SIMS::InputStudent(StudentList studentList) {
	string name;
	string studentID;
	string birthYear;
	string department;
	string tel;


	do {
		cout << "Name ?";
		getline(cin, name);
	} while (Student::IsNameVaild(name) == false);


	do {
		cout << "Student ID(10 digits) ?";
		getline(cin, studentID);
	} while ((Student::IsStudentIDVaild(studentID) == false) || (IsStudentIDNew(studentList, studentID) == false));

	do {
		cout << "Birth Year(4 digits) ?";
		getline(cin, birthYear);
	} while (Student::IsBirthYearVaild(birthYear) == false);

	cout << "Department ?";
	getline(cin, department);

	do {
		cout << "Tel ?";
		getline(cin, tel);
	} while (Student::IsTelVaild(tel) == false);


	vector<string> studentInfo;

	studentInfo = { name , studentID , birthYear , department , tel };

	return studentInfo;
}


bool SIMS::IsStudentIDNew(StudentList studentList, string studentID) {
	bool tmp = true;
	for (int i = 0; i < studentList.GetSize(); i++) {
		Student student = studentList.GetStudent(i);
		if (studentID.compare(student.GetStudentID()) == 0) {
			cout << "Error : Already inserted" << endl;
			return tmp = false;
		}
	}
	return tmp;
}

/* Page2. Search */

void SIMS::SearhStudent(StudentList studentList) {
	ShowSearchMenu();
	int menu;
	menu = Input();
	SelectSearchMenu(studentList, menu);
}

void SIMS::ShowSearchMenu() {
	cout << "- Search -" << endl;
	cout << "1. Search by name" << endl;
	cout << "2. Search by student ID(10 numbers)" << endl;
	cout << "3. Search by admission year(4 numbers)" << endl;
	cout << "4. Search by department name" << endl;
	cout << "5. List All" << endl;
}

void SIMS::SelectSearchMenu(StudentList studentList, int menu) {

	string name;
	string studentID;
	string admissionYear;
	string departmentName;

	switch (menu) {
	case 1:
		cout << "Name keyword? ";
		getline(cin, name);
		SearchName(studentList, name);
		break;
	case 2:
		cout << "Student ID keyword? ";
		getline(cin, studentID);
		SearchStudentID(studentList, studentID);
		break;
	case 3:
		cout << "Admission Year keyword? ";
		getline(cin, admissionYear);
		SearchAdmissionYear(studentList, admissionYear);
		break;
	case 4:
		cout << "Department name keyword? ";
		getline(cin, departmentName);
		SearchDepartmentName(studentList, departmentName);
		break;
	case 5:
		if (studentList.GetSize() != 0) {
			studentList.Print();
		}
		else {
			cout << "Nothing in List" << endl;
		}

		break;
	}
}

void SIMS::DisplayIndex() {
	cout.setf(ios::left);
	cout << endl << setw(15) << "Name" << setw(15) << "StudentID" << setw(15) << "Dept" << setw(15) << "Birth Year" << setw(15) << "Tel" << endl;
}


void SIMS::SearchName(StudentList studentList, string name) {
	DisplayIndex();
	for (int i = 0; i < studentList.GetSize(); i++) {
		Student student = studentList.GetStudent(i);
		if (name.compare(student.GetName()) == 0) {
			student.Print();
		}
	}
	cout << endl;
}
void SIMS::SearchStudentID(StudentList studentList, string studentID) {
	DisplayIndex();
	for (int i = 0; i < studentList.GetSize(); i++) {
		Student student = studentList.GetStudent(i);
		if (studentID.compare(student.GetStudentID()) == 0) {
			student.Print();
		}
	}
	cout << endl;
}

void SIMS::SearchAdmissionYear(StudentList studentList, string admissionYear) {
	DisplayIndex();
	for (int i = 0; i < studentList.GetSize(); i++) {
		Student student = studentList.GetStudent(i);
		string newAdmissionYear = student.GetStudentID().substr(0, 4);
		if (admissionYear.compare(newAdmissionYear) == 0) {
			student.Print();
		}
	}
	cout << endl;
}
void SIMS::SearchDepartmentName(StudentList studentList, string departmentName) {
	DisplayIndex();
	for (int i = 0; i < studentList.GetSize(); i++) {
		Student student = studentList.GetStudent(i);
		if (departmentName.compare(student.GetDepartment()) == 0) {
			student.Print();
		}
	}
	cout << endl;
}

/* Page3. Sorting Option */

void SIMS::SortStudent(StudentList studentList) {
	ShowSortMenu();
	int menu;
	menu = Input();
	SelectSortMenu(studentList, menu);
}

void SIMS::ShowSortMenu() {
	cout << "-Sorting Option" << endl;
	cout << "1. Sort by Name" << endl;
	cout << "2. Sort by Student ID" << endl;
	cout << "3. Sort by Admission Year" << endl;
	cout << "4. Sort by Department name" << endl;
}

void SIMS::SelectSortMenu(StudentList studentList, int menu) {
	switch (menu) {
	case 1:
		studentList.SetSortBy(1);
		break;
	case 2:
		studentList.SetSortBy(2);
		break;
	case 3:
		studentList.SetSortBy(3);
		break;
	case 4:
		studentList.SetSortBy(4);
		break;
	}
}

