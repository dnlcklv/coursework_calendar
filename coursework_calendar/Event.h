#pragma once
#include "Date.h"
class Event : public Date
{
	std::string description;
public:
	Event();
	Event(int day, int month, int year, std::string desc);
	std::string getDescription();
	std::string toString();

};

