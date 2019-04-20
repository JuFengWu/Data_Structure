#include "pch.h"
#include "../Tree/BinarySearchTree.h"
#include"../Tree/TreeNodeAndBinaryTree.h"


TEST(TestCaseName, TestBinarySearchTreeTestSearch) {
	
	
	Tree::BinarySearchTree<char> binarySearchTree;
	
	binarySearchTree.add(5, 'q');
	EXPECT_EQ(1, 1);
	binarySearchTree.add(6, 'p');
	binarySearchTree.add(10, 'c');
	
    EXPECT_EQ('q', binarySearchTree.search(5));
	EXPECT_EQ('p', binarySearchTree.search(6));
	EXPECT_EQ('c', binarySearchTree.search(10));
}
TEST(TestCaseName, BinarySearchTreeSearchElement) {


	Tree::BinarySearchTree<char> binarySearchTree;

	binarySearchTree.add(5, 'q');
	binarySearchTree.add(6, 'p');
	binarySearchTree.add(10, 'c');

	EXPECT_EQ('q', binarySearchTree.searchNode(5)->getElement());
	EXPECT_EQ('p', binarySearchTree.searchNode(6)->getElement());
	EXPECT_EQ('c', binarySearchTree.searchNode(10)->getElement());
}
TEST(TestCaseName, BinarySearchTreeSearchNodeTraversal) {


	Tree::BinarySearchTree<char> binarySearchTree;

	binarySearchTree.add(5, 'q');
	binarySearchTree.add(6, 'p');
	binarySearchTree.add(10, 'c');

	Tree::PreOrder<char> preOrder;
	std::vector<std::pair<int, char>> preOrderAns;
	std::pair<int, char> first(5, 'q');
	std::pair<int, char> second(6, 'p');
	std::pair<int, char> third(10, 'c');
	preOrderAns.push_back(first);
	preOrderAns.push_back(second);
	preOrderAns.push_back(third);

	EXPECT_EQ(preOrderAns, binarySearchTree.getAllKeyAndData(preOrder));

	Tree::InOrder<char> inOrder;
	std::vector<std::pair<int, char>> inOrderAns;
	inOrderAns.push_back(third);
	inOrderAns.push_back(second);
	inOrderAns.push_back(first);
	EXPECT_EQ(inOrderAns, binarySearchTree.getAllKeyAndData(inOrder));

	Tree::PostOrder<char> postOrder;
	std::vector<std::pair<int, char>> postOrderAns;
	postOrderAns.push_back(third);
	postOrderAns.push_back(second);
	postOrderAns.push_back(first);
	EXPECT_EQ(postOrderAns, binarySearchTree.getAllKeyAndData(postOrder));
	
}

TEST(TestCaseName,BinarySearchTreeDeleteLeft) {


	Tree::BinarySearchTree<char> binarySearchTree;

	binarySearchTree.add(5, 'q');
	binarySearchTree.add(6, 'p');
	binarySearchTree.add(10, 'c');
	binarySearchTree.deleteObject(5);

	Tree::PreOrder<char> preOrder;
	std::vector<std::pair<int, char>> preOrderAns;
	std::pair<int, char> second(6, 'p');
	std::pair<int, char> third(10, 'c');
	preOrderAns.push_back(second);
	preOrderAns.push_back(third);

	EXPECT_EQ(preOrderAns, binarySearchTree.getAllKeyAndData(preOrder));
}
TEST(TestCaseName, BinarySearchTreeDeleteRight) {


	Tree::BinarySearchTree<char> binarySearchTree;
	
	binarySearchTree.add(10, 'c');
	binarySearchTree.add(6, 'p');
	binarySearchTree.add(5, 'q');
	
	binarySearchTree.deleteObject(6);

	Tree::PostOrder<char> postOrder;
	std::vector<std::pair<int, char>> preOrderAns;
	std::pair<int, char> second(5, 'q');
	std::pair<int, char> third(10, 'c');
	preOrderAns.push_back(second);
	preOrderAns.push_back(third);

	EXPECT_EQ(preOrderAns, binarySearchTree.getAllKeyAndData(postOrder));
}
TEST(TestCaseName, BinarySearchTreeDeleteMiddle) {
	Tree::BinarySearchTree<char> binarySearchTree;
	
	binarySearchTree.add(6, 'p');
	binarySearchTree.add(10, 'c');
	binarySearchTree.add(5, 'q');
	binarySearchTree.deleteObject(6);

	Tree::InOrder<char> InOrder;
	std::vector<std::pair<int, char>> preOrderAns;
	std::pair<int, char> second(10, 'c');
	std::pair<int, char> third(5, 'q');
	preOrderAns.push_back(second);
	preOrderAns.push_back(third);

	EXPECT_EQ(preOrderAns, binarySearchTree.getAllKeyAndData(InOrder));
}
TEST(TestCaseName, BinarySearchTreeConstruct){
	Tree::BinarySearchTree<char> binarySearchTree;

	binarySearchTree.add(5, 'q');
	binarySearchTree.add(6, 'p');
	binarySearchTree.add(10, 'c');
	

	Tree::BinarySearchTree<char> binarySearchTreeCopyConstruct(binarySearchTree);

	Tree::PreOrder<char> preOrder;
	std::vector<std::pair<int, char>> preOrderAns;
	std::pair<int, char> first(5, 'q');
	std::pair<int, char> second(6, 'p');
	std::pair<int, char> third(10, 'c');
	preOrderAns.push_back(first);
	preOrderAns.push_back(second);
	preOrderAns.push_back(third);

	EXPECT_EQ(preOrderAns, binarySearchTreeCopyConstruct.getAllKeyAndData(preOrder));

	Tree::BinarySearchTree<char> binarySearchTreeMoveConstruct = std::move(binarySearchTree);

	EXPECT_EQ(preOrderAns, binarySearchTreeMoveConstruct.getAllKeyAndData(preOrder));

}

TEST(TestCaseName, TestOperatorAssigment){
	Tree::BinarySearchTree<char> binarySearchTree;

	binarySearchTree.add(5, 'q');
	binarySearchTree.add(6, 'p');
	binarySearchTree.add(10, 'c');

	Tree::BinarySearchTree<char> binarySearchTreeCopyAssigment;

	binarySearchTreeCopyAssigment = binarySearchTree;

	Tree::PreOrder<char> preOrder;
	std::vector<std::pair<int, char>> preOrderAns;
	std::pair<int, char> first(5, 'q');
	std::pair<int, char> second(6, 'p');
	std::pair<int, char> third(10, 'c');
	preOrderAns.push_back(first);
	preOrderAns.push_back(second);
	preOrderAns.push_back(third);

	EXPECT_EQ(preOrderAns, binarySearchTreeCopyAssigment.getAllKeyAndData(preOrder));

	Tree::BinarySearchTree<char> binarySearchTreeMoveAssigment;
	binarySearchTreeMoveAssigment = std::move(binarySearchTree);

	EXPECT_EQ(preOrderAns, binarySearchTreeMoveAssigment.getAllKeyAndData(preOrder));
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
