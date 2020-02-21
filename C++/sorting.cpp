#include <bits/stdc++.h>

using namespace std;

void InsertionSort(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		int cur = a[i]; int j = i - 1;
		for (; j >= 0 && a[j] > cur; --j) 
			a[j + 1] = a[j];
		a[j + 1] = cur;
	}
}

void SelectionSort(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		int cur = i;
		for (int j = i + 1; j < n; ++j) if (a[j] < a[cur]) 
			cur = j;
		swap(a[cur], a[i]);
	}
}

void MergeSort(int* a, int n)
{
	if (n == 1) return;
	int mid = n / 2;
	int* Left = new int[mid];
	int* Right = new int[n - mid];
	for (int i = 0; i < mid; ++i) Left[i] = a[i];
	for (int i = mid; i < n; ++i) Right[i - mid] = a[i];

	MergeSort(Left, mid);
	MergeSort(Right, n - mid);

	int cur1 = 0, cur2 = 0, cur3 = 0;
	while (cur1 < mid && cur2 < n - mid)
	{
		if (Left[cur1] < Right[cur2])
			a[cur3] = Left[cur1++];
		else 
			a[cur3] = Right[cur2++];
		++cur3;
	}
	while (cur1 < mid)
		a[cur3++] = Left[cur1++];
	while (cur2 < n - mid)
		a[cur3++] = Right[cur2++];

	delete[] Left;
	delete[] Right;
}

int main()
{
	int n = 0;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	// InsertionSort(a, n);
	// SelectionSort(a, n);
	MergeSort(a, n);
	for (int i = 0; i < n; ++i) cout << a[i] << ' ';

	delete[] a;
	return 0;
}