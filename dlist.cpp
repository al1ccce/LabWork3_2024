#include "dlist.h"
#include <random>

int main(){
    srand(time(0));
    DoubleLinkedList list;
    for (int i = 0; i < 10; i++){
        list.addTail(to_string(rand() % 999));
    }
    list.printbash();
    list.ser_bin();

    DoubleLinkedList newlist;
    newlist.deser_bin();
    newlist.printbash();


    DoubleLinkedList list2;
    for (int i = 0; i < 10; i++){
        list2.addTail(to_string(rand() % 999));
    }
    list2.printbash();
    list2.ser_txt();

    DoubleLinkedList newlist2;
    newlist2.deser_txt();
    newlist2.printbash();

    return 0;
}
