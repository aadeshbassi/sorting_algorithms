// Sorting_algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> values)
{
	for (int& value : values)
	{
		cout << value << " ";
	}
	cout << endl;
}

void bubble_sort(vector<int> &values)
{
	for (int i = 0; i < values.size() - 1 ; i++)
	{
		for (int j = 0; j < values.size() - i - 1; j++)
		{
			if (values[j] > values[j+1])
			{
				swap(values[j], values[j+1]);
			}
		}
	}
	print(values);
}

void selection_sort(vector<int>& values)
{
	int min_index{};
	for (int i = 0; i < values.size() - 1; i++)
	{
		min_index = i;
		for (int j = i+1; j < values.size() - 1; j++)
		{
			if (values[j] < values[min_index])
			{
				min_index = j;
			}
		}
		if(min_index!=i) swap(values[min_index], values[i]);

	}
	print(values);
}

void insertion_sort(vector<int>& values)
{
	int min_index{};
	for (int i = 0; i < values.size(); i++)
	{
		min_index = i-1;
		int key = values[i];
		while (min_index >= 0 && values[min_index] > key)
		{
			values[min_index + 1] = values[min_index];
			min_index--;
		}
		values[min_index + 1] = key;
	}
	print(values);
}

void merge(vector<int> &values, int low, int mid, int high)
{
	int array_left_size = mid - low + 1;
	int array_right_size = high - mid;
	vector<int> arr_left(array_left_size, 0);
	vector<int> arr_right(array_right_size, 0);

	for (int i = 0; i < array_left_size; i++)
	{
		arr_left[i] = values[low + i];
	}
	for (int i = 0; i < array_right_size; i++)
	{
		arr_right[i] = values[mid + 1 + i];
	}


	int index_left = 0;
	int index_right = 0;
	int index_sol = low;
	while (index_left < array_left_size && index_right < array_right_size)
	{
		if(arr_left[index_left] > arr_right[index_right])
		{
			values[index_sol] = arr_right[index_right];
			index_right++;
		}
		else
		{
			values[index_sol] = arr_left[index_left];
			index_left++;
		}
		index_sol++;
	}

	while (index_left < array_left_size)
	{
		values[index_sol] = arr_left[index_left];
		index_left++;
		index_sol++;
	}

	while (index_right < array_right_size)
	{
		values[index_sol] = arr_right[index_right];
		index_right++;
		index_sol++;
	}

}

void merge_sort(vector<int> &values, int low, int high)
{
	if (low >= high)
	{
		return;
	}
	int mid = low + (high - low)/2;
	merge_sort(values, low, mid);
	merge_sort(values, mid + 1, high);
	merge(values, low, mid,high);
}

int partition(vector<int>& values, int low, int high)
{
	int pivot = values[low];
	int count{};
	for (int i = low + 1 ; i <= high; i++)
	{
		if (values[i] <= pivot) count++;
	}
	int pivot_index =low + count;
	swap(values[low], values[pivot_index]);

	int index_start = low;
	int index_end = high;
	while ( index_start < pivot_index && index_end > pivot_index)
	{
		while (values[index_start] <= pivot) index_start++;
		while (values[index_end] > pivot) index_end--;
		if (index_start < pivot_index && index_end > pivot_index) swap(values[index_start++], values[index_end--]);
	}

	return pivot_index;
}

void quick_sort(vector<int>& values, int low, int high)
{
	if (low >= high)
	{
		return;
	}
	int partition_value = partition(values,low,high);
	quick_sort(values, low, partition_value-1);
	quick_sort(values, partition_value + 1, high);
	
}

int main()
{
	vector <int> values{2,3,4,19,1,2,5,81,10,12,5,7,9,0,22,11,17};
	//bubble_sort(values);
	//selection_sort(values);
	//insertion_sort(values);
	//merge_sort(values,0,values.size()-1);
	print(values);
	quick_sort(values, 0, values.size() - 1);
	print(values);

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
