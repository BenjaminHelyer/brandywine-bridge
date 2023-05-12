#include <iostream>

class Hash_Table {
    public:
        double memory [5] = { 0 };
        void set_key(int key, double value);
        double get_key(int key);
};

void Hash_Table::set_key(int key, double value) {
    int index = key % 5;
    memory[index] = value; // TODO: support collisions
}

double Hash_Table::get_key(int key) {
    int index = key % 5;
    return memory[index];
}

int main() {
    Hash_Table myTable;
    myTable.set_key(3, 0.3);
    std::cout << myTable.get_key(3) << std::endl;

    return 0;
}