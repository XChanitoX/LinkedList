#include <iostream>
#include "Lista.h"

using namespace std;

int main() {
    auto lista = new Lista();

    lista->insert(10);
    lista->insert(11);
    lista->insert(12);
    lista->insert(13);
    lista->insert(5);

    lista->remove(13);
    lista->remove(12);
    lista->remove(10);
    lista->remove(12);
    lista->remove(12);
    lista->remove(5);
    lista->remove(11);

    lista->cantidad();

    lista->display();

    return 0;
}
