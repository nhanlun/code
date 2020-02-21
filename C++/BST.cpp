#include <bits/stdc++.h>

#define ll long long 
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define sz(x) (int(x.size()))
#define DEBUG(x) { cerr << #x << " = " << x << '\n'; }

using namespace std;
const int N = 505;

struct Node
{
	int val;
	Node * pLeft;
	Node * pRight;
	~Node()
	{
		delete pLeft;
		delete pRight;
		// cerr << "deleted" << '\n';
	}
	Node()
	{
		pLeft = pRight = nullptr;
	}
	Node(int x) : val(x)
	{
		pLeft = pRight = nullptr;
	}
};

void InsertTree(Node *& root, int x)
{
	if (root == nullptr) 
	{
		root = new Node(x);
		return;
	}
	if (x < root -> val) InsertTree(root -> pLeft, x);
	else if (x > root -> val) InsertTree(root -> pRight, x);
}

Node * Search(Node * root, int x)
{
	if (root == nullptr) return nullptr;
	if (root -> val == x) return root;
	else if (x < root -> val) return Search(root -> pLeft, x);
	else return Search(root -> pRight, x);
}

void PrintInorder(Node * root)
{
	if (root == nullptr) return;
	PrintInorder(root -> pLeft);
	cout << root -> val << ' ';
	PrintInorder(root -> pRight);
}

void PrintPreorder(Node * root)
{
	if (root == nullptr) return;
	cout << root -> val << ' ';
	PrintPreorder(root -> pLeft);
	PrintPreorder(root -> pRight);
}

void PrintPostorder(Node * root)
{
	if (root == nullptr) return;
	PrintPostorder(root -> pLeft);
	PrintPostorder(root -> pRight);
	cout << root -> val << ' ';
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

void print_XY(Node* root, int x, int y)
{
	if (root == nullptr) return;
	if (root->val >= x && root->val <= y) 
	{
		print_XY(root->pLeft, x, y);
		cout << root->val << ' ';
		print_XY(root->pRight, x, y);
	}
	else if (root->val > y) print_XY(root->pLeft, x, y);
	else print_XY(root->pRight, x, y);
}

void print_level(Node* root, int cur, int level)
{
	if (root == nullptr) return;
	if (cur == level) 
	{
		cout << root->val << ' ';
		return;
	}
	print_level(root->pLeft, cur + 1, level);
	print_level(root->pRight, cur + 1, level);
}

void print_same_level(Node* root, int x)
{
	if (root == nullptr) return;
	Node* cur = root;
	int level = 0;
	while (cur != nullptr && cur->val != x)
	{
		++level;
		if (cur->val > x) cur = cur->pLeft;
		else cur = cur->pRight;
	}
	if (cur == nullptr) return;
	print_level(root, 0, level);
}

void print_LCA(Node* root, int x, int y)
{
	if (root == nullptr) return;
	auto tmp1 = Search(root, x);
	auto tmp2 = Search(root, y);
	if (tmp1 == nullptr || tmp2 == nullptr) return;
	Node* cur = root;
	while (cur != nullptr)
	{
		if (x <= cur->val && y >= cur->val) 
		{
			cout << cur->val;
			return;
		} 
		else if (x < cur->val && y < cur->val) cur = cur->pLeft;
		else cur = cur->pRight;
	}
}

void print_leaf(Node* root)
{
	if (root == nullptr) return;
	if (root->pLeft == nullptr && root->pRight == nullptr) cout << root->val << ' ';
	print_leaf(root->pLeft);
	print_leaf(root->pRight);
}

void RemoveNode(Node* root, int x)
{
	if (root == nullptr) return;
	Node* cur = root;
	Node* par = nullptr;
	while (cur != nullptr && cur->val != x)
	{
		par = cur;
		if (cur->val > x) cur = cur->pLeft;
		else cur = cur->pRight;
	}
	if (cur == nullptr) return;
	if (cur->pRight == nullptr)
	{
		if (par == nullptr) root = cur->pLeft;
		else if (par->pLeft == cur) par->pLeft = cur->pLeft;
		else par->pRight = cur->pLeft;
		cur->pLeft = cur->pRight = nullptr;
		delete cur;
	}
	else
	{
		Node* tmp = cur->pRight;
		par = cur;
		while (tmp->pLeft != nullptr) 
		{
			par = tmp;
			tmp = tmp->pLeft;
		}
		swap(tmp->val, cur->val);
		if (par == cur) par->pRight = tmp->pRight;
		else par->pLeft = tmp->pRight;
		tmp->pLeft = tmp->pRight = nullptr;
		delete tmp;
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	Node * root = nullptr;
	int x;
	while (cin >> x && x != 0) InsertTree(root, x);

	// cout << Search(root, 10) << '\n';
	RemoveNode(root, 70);

	bool * yolo = new bool[100];
	Draw(root, 0, yolo, 0);

	delete[] yolo;
	// PrintInorder(root); cout << '\n';
	// PrintPreorder(root); cout << '\n';
	// PrintPostorder(root); cout << '\n';

	// print_XY(root, 13, 170); cout << '\n';
	// print_same_level(root, 45); cout << '\n';
	// print_LCA(root, 150, 300);
	// print_leaf(root);

	delete root;

	return 0;
}