#include "Nodo.h"




//                      -- Constructors --

template<class Elem>
Node<Elem>::Node()
{
    this->next = NULL;
}

template<class Elem>
Node<Elem>::Node(Elem &a)
{
    this->info = a;
    this->next = NULL;
}

template<class Elem>
Node<Elem>::Node(Node<Elem>* in, Elem &a)
{
    this->info = a;
    this->next = NULL;
}



//                       -- Setters --

template<class Elem>
void Node<Elem>::setInfo(Elem &a)
{
    this->info = a;
}

template<class Elem>
void Node<Elem>::setNext(Node<Elem>* next)
{
    this->next = next;
}

//                       -- Getters --

template<class Elem>
Elem Node<Elem>::getInfo()
{
    return this->info;
}

template<class Elem>
Node<Elem>* Node<Elem>::getNext()
{
    return this->next;
}
