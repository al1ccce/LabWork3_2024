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

class Queue {
public:
    Node* head;
    Node* tail;

    Queue(){
        head = nullptr;
        tail = nullptr;
    }

    void push(string val) {
        Node* newNode = new Node{val, nullptr};
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
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

        while (in.peek() != EOF) {
            string val;
            getline(in, val, '\0'); // Чтение строки до нулевого символа
            push(val);
        }
        in.close();
    }

    void ser_txt() {
        string file = "data.txt";
        ofstream out(file);

        Node* current = head;
        while (current != nullptr) {
            out << current->val << '\n';
            current = current->next;
        }
        out.close();
    }

    void deser_txt() {
        string file = "data.txt";
        ifstream in(file);

        string line;
        while (getline(in, line)) {
            push(line);
        }
        in.close();
    }
};