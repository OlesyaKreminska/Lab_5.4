#include <iostream>
#include <cmath>
using namespace std;

// Ітераційний варіант
double S0(const int N)
{
    double s = 0;
    for (int j = 2; j <= N; j++)
        s += (j * (N - j)) / (pow(j, 2) + pow((N - j), 2));
    return s;
}

// Рекурсивний варіант (збільшення j)
double S1(const int N, const int j)
{
    if (j > N)
        return 0;
    else
        return (j * (N - j)) / (pow(j, 2) + pow((N - j), 2)) + S1(N, j + 1);
}

// Рекурсивний варіант (зменшення j)
double S2(const int N, const int j)
{
    if (j < 2)
        return 0;
    else
        return (j * (N - j)) / (pow(j, 2) + pow((N - j), 2)) + S2(N, j - 1);
}

// Рекурсивний варіант (з накопиченням результату зверху вниз)
double S3(const int N, const int j, double t)
{
    t = t + (j * (N - j)) / (pow(j, 2) + pow((N - j), 2));
    if (j >= N)
        return t;
    else
        return S3(N, j + 1, t);
}

// Рекурсивний варіант (з накопиченням результату знизу вверх)
double S4(const int N, const int j, double t)
{
    t = t + (j * (N - j)) / (pow(j, 2) + pow((N - j), 2));
    if (j <= 2)
        return t;
    else
        return S4(N, j - 1, t);
}

int main()
{
    int N;
    cout << "N = ";
    cin >> N;

    // Виведення результатів кожної функції
    cout << "(iter) S0 = " << S0(N) << endl;
    cout << "(rec up ++) S1 = " << S1(N, 2) << endl;
    cout << "(rec up --) S2 = " << S2(N, N) << endl;
    cout << "(rec down ++) S3 = " << S3(N, 2, 0) << endl;
    cout << "(rec down --) S4 = " << S4(N, N, 0) << endl;

    return 0;
}
