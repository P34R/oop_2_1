#include "stdafx.h"
#include "Time.h"
#include "Date.h"
#include "Duration.h"
#include <iostream>
#include <vector>
class Date;
Duration::Duration(Date date1, Date date2){
	day = 0;
	month = 0;
	year = 0;
	hour = 0;
	minutes = 0;
	seconds = 0;
	Duration_(date1, date2);
/*	Date get_date();
	int get_dur_day();
	int get_dur_seconds();*/
}
void Duration::Duration_(Date date1, Date date2) {
//	int LeapYear = (date1.year-date2.year)/4-(date1.year-date2.year)/100+(date1.year-date2.year)/400;
//	int LeapYear = 0;
//	if (date1.month <= 2) LeapYear = 1;
//	if (date2.isLeap == 1) LeapYear++;
/*	date1.day += 365 * date1.year;
	date1.year = 0;
	date2.day += 365 * date2.year;
	date2.year = 0;
	while (date1.month != 0) {
		date1.month--;
		if (date1.month == 0) {
			date1.day += 31;
		}
		else if (date1.month < 8 && date1.month != 0) {
			if (date1.month % 2 == 1) {
				date1.day += 31;
			}
			else if (date1.month == 1) date1.day += 28;
			else date1.day += 30;
		}
		else {
			if (date1.month % 2 == 0) {
				date1.day += 31;
			}
			else date1.day += 30;
		}
	}
	while (date2.month != 0) {
		date2.month--;
		if (date2.month == 0) {
			date2.day += 31;
		}
		else if (date2.month < 8 && date2.month != 0) {
			if (date2.month % 2 == 1) {
				date2.day += 31;
			}
			else if (date2.month == 1) date2.day += 28;
			else date2.day += 30;
		}
		else {
			if (date2.month % 2 == 0) {
				date2.day += 31;
			}
			else date2.day += 30;
		}
	}
	date1.time.seconds += (3600 * date1.time.hour) + (60 * date1.time.minutes);
	date1.time.hour = 0;
	date1.time.minutes = 0;
	date2.time.seconds += (3600 * date2.time.hour) + (60 * date2.time.minutes);
	date2.time.minutes = 0;
	date2.time.hour = 0;
	this->seconds = date1.time.seconds - date2.time.seconds;
	this->day = date1.day - date2.day;
	this->day += LeapYear;
	if (seconds >= 86400) {
		this->day++;
		this->seconds -= 86400;
	}*/
	std::vector<int> mas(12); mas = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int Leaps = 0;
	if (date1.month >= 2 && date1.day < 29) this->day++;
	this->day += date1.day-1;
	date1.day = 1;
	Leaps = date1.year - date2.year;
	Leaps = (Leaps) / 4 - Leaps / 100 + Leaps / 400 + 1;
	this->day += Leaps;
	this->day -= date1.day;
	date1.day = 1;
	int counter_s = 0;
	while (counter_s!=1){
	if (date1.month != date2.month) {
		this->day += mas[date2.month - 1] - date2.day + 1;
		date2.month++;
		date2.day = 1;
		if (date2.month > 12) {
			date2.year++;
			date2.month = 1;
		}
	}
	else counter_s = 1;
	}
	this->day += (date1.year - date2.year) * 365;
	date1.time.seconds += 3600 * date1.time.hour + 60 * date1.time.minutes;
	date2.time.seconds += 3600 * date2.time.hour + 60 * date2.time.minutes;
	this->seconds=date1.time.seconds - date2.time.seconds;
	if (this->seconds >= 86400) {
		this->seconds -= 86400;
		this->day++;
	}
	if (this->seconds < 0) {
		this->day--;
		this->seconds += 86400;
	}
}
Date Duration::get_date() {
	Date date(this->day, 0, 0,0,0,this->seconds);
//	date.day = this->day;
//	date.time.seconds = this->seconds;
	return date;
}
int Duration::get_dur_day() {
	return day;
}
int Duration::get_dur_seconds() {
	return seconds;
}