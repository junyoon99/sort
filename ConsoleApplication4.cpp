#include <iostream>

using Comparison = bool(*)(int, int);

bool Ascending(int x, int y) 
{
	return x > y;
}

bool Descending(int x, int y) 
{
	return x < y;
}


void sequentialSort(int numbers[], int count, Comparison f) 
{
	for (int i = 0; i < count-1; i++) 
	{
		for (int j = i+1; j < count; j++) 
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

for (int i = 0; i < count; i++) 
{
	for (int j = i+1; j < count; j++) 
	{
		if (numbers[i] > numbers[j]) 
		{
			i = j;
			break;
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

void Printarray(int input[], int count) 
{
	for (int i = 0; i < count; i++)
	{
		std::cout << input[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	const int SIZE_ARRAY{ 10 };
	int scores[SIZE_ARRAY]{ 20,10,40,30,70,90,80,60,50,100 };

	sequentialSort(scores, SIZE_ARRAY, Ascending);

	Printarray(scores, SIZE_ARRAY);
}