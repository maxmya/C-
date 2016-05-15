#include <iostream>
#include "CaesarCipher.h"

using namespace std;

int main() {

    CaesarCipher cc("Meet Me After The Toga Party", 3);
    string s = cc.Encrypt();
    cout << s; //output: phhw ph diwhu wkh wrjd sduwb
    cc.setLineOfText(s);
    string g = cc.Decrypt();
    cout << g; //output: meet me after the toga party


    return 0;
}