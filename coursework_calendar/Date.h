#pragma once
#include <iostream>
class Date
{
protected:
	int year;
	int month;
	int day;
public:
	Date();
	void setDate(int day, int month, int year);
	int getYear();
	int getMonth();
	int getDay();

	std::string ToString();

	void IncreaseMonth();
	void DecreaseMonth();
	const std::string DayNames[7] = {
	"��",
	"��",
	"��",
	"��",
	"��",
	"��",
	"��"
	};
	const std::string MonthNames[12] = {
	"������",
	"�������",
	"����",
	"������",
	"���",
	"����",
	"����",
	"������",
	"��������",
	"�������",
	"������",
	"�������"
	};
	const int MonthDays[12] = {
	31, 28, 31, 30, 31, 30,
	31, 31, 30, 31, 30, 31,
	};
};

