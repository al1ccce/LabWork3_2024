#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;

class Vector {
public:
    int size;
    string* vec;

    Vector(int cap = 10){
        size = 0;
        capacity = cap;
        vec = new string[capacity];
    }

    void push_back(string value) {
        resize();
        vec[size] = value; // Копируем строку
        ++size;
    }

    void push_idx(string value, int idx) {
        if (idx < 0 || idx > size) return;
        resize();
        // Сдвиг элементов вправо, начиная с конца
        for (int i = size; i > idx; --i) {
            vec[i] = vec[i - 1];
        }
        vec[idx] = value;
        ++size;
    }

    string get(int idx) {
        if (idx < 0 || idx >= size) return "";
        return vec[idx];
    }

    void delete_idx(int idx) {
        if (idx < 0 || idx >= size) return;
        // Сдвиг элементов влево, начиная с индекса
        for (int i = idx; i < size - 1; ++i) {
            vec[i] = vec[i + 1];
        }
        --size;
    }

    void exchange(string value, int idx) {
        if (idx < 0 || idx >= size) return;
        vec[idx] = value;
    }

    int get_size() {
        return size;
    }

    void printbash() {
        for (int i = 0; i < size; i++) {
            cout << vec[i] << " ";
        }
        cout << endl;
    }

    void ser_bin() {
        string file = "data.bin";
        ofstream out(file, ios::binary);

        for (int i = 0; i < size; i++) {
            out.write(vec[i].c_str(), vec[i].size() + 1); // +1 для записи нулевого символа
        }
        out.close();
    }

    void deser_bin() {
        string file = "data.bin";
        ifstream in(file, ios::binary);

        while (in.peek() != EOF) {
            string val;
            getline(in, val, '\0'); // Чтение строки до нулевого символа
            vec[size] = val;
            size++;
        }
        in.close();
    }

    void ser_txt() {
        string file = "data.txt";
        ofstream out(file);
        for (int i = 0; i < size; i++) {
            out << vec[i] << endl;
        }
        out.close();
    }

    void deser_txt() {
        string file = "data.txt";
        ifstream in(file);

        string line;
        while (getline(in, line)) {
            push_back(line);
        }
        in.close();
    }

private:
    int capacity;

    void resize() {
        if (size < capacity) return;
        capacity *= 2;
        string* newVec = new string[capacity];
        for (int i = 0; i < size; ++i) {
            newVec[i] = vec[i];
        }
        delete[] vec;
        vec = newVec;
    }
};