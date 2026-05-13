#include <iostream>
#include <algorithm>

float* filterGreaterAverage(float* arr, int n, int& newSize) {
    float sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    float average = sum / n;
    newSize = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > average) {
            ++newSize;
        }
    }
    float* result = new float[newSize];
    int index = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > average) {
            result[index++] = arr[i];
        }
    }
    std::sort(result, result + newSize);
    return result;
}