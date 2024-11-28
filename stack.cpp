#include "stack.h"
#include <random>

int main(){
    srand(time(0));
    Stack list;
    for (int i = 0; i < 10; i++){
        list.addHead(to_string(rand() % 999));
    }
    list.printbash();
    list.ser_bin();

    Stack newlist;
    newlist.deser_bin();
    newlist.printbash();


    Stack list2;
    for (int i = 0; i < 10; i++){
        list2.addHead(to_string(rand() % 999));
    }
    list2.printbash();
    list2.ser_txt();

    Stack newlist2;
    newlist2.deser_txt();
    newlist2.printbash();

    return 0;
}
