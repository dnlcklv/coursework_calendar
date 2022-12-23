#include <iostream>
#include <locale>
#include "Calendar.h"
int main()
{
	locale::global(locale(""));
	wcout.imbue(locale(".1251"));
	wcin.imbue(locale(".866"));
	setlocale(LC_ALL, "ru");
	Calendar mainCalendar;
	mainCalendar.Run();
	return 0;
}
