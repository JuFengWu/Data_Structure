#include<vector>
#include<iostream>
#include"Sort.h"



namespace Sort {

	void Sort::showArray(std::vector<int> array) 
	{
		for (unsigned int i = 0; i < array.size(); i++) 
		{
			std::cout << "number " << i << " is " << array[i] << std::endl;
		}
		
	}

#ifdef CPP17CODE
	std::tuple<std::vector<int>, std::vector<int>> MergeSort::splitVectorIntoHalf(std::vector<int> arr)
	{
		std::size_t const half_size = arr.size() / 2;
		std::vector<int> splitFirst(arr.begin(), arr.begin() + half_size);
		std::vector<int> splitSecond(arr.begin() + half_size, arr.end());

		return std::forward_as_tuple(splitFirst, splitSecond);
	}
	std::vector<int> MergeSort::dividedAndMerge(std::vector<int> array1, std::vector<int> array2)
	{
		std::vector<int> arrayFirst;
		std::vector<int> arraySecond;
		std::tuple<std::vector<int>, std::vector<int>> arrs;
		if (array1.size() != 1)
		{
			arrs = splitVectorIntoHalf(array1);
			arrayFirst = dividedAndMerge(std::get<0>(arrs), std::get<1>(arrs));
			arraySecond = array2;
		}
		else if (array2.size() != 1)
		{
			arrs = splitVectorIntoHalf(array2);
			arrayFirst = array1;
			arraySecond = dividedAndMerge(std::get<0>(arrs), std::get<1>(arrs));
		}
		else
		{
			arrayFirst = array1;
			arraySecond = array2;
		}
		return merge(arrayFirst, arraySecond);
	}
#else
	void MergeSort::splitVectorIntoHalf(std::vector<int> inputArr, std::vector<int> &splitFirst, std::vector<int> &splitSecond) {
	
		std::size_t const half_size = inputArr.size() / 2;
		std::vector<int> splitedFirst(inputArr.begin(), inputArr.begin() + half_size);
		std::vector<int> splitedSecond(inputArr.begin() + half_size, inputArr.end());
		splitFirst = splitedFirst;
		splitSecond = splitedSecond;
	}
	std::vector<int> MergeSort::sort(std::vector<int> array)
	{
		std::cout << "do heap sort" << std::endl;
		std::vector<int> newArray = array;

		std::vector<int> array1(array.begin(), array.begin() + array.size() / 2);
		std::vector<int> array2(array.begin() + array.size() / 2, array.end());

		return dividedAndMerge(array1, array2);
	}
	std::vector<int> MergeSort::dividedAndMerge(std::vector<int> array1, std::vector<int> array2)
	{
		std::vector<int> arrayFirst;
		std::vector<int> arraySecond;
		std::vector<int> firstDividedArray;
		std::vector<int> secondDividedArray;
		if (array1.size() != 1)
		{
			splitVectorIntoHalf(array1, firstDividedArray, secondDividedArray);
			arrayFirst = dividedAndMerge(firstDividedArray, secondDividedArray);
			arraySecond = array2;
		}
		else if (array2.size() != 1)
		{
			splitVectorIntoHalf(array2, firstDividedArray, secondDividedArray);
			arrayFirst = array1;
			arraySecond = dividedAndMerge(firstDividedArray, secondDividedArray);
		}
		else
		{
			arrayFirst = array1;
			arraySecond = array2;
		}
		return merge(arrayFirst, arraySecond);
	}
#endif // CPP17CODE	

	std::vector<int> MergeSort::merge(std::vector<int> array1, std::vector<int> array2)
	{
		int totalLength = array1.size() + array2.size();
		int array1Index = 0;
		int array2Index = 0;
		std::vector<int> newArray;
		for (int i = 0; i < totalLength; i++)
		{
			if (array1Index == array1.size()) 
			{
				newArray.push_back(array2[array2Index]);
				array2Index++;
			}
			else if(array2Index == array2.size())
			{
				newArray.push_back(array1[array1Index]);
				array1Index++;
			}
			else if (array1[array1Index] > array2[array2Index]) 
			{
				newArray.push_back(array2[array2Index]);
				array2Index++;
			}
			else
			{
				newArray.push_back(array1[array1Index]);
				array1Index++;
			}
		}
		return newArray;
	}
	void Sort::swap(int &d1, int &d2) {
		int temp = d1;
		d1 = d2;
		d2 = temp;
	}
	void HeapSort::modifyHeap(std::vector<int> &data, int root, int length) {
		int leftChild = root * 2 ;	    
		int rightChild = root * 2 + 1;    
		int maxNode = -1;
		if (leftChild < length && (data[leftChild] > data[root])){
			maxNode = leftChild;
		}	
		else {
			maxNode = root;
		}
		if (rightChild < length && (data[rightChild] > data[maxNode])){
			maxNode = rightChild;
		}	
		if (maxNode != root) {
			Sort::swap(data[maxNode], data[root]);
			modifyHeap(data, maxNode, length);
		}
	}

	void HeapSort::doMaxHeap(std::vector<int> &data) {
		int halfArraySize = data.size() / 2;
		for (int i = halfArraySize; i >= 0; i--) {
			modifyHeap(data, i, data.size());
		}
	}

	std::vector<int> HeapSort::sort(std::vector<int> array) {
		
		std::cout << "do heap sort" << std::endl;

		doMaxHeap(array);
		for (int i = array.size() - 1; i > 0; i--) {
			swap(array[0], array[i]);
			modifyHeap(array, 0, i);
		}
		
		return array;
	}
};