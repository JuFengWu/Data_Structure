namespace Tree {
	class TreeNode {
	public:
		TreeNode(int key, char s, bool isNodeHaveColor) :leftchild(0), rightchild(0), _key(key), _data(s), _isNodeHaveColor(isNodeHaveColor), _color(true) {};
		int getKey();
		char getElement();
		TreeNode* getLeftchild();
		TreeNode* getRightchild();
		void setLeftchild(TreeNode* node);
		void setRightchild(TreeNode* node);
		bool getColor();
		void setColor(bool color);
		TreeNode* parient;
	private:
		TreeNode* leftchild;
		TreeNode* rightchild;
		int _key;
		char _data;
		bool _isNodeHaveColor;
		bool _color;// true is black, false is red
	};

	class BinaryTree {
	public:
		virtual void add(int key, char data) = 0;
		void showAllInOrder();
		char search(int key);
		virtual bool deleteObject(int key) = 0;
		TreeNode* searchNode(int key);
		void showTreeStruct();
		void testSuccesssor();
		static const int showSpace = 3;
	protected:
		TreeNode* leftSuccessor(TreeNode *current);
		TreeNode* rightSuccessor(TreeNode *current);
		TreeNode* root;

	private:

		void inOrder(TreeNode *current);
		void print2DTree(TreeNode* root, int space);

	};
}
