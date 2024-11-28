#include "queue.h"
#include <random>

int main(){
    srand(time(0));
    Queue obj;
    for (int i = 0; i < 10; i++){
        obj.push(to_string(rand() % 999));
    }
    obj.printbash();
    obj.ser_bin();

    Queue newobj;
    newobj.deser_bin();
    newobj.printbash();


    Queue obj2;
    for (int i = 0; i < 10; i++){
        obj2.push(to_string(rand() % 999));
    }
    obj2.printbash();
    obj2.ser_txt();

    Queue newobj2;
    newobj2.deser_txt();
    newobj2.printbash();

    return 0;
}
