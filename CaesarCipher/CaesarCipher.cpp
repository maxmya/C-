//
// Created by maxmya on 04/04/16.
//

#include "CaesarCipher.h"

CaesarCipher::CaesarCipher(string line, int key) {

    setLineOfText(line);
    setKey(key);

}

void CaesarCipher::setKey(int k) {

    if (k > 25 || k < 0) {
        cerr << "The key Entered " << k << " is invalid , please enter integer key value between 1 and 25";
    } else {
        key = k;
    }

}

int CaesarCipher::getKey() {
    return key;
}

void CaesarCipher::setLineOfText(string line) {

    if (line == "") {

        cerr << "The Entered Statement is Empty ! nothing to Encrypt";

    } else {

        lineOfText = line;

    }

}

string CaesarCipher::getLineofText() {
    return lineOfText;
}

string CaesarCipher::Encrypt() {

    string msg = getLineofText();

    char msgArr[msg.length()];
    strncpy(msgArr, msg.c_str(), sizeof(msgArr));

    for (int i = 0; i < sizeof(msgArr); i++) {
        if (msgArr[i] != ' ') {
            msgArr[i] = msgArr[i] + getKey() % 26;
        }
    }

    string finalEncrypted(msgArr);

    // to make it lower case
    std::transform(finalEncrypted.begin(), finalEncrypted.end(), finalEncrypted.begin(), ::tolower);

    return finalEncrypted;

}

string CaesarCipher::Decrypt() {

    string msg = getLineofText();
    char msgArr[msg.length()];
    strncpy(msgArr, msg.c_str(), sizeof(msgArr));

    for (int i = 0; i < sizeof(msgArr); i++) {
        if (msgArr[i] != ' ') {
            msgArr[i] = msgArr[i] - getKey() % 26;
        }
    }

    string finalDecrypted(msgArr);

    // to make it lower case
    std::transform(finalDecrypted.begin(), finalDecrypted.end(), finalDecrypted.begin(), ::tolower);

    return finalDecrypted;
}