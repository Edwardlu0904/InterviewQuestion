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

void printDuplicateChar(const char* str) {
    
    map<char, int> charDict;
    map<char, int>::iterator it;
    
    while (*str != '\0') {
        char singleChar = *str;
        cout << singleChar << endl;
        it = charDict.find(singleChar);
        if (it != charDict.end()) {
            it->second++;
        } else {
            charDict.insert(map<char, int>::value_type(singleChar,1));
        }
        str++;

    }
    
    for (it = charDict.begin(); it != charDict.end(); it++) {
        cout << it->first << ":" << it->second << endl;
    }
}

void printDuplicateChar2(const char* str) {
    int countArray[26];
    for (int i = 0; i < 26; i++) {
        *(countArray + i) = 0;
    }
    
    while (*str != '\0') {
        char singleChar = *str;
        str++;
        int countArrayIndex;
        if ('A' <= singleChar && 'Z' >= singleChar) {
            countArrayIndex = (int)(singleChar - 'A');
        } else if ('a' <= singleChar && 'z' >= singleChar) {
            countArrayIndex = (int)(singleChar - 'a');
        } else {
            continue;
        }
        *(countArray + countArrayIndex)+=1;
    }
    
    for (int i = 0; i < 26; i++) {
        int repeatCount = *(countArray + i);
        if (repeatCount > 0) {
            char singleChar = ('A' + i);
            cout << singleChar << ":" << repeatCount << endl;
        }
    }
    
}


int main(int argc, const char * argv[]) {
    
    char* str = "aab";
    
    printDuplicateChar2(str);
    
    return 0;
}
