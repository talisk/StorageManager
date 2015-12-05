//
// TODO:
// There has a bug when a process distribute its memory
// into two or more storages, the release operation will
// dirty the data.
//


#include "Global.h"
#include "Storage.h"
#include "Process.h"

Storage createStorage() {
    string storageName;
    int size;

    for (int i = 0; i < (BITCOUNT + 1) * 2; ++i) {
        cout<<"====";
    }
    cout<<endl;

    cout<<"Storage Name('r' for random name):";
    cin>>storageName;
    cout<<"How many bytes "<<storageName<<" have?";
    cin>>size;

    if (storageName=="r") {
        Storage storage1(size);
        storage1.print();
        cout << storage1.name() << " created successfully." << endl;
        for (int i = 0; i < (BITCOUNT + 1) * 2; ++i) {
            cout<<"====";
        }
        cout<<endl<<endl;

        return storage1;
    } else {
        Storage storage1(storageName, size);
        storage1.print();
        cout << storage1.name() << " created successfully." << endl;
        for (int i = 0; i < (BITCOUNT + 1) * 2; ++i) {
            cout << "====";
        }
        cout << endl<<endl;

        return storage1;
    }
}

Process createProcess() {
    string processName;

    for (int i = 0; i < (BITCOUNT + 1) * 2; ++i) {
        cout<<"====";
    }
    cout<<endl;

    cout<<"Process Name('r' for random name):";
    cin>>processName;

    if (processName=="r") {
        Process process1 = Process();

        process1.description();
        cout << process1.name() << " created successfully." << endl;
        for (int i = 0; i < (BITCOUNT + 1) * 2; ++i) {
            cout<<"====";
        }
        cout<<endl<<endl;

        return process1;
    } else{
        Process process1(processName);

        process1.description();
        cout << process1.name() << " created successfully." << endl;
        for (int i = 0; i < (BITCOUNT + 1) * 2; ++i) {
            cout<<"====";
        }
        cout<<endl<<endl;

        return process1;
    }
}

void destoryProcess(Process &process, vector<Storage> &storages) {
    for (int i = 0; i < storages.size(); ++i) {
        storages[i].freeForSpace(process.dataPosition);
        cout<<process.name()<<" in "<<storages[i].name()<<" are free"<<endl;
    }
}

void printAllProcess(vector<Process> &processes) {
    for (int i = 0; i < processes.size(); ++i) {
        processes[i].description();
    }
}
// main

int main() {

    int storageCount, processCount;
    vector<Storage> storages;
    vector<Process> processes;

    cout<<"How many storages?";
    cin>>storageCount;
    cout<<"How many processes?";
    cin>>processCount;

    for (int i = 0; i < storageCount; ++i) {
        storages.push_back(createStorage());
    }
    for (int i = 0; i < processCount; ++i) {
        processes.push_back(createProcess());
    }

    int temp = 1;
    while(temp>0){
        int choice;
        cout<<"1.Select storage\t\t\t2.Select process"<<endl;
        cout<<"3.View all storage\t\t\t4.View all process"<<endl<<"0.Exit"<<endl;

        cin>>choice;

        switch (choice) {

            case 1: {
                cout<<"Which storage?(0-"<<storages.size()-1<<")"<<endl;
                int storageSelection;
                cin>>storageSelection;

                cout<<"1.Distribution\t\t\t2.Check status"<<endl;
                cout<<"0.Back"<<endl;
                cin>>choice;
                switch (choice){
                    case 0:
                        break;
                    case 1: {
                        cout<<"How many bits distribute to "<<storages[storageSelection].name()<<"?"<<endl;
                        int distributeBits;
                        cin>>distributeBits;

                        printAllProcess(processes);
                        cout<<"Which process?(0-"<<processes.size()-1<<")"<<endl;
                        int processSelection;
                        cin>>processSelection;

                        if (storages[storageSelection].applyForSpace(distributeBits, processes[processSelection])) {
                            cout<<"Distribute successfully."<<endl;
                            cout<<storages[storageSelection].name()<<" -->> "<<distributeBits<<" bits -->> "<<processes[processSelection].name()<<endl;
                        }

                        break;
                    }
                    case 2: {
                        storages[storageSelection].print();
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 2: {
                printAllProcess(processes);
                cout<<"Which process?(0-"<<storages.size()-1<<")"<<endl;
                int processSelection;
                cin>>processSelection;

                cout<<"1.Destory process\t\t\t2.Check status"<<endl;
                cout<<"0.Back"<<endl;

                cin>>choice;
                switch (choice){
                    case 0:
                        break;
                    case 1: {
                        destoryProcess(processes[processSelection], storages);
                        break;
                    }
                    case 2: {
                        processes[processSelection].description();
                        break;
                    }
                    default:
                        break;
                }


                break;
            }
            case 3: {
                for (int i = 0; i < storageCount; ++i) {
                    storages[i].print();
                }
                break;
            }
            case 4: {
                printAllProcess(processes);
                break;
            }
            case 0: {
                exit(0);
            }
            default:
                break;
        }

        temp++;
    }

    return 0;
}