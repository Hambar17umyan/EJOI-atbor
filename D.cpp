#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#pragma warning(disable : 4996)
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

const int N = 102;
ll arr[N][N][N];
ll l[N][N][N], r[N][N][N], f[N][N][N], b[N][N][N];
void solve()
{
	int n, i, j, m;
	cin >> n >> m;
	scanf("%i", n);
	scanf("%i", m);
	while (m--)
	{
		int op;
		scanf("%i", op);
		if (op == 2)
		{
			string s;
			scanf("%s", s);
			if (s == "front")
			{
				for (i = 0; i < n; i++)
				{
					for (j = 0; j < n; j++)
					{
						cout << f[i][j][0] << ' ';
					}
					cout << '\n';
				}
			}
			else if (s == "left")
			{
				for (i = 0; i < n; i++)
				{
					for (j = n - 1; j >= 0; j--)
					{
						cout << l[i][0][j] << ' ';
					}
					cout << '\n';
				}
			}
			else if (s == "right")
			{
				for (i = 0; i < n; i++)
				{
					for (j = 0; j < n; j++)
					{
						cout << r[i][n - 1][j] << ' ';
					}
					cout << endl;
				}
			}
			else
			{
				for (i = 0; i < n; i++)
				{
					for (j = n - 1; j >= 0; j--)
					{
						cout << b[i][j][n - 1] << ' ';
					}
					cout << endl;
				}
			}
		}
		else
		{
			int x, y, z;
			ll k;
			scanf("%i", x);
			scanf("%i", y);
			scanf("%i", z);
			scanf("%lli", k);
			x--;
			y--;
			z--;
			arr[x][y][z] = k;
			l[x][y][z] = r[x][y][z] = b[x][y][z] = f[x][y][z] = k;
			for (i = z - 1; i >= 0; i--)
			{
				if (arr[x][y][i] == 0)
				{
					f[x][y][i] = k;
				}
				else break;
			}
			for (i = z + 1; i < n; i++)
			{
				if (arr[x][y][i] == 0)
				{
					b[x][y][i] = k;
				}
				else break;
			}

			for (i = y - 1; i >= 0; i--)
			{
				if (arr[x][i][z] == 0)
				{
					l[x][i][z] = k;
				}
				else break;
			}
			for (i = y + 1; i < n; i++)
			{
				if (arr[x][i][z] == 0)
				{
					r[x][i][z] = k;
				}
				else break;
			}

			/*for (i = x - 1; i >= 0; i--)
			{
				if (arr[i][y][z] == 0)
				{
					res[i][y][z] = k;
				}
				else break;
			}
			for (i = x + 1; i < n; i++)
			{
				if (arr[i][y][z] == 0)
				{
					res[i][y][z] = k;
				}
				else break;
			}*/
		}
	}
}

int main()
{
	speed;
	solve();

	return 0;
}