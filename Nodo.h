#ifndef PRACTICANDO_NODO_H
#define PRACTICANDO_NODO_H

class Node{
public:
    int data;
    Node* next;

    Node(int numero){
        this->data = numero;
        this->next = nullptr;
    }

    void killSelf(){
        this->next = nullptr;
        delete this;
    }
};

#endif //PRACTICANDO_NODO_H
