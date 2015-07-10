#include <iostream>

template<class Type>
struct BinaryTreeNode
{
	Type data;
	BinaryTreeNode* pLeftChild;
	BinaryTreeNode* pRightChild;
};

template <class T>
class BinaryTree
{
public:
	BinaryTreeNode<T>* CreateBinaryTree()
	{
		BinaryTreeNode<T>* pBinaryTreeRootNode;
		T inputNodeData;
		std::cin >> inputNodeData;
		if (inputNodeData == 0)
		{
			return NULL;
		}
		else
		{
			pBinaryTreeRootNode = new BinaryTreeNode<T>();
			pBinaryTreeRootNode->data = inputNodeData;
			std::cout << "Please input the node:" 
					  << inputNodeData << "\'s left child" <<std::endl;
			pBinaryTreeRootNode->pLeftChild = CreateBinaryTree();
			std::cout << "Please input the node:" 
					  << inputNodeData << "\'s right child" <<std::endl;
			pBinaryTreeRootNode->pRightChild = CreateBinaryTree();
		}
		return pBinaryTreeRootNode;
	}

	void PreInOrder(BinaryTreeNode<T>* pBinaryTreeRootNode)
	{
		if (pBinaryTreeRootNode == NULL)
		{
			return;
		}
		else
		{
			std::cout << pBinaryTreeRootNode->data << std::endl;
			PreInOrder(pBinaryTreeRootNode->pLeftChild);
			PreInOrder(pBinaryTreeRootNode->pRightChild);
		}
	}

	void MiddleInOrder(BinaryTreeNode<T>* pBinaryTreeRootNode)
	{
		if (pBinaryTreeRootNode == NULL)
		{
			return;
		}
		else
		{
			MiddleInOrder(pBinaryTreeRootNode->pLeftChild);
			std::cout << pBinaryTreeRootNode->data << std::endl;
			MiddleInOrder(pBinaryTreeRootNode->pRightChild);
		}
	}

	void PostInOrder(BinaryTreeNode<T>* pBinaryTreeRootNode)
	{
		if (pBinaryTreeRootNode == NULL)
		{
			return;
		}
		PostInOrder(pBinaryTreeRootNode->pLeftChild);
		PostInOrder(pBinaryTreeRootNode->pRightChild);
		std::cout << pBinaryTreeRootNode->data << std::endl;
	}

	void Reverse(BinaryTreeNode<T>* pBinaryTreeRootNode)
	{
		if (pBinaryTreeRootNode == NULL)
		{
			return;
		}
		Reverse(pBinaryTreeRootNode->pLeftChild);
		Reverse(pBinaryTreeRootNode->pRightChild);
		BinaryTreeNode<T>* pTempNode = pBinaryTreeRootNode->pLeftChild;
		pBinaryTreeRootNode->pLeftChild = pBinaryTreeRootNode->pRightChild;
		pBinaryTreeRootNode->pRightChild = pTempNode;
	}

	int GetBinaryTreeHeight(BinaryTreeNode<T>* pBinaryTreeRootNode)
	{
		int iLeftTreeHeight = 0;
		int iRightTreeHeight = 0;
		if (pBinaryTreeRootNode == NULL)
		{
			return 0;
		}
		iLeftTreeHeight = GetBinaryTreeHeight(pBinaryTreeRootNode->pLeftChild);
		iRightTreeHeight = GetBinaryTreeHeight(pBinaryTreeRootNode->pRightChild);
		return 1+ (iLeftTreeHeight > iRightTreeHeight ? iLeftTreeHeight : iRightTreeHeight);
	}

};


int main(int argc, char const *argv[])
{
	BinaryTree<int> myTree;
	BinaryTreeNode<int>* pBinaryTreeRootNode = myTree.CreateBinaryTree();

	std::cout << "PreInOrder BinaryTree ..." << std::endl;
	myTree.PreInOrder(pBinaryTreeRootNode);

	std::cout << "MiddleInOrder BinaryTree ..." << std::endl;
	myTree.MiddleInOrder(pBinaryTreeRootNode);

	std::cout << "PostInOrder BinaryTree ..." << std::endl;
	myTree.PostInOrder(pBinaryTreeRootNode);

	std::cout << "Reverse BinaryTree ..." << std::endl;
	myTree.Reverse(pBinaryTreeRootNode);

	std::cout << "PreInOrder BinaryTree ..." << std::endl;
	myTree.PreInOrder(pBinaryTreeRootNode);

	std::cout << "Get BinaryTree Height..." << std::endl;
	int iHeight = myTree.GetBinaryTreeHeight(pBinaryTreeRootNode);
	std::cout << "BinaryTreeHeight is:" << iHeight << std::endl;
	return 0;
}
