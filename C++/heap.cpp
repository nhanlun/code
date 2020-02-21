#include <iostream>

using namespace std;

void push(int* a, int& size, int& x)
{
	a[size] = x;
	int cur = size;
	while (cur > 0 && a[cur] > a[(cur - 1) >> 1]) 
	{
		swap(a[cur], a[(cur - 1) >> 1]);
		cur = (cur - 1) >> 1;
	}
	++size;
}

int pop(int* a, int& size)
{
	int res = a[0];
	--size;
	swap(a[0], a[size]);
	int cur = 0;
	while (((cur << 1) | 1) < size)
	{
		int tmp = (cur << 1) | 1;
		if (tmp < size - 1 && a[tmp + 1] > a[tmp]) ++tmp;
		if (a[cur] >= a[tmp]) break;
		swap(a[cur], a[tmp]);
		cur = tmp;
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	int size = 0;
	for (int i = 1; i <= n; ++i) 
	{
		int x;
		cin >> x;
		push(a, size, x);
	}
	// for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << '\n';
	for (int i = 1; i <= n; ++i) cout << pop(a, size) << ' ';

	delete[] a;
	return 0;
}