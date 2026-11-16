#include "Input.h"
#include "Cleanup.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cctype>
using namespace std;

string toStr(int n) { ostringstream o; o << n; return o.str(); }

string toLower(string s) {
    for (size_t i = 0; i < s.size(); i++) s[i] = (char)tolower((unsigned char)s[i]);
    return s;
}
int askInt(string msg, int lo, int hi) {
    while (true) {
        cout << msg;
        int v;
        if (cin >> v && v >= lo && v <= hi) { cin.ignore(10000, '\n'); return v; }
        if (cin.eof()) { cleanup(); exit(0); }
        cin.clear(); cin.ignore(10000, '\n');
        cout << "  Please enter a number from " << lo << " to " << hi << ".\n";
    }
}
string askText(string msg) {
    cout << msg;
    string s;
    if (!getline(cin, s)) { cleanup(); exit(0); }
    return s;
}
