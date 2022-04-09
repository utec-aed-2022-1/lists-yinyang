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
        ForwardList() : List<T>() { // *
            head = nullptr;
        }

        ~ForwardList(){ // *
            if(!is_empty()){
                Node* temp = head;
                while(temp != nullptr){
                    temp = head->next;
                    delete head;
                    head = temp;
                }
            } 	            
        }

        T front(){ //LISTO
            //throw ("sin definir");
            if(head != nullptr)
                return head->data;
            else
                throw("Lista vacía.")
        }

        T back(){ //LISTO
            //throw ("sin definir");
            Node<T>* temp = head;
            int data;
            if(temp != nullptr){
                while(temp->next != nullptr)
                    temp = temp->next;
                data = temp->data;
                delete temp; 
                return data;
            }
            else
                throw("Lista vacía.")
        }

        void push_front(T data){ // *
            //throw ("sin definir");
            Node<T>* nuevo = new Node<T>(data);
            nuevo->data = data;
            Node* temp = nuevo;
            nuevo->next = head;
            head = nuevo;
            nodes++;
        }

        void push_back(T data){ //LISTO
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

        T pop_front(){ //REVISAR *
            //throw ("sin definir");
            if (!is_empty()) {
                // Node<T>* temp = head;
                // // T data;
                // // data = temp->data;
                // head = head->next;
                // nodes--;
                // delete temp;
                // return data;

                Node<T>* temp = head;
                head = head->next;
                nodes--;
                delete temp;
                return data;


            }
            else {
                throw ("Lista vacía.")
            }
            
        }

        T pop_back(){ //LISTO
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

        T insert(T data, int pos){ //LISTO
            //throw ("sin definir");            
            if(pos == 0)
                push_front(data);
            else{
                Node<T>* temp = head;
                Node<T>* aux = new Node<T>(data);
                for (int n=0; n<pos-1; ++n)
                    temp = temp->next;
                aux->next = temp->next;
                temp->next = aux;
                delete temp;
                delete aux;
            }
            nodes++;
        }

        bool remove(int pos){ //FALTA
            //throw ("sin definir");

        }

        T& operator[](int pos){ //REVISAR
            //throw ("sin definir");
            Node<T>* temp = head;
            int data;
            for (int n = 0; n<pos-1; ++n)
                temp = temp->next;
            data = temp->data;
            delete temp;
            return data;
        }

        bool is_empty(){ //LISTO
            //throw ("sin definir");
            return head == nullptr;
        }

        int size(){ //LISTO
            //throw ("sin definir");
            return nodes;
        }

        void clear(){ //REVISAR
            //throw ("sin definir");
            head = nullptr;
            nodes = 0;
        }
        
        void sort(){ //FALTA
            throw ("sin definir");
        }

        bool is_sorted(){ //LISTO
            //throw ("sin definir");
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

        void reverse(){ //REVISAR
            //throw ("sin definir");
            Node<T>* aux = head;
            T dato;
            for (int n=0; n<nodes; ++n){
                dato = pop_back();
                insert(dato, n);
            }
        }

        std::string name(){
            return "ForwardList";
        }
        
};

#endif