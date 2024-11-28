#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;

class Nodedb{
public:
    string val;
    Nodedb* prev;
    Nodedb* next;
};

class DoubleLinkedList{
public:
    Nodedb* head;
    Nodedb* tail;
        DoubleLinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    void addTail(string val){
        Nodedb* newNode = new Nodedb{val, tail, nullptr};
        if (tail != nullptr) {
            tail->next = newNode;
        } else {
            // Если список пустой, обновляем head
            head = newNode;
        }
        tail = newNode;
    }

    void addHead(string val) {
        Nodedb* newNode = new Nodedb{val, nullptr, head};
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            // Если список пустой, обновляем tail
            tail = newNode;
        }
        head = newNode;
    }

    void deleteHead(){
        if (head == nullptr) return;
        if (head == tail){
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        Nodedb* current = head->next;
        delete head;
        head = current;
        head->prev = nullptr;
    }

    void deleteTail() {
        if (tail == nullptr) return; // Если список пуст, ничего не делаем
        if (head == tail) { // Если в списке только один узел
            delete tail;
            head = nullptr;
            tail = nullptr;
            return;
        }
        // Если в списке больше одного узла
        Nodedb* prevTail = tail->prev; 
        delete tail; 
        tail = prevTail; 
        tail->next = nullptr; 
    }

    void deleteValue(string value) {
        if (head == nullptr) return; // Если список пуст, ничего не делаем
        // Если значение находится в голове списка
        if (head->val == value) {
            Nodedb* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr; // Обновляем указатель prev новой головы
            } else {
                tail = nullptr; // Если список стал пустым, обновляем tail
            }
            delete temp;
            return;
        }
        Nodedb* current = head;
        while (current->next != nullptr && current->next->val != value) {
            current = current->next;
        }
        // Если значение не найдено
        if (current->next == nullptr) {
            return;
        }
        Nodedb* temp = current->next;
        current->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = current; // Обновляем указатель prev следующего узла
        } else {
            tail = current; // Если удаляемый узел был хвостом, обновляем tail
        }
        delete temp;
    }

    bool find(string value){
        Nodedb* current = head;
        while(current != nullptr){
            if (current->val == value){
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void printbash() {
        Nodedb* current = head;
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

        Nodedb* current = head;
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

        Nodedb* current = head;
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