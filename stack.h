#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;

class Node{
public:
    string val;
    Node* next;
};

class Stack{
public:
    Node* head;
    Stack(){
        head = nullptr;
    }
    ~Stack() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }  
    void addHead(string val){
        Node* newNode = new Node{val, head};
        head = newNode;
    }

    void printbash() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->val;
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }

    void deleteHead(){
        if (head == nullptr) return;
        Node* current = head->next;
        delete head;
        head = current;
    }

    void ser_bin() {
        string file = "data.bin";
        ofstream out(file, ios::binary);

        Node* current = head;
        while (current != nullptr) {
            out.write(current->val.c_str(), current->val.size() + 1); // +1 для записи нулевого символа
            current = current->next;
        }
        out.close();
    }

    void deser_bin() {
        string file = "data.bin";
        ifstream in(file, ios::binary);

        Stack tempStack;
        while (in.peek() != EOF) {
            string val;
            getline(in, val, '\0'); // Чтение строки до нулевого символа
            tempStack.addHead(val);
        }
        in.close();

        while (tempStack.head != nullptr) {
            addHead(tempStack.head->val);
            tempStack.deleteHead();
        }
    }

    void ser_txt() {
        string file = "data.txt";
        ofstream out(file);
        Node* current = head;
        while (current != nullptr) {
            out << current->val << endl;
            current = current->next;
        }
        out.close();
    }

    void deser_txt() {
        string file = "data.txt";
        ifstream in(file);

        Stack tempStack;
        string line;
        while (getline(in, line)) {
            tempStack.addHead(line);
        }
        in.close();

        while (tempStack.head != nullptr) {
            addHead(tempStack.head->val);
            tempStack.deleteHead();
        }
    }
};