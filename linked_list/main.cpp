#include <iostream>
#include "List.h"

using namespace std;

int main(int argc, char** argv)
{
    List myList;
    myList.AddNode(3);
    myList.AddNode(1);
    myList.AddNode(4);
    myList.PrintList();

    myList.DeleteNode(3);
    myList.PrintList();

    myList.AddNode(3);
    myList.PrintList();

    return 0;
}