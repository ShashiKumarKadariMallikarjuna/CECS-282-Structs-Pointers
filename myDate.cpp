//Shashi Kumar Kadari Mallikarjuna
//CECS 282
//Prog-3: Structs and Pointers
//Due - Oct 18,2018
#include "myDate.h"
#include <iostream>
string monthName(int);
//converts Gregorian date to Julain Date

int myDate :: Greg2Julian(int month, int day, int year)
{
	int i, j, k;
	i = year;
	j = month;
	k = day;
	int JD = k - 32075 + 1461 * (i + 4800 + (j - 14) / 12) / 4 + 367 * (j - 2 - (j - 14) / 12 * 12) / 12 - 3 * ((i + 4900 + (j - 14) / 12) / 100) / 4;
	return JD;
}
//converts Julian date to Gregorian date
void myDate::Julian2Greg(int JD, int &month, int &day, int &year)
{
	int i, j, k;
	int l = JD + 68569;
	int n = 4 * l / 146097;
	l = l - (146097 * n + 3) / 4;
	i = 4000 * (l + 1) / 1461001;
	l = l - 1461 * i / 4 + 31;
	j = 80 * l / 2447;
	k = l - 2447 * j / 80;
	l = j / 11;
	j = j + 2 - 12 * l;
	i = 100 * (n - 49) + i + l;
	year = i;
	month = j;
	day = k;
}

//constructor which initializes the date to 5/11/1959
myDate::myDate()
{
	day = 11;
	month = 5;
	year = 1959;
}
//overloaded constructor which sets the date with the values
myDate::myDate(int M, int D, int Y)
{
	int JD = Greg2Julian(M, D, Y);
	int tempM, tempD, tempY;
	Julian2Greg(JD, tempM, tempD, tempY);
	if (tempM == M && tempD == D && tempY == Y) {
		month = M;
		day = D;
		year = Y;
	}
	else {
		day = 11;
		month = 5;
		year = 1959;
	}
}
//display the date in the following format(May 11, 1959)
string myDate::display()
{
	return monthName(month) +" "+to_string( day)+", " +to_string( year);

}
//increments the date by N days
void myDate::increaseDate(int n)
{
	int jd = Greg2Julian(month, day, year);
	jd += n;
	Julian2Greg(jd, month, day, year);
}
//decrements the date by N days
void myDate::decreaseDate(int N)
{
	int JD = Greg2Julian(month, day, year);
	JD -= N;
	Julian2Greg(JD, month, day, year);
}
//returns the number of days between this date and the date D.
int myDate::daysBetween(myDate d)
{
	int jd = Greg2Julian(month, day, year);
	int jd1 = Greg2Julian(d.getMonth(), d.getDay(), d.getYear());
	return jd1 - jd;
}
//returns the month
int myDate::getMonth()
{
	return month;
}
//returns the day
int myDate::getDay()
{
	return day;
}
//returns the year
int myDate::getYear()
{
	return year;
}
//returns the number of days since the current year began
int myDate::dayOfYear()
{
	int JD = Greg2Julian(1, 1, year);
	int JD1 = Greg2Julian(month, day, year);
	return JD1 - JD + 1;
}

//returns the day of the week
string myDate::dayName()
{
	int JD = Greg2Julian(month, day, year);
	switch (JD % 7) {
	case 0:
		return "Monday";
	case 1:
		return "Tuesday";
	case 2:
		return "Wednesday";
	case 3:
		return "Thursday";
	case 4:
		return "Friday";
	case 5:
		return "Saturday";
	case 6:
		return "Sunday";
	default:
		return "cc ";
	}
}
//returns the name of the month
string monthName(int month) {
	switch (month) {
	case 1:
		return "January";
	case 2:
		return "February";
	case 3:
		return "March";
	case 4:
		return "April";
	case 5:
		return "May";
	case 6:
		return "June";
	case 7:
		return "July";
	case 8:
		return "August";
	case 9:
		return "September";
	case 10:
		return "October";
	case 11:
		return "November";
	case 12:
		return "December";
	default:
		return " ";
	}

}