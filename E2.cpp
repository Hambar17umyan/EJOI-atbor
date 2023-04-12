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

pair<int, int>arr[100005];
int v[100000008];
void solve()
{
	int n, i, j, m, l, k;
	cin >> l >> n >> m;
	for (i = 0; i < n; i++)
	{
		bool b;
		cin >> k >> b;
		v[k - 1] = 1;
		if (b)
			v[k - 1] = 2;
		arr[i] = make_pair(k - 1, v[k - 1]);
	}
	while (m--)
	{
		int s, e;
		bool vc;
		cin >> s >> vc >> e;
		s--;
		e--;
		k = 0;
		while (true)
		{
			if (s >= l || s < 0)
			{
				cout << -1 << endl;
				break;
			}
			if (s == e)
			{
				cout << k << endl;
				break;
			}
			if (vc)
			{
				if (v[s] == 2)
				{
					v[s] = 1;
					s--;
					k++;
					vc = 0;
				}
				else if (v[s] == 1)
				{
					v[s] = 2;
					s++;
					k++;
				}
				else
				{
					k++;
					s++;
				}
			}
			else
			{
				if (v[s] == 2)
				{
					v[s] = 1;
					s++;
					k++;
					vc = 1;
				}
				else if (v[s] == 1)
				{
					v[s] = 2;
					s--;
					k++;
				}
				else
				{
					k++;
					s--;
				}
			}
		}
		for (i = 0; i < n; i++)
		{
			v[arr[i].first] = arr[i].second;
		}
	}
}

int main()
{
	speed;
	solve();

	return 0;
}