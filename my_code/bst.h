#ifndef bst_h
#define bst_h

#include <iostream>

void indent(int level) {
    // indent more at each level:
    for (int i = 0; i < level; i++) std::cout << "  ";
}

template <typename T>
class Bst {
    friend void print_bst(const Bst<T>& bst, int level=0) {
        indent(level);
        level++;
        
        std::cout << "data: " << bst.data << std::endl;
        indent(level + 1);
        std::cout << "left: ";
        
        if (!bst.left) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.left, level);
        }
        indent(level + 1);
        std::cout << "right: ";
        if (!bst.right) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.right, level);
        }
        std::cout << std::endl;
    }
    
public:
    Bst(T d, Bst* p=nullptr, Bst* l=nullptr, Bst* r=nullptr)
    : data(d), parent(p), left(l), right(r) {}
    
    Bst<T>* search(const T& d) {
        if(this->data == d) return this;
        else if(this->data < d && this->right) return this->right->search(d);
        else if(this->data > d && this->left) return this->left->search(d);
        else return nullptr; 
    }
    
    Bst<T>* insert(const T d) {
        if(d < this->data){
            if(this->left == nullptr) this->left = new Bst<T>(d, this);
            else this->left->insert(d);
        } else if (d > this->data) {
            if(this->right == nullptr) this->right = new Bst<T>(d, this);
            else this->right->insert(d);
        }
        return this;
    }
    
    Bst<T>* predecessor(const T d){
        Bst<T>* target = search(d);
        if(target->left) {
            target = target -> left;
            while (target->right != nullptr) target = target->right;
            return target;
        }
        while (target->parent != nullptr) {
            if(target-> parent -> data < d) break;
            target = target -> parent;
        }
        return target -> parent; 
    }
    
    Bst<T>* successor(const T d){
        Bst<T>* target = search(d);
        if(target->right) {
            target = target -> right;
            while (target->left != nullptr) target = target->left;
            return target;
        }
        while (target->parent != nullptr) {
            if(target-> parent -> data > d) break;
            target = target -> parent;
        }
        return target -> parent;
    }
    
    T& min(){
        if(this->left == nullptr) return this->data;
        return this->left->min();
    }
    
    T& max(){
        if(this->right == nullptr) return this->data;
        return this->right->max();
    }
    
    T get_val() const {
        return data;
    }
    
private:
    T data;
    Bst* parent;
    Bst* left;
    Bst* right;
};

//template <typename T>


#endif /* bst_h */
