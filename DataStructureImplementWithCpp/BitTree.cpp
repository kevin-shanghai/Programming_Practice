#include <iostream>

template<class Type>
struct BitTreeNode
{
	Type data;
	BitTreeNode* pLeftChild;
	BitTreeNode* pRightChild;
};

template <class T>
class BitTree
{
public:
	BitTreeNode<T>* CreateBitTree()
	{
		BitTreeNode<T>* pBitTreeRootNode;
		T inputNodeData;
		std::cin >> inputNodeData;
		if (inputNodeData == 0)
		{
			return NULL;
		}
		else
		{
			pBitTreeRootNode = new BitTreeNode<T>();
			pBitTreeRootNode->data = inputNodeData;
			std::cout << "Please input the node:" 
					  << inputNodeData << "\'s left child" <<std::endl;
			pBitTreeRootNode->pLeftChild = CreateBitTree();
			std::cout << "Please input the node:" 
					  << inputNodeData << "\'s right child" <<std::endl;
			pBitTreeRootNode->pRightChild = CreateBitTree();
		}
		return pBitTreeRootNode;
	}

	void PreInOrder(BitTreeNode<T>* pBitTreeRootNode)
	{
		if (pBitTreeRootNode == NULL)
		{
			return;
		}
		else
		{
			std::cout << pBitTreeRootNode->data << std::endl;
			PreInOrder(pBitTreeRootNode->pLeftChild);
			PreInOrder(pBitTreeRootNode->pRightChild);
		}
	}

	void MiddleInOrder(BitTreeNode<T>* pBitTreeRootNode)
	{
		if (pBitTreeRootNode == NULL)
		{
			return;
		}
		else
		{
			MiddleInOrder(pBitTreeRootNode->pLeftChild);
			std::cout << pBitTreeRootNode->data << std::endl;
			MiddleInOrder(pBitTreeRootNode->pRightChild);
		}
	}

	void PostInOrder(BitTreeNode<T>* pBitTreeRootNode)
	{
		if (pBitTreeRootNode == NULL)
		{
			return;
		}
		PostInOrder(pBitTreeRootNode->pLeftChild);
		PostInOrder(pBitTreeRootNode->pRightChild);
		std::cout << pBitTreeRootNode->data << std::endl;
	}

	void Reverse(BitTreeNode<T>* pBitTreeRootNode)
	{
		if (pBitTreeRootNode == NULL)
		{
			return;
		}
		Reverse(pBitTreeRootNode->pLeftChild);
		Reverse(pBitTreeRootNode->pRightChild);
		BitTreeNode<T>* pTempNode = pBitTreeRootNode->pLeftChild;
		pBitTreeRootNode->pLeftChild = pBitTreeRootNode->pRightChild;
		pBitTreeRootNode->pRightChild = pTempNode;
	}

	int GetBitTreeHeight(BitTreeNode<T>* pBitTreeRootNode)
	{
		int iLeftTreeHeight = 0;
		int iRightTreeHeight = 0;
		if (pBitTreeRootNode == NULL)
		{
			return 0;
		}
		iLeftTreeHeight = GetBitTreeHeight(pBitTreeRootNode->pLeftChild);
		iRightTreeHeight = GetBitTreeHeight(pBitTreeRootNode->pRightChild);
		return 1+ (iLeftTreeHeight > iRightTreeHeight ? iLeftTreeHeight : iRightTreeHeight);
	}

};


int main(int argc, char const *argv[])
{
	BitTree<int> myTree;
	BitTreeNode<int>* pBitTreeRootNode = myTree.CreateBitTree();

	std::cout << "PreInOrder BitTree ..." << std::endl;
	myTree.PreInOrder(pBitTreeRootNode);

	std::cout << "MiddleInOrder BitTree ..." << std::endl;
	myTree.MiddleInOrder(pBitTreeRootNode);

	std::cout << "PostInOrder BitTree ..." << std::endl;
	myTree.PostInOrder(pBitTreeRootNode);

	std::cout << "Reverse BitTree ..." << std::endl;
	myTree.Reverse(pBitTreeRootNode);

	std::cout << "PreInOrder BitTree ..." << std::endl;
	myTree.PreInOrder(pBitTreeRootNode);

	std::cout << "Get BitTree Height..." << std::endl;
	int iHeight = myTree.GetBitTreeHeight(pBitTreeRootNode);
	std::cout << "BitTreeHeight is:" << iHeight << std::endl;
	return 0;
}