// Tree.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include "pch.h"
#include <iostream>
#include "BinarySearchTree.h"
#include "TreeNodeAndBinaryTree.h"


int main()
{
	Tree::BinarySearchTree<char> binarySearchTree;
	binarySearchTree.add(30, 'j');
	binarySearchTree.add(100, 'f');
	binarySearchTree.add(50, 'a');
	binarySearchTree.add(102, 'x');
	binarySearchTree.add(20, 'd');
	binarySearchTree.add(25, 'd');
	binarySearchTree.add(2, 'b');
	binarySearchTree.add(10, 'a');
	binarySearchTree.add(1, 'a');

	
	binarySearchTree.showAllInOrder();
}

