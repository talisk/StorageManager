//
// Created by 孙恺 on 15/12/5.
//

#include "Process.h"

void Process::changeName(string newName) {
    this->processName = newName;
}

string Process::name() {
    return this->processName;
}

unsigned long Process::dataSize() {
    return this->dataPosition.size();
}

void Process::description() {
    cout<<"Process Name:\t"<<this->processName<<endl;
    cout<<"Data Size:\t\t"<<this->dataSize()<<endl;
    for (int i = 0; i < this->dataSize(); ++i) {
        cout<<this->name()<<": (byte"<<this->dataPosition[i].row<<", bit"<<this->dataPosition[i].column<<")"<<endl;
    }
}

Process::Process() {
    string name = "process";
    name.append(to_string(rand()));
    this->processName = name;
}

Process::Process(string processName){
    this->processName = processName;
}
