#include "pch.h"
#include "../Sort/Sort.cpp"

TEST(TestCaseName, HeapSortTest) {
	Sort::HeapSort testSort;
	std::vector<int> testArray;

	testArray.push_back(16);
	testArray.push_back(1);
	testArray.push_back(8);
	testArray.push_back(5);
	testArray.push_back(7);
	testArray.push_back(9);
	testArray.push_back(13);
	testArray.push_back(20);

	testSort.sortWay(testArray);

	ASSERT_EQ(8, testArray.size());

	EXPECT_EQ(1, testArray[0]);
	EXPECT_EQ(5, testArray[1]);
	EXPECT_EQ(7, testArray[2]);
	EXPECT_EQ(8, testArray[3]);
	EXPECT_EQ(9, testArray[4]);
	EXPECT_EQ(13, testArray[5]);
	EXPECT_EQ(16, testArray[6]);
	EXPECT_EQ(20, testArray[7]);
}

TEST(TestCaseName, MergeSortTest) {
	Sort::MergeSort testSort;
	std::vector<int> testArray;

	testArray.push_back(18);
	testArray.push_back(1);
	testArray.push_back(10);
	testArray.push_back(8);
	testArray.push_back(5);
	testArray.push_back(7);
	testArray.push_back(9);
	testArray.push_back(13);

	testSort.sortWay(testArray);

	ASSERT_EQ(8, testArray.size());

	EXPECT_EQ(1, testArray[0]);
	EXPECT_EQ(5, testArray[1]);
	EXPECT_EQ(7, testArray[2]);
	EXPECT_EQ(8, testArray[3]);
	EXPECT_EQ(9, testArray[4]);
	EXPECT_EQ(10, testArray[5]);
	EXPECT_EQ(13, testArray[6]);
	EXPECT_EQ(18, testArray[7]);
}