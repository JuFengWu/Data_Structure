#include"TreeNodeAndBinaryTree.h"
#include<iostream>
namespace Tree {
	int TreeNode::getKey() {
		return _key;
	}
	char TreeNode::getElement() {
		return _data;
	}
	TreeNode* TreeNode::getLeftchild() {
		return leftchild;
	}
	TreeNode* TreeNode::getRightchild() {
		return rightchild;
	}
	void TreeNode::setLeftchild(TreeNode* node) {
		leftchild = node;
	}
	void TreeNode::setRightchild(TreeNode* node) {
		rightchild = node;
	}
	bool TreeNode::getColor() {
		if (_isNodeHaveColor) {
			return _color;
		}
		else {
			throw "this node does not have color!!";
		}
	}
	void TreeNode::setColor(bool color) {
		if (_isNodeHaveColor) {
			_color = color;
		}
		else {
			throw "this node does not have color!!";
		}
	}
	void BinaryTree::showAllInOrder() {
		inOrder(this->root);
		std::cout << "above is all" << std::endl;

	}
	void BinaryTree::inOrder(TreeNode *current) {
		if (current != nullptr) {
			inOrder(current->getLeftchild());
			std::cout << "key is:" << current->getKey() << "  value is:" << current->getElement() << std::endl;
			inOrder(current->getRightchild());
		}
	}
	char BinaryTree::search(int key) {
		TreeNode *theNode = searchNode(key);

		if (theNode != nullptr) {
			return theNode->getElement();
		}
		return NULL;
	}
	void BinaryTree::showTreeStruct() {
		print2DTree(root, 0);
	}
	void BinaryTree::print2DTree(TreeNode* root, int space) {
		if (root == nullptr) {
			return;
		}
		space += BinaryTree::showSpace;
		print2DTree(root->getLeftchild(), space);
		for (int i = 0; i < space; i++) {
			std::cout << " ";
		}
		std::cout << root->getKey() << std::endl;
		print2DTree(root->getRightchild(), space);
	}

	TreeNode* BinaryTree::searchNode(int key) {
		TreeNode *current = root;

		while (current != nullptr && key != current->getKey()) {
			if (key < current->getKey()) {//go left 
				current = current->getLeftchild();
			}
			else {
				current = current->getRightchild();
			}
		}

		if (current == nullptr) {
			return nullptr;
		}
		return current;
	}

	TreeNode* BinaryTree::leftSuccessor(TreeNode *current) {// left max value
		if (current->getLeftchild() == nullptr) {
			std::cout << "there is not left Successor" << std::endl;
			return nullptr;
		}
		current = current->getLeftchild();
		TreeNode *successor = current;
		while (current->getRightchild() != nullptr) {
			successor = current->getRightchild();
			current = current->getRightchild();
		}

		return successor;
	}
	TreeNode* BinaryTree::rightSuccessor(TreeNode *current) {
		if (current->getRightchild() == nullptr) {
			std::cout << "there is not right Successor" << std::endl;
			return nullptr;
		}
		current = current->getRightchild();
		TreeNode* successor = current;
		while (current->getLeftchild() != nullptr) {
			successor = current->getLeftchild();
			current = current->getLeftchild();
		}

		return successor;
	}
	void BinaryTree::testSuccesssor() {
		showTreeStruct();
		TreeNode* successor = leftSuccessor(root);
		std::cout << "left successor is " << successor->getKey() << std::endl;
		successor = rightSuccessor(root);
		std::cout << "right successor is " << successor->getKey() << std::endl;
		std::cout << "root index is " << root->getKey() << std::endl;
	}
};