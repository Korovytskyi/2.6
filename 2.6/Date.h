#pragma once
#include <string>
#include <sstream>
#include <iostream>



using namespace std;

class Date
{
public:
	class Triad
	{
	private:
		int year;
		int month;
		int day;
	public:
		void Init(int y, int m, int d);
		void SetYear(int value) { year = abs(value); }
		void SetMonth(int value) { month = abs(value); }
		void SetDay(int value) { day = abs(value); }
		void incYear() { ++year; }
		void incMonth() { ++month; }
		void incDay() { ++day; }
		int GetYear() const { return year; }
		int GetMonth() const { return month; }
		int GetDay() const { return day; }
		Triad();
		Triad(int, int, int);
		Triad(const Triad&);
		Triad& operator = (const Triad&);
		friend ostream& operator << (ostream&, const Triad&);
		friend istream& operator >> (istream&, Triad&);
		operator string() const;
		Triad& operator ++ ();
		Triad& operator -- ();
		Triad operator ++ (int);
		Triad operator -- (int);

	};
private:
	Triad date;
public:
	void Init(Triad value);

	void incYear();
	void incMonth();
	void incDay();
	void Display() const;
	void YearConverter();
	void MonthConverter();
	void DayConverter();
	void addDay();
	void SetYear(int value);
	void SetMonth(int value);
	void SetDay(int value);
	int GetYear() const { return date.GetYear(); }
	int GetMonth() const { return date.GetMonth(); }
	int GetDay() const { return date.GetDay(); }
	void Stabilizer();
	string toString() const;

};

