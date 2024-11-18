#include "functions.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream> // For file handling
#include <tuple>   // For storing performance data
#include <iomanip>  //using this to format the output in a readable format
using namespace std;

// Function to generate random numbers
void fillArray(vector<int>& arr, int size) {
    arr.clear();
    for (int i = 0; i < size; ++i) {
        arr.push_back(rand() % 100000); // Random values between 0 and 99999
    }
}

// Quick Sort Implementation
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge Sort Implementation
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Performance Data Collection
void collectPerformanceData() {
    std::vector<int> sizes = { 100, 1000, 10000, 100000 };
    std::vector<std::tuple<int, double, double>> performanceData;

    std::cout << "Size\tQuick Sort\tMerge Sort\t\n";

    for (int size : sizes) {
        std::vector<int> arr;

        // Generate random data
        fillArray(arr, size);

        // Measure Quick Sort
        auto quickArr = arr;
        auto start = std::chrono::high_resolution_clock::now();
        quickSort(quickArr, 0, quickArr.size() - 1);
        auto end = std::chrono::high_resolution_clock::now();
        double quickTime = std::chrono::duration<double, std::milli>(end - start).count();

        // Measure Merge Sort
        auto mergeArr = arr;
        start = std::chrono::high_resolution_clock::now();
        mergeSort(mergeArr, 0, mergeArr.size() - 1);
        end = std::chrono::high_resolution_clock::now();
        double mergeTime = std::chrono::duration<double, std::milli>(end - start).count();

        std::cout << size << "\t" << quickTime << " ms\t" << mergeTime << " ms\t \n";

        // Save data to vector
        performanceData.emplace_back(size, quickTime, mergeTime);
    }

    // Write to CSV file
    writeToCSV("performance_data.csv", performanceData);
}

// Print array elements
void printArray(const std::vector<int>& arr) {
    if (arr.empty()) {
        std::cout << "Array is empty.\n";
        return;
    }

    std::cout << "Array elements: ";
    for (const auto& val : arr) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

// Write performance data to a CSV file
void writeToCSV(const std::string& filename, const std::vector<std::tuple<int, double, double>>& data) {
    std::ofstream file(filename);

    if (!file) {
        std::cerr << "Error: Could not open file for writing.\n";
        return;
    }

    // Write CSV header
    file << "Size,Quick Sort,Merge Sort\n";

    // Write data rows
    for (const auto& row : data) {
        int size;
        double quickTime, mergeTime;
        std::tie(size, quickTime, mergeTime) = row;
        file << size << "," << quickTime << "," << mergeTime << "\n";
    }

    file.close();
    std::cout << "Performance data saved to " << filename << "\n";
}


// Display menu options
void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Fill array with random values\n";
    cout << "2. Collect performance data\n";
    cout << "3. Print Array\n";
    cout << "4. Exit\n";
}
