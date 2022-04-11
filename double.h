#ifndef DOUBLY_H
#define DOUBLY_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class DoubleList : public List<T> {
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes;

    public:
        DoubleList() : List<T>(), nodes(0), head(nullptr), tail(nullptr){
            nodes = 0;
            this->head = this->tail = nullptr;
        }

        ~DoubleList(){ 
         	if(!this->is_empty()){
                Node<T>* temp = this->head;
                while(temp != nullptr){
                    temp = this->head->next;
                    delete head;
                    this->head = temp;
                }
            }            
        }

        // T front(){} // Herencia

        T back(){
            if(!this->is_empty()){
                return this->tail->data;
            } else{
                throw ("Lista vacía");
            }    
        }

        void push_front(T data){ // *
            Node<T>* node = new Node<T>(data);
            node->data = data;
            Node<T>* temp = node;
            node->next = this->head;
            this->head->prev = node;
            this->head = node;
            nodes++;
        }
        
        void push_back(T data){ // *
            Node<T>* node = new Node<T>(data);
            node->data = data;
            Node<T>* temp = node;
            node->prev = tail;
            tail->next = node;
            tail = node;
            nodes++;
        }           
        
        T pop_front(){ // *
            if (!this->is_empty()){
                Node<T>* temp = this->head;
                this->head = this->head->next;
                nodes--;
                T data = temp->data;
                delete temp;
                return data;
            }
            else {
                throw ("Lista vacía.");
            }
        }

        T pop_back(){ // *
            if (!this->is_empty()){
                Node<T>* temp = this->tail;
                this->tail = this->tail->prev;
                nodes--;
                T data = temp->data;
                delete temp;
                return data;
            }
            else {
                throw ("Lista vacía.");
            }
        }

        T insert(T data, int pos){
            if(!this->is_empty() && pos < this->size()){
                Node<T>* temp = this->head;
                for(int i = 0; i < pos - 1; i++){
                    temp = temp->next;
                }
                Node<T>* node = new Node<T>(data);
                node->data = data;
                node->next = temp->next->next;
                temp->next = node;
                node->prev = temp->next;
                temp->next->next->prev = node;
                nodes++;
                return data;
            } else{
                throw ("Lista vacía");
            }
        }

        bool remove(int pos){
            if(!this->is_empty() && pos < this->nodes){
                if(pos == 0){
                    Node<T>* temp = this->head;
                    this->head = this->head->next;
                    delete temp;
                    nodes--;
                    return true;
                } else if(pos == this->nodes - 1){
                    Node<T>* temp = this->tail;
                    this->tail = this->tail->prev;
                    delete temp;
                    nodes--;
                    return true;
                } else{
                    Node<T>* temp = this->head;
                    for(int i = 0; i < pos - 1; i++){
                        temp = temp->next;
                    }
                    T data = temp->data;
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    nodes--;
                    delete temp;
                    return true;
                }    
            } else{
                return false;             
            }
        }

        T& operator[](int pos){
            if(!this->is_empty() && pos < this->size()){
                Node<T>* temp = this->head;
                for(int i = 0; i < pos - 1; i++){
                    temp = temp->next;
                }
                return temp->data;
            } else{
                throw ("Lista vacía");
            }
        }

        bool is_empty(){
            return this->head == nullptr;
        }

        // int size(){} // Herencia

        void clear(){ // *
            if(!this->is_empty()){                
                for(int i = 0; i < this->nodes - 1; i++){
                    Node<T>* temp = this->tail;
                    delete temp;
                    nodes--;
                }
            } else{
                throw ("Lista vacía");
            }
        }

        void sort(){ //
            if(!this->is_empty() /* && this->is_sorted() = false && this->nodes == 1 */){
                Node<T>* temp = this->head;        
                for(int i = 0; i < this->size() - 1; i++){
                    if(temp->data < temp->next->data){
                        temp = temp->next;
                    } else{
                        T aux = temp->data;
                        temp->data = temp->next->data;
                        temp->next->data = aux;
                        temp = temp->next;
                    }
                }
            } else{
                throw ("Lista vacía.");
            }
        }

        bool is_sorted(){ // LISTO
            if(!this->is_empty()){
                T prev = head->data;
                for(Node<T>* temp = head->next; temp!=nullptr; temp=temp->next){
                    if(temp->data < prev)
                        return false;
                    prev = temp->data;
                }
                return true;
            }
            else
                throw("Lista vacía.");
        }

        void reverse(){
            Node<T>* tempHead = this->head;
            Node<T>* tempTail = this->tail;
            for(int i = 0; this->size() % 2; i++){
                this->head->data = tempTail->data;
                this->tail->data = tempHead->data;
                this->head = this->head->next;
                this->tail = this->tail->prev;
            }
        }

        std::string name(){
            return "DoubleList";
        }
        


};

#endif