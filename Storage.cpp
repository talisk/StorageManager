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
    cout<<"Usage Rates:\t"<<(1 - (float)this->freeSpace / (float)this->capacity)*100<<"%"<<endl;
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
            cout<<(this->storageRegion[i][j]?"■":"□")<<"\t|\t";
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

bool Storage::applyForSpace(int quantity, Process &process) {

    vector<Position> &dataPosition = process.dataPosition;
    string owner = process.name();
    
    if (this->freeSpace < quantity) {
        return false;
    }

    for (int i = 0; i < quantity; ++i) {
        Position result = traverseAvailableUnit();
        result.owner = owner;
        result.storage = this->storageName;
        dataPosition.push_back(result);
        set1(result);
    }

    this->freeSpace -= quantity;

    return true;
}

bool Storage::freeForSpace(vector<Position> &dataPosition) {
    unsigned long freeSize = dataPosition.size();

    unsigned long notOwn = 0;

    for (int i = 0; i < freeSize; ++i) {
        if (dataPosition[i].storage != this->storageName) {
            notOwn++;
            continue;
        }
        set0(dataPosition.back());
        dataPosition.pop_back();
    }

    freeSize -= notOwn;
    this->freeSpace += freeSize;

    return true;
}

// private methods

Position Storage::traverseAvailableUnit() {
    Position result;
    for (int row = 0; row < this->storageRegion.size(); ++row) {
        for (int column = 0; column < BITCOUNT; ++column) {
            if (this->storageRegion[row][column] == 0) {
                result.row = row;
                result.column = column;
                return result;
            }
        }
    }
}

void Storage::set0(Position position) {
    this->storageRegion[position.row].reset(position.column);
}

void Storage::set1(Position position) {
    this->storageRegion[position.row].set(position.column);
}
