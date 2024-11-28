#include "hash.h"
#include <random>

int main(){
    srand(time(0));
    HashTable obj(11);
    for (int i = 0; i < 7; i++){
        obj.insert(to_string(i), to_string(rand() % 99));
    }
    obj.printbash();
    obj.ser_bin();

    HashTable newobj(11);
    newobj.deser_bin();
    newobj.printbash();

    HashTable obj2(11);
    for (int i = 0; i < 7; i++){
        obj2.insert(to_string(i), to_string(rand() % 99));
    }
    obj2.printbash();

    obj2.ser_txt();

    HashTable newobj2(11);
    newobj2.deser_txt();
    newobj2.printbash();

    return 0;
}
