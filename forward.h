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
        ForwardList() : List<T>() {}

        ~ForwardList(){ 
         	// TODO            
        }

        T front(){
            throw ("sin definir");

        }

        T back(){
            throw ("sin definir");
        }

        void push_front(T data){
            //throw ("sin definir");
            Node<T>* nuevo = new Node<T>(data);
            nuevo->data = data;
            head = nuevo;
            nodes++;
        }

        void push_back(T data){
            //throw ("sin definir");
            Node<T>* nuevo = new Node<T>;
            nuevo->data = data;
            if (head == nullptr)
                head = nuevo;
            else{
                Node<T>* temp = head;
                while(temp->next != nullptr) // Si el siguiente no apunta a nullptr
                    temp = temp->next;           // Se pasa al siguiente elemento
                temp->next = nuevo;
                nuevo->next = nullptr
                nodes++;
                delete temp;
            }
        }

        T pop_front(){ //REVISAR
            //throw ("sin definir");
            if (head != nullptr) {
                Node<T>* temp = head;
                T data;
                data = temp->data;
                head = head->next;
                nodes--;
                delete temp;
                return data;
            }
            else {
                throw("Lista vacía.")
            }
            
        }

        T pop_back(){
            //throw ("sin definir");
            if (head != nullptr){
                Node<T>* temp = head;
                T data;

                if (temp->next != nullptr)
                    while(temp->next->next != nullptr)
                        temp = temp->next;

                    data = temp->next->data;
                    delete temp->next;
                    temp->next = nullptr;

                else{
                    data = head->data
                    head = nullptr;
                    delete temp;
                }
                nodes--;
                return data;
            }
            else
                throw("Lista vacía.")
        }

        T insert(T data, int pos){
            //throw ("sin definir");
        }

        bool remove(int pos){
            throw ("sin definir");
        }

        T& operator[](int pos){
            throw ("sin definir");
        }

        bool is_empty(){
            //throw ("sin definir");
            return head == nullptr;
        }

        int size(){
            //throw ("sin definir");
            return nodes;
        }

        void clear(){ //REVISAR
            //throw ("sin definir");
            head = nullptr;
            nodes = 0;
        }
        
        void sort(){
            throw ("sin definir");
        }

        bool is_sorted(){
            throw ("sin definir");
        }

        void reverse(){
            //throw ("sin definir");

        }

        std::string name(){
            return "ForwardList";
        }
        
};

#endif