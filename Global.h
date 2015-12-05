//
// Created by 孙恺 on 15/12/4.
//

#ifndef STORAGEMANAGER_GLOBAL_H
#define STORAGEMANAGER_GLOBAL_H

#include <bitset>
#include <string>
#include <vector>
#include <iostream>
using std::bitset;
using namespace std;

#ifndef BITCOUNT
#define BITCOUNT 8
#endif

#ifndef BYTE
#ifdef BITCOUNT
#define BYTE bitset<BITCOUNT>
#endif
#endif

typedef struct Position {
    int column,row;
    string owner;
    string storage;
}Position;

#endif //STORAGEMANAGER_GLOBAL_H
