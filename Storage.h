//
// Created by 孙恺 on 15/12/4.
//

#ifndef STORAGEMANAGER_STORAGE_H
#define STORAGEMANAGER_STORAGE_H

#include "Global.h"
#include "Process.h"

class Storage {
public:
    string name();
    void changeName(string newName);

    unsigned long size();
    unsigned long free();

    /**
     * Print the storage state by table.
	 */
    void print();

    bool applyForSpace(int quantity, Process &process);
    bool freeForSpace(vector<Position> &dataPosition);


    /**
     * Constructor with default storage name.
	 * @param bytesCount How many bytes the storage has.
	 */
    Storage(int bytesCount);

    /**
     * Constructor with storageName.
     * @param storageName the storage name.
	 * @param bytesCount How many bytes the storage has.
	 */
    Storage(string storageName, int bytesCount);





private:
    string storageName;
    vector<BYTE> storageRegion;
    unsigned long capacity;
    unsigned long freeSpace;

    void set1(Position position);
    void set0(Position position);
    Position traverseAvailableUnit();
};


#endif //STORAGEMANAGER_STORAGE_H
