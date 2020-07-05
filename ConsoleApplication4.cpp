#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <math.h>

using namespace std;

struct Student {
	string firstname = "";
	string lastname = "";
	string phone = ""; // we're using string, because phone number is not a number
	string isNonresident = "false";
	int sub1 = rand() % 30;
	int sub2 = rand() % 30;
	int sub3 = rand() % 30;
};

// Vector is a dynamic array (container)
vector<Student> readStudents(); // definition of function
void writeStudents(vector<Student>& students);
vector<string> splitString(const string & s, char delimiter);
void displayMenu();
void enterStudent();
void showAllStudents();
void showStudentById(int id);

vector<Student> students = vector<Student>();

int main()
{
	displayMenu();
}

void displayMenu() {
	vector<Student> temp_students = vector<Student>();
	int choice = -1;
	int temp_id = -1;
	cout << "Choose one of following options: " << endl;
	cout << "1 for add next student" << endl;
	cout << "2 for show all students" << endl;
	cout << "3 for show student by ID" << endl;
	cout << "4 save students data to file" << endl;
	cout << "5 load students from file" << endl;
	cout << "Enter (1-5): ";
	while (choice < 1 || choice > 5) {
		cin >> choice;
	}
	switch (choice) {
	case 1: {
		enterStudent();
	}break;
	case 2: {
		showAllStudents();
	}break;
	case 3: {
		cout << "Enter student ID: " << endl;
		cin >> temp_id;
		showStudentById(temp_id);
		displayMenu();
	}break;
	case 4: {
		writeStudents(students);
		displayMenu();
	}break;
	case 5: {
		temp_students = readStudents();
		if (temp_students.size() > 0) {
			students = temp_students;
		}
		else {
			cout << "Something went wrong, no modification has been done." << endl;
		}
		displayMenu();
	}break;
	}
}
void enterStudent() {
	Student s;

	cout << "Enter student first name: " << endl;
	cin >> s.firstname;
	cout << "Enter student last name: " << endl;
	cin >> s.lastname;
	cout << "Enter student phone: " << endl;
	cin >> s.phone;
	cout << "Enter student is nonresident: " << endl;
	cin >> s.isNonresident;
	cout << "Enter student 1. subject: " << endl;
	cin >> s.sub1;
	cout << "Enter student 2. subject: " << endl;
	cin >> s.sub2;
	cout << "Enter student 3. subject: " << endl;
	cin >> s.sub3;

	students.push_back(s);

	cout << "Student has been added to database." << endl;
	displayMenu();
}
void showStudentById(int id) {
	if (students.size() == 0) {
		cout << "No students in database" << endl;
		return displayMenu();
	}
	if (id >= students.size() || id < 0) {
		cout << "Wrong student ID..." << endl;
		return displayMenu();
	}

	cout << "Student data: " << endl;
	cout << "ID: " << id << endl;
	cout << students.at(id).firstname << " " << students.at(id).lastname << endl;
	cout << "Phone: " << students.at(id).phone << endl;
	cout << "Is non residental: " << students.at(id).isNonresident << endl;
	cout << "Subjects: " << students.at(id).sub1 << ", " << students.at(id).sub2 << ", " << students.at(id).sub3 << endl;
	cout << "----------" << endl << endl;
}
void showAllStudents() {
	if (students.size() == 0) {
		cout << "No students in database" << endl;
		return displayMenu();
	}
	for (size_t i = 0; i < students.size(); i++) {
		showStudentById(i);
	}
	displayMenu();
}
vector<Student> readStudents() {
	vector<Student> out = vector<Student>();
	ifstream file;
	string path;
	cout << "Enter filename: " << endl;
	cin >> path;

	file.open(path);
	if (file.is_open()) {
		while (!file.eof()) {
			string temp = "";
			getline(file, temp);
			vector<string> sString = splitString(temp, ',');

			Student s;
			s.firstname = sString[0];
			s.lastname = sString[1];
			s.phone = sString[2];
			s.isNonresident = sString[3] == "true"; // if string is equal true then change boolean
			s.sub1 = stoi(sString[4]);
			s.sub2 = stoi(sString[5]);
			s.sub3 = stoi(sString[6]);

			out.push_back(s); // push temporary student object to an array
		}
		file.close(); // close the file
	}
	else {
		cout << "File doesn't exists.";
	}
	return out; // return pushed student objects
}
void writeStudents(vector<Student> &students) {
	ofstream file;
	string path;

	cout << "Enter filename: " << endl;
	cin >> path;

	file.open(path);

	if (file.is_open()) {
		for (size_t i = 0; i < students.size(); ++i) {
			file << students[i].firstname << "," << students[i].lastname << "," << students[i].phone << "," << students[i].isNonresident << "," << students[i].sub1 << "," << students[i].sub2 << "," << students[i].sub3;
			if (i < students.size() - 1) {
				file << endl;
			}
		}

		file.close();
		cout << "Write completed" << endl;
	}
	else {
		cout << "Sorry, but we cannot open file. Please check folder permissions." << endl;
	}
}

vector<string> splitString(const string & s, char delimiter)
{
	vector<string> tokens;
	string token;
	istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}