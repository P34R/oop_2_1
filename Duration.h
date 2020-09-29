#pragma once
class Date;
class Duration{
public:
	int day=0;
	int month=0;
	int year = 0;
	int hour=0;
	int minutes=0;
	int seconds=0;
	Duration(Date date1, Date date2);
	void Duration_(Date date1, Date date2);
	Date get_date();
	int get_dur_day();
	int get_dur_seconds();


};
