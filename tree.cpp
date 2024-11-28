#include "tree.h"
#include <random>

int main(){
    srand(time(0));
    FullBinaryTree obj;
    for (int i = 0; i < 7; i++){
        obj.insert(obj.root, rand() % 99);
    }
    obj.printbash();
    cout << "\n\n\n\n";
    obj.ser_bin();

    FullBinaryTree newobj;
    newobj.deser_bin();
    newobj.printbash();
    cout << "\n\n\n\n";

    FullBinaryTree obj2;
    for (int i = 0; i < 7; i++){
        obj2.insert(obj2.root, rand() % 99);
    }
    obj2.printbash();
    cout << "\n\n\n\n";

    obj2.ser_txt();

    FullBinaryTree newobj2;
    newobj2.deser_txt();
    newobj2.printbash();

    return 0;
}
