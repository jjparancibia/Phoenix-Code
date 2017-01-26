#include<iostream>
#include<climits>
#include<vector>
#include<cmath>
#include<utility>
#include<algorithm>
using namespace std;
void ordenar(vector< pair<int,int> > &p, vector<double> &a)
{
    double temp;
    pair<int,int> t;
    for(unsigned int i = 0 ; i < a.size() ;i++)
    {
        for(unsigned int j = 0 ; j < a.size() ;j++)
        {
            if(a[i]<a[j])
            {
                temp = a[i]; t = p[i];
                a[i] = a[j]; p[i] = p[j];
                a[j] = temp; p[j] = t;
            }
        }
    }
}
void envolvente(vector< pair<int,int> > &p, vector<double> &a)
{
    for(unsigned int i = 1 ; i < p.size() ; i++)
    {
        if(((p[i].first-p[i-1].first)*(p[i+1].second-p[i].second)-(p[i].second-p[i-1].second)*(p[i+1].first-p[i].first)) < 0)
        {
            p.erase(p.begin()+i);
            a.erase(a.begin()+i);
            i--;
        }
    }
}
int main()
{
    int n;  cin >> n;
    vector< pair<int,int> > puntos(n);
    vector<double> angulos(n,0.0);
    int men = 0;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> puntos[i].first;
        cin >> puntos[i].second;
        if(puntos[i].second < puntos[men].second)
            men = i;
        else if(puntos[i].second == puntos[men].second)
            if(puntos[i].first < puntos[men].first)
               men = i;
    }
    for(int i = 0 ; i < n ; i++)
        if(i != men)
            angulos[i] = acos((puntos[i].first-puntos[men].first)/sqrt(pow(puntos[i].first-puntos[men].first,2)+pow(puntos[i].second-puntos[men].second,2)));

    ordenar(puntos,angulos);
    envolvente(puntos,angulos);

    for(unsigned int i = 0 ; i < puntos.size() ; i++)
    {
        cout << puntos[i].first << " ";
        cout << puntos[i].second << " ";
        cout << angulos[i] << endl;
    }
    return 0;
}
