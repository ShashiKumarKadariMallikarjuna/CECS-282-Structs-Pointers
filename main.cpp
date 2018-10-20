//Shashi Kumar Kadari Mallikarjuna
//CECS 282
//Prog-3: Structs and Pointers
//Due - Oct 18,2018
#define _CRT_SECURE_NO_WARNINGS
#include "myDate.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include<time.h>
#include <iomanip>
using namespace std;

struct Student {
	char name[20];
	int ID;
	char grade;
	myDate bdate;
	string homeTown;
};

int menu();
void populate(Student []);
void display(Student []);
void display(Student *[]);
void swap(Student **, Student **);
void sortbyName(Student *[]);
void sortbyID(Student *[]);
void sortbyGrade(Student *[]);
void sortbyBirthday(Student *[]);
void sortbyHTown(Student *[]);

int main() {
	Student myClass[10];
	Student *Name[10];
	Student *ID[10];
	Student *Grade[10];
	Student *bday[10];
	Student *htown[10];
	for (int i = 0; i < 10; i++) {
		Name[i] = &myClass[i];
		ID[i] = &myClass[i];
		Grade[i] = &myClass[i];
		bday[i] = &myClass[i];
		htown[i] = &myClass[i];
	}

	populate(myClass);

	int option=0;
	while (option != 6) {
		option = menu();
		if (option == 0) {
			cout << endl<<"Original list of Student details"<<endl;
			display(myClass);
		}
		else if (option == 1) {
			cout << endl<<"Sorting by Name"<<endl;
			sortbyName(Name);
			display(Name);
		}
		else if (option == 2) {
			cout << endl << "Sorting by Student ID" << endl;
			sortbyID(ID);
			display(ID);
		}
		else if (option == 3) {
			cout << endl << "Sorting by Grade" << endl;
			sortbyGrade(Grade);
			display(Grade);
		}
		else if (option == 4) {
			cout << endl << "Sorting by Birthday" << endl;
			sortbyBirthday(bday);
			display(bday);
		}
		else if (option == 5) {
			cout << endl << "Sorting by Home Town" << endl;
			sortbyHTown(htown);
			display(htown);
		}
	}
	getchar();
	return 0;
}

int menu() {
	int option;
	cout << endl<<"0) Display original list"<<endl;
	cout << "1) Display list sorted by Name" << endl;
	cout << "2) Display list sorted by Student ID" << endl;
	cout << "3) Display list sorted by Grade" << endl;
	cout << "4) Display list sorted by Birthday" << endl;
	cout << "5) Display list sorted by Home Town" << endl;
	cout << "6) Exit"<<endl;
	cout << "Enter your option: " << endl;
	cin >> option;
	while (option < 0 || option>6) {
		cout << "INVALID option " << endl << "Enter your option: ";
		cin >> option;
	}
	return option;
}

void populate(Student sa[]) {
	char grades[5] = { 'A','B','C','D','F' };
	string hometowns[10] = { "Cerritos", "Buena Park", "La Palma", "La Mirada", "La Habra", "Whittier", "Artesia", "Norwalk", "Downey", "Santa Ana" };
	//assigning 10 student names
	strcpy(sa[0].name, "Steve");
	strcpy(sa[1].name, "Shashi");
	strcpy(sa[2].name,"Sponge Bob");
	strcpy(sa[3].name ,"Gare");
	strcpy(sa[4].name, "Rebacca");
	strcpy(sa[5].name, "Shiv");
	strcpy(sa[6].name, "Drake");
	strcpy(sa[7].name,"Ronaldo");
	strcpy(sa[8].name, "Kumar");
	strcpy(sa[9].name, "Ron");
	srand(time(0));
	for (int i= 0; i <10; i++) {
		//generates random non repeating ID
		int Random = rand() % 9000 + 1000;
		if (i == 0) {
			sa[i].ID = Random;
		}
		else {
			for (int j = 0; j < i ; j++) {
				while (Random == sa[i].ID) {
					Random = rand() % 9000 + 1000;
				}
			}
			sa[i].ID = Random;
		}
		//generates random date of birth
		sa[i].bdate = myDate(1, 1, 1995);
		myDate d2(12, 31, 2000);
		sa[i].bdate.increaseDate(rand() % sa[i].bdate.daysBetween(d2));
		//assigns random grades to students
		sa[i].grade = grades[rand() % 5];
		//assigns hometowns to students
		sa[i].homeTown = hometowns[i];
	}
}
//swap function to swap two students
void swap(Student **x, Student **y) {
	Student *temp;
	temp = *y;
	*y = *x;
	*x = temp;
}
//function that sorts by name
void sortbyName(Student *Nameptr[]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9 - i; j++) {
			if (strcmp(Nameptr[j]->name, Nameptr[j+1]->name) > 0) {
				swap(Nameptr[j],Nameptr[j+1]);
			}
		}	
	}
}
//function that sorts by Student ID
void sortbyID(Student *IDptr[]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9 - i; j++) {
			if (IDptr[j]->ID > IDptr[j + 1]->ID) {
				swap(IDptr[j], IDptr[j + 1]);
			}
		}
	}
}
//function that sorts by Grade
void sortbyGrade(Student *Gradeptr[]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9 - i; j++) {
			if (Gradeptr[j]->grade > Gradeptr[j + 1]->grade) {
				swap(Gradeptr[j], Gradeptr[j + 1]);
			}
		}
	}
}

//function that sorts by Birthday
void sortbyBirthday(Student *bday[]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9 - i; j++) {
			int month1, day1, year1, month2, day2, year2;
			month1 = bday[j]->bdate.getMonth();
			day1 = bday[j]->bdate.getDay();
			year1 = bday[j]->bdate.getYear();
			month2 = bday[j + 1]->bdate.getMonth();
			day2 = bday[j + 1]->bdate.getDay();
			year2 = bday[j + 1]->bdate.getYear();

			if (bday[j]->bdate.Greg2Julian(month1, day1, year1) > bday[j + 1]->bdate.Greg2Julian(month2, day2, year2))
			{
				swap(bday[j], bday[j + 1]);
			}
		}
	}
}

//function that sorts by Home town
void sortbyHTown(Student *Htownptr[]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9 - i; j++) {
			if ((Htownptr[j]->homeTown).compare( Htownptr[j + 1]->homeTown)>0) {
				swap(Htownptr[j], Htownptr[j + 1]);
			}
		}
	}
}
//display function that displays the formatted student details
void display(Student sa[]) {
	cout<< setw(15) << left << "Name"<< setw(15) << left << "Student ID"<< setw(10) << left << "Grade"<< setw(22) << left << "Birthday"<< setw(15) << left << "Home Town"<<endl;
	cout << setw(15) << left << "____" << setw(15) << left << "__________" << setw(10) << left << "_____" << setw(22) << left << "________" << setw(15) << left << "_________" << endl << endl;

		for (int i = 0; i < 10; i++) {
			cout << setw(15) << left << sa[i].name
				<< setw(15) << left << sa[i].ID
				<< setw(10) << left << sa[i].grade
				<< setw(22) << left << sa[i].bdate.display()
				<< setw(15) << left << sa[i].homeTown<<endl;
		}
}
void display(Student *sa[]) {
	cout << setw(15) << left << "Name" << setw(15) << left << "Student ID" << setw(10) << left << "Grade" << setw(22) << left << "Birthday" << setw(15) << left << "Home Town" << endl;
	cout << setw(15) << left << "____" << setw(15) << left << "__________" << setw(10) << left << "_____" << setw(22) << left << "________" << setw(15) << left << "_________" << endl << endl;
	for (int i = 0; i < 10; i++) {
		cout << setw(15) << left << sa[i]->name
			<< setw(15) << left << sa[i]->ID
			<< setw(10) << left << sa[i]->grade
			<< setw(22) << left << sa[i]->bdate.display()
			<< setw(15) << left << sa[i]->homeTown << endl;
	}
}
