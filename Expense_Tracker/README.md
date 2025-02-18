# Expense Tracker

An efficient CLI-based Expense Tracker application to manage and keep track of your expenses.

## Features

- **Add Expense**: Add a new expense with a description and amount.
- **List Expenses**: Display all the expenses sorted by their ID.
- **Delete Expense**: Remove an expense using its ID.
- **Summarize Expenses**: Display the total of all expenses.
- **Export to CSV**: Export the list of expenses to a CSV file.
- **Help**: Display the list of available commands.

## Usage

### Add Expense
Add a new expense with a description and an amount.

```bash
add --description "<description>" --amount <amount>

Example:
add --description "Coffee" --amount 3.50
```


### List Expense
list

### Delete Expense

```bash
delete --id <id>

Example:
delete --id 2
```

### Summarize Expenses
summary

### Export to CSV

```bash
export <filename>

Example:
export expenses.csv
```

### Help
help

## Code Structure
 - **Expense_Tracker.cpp**: Contains the main logic and user interaction.

 - **expenses.h**: Defines the Expense structure.

 - **sort_utils.cpp**: Provides sorting functionality for the expenses.

 - **sort_utils.h**: Declares the sorting functions.
