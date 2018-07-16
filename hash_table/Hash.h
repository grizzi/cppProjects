//
// Created by giuseppe on 16/07/18.
//
#include <cstdlib>
#include <iostream>
#include <string>

#ifndef HASH_TABLE_HASH_H
#define HASH_TABLE_HASH_H

class hash{
    private:
        static const int tableSize=10;

        // Create item as a linked list
        struct item{
            std::string name;
            std::string drink;
            item* next;
        };

        // Table of item pointers - the hash table
        item* HashTable[tableSize];

    public:
        hash();
        int Hash(std::string key);
        void AddItem(std::string name, std::string drink);
        int NumberOfItemsInIndex(int index);
        void PrintTable();
        void PrintItemsInIndex(int index);
        void FindDrink(std::string name);
};
#endif //HASH_TABLE_HASH_H
