#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <iostream>
#include <chrono>

// Function declarations
void fillArray(std::vector<int>& arr, int size);
void quickSort(std::vector<int>& arr, int low, int high);
void mergeSort(std::vector<int>& arr, int left, int right);
void collectPerformanceData();
void printArray(const std::vector<int>& arr);
void writeToCSV(const std::string& filename, const std::vector<std::tuple<int, double, double>>& data);
void displayMenu();

#endif // FUNCTIONS_H

