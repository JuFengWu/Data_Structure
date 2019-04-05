#include"BinarySearchTree.h"

namespace Tree {
	void BinarySearchTree::add(int key, char data) {
		TreeNode *inserNode = new TreeNode(key, data, false);
		TreeNode *checkNode = root;
		TreeNode *lastNode = checkNode;
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
			root = inserNode;
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
	void BinarySearchTree::modifyParitenNode(TreeNode* theNode, TreeNode* thePickNode) {
		if (theNode->parient->getLeftchild() == theNode) {
			theNode->parient->setLeftchild(thePickNode);
		}
		else {
			theNode->parient->setRightchild(thePickNode);
		}
	}

	void BinarySearchTree::replaceAndDeleteNode(TreeNode* thePlaceNode, TreeNode* thePickNode, bool isLeft) {
		if (isLeft) {
			thePickNode->parient->setLeftchild(nullptr);
		}
		else {
			thePickNode->parient->setRightchild(nullptr);
		}
		if (thePlaceNode->parient == nullptr) {
			root = thePickNode;
		}
		else {
			modifyParitenNode(thePlaceNode, thePickNode);
		}
		thePickNode->parient = thePlaceNode->parient;
		thePickNode->setLeftchild(thePlaceNode->getLeftchild());
		thePickNode->setRightchild(thePlaceNode->getRightchild());
		delete thePlaceNode;
	}
	bool BinarySearchTree::deleteObject(int key) {
		TreeNode *theNode = searchNode(key);
		if (theNode == nullptr) {
			return false;
		}
		else if (theNode->getLeftchild() == nullptr && theNode->getRightchild() == nullptr) {
			modifyParitenNode(theNode, nullptr);
			delete theNode;
		}
		else if (theNode->getLeftchild() != nullptr && theNode->getRightchild() != nullptr) {
			TreeNode* successor = rightSuccessor(theNode);
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