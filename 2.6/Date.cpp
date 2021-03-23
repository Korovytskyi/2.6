#include "Date.h"
Date::Triad::Triad() { year = 0, month = 0, day = 0; }
Date::Triad::Triad(int year = 0, int month = 0, int day = 0)
{
	this->year = year;
	this->month = month;
	this->day = day;
}
Date::Triad::Triad(const Triad& a)
{
	year = a.GetYear();
	month = a.GetMonth();
	day = a.GetDay();

}
void Date::Init(Triad value)
{
	this->date = value;
	Stabilizer();
}
void Date::incYear()
{
	date.SetYear(date.GetYear() + 1);
	YearConverter();
}
void Date::incMonth()
{
	date.SetMonth(date.GetMonth() + 1);
	MonthConverter();
}
void Date::incDay()
{
	date.SetDay(date.GetDay() + 1);
	DayConverter();
}
void Date::Display() const
{
	cout << date.GetYear() + 1 << " Year " << date.GetMonth() + 1 << " Month " << date.GetDay() << " Day " << endl;
}
void Date::SetYear(int value)
{
	date.SetYear(date.GetYear() + value);
	YearConverter();
}
void Date::YearConverter()
{
	if (date.GetYear() >= 30)
		date.SetYear(date.GetYear() % 30);
}
void Date::SetMonth(int value)
{
	date.SetMonth(date.GetMonth() + value);
	MonthConverter();
}
void Date::MonthConverter()
{
	while (date.GetMonth() >= 12)
	{
		date.SetMonth(date.GetMonth() - 12);
		incYear();
	}
}
void Date::SetDay(int value)
{
	date.SetDay(date.GetDay() + value);
	DayConverter();
}
void Date::DayConverter()
{
	while (date.GetDay() >= 30)
	{
		date.SetDay(date.GetDay() - 30);
		incMonth();
	}
}

void Date::addDay()
{
	int value;
	cout << "Dodatu dniv "; cin >> value;
	date.SetDay(date.GetDay() + value);
	Stabilizer();
}
Date::Triad& Date::Triad::operator = (const Triad& a)
{
	year = a.year;
	month = a.month;
	day = a.day;
	return *this;
}
ostream& operator << (ostream& out, const Date::Triad& a)
{
	out << string(a);
	return out;
}
istream& operator >> (istream& in, Date::Triad& a)
{
	cout << " first = "; in >> a.year;
	cout << " second = "; in >> a.month;
	cout << " third = "; in >> a.day;
	cout << a.year << "      " << a.month << "       " << a.day << endl;
	return in;
}
Date::Triad::operator string() const
{
	stringstream ss;
	ss << " first: " << year << endl;
	ss << " second: " << month << endl;
	ss << " third: " << day - 1 << endl;
	return ss.str();
}
void Date::Triad::Init(int y, int m, int d)
{
	year = abs(y);
	month = abs(m);
	day = abs(d);
}
Date::Triad& Date::Triad::operator ++ ()
{
	year++;
	month++;
	day++;
	return *this;
}
Date::Triad& Date::Triad::operator -- ()
{
	year--;
	month--;
	day--;
	return *this;
}
Date::Triad Date::Triad::operator ++ (int)
{
	Triad t(*this);
	year++;
	month++;
	day++;
	return t;
}
Date::Triad Date::Triad::operator -- (int)
{
	Triad t(*this);
	year--;
	month--;
	day--;
	return t;
}

string Date::toString() const
{
	stringstream sout;
	sout << "number 1: " << date.GetYear() << ", number 2: " << date.GetMonth() << ", number 3: " << date.GetDay() << endl;
	return sout.str();
}
void Date::Stabilizer()
{
	DayConverter();
	MonthConverter();
	YearConverter();
}
