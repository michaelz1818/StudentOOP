#include <iostream>
#include "llist.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
    if(!nd) return os << "NULL";
    return os << nd->data;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
    if(!head) head = new Node(d);
//    Node* curr = head;
//    while(curr->next){
//        curr = curr->next;
//    }
//    curr->next = new Node(d);
    if(!head->next) head->next = new Node(d);
    else add_at_end(head->next, d);
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* curr) {
    os << curr;
    if(curr && curr -> next){
        os << " ";
        print_list(os, curr->next);
    }
    os << endl;
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
    if(!head) head = new Node(d);
    else head = new Node(d, head);
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
    if(!head) return nullptr;
    if(!head -> next) return head;
    return last(head->next); 
}
