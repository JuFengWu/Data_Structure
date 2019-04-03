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

	std::vector<int> testArray2(testArray);
	
	Sort::MergeSort mergeSort;
	Sort::HeapSort heapSort;
	Sort::SortContext mysort(&mergeSort);
	std::cout << "original elements:\n";
	mysort.showArray(testArray);
	std::cout << "------------------------------\n";
	mysort.showArray(mysort.sort(testArray));
	std::cout << "------------------------------\n"<<"original elements:\n";
	mysort.showArray(testArray2);
	std::cout << "------------------------------\n";
	mysort.modifySortContext(&heapSort);
	mysort.showArray(mysort.sort(testArray));
	std::system("pause");



}