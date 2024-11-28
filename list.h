#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;

class Node {
public:
    string val;
    Node* next;

    Node(string value) : val(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    void addTail(string val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = newNode;
    }

    void addHead(string val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void printbash() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->val;
            if (current->next != nullptr) {
                cout << ' ';
            }
            current = current->next;
        }
        cout << endl;
    }

    void deleteHead() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteTail() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* tail = head;
        while (tail->next->next != nullptr) {
            tail = tail->next;
        }
        delete tail->next;
        tail->next = nullptr;
    }

    void deleteValue(string value) {
        if (head == nullptr) return;
        if (head->val == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->val != value) {
            current = current->next;
        }
        if (current->next == nullptr) return;
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    bool find(string value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->val == value) {
                return true;
            }
            current = current->next;
        }
        return false;
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
            addTail(val);
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
            addTail(line);
        }
        in.close();
    }
};