//
//  main.cpp
//  StringHandleQuestion
//
//  Created by 聖宜 盧 on 2015/8/25.
//  Copyright (c) 2015年 edward. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

int getIndex(char c) {
    int charCount_index;
    if ('a' <= c && 'z' >= c) {
        charCount_index = (int)(c - 'a');
    } else if ('A' <= c && 'z' >= c) {
        charCount_index = (int)(c - 'A');
    }
    return charCount_index;
}

bool isAnagrams(const char* s, const char* t) {
    bool result = false;
    //Condition 1: strings length must be indentical
    if (strlen(s) != strlen(t)) {
        return false;
    }
    //Condition 2: two words with same character counts
    int charCount[26];
    for (int i = 0; i < 26; i++) {
        *(charCount + i) = 0;
    }
    
    while (*s != '\0') {
        char singleCharS = *s;
        char singleCharT = *t;
        s++;
        t++;
        int indexS = getIndex(singleCharS);
        *(charCount + indexS) += 1;
        int indexT = getIndex(singleCharT);
        *(charCount + indexT) -= 1;
    }
    
    for (int i = 0; i < 26; i++) {
        if (*(charCount + i) != 0) {
            return false;
        }
    }
    
    
    return true;
}


int main(int argc, const char * argv[]) {
    const char *str1 = "Chaiy";
    const char *str2 = "chiay";
    cout << isAnagrams(str1, str2) << endl;
    return 0;
}
