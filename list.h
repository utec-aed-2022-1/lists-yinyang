#ifndef LIST_H
#define LIST_H

#include "node.h"

// TODO: Implement all methods
template <typename T>
class List {  
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes;

    public:
        List() : head(nullptr), tail(nullptr), nodes(0) {
            nodes = 0;
            this->head = this->tail = nullptr;
        }
        
        virtual ~List(){
            // TODO           
        };
        
        // Contrato
        virtual T front(){
            if(!this->is_empty()){
                return this->head->data;
            } else{
                throw ("Lista vacía");
            }
        }
        virtual T back() = 0;
        virtual void push_front(T) = 0;
        virtual void push_back(T) = 0;
        virtual T pop_front() = 0;
        virtual T pop_back() = 0;
        virtual T insert(T, int) = 0;
        virtual bool remove(int) = 0;
        virtual T& operator[](int) = 0; // debe ser declarado en cada clase hija
        virtual bool is_empty() = 0;
        virtual int size(){
            return this->nodes;
        }
        virtual void clear() = 0;
        virtual void sort() = 0;
        virtual bool is_sorted() = 0;
        virtual void reverse() = 0;
        virtual std::string name() = 0;
};


#endif