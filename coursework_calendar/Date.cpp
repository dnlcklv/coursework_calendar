#include "Date.h"
#include <time.h>
#include <string>
#include <sstream>
#pragma warning(disable : 4996)

Date::Date()
{
	time_t t = time(0);

	struct tm* now = localtime(&t);

	year = now->tm_year + 1900;
	month = now->tm_mon + 1;
	day = now->tm_mday;
}

void Date::IncreaseMonth()
{
	if (month < 12)
	{
		month++;
	}
	else
	{
		month = 1;
		year++;
	}
}

void Date::DecreaseMonth()
{
	if (month > 1)
	{
		month--;
	}
	else
	{
		month = 12;
		year--;
	}
}

std::string Date::ToString()
{
	std::stringstream ss;
	ss << day << "." << month << "." << year;
	return ss.str();
}

int Date::getDay()
{
	return day;
}

void Date::setDate(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

int Date::getYear()
{
	return year;
}

int Date::getMonth()
{
	return month;
}