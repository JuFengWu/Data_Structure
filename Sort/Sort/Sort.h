#pragma once
#include<vector>


namespace Sort{
	class StrategySortInterface {
	public:
		virtual void sortWay(std::vector<int> &arr) = 0;
	};

	class SortContext{
	private:
		StrategySortInterface *_strategy;
	public:
		SortContext(StrategySortInterface *strategy) :_strategy(strategy) {};
		std::vector<int> sort(std::vector<int> array);
		void modifySortContext(StrategySortInterface *strategy);
		void showArray(std::vector<int> array);
	};

	class MergeSort :public StrategySortInterface {
	public:
		void sortWay(std::vector<int> &arr) override;
	private:
		void dividedAndMerge(std::vector<int> &arr, int front, int end);
		void merge(std::vector<int> &arr, int front, int middle, int end);

	};

	class HeapSort : public StrategySortInterface {
	private:
		void doMaxHeap(std::vector<int> &array);
		void modifyHeap(std::vector<int> &data, int root, int length);
	public:
		void sortWay(std::vector<int> &arr) override;
	
	};
};