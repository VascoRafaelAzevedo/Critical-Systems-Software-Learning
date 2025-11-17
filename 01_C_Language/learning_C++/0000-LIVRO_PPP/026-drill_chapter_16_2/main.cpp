#include <iostream>
#include <span>
#include <vector>

using namespace std;

void print_v(span<int> span) { // just to test
    for (int i : span) {
        cout << i << endl;
    }
}

void f(vector<int> gv) {

    vector<int> lv(10);

    lv = gv;

    print_v(lv);

    vector<int> lv2(gv);

    print_v(lv2);
}

int main() {

    vector<int> gv{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

    f(gv);

    vector<int> vv(10);
    vv[0] = 1;

    for (int i = 2; i <= 10; i++) {
        vv[i - 1] = vv[i - 2] * i;
    }

    f(vv);

    return 0;
}