#include "day1.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


day1::day1()
{
    vector<int> inputArray; //day1, input array, all integers from the file
    vector<int> threeInputArray; //day2, sum of 3 integers
    int line;

    //getting input from the file to both vector arrays
    ifstream file("input.txt");
    if (file.is_open())
    {
        while (file >> line)
        {
            inputArray.push_back(line);
        }
        for (int i = 0; i < inputArray.size(); i++)
        {
            if (i >= 2)
            {
                threeInputArray.push_back(inputArray[i] + inputArray[i - 1] + inputArray[i - 2]);
            }
        }
    }
    file.close();

    cout << checkArray(inputArray) << endl;
    cout << checkArray(threeInputArray) << endl;
}

int day1::checkArray(std::vector<int> array)
{
    int counter = 0;
    for (int i = 0; i < array.size(); i++)
    {
        if (i > 0)
        {
            if (array[i] > array[i - 1]) counter++;
        }
    }
    return counter;
}
