#pragma once
#include "Date.h"
class Event : public Date
{
	std::string description;
public:
	void setDescription();
	std::string getDescription();
	std::string toString();

};

