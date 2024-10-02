#include <type_traits>
#include <hash_fun.h>
#include <unordered_set>
#include <iostream>
#include <string>
#include <cstring>


template <typename Val>
class unordered_set_base {
protected:
    struct Node {
        Node* prev;
        size_t hash_code;
        Val val;
        Node* next;
    };

    size_t cap;
    size_t sz;
    size_t cells_filled;

    Node** arr;
    Node* head;

public:

    void rehash(size_t new_cap) {
        Node** new_arr = new Node*[new_cap];
        memset(static_cast<void*>(new_arr), 0, new_cap * sizeof(Node*));
        Node* new_head;

        size_t new_ind;
        for (Node* curr = head; curr->next != nullptr; curr = curr->next) {
            new_ind = curr->hash_code % new_cap;
            if (new_arr[new_ind] == nullptr) {
                new_arr[new_ind] = new Node(curr);
                Node* tmp = head->next;
                head->next = new_arr[new_ind];
                new_arr[new_ind]->prev = head;
                new_arr[new_ind]->next = tmp;
            }
        }
    }
    void insert(const Val& val) = delete;
};

template <typename Val>
class unordered_set: public unordered_set_base<Val> {
    
    auto hash = [](Val& val) {
        __gnu_cxx::hash<const char *> hash;
        return hash(val.c_str());
    };

    void insert() {}
};


template <>
class unordered_set<char *> : public unordered_set_base<char *> {
    __gnu_cxx::hash<const char *> hash;

    void insert(const char* val) {
        if (cells_filled > 2 * cap / 3) {
            rehash(cap * 2);
        }

        size_t hash_code = hash(val);
        size_t index = hash_code / cap;

        Node* node_ptr = new Node;
        node_ptr->val = new char[strlen(val)+1];
        std::strcpy(node_ptr->val, val);
    }
};



int main() {
    __gnu_cxx::hash<std::string> hash;


}