#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "student.h"
#include "StudentList.h"
using namespace std;

class SIMS {
private:
	/* Main Page */
	void ShowMenu(); //display the main menu
	int Input(); //get user's input
	void SelectMenu(StudentList studentList, int menu);

	/* Page1. Insertion */
	void InsertStudent(StudentList studentList); 
	vector<string> InputStudent(StudentList studentList); //get Input Student from student
	bool IsStudentIDNew(StudentList studentList, string studentID);

	/* Page2. Search */
	void SearhStudent(StudentList studentList);
	void ShowSearchMenu();

	void SelectSearchMenu(StudentList studentList, int menu);

	void DisplayIndex();

	void SearchName(StudentList studentList, string name);
	void SearchStudentID(StudentList studentList, string studentID);
	void SearchAdmissionYear(StudentList studentList, string admissionYear);
	void SearchDepartmentName(StudentList studentList, string departmentName);

	/* Page3. Sorting Option */
	void SortStudent(StudentList studentList);
	void ShowSortMenu();
	void SelectSortMenu(StudentList studentList, int menu);

public:
	SIMS(string filePath);


};