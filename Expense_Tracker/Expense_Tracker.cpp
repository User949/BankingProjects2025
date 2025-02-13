#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <ctime>
#include "expenses.h"
#include "sort_utils.h"

std::vector<Expense> expenses;
std::vector<int> availableIds;
int nextId = 1;

std::string getCurrentDate()
{
    std::time_t t = std::time(nullptr);
    std::tm now;
    localtime_s(&now, &t);
    char buffer[11];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &now);
    return std::string(buffer);
}

void addExpense(const std::string& description, double amount)
{
	int id;
	if (!availableIds.empty()) 
	{
		id = availableIds.back();
		availableIds.pop_back();
	}
	else 
		id = nextId++;
	std::string date = getCurrentDate();
	Expense expense(id, date, description, amount);
	expenses.push_back(expense);
	std::cout << "# Expense added successfully (ID: " << expense.id << ")\n";
}

void listExpenses()
{
	quickSort(expenses, 0, expenses.size() - 1);

	std::cout << "# ID  Date       Description  Amount\n";
	for (const auto& expense : expenses)
		std::cout << "# " << expense.id << "   " << expense.date << "  " << expense.description << std::setw(5) << "  $" << expense.amount << "\n";
}

void deleteExpense(int id)
{
	for (auto it = expenses.begin(); it != expenses.end(); ++it)
	{
		if (it->id == id)
		{
			expenses.erase(it);
			availableIds.push_back(id);
			std::cout << "# Expense deleted successfully\n";
			return;
		}
	}
	std::cout << "# Expense not found\n";
}

void summarizeExpenses()
{
	double total = 0;
	for (const auto& expense : expenses)
		total += expense.amount;
	std::cout << "Total expenses: $" << total << "\n";
}

void exportToCSV(const std::string& filename)
{
	std::ofstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "# Could not open the file for writing.\n";
		return;
	}
	file << "ID,Date,Description,Amount\n";
	for (const auto& expense : expenses)
		file << expense.id << ", " << expense.date << ", " << expense.description << ", " << expense.amount << "\n";
	
	file.close();
	std::cout << "# Expenses exported to " << filename << " successfully.\n\n";
}

int main() 
{
	std::string command;
	while (true) 
	{
		std::cout << "$ expense-tracker ";
		std::getline(std::cin, command);
		std::istringstream iss(command);
		std::string subcommand;
		iss >> subcommand;

		if (subcommand == "add") 
		{
			std::string option1, option2, description;
			double amount;
			iss >> option1 >> std::quoted(description) >> option2 >> amount;
			if (option1 == "--description" && option2 == "--amount")
			{
				addExpense(description, amount);
				std::cout << "\n";
			}
			else
				std::cout << "# Invalid options for add command\n\n";
		}
		else if (subcommand == "list") 
		{
			listExpenses();
			std::cout << "\n";
		}
		else if (subcommand == "delete") 
		{
			std::string option;
			int id;
			iss >> option >> id;
			if (option == "--id") 
			{
				deleteExpense(id);
				std::cout << "\n";
			}
			else
				std::cout << "# Invalid option for delete command\n\n";
		}
		else if (subcommand == "summary")
		{
			summarizeExpenses();
			std::cout << "\n";
		}
		else if (subcommand == "export")
		{
			std::string filename;
			iss >> filename;
			exportToCSV(filename);
		}
		else if (subcommand == "help")
		{
			std::cout << "Expense Tracker Commands:\n";
			std::cout << "  add --description \"<desc>\" --amount <amount>  : Add a new expense\n";
			std::cout << "  list                                            : List all expenses\n";
			std::cout << "  delete --id <id>                                : Delete an expense by ID\n";
			std::cout << "  summary                                         : Summarize total expenses\n";
			std::cout << "  export <filename>                               : Export expenses to a CSV file\n";
			std::cout << "  help						  : Show this help message\n\n";
		}
		else 
			std::cout << "# Unknown command\n\n";
	}
	return 0;
}
