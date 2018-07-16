//
// Created by giuseppe on 16/07/18.
//

#ifndef LINKED_LIST_LIST_H
#define LINKED_LIST_LIST_H

class List{
    private:
        /* Define the node structure but at the same time redefine its
         * pointer denomination as nodePtr */
        typedef struct node{
                    int data;
                    node* next;   // node pointer to another node in the list
        }* nodePtr;

    nodePtr head;   // head of the list
    nodePtr curr;   // current node used for traversal
    nodePtr temp;   // used for delation

    public:
        List();
        void AddNode(int addData);
        void DeleteNode(int delData); // match on data for deleting the node
        void PrintList();
};
#endif //LINKED_LIST_LIST_H
