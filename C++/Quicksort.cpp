#include <bits/stdc++.h>

using namespace std;
const int N = 105;
int a[N];

void Sort(int* a, int l, int r)
{
	if (l >= r) return;
	int mid = a[(l + r) >> 1];
	int i = l;
	int j = r;
	while (i <= j)
	{
		while (i < r && a[i] < mid) ++i;
		while (j > l && a[j] > mid) --j;	
		if (i <= j) 
		{
			swap(a[i], a[j]);
			++i;
			--j;
		}
	}
	Sort(a, l, j);
	Sort(a, i, r);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	// Sort(a, 1, n);
	for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
	return 0;
}