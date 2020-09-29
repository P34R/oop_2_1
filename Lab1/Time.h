#pragma once
class Time {
public:
	Time(int h = 0, int mn = 0, int s = 0);
	int hour = 0;
	int minutes = 0;
	int seconds = 0;
	bool isRight();
};