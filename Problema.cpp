#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
void hallar_primos(vector< pair<int,int> > &v)
{
    v.push_back(make_pair(2,0));
    v.push_back(make_pair(3,0));
    v.push_back(make_pair(5,0));
    bool ans;
    for(int i = 6 ; i < 100000 ; i++)
    {
        ans = true;
        for(unsigned int j = 0 ; j < v.size() ; j++)
            if(i%v[j].first==0)
            {
                ans = false;
                break;
            }
        if(ans)
            v.push_back(make_pair(i,0));
    }
}
int main()
{
    vector< pair<int,int> > primos;
    hallar_primos(primos);
    int n; cin >> n;
    vector<int> values(n);
    int maximo = 0, i_max = 0;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> values[i];
        int k = 0;
        while(primos[k].first<=values[i])
        {
            if(values[i]%primos[k].first == 0)
            {
                primos[k].second++;
                if(primos[k].second>maximo)
                {
                    maximo = primos[k].second;
                    i_max = k;
                }
            }
            k++;
        }
    }
    cout << primos[i_max].second << endl;
    return 0;
}
