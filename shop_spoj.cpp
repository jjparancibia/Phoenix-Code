//http://www.spoj.com/problems/SHOP/

#include<iostream>
#include<vector>
#include<climits>
#define INF INT_MAX
using namespace std;
vector< vector<char> > shop;
vector< vector<int> > times;
int val;
void find(int x, int y)
{
	val++;
	if(y+1 < shop[0].size() && shop[x][y+1] != 'X')
		if(times[x][y+1] > times[x][y] + shop[x][y+1] - 48)
		{
			times[x][y+1] = times[x][y] + shop[x][y+1] - 48;
			find(x,y+1);
		}
	if(x+1 < shop.size() && shop[x+1][y] != 'X')
		if(times[x+1][y] > times[x][y] + shop[x+1][y] - 48)
		{
			times[x+1][y] = times[x][y] + shop[x+1][y] - 48;
			find(x+1,y);
		}
	if(y > 0 && shop[x][y-1] != 'X')
		if(times[x][y-1] > times[x][y] + shop[x][y-1] - 48)
		{
			times[x][y-1] = times[x][y] + shop[x][y-1] - 48;
			find(x,y-1);
		}
	if(x > 0 && shop[x-1][y] != 'X')
		if(times[x-1][y] > times[x][y] + shop[x-1][y] - 48)
		{
			times[x-1][y] = times[x][y] + shop[x-1][y] - 48;
			find(x-1,y);
		}
}
int main()
{
	int m, n, i_s, j_s, i_d, j_d;
	while(1)
	{
		cin >> m >> n;
		if(m == 0 && n == 0)	break;
		val = 0;
		shop.resize(n,vector<char>(m));
		times.resize(n,vector<int>(m,INF));
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < m ; j++)
			{
				cin >> shop[i][j];
				if(shop[i][j] == 'S'){  i_s = i;  j_s = j;  }	
				else if(shop[i][j] == 'D'){  i_d = i;  j_d = j;  }
			}

		times[i_s][j_s] = 0;
		shop[i_d][j_d] = '0';
		find(i_s,j_s);
		cout << times[i_d][j_d] << endl;
		cout << val << endl;
		shop.clear();
		times.clear();
	}
	return 0;
}
