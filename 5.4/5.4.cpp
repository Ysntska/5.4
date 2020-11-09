#include <iostream>
#include <cmath>

using namespace std;

double P0(const double N)
{
    double p = 1;
    for (int k = N; k <= 19; k++)
        p *= (((k - N) / (k + N) + 1));
    return p;
}
double P1(const double N, double k)
{
    if (k > 19)
        return 1;
    else
        return (((k - N) / (k + N)) + 1) * P1(N, k + 1);
}
double P2(const double N, double k)
{
    if (k < N)
        return 1;
    else
        return (((k - N) / (k + N)) + 1) * P2(N, k - 1);
}
double P3(const double N, double k, double t)
{
    t = t * (((k - N) / (k + N) + 1));
    if (k >= 19)
        return t;
    else
        return P3(N, k + 1, t);
}
double P4(const double N, double k, double t)
{
    t = t * (((k - N) / (k + N) + 1));
    if (k <= N)
        return t;
    else
        return P4(N, k - 1, t);
}
int main()
{
    int N;
    cout << "N= "; cin >> N;
    cout << "(iter) P0 = " << P0(N) << endl;
    cout << "(rec up ++) P1 = " << P1(N, N) << endl;
    cout << "(rec up --) P2 = " << P2(N, 19) << endl;
    cout << "(rec down ++) P3 = " << P3(N, N, 1) << endl;
    cout << "(rec down --) P4 = " << P4(N, 19, 1) << endl;

    system("pause");
    return 0;
}