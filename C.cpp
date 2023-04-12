#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <iterator>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
using namespace std;

#define ll long long
#define usg unsigned
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define commadig(x) cout << fixed << setprecision(x);

#define poss pos * 2
#define midd mid + 1
#define middle ll mid = (l + r) / 2

const int N = 100005;
int arr[N];
int prr[N];
int tree[4 * N];

void build(int l, int r, int pos)
{
	tree[pos] = 0;
	if (l == r)
	{
		prr[r] = pos;
		return;
	}
	middle;
	build(l, mid, poss);
	build(midd, r, poss + 1);
}

ll fsum(int l, int r, int ql, int qr, int pos)
{
	if (ql == l && qr == r)
	{
		return tree[pos];
	}
	middle;
	if (qr <= mid)
	{
		return fsum(l, mid, ql, qr, poss);
	}
	if (ql > mid)
	{
		return fsum(midd, r, ql, qr, poss + 1);
	}
	return fsum(l, mid, ql, mid, poss) + fsum(midd, r, midd, qr, poss + 1);
}

void update(int pos)
{
	while (pos >= 1)
	{
		tree[pos] += 1;
		pos /= 2;
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	while (m--)
	{
		build(0, n - 1, 1);
		int o, p;
		cin >> o >> p;
		int k = 0;
		for (int i = o - 1; i <= p - 1; i++)
		{
			k += fsum(0, n - 1, arr[i] - 1, n - 1, 1);
			update(prr[arr[i] - 1]);
			//cout << 'f' << endl;
		}
		cout << k << endl;
	}
}

int main()
{
	solve();

	return 0;
}