#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h> //

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8); //
    //setlocale(LC_ALL, "rus");
    int n;

    ifstream input;
    input.open("input.txt");

    input >> n; //размер массива

    int **array = new int* [n];
    for (int i = 0; i < n; ++i)
        array[i] = new int [n];

    for (int i = 0; i < n; ++i) //ввод массива
        for (int j = 0; j < n; ++j)
            input >> array[i][j];

    BucketSort(array); //задание 4
    CombSort(array); //задание 9
    SelectionSort(array); //задание 14
    return 0;
}