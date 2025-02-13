#pragma once
#ifndef SORT_UTILS_H
#define SORT_UTILS_H

#include <vector>
#include "expenses.h"

int partition(std::vector<Expense>& arr, int low, int high);
void quickSort(std::vector<Expense>& arr, int low, int high);

#endif
