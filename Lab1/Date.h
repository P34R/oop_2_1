#pragma once
class Time;
class Date
{
public:
	Date(int d = 1, int m = 1, int y = 1900, int h = 0, int mn = 0, int s = 0);
	int day = 0;
	int month = 0;
	int year = 0;
	class Time time;
	bool isLeap = (year % 4 == 0 && year % 100 != 00) || (year % 400 == 0) ? 1 : 0;
	Date& operator= (const Date &date)
	{
		day = date.day;
		month = date.month;
		year = date.year;
		time.hour = date.time.hour;
		time.minutes = date.time.minutes;
		time.seconds = date.time.seconds;

		return *this;
	}
	bool isRight();
	void minus_dur(Date date1);
	void add_dur(Date date1);
	int day_of_week();
	int week_of_year();
	int week_of_month();
	void Leap();
	static int statistics(int Day, int Year);
};

