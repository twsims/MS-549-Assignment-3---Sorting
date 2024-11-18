#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <iostream>
#include <chrono>
using namespace std; 

// Function declarations
void fillArray(vector<int>& arr, int size);
void quickSort(vector<int>& arr, int low, int high);
void mergeSort(vector<int>& arr, int left, int right);
void collectPerformanceData();
void printArray(const vector<int>& arr);
void writeToCSV(const string& filename, const vector<tuple<int, double, double>>& data);
void displayMenu();

#endif // FUNCTIONS_H

