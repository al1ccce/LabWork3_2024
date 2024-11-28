#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;

class HashBucket{
public:
    string key;
    string value;
    bool isDeleted;
    HashBucket() : key(""), value(""), isDeleted(false) {}
};

class HashTable {
private:
    int size;
    int capacity;
    HashBucket* table;

    int Hash1(const string& key) const {
        int hashz = 0;
        for (char c : key) {
            hashz += static_cast<int>(c);
        }
        return hashz % capacity;
    }

    int Hash2(int h) const {
        return 1 + (h % (capacity - 1));
    }

    int FinalHash(const string& key, int attempt) const {
        int h = Hash1(key);
        int g = Hash2(h);
        return (h + attempt * g) % capacity;
    }

public:
    HashTable(int cap) : size(0), capacity(cap) {
        table = new HashBucket[capacity];
    }

    ~HashTable() {
        delete[] table;
    }

    string find(const string& key) const {
        int attempt = 0;
        int index;

        do {
            index = FinalHash(key, attempt);
            if (!table[index].isDeleted && table[index].key == key) {
                return table[index].value;
            }
            attempt++;
        } while (attempt < capacity && !table[index].key.empty());

        return "";
    }

    void insert(const string& key, const string& value) {
        if (size >= capacity) {
            cout << "Таблица заполнена." << endl;
            return;
        }

        if (find(key) != "") {
            cout << "Ключ уже существует." << endl;
            return;
        }

        int attempt = 0;
        int index;

        do {
            index = FinalHash(key, attempt);
            if (table[index].key.empty() || table[index].isDeleted) {
                table[index].key = key;
                table[index].value = value;
                table[index].isDeleted = false;
                size++;
                return;
            }
            attempt++;
        } while (attempt < capacity);
    }

    bool remove(const string& key) {
        int attempt = 0;
        int index;

        do {
            index = FinalHash(key, attempt);
            if (!table[index].isDeleted && table[index].key == key) {
                table[index].isDeleted = true;
                size--;
                cout << "Удалено." << endl;
                return true;
            }
            attempt++;
        } while (attempt < capacity && !table[index].key.empty());

        cout << "Ключ не найден." << endl;
        return false;
    }

    void print(const string& file, const string& namestruct){
        ofstream out(file);
        out << namestruct << endl;
        for (int i = 0; i < capacity; i++) {
            if (!table[i].key.empty() && !table[i].isDeleted) {
                out << table[i].key << ' ' << table[i].value << endl;
            }
        }
        out.close();
    }

    void printbash(){
        for (int i = 0; i < capacity; i++) {
            if (!table[i].key.empty() && !table[i].isDeleted) {
                cout << table[i].key << " - " << table[i].value;
            }
        cout << endl;
        }
    }

    void ser_bin() {
        string file = "data.bin";
        ofstream out(file, ios::binary);

        for (int i = 0; i < capacity; i++) {
            if (!table[i].key.empty() && !table[i].isDeleted) {
                size_t key_size = table[i].key.size();
                size_t value_size = table[i].value.size();
                out.write(reinterpret_cast<const char*>(&key_size), sizeof(key_size));
                out.write(table[i].key.c_str(), key_size);
                out.write(reinterpret_cast<const char*>(&value_size), sizeof(value_size));
                out.write(table[i].value.c_str(), value_size);
            }
        }
        out.close();
    }

    void deser_bin() {
        string file = "data.bin";
        ifstream in(file, ios::binary);
    
        while (in.peek() != EOF) {
            size_t key_size;
            size_t value_size;
            in.read(reinterpret_cast<char*>(&key_size), sizeof(key_size));
            string key(key_size, '\0');
            in.read(&key[0], key_size);
            in.read(reinterpret_cast<char*>(&value_size), sizeof(value_size));
            string value(value_size, '\0');
            in.read(&value[0], value_size);
            insert(key, value);
        }
        in.close();
    }

    void ser_txt() {
        string file = "data.txt";
        ofstream out(file);

        for (int i = 0; i < capacity; i++) {
            if (!table[i].key.empty() && !table[i].isDeleted) {
                out << table[i].key << ' ' << table[i].value << endl;
            }
        }
        out.close();
    }

    void deser_txt() {
        string file = "data.txt";
        ifstream in(file);

        string line;
        while (getline(in, line)) {
            stringstream ss(line);
            string key, value;
            ss >> key >> value;
            insert(key, value);
        }
        in.close();
    }
};