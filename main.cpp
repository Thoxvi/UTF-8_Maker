//
// Created by yanyuhl on 18-4-6.
//
#include <cstdlib>
#include <forward_list>
#include <vector>
#include <iostream>

using namespace std;

typedef unsigned char uchar;
typedef vector<uchar> utf_8_char;
typedef forward_list<utf_8_char> utf_8_list;
typedef long long ll;

ll get2n(int n) {
    if (n < 0) return 0;
    ll size = 1;

    for (int i = 0; i < n; ++i) {
        size <<= 1;
    }
    return size;
}

bool getNByteUTF_8(utf_8_list &ulist, int n) {
    ll size;
    ll size1;

    uchar head;
    uchar tail = static_cast<uchar>(get2n(7));

    switch (n) {
        case 1:
            size = get2n(7);
            for (uchar i = 0; i < size; ++i) {
                utf_8_char uc;
                uc.push_back(static_cast<uchar>(i));
                ulist.push_front(uc);
            }
            return true;
        case 2:
            size = get2n(5);
            size1 = get2n(6);
            head = static_cast<uchar>(get2n(7) + get2n(6));
            for (uchar j = 0; j < size; ++j) {
                for (uchar i = 0; i < size1; ++i) {
                    utf_8_char uc;
                    uc.push_back(head + j);
                    uc.push_back(tail + i);
                    ulist.push_front(uc);
                }
            }
            return true;
        case 3:
            size = get2n(4);
            size1 = get2n(6);
            head = static_cast<uchar>(get2n(7) + get2n(6) + get2n(5));
            for (uchar j = 0; j < size; ++j) {
                for (uchar i = 0; i < size1; ++i) {
                    for (uchar k = 0; k < size1; ++k) {
                        utf_8_char uc;
                        uc.push_back(head + j);
                        uc.push_back(tail + i);
                        uc.push_back(tail + k);
                        ulist.push_front(uc);
                    }

                }
            }
            return true;
        case 4:
            size = get2n(3);
            size1 = get2n(6);
            head = static_cast<uchar>(get2n(7) + get2n(6) + get2n(5) + get2n(4));
            for (uchar j = 0; j < size; ++j) {
                for (uchar i = 0; i < size1; ++i) {
                    for (uchar k = 0; k < size1; ++k) {
                        for (uchar l = 0; l < size1; ++l) {
                            utf_8_char uc;
                            uc.push_back(head + j);
                            uc.push_back(tail + i);
                            uc.push_back(tail + k);
                            uc.push_back(tail + l);
                            ulist.push_front(uc);
                        }
                    }

                }
            }
            return true;
        default:
            return false;
    }

}

bool printToFd(const utf_8_list &ulist, int lenght, bool hasIndex) {
    ll count = 0;

    if (hasIndex) {
        cout << count << "\t";
    }

    for (const utf_8_char &utf:ulist) {
        if (++count % lenght == 0) {
            cout << endl;
            if (hasIndex) {
                cout << count << "\t";
            }
        }
        for (const uchar &c:utf) {
            cout << c;
        }
        cout << "\t";
    }
}

int main(int argc, char **argv) {
    utf_8_list ulist;
    for (int i = 1; i <= 4; ++i) {
        if (getNByteUTF_8(ulist, i)) {
            printToFd(ulist, 10, true);
            ulist.clear();
        }
    }
    return EXIT_SUCCESS;
}

