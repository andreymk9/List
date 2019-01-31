#include<iostream>
template<class T>
class list{
    public:
        struct Node{
            T val;
            Node* next;
            Node* last;
        };

        class iterator{
                Node* p;
                bool check = 0;
            public:
                iterator(Node* add): p(add){}
                iterator(): p(nullptr) {}
                Node* f() {return p;}
                void operator= (Node* add) { p = add;}
                bool operator!= (Node* add) {
                    if(p == nullptr){
                        return 0;
                    }
                    else return 1;
                }
                T operator* () {return p->val;}
                void operator++ () {p = p->next;}
        };

        list();
        list(const int sz, const T val);
        list(const list<T>& obj);
        list(list<T>&& obj);
        void push_back(const T& val);
        void pop_back();
        void push_front(const T& val);
        void pop_front();
        void remove(const T& val);
        void clear();
        bool empty() {if(lSize > 0) return 0; return 1;}
        int size() {return lSize;}
        Node* begin(){
            Node* p = l;
            for(int i = 0; p->last != nullptr; ++i)
                p = p-> last;
            return p;
        }
        Node* end(){return l;}
        list<T>& operator= (const list<T>& obj);
        list<T>& operator= (list<T>&& obj); 
    private:       
        int lSize;
        Node* l;    
};