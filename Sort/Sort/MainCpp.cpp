#include<iostream>
#include<vector>
#include"Sort.h"
 

int Add(int a, int b) {
	return a + b;
}

int main()
{
	std::vector<int> testArray;

	testArray.push_back(1);
	testArray.push_back(10);
	testArray.push_back(8);
	testArray.push_back(5);
	testArray.push_back(7);
	testArray.push_back(9);
	testArray.push_back(14);

	Sort::Sort* mysort;
	Sort::MergeSort mergeSort;
	Sort::HeapSort heapSort;
	mysort = &heapSort;
	mysort->showArray(mysort->sort(testArray));
	mysort = &mergeSort;
	mysort->showArray(mysort->sort(testArray));
	std::system("pause");



}