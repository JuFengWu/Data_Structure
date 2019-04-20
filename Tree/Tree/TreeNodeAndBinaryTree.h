#ifndef TREENODEANDBINARYTREE
#define TREENODEANDBINARYTREE
#include<utility>
#include <vector>
#include"Traversal.h"

namespace Tree {
	template <class CType>
	class TreeNode {
	public:
		TreeNode(int key, CType data, bool isNodeHaveColor) :parent(nullptr),leftchild(nullptr), rightchild(nullptr), _key(key), _data(data), _isNodeHaveColor(isNodeHaveColor), _color(true) {};
		int getKey();
		CType getElement();
		TreeNode* getLeftchild();
		TreeNode* getRightchild();
		void setLeftchild(TreeNode<CType> * node);
		void setRightchild(TreeNode<CType> * node);
		bool getColor();
		void setColor(bool color);
		TreeNode* parent;
	private:
		TreeNode* leftchild;
		TreeNode* rightchild;
		int _key;
		CType _data;
		bool _isNodeHaveColor;
		bool _color;// true is black, false is red
	};

	template <class CType>
	class BinaryTree {
	public:
		virtual ~BinaryTree() = default;
		virtual void add(int key, CType data) = 0;   //OK
		void showAllInOrder();
		CType search(int key);// log(n)             //OK
		virtual bool deleteObject(int key) = 0;    //OK
		TreeNode<CType>* searchNode(int key);      //OK
		void showTreeStruct();
		std::vector<std::pair<int, CType>> getAllKeyAndData(Traversal<CType>& traversalWay);
		
		
	protected:
		static const int showSpace = 3;
		TreeNode<CType>* root;
		TreeNode<CType>* leftSuccessor(TreeNode<CType>* current);
		TreeNode<CType>* rightSuccessor(TreeNode<CType>* current);
		void deleteAllNode(TreeNode<CType>* treeNode);

	};



	template <class CType>
	int TreeNode<CType>::getKey() {
		return _key;
	}
	template <class CType>
	CType TreeNode<CType>::getElement() {
		return _data;
	}
	template <class CType>
	TreeNode<CType>* TreeNode <CType> ::getLeftchild() {
		return leftchild;
	}
	template <class CType>
	TreeNode<CType>* TreeNode<CType>::getRightchild() {
		return rightchild;
	}
	template <class CType>
	void TreeNode<CType>::setLeftchild(TreeNode<CType> * node) {
		leftchild = node;
	}
	template <class CType>
	void TreeNode <CType> ::setRightchild(TreeNode<CType>  * node) {
		rightchild = node;
	}
	template <class CType>
	bool TreeNode<CType>::getColor() {
		if (_isNodeHaveColor) {
			return _color;
		}
		else {
			throw "this node does not have color!!";
		}
	}
	template <class CType>
	void TreeNode<CType>::setColor(bool color) {
		if (_isNodeHaveColor) {
			_color = color;
		}
		else {
			throw "this node does not have color!!";
		}
	}
	template <class CType>
	void BinaryTree<CType>::showAllInOrder() {
		InOrder<CType> inOrder;
		std::vector<std::pair<int, CType>> data;
		inOrder.traversal(this->root, data);
		for (unsigned int i = 0;i < data.size(); i++) {
			std::cout << "key is " << data[i].first << " value is " << search(data[i].second) << std::endl;
		}
		std::cout << "above is all" << std::endl;

	}
	
	template <class CType>
	CType BinaryTree<CType>::search(int key) {
		TreeNode<CType> *theNode = searchNode(key);

		if (theNode != nullptr) {
			return theNode->getElement();
		}
		//throw "there is no elements";
		return -1;
	}
	template <class CType>
	void BinaryTree<CType>::showTreeStruct() {
		
		Print2DTree<CType> print2DTree(BinaryTree::showSpace);
		std::vector<std::pair<int, CType>> data;
		print2DTree.traversal(root, data);
	}
	
	template <class CType>
	TreeNode<CType>* BinaryTree<CType>::searchNode(int key) {
		TreeNode<CType> *current = root;

		while (current != nullptr && key != current->getKey()) {
			if (key > current->getKey()) {//go left 
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
	template <class CType>
	TreeNode<CType>* BinaryTree<CType>::leftSuccessor(TreeNode<CType> *current) {// left max value
		if (current->getLeftchild() == nullptr) {
			std::cout << "there is not left Successor" << std::endl;
			return nullptr;
		}
		current = current->getLeftchild();
		TreeNode<CType> *successor = current;
		while (current->getRightchild() != nullptr) {
			successor = current->getRightchild();
			current = current->getRightchild();
		}

		return successor;
	}
	template <class CType>
	TreeNode<CType>* BinaryTree<CType>::rightSuccessor(TreeNode<CType> *current) {
		if (current->getRightchild() == nullptr) {
			std::cout << "there is not right Successor" << std::endl;
			return nullptr;
		}
		current = current->getRightchild();
		TreeNode<CType>* successor = current;
		while (current->getLeftchild() != nullptr) {
			successor = current->getLeftchild();
			current = current->getLeftchild();
		}

		return successor;
	}
	template <class CType>
	void BinaryTree<CType>::deleteAllNode(TreeNode<CType>* treeNode) {
		if (treeNode != nullptr)
		{
			deleteAllNode(treeNode->getLeftchild());
			deleteAllNode(treeNode->getRightchild());
			delete treeNode;
		}
	}
	template <class CType>
	std::vector<std::pair<int, CType>> BinaryTree<CType>::getAllKeyAndData(Traversal<CType>& traversalWay) {
		std::vector<std::pair<int, CType>> data;
		traversalWay.traversal(root, data);
		return data;
	}
}

#endif 