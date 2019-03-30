#include "pch.h"
#include "../Sort/Sort.cpp"

TEST(TestCaseName, HeapSortTest) {
	Sort::HeapSort testSort;
	std::vector<int> testArray;

	testArray.push_back(1);
	testArray.push_back(16);
	testArray.push_back(8);
	testArray.push_back(5);
	testArray.push_back(7);
	testArray.push_back(9);
	testArray.push_back(13);
	testArray.push_back(20);

	std::vector<int> newArray = testSort.sort(testArray);

	ASSERT_EQ(8, newArray.size());

	EXPECT_EQ(1, newArray[0]);
	EXPECT_EQ(5, newArray[1]);
	EXPECT_EQ(7, newArray[2]);
	EXPECT_EQ(8, newArray[3]);
	EXPECT_EQ(9, newArray[4]);
	EXPECT_EQ(13, newArray[5]);
	EXPECT_EQ(16, newArray[6]);
	EXPECT_EQ(20, newArray[7]);
}

TEST(TestCaseName, MergeSortTest) {
	Sort::MergeSort testSort;
	std::vector<int> testArray;

	testArray.push_back(1);
	testArray.push_back(10);
	testArray.push_back(8);
	testArray.push_back(5);
	testArray.push_back(7);
	testArray.push_back(9);
	testArray.push_back(13);

	std::vector<int> newArray = testSort.sort(testArray);

	ASSERT_EQ(7, newArray.size());

	EXPECT_EQ(1, newArray[0]);
	EXPECT_EQ(5, newArray[1]);
	EXPECT_EQ(7, newArray[2]);
	EXPECT_EQ(8, newArray[3]);
	EXPECT_EQ(9, newArray[4]);
	EXPECT_EQ(10, newArray[5]);
	EXPECT_EQ(13, newArray[6]);
}