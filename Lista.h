#ifndef PRACTICANDO_LISTA_H
#define PRACTICANDO_LISTA_H
#include "Nodo.h"

using namespace std;

class Lista{
private:
    Node* head;
    int cantidadNodos;

public:
    Lista(){
        this->head = nullptr;
        this->cantidadNodos = 0;
    }

    void cantidad(){
        if (cantidadNodos == 0)
            cout << "La lista esta vacia" << endl;
        cout << "La cantidad de nodos es: " << cantidadNodos << endl;
    }

    void insert(int data){
        Node* temporal = head;
        Node* nuevoNodo = new Node(data);
        if (this->head == nullptr){
            this->head = nuevoNodo;
        }
        else{
            if (temporal->next == nullptr){
                if (temporal->data < nuevoNodo->data){
                    temporal->next = nuevoNodo;
                }else{
                    nuevoNodo->next = temporal;
                    this->head = nuevoNodo;
                }
            }else{
                if (temporal->data > nuevoNodo->data){
                    nuevoNodo->next = temporal;
                    this->head = nuevoNodo;
                }
                else{
                    while(temporal->next != nullptr && temporal->next->data < nuevoNodo->data){
                        temporal = temporal->next;
                    }
                    nuevoNodo->next = temporal->next;
                    temporal->next = nuevoNodo;
                }
            }
        }
        cantidadNodos++;
    }

    void remove(int numero){
        Node* temporal = head;
        bool alerta = false;
        if (temporal->data == numero){
            head = head->next;
            temporal->killSelf();
            alerta = true;
        }else{
            while(temporal->next != nullptr){
                if (temporal->next->data == numero){
                    Node* nodoEliminar = temporal->next;
                    temporal->next = nodoEliminar->next;
                    nodoEliminar->killSelf();
                    alerta = true;
                    break;
                }
                temporal = temporal->next;
            }
        }
        if (alerta){
            cantidadNodos--;
            cout << "El valor " << numero << " ha sido eliminado correctamente" << endl;
        }
        else
            cout << "El valor " << numero << " no existe en la lista" << endl;
    }

    void display(){
        Node* temporal = head;
        while (temporal != nullptr && temporal->next != nullptr){
            cout << temporal->data << " -> ";
            temporal = temporal->next;
        }
        if (temporal)
            cout << temporal->data;
    }
};

#endif //PRACTICANDO_LISTA_H
