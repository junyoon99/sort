#include <iostream>
#include <chrono>

using Comparison = bool(*)(int, int);

bool Ascending(int x, int y) 
{
    return x > y;
}

bool Descending(int x, int y) 
{
    return x < y;
}


void Sort(int numbers[], int count, Comparison f) 
{
    for (int i = 0; i < count; i++) 
    {
        for (int j = 0; j < count; j++) 
        {
            if (f(numbers[i], numbers[j])) 
            {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
}

int add(int x, int y) 
{
    return x + y;
}

int Sum(int numbers[], int count) 
{
    int total{};
    for (int i = 0; i < count; i++) 
    {
        total += numbers[i];
    }
    return total;
}

int main()
{
    const int SIZE_ARRAY{ 10 };
    int scores[SIZE_ARRAY]{ 20,10,40,30,70,90,80,60,50,100 };

    auto startTime = std::chrono::system_clock::now();
    Sort(scores, SIZE_ARRAY, Ascending);
    auto endTime = std::chrono::system_clock::now();

    auto duration = endTime - startTime;

    std::cout << "Sort() - " << duration.count() << "ms" << std::endl;

    for (int i = 0; i < SIZE_ARRAY; i++) 
    {
        std::cout << scores[i] << std::endl;
    }
}