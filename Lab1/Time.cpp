#include "stdafx.h"
#include "Time.h"
#include "Date.h"


Time::Time(int h, int mn, int s)
{
	hour = h;
	minutes = mn;
	seconds = s;
//	bool isRight();
}
bool Time::isRight() {
	if (this->hour > 23 || this->hour < 0) return 0;
	if (this->minutes > 59 || this->minutes < 0) return 0;
	if (this->seconds > 59 || this->seconds < 0) return 0;
	return 1;
}