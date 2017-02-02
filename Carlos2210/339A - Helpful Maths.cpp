#include<iostream>
#include<vector>
#include<string>

using namespace std;

void merge_vector( int l, int p, int h, vector <int> &v )
{
    for( int i = p + 1; i < h + 1; i++ )
    {
        int key = i - 1, temp = v[i];

        while ( v[key] > temp && key >= l )
        {
            v[key + 1] = v[key];
            key--;
        }
        v[key + 1] = temp;
    }
}

void merge_sort( int low, int high, vector <int> &v )
{
    if ( low < high )
    {
        int pivot = ( low + high )/2;

        merge_sort( low, pivot, v );
        merge_sort( pivot + 1, high, v);
        merge_vector( low, pivot, high, v );
    }
}

int main()
{
    string cadena;
    vector <int> orden;

    cin >> cadena;

    for ( int i = 0; i <= cadena.size(); i+=2 )
        orden.push_back( cadena[i]-48 );

    merge_sort( 0, orden.size() - 1, orden );

    for ( int i = 0; i < orden.size() - 1; i++ )
        cout << orden[i] << "+";

    cout << orden[orden.size() - 1];

    return 0;
}
