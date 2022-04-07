#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(){
        // TODO
        data = 0;
        next = prev = nullptr;
    }

    Node(T value){
        // TODO
        data = value;
        next = prev = nullptr;
    }

    void killSelf(){
        // TODO
        delete next;
        delete prev;
    }    
};

#endif