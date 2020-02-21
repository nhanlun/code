#include <bits/stdc++.h>

using namespace std;

struct Node
{
	Node *pLeft, *pRight, *pMid;
	int val1, val2;
	Node()
	{
		pLeft = pRight = pMid = nullptr;
		val1 = val2 = -1;
	}
	~Node()
	{
		delete pLeft;
		delete pMid;
		delete pRight;
	}
};

bool TheRealInsert(Node* &root, int x, Node* &leftChild, Node* &rightChild, int &overload)
{
	if (root == nullptr) 
	{
		overload = x;
		return true;
	}
	if (root->val1 == x || root->val2 == x) return false;

	int numVal = (root->val1 != -1) + (root->val2 != -1);
	bool tmp = false;
	if (numVal == 1)
	{
		if (root->val1 > x) tmp = TheRealInsert(root->pLeft, x, leftChild, rightChild, overload);
		else tmp = TheRealInsert(root->pRight, x, leftChild, rightChild, overload);

		if (tmp)
		{
			root->pMid = rightChild;
			if (root->val1 < x) swap(root->pMid, root->pRight);
			root->val2 = overload;
			if (root->val1 > root->val2) swap(root->val1, root->val2);
		}

		overload = -1;
		leftChild = rightChild = nullptr;
		return false;
	}
	else
	{
		if (root->val1 > x) tmp = TheRealInsert(root->pLeft, x, leftChild, rightChild, overload);
		else if (root->val2 < x) tmp = TheRealInsert(root->pRight, x, leftChild, rightChild, overload);
		else tmp = TheRealInsert(root->pMid, x, leftChild, rightChild, overload);

		if (tmp)
		{
			Node* tmpp = new Node();
			if (root->val1 > x)
			{
				tmpp->pLeft = root->pMid;
				tmpp->pRight = root->pRight;
				tmpp->val1 = root->val2;
				root->pRight = rightChild;
				swap(root->val1, overload);
			}
			else if (root->val2 < x)
			{
				tmpp->pLeft = root->pRight;
				tmpp->pRight = rightChild;
				tmpp->val1 = overload;
				root->pRight = root->pMid;
				swap(overload, root->val2);
			}
			else
			{
				tmpp->pLeft = rightChild;
				tmpp->pRight = root->pRight;
				tmpp->val1 = root->val2;
				root->pRight = root->pMid;
			}

			root->val2 = -1;
			root->pMid = nullptr;
			leftChild = root;
			rightChild = tmpp;
			return true;
		}
		return false;
	}
}

void Insert(Node* &root, int x)
{
	Node* tmp1 = nullptr;
	Node* tmp2 = nullptr;
	int tmp = -1;
	bool overload = TheRealInsert(root, x, tmp1, tmp2, tmp);
	if (overload)
	{
		root = new Node();
		root->pLeft = tmp1;
		root->pRight = tmp2;
		root->val1 = tmp;
	}
}

void Draw(Node* root, int level, bool* yolo, int type)
{
	for (int i = 0; i < level - 1; ++i) if (yolo[i]) cout << "|  "; else cout << "   ";
	if (type == 1) cout << "\\-";
	else if (type == 2) cout << "|-";
	cout << root->val1 << ' ';
	if (root->val2 != -1) cout << root->val2 << '\n'; else cout << '\n';

	int numChild = (root->pLeft != nullptr) + (root->pRight != nullptr) + (root->pMid != nullptr);
	numChild = min(numChild, 2);
	if (root->pLeft != nullptr)
	{
		yolo[level] = true;
		Draw(root->pLeft, level + 1, yolo, numChild);
		yolo[level] = false;
	}
	if (root->pMid != nullptr)
	{
		yolo[level] = true;
		Draw(root->pMid, level + 1, yolo, numChild);
		yolo[level] = false;
	}
	if (root->pRight != nullptr) Draw(root->pRight, level + 1, yolo, 1);
}

void PrintInorder(Node* root)
{
	if (root == nullptr) return;
	PrintInorder(root->pLeft);
	cout << root->val1 << ' ';
	PrintInorder(root->pMid);
	if (root->val2 != -1) cout << root->val2 << ' ';
	PrintInorder(root->pRight);
}

int main()
{
	int x;
	Node* root = nullptr;
	while (cin >> x && x != 0) Insert(root, x);

	PrintInorder(root);
	// bool* yolo = new bool[100];
	// Draw(root, 0, yolo, 0);

	// delete[] yolo;
	delete root;
	return 0;
}