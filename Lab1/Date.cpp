#include "stdafx.h"
#include "Time.h"
#include "Date.h"
#include "Duration.h"
#include <vector>
#include <iostream>
class Date;
class Time;
Date::Date(int d , int m, int y, int h , int mn, int s)
{
	day = d;
	month = m;
	year = y;
	time.hour = h;
	time.minutes = mn;
	time.seconds = s;
	isLeap = (year % 4 == 0 && year % 100 != 00) || (year % 400 == 0) ? 1 : 0;
/*	day_of_week();
	void add_dur(Date date1);
	void minus_dur(Date date1);
	bool isRight();*/
}

int Date::day_of_week() {
	int dw = 0;
	Date monday;
	monday.day = 1;
	monday.month = 1;
	monday.year = 1900;
	Duration dur(*this, monday);
	dw = dur.get_dur_day() % 7;
	std::cout << std::endl << "Month " << this->month << " = " << dw << std::endl;
	return dw; // 0-monday 1-tuesday...
}
void Date::Leap() {
	this->isLeap = (this->year % 4 == 0 && this->year % 100 != 00) || (this->year % 400 == 0) ? 1 : 0;
}
void Date::add_dur(Date date1) {
	int month_counter = 0;
	int temp = 0;
	this->day += date1.day;
	this->time.seconds += date1.time.seconds;
	temp = this->time.seconds % 3600;
	this->time.hour += this->time.seconds / 3600;
	this->time.seconds = temp;
	temp = this->time.seconds % 60;
	this->time.minutes += this->time.seconds / 60;
	this->time.seconds = temp;
	temp = this->time.hour % 24;
	this->day += this->time.hour / 24;
	this->time.hour = temp;
	temp = 0;
	while (this->day > 365) {
		this->day -= 365;
		this->year++;
	}
	while (temp != 1) {

		if (this->month == 2) {
			if (this->day > 28)
				this->day -= 28;
			else temp = 1;
		}
		else if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12) {
			if (this->day > 31) this->day -= 31;
			else temp = 1;
		}
		else {
			if (this->day > 30) this->day -= 30;
			else temp = 1;

		}
		if (temp != 1)
			this->month++;
	}
	isLeap = (year % 4 == 0 && year % 100 != 00) || (year % 400 == 0) ? 1 : 0;
}
void Date::minus_dur(Date date1) {
	this->day -= date1.day;
	this->time.seconds -= date1.time.seconds;
	while (this->time.seconds < 0) {
		this->time.minutes--;
		this->time.seconds += 60;
	}
	while (this->time.minutes < 0) {
		this->time.hour--;
		this->time.minutes += 60;
	}
	while (this->time.hour < 0) {
		this->day--;
		this->time.hour += 60;
	}
	while (this->day <= 0) {
		this->month--;
		if (this->month <= 0) {
			year--;
			this->month += 12;
			isLeap = (year % 4 == 0 && year % 100 != 00) || (year % 400 == 0) ? 1 : 0;
		}
		if (this->month == 2) {
			if (this->isLeap == 1) this->day += 29;
			else this->day += 28;
		}
		else if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12) {
			if (this->day > 31) this->day -= 31;
		}
		else {
			if (this->day > 30) this->day -= 30;
		}

	}
	isLeap = (year % 4 == 0 && year % 100 != 00) || (year % 400 == 0) ? 1 : 0;
}
bool Date::isRight() {
	if (this->month > 12 || this->month < 1) return 0;
	if (this->day > 31 || this->day < 1) return 0;
	if (this->year < 0) return 0;
	if (this->month == 2 && this->isLeap == 1) {
		if (this->day > 29) {
			return 0;
		}
	}
	else if (this->month < 8) {
		if (this->month == 2) {
			if (this->day > 28) return 0;
		}
		else if (this->month % 2 == 0) {
			if (this->day > 30) return 0;
		}
	}
	else if (this->month >= 8) {
		if (this->month % 2 == 1) {
			if (this->day > 30) return 0;
		}
	}
	if (this->time.isRight() == 1) return 1;
	else return 0;
}
int Date::statistics(int Day, int Year) {
	std::vector<int>month_day(12,0);
	std::vector<int>day_stat(7, 0);
	for (int i = 0; i < month_day.size(); i++) {
		Date date1(Day, i + 1, Year);
		month_day[i]= date1.day_of_week();
		day_stat[month_day[i]]++;
	}
	int max = day_stat[0];
	for (int i = 0; i < day_stat.size(); i++) {
		if (max < day_stat[i]) max = day_stat[i];
		std::cout << day_stat[i] << " ";
	}
	return max;
}
int Date::week_of_year() {
	int dw = 0;
	Date monday;
	monday.day = 1;
	monday.month = 1;
	monday.year = 1900;
	Duration dur(*this, monday);
	dw = dur.get_dur_day() % 7;
	int month_temp = this->month - 1;
	int day_temp = 0;
	while (month_temp != 0) {
		if (month_temp == 2) {
			if (this->isLeap == 1) day_temp += 29;
			else day_temp += 28;
		}
		else if (month_temp == 1 || month_temp == 3 || month_temp == 5 || month_temp == 7 || month_temp == 8 || month_temp == 10 || month_temp == 12) {
			day_temp += 31;
		}
		else {
			day_temp += 30;
		}
		month_temp--;
	}
	return (this->day + (7 - dw)) / 7 + day_temp / 7 +1;
}
int Date::week_of_month() {
	int dw = 0;
	Date monday;
	monday.day = 1;
	monday.month = 1;
	monday.year = 1900;
	Duration dur(*this, monday);
	dw = dur.get_dur_day() % 7;
	return (this->day + (7 - dw)) / 7;
}