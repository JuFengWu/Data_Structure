#pragma once
#ifndef TRAVERSAL
#define TRAVERSAL
#include"TreeNodeAndBinaryTree.h"
#include <utility>
#include <vector>
namespace Tree {
	template <class CType>
	class TreeNode;

	template <class CType>
	class Traversal {
	public:
		void traversal(TreeNode<CType>* currentNode, std::vector<std::pair<int, CType>>& data) {
			if (currentNode!=nullptr) {
				current = currentNode;
				beforeTraversal(data);
				traversal(current->getLeftchild(), data);

				current = currentNode;
				inBetweenTwoTraversal(data);
				traversal(current->getRightchild(), data);

				current = currentNode;
				afterTraversal(data);
			}
		}
		
	protected:
		TreeNode<CType>* current;
		virtual void beforeTraversal(std::vector < std::pair<int, CType>>& data) {
			return;
		}
		virtual void inBetweenTwoTraversal(std::vector < std::pair<int, CType>>& data) {
			return;
		}
		virtual void afterTraversal(std::vector < std::pair<int, CType>>& data) {
			return;
		}
	};
	template <class CType>
	class PreOrder : public Traversal<CType>
	{
	protected:
		void beforeTraversal(std::vector < std::pair<int, CType>>& data) override {
			data.push_back(std::make_pair(this->current->getKey(), this->current->getElement()));
		}
		void inBetweenTwoTraversal(std::vector< std::pair<int, CType>>& data) override {
			return;
		}
		void afterTraversal(std::vector < std::pair<int, CType>>& data) override{
			return;
		}
		
	};
	template <class CType>
	class InOrder : public Traversal<CType>
	{
	protected:
		void beforeTraversal(std::vector < std::pair<int, CType>>& data) override {
			return;
		}
		void inBetweenTwoTraversal(std::vector < std::pair<int, CType>>& data) override {
			data.push_back(std::make_pair(this->current->getKey(), this->current->getElement()));
		}
		void afterTraversal(std::vector < std::pair<int, CType>>& data) override {
			return;
		}
	};
	template <class CType>
	class PostOrder : public Traversal<CType>
	{
	protected:
		void beforeTraversal(std::vector < std::pair<int, CType>>& data) override {
			return;
		}
		void inBetweenTwoTraversal(std::vector < std::pair<int, CType>>& data) override {
			return;
		}
		void afterTraversal(std::vector < std::pair<int, CType>>& data) override {
			data.push_back(std::make_pair(this->current->getKey(), this->current->getElement()));
		}
	};
	template <class CType>
	class Print2DTree : public Traversal<CType> {
	public:
		Print2DTree(int showSpace) : _showSpace(showSpace), _space(0){};
	protected:
		void beforeTraversal(std::vector < std::pair<int, CType>>& data) override {
			_space += _showSpace;
		}
		void inBetweenTwoTraversal(std::vector < std::pair<int, CType>>& data) override {
			for (int i = 0; i < _space; i++) {
				std::cout << " ";
			}
			std::cout << this->current->getKey() << std::endl;
		}
		void afterTraversal(std::vector < std::pair<int, CType>>& data) override {
			_space -= _showSpace;
		}
	private:
		int _space;
		int _showSpace;
	};
	

}
#endif // TRAVERSAL

