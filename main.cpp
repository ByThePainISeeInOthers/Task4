#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <windows.h> //

using namespace std;

void BucketSort(int** array, int size) {
    ofstream output;
    output.open("output4.txt"); //открываем файл вывода

    int* row = new int[size];

    for (int rowCounter = 0; rowCounter < size; ++rowCounter) { //проход по строкам

        row = array[rowCounter];

        int k, Min = array[0][0], Max = array[0][0], bucketNumber;

        for (int i = 0; i < size; ++i) { //поиск минимального и максимального элемента строки
            if (row[i] < Min)
                Min = row[i];
            if (row[i] > Max)
                Max = row[i];
        }

        bucketNumber = round(sqrt(Max - Min)); //количество блоков
        k = (Max - Min) / bucketNumber + 1; //шаг

        vector<vector<int>> bucket(bucketNumber);

        for (int i = 0; i < size; ++i) {//распределение по блокам
            bucket[(row[i] - Min) / k].push_back(row[i]);
        }

        for (int i = 0; i < bucketNumber; ++i) { //сортировка блоков
            for (int j = 1; j < bucket[i].size(); ++j) {
                if (bucket[i][j - 1] < bucket[i][j]) {
                    swap(bucket[i][j - 1], bucket[i][j]);
                    if (j > 1)
                        j -= 2;
                }
            }
        }

        vector<int> result;

        for (int i = bucketNumber - 1; i >= 0; --i) { //формирование отсортированной строки
            if (bucket[i].size() != 0) {
                for (int j = 0; j < bucket[i].size(); ++j) {
                    result.push_back(bucket[i][j]);
                }
            }
        }

        for (int i = 0; i < size; ++i) //занос строки в основной массив
            array[rowCounter][i] = result[i];
    }

    for (int i = 0; i < size; ++i) { //вывод
        for (int j = 0; j < size; ++j)
            output << array[i][j] << ' ';
        output << endl;
    }
}

void CombSort(int** array, int size) {
    ofstream output;
    output.open("output9.txt"); //открываем файл вывода

    int step;

    int* column = new int[size];

    for (int columnCounter = 0; columnCounter < size; ++columnCounter) { //проход по столбцам
        step = size - 1;

        for (int i = 0; i < size; ++i) { //сохранение столбцов в отдельный массив
            column[i] = array[i][columnCounter];
        }

        while (step >= 1) { //сортировка
            for (int i = 0; i + step < size; ++i) {
                if (columnCounter % 3 == 2) { //по убыванию для каждого третьего столбца
                    if (column[i] < column[i + step]) {
                        swap(column[i], column[i + step]);
                    }
                }
                else {
                    if (column[i] > column[i + step]) { //по возрастанию для остальных
                        swap(column[i], column[i + step]);
                    }
                }
            }
            step /= 1.2473309; //изменение шага
        }

        for (int i = 0; i < size; ++i) { //возвращение значений в изначальный массив
             array[i][columnCounter] = column[i];
        }
    }
    for (int i = 0; i < size; ++i) { //вывод
        for (int j = 0; j < size; ++j)
            output << array[i][j] << ' ';
        output << endl;
    }
}

void SelectionSort(int** array, int size) {
    ofstream output;
    output.open("output14.txt"); //открываем файл вывода

    for (int k = 1; k < size - 1; ++k) { //проход по диагоналям
        vector<int> diagonal;

        for (int i = 0; i < size; ++i) { //формирование вектора диагонали
            if (k + i < size) {
                diagonal.push_back(array[i][k + i]);
            }
        }

        for (int i = 0; i < diagonal.size() - 1; ++i) { //сортировка
            int max_index = i;
            for (int j = i + 1; j < diagonal.size(); ++j) {
                if (diagonal[j] > diagonal[max_index]) {
                    max_index = j;
                }
            }
            if (max_index != i) {
                swap(diagonal[i], diagonal[max_index]);
            }
        }

        int t = 0;
        for (int i = 0; i < size; ++i) { //занесение диагоналей обратно в массив
            if (k - i < size) {
                array[i][k + i] = diagonal[t];
                ++t;
            }
        }

        //вторая часть

        diagonal.clear();

        for (int i = 0; i < size; ++i) { //формирование вектора диагонали
            if (k + i < size) {
                diagonal.push_back(array[k + i][i]);
            }
        }

        for (int i = 0; i < diagonal.size() - 1; ++i) { //сортировка
            int max_index = i;
            for (int j = i + 1; j < diagonal.size(); ++j) {
                if (diagonal[j] > diagonal[max_index]) {
                    max_index = j;
                }
            }
            if (max_index != i) {
                swap(diagonal[i], diagonal[max_index]);
            }
        }

        t = 0;
        for (int i = 0; i < size; ++i) { //занесение диагоналей обратно в массив
            if (k + i < size) {
                array[k + i][i] = diagonal[t];
                ++t;
            }
        }
    }

    for (int i = 0; i < size; ++i) { //вывод
        for (int j = 0; j < size; ++j)
            output << array[i][j] << ' ';
        output << endl;
    }
}

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

    //BucketSort(array, n); //задание 4
    //CombSort(array, n); //задание 9
    //SelectionSort(array, n); //задание 14
    return 0;
}