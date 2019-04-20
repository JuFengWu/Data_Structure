#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE
#include"TreeNodeAndBinaryTree.h"
namespace Tree {
	template <class CType>
	class BinarySearchTree : public BinaryTree<CType> {
	public:
		BinarySearchTree();
		BinarySearchTree(const BinarySearchTree<CType>& other); //"this is copy constructor"
		BinarySearchTree(BinarySearchTree<CType>&& other);//"this is move constructor"
		BinarySearchTree<CType>& operator = (const BinarySearchTree<CType> &other);// "this is copy operator ="
		BinarySearchTree<CType>& operator = (BinarySearchTree<CType> && other); //"this is move operator ="
		void add(int key, CType data) override;
		bool deleteObject(int key)  override;
		~BinarySearchTree();
	private:
		
		void modifyParitenNode(TreeNode<CType>* theNode, TreeNode<CType>* thePickNode);
		void replaceAndDeleteNode(TreeNode<CType>* thePlaceNode, TreeNode<CType>* thePickNode, bool isLeft);
	};
	template <class CType>
	BinarySearchTree<CType>::BinarySearchTree() {
		this->root = nullptr;
	}

	template <class CType>
	BinarySearchTree<CType>::BinarySearchTree(const BinarySearchTree<CType>& other) {
		this->root = nullptr;
		PreOrder<CType> traversalWay;
		TreeNode<CType> *otherRoot = other.root;
		std::vector<std::pair<int, CType>> data;
		traversalWay.traversal(otherRoot, data);
		for (unsigned int i = 0;i < data.size();i++) {
			this->add(data[i].first, data[i].second);
		}
		std::cout << "this is copy constructor" << std::endl;
	}
	template <class CType>
	BinarySearchTree<CType>::BinarySearchTree(BinarySearchTree<CType>&& other) {
		this->root = other.root;
		other.root = nullptr;
		std::cout<<"this is move constructor" << std::endl;
	}
	template <class CType>
	BinarySearchTree<CType>&  BinarySearchTree<CType>::operator =(const BinarySearchTree<CType> &other) {
		std::cout << "this is copy operator =" << std::endl;

		BinarySearchTree<CType> temp(other);

		*this = std::move(temp);

		return *this;
	}
	template <class CType>
	BinarySearchTree<CType>&  BinarySearchTree<CType>:: operator = (BinarySearchTree<CType> && other) {
		std::cout << "this is move operator =" << std::endl;
		this->root = other.root;
		other.root = nullptr;

		return *this;
	}
	template <class CType>
	void BinarySearchTree<CType>::add(int key, CType data) {
		TreeNode<CType> *inserNode = new TreeNode<CType>(key, data, false);
		TreeNode<CType> *checkNode = this->root;
		TreeNode<CType> *lastNode = checkNode;
		bool isRight = false;

		while (checkNode != nullptr) {
			lastNode = checkNode;
			if (inserNode->getKey() < checkNode->getKey()) {
				checkNode = checkNode->getRightchild();
				isRight = true;
			}
			else {
				checkNode = checkNode->getLeftchild();
				isRight = false;
			}
		}
		if (lastNode == nullptr) {
			this->root = inserNode;
			return;
		}
		else if (isRight) {
			lastNode->setRightchild(inserNode);
		}
		else {
			lastNode->setLeftchild(inserNode);
		}
		inserNode->parent = lastNode;
	}
	template <class CType>
	void BinarySearchTree<CType>::modifyParitenNode(TreeNode<CType>* theNode, TreeNode<CType>* thePickNode) {
		if (theNode->parent->getLeftchild() == theNode) {
			theNode->parent->setLeftchild(thePickNode);
		}
		else {
			theNode->parent->setRightchild(thePickNode);
		}
	}
	template <class CType>
	void BinarySearchTree<CType>::replaceAndDeleteNode(TreeNode<CType>* thePlaceNode, TreeNode<CType>* thePickNode, bool isLeft) {
		if (isLeft) {
			thePickNode->parent->setLeftchild(nullptr);
		}
		else {
			thePickNode->parent->setRightchild(nullptr);
		}
		if (thePlaceNode->parent == nullptr) {
			this->root = thePickNode;
		}
		else {
			modifyParitenNode(thePlaceNode, thePickNode);
		}
		thePickNode->parent = thePlaceNode->parent;
		thePickNode->setLeftchild(thePlaceNode->getLeftchild());
		thePickNode->setRightchild(thePlaceNode->getRightchild());
		delete thePlaceNode;
	}
	template <class CType>
	bool BinarySearchTree<CType>::deleteObject(int key) {
		TreeNode<CType> *theNode = this->searchNode(key);
		if (theNode == nullptr) {
			return false;
		}
		else if (theNode->getLeftchild() == nullptr && theNode->getRightchild() == nullptr) {
			modifyParitenNode(theNode, nullptr);
			delete theNode;
		}
		else if (theNode->getLeftchild() != nullptr && theNode->getRightchild() != nullptr) {
			TreeNode<CType>* successor = this->rightSuccessor(theNode);
			replaceAndDeleteNode(theNode, successor, false);
		}
		else if (theNode->getLeftchild() == nullptr && theNode->getRightchild() != nullptr) {
			if (theNode->parent == nullptr) {
				this->root = theNode->getRightchild();
			}
			theNode->parent->setRightchild(theNode->getRightchild());
			theNode->getRightchild()->parent = theNode->parent;

			delete theNode;
			
		}
		else if (theNode->getLeftchild() != nullptr && theNode->getRightchild() == nullptr) {
			if (theNode->parent == nullptr) {
				this->root = theNode->getLeftchild();
			}
			theNode->parent = theNode->getLeftchild();
			theNode->getLeftchild()->parent = theNode->parent;
			
			delete theNode;

		}
		return true;
	}
	template <class CType>
	BinarySearchTree<CType>::~BinarySearchTree(){
		if (this->root!=nullptr) {
			this->deleteAllNode(this->root);
			this->root = nullptr;
		}
	}
	
}
#endif