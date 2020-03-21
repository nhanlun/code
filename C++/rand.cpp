#include <bits/stdc++.h>

using namespace std;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

int random(int l, int r)
{
    return uniform_int_distribution<int>(l, r)(gen);
}

int hexToDec(const string& s)
{
    stringstream ss(s);
    int res;
    ss >> hex >> res;
    return res;
}

string decToHex(int x)
{
    stringstream ss;
    ss << hex << x;
    return ss.str();
}

int main()
{
    int cmd;
    int x; string y;
    while (cin >> cmd)
    {
        if (cmd == 1) 
        {
            x = random(0, 255);
            cout << x << '\n';
            cin >> y;
            if (x == hexToDec(y)) 
                cout << "Correct\n";
            else 
                cout << "Wrong " << decToHex(x) << '\n';
        }
        else if (cmd == 2)
        {
            x = random(0, 255);
            cout << decToHex(x) << '\n';
            int tmp;
            cin >> tmp;
            if (tmp == x) 
                cout << "Correct\n";
            else 
                cout << "Wrong " << x << '\n';
        }
    }
    return 0;
}