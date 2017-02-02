#include<iostream>
#include<vector>

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
    int N, carga;
    int pagoTotal = 0;

    vector <int> costos(N);

    cin >> N >> carga;

    for ( int i = 0; i < N; i++ )
        cin >> costos[i];

    merge_sort( 0, N - 1, costos );

    for ( int i = 0; i < carga; i++ )
    {
        if ( costos[i] < 0 )
        {
            pagoTotal = pagoTotal + ( -1*costos[i] );
        }
        else
            i = carga;
    }

    cout << pagoTotal;

    return 0;
}
