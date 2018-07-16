//
// Created by giuseppe on 16/07/18.
//

#include <iostream>
#include "Hash.h"

hash::hash()
{
    // Initialization
    for(int i=0; i < tableSize; i++)
    {
        HashTable[i] = new item;
        HashTable[i]->name = "empty";
        HashTable[i]->drink = "empty";
        HashTable[i]->next = NULL;
    }

}

int hash::Hash(std::string key)
{
    // Return a value accounting for the dimension of the table
    int hash = 0;
    int index;

    // String manipulation
    for(size_t i=0; i<key.length(); i++)
        hash += (int)key[i];

    // Make sure we do not overflow table size returning reminder
    index = hash % tableSize ;
    return index;
}

void hash::AddItem(std::string name, std::string drink)
{
    // where information is going to be stored
    int index = Hash(name);

    // Handle case where no object stored at index
    if(HashTable[index]->name== "empty")
    {
        HashTable[index]->name = name;
        HashTable[index]->drink = drink;
    }
    else
    {
        item* Ptr=HashTable[index];
        item* n = new item;
        n->name = name;
        n->drink = drink;
        n->next = NULL;

        // Go down the list
        while(Ptr->next != NULL)
            Ptr = Ptr->next;

        // Tail of the list pointing to the newly added node
        Ptr->next = n;
    }
}

int hash::NumberOfItemsInIndex(int index)
{
    int count = 0;
    if(HashTable[index]->name == "empty")
        return count;
    else
    {
        count ++;
        item* Ptr = HashTable[index];
        while(Ptr->next != NULL)
        {
            count++;
            Ptr = Ptr->next;
        }
        return count;
    }
}

void hash::PrintTable()
{
   int number;
   for(int i=0; i < tableSize; i++)
   {
       number = NumberOfItemsInIndex(i);
       std::cout << "-------------------------\n";
       std::cout << "index = " << i << std::endl;
       std::cout << HashTable[i]->name << std::endl;
       std::cout << HashTable[i]->drink << std::endl;
       std::cout << "# of items = " << number << std::endl;
       std::cout << "-------------------------\n";
   }
}

void hash::PrintItemsInIndex(int index)
{
    item* Ptr = HashTable[index];
    if(Ptr->name=="empty")
        std::cout << "Nothing stored at index = " << index << std::endl;
    else
    {
        int count = 1;
        while(Ptr !=NULL)
        {
            std::cout << "---------------------------------\n";
            std::cout << "Item  #" << count << std::endl;
            std::cout << Ptr->name << std::endl;
            std::cout << Ptr->drink << std::endl;
            std::cout << "---------------------------------\n";
            Ptr = Ptr->next;
            count += 1;
        }
    }
}

void hash::FindDrink(std::string name)
{
    int index = Hash(name);
    bool foundName = false;
    std::string drink;

    item* Ptr = HashTable[index];
    while(Ptr != NULL)
    {
        if(Ptr->name == name)
        {
            foundName = true;
            drink = Ptr->drink;
            break;
        }
        Ptr = Ptr->next;
    }
    if(foundName)
        std::cout << name << " favourite drink is " << drink << ".\n";
    else
        std::cout << name << " not found.\n";
}
