#include "Multime.h"
#include "IteratorMultime.h"
#include <iostream>

#define NULL_TELEM 9999999
using namespace std;

//o posibila relatie
bool rel(TElem e1, TElem e2) {
	return e1 <= e2;
}

Multime::Multime() {
	head = nullptr;

    lungime = 0;
}


bool Multime::adauga(TElem elem) {
	Node* temp = head;
    Node* add = new Node;

    add -> valoare = elem;
    add -> next = nullptr;

    if(lungime == 0){
        head = add;
        lungime++;
        return true;
    }
    if(head -> valoare > add -> valoare){
        add -> next = head;
        head = add;
        lungime++;
        return true;
    }
    else if(head -> valoare == add -> valoare){
        return false;
    }

    while(temp -> next != nullptr && rel(temp -> next -> valoare, add -> valoare)){
        if(temp -> next -> valoare == add -> valoare){
            return false;
        }
        temp = temp -> next;
    }
    add -> next = temp -> next;
    temp -> next = add;

    lungime++;

	return true;
}


bool Multime::sterge(TElem elem) {
	Node *temp = head, *n_elem, *ultim;
    if(head == nullptr){
        return false;
    }
    if(head -> valoare == elem){
        head = head -> next;
        lungime--;
        return true;
    }

    while(temp -> next != nullptr){
        if(temp -> next -> valoare == elem){
            n_elem = temp -> next;
            temp -> next = temp -> next -> next;
            free(n_elem);
            lungime--;
            return true;
        }
        ultim = temp;
        temp = temp -> next;
    }
    if(temp -> valoare == elem){
        ultim -> next = nullptr;
        free(temp);
        lungime--;
        return true;
    }
	return false;
}


bool Multime::cauta(TElem elem) const {
	Node* temp = head;
    while(temp != nullptr){
        if(temp -> valoare == elem){
            return true;
        }
        temp = temp -> next;
    }
	return false;
}


int Multime::dim() const {
	return lungime;
}



bool Multime::vida() const {
	return lungime == 0;
}

IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}


Multime::~Multime() {
	Node* temp = head, *aux;
    if(head == nullptr){
        return;
    }
    while(temp -> next != nullptr){
        aux = temp -> next;
        free(temp);
        temp = aux;
    }
    free(temp);
}

void Multime::Afisare(){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp -> valoare << " ";
        temp = temp -> next;
    }
}






