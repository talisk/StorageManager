//
// Created by 孙恺 on 15/12/4.
//

#include "Storage.h"

string Storage::name() {
    return this->storageName;
}
void Storage::changeName(string newName) {
    this->storageName = newName;
}

unsigned long Storage::size() {
    return this->capacity;
}

unsigned long Storage::free() {
    return this->freeSpace;
}

void Storage::print() {
    for (int k = 0; k < (BITCOUNT + 1) * 2; ++k) {
        cout<<"----";
    }
    cout<<endl;
    cout<<"Storage Name:\t"<<this->storageName<<endl;
    cout<<"Capacity:\t\t"<<this->capacity<<" bits"<<endl;
    cout<<"Free:\t\t\t"<<this->freeSpace<<" bits"<<endl;
    cout<<"Usage Rates:\t"<<((float)this->freeSpace / (float)this->capacity)*100<<"%"<<endl;
    for (int k = 0; k < (BITCOUNT + 1) * 2; ++k) {
        cout<<"----";
    }
    cout<<endl;

    cout<<"\t\t|\t";
    for (int bit = 0; bit < BITCOUNT; ++bit) {
        cout<<"bit"<<bit<<"|\t";
    }
    cout<<endl;
    for (int k = 0; k < (BITCOUNT + 1) * 2; ++k) {
        cout<<"----";
    }
    cout<<endl;
    for (int i = 0; i < this->storageRegion.size(); ++i) {
        cout<<"byte"<<i<<"\t|\t";
        for (int j = 0; j < BITCOUNT; ++j) {
            cout<<this->storageRegion[i][j]<<"\t|\t";
        }

        cout<<endl;

        for (int k = 0; k < (BITCOUNT + 1) * 2; ++k) {
            cout<<"----";
        }

        cout<<endl;
    }
}

Storage::Storage(int bytesCount) {
    this->storageName = "defaultStorage";
    for (int i = 0; i < bytesCount; ++i) {
        BYTE newByte;
        this->storageRegion.push_back(newByte);
    }
    this->capacity = BITCOUNT * storageRegion.size();
    this->freeSpace = this->capacity;
}

Storage::Storage(string storageName, int bytesCount){
    this->storageName = storageName;
    for (int i = 0; i < bytesCount; ++i) {
        BYTE newByte;
        this->storageRegion.push_back(newByte);
    }
    this->capacity = BITCOUNT * storageRegion.size();
    this->freeSpace = this->capacity;
}

