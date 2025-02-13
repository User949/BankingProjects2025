#pragma once
#ifndef EXPENSES_H
#define EXPENSES_H

#include <vector>
#include <string>

struct Expense
{
	int id;
	std::string date;
	std::string description;
	double amount;
	Expense(int id, const std::string& date, const std::string& description, double amount)
		: id(id), date(date), description(description), amount(amount) {
	}
};

#endif
