// ooplab1.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include "Time.h"
#include "Date.h"
#include "Duration.h"
#include <vector>
using namespace std;
class Time;
class Date;
// #######################################
bool compare(Date date1, Date date2) {
	if (date1.year < date2.year)
		return 0;
	if (date1.year > date2.year)
		return 1;
	if (date1.month < date2.month)
		return 0;
	if (date1.month > date2.month)
		return 1;
	if (date1.day < date2.day)
		return 0;
	if (date1.day > date2.day)
		return 1;
	return 0;
}
template <class T>
bool compare(T a, T b)
{
	if (a < b)
		return 0;
	else
		return 1;
}
template<class T>
class Node {
public:
	T field;
	Node<T>* next;

};
template <class T>
class List {
public:
	Node<T>* start=new Node<T>;
	List(T fd) { this->start->field = fd; this->start->next = NULL; }
	void List_sort() {
		Node<T>* newList;
		newList = this->start;
//		newList->field = this->start->field;
//		newList->next = NULL;
		Node<T>* i;
		Node<T>* j;
		i = start->next;
		while (i != NULL) {
			j = newList;
			if (compare(j->field, i->field))
			{
				Node<T>*temp = new Node<T>;
				temp->next = newList;
				temp->field = i->field;
				newList = temp;
				
			}
			else {
				while (j != NULL) {
					if (!compare(j->field, i->field) && (j->next == NULL || !compare(i->field, j->next->field))) {
						Node<T>* temp = j->next;
						if (j->next != NULL)
						{
							temp->field = j->next->field;
	//						temp->next = j->next->next;
						}
						else
							temp = NULL;
						j->next = new Node<T>; j->next->field = i->field;
						j->next->next = temp;
					}
					j = j->next;
				}
			}
			i = i->next;
		}
		start = newList;
	//	return newList;
	}
	void add(T fd) {
		Node<T>* temp = this->start;
		while (temp->next != NULL)
			temp = temp->next;
		Node<T>* newnode = new Node<T>;
		newnode->field = fd;
		newnode->next = NULL;
		temp->next = newnode;
	}
	void coutall() {
		Node<T>* temp = this->start;
		while (temp != NULL) {
			cout << temp->field << endl;
			temp = temp->next;

		}
	}
};


ostream &operator<<(ostream&out, Time &time) {
	out << time.hour << ":" << time.minutes << ":" << time.seconds;
	return out;
}//overflow operator << for time
/*
bool operator< (const Date &date1, const Date &date2)
{
	if (date1.year < date2.year)
		return 0;
	if (date1.year > date2.year)
		return 1;
	if (date1.month < date2.month)
		return 0;
	if (date1.month > date2.month)
		return 1;
	if (date1.day < date2.day)
		return 0;
	if (date1.day > date2.day)
		return 1;
	return 0;
}*/
istream &operator>>(istream&in, Time &time) {
	in >> time.hour >> time.minutes >> time.seconds;
	if (time.hour == 24) time.hour = 0;
	if (time.minutes == 60) time.minutes = 0;
	if (time.seconds == 60) time.seconds = 0;
	return in;
}//overflow operator >> for time

ostream &operator<<(ostream&out, Date& date) {
	out << date.day << "/" << date.month << "/" << date.year << " " << date.time;
	return out;
}//overflow operator << for date

istream &operator>>(istream&in, Date &date) {
	in >> date.day >> date.month >> date.year >> date.time;
	date.isLeap = (date.year % 4 == 0 && date.year % 100 != 00) || (date.year % 400 == 0) ? 1 : 0;
	return in;
}//overflow operator >> for date
// ####################################3

int main()
{/*
	Date date(10,10,1800,0,0,0);
	List<Date> list(date);
	for (int i = 0; i < 10; i++) {
		date.day =(i + 1)+11 ;
		date.month = (i + 1)+11;
		date.year = 1900 + (10 + (i * 10));
		list.add(date);
	}
	list.List_sort();
	list.coutall();*/
//	Date date1(28,9,2020);
//	Date date2;
//	Duration dur(date1, date2);
//	cout << endl << date1.day_of_week() << endl;
//	cout << endl<< date1.week_of_month() <<endl;
//	cout << endl << date1.week_of_year() << endl;
//	cout << endl << Date::statistics(28, 2020) << endl;
	
//	Date date2;
//	Duration dur(date1, date2);
	
/*	Date date1;
	Date date2;
	cin >> date1;
	cout <<"DATE 1: "<< date1<<endl;
	if (date1.isRight() == 0) cout << "ERROR\n";
	else cout << "NICE\n";
	
	cin >> date2;
	cout << "DATE 2: " << date2 << endl;
	if (date2.isRight() == 0) cout << "ERROR\n";
	else cout << "NICE\n";
	cout << date1.day_of_week()<<endl;*/
//	cout <<endl<<Date::statistics(28, 2020)<< endl;
    return 0;
}