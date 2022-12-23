#include "Calendar.h"
#include <string>
#include <ostream>
#include <istream>
#include <fstream>
#include <iomanip>
#include <vector>

void Calendar::Run()
{
	bool run = true;

	while (run)
	{
        char command;
        std::cout
            << "\nN: ��������� �����" << "\t\tP: ���������� �����" << "\t\tI: �������� ��������� �� ����"
            << "\nA: �������� �������" << "\t\tL: �������� �������" << "\t\tD: ������� �������" 
            << "\nS: ��������� ������� � ����" << "\tR: ������� ��� �������" << "\t\tQ: �����" 
            << "\n������� �������: ";
        std::cin >> command;
        if (command >= 'a' && command <= 'z')
            command += ('A' - 'a');

        switch (command) {
        case 'N':
            NextMonth();
            Print();
            break;
        case 'P':
            PreviousMonth();
            Print();
            break;
        case 'I':
            InputDate();
            Print();
            break;
        case 'A':
            AddEvent();
            break;
        case 'L':
            ListEvents();
            break;
        case 'D':
            DeleteEvents();
            break;
        case 'S':
            Save();
            break;
        case 'R':
            ClearEvents();
            break;
        case 'Q':
            run = false;
            break;
        default:
            std::cout << "����� ������� ���." << std::endl;
            break;
        }
	}
}

void Calendar::Print()
{
    int year = currentDate.getYear();
    int month = currentDate.getMonth();

    cout << "    " << currentDate.MonthNames[month - 1];
    cout << "    " << year << endl;

    cout << "**************************" << endl;

    for (int i = 0; i < 7; i++) {
        cout << currentDate.DayNames[i] << "  ";
    }
    cout << endl;

    if (month < 3)
    {
        year -= 1;
    }

    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    int d = 1;

    if (month == 2) {
        d = 0;
    }

    int startingDay = ((year + year / 4 - year / 100 + year / 400 + t[month - 1] + d) % 7);
    int dayCount = currentDate.MonthDays[month - 1];

    for (int x = 0; x < startingDay; x++) {
        cout << "    ";
    }

    for (int d = 0; d < dayCount; d++) {
        if (d < 9)

            cout << "0" << d + 1 << "  ";
        else
            cout << d + 1 << "  ";
        ++startingDay;
        if (startingDay == 7) {
            startingDay = 0;
            cout << endl;
        }
    }

    cout << endl;
}

void Calendar::NextMonth()
{
    currentDate.IncreaseMonth();
}

void Calendar::PreviousMonth()
{
    currentDate.DecreaseMonth();
}

void Calendar::InputDate()
{
	int year, month, day;
	std::cout << "Input date:\n";
	do
	{
		std::cout << "Day: ";
		std::cin >> day;
	} while (day <= 1 || day > 31);

	do
	{
		std::cout << "Month: ";
		std::cin >> month;
	} while (month <= 1 || month > 12);

	do
	{
		std::cout << "Year: ";
		std::cin >> year;
	} while (year < 0);

	currentDate.setDate(day, month, year);
}

void Calendar::AddEvent()
{

    int year, month, day;
    cout << "������� ����\n";
    do
    {
        cout << "����: ";
        cin >> day;
    } while (day < 0 || day > 31);

    do 
    {
        cout << "�����: ";
        cin >> month;
    } while (month < 0 || month > 12);

    do
    {
        cout << "���: ";
        cin >> year;
    } while (year < 0);
    

    string desc;
    cout << "������� �������� ������� �� ���������� �����(������ ������� ������� ������ �������������, �������� Day_of_Russia ):"; //����� ���� ������ �������� �������, ���� ������ ����� ���������
    cin >> desc;

    events.push_back(new Event(day,month,year,desc));
    cout << "������� ���������";
}

void Calendar::ListEvents()
{
    if (events.size() != 0)
    {
        for (auto it = events.begin(); it != events.end(); it++)
        {
            cout << (*it)->toString() << endl;
        }
    }
    else cout << "��� �������.";
}

void Calendar::DeleteEvents()
{
    if (events.size() != 0)
    {
        bool select = false;
        list <Event*>::iterator buf;
        string eventName;
        cout << "������� �������� �������, ������� ������ �������: ";
        cin >> eventName;

        for (auto it = events.begin(); it != events.end(); it++)
        {
            if (eventName == (*it)->getDescription())
            {
                select = true;
                buf = it;
            }
        }
        if (select)
        {
            events.erase(buf);
            cout << "������� " << (*buf)->getDescription() << " �������";
        }
        else cout << "������ ������� ���";
    }
    else cout << "C������ �������� ������� :)";
}

void Calendar::ClearEvents()
{
    if (events.size() != 0)
    {
        events.clear();
    }
    cout << "������� ������� �������.";
}

void Calendar::Save()
{
    std::ofstream fileEvent("event.txt");
    if (fileEvent.is_open())
    {
        for (auto it = events.begin(); it != events.end(); it++)
        {
            fileEvent << (*it)->getDay() << "." << (*it)->getMonth() << "." << (*it)->getYear() << " ��������: " << (*it)->getDescription() << endl;
        }
        cout << "�������� ���������.";
    }
    else cout << "������ �������� �����.";
}
