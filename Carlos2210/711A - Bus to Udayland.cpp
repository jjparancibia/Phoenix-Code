#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    int N;
    int i = 0;

    string check = "NO";
    string asiento;

    vector <string> cine;

    cin >> N;

    for ( int k = 0; k < N; k++ )
    {
        cin >> asiento;
        cine.push_back( asiento );
    }

    while ( i < N )
    {
        if ( cine[i] == "OO|XX" )
        {
            cine[i] = "++|XX";
            i = N;  check = "YES";

            cout << check << endl;
        }

            else if ( cine[i] == "OO|XO" )
            {
                cine[i] = "++|XO";
                i = N;  check = "YES";

                cout << check << endl;
            }

                else if ( cine[i] == "OO|OX" )
                {
                    cine[i] = "++|OX";
                    i = N;  check = "YES";

                    cout << check << endl;
                }

                    else if ( cine[i] == "OO|OO" )
                    {
                       cine[i] = "++|OO";
                       i = N;  check = "YES";

                       cout << check << endl;
                    }

                        else if ( cine[i] == "XX|OO" )
                        {
                            cine[i] = "XX|++";
                            i = N;  check = "YES";

                            cout << check << endl;
                        }

                            else if ( cine[i] == "XO|OO" )
                            {
                                cine[i] = "XO|++";
                                i = N;  check = "YES";

                                cout << check << endl;
                            }

                                else if ( cine[i] == "OX|OO" )
                                {
                                    cine[i] = "OX|++";
                                    i = N;  check = "YES";

                                    cout << check << endl;
                                }
        i++;
        }

    if ( check == "NO" )
    {
        cout << "NO";
        return 0;
    }

    for ( int k = 0; k < N; k++ )
        cout << cine[k] << endl;

    return 0;
}
