#include<iostream>
#include"list.cpp"


int main(){
    list<int> l;
    l.push_back(10);
    l.push_back(3);
    l.push_back(12);
    l.push_back(3);
    l.push_back(14);
    l.push_back(15);
    l.push_back(3);
    l.push_back(17);
    l.push_back(3);
    l.remove(3);
    list<int>::iterator it = l.begin();
    for(it; it != l.end(); ++it){
        std::cout<<*it<<" ";
    }
    int b = l.size();
    std::cout<<std::endl<<b;

    l.push_front(3);
    std::cout<<std::endl;
    list<int>::iterator i = l.begin();
    for(i; i != l.end(); ++i){
        std::cout<<*i<<" ";
    }
    int a = l.size();
    std::cout<<std::endl<<a;
    
    return 0;
}