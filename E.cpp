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

map<int, pair<int, bool>>xch;

const int N = 200005;
int t1[4 * N], t2[4 * N], prr[N];
void build(int l, int r, int pos)
{
	if (l == r)
	{
		if (xch[r].second)
		{
			t1[pos] = t2[pos] = r + 1;
		}
		prr[l] = pos;
		return;
	}
	middle;
	build(l, mid, poss);
	build(midd, r, poss + 1);
	if (t1[poss] != 0)
	{
		t1[pos] = t1[poss];
	}
	else t1[pos] = t1[poss + 1];
	if (t2[poss + 1] != 0)
	{
		t2[pos] = t2[poss + 1];
	}
	else t2[pos] = t2[poss];
}

ll q1(int l, int r, int ql, int qr, int pos)
{
	if (l == ql && r == qr)
	{
		return t1[pos];
	}
	middle;
	if (qr <= mid)
		return q1(l, mid, ql, qr, poss);
	if (ql >= midd)
		return q1(midd, r, ql, qr, poss + 1);
	ll a = q1(l, mid, ql, mid, poss);
	if (a != 0)
		return a;
	return q1(midd, r, midd, qr, poss + 1);
}

ll q2(int l, int r, int ql, int qr, int pos)
{
	if (l == ql && r == qr)
	{
		return t2[pos];
	}
	middle;
	if (qr <= mid)
		return q2(l, mid, ql, qr, poss);
	if (ql >= midd)
		return q2(midd, r, ql, qr, poss + 1);
	ll a = q2(midd, r, midd, qr, poss + 1);
	if (a != 0)
		return a;
	return q2(l, mid, ql, mid, poss);
}

void update(int pos)
{
	t1[pos] = t2[pos] = 0;
	pos /= 2;
	while (pos >= 1)
	{
		if (t1[poss] != 0)
		{
			t1[pos] = t1[poss];
		}
		else t1[pos] = t1[poss + 1];
		if (t2[poss + 1] != 0)
		{
			t2[pos] = t2[poss + 1];
		}
		else t2[pos] = t2[poss];
	}
}

ll q(int s, bool v, int e, int n, int y)
{
	if (v) //right
	{
		ll u = q2(0, n - 1, xch[s].first + 1, n - 1, 1);
		if (u == 0)
		{
			return -1;
		}
		update(prr[u]);
		if (u - 1 >= e && s <= e)
		{
			return e - s + y;
		}
		else
			return q(u - 1, 0, e, n, y + u - s);
	}
	else
	{
		ll u = q1(0, n - 1, 0, xch[s].first - 1, 1);
		if (u == 0)
		{
			return -1;
		}
		update(prr[u]);
		if (u - 1 <= e && s >= e)
		{
			return s - e + y;
		}
		else
			return q(u - 1, 1, e, n, y + s - u);
	}
}
void solve()
{
	int n, m, l;
	cin >> l >> n >> m;
	set<int> st;
	for (int i = 0; i < n; i++)
	{
		int k;
		bool b;
		cin >> k >> b;
		k--;
		xch[k] = make_pair(0, b);
		if (b)
			st.insert(k);
	}
	int i = 0;
	for (map<int, pair<int, bool>>::iterator it = xch.begin(); it != xch.end(); it++, i++)
	{
		it->second.first = i;
	}
	build(0, n - 1, 1);
	while (m--)
	{
		int s, e;
		bool v;
		cin >> s >> v >> e;
		set<int>::iterator
	}
}

int main()
{
	speed;
	solve();

	return 0;
}