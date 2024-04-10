#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <cstddef>

template<class Elem>
class Node
{
    private:

        Elem info;
        Node<Elem>* next;

    public:

        Node();
        Node(Elem &a);
        Node(Node<Elem>* in, Elem &a);

        Node<Elem>* getNext();
        Elem getInfo();

        void setNext(Node<Elem>* next);
        void setInfo(Elem &info);
};


#endif // NODO_H_INCLUDED
