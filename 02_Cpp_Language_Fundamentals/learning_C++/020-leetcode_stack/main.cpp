#include <iostream>
#include <print>
#include <stack>
#include <vector>

using namespace std;



int main() {

    vector<int> small{73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> res = dailyTemperatures(small);

    for (int i : res) {
        cout << i << endl;
    }

    return 0;
}