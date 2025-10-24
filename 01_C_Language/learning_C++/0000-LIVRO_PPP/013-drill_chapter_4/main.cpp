#include <iostream>
#include <vector>
using namespace std;

int main()
{
    try
    {
        cout << "Success!\n";

        cout << "Success!\n";

        cout << "Success" << "!\n ",

        cout << "success" << "\n";

        int res = 7;
        vector<int> v(10);
        v[5] = res;
        cout << "Success!\n";

        vector<int> v1(10);
        v[5] = 7;
        if (v[5] != 7)
            cout << "Success!\n";

        if (v[5] == 7)
            cout << "Success!\n";
        else
            cout << "Fail!\n";

        bool c = false;
        if (c)
            cout << "Success!\n";
        else
            cout << "Fail!\n";

        string s = "ape";
        bool c1 = "fool" < s;
        if (c)
            cout << "Success!\n";

        string s2 = "ape";
        if (s == "fool")
            cout << "Success!\n";

        string s3 = "ape";
        if (s == "fool")
            cout << "Success!\n";

        string s4 = "ape";
        if (s == "fool")
            cout << "Success!\n";

        vector<char> v2(5);
        for (int i = 0; 0 < v.size(); ++i)
            ;
        cout << "Success!\n";

        vector<char> v3(5);
        for (int i = 0; i <= v.size(); ++i)
            ;
        cout << "Success!\n";

        string s5 = "Success!\n";
        for (int i = 0; i < 6; ++i)
            cout << s[i];

        if (true)
            cout << "Success!\n";
        else
            cout << "Fail!\n";

        int x = 2000;
        int  c7 = x;
        if (c7 == 2000)
            cout << "Success!\n";

        string s6 = "Success!\n";
        for (int i = 0; i < 10; ++i)
            cout << s[i];

        vector<int> v4(5);
        for (int i = 0; i <= v.size(); ++i)
            ;
        cout << "Success!\n";

        int i = 0;
        int j = 9;
        while (i < 10)
            ++j;
        if (j < i)
            cout << "Success!\n";

        int x1 = 2;
        double d = 5 / (x-2);
        if (d == 2 * x + 0.5)
            cout << "Success!\n";

        string s8 = "Success!\n";
        for (int i = 0; i <= 10; ++i)
            cout << s[i];

        int i0 = 0;
        while (i < 10)
            ++j;
        if (j < i)
            cout << "Success!\n";

        int x4 = 4;
        double d45 = 5 / (x-2);
        if (d45 == 2 * x + 0.5)
            cout << "Success!\n";

        cout << "Success!\n";

        return 0;
    }
    catch (exception &e)
    {
        cerr << "error: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "Oops: unknown exception!\n";
        return 2;
    }

    return 0;
}