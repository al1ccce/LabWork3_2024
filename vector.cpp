#include "vector.h"
#include <random>

int main(){
    srand(time(0));
    Vector obj;
    for (int i = 0; i < 10; i++){
        obj.push_back(to_string(rand() % 999));
    }
    obj.printbash();
    obj.ser_bin();

    Vector newobj;
    newobj.deser_bin();
    newobj.printbash();


    Vector obj2;
    for (int i = 0; i < 10; i++){
        obj2.push_back(to_string(rand() % 999));
    }
    obj2.printbash();
    //cout << obj2.get_size();
    obj2.ser_txt();

    Vector newobj2;
    newobj2.deser_txt();
    newobj2.printbash();
    //cout << newobj2.get_size();
    return 0;
}
