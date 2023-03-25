#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, temp, max, max_pos, index, rang, result;
    vector<int> arr, rangs;
    bool flag = false;
    //Ввод данных
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    //Поиск максимальноо результата
    max = arr.front();
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr.at(i) > max) {
            max = arr.at(i);
            max_pos = i;
        }
    }
    //Поиск результата по условию
    index = 0;
    for (int i = max_pos+1; i < arr.size() - 1; i++)
    {
        if ((arr.at(i) % 10 != 0) && (arr.at(i) % 5 == 0) && (arr.at(i) > arr.at(i + 1)))
        {
            if (!flag)
            {
                index = i;
                flag = true;
            }
            else
            {
                if (arr.at(i) > arr.at(index))
                    index = i;
            }
        }    
    }
    //Вывод если значение не найдено
    if (!flag)
    {
        cout << "0";
        return 0;
    }

    rang = 1;
    result = arr.at(index);

    //Поиск места
    for (int i = 0; i < arr.size(); i++) {
        if (arr.at(i) > result) {
            rang++;
        }
    }
    //Вывод результата
    cout << rang;

    return 0;
}
