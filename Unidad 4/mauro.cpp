#include <iostream>
#include <algorithm>

using namespace std;

bool funcion(int a, int b, int c)
{
    return (a < b and b < c);
}

int main()
{
    long long a = 0, b = 0, c = 0;

    cout << "Introduzca el primer número" << "\n";
    cin >> a;
    cout << "Introduzca el segundo número" << "\n";
    cin >> b;
    cout << "Introduzca el tercer número" << "\n";
    cin >> c;
    if(funcion(a, b, c))
    {
        cout << "El primer numero es el mas pequeño" << "\n";
    }
    else
    {
        cout << "El primer numero NO es el mas pequeño" << "\n";
    }

}