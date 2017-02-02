#include<iostream>

using namespace std;

void Duracion( int &mayor, int &menor, int &min )
{
    if ( menor > 2 || ( menor == 2 && mayor <= 2 ) )
    {
        mayor += 1;
        menor -= 2;
        min++;

        Duracion( mayor, menor, min );
    }

        else if ( 0 < menor && mayor > 1 )
            Duracion( menor, mayor, min );
}

int main()
{
    int j1, j2, minutos = 0;
    int orden;

    cin >> j1 >> j2;

    if ( j1 < j2 )
    {
        orden = j1;
        j1 = j2;
        j2 = orden;
    }

    Duracion( j1, j2, minutos );

    cout << minutos;

    return 0;
}
