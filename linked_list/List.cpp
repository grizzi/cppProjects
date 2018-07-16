//
// Created by giuseppe on 16/07/18.
//

#include <cstdlib>
#include <iostream>
#include "List.h"

using namespace std;

// Constructor - Initialize pointers
List::List() {
    head = NULL;
    curr = NULL;
    temp = NULL;
}

void List::AddNode(int addData) {
    nodePtr n = new node;
    n->next = NULL;
    n->data = addData;

    // Not empty list
    if(head != NULL)
    {
        curr = head;
        // Advance until the last node in the list
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = n;
    }
    else
    {
        head = n;
    }
}

void List::DeleteNode(int delData) {
    nodePtr delPtr = NULL;
    temp = head;
    curr = head;

    // the curr node is one step ahead of the curr so that we can glue the
    // list if temp is deleted. Traverse the list for finding the value
    while(curr !=NULL && curr->data != delData)
    {
        temp = curr;
        curr = curr->next;
    }

    // Data was not found in the list
    if(curr == NULL)
    {
        cout <<  delData << " was not in the list." << endl;
        delete delPtr;    // release memory
    }
    {
        delPtr = curr;
        // make the current pointer (the one to delete) point to the next node
        // and make the previous pointer point to this next node
        // Handle the case where the deleted pointer is the head
        if(curr = head)
            head = curr->next;
        curr = curr->next;
        temp->next = curr;

        // delete pointer
        delete delPtr;
        cout << "The value " << delData << " was deleted." << endl;
    }
}

void List::PrintList()
{
    curr = head;
    cout << "List = [ ";
    while(curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "]" << endl;
}

