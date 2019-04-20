// Tree.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include "pch.h"
#include <iostream>
#include <vector>
#include "BinarySearchTree.h"
#include "TreeNodeAndBinaryTree.h"
#include "Traversal.h"


#ifdef _DEBUG
#define DEBUG_CLIENTBLOCK   new( _CLIENT_BLOCK, __FILE__, __LINE__)
#else
#define DEBUG_CLIENTBLOCK
#endif
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
#define new DEBUG_CLIENTBLOCK
#endif

int main()
{
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

		binarySearchTree.deleteObject(1);


		//binarySearchTree.showAllInOrder();
		binarySearchTree.showTreeStruct();
		std::cout << binarySearchTree.search(30) << std::endl;
		std::cout << binarySearchTree.search(20) << std::endl;
		Tree::PreOrder<char> preOder;

	    auto data = binarySearchTree.getAllKeyAndData(preOder);
		for(unsigned int i=0;i< data.size();i++){
			std::cout << data[i].first << ",";
		}
		std::cout << std::endl;

		//Tree::BinaryTree<char> bst;
		Tree::BinarySearchTree<char> bst(binarySearchTree);
		//bst = std::move(binarySearchTree);

		//TODO: check rule of five in base 

		bst.showTreeStruct();
		std::cout << "after show tree struct" << std::endl;
		std::cout << "after do copy operator" << std::endl;

		std::cout << "after assign"<<std::endl;
		
	}
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	std::system("pause");
	
}

