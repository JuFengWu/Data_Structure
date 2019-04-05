#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE
#include"TreeNodeAndBinaryTree.h"
namespace Tree {
	template <class CType>
	class BinarySearchTree : public BinaryTree<CType> {
	public:
		void add(int key, CType data) override;
		bool deleteObject(int key)  override;

	private:
		void modifyParitenNode(TreeNode<CType>* theNode, TreeNode<CType>* thePickNode);
		void replaceAndDeleteNode(TreeNode<CType>* thePlaceNode, TreeNode<CType>* thePickNode, bool isLeft);
	};

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
		inserNode->parient = lastNode;
	}
	template <class CType>
	void BinarySearchTree<CType>::modifyParitenNode(TreeNode<CType>* theNode, TreeNode<CType>* thePickNode) {
		if (theNode->parient->getLeftchild() == theNode) {
			theNode->parient->setLeftchild(thePickNode);
		}
		else {
			theNode->parient->setRightchild(thePickNode);
		}
	}
	template <class CType>
	void BinarySearchTree<CType>::replaceAndDeleteNode(TreeNode<CType>* thePlaceNode, TreeNode<CType>* thePickNode, bool isLeft) {
		if (isLeft) {
			thePickNode->parient->setLeftchild(nullptr);
		}
		else {
			thePickNode->parient->setRightchild(nullptr);
		}
		if (thePlaceNode->parient == nullptr) {
			this->root = thePickNode;
		}
		else {
			modifyParitenNode(thePlaceNode, thePickNode);
		}
		thePickNode->parient = thePlaceNode->parient;
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
			replaceAndDeleteNode(theNode, theNode->getRightchild(), false);
		}
		else if (theNode->getLeftchild() != nullptr && theNode->getRightchild() == nullptr) {
			replaceAndDeleteNode(theNode, theNode->getLeftchild(), true);
		}
		return true;
	}
}
#endif