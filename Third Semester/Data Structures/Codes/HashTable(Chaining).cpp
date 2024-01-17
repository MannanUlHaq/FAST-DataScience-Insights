#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

class TreeNode
{
	int Data;
	TreeNode* Left;
	TreeNode* Right;

	friend class BST;
};

class BST
{
private:
	TreeNode* Root;

	void insertRecursive(TreeNode*& currNode, TreeNode* newNode)
	{
		if (currNode == nullptr)
			currNode = newNode;
		else if (newNode->Data < currNode->Data)
			insertRecursive(currNode->Left, newNode);
		else
			insertRecursive(currNode->Right, newNode);
	}

	void inOrderRecursive(TreeNode* currNode)
	{
		if (currNode != nullptr)
		{
			inOrderRecursive(currNode->Left);
			cout << currNode->Data << " ";
			inOrderRecursive(currNode->Right);
		}
	}

	void preOrderRecursive(TreeNode* currNode)
	{
		if (currNode != nullptr)
		{
			cout << currNode->Data << " ";
			preOrderRecursive(currNode->Left);
			preOrderRecursive(currNode->Right);
		}
	}

	void postOrderRecursive(TreeNode* currNode)
	{
		if (currNode != nullptr)
		{
			postOrderRecursive(currNode->Left);
			postOrderRecursive(currNode->Right);
			cout << currNode->Data << " ";
		}
	}

	void levelorderPrintHelper(TreeNode* currNode)
	{
		if (currNode == nullptr)
			return;

		queue<TreeNode*> q;
		q.push(currNode);

		while (!q.empty())
		{
			int levelSize = q.size();
			for (int i = 0; i < levelSize; ++i)
			{
				TreeNode* node = q.front();
				q.pop();
				cout << node->Data << " ";

				if (node->Left)
					q.push(node->Left);
				if (node->Right)
					q.push(node->Right);
			}

			cout << endl;
		}
	}

	bool searchRecursive(TreeNode* currNode, int Value)
	{
		if (currNode == nullptr)
			return false;
		else if (currNode->Data == Value)
			return true;
		else if (Value < currNode->Data)
			searchRecursive(currNode->Left, Value);
		else
			searchRecursive(currNode->Right, Value);
	}

	int countNodesRecursive(TreeNode* currNode)
	{
		if (currNode == nullptr)
			return 0;
		return 1 + countNodesRecursive(currNode->Left) + countNodesRecursive(currNode->Right);
	}

	int leafCountRecursive(TreeNode* currNode)
	{
		if (currNode == nullptr)
			return 0;
		if (currNode->Left == nullptr && currNode->Right == nullptr)
			return 1;
		return leafCountRecursive(currNode->Left) + leafCountRecursive(currNode->Right);
	}

	void DeleteTree(TreeNode* node)
	{
		if (node != nullptr)
		{
			DeleteTree(node->Left);
			DeleteTree(node->Right);
			delete node;
		}
	}

	void Ancestor(int Value, vector<TreeNode*>& Ancestors, TreeNode* CurrNode)
	{
		if (Value == CurrNode->Data)
			return;
		else if (Value < CurrNode->Data)
		{
			Ancestors.push_back(CurrNode);
			Ancestor(Value, Ancestors, CurrNode->Left);
		}
		else if (Value > CurrNode->Data)
		{
			Ancestors.push_back(CurrNode);
			Ancestor(Value, Ancestors, CurrNode->Right);
		}
	}

	void findPatternRecursive1(TreeNode* currNode, int* seq, int seqSize, int& seqIndex, bool& Check)
	{
		if (currNode != nullptr)
		{
			findPatternRecursive1(currNode->Left, seq, seqSize, seqIndex, Check);

			if (currNode->Data == seq[seqIndex])
				seqIndex++;
			else
				seqIndex = 0;

			if (seqIndex == seqSize)
				Check = true;

			findPatternRecursive1(currNode->Right, seq, seqSize, seqIndex, Check);
		}
	}

	void collectData(TreeNode* currNode, vector<int>& TreeData)
	{
		if (currNode != nullptr)
		{
			collectData(currNode->Left, TreeData);
			TreeData.push_back(currNode->Data);
			collectData(currNode->Right, TreeData);
		}
	}

	bool findPatternRecursive2(vector<int> TreeData, int TreeSize, int TreeIndex, int* seq, int seqSize, int seqIndex)
	{
		if (seqIndex == seqSize)
			return true;
		if (TreeIndex == TreeSize)
			return false;

		if (TreeData[TreeIndex] == seq[seqIndex])
		{
			TreeIndex++;
			seqIndex++;
			return findPatternRecursive2(TreeData, TreeData.size(), TreeIndex, seq, seqSize, seqIndex);
		}
		else
		{
			TreeIndex++;
			seqIndex = 0;
			return findPatternRecursive2(TreeData, TreeData.size(), TreeIndex, seq, seqSize, seqIndex);
		}
	}

public:
	BST()
	{
		Root = nullptr;
	}

	void Insert(int Value)
	{
		TreeNode* newNode = new TreeNode;
		newNode->Data = Value;
		newNode->Left = newNode->Right = nullptr;

		insertRecursive(Root, newNode);
	}

	void inOrder()
	{
		inOrderRecursive(Root);
	}

	void preOrder()
	{
		preOrderRecursive(Root);
	}

	void postOrder()
	{
		postOrderRecursive(Root);
	}

	void levelorderPrint()
	{
		levelorderPrintHelper(Root);
	}

	void Search(int Value)
	{
		if (Root == nullptr)
			cout << "TREE is Empty!" << endl;
		else if (searchRecursive(Root, Value) == true)
			cout << "Value " << Value << " Founded!" << endl;
		else
			cout << "Value " << Value << " not Found!" << endl;
	}

	int countNodes()
	{
		return countNodesRecursive(Root);
	}

	int leafCount()
	{
		return leafCountRecursive(Root);
	}

	int Minimum()
	{
		if (Root == nullptr)
		{
			cout << "TREE is Empty!" << endl;
			return -1;
		}

		TreeNode* currNode = Root;
		while (currNode->Left != nullptr)
		{
			currNode = currNode->Left;
		}

		return currNode->Data;
	}

	int Maximum()
	{
		if (Root == nullptr)
		{
			cout << "TREE is Empty!" << endl;
			return -1;
		}

		TreeNode* currNode = Root;
		while (currNode->Right != nullptr)
		{
			currNode = currNode->Right;
		}

		return currNode->Data;
	}

	bool Remove(int Value)
	{
		TreeNode* currNode = Root, * Parent = nullptr;

		while (currNode != nullptr && currNode->Data != Value)
		{
			Parent = currNode;
			if (Value < currNode->Data)
				currNode = currNode->Left;
			else
				currNode = currNode->Right;
		}

		if (currNode == nullptr)
			return false;
		else
		{
			if (currNode->Left != nullptr && currNode->Right != nullptr)
			{
				TreeNode* l = currNode->Left, * parentLeft = currNode;

				while (l->Right != nullptr)
				{
					parentLeft = l;
					l = l->Right;
				}

				currNode->Data = l->Data;
				currNode = l;
				Parent = parentLeft;
			}

			TreeNode* Child;

			if (currNode->Left != nullptr)
				Child = currNode->Left;
			else
				Child = currNode->Right;

			if (currNode == Root)
				Root = Child;
			else
			{
				if (currNode == Parent->Left)
					Parent->Left = Child;
				else
					Parent->Right = Child;
			}
		}

		delete currNode;
		currNode = nullptr;
		return true;
	}

	~BST()
	{
		DeleteTree(Root);
	}

	void commonAncestor(int X, int Y)
	{
		vector<TreeNode*> X_Ancestors;
		vector<TreeNode*> Y_Ancestors;

		Ancestor(X, X_Ancestors, Root);
		Ancestor(Y, Y_Ancestors, Root);

		int size = min(X_Ancestors.size(), Y_Ancestors.size());
		stack<TreeNode*> S;

		for (int i = 0; i < size; i++)
		{
			if (X_Ancestors[i]->Data == Y_Ancestors[i]->Data)
				S.push(X_Ancestors[i]);
		}

		size = S.size();

		for (int i = 1; i <= size; i++)
		{
			TreeNode* Value = S.top();
			cout << Value->Data << " ";
			S.pop();
		}
	}

	bool findpattern1(int* seq, int seqSize, int seqIndex)
	{
		bool Check = false;
		findPatternRecursive1(Root, seq, seqSize, seqIndex, Check);
		return Check;
	}

	bool findpattern2(int* seq, int seqSize, int seqIndex)
	{
		vector<int> TreeData;
		collectData(Root, TreeData);

		int TreeIndex = 0;
		bool Check = findPatternRecursive2(TreeData, TreeData.size(), TreeIndex, seq, seqSize, seqIndex);
		return Check;
	}

	void NodesSum(TreeNode* Curr, int& Sum)
	{
		if (Curr != nullptr)
		{
			Sum += Curr->Data;
			NodesSum(Curr->Left, Sum);
			NodesSum(Curr->Right, Sum);
		}
	}

	void isDifferenceBST(TreeNode* Curr, bool& Check)
	{
		if (Curr != nullptr && Check == true)
		{
			int Left_Sum = 0;
			NodesSum(Curr->Left, Left_Sum);
			int Right_Sum = 0;
			NodesSum(Curr->Right, Right_Sum);

			if ((Left_Sum - Right_Sum) == Curr->Data)
				Check = true;
			else
				Check = false;

			isDifferenceBST(Curr->Left, Check);
			isDifferenceBST(Curr->Right, Check);
		}
	}

	void isDifferenceBST(bool& Check)
	{
		isDifferenceBST1(Root, Check)
	}
};

void main()
{
	BST Tree;
	Tree.Insert(18);
	Tree.Insert(10);
	Tree.Insert(5);
	Tree.Insert(20);
	Tree.Insert(10);
	Tree.Insert(11);
	Tree.Insert(6);

	bool Check;
	Tree.isDifferenceBST1(Check);
	cout << Check;

}