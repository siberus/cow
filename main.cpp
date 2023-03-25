#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, temp, max, max_pos, index, rang;
    vector<int> arr, rangs;
    bool flag = false;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    max = arr.front();
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr.at(i) > max) {
            max = arr.at(i);
            max_pos = i;
        }
    }
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
    rang = 1;
    if (!flag)
    {
        cout << "0";
        return 0;
    }
    temp = arr.front();
    for (int i = 0; i < arr.size(); i++) {
        if (arr.at(i) != temp) {
            rangs.push_back(temp);
            temp = arr.at(i);
        }
    }
    rangs.push_back(temp);

    for (int i = 0; i < rangs.size(); i++) {
        if (rangs.at(i) > rangs.at(index)) {
            rang++;
        }
    }

    cout << rang;

    return 0;
}
