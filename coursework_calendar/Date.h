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
	"Пн",
	"Вт",
	"Ср",
	"Чт",
	"Пт",
	"Сб",
	"Вс"
	};
	const std::string MonthNames[12] = {
	"Январь",
	"Февраль",
	"Март",
	"Апрель",
	"Май",
	"Июнь",
	"Июль",
	"Август",
	"Сентябрь",
	"Октябрь",
	"Ноябрь",
	"Декабрь"
	};
	const int MonthDays[12] = {
	31, 28, 31, 30, 31, 30,
	31, 31, 30, 31, 30, 31,
	};
};

