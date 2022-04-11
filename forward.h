#ifndef FORWARD_H
#define FORWARD_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class ForwardList : public List<T> {
    private:
        Node<T>* head;
        int nodes;

    public:
        ForwardList() : List<T>(), nodes(0), head(nullptr){ // *
            nodes = 0;
            this->head = nullptr;
        }

        ~ForwardList(){ // *
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

        T back(){ // *            
            if(!this->is_empty()){
                Node<T>* temp = this->head;
                for(int i = 0; i < this->nodes - 1; i++){
                    temp = temp->next;
                }
                return temp->data;
            } else{
                throw ("Lista vacía");
            } 
        }

        void push_front(T data){ // *
            Node<T>* node = new Node<T>(data);
            node->data = data;
            Node<T>* temp = node;
            node->next = head;
            head = node;
            nodes++;
        }

        void push_back(T data){ // *
            if(!this->is_empty()){
                Node<T>* temp = this->head;
                for(int i = 0; i < this->nodes - 1; i++){
                    temp = temp->next;
                }
                Node<T>* node = new Node<T>(data);
                temp->next = node;                
                nodes++;
                // return node->data;
            } else{
                throw ("Lista vacía");
            }
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
            if(!this->is_empty()){
                Node<T>* temp = this->head;
                for(int i = 0; i < this->nodes - 1; i++){
                    temp = temp->next;
                }
                T data = temp->data;
                delete temp;
                nodes--;
                return data;
            } else{
                throw ("Lista vacía");
            }
        }

        T insert(T data, int pos){
            if(!this->is_empty() && pos < this->nodes){
                Node<T>* temp = this->head;
                for(int i = 0; i < pos - 1; i++){
                    temp = temp->next;
                }
                Node<T>* node = new Node<T>(data);
                node->next = temp->next->next;
                temp->next = node;          
                nodes++;
                return data;
            } else{
                throw ("Lista vacía");
            }
        }

        bool remove(int pos){ // *
            if(!this->is_empty() && pos < this->nodes){
                Node<T>* temp = this->head;
                for(int i = 0; i < pos - 1; i++){
                    temp = temp->next;
                }
                Node<T>* node = temp->next;
                temp->next = temp->next->next;
                delete node;
                nodes--;
                return true;
            } else{
                throw ("Lista vacía");
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
                throw ("Lista vacía.");
            }
        }

        bool is_empty(){
            return this->head == nullptr;
        }

        // int size(){} // Herencia

        void clear(){ // *            
            if(!this->is_empty()){
                for(int i = 0; i < this->nodes - 1; i++){
                    Node<T>* temp = this->head;
                    this->head = this->head->next;
                    delete temp;
                    nodes--;
                }
            } else{
                throw ("Lista vacía");
            }
        }
        
        void sort(){ //
            if(!this->is_empty() /* && this->is_sorted() = false && this->nodes == 1*/){
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


            // Node<T> *prev1,*prev2,*tmp2;
            // prev1 = head;
            // bool flag;

            // for (Node<T>* tmp1 = head -> next; tmp1 != nullptr; tmp1 = tmp1 -> next){
            //     flag = true;
            //     tmp2 = head; prev2 = head;
            //     while(tmp1 != tmp2){
            //         if ((tmp2 == head) && (tmp1 -> data <= tmp2 -> data)){
            //             push_front(tmp1 -> data);
            //             prev1 -> next = tmp1 -> next;
            //             flag = false;
            //             break;
            //         }
            //         else if (tmp1 -> data <= tmp2 -> data){
            //             prev1 -> next = tmp1 -> next; 
            //             prev2 -> next = tmp1;
            //             tmp1 -> next = tmp2;
            //             flag = false;
            //             break;
            //         }
            //         else {
            //             if (tmp2 != head){prev2 = tmp2;};
            //             tmp2 = tmp2 -> next;
            //         }
            //     }
            //     if (flag == true){
            //         prev1 = tmp1; 
            //     }

            // }
        }

        bool is_sorted(){ // LISTO
            if(head != nullptr){
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

        void reverse(){ // REVISAR
            Node<T>* temp = this->head;
            T dato;
            for (int n = 0; n < nodes; ++n){
                dato = pop_back();
                insert(dato, n);
            }
        }

        std::string name(){
            return "ForwardList";
        }
        
};

#endif