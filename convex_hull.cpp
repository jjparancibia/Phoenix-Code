#include<iostream>
#include<vector>
#include<cmath>
#include<utility>
#include<algorithm>
using namespace std;
bool relation(pair<pair<double,double>,double> i , pair<pair<double,double>,double> j)
{
    return (i.second < j.second);
}

void convex(vector< pair< pair<double,double>,double> > &p)
{
    for(unsigned int i = 1 ; i < p.size() ; i++)
    {
        if(((p[i].first.first-p[i-1].first.first)*(p[i+1].first.second-p[i].first.second)-(p[i].first.second-p[i-1].first.second)*(p[i+1].first.first-p[i].first.first)) < 0)
        {
            p.erase(p.begin()+i);
            i--;
        }
    }
}

int main()
{
    int n;  cin >> n;
    vector< pair< pair<double,double>,double> > points(n);
    int lower = 0;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> points[i].first.first >> points[i].first.second; //(x,y)
        points[i].second = 0.0;
        if(points[i].first.second < points[lower].first.second)
            lower = i;
        else if(points[i].first.second == points[lower].first.second)
            if(points[i].first.first < points[lower].first.first)
                lower = i;
    }
    for(int i = 0 ; i < n ; i++)
        if(i != lower)
            points[i].second = acos((points[i].first.first-points[lower].first.first)/sqrt(pow(points[i].first.first-points[lower].first.first,2)+pow(points[i].first.second-points[lower].first.second,2)));

    sort(points.begin(),points.end(),relation);
    cout << endl;
    cout << "x\ty\tangle\n";
    for(unsigned int i = 0 ; i < points.size() ; i++)
        cout << points[i].first.first << "\t" << points[i].first.second << "\t" << points[i].second << endl;

    points.push_back(make_pair(make_pair(points[0].first.first,points[0].first.second),points[0].second));

    convex(points);
    cout << endl;
    cout << "x\ty\tangle\n";
    for(unsigned int i = 0 ; i < points.size() ; i++)
        cout << points[i].first.first << "\t" << points[i].first.second << "\t" << points[i].second << endl;

    return 0;
}
