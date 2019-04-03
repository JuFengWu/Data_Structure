#include<vector>
#include<iostream>
#include"Sort.h"



namespace Sort {

	void SortContext::showArray(std::vector<int> array){
		for (unsigned int i = 0; i < array.size(); i++) 
		{
			std::cout << "number " << i << " is " << array[i] << std::endl;
		}
	}
	std::vector<int> SortContext::sort(std::vector<int> arr) {
		_strategy->sortWay(arr);
		return arr;
	}
	void SortContext::modifySortContext(StrategySortInterface *strategy) {
		_strategy = strategy;
	}
	void MergeSort::sortWay(std::vector<int> &arr)
	{
		std::cout << "do merge sort" << std::endl;
		dividedAndMerge(arr, 0,arr.size()-1);
	}
	void MergeSort::dividedAndMerge(std::vector<int> &arr, int front, int end) {
		if (front < end) {
			int mid = (front + end) / 2;
			dividedAndMerge(arr, front, mid);
			dividedAndMerge(arr, mid + 1, end);
			merge(arr, front, mid, end);
		}
	}
	void MergeSort::merge(std::vector<int> &arr, int front, int middle, int end) {
		std::vector<int> leftArr(arr.begin() + front, arr.begin() + middle+1);		
		std::vector<int> rightArr(arr.begin() + middle+1, arr.begin()+ end+1);
		int array1Index = 0;
		int array2Index = 0;
		for (int i = front; i < end+1; i++) {
			if (array1Index == (middle-front+1)) {
				arr[i] = rightArr[array2Index];
				array2Index++;
			}
			else if(array2Index == (end -middle)){
				arr[i] = leftArr[array1Index];
				array1Index++;
			}
			else if(leftArr[array1Index]> rightArr[array2Index]){
				arr[i] = rightArr[array2Index];
				array2Index++;
			}
			else{
				arr[i] = leftArr[array1Index];
				array1Index++;
			}
		}
	}
	
	void HeapSort::modifyHeap(std::vector<int> &data, int root, int length) {
		int leftChild = root * 2+1 ;	    
		int rightChild = root * 2 + 2;    
		int maxNode = root;
		if (leftChild < length && (data[leftChild] > data[root])){
			maxNode = leftChild;
		}	
		if (rightChild < length && (data[rightChild] > data[maxNode])){
			maxNode = rightChild;
		}	
		if (maxNode != root) {
			std::swap(data[maxNode], data[root]);
			modifyHeap(data, maxNode, length);
		}
	}

	void HeapSort::doMaxHeap(std::vector<int> &data) {
		int halfArraySize = data.size() / 2;
		for (int i = halfArraySize; i >= 0; i--) {
			modifyHeap(data, i, data.size());
		}
	}

	void HeapSort::sortWay(std::vector<int> &arr) {
		
		std::cout << "do heap sort" << std::endl;

		doMaxHeap(arr);
		for (int i = arr.size() - 1; i > 0; i--) {
			std::swap(arr[0], arr[i]);
			modifyHeap(arr, 0, i);
		}
	}
};