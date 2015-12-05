#include "Global.h"
#include "Storage.h"
#include "Process.h"

int main() {
    Storage storage1("storage1", 8);
    Storage storage2("storage2", 8);

    Process process1("process1");
    Process process2("process2");

    storage1.applyForSpace(20, process1);
    storage1.print();

    storage2.applyForSpace(13, process1);
    storage2.print();

    storage2.applyForSpace(12, process2);
    storage2.print();

    storage2.freeForSpace(process1.dataPosition);
    storage2.print();

    storage2.applyForSpace(14, process1);
    storage2.print();



    return 0;
}