#ifndef TREENODEANDBINARYTREE
#define TREENODEANDBINARYTREE


namespace Tree {
	template <class CType>
	class TreeNode {
	public:
		TreeNode(int key, CType data, bool isNodeHaveColor) :leftchild(0), rightchild(0), _key(key), _data(data), _isNodeHaveColor(isNodeHaveColor), _color(true) {};
		int getKey();
		CType getElement();
		TreeNode* getLeftchild();
		TreeNode* getRightchild();
		void setLeftchild(TreeNode<CType> * node);
		void setRightchild(TreeNode<CType> * node);
		bool getColor();
		void setColor(bool color);
		TreeNode* parient;
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
		virtual void add(int key, CType data) = 0;
		void showAllInOrder();
		CType search(int key);
		virtual bool deleteObject(int key) = 0;
		TreeNode<CType>* searchNode(int key);
		void showTreeStruct();
		void testSuccesssor();
		static const int showSpace = 3;
		
	protected:
		TreeNode<CType>* root;
		TreeNode<CType>* leftSuccessor(TreeNode<CType> *current);
		TreeNode<CType>* rightSuccessor(TreeNode<CType> *current);
		

	private:
		void print2DTree(TreeNode<CType>* root, int space);
		void inOrder(TreeNode<CType> *current);	

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
		inOrder(this->root);
		std::cout << "above is all" << std::endl;

	}
	template <class CType>
	void BinaryTree<CType>::inOrder(TreeNode<CType> *current) {
		if (current != nullptr) {
			inOrder(current->getLeftchild());
			std::cout << "key is:" << current->getKey() << "  value is:" << current->getElement() << std::endl;
			inOrder(current->getRightchild());
		}
	}
	template <class CType>
	CType BinaryTree<CType>::search(int key) {
		TreeNode *theNode = searchNode(key);

		if (theNode != nullptr) {
			return theNode->getElement();
		}
		return nullptr;
	}
	template <class CType>
	void BinaryTree<CType>::showTreeStruct() {
		print2DTree(root, 0);
	}
	template <class CType>
	void BinaryTree<CType>::print2DTree(TreeNode<CType>* root, int space) {
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
	template <class CType>
	TreeNode<CType>* BinaryTree<CType>::searchNode(int key) {
		TreeNode<CType> *current = root;

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
	void BinaryTree<CType>::testSuccesssor() {
		print2DTree(root, 0);
		TreeNode* successor = leftSuccessor(root);
		std::cout << "left successor is " << successor->getKey() << std::endl;
		successor = rightSuccessor(root);
		std::cout << "right successor is " << successor->getKey() << std::endl;
		std::cout << "root index is " << root->getKey() << std::endl;
	}
	
}

#endif 