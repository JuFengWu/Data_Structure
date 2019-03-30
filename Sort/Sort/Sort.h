#pragma once
#include<vector>
//#define CPP17CODE



namespace Sort{
	class Sort
	{
	public:
		void showArray(std::vector<int> array);
		virtual std::vector<int> sort(std::vector<int> array) = 0;
		void static swap(int &d1, int &d2);

	};

	class MergeSort :public Sort
	{
	public:
		std::vector<int> sort(std::vector<int> array) override;
	private:
		std::vector<int> dividedAndMerge(std::vector<int> array1, std::vector<int> array2);
		std::vector<int> merge(std::vector<int> array1, std::vector<int> array2);
#ifdef CPP17CODE
		std::tuple<std::vector<int>, std::vector<int>> splitVectorIntoHalf(std::vector<int> arr);
#else
		void splitVectorIntoHalf(std::vector<int> inputArr, std::vector<int> &splitFirst, std::vector<int> &splitSecond);
#endif // CPP17CODE
	};

	class HeapSort : public Sort {
	public:
		std::vector<int> sort(std::vector<int> array) override;
	private:
		void doMaxHeap(std::vector<int> &array);
		void modifyHeap(std::vector<int> &data, int root, int length);
	};
};