#include "Event.h"
#include <sstream>
#pragma warning(disable : 4996)

Event::Event(int day, int month, int year, std::string desc)
{
	this->day = day;
	this->month = month;
	this->year = year;
	this->description = desc;
}

std::string Event::getDescription()
{
	return description;
}

std::string Event::toString()
{
	std::stringstream ss;
	ss << day << "." << month << "." << year;
	return (ss.str() + " Название:" + description);
}
