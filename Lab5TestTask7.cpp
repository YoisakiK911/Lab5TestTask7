#include <iostream>
using namespace std;
bool check(int x) {
    if (x == 0) {
        return 0;

    }
    else {
        return 1;
    }
}
void printBits(unsigned short int bits) {
    for (int i = 15; i >= 0; i--) {
        unsigned int mask = 1u << i;
        cout << ((bits & mask) ? 1 : 0);
        if (i % 4 == 0 && i != 0) {
            cout << ' ';
        }
    }
    cout << endl;
}

int main() {
    int x, s;
    cin >> x >> s;

    unsigned short int u = static_cast<unsigned short int>(x);
    short int sx = static_cast<short int>(u);

    unsigned short int logic, arith, cyclic;

    if (s == 0) {
        logic = u;
        arith = u;
        cyclic = u;
    }
    else if (s > 0) {
        unsigned int k = static_cast<unsigned int>(s);

        logic = static_cast<unsigned short int>(u << k);

        arith = logic;

        cyclic = static_cast<unsigned short int>((u << k) | (u >> (16 - k)));
    }
    else {
        unsigned int k = static_cast<unsigned int>(-s);

        logic = static_cast<unsigned short int>(u >> k);

        arith = static_cast<unsigned short int>(sx >> k);

        cyclic = static_cast<unsigned short int>((u >> k) | (u << (16 - k)));
    }

    printBits(u);
    printBits(logic);
    printBits(arith);
    printBits(cyclic);
    cout << "this is end " << endl;

    return 0;
}