#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main()
{
	int n, number,expected;
	vector<int> love_mobiles;
	stack<int> side_street;
	while(1)
	{
		cin >> n;
		if(n == 0)	break;
		expected = 1;
		for(int i = 0 ; i < n ; i++)
		{
			cin >> number;
			love_mobiles.insert(love_mobiles.begin(),number);
		}
		while(1)
		{
			if(!love_mobiles.empty() && love_mobiles.back() == expected)
			{
				expected++;
				love_mobiles.pop_back();
				continue;
			}
			else if(!side_street.empty() && side_street.top() == expected)
			{
				expected++;
				side_street.pop();
				continue;
			}
			else if(!love_mobiles.empty())
			{
				side_street.push(love_mobiles.back());
				love_mobiles.pop_back();
				continue;
			}
			break;
		}
		if(expected == n+1)	cout << "yes" << endl;
		else	cout << "no" << endl;
		while(!side_street.empty())	side_street.pop();
	}
	return 0;
}
