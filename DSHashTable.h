//
// Created by mikec_g1kgiu8 on 11/30/2021.
//

#ifndef INC_21F_FINAL_PROJ_TEMPLATE_DSHASHTABLE_H
#define INC_21F_FINAL_PROJ_TEMPLATE_DSHASHTABLE_H

#include <vector>
#include "DSAVLTree.h"
#include <iostream>
#include <fstream>

/// A templated Hash Table.
///
/// A templated Hash Table that utilizes an AVLTree and the std::hash function.
/// @tparam K The type of the key.
/// @tparam V The type of the value.
template <typename K, typename V>
class DSHashTable {
    private:
        static const int tableSize = 500009; //Prime Number > 100,000
        DSAVLTree<K, V> table[tableSize];

    public:
        /// Default Constructor.
        ///
        /// The default constructor.
        DSHashTable();

        /// Finds the value associated with the given key.
        ///
        /// Finds the value associated with the given key. Throws a runtime error if the key is not found.
        /// @param key The key being searched for.
        /// @return The value associated with the given key.
        V& at(const K& key);

        /// Adds the given key to the HashTable.
        ///
        /// Adds the given key to the HashTable and returns its associated value by reference (so it can be assigned a value).
        /// If the key is already in the HashTable, it returns its associated value by reference (so that value can be changed).
        /// @param key The key being added to the HashTable.
        /// @return The value associated with the given key.
        V& add(const K& key);

        /// Writes the persistence file.
        ///
        /// Copies all of the data in the HashTable to a persistence file.
        /// @param fileName The name of the persistence file being written to.
        void doPersistence(string& fileName);

        /// Clears the HashTable.
        ///
        /// Iterates through the entire HashTable and deletes all values stored.
        void clear();

        /// Counts the number of elements in the HashTable.
        ///
        /// Iterates through the HashTable and counts the number of elements in it.
        /// @return The number of elements stored in the HashTable.
        int getUnique();
};

template<typename K, typename V>
DSHashTable<K, V>::DSHashTable() = default;

template<typename K, typename V>
V &DSHashTable<K, V>::at(const K& key) {
    std::hash<K> theHasher;
    auto hashValue = theHasher(key);
    int location = hashValue % tableSize;
    auto& bucket = table[location];
    return bucket.find(key);
}

template<typename K, typename V>
V &DSHashTable<K, V>::add(const K &key) {
    std::hash<K> theHasher;
    auto hashValue = theHasher(key);
    int location = hashValue % tableSize;
    auto& bucket = table[location];
    try {
        return bucket.find(key);
    } catch (std::runtime_error &e) {
        return bucket.insert(key);
    }
}

template<typename K, typename V>
void DSHashTable<K, V>::doPersistence(string& fileName) {
    ofstream output(fileName);
    for (int i = 0; i < tableSize; i++) {
        table[i].callPersistenceWithRoot(output);
    }
    output.close();
}

template<typename K, typename V>
void DSHashTable<K, V>::clear() {
    for (int i = 0; i < tableSize; i++) {
        table[i].deleteTree();
    }
}

template<typename K, typename V>
int DSHashTable<K, V>::getUnique() {
    int count = 0;
    for (int i = 0 ; i < tableSize ; i++) {
        count += table[i].getUniqueWordCount();
    }
    return count;
}

#endif //INC_21F_FINAL_PROJ_TEMPLATE_DSHASHTABLE_H
