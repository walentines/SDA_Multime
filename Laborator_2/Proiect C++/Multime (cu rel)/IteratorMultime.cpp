#include "IteratorMultime.h"
#include "Multime.h"


IteratorMultime::IteratorMultime(const Multime& m): mult(m) {
    curent = m.head;
    h = m.head;
}

TElem IteratorMultime::element() const {
	if(valid()){
        return curent -> valoare;
    }
    return -1;
}

bool IteratorMultime::valid() const {
	return curent != nullptr;
}

void IteratorMultime::urmator() {
	curent = curent -> next;
}

void IteratorMultime::prim() {
	curent = h;
}

