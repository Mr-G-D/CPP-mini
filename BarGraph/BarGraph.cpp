// BarGraph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<windows.h>
#include<vector>
#include <map>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
int main()
{
    cout << "Enter the values\n";

    int num;
    vector<int> arr;
    map<int, int> histogram;
    map<int, int>::iterator i;
    int max = 0;
    float curr;

    while (cin >> num) {
        if (num > 20 || num < 0) {
            SetConsoleTextAttribute(h, 4);
            cout << "The Value must be between 0 and 20";
        }
        else {
            arr.push_back(num);
        }
        
    }

    for (int x : arr) {
        i = histogram.find(x);
        if (i == histogram.end()) {
            histogram.insert(pair<int, int>(x, 1));
            //cout << x << ":" << histogram[x] << endl;
        }
        else {
            histogram[x] += 1;
            if (histogram[x] > max) {
                max = histogram[x];
            }
            //cout << x << ":" << histogram[x] << endl;
        }
    }

    //for (auto x : histogram) {
    //    cout << x.first << ":" << x.second << endl;
    //}

    for (int j = 0; j < 21; j++) {
        if (j < 10) {
            cout << 0;
        }
        cout << j << ":"<<"  ";
        i = histogram.find(j);
        if (i == histogram.end()) {
            cout << 0;
        }
        else {
            curr = (histogram[j] / (float)max) * 60;
            cout << curr << "  ";
            cout << string(curr, '*');
        }
        cout << endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
