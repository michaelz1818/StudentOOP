#include <cassert>
#include "../my_code/llist.h"

using namespace std;

int main() {
    Node* head = nullptr;
    print_list(cout, head);
    head = new Node(8, nullptr);
    print_list(cout, head); 
    add_at_end(head, 16);
    add_at_end(head, 32);
    add_at_end(head, 64);
    add_at_end(head, 128);
    add_at_end(head, 256);
    cout << "head->data: " << head->data << endl;
    assert(head->data == 8);
    
    // let's see if our last() function works:
    Node* lastp = last(head);
    cout << "Last: " << lastp << endl;
    assert(lastp->data == 256);
    
    add_at_front(head, 4);
    assert(head->data == 4);
    
//    del_tail(head, head);
    del_tail(head); 
    lastp = last(head);
    cout << "Last: " << lastp << endl;
    assert(lastp->data == 128);
    // check our whole list:
    cout << "head list: \n";
    print_list(cout, head);
    
    // now reverse it:
    Node* reversed = reverse(head);
    cout << "Reversed: \n";
    print_list(cout, reversed);
    assert(reversed->data == 128);
    lastp = last(reversed);
    assert(lastp->data == 4);
    print_list(cout, head);
    
    // now duplicate it:
    Node* dupe = duplicate(head);
    cout << "Duplicate: \n";
    print_list(cout, dupe);
    assert(dupe->data == 4);
    lastp = last(dupe);
    assert(lastp->data == 128);
    
    // now join the reversed list on to the end of the original list:
    head = join(head, reversed);
    cout << "Joined lists: \n";
    print_list(cout, head);
    lastp = last(head);
    assert(lastp->data == 4);
    /*
     */
}
