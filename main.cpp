//
// Created by yanyuhl on 18-4-6.
//
#include <cstdlib>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

typedef vector<char> utf_8_char;
typedef list<utf_8_char> utf_8_list;
typedef long long ll;

bool getNByteUTF_8(utf_8_list &ulist, int n) {

    switch (n) {
        case 1:
            for (int i = 0; i < ((1 << 7) - 1); ++i) {
                utf_8_char uc;
                uc.push_back(static_cast<char>(i));
                ulist.push_back(uc);
            }
            return true;
        default:
            return false;
    }

}


int main(int argc, char **argv) {
    utf_8_list ulist_1;
    if (getNByteUTF_8(ulist_1, 1)) {
        ll index = 0;

        cout << "\t";
        for (int i = 0; i < 10; i++) {
            cout << i << "\t";
        }

        for (const utf_8_char &c:ulist_1) {
            if (index % 10 == 0) {
                cout << endl;
                cout << index << ":";
                cout << "\t" << c[0];
            } else {
                cout << "\t" << c[0];
            }
            index++;
        }
    }

    return EXIT_SUCCESS;
}

