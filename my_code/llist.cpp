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
    head = new Node(d, head);
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
    if(!head) return nullptr;
    if(!head -> next) return head;
    return last(head->next); 
}

/*
 * These are coming:
 */

/*
 * Delete the first node and attach head to the 2nd node:
 * */
bool del_head(Node*& head){
    if(!head) return false;
    Node* delHead = head;
    head = head->next;
    delete delHead;
    return true;
}

/*
 * Delete the last node and set prev->next to nullptr:
 * */
//bool del_tail(Node*& head, Node*& prev){
//    if(!head) return false;
//    if(!head->next){
//        prev -> next = nullptr;
//        delete head;
//        return true;
//    } else {
//        return del_tail(head->next, head);
//    }
//}

bool del_tail(Node*& head){
    if(!head) return false;
    if(!head->next){
        delete head;
        head = nullptr;
        return true;
    } else {
        return del_tail(head->next);
    }
}

/*
 * Duplicate the entire list -- you must not share memory!
 * */
Node* duplicate(Node* head){
    if(!head) return nullptr;
//    Node* dupList = new Node(head->data);
//    Node* dupCurr = dupList;
//    Node* curr = head;
//    while(curr->next){
//        dupCurr->next = new Node(curr->next->data);
//        curr = curr->next;
//        dupCurr = dupCurr->next;
//    }
//    return dupList;
    return new Node(head->data, duplicate(head->next));
}

/*
 * Reverse the list: return a brand new list with everything reversed.
 * */
//THE FOLLOWING CODE REVERSED THE ORIGINAL LIST
//Node* reverse(Node* curr, Node* new_next){
//    if(!curr) return nullptr;
//    if(!curr->next){
//        curr->next = new_next;
//        return curr;
//    } else {
//        Node* temp = curr->next;
//        curr->next = new_next;
//        return reverse(temp, curr);
//    }
//}

Node* reverse(Node* curr, Node* new_next){
//    if(!curr) return nullptr;
//    Node* thisNode = new Node(curr->data, new_next);
//    if(!curr->next) return thisNode;
//    else return reverse(curr->next, thisNode);
    if(!curr) return new_next;
    else return reverse(curr->next, new Node(curr->data, new_next));
}

/*
 * Join two lists: tack list 2 onto the end of list 1:
 * Use existing memory.
 * */
Node* join(Node*& list1, Node* list2){
    if(!list1 && !list2) return nullptr;
    if(!list1) return list2;
//    Node* currL1 = list1;
//    while(currL1 -> next){
//        currL1 = currL1 -> next;
//    }
//    currL1->next = list2;
//    return list1;
    
//    list1 -> next = join(list1 -> next, list2);
    last(list1) -> next = list2;
    return list1;
}
