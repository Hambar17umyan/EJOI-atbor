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

void solve()
{
	string s;
	cin >> s;
	int n = s.size();
	int i, j, k;
	set<ll>st;
	ll res = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n - 1; j++)
		{
			for (k = j + 1; k < n - 1; k++)
			{
				ll a, b, c, d;
				a = b = c = d = 0;
				if (s[0] == '0' && i != 0)
				{
					continue;
				}
				if (s[i + 1] == '0' && j != i + 1)
				{
					continue;
				}
				if (s[j + 1] == '0' && j + 1 != k)
				{
					continue;
				}
				if (s[k + 1] == '0' && k + 1 != n - 1)
				{
					continue;
				}
				for (int y = 0; y <= i; y++)
				{
					a *= 10;
					a += (s[y] - '0');
				}
				for (int y = i + 1; y <= j; y++)
				{
					b *= 10;
					b += (s[y] - '0');
				}
				for (int y = j + 1; y <= k; y++)
				{
					c *= 10;
					c += (s[y] - '0');
				}
				for (int y = k + 1; y <= n - 1; y++)
				{
					d *= 10;
					d += (s[y] - '0');
				}
				if (a + b - c * d >= 0)
					st.insert(a + b - c * d);
				if (a + b * c - d >= 0)
					st.insert(a + b * c - d);
				if (a - b + c * d >= 0)
					st.insert(a - b + c * d);
				if (a - b * c + d >= 0)
					st.insert(a - b * c + d);
				if (a * b - c + d >= 0)
					st.insert(a * b - c + d);
				if (a * b + c - d >= 0)
					st.insert(a * b + c - d);

			}
		}
	}

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n - 1; j++)
		{
			ll a, b, c, d;
			a = b = c = d = 0;
			if (s[0] == '0' && i != 0)
			{
				continue;
			}
			if (s[i + 1] == '0' && j != i + 1)
			{
				continue;
			}
			if (s[j + 1] == '0' && j + 1 != k)
			{
				continue;
			}
			for (int y = 0; y <= i; y++)
			{
				a *= 10;
				a += (s[y] - '0');
			}
			for (int y = i + 1; y <= j; y++)
			{
				b *= 10;
				b += (s[y] - '0');
			}
			for (int y = j + 1; y <= n - 1; y++)
			{
				c *= 10;
				c += (s[y] - '0');
			}
			if (a + b * c >= 0)
				st.insert(a + b * c);
			if (a + b - c >= 0)
				st.insert(a + b - c);
			if (a * b - c >= 0)
				st.insert(a * b - c);
			if (a * b + c >= 0)
				st.insert(a * b + c);
			if (a - b + c >= 0)
				st.insert(a - b + c);
			if (a - b * c >= 0)
				st.insert(a - b * c);
		}
	}

	for (i = 0; i < n - 1; i++)
	{
		ll a, b, c, d;
		a = b = c = d = 0;
		if (s[0] == '0' && i != 0)
		{
			continue;
		}
		if (s[i + 1] == '0' && n - 1 != i + 1)
		{
			continue;
		}
		for (int y = 0; y <= i; y++)
		{
			a *= 10;
			a += (s[y] - '0');
		}
		for (int y = i + 1; y <= n - 1; y++)
		{
			b *= 10;
			b += (s[y] - '0');
		}
		if (a + b >= 0)
			st.insert(a + b);
		if (a * b >= 0)
			st.insert(a * b);
		if (a - b >= 0)
			st.insert(a - b);
	}
	cout << st.size();
}

int main()
{
	solve();

	return 0;
}