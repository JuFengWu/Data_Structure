#include"TreeNodeAndBinaryTree.h"
namespace Tree {
	class BinarySearchTree : public BinaryTree {
	public:
		void add(int key, char data) override;
		bool deleteObject(int key)  override;

	private:
		void modifyParitenNode(TreeNode* theNode, TreeNode* thePickNode);
		void replaceAndDeleteNode(TreeNode* thePlaceNode, TreeNode* thePickNode, bool isLeft);
	};
}
