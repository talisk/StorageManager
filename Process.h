//
// Created by 孙恺 on 15/12/5.
//

#ifndef STORAGEMANAGER_PROCESS_H
#define STORAGEMANAGER_PROCESS_H

#include "Global.h"


class Process {
public:
    string name();
    void changeName(string newName);

    unsigned long dataSize();
    void description();

    vector<Position> dataPosition;

    /**
     * Constructor with default process name.
	 */
    Process();

    /**
     * Constructor with processName.
     * @param processName the process name.
	 */
    Process(string processName);

private:
    string processName;
};


#endif //STORAGEMANAGER_PROCESS_H
