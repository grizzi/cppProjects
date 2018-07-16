#include <iostream>
#include "Hash.h"

int main(){

    hash table;

    table.AddItem("Giuseppe", "Thè");
    table.AddItem("Luca", "Cola");
    table.AddItem("Mara", "Beer");
    table.AddItem("Nico", "Beer");
    table.AddItem("Pep", "Fanta");
    table.AddItem("Lia", "choco");
    table.AddItem("Red", "Beer");
    table.AddItem("Ros", "Beer");
    table.AddItem("Rick", "Lemonade");

    table.PrintTable();
    table.PrintItemsInIndex(3);

    table.FindDrink("Rick");
    table.FindDrink("John");

}