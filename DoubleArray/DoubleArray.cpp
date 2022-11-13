// DoubleArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    cout << "Enter the value..." << endl;

    int n;
    cin >> n;

    double arr[n]{};

    for (int i = 1; i < n; i++) {
        arr[i] = (1 / (float)i);
    }

    double sum = 0;
    for (auto x : arr) {
        sum += x;
    }

    cout << "The sum is " << sum;

}
