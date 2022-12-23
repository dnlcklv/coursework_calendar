#pragma once
#include <list>
#include <iostream>
#include "Date.h"
#include "Event.h"

using namespace std;

class Calendar
{
	Date currentDate;
	list <Event*> events;
public:
	void Run();
	void Print();
	void NextMonth();
	void PreviousMonth();
	void InputDate();
	void AddEvent();
	void ListEvents();
	void DeleteEvents();
	void ClearEvents();
	void Save();
	void Load();
};

