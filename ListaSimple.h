#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED

    #include "Nodo.cpp"



template<class Elem>
class List
{
    private:
        int length;
        Node<Elem>* first;
        Node<Elem>* last;

        void sort_partition(int start, int end);

    public:

        // Constructors

        List();
        List(List<Elem> &in);

        // Setters

        void copy(List<Elem> &in);
        void insertToStart(int pos, Elem a);
        void insertToEnd(Elem a);
        void sort();
        void removeDuplicates();
        void deleteElem(int pos);
        void modify(int pos, Elem a);
        void swap(int pos1, int pos2);
        void empty();
        void reverse();

        // Getters

        bool isEmpty();
        int getLength();
        Node<Elem>* getFirst();
        Elem consult(int pos);

        // Destructors

        ~List();

        // Operators

        Elem &operator [](int pos);
        void operator = (List<Elem> &listToAsign);
        bool operator == (List<Elem> &listToCompare);


};







#endif // LISTASIMPLE_H_INCLUDED
