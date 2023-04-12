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

bool color[1002][1002];
int arr[100005];
vector<int>g[100005];
int res[100005];
bool cl[100005];

void rec(int l, int r, ll k, int y)
{
	if (!color[r][l])
		res[k]++;
	color[l][r] = color[r][l] = 1;
	for (int i = 0; i < g[r].size(); i++)
	{
		if (g[r][i] != y)
		{
			rec(l, g[r][i], k + 1, r);
		}
	}
}
void solve()
{
	int n, i, j, k;
	cin >> n;
	bool bb = true;
	for (i = 0; i < n - 1; i++)
	{
		cin >> arr[i + 1];
		if (arr[i + 1] != 1)
			bb = false;
		arr[i + 1]--;
		g[i + 1].push_back(arr[i + 1]);
		g[arr[i + 1]].push_back(i + 1);
	}
	if (bb)
	{

		if (n == 1)
		{
			cout << 1;
		}
		else if (n == 2)
		{
			cout << 2 << ' ' << 1;
		}
		else
		{
			ll ui = ((n - 1) * (n - 2));
			ui /= 2;
			cout << n << ' ' << n - 1 << ' ' << ui << ' ';
			for (i = 3; i < n; i++)
			{
				cout << 0;
				if (i != n - 1)
					cout << ' ';
			}
		}
		return;
	}
	for (i = 0; i < n; i++)
	{
		rec(i, i, 1, -1);
	}
	for (i = 1; i <= n; i++)
	{
		cout << res[i] << ' ';
	}
}

int main()
{
	speed;
	solve();

	return 0;
}