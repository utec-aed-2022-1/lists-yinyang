#ifndef CIRCULAR_H
#define CIRCULAR_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class CircularList : public List<T> {  
    private:
        Node<T>* head; // sentinel
        int nodes;
    public:
        CircularList() : List<T>(), nodes(0), head(nullptr) {
            this->nodes = 0;
            this->head = new Node<T>();
            this->head->next = head;
            this->head->prev = head;
        }

        ~CircularList(){
           this->clear();
           delete this->head;
        }

        T front(){
            if(!this->is_empty()){
                return this->head->data;
            } else{
                throw ("Lista vacía");
            }
        }

        T back(){
            if(is_empty())
                throw("Lista vacía.");
            else
                return this->head->prev->data;
        }

        void push_front(T data){
            Node<T>* node = new Node<T>(data);
            node->data = data;
            node->next = this->head->next;
            node->prev = this->head;
            if(this->is_empty()){
                this->head->prev = node;
            } else{
                this->head->next->prev = node;
            }
            this->head->next = node;
            nodes++;
        }

        void push_back(T data){
            Node<T>* nuevo = new Node<T>(data);

            head->prev->next = nuevo;
            nuevo->prev = head->prev;

            head->prev = nuevo;
            nuevo->next = head;

            nodes++;
        }

        T pop_front(){
            if(!this->is_empty()){
                T data = this->head->next->data;
                this->head->next = this->head->next->next;
                delete this->head->next->prev;
                this->head->next->prev = this->head;
                this->nodes--;
                return data;
            }
            else{
                throw("Lista vacía.");
            }
        }

        T pop_back(){
            if(!this->is_empty()){
                T data = this->head->prev->data;

                this->head->prev = this->head->prev->prev;
                delete this->head->prev->next;
                this->head->prev->next = head;

                nodes--;
                return data;
            }
            else{
                throw("Lista vacía.");
            }
        }

        T insert(T data, int pos){
            Node<T>* temp = this->head->next;
            if(this->is_empty() && pos == 0){
                this->push_back(data);
                return data;
            } else{
                if(pos+1 <= this->nodes){
                    Node<T>* node = new Node<T>(data);
                    while(pos){
                        temp = temp->next;
                        pos--;
                    }
                    temp->prev->next = node;
                    node->prev = temp->prev;
                    node->next = temp;
                    temp->prev = node;
                    this->nodes++;
                } else{
                    throw("Posición fuera del rango.");
                }
                return data;             
            }
        }

        bool remove(int pos){
            if(pos+1 <= nodes){
                Node<T>* temp = this->head->next;
                while(pos == 0){
                    temp = temp->next;
                    pos--;
                }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                return true;
            }
            else
                return false;

        }

        T& operator[](int pos){
            Node<T>* tmp = head->next;
            for (int n = 0; n < pos; n++){ 
                tmp = tmp -> next;
            }  
            return tmp -> data;
        }

        bool is_empty(){
            return this->head->next == this->head;
        }

        int size(){
            return this->nodes;
        }

        void clear(){
            if(!this->is_empty()){
                int iter = this->size();
                for(int i = 0; i < iter; i++){
                    Node<T>* temp = this->head->next;
                    this->head->next = temp->next;
                    delete temp;
                    this->nodes--;
                }
                this->head->prev = this->head;
            }
        }

        // // void SortFunct(Node<T>* &_head, Node<T>* &tail, T data){//O(n^2)
        //     Node<T>* aux;
        //     Node<T>* tmp = _head;
        //     if (tmp -> data >= data){
        //         aux = tail -> prev;
        //         tail -> prev -> next = tail -> next; 
        //         tail -> next -> prev = tail -> prev;
        //         this->push_front(data);
        //         tail = aux;
                
        //     }
        //     else{
        //         Node<T>* nodo = new Node<T>(data);
        //         while (tmp != tail && tmp -> next -> data < data ){
        //             tmp = tmp -> next;
        //         }
        //         if (tmp != tail){
        //             // Remover tail de la lista
        //             tail -> prev -> next = tail -> next; 
        //             tail -> next -> prev = tail -> prev;
        //             // Incluir data en valores
        //             tmp -> next -> prev = nodo;
        //             nodo -> next = tmp -> next;
        //             tmp -> next = nodo; 
        //             nodo -> prev = tmp;
        //         }
        //     } 
        // }

        void sort(){
            if(!this->is_empty()){
                bool isSorted = this->is_sorted();
                while(!isSorted){
                    isSorted = true;
                    Node<T>* temp = this->head->next;      
                    while(temp != this->head && temp->next != this->head){
                        if(temp->data > temp->next->data){
                            T aux = temp->data;
                            temp->data = temp->next->data;
                            temp->next->data = aux;
                            temp = temp->next;
                            isSorted = false;
                        }
                        temp = temp->next;
                    }
                }
            } else{
                throw ("Lista vacía.");
            }
            // if (this->is_empty()){
            //     throw("Lista vacía");
            // }
            // else if(this->nodes == 1){
            //     return;
            // }
            // else {
            //     for(Node<T>* temp = this->head->next->next; temp != this->head; temp = temp->next){
            //         SortFunct(this->head->next,temp,temp->data);
            //     }
            // }
        }

        bool is_sorted(){
            if(!is_empty()){
                Node<T>* temp = head->next->next;
                while(temp != head){
                    if(temp->data > temp->prev->data)
                        temp = temp->next;
                    else
                        return false;
                }
                return true;
            }
            else
                throw("Lista vacía.");
        }

        void reverse(){
            throw("No implementado.");
        }

        std::string name(){
            return "CircularList";
        }
};

#endif