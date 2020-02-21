#include <bits/stdc++.h>

using namespace std;
const int N = 105;
const double eps = 1e-7;
double a[N][N];
int m, n;

bool CompareWithZero(double & x) //because of floating point error
{
	if (abs(x) > eps) return false;
	return true;
}

void SwapRow(double a[][N], int & x, int & y, int & n)
{
	for (int i = 0; i < n; ++i) swap(a[x][i], a[y][i]);
}

void MulRow(double a[][N], int & x, int & n, double & val)
{
	for (int i = 0; i < n; ++i) a[x][i] *= val;
}

void AddRow(double a[][N], int & x, int & y, int & n, double & coef) // row[x] + row[y] * coef
{
	for (int i = 0; i < n; ++i) a[x][i] += a[y][i] * coef;
}

bool Empty(double a[][N], int & x, int & n)
{
	for (int i = 0; i < n; ++i) if (a[x][i] != 0.0) return false;
	return true;
}

int PivotRow(double a[][N], int & x, int & n)
{
	for (int i = 0; i < n; ++i) if (!CompareWithZero(a[x][i])) return i;
	return -1;
}

int PivotCol(double a[][N], int & m, int & n, int & cur)
{
	int pos = long(1e9);
	for (int i = cur; i < m; ++i) 
	{
		int tmp = PivotRow(a, i, n);
		if (tmp != -1) pos = min(pos, tmp);
	}
	if (pos == long(1e9)) pos = -1;
	return pos;
}

void SortRow(double a[][N], int & m, int & n, int & cur)
{
	int pos = PivotCol(a, m, n, cur);
	if (pos == -1) return;
	for (int i = cur; i < m; ++i) if (PivotRow(a, i, n) == pos) 
	{
		SwapRow(a, cur, i, n);
		break;
	}

	for (int i = 0; i < m; ++i) if (Empty(a, i, n))
	{
		bool found = false;
		for (int j = i + 1; j < m; ++j) if (!Empty(a, j, n)) 
		{
			SwapRow(a, i, j, n);
			found = true;
			break;
		}
		if (!found) break;
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> m >> n;
	for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
	for (int i = 0; i < m; ++i)
	{
		SortRow(a, m, n, i);
		int pos = PivotRow(a, i, n);
		if (pos == -1) break;

		double tmp = 1 / a[i][pos];
		MulRow(a, i, n, tmp);

		for (int j = 0; j < m; ++j) if (i != j && !CompareWithZero(a[j][pos])) 
		{
			double tmp = - a[j][pos] / a[i][pos];
			AddRow(a, j, i, n, tmp);
		}

	}

	cout << fixed << setprecision(3);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (CompareWithZero(a[i][j])) a[i][j] = 0;
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';

	return 0;
}