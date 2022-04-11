#ifndef CIRCULAR_H
#define CIRCULAR_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class CircularList : public List<T> {  
    private:
        Node<T>* head;//sentinel
        int nodes;
    public:
        CircularList() : List<T>() {
            nodes = 0;
            head = new Node<T>();
            head->next = head;
            head->prev = head;
        }

        ~CircularList(){
           // TODO
           delete head;
        }

        T front(){
            if(is_empty())
                throw("Lista vacía.");
            else
                return this->head->next->data;
        };

        T back(){
            if(is_empty())
                throw("Lista vacía.");
            else
                return this->head->prev->data;
        };

        void push_front(T data){
            Node<T>* nuevo = new Node<T>(data);

            head->next->prev = nuevo;
            nuevo->next = head->next;
            nuevo->prev = head;
            head->next = nuevo;

            nodes++;

        };

        void push_back(T data){
            Node<T>* nuevo = new Node<T>(data);

            head->prev->next = nuevo;
            nuevo->prev = head->prev;

            head->prev = nuevo;
            nuevo->next = head;

            nodes++;
        };

        T pop_front(){
            if(is_empty())
                throw("Lista vacía.");
            else{
                T valor = head->next->data;

                head->next = head->next->next;
                delete head->next->prev;
                head->next->prev = head;

                nodes--;
                return valor;
            }
        };

        T pop_back(){
            if(is_empty())
                throw("Lista vacía.");
            else{
                T valor = head->prev->data;

                head->prev = head->prev->prev;
                delete head->prev->next;
                head->prev->next = head;

                nodes--;
                return valor;
            }
        };

        T insert(T data, int pos){
            Node<T>* temp = head->next;

            if(is_empty())
                push_back(data);
            else{
                if(pos+1 <= nodes){
                    Node<T>* nuevo = new Node<T>(data);

                    while(pos != 0){
                        temp = temp->next;
                        pos--;
                    }
                    temp->prev->next = nuevo;
                    nuevo->prev = temp->prev;
                    nuevo->next = temp;
                    temp->prev = nuevo;
                }
                else
                    throw("Posición fuera del rango.");
                
                delete temp;
                return data;             
            }
            
        };

        bool remove(int pos){

            if(pos+1 <= nodes){
                Node<T>* temp = head->next;
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
        }; //debe ser declarado en cada clase hija

        bool is_empty(){
            return head->next == head;
        };

        int size(){
            return nodes;
        };

        void clear(){
            head->next = head;
            head->prev = head;
        };

        void SortFunct(Node<T>* &_head, Node<T>* &tail, T data){//O(n^2)
            Node<T>* aux;
            Node<T>* tmp = _head;
            if (tmp -> data >= data){
                aux = tail -> prev;
                tail -> prev -> next = tail -> next; 
                tail -> next -> prev = tail -> prev;
                push_front(data);
                tail = aux;
                
            }
            else{
                Node<T>* nodo = new Node<T>(data);
                while (tmp != tail && tmp -> next -> data < data ){
                    tmp = tmp -> next;
                }
                if (tmp != tail){
                    // Remover tail de la lista
                    tail -> prev -> next = tail -> next; 
                    tail -> next -> prev = tail -> prev;
                    // Incluir data en valores
                    tmp -> next -> prev = nodo;
                    nodo -> next = tmp -> next;
                    tmp -> next = nodo; 
                    nodo -> prev = tmp;
                }
            } 
        }

        void sort(){
            if (is_empty()){
                throw("Lista vacía");
            }
            else if(nodes == 1){
                return;
            }
            else {
                for(Node<T>* temp=head->next -> next; temp !=head; temp = temp->next){
                    SortFunct(head->next,temp,temp ->data);
                }
            }
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
        };

        void reverse(){
            throw("No implementado.");
        };

        std::string name(){
            return "CircularList";
        }
};

#endif