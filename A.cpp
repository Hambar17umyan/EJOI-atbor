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
#define _CRT
using namespace std;

#define ll long long
#define usg unsigned
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define commadig(x) cout << fixed << setprecision(x);

const int N = 505;
ll arr[N][N];
ll res[N][N];

void solve()
{
	int n, i, j, m;
	scanf("%i", n);
	cin >> n >> m;
	ll k = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++, k++)
		{
			cin >> arr[i][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		res[i][i] = arr[i][i];
	}
	for (i = 0; i < n; i++)
	{
		ll l = arr[i][i];
		for (j = i + 1; j < n; j++)
		{
			for (k = i; k < j; k++)
			{
				l = max(l, arr[j][k]);
				l = max(l, arr[k][j]);
			}
			l = max(arr[j][j], l);
			res[i][j] = l;
		}
	}
	while (m--)
	{
		ll o, p;
		cin >> o >> p;
		o--;
		p--;
		cout << res[o][p] << endl;
	}
}

int main()
{
	solve();

	return 0;
}