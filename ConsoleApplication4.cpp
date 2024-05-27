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

//for (int i = 0; i < count; i++) 
//{
//	for (int j = i+1; j < count; j++) 
//	{
//		if (numbers[i] > numbers[j]) 
//		{
//			i = j;
//			break;
//		}
//	}
//}

void selectionSort(int numbers[], int count)
{
	for (int i = 0; i < count; i++)
	{
		int minIndex = i;
		for (int j = i; i < count; j++)
		{
			if (numbers[minIndex] > numbers[j]) 
			{
				minIndex = j;
			}
		}
	}
}

void BubbleSort(int numbers[], int count) 
{
	for (int phase = 0; phase < count - 1; phase++) 
	{
		for (int k{}; k < count - 1 - phase; ++k) 
		{
			if (numbers[k] > numbers[k + 1]) 
			{
				int temp = numbers[k];
				numbers[k] = numbers[k + 1];
				numbers[k + 1] = temp;
			}
		}
	}
}

void InsertionSort(int numbers[], int count) 
{
	for (int i = 1; i < count; i++) 
	{	
		int j = i;
		int target = numbers[i];
		while (--j >= 0 && target < numbers[j]) 
		{
			numbers[j+1] = numbers[j];
			numbers[j] = target;
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

//----------------------

void merge(int numbers[], int start, int half, int end, int temp[]) 
{
	int i = start;
	int j = half + 1;
	int tempIndex{};

	while (i <= half && j <= end)
	{
		if (numbers[i] < numbers[j])
		{
			temp[tempIndex++] = numbers[i++];
		}
		else
		{
			temp[tempIndex++] = numbers[j++];
		}
	}

	while (i <= half)
	{
		temp[tempIndex++] = numbers[i++];
	}
	while (j <= end) 
	{
		temp[tempIndex++] = numbers[j++];
	}

	tempIndex = 0;
	for (int i = start; i <= end; i++) 
	{
		numbers[i] = temp[tempIndex++];
	}

}
void mergeSort(int numbers[], int start, int end, int temp[])
{
	if (start >= end) return;

	int half = (start + end) / 2;

	mergeSort(numbers, start, half, temp);
	mergeSort(numbers, half + 1, end, temp);

	merge(numbers, start, half, end, temp);
}

//Quick Sort
void QuickSort(int numbers[], int start, int end) 
{
	int i = start;
	int j = end;
	int pivot = numbers[(start + end) / 2];

	do 
	{
		while (numbers[i] < pivot)
		{
			i++;
		}
		while (numbers[j] > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			int temp = numbers[i];
			numbers[i] = numbers[j];
			numbers[j] = temp;

			i++;
			j++;
		}
	} while (i <= j);

	if (start < j) 
	{
		QuickSort(numbers, start, j);
	}
	if (i < end) 
	{
		QuickSort(numbers, i, end);
	}
}


int main()
{
	const int SIZE_ARRAY{ 10 };
	int scores[SIZE_ARRAY]{ 20,10,40,30,70,90,80,60,50,100 };

	//sequentialSort(scores, SIZE_ARRAY, Ascending);

	//selectionSort(scores, SIZE_ARRAY);
	

	int temp[SIZE_ARRAY];
	mergeSort(scores, 0, SIZE_ARRAY-1, temp);

	//QuickSort(scores, 0, SIZE_ARRAY - 1);
	Printarray(scores, SIZE_ARRAY);
}