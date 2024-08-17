#include <iostream>
#include <list>
#include <vector>
using namespace std;

// HashTable class using separate chaining
class HashTable {
private:
    int tableSize; // Size of the hash table
    vector<list<int>> table; // Vector of lists for separate chaining

    // Hash function to map values to key
    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    // Constructor to initialize the hash table
    HashTable(int size) {
        tableSize = size;
        table.resize(tableSize);
    }

    // Function to insert a key into the hash table
    void insert(int key) {
        int index = hashFunction(key); // Get the index for the key
        table[index].push_back(key); // Insert the key into the appropriate list
    }

    // Function to remove a key from the hash table
    void remove(int key) {
        int index = hashFunction(key); // Get the index for the key

        // Traverse the list to find the key and remove it
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (*it == key) {
                table[index].erase(it);
                return;
            }
        }

        cout << "Key " << key << " not found!" << endl; // Key not found
    }

    // Function to search for a key in the hash table
    bool search(int key) {
        int index = hashFunction(key); // Get the index for the key

        // Traverse the list to find the key
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (*it == key) {
                return true; // Key found
            }
        }

        return false; // Key not found
    }

    // Function to display the contents of the hash table
    void displayHashTable() {
        for (int i = 0; i < tableSize; ++i) {
            cout << "Index " << i << ":";
            for (auto x : table[i]) {
                cout << " --> " << x;
            }
            cout << endl;
        }
    }
};

// Main function to demonstrate the HashTable class
int main() {
    // Create a hash table of size 10
    HashTable ht(10);

    // Insert keys into the hash table
    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    ht.insert(40);
    ht.insert(50);
    ht.insert(15);
    ht.insert(25);
    ht.insert(35);

    // Display the hash table
    cout << "Hash Table contents:" << endl;
    ht.displayHashTable();
    // Expected Output:
    // Index 0: --> 10 --> 20 --> 30 --> 40 --> 50
    // Index 1:
    // Index 2:
    // Index 3:
    // Index 4:
    // Index 5: --> 15 --> 25 --> 35
    // Index 6:
    // Index 7: 
    // Index 8:
    // Index 9:

    // Search for keys in the hash table
    cout << "Search for key 20: " << (ht.search(20) ? "Found" : "Not Found") << endl;
    // Output: Search for key 20: Found
    cout << "Search for key 45: " << (ht.search(45) ? "Found" : "Not Found") << endl;
    // Output: Search for key 45: Not Found

    // Remove keys from the hash table
    ht.remove(20);
    ht.remove(35);
    ht.remove(45); // Key not in the hash table

    // Display the hash table after removal
    cout << "Hash Table contents after removal:" << endl;
    ht.displayHashTable();
    // Expected Output:
    // Index 0: --> 10 --> 30 --> 40 --> 50
    // Index 1:
    // Index 2:
    // Index 3:
    // Index 4:
    // Index 5: --> 15 --> 25
    // Index 6:
    // Index 7: 
    // Index 8:
    // Index 9:

    return 0;
}