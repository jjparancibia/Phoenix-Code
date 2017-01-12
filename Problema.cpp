#include<iostream>
#include<cmath>
using namespace std;
void hallar_primos(vector<int> &v)
{
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    bool ans;
    for(int i = 6 ; i < 100000 ; i++)
    {
        ans = true;
        for(unsigned int j = 0 ; j < v.size() ; j++)
            if(i%v[j]==0)
            {
                ans = false;
                break;
            }
        if(ans)
            v.push_back(i);
    }
}
int main()
{
    vector<int> primos;
    hallar_primos(primos);
    return 0;
}
