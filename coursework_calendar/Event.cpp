#include "Event.h"
#include <sstream>
#pragma warning(disable : 4996)

void Event::setDescription()
{
	std::cin >> description;
}

std::string Event::getDescription()
{
	return description;
}

std::string Event::toString()
{
	std::stringstream ss;
	ss << day << "." << month << "." << year;
	return (ss.str() + description);
}
