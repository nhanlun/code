#include <bits/stdc++.h>

using namespace std;

struct Node
{
	Node* pLeft;
	Node* pRight;
	bool color; // red = true, black = false
	Node()
	{
		
	}
};

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
	while (cin >> x && x != 0) root = Insert(root, x);
	
	bool* yolo = new bool[100];
	Draw(root, 0, yolo, 0);

	delete[] yolo;
	delete root;

	return 0;
}