#include <bits/stdc++.h>

using namespace std;

struct Node
{
	Node * pLeft;
	Node * pRight;
	int val, height;
	Node()
	{
		val = 0;
		height = 1;
		pLeft = pRight = nullptr;
	}
	Node(int x)
	{
		val = x;
		height = 1;
		pLeft = pRight = nullptr;
	}
	~Node()
	{
		delete pLeft;
		delete pRight;
	}
};

int GetHeight(Node * root)
{
	if (root == nullptr) return 0;
	return root -> height;
}

int CalcHeight(Node * root)
{
	int LeftHeight = GetHeight(root -> pLeft);
	int RightHeight = GetHeight(root -> pRight);
	return (1 + max(LeftHeight, RightHeight));
}

int CalcBalance(Node * root)
{
	int LeftHeight = GetHeight(root -> pLeft);
	int RightHeight = GetHeight(root -> pRight);
	return LeftHeight - RightHeight;
}

void RightRotate(Node* &root)
{
	Node* tmp1 = root->pLeft;
	Node* tmp2 = tmp1->pRight;

	root->pLeft = tmp2;
	tmp1->pRight = root;

	root->height = CalcHeight(root);
	tmp1->height = CalcHeight(tmp1);

	root = tmp1;
}

void LeftRotate(Node* &root)
{
	Node* tmp1 = root->pRight;
	Node* tmp2 = tmp1->pLeft;

	root->pRight = tmp2;
	tmp1->pLeft = root;

	root->height = CalcHeight(root);
	tmp1->height = CalcHeight(tmp1);

	root = tmp1;
}

void Insert(Node* &root, int x)
{
	if (root == nullptr)
	{
		root = new Node(x);
		return;
	}
	if (root->val > x) Insert(root->pLeft, x);
	else if (root->val < x) Insert(root->pRight, x);
	else return;
	root->height = CalcHeight(root);
	int balanceFactor = CalcBalance(root);

	// Left Left case
	if (balanceFactor > 1 && x < root->pLeft->val) RightRotate(root);
	// Left Right case
	if (balanceFactor > 1 && x > root->pLeft->val)
	{
		LeftRotate(root->pLeft);
		RightRotate(root);
	}
	// Right Right case
	if (balanceFactor < -1 && x > root->pRight->val) LeftRotate(root);
	// Right Left case
	if (balanceFactor < -1 && x < root->pRight->val) 
	{
		RightRotate(root->pRight);
		LeftRotate(root);
	}
}

void Draw(Node * root, int cur, bool * yolo, int type)
{
	for (int i = 0; i < cur - 1; ++i) if (yolo[i]) cout << "|  "; else cout << "   ";
	if (type == 2) cout << "|-";
	else if (type == 1) cout << "\\-";
	cout << root -> val << '\n';

	int numChild = (root -> pLeft != nullptr) + (root -> pRight != nullptr);
	if (root -> pLeft != nullptr) 
	{
		if (numChild == 2) yolo[cur] = true; 
		else yolo[cur] = false;
		Draw(root -> pLeft, cur + 1, yolo, numChild);
	}
	if (root -> pRight != nullptr)
	{
		yolo[cur] = false;
		Draw(root -> pRight, cur + 1, yolo, 1);
	}
	yolo[cur] = false;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	Node * root = nullptr;
	int x;
	while (cin >> x && x != 0) Insert(root, x);
	
	bool* yolo = new bool[100];
	Draw(root, 0, yolo, 0);

	delete[] yolo;
	delete root;

	return 0;
}