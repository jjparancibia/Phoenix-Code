#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;
int main()
{
    ofstream archivo;
    archivo.open("in.txt");
    int n = 100000;
    //int n = rand()%100000+1;
    archivo << n << endl;
    for(int i = 0 ; i < n ; i++)
        archivo << rand()%100000+1 << " ";
    archivo.close();
    return 0;
}
