#ifndef mList
#define mList

#include"list.h"

template<class T>
list<T>::list(){
    l = nullptr;
    lSize = 0;
}

template<class T>
list<T>::list(const int sz, const T val){
    l = nullptr;
    lSize = sz;
    for(int i = 0; i < sz; ++i){
        push_back(val);
    }
}

template<class T>
void list<T>::push_back(const T& val){
    ++lSize;
    Node* ptr = new Node;
    ptr->val = val;
    ptr->last = l;
    ptr->next = nullptr;
    if(lSize > 1)
        ptr->last->next = ptr;
    l = ptr;
}

template<class T>
void list<T>::pop_back(){
    Node* p = l->last;
    delete l;
    l = p;
    --lSize;
    p = nullptr;
}

template<class T>
void list<T>::push_front(const T& val){
    Node* ptr = new Node;
    if(l == nullptr){
        ptr->val = val;
        ptr->last = nullptr;
        ptr->next = nullptr;
        ++lSize;
    }
    Node* pointer = l;
    for(int i = 0; pointer->last != nullptr; ++i){
        pointer = pointer-> last;
    }
    pointer->last = ptr;
    ptr->val = val;
    ptr->next = pointer;
    ptr->last = nullptr;
    ++lSize;
}

template<class T>
list<T>::list(const list<T>& obj){
    list<T>::Node* p = obj.f();
    for(int i = 0; p->last != nullptr; ++i){
        push_front(p->val);
        p = p->last;
    }
}

template<class T>
list<T>::list(list<T>&& obj){
    list<T>::Node* p = obj.f();
    for(int i = 0; p->last != nullptr; ++i){
        push_front(p->val);
        p = p->last;
    }
    p = obj.f();
    p.clear();
}

template<class T>
void list<T>::pop_front(){
    Node* pointer = l;
    for(int i = 0; pointer->last != nullptr; ++i){
        pointer = pointer-> last;
    }
    Node* temp = pointer->next;
    temp->last = nullptr;
    delete pointer;
    --lSize;
}

template<class T>
void list<T>::clear(){
    Node* ptr = nullptr;
    for(int i = 0; l != nullptr; ++i){
        ptr = l;
        l = ptr-> last;
        delete ptr;
    }
    ptr = nullptr;
    lSize = 0;
}

template<class T>
void list<T>::remove(const T& val){
    Node* ptr = l;
    for(int i = lSize; i >= 0; --i){
        if(ptr->next == nullptr && ptr->val == val){
            ptr->last->next = nullptr;
            l = ptr->last;
            delete ptr;
            ptr = l;
            --lSize;
        }
        if(ptr->next == nullptr && ptr->val != val)
            ptr = ptr->last;
        if(ptr->last == nullptr && ptr->val == val){
            ptr->next->last = nullptr;
            delete ptr;
            --lSize;
        }
        if(ptr->next != nullptr && ptr->last != nullptr && ptr->val == val){
            ptr->last->next = ptr->next;
            ptr->next->last = ptr->last;
            Node* p = ptr->last;
            delete ptr;
            ptr = p;
            --lSize;
        }
        if(ptr->next != nullptr && ptr->last != nullptr && ptr->val != val)
            ptr = ptr->last;
    }
}

template<class T>
list<T>& list<T>::operator= (const list<T>& obj){
    if(this == &obj)
        return *this;
    if(lSize > 0)
        clear();
    list<T>::Node* p = obj.f();
    for(int i = 0; p->last != nullptr; ++i){
        push_front(p->val);
        p = p->last;
    }
}

template<class T>
list<T>& list<T>::operator= (list<T>&& obj){
    if(this == &obj)
        return *this;
    if(lSize > 0)
        clear();
    list<T>::Node* p = obj.f();
    for(int i = 0; p->last != nullptr; ++i){
        push_front(p->val);
        p = p->last;
    }
    p = obj.f();
    p.clear();
}

#endif