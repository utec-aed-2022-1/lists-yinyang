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
<<<<<<< HEAD
        ForwardList() : List<T>(), nodes(0), head(nullptr){ // *
            nodes = 0;
            this->head = nullptr;
        }

        ~ForwardList(){ // *
            if(!this->is_empty()){
                Node<T>* temp = this->head;
=======
        ForwardList() : List<T>(), nodes(0), head(nullptr) { // *
            //head = nullptr;
        }

        ~ForwardList(){ // *
            if(!is_empty()){
                Node<T>* temp = head;
>>>>>>> 6cda62992bea34d88e9aa1657ef64bc630cd6455
                while(temp != nullptr){
                    temp = this->head->next;
                    delete head;
                    this->head = temp;
                }
            } 	            
        }

<<<<<<< HEAD
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
=======
        T front(){ //LISTO
            //throw ("sin definir");
            if(head != nullptr)
                return head->data;
            else
                throw("Lista vacía.");
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
                throw("Lista vacía.");
        }

        void push_front(T data){ // *
            //throw ("sin definir");
            Node<T>* nuevo = new Node<T>(data);
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
                    temp = temp->next;       // Se pasa al siguiente elemento
                temp->next = nuevo;
                nuevo->next = nullptr;
>>>>>>> 6cda62992bea34d88e9aa1657ef64bc630cd6455
                nodes++;
                // return node->data;
            } else{
                throw ("Lista vacía");
            }
        }

<<<<<<< HEAD
        T pop_front(){ // *
            if (!this->is_empty()){
                Node<T>* temp = this->head;
                this->head = this->head->next;
=======
        T pop_front(){ //REVISAR *
            //throw ("sin definir");
            if (!is_empty()) {
                Node<T>* temp = head;
                T data;
                data = temp->data;
                head = head->next;
>>>>>>> 6cda62992bea34d88e9aa1657ef64bc630cd6455
                nodes--;
                T data = temp->data;
                delete temp;
                return data;
<<<<<<< HEAD
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
=======

                // Node<T>* temp = head;
                // head = head->next;
                // nodes--;
                // delete temp;
                // return data;


            }
            else {
                throw ("Lista vacía.");
            }
            
        }

        T pop_back(){ //LISTO
            //throw ("sin definir");
            // if (head != nullptr){
            //     Node<T>* temp = head;
            //     T data;

            //     if (temp->next != nullptr){
            //         while(temp->next->next != nullptr)
            //             temp = temp->next;
            //         data = temp->next->data;
            //         delete temp->next;
            //         temp->next = nullptr;
            //     }
                    
            //     else{
            //         data = head->data;
            //         head = nullptr;                    
            //     }
            //     nodes--;
            //     delete temp;
            //     return data;
            // }
            // else
            //     throw("Lista vacía.");
            Node<T>* tmp = head;
            T data; 
            if (tmp != nullptr ){
                if (tmp -> next == nullptr){
                    
                    data = tmp -> data; 
                    tmp = nullptr;
                    delete tmp; 
                    head = nullptr;
                }
                else{
                    while(tmp -> next -> next != nullptr){ 
                        tmp = tmp -> next;
                    }
                    data = tmp -> next -> data;
                    tmp -> next = nullptr;
                    delete tmp -> next;

>>>>>>> 6cda62992bea34d88e9aa1657ef64bc630cd6455
                }
                T data = temp->data;
                delete temp;
                nodes--;
                return data;
            } else{
                throw ("Lista vacía");
            }
<<<<<<< HEAD
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
=======
            else{
                throw("Lista vacía");
            }
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
            return data;
        }

        bool remove(int pos){ //FALTA
            throw ("sin definir");

        }

        T& operator[](int pos){ //REVISAR
            //throw ("sin definir");
            Node<T>* temp = head;
            //T data;
            for (int n = 0; n<pos-1; ++n)
                temp = temp->next;
            //data = temp->data;
            //delete temp;
            return temp->data;
        }

        bool is_empty(){ //LISTO
            //throw ("sin definir");
            return head == nullptr;
        }

        int size(){ //LISTO
            //throw ("sin definir");
            return nodes;
        }
>>>>>>> 6cda62992bea34d88e9aa1657ef64bc630cd6455

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
        
<<<<<<< HEAD
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
=======
        void sort(){ //FALTA
            //throw ("sin definir");
            Node<T> *prev1,*prev2,*tmp2;
            prev1 = head;
            bool flag;

            for (Node<T>* tmp1 = head -> next; tmp1 != nullptr; tmp1 = tmp1 -> next){
                flag = true;
                tmp2 = head; prev2 = head;
                while(tmp1 != tmp2){
                    if ((tmp2 == head) && (tmp1 -> data <= tmp2 -> data)){
                        push_front(tmp1 -> data);
                        prev1 -> next = tmp1 -> next;
                        flag = false;
                        break;
                    }
                    else if (tmp1 -> data <= tmp2 -> data){
                        prev1 -> next = tmp1 -> next; 
                        prev2 -> next = tmp1;
                        tmp1 -> next = tmp2;
                        flag = false;
                        break;
                    }
                    else {
                        if (tmp2 != head){prev2 = tmp2;};
                        tmp2 = tmp2 -> next;
                    }
                }
                if (flag == true){
                    prev1 = tmp1; 
                }

            }
        }

        bool is_sorted(){ //LISTO
            //throw ("sin definir");
>>>>>>> 6cda62992bea34d88e9aa1657ef64bc630cd6455
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

<<<<<<< HEAD
        void reverse(){ // REVISAR
            Node<T>* temp = this->head;
            T dato;
            for (int n = 0; n < nodes; ++n){
=======
        void reverse(){ //REVISAR
            //throw ("sin definir");
            Node<T>* aux = head;
            T dato;
            for (int n=0; n<nodes; ++n){
>>>>>>> 6cda62992bea34d88e9aa1657ef64bc630cd6455
                dato = pop_back();
                insert(dato, n);
            }
        }

        std::string name(){
            return "ForwardList";
        }
        
};

#endif