//
// Created by maxmya on 04/04/16.
//

#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

class CaesarCipher {


public:
    CaesarCipher(string = "", int = 0);

    string Encrypt();

    string Decrypt();

    void setLineOfText(string);

    string getLineofText();

    void setKey(int);

    int getKey();


private:
    string lineOfText;
    int key;

};


