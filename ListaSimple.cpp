
    #include "ListaSimple.h"


//                  -- Constructors --

template<class Elem>
List<Elem>::List()
{
    this->first = NULL;
    this->last = NULL;
    this->length = 0;
}

template<class Elem>
List<Elem>::List(List<Elem> &in)
{
    int inLength = in.getLength();
    Elem inInfo;

    if(this->length>0)
    {
        this->empty();
    }

    for(int i=1; i<=inLength ; i++)
    {
        inInfo = in.consult(i);
        this->insertToStart(i, inInfo);
    }
}


//                     -- Getters --

template<class Elem>
int List<Elem>::getLength()
{
    return this->length;
}

template<class Elem>
bool List<Elem>::isEmpty()
{
    return this->length == 0;
}

template<class Elem>
Elem List<Elem>::consult(int pos)
{
    Elem res;
    Node<Elem>* aux;

    if(pos>0 && pos<=this->length)
    {
        if(pos==1)
        {
            res = this->first->getInfo();
        }
        else if(pos==this->length)
        {
            res = this->last->getInfo();
        }
        else
        {
            aux= this->first;
            for(int i=1; i<pos; i++)
            {
                aux = aux->getNext();
            }

            res = aux->getInfo();
        }
    }

    return res;
}

template<class Elem>
Node<Elem>* List<Elem>::getFirst()
{
    return this->first;
}

//                      -- Setters --

template<class Elem>
void List<Elem>::copy(List<Elem> &in)
{
    int inLength = in.getLength();
    Elem inInfo;

    if(this->length>0)
    {
        this->empty();
    }

    for(int i=1; i<=inLength ; i++)
    {
        inInfo = in.consult(i);
        this->insertToStart(i, inInfo);
    }
}


template<class Elem>
void List<Elem>::insertToStart(int pos, Elem a)
{
    Node<Elem>* newNode, *aux;
    int end = this->length+1;

    if(pos>0 && pos<=end)
    {
        newNode = new Node<Elem>;
        newNode->setInfo(a);

        if(pos==1)
        {
            newNode->setNext(this->first);
            this->first = newNode;
            if(this->length <= 1)
            {
                this->last = this->first;
            }

        }
        else if(pos==end)
        {
            this->last->setNext(newNode);
            this->last = newNode;
        }
        else
        {
            aux = this->first;

            for(int i=1; i<pos-1; i++)
            {
                aux = aux->getNext();
            }

            newNode->setNext(aux->getNext());
            aux->setNext(newNode);
        }

        this->length += 1;
    }
}

template<class Elem>
void List<Elem>::insertToEnd(Elem a)
{
    Node<Elem>* newNode;

    newNode = new Node<Elem>;
    newNode->setInfo(a);

    if(this->last == NULL)
    {
        this->first = newNode;
        this->last = this->first;
    }
    else
    {
        this->last->setNext(newNode);
        this->last = newNode;
    }

    this->length+=1;

}


template<class Elem>
void List<Elem>::deleteElem(int pos)
{
    Node<Elem>* aux, *auxdel;

    if(pos>0 && pos<=this->length)
    {
        if(pos==1)
        {
            aux = this->first->getNext();
            delete this->first;

            this->first = aux;
        }
        else
        {
            aux = this->first;
            for(int i=1; i< pos-1; i++)
            {
                aux = aux->getNext();
            }

            if(pos==this->length)
            {
                this->last = aux;
                delete aux;
                this->last->setNext(NULL);
            }
            else
            {
                auxdel = aux->getNext();
                aux->setNext(auxdel->getNext());
                delete auxdel;
            }


        }

        this->length -= 1;
    }
}

template<class Elem>
void List<Elem>::swap(int pos1, int pos2)
{
    Elem info_aux, info_aux2;
    Node<Elem>* nAux, *nAux2;
    if((pos1>0 && pos1<=this->length) && (pos2>0 && pos2<=this->length && pos2!=pos1))
    {
        if(pos1==1)
        {
            info_aux = this->first->getInfo();

            if(pos2==this->length)
            {
                info_aux2 = this->last->getInfo();
                this->first->setInfo(info_aux2);
                this->last->setInfo(info_aux);
            }
            else
            {
                nAux = this->first;
                for(int i=1; i<pos2; i++)
                {
                    nAux = nAux->getNext();
                }

                info_aux2 = nAux->getInfo();
                this->first->setInfo(info_aux2);
                nAux->setInfo(info_aux);

            }

        }
        else if(pos1==this->length)
        {
            info_aux = this->last->getInfo();

            if(pos2==1)
            {
                info_aux2 = this->first->getInfo();
                this->last->setInfo(info_aux2);
                this->first->setInfo(info_aux);
            }
            else
            {
                nAux = this->first;
                for(int i=1; i<pos2; i++)
                {
                    nAux = nAux->getNext();
                }

                info_aux2 = nAux->getInfo();
                this->last->setInfo(info_aux2);
                nAux->setInfo(info_aux);

            }
        }
        else
        {


            nAux = this->first;
            nAux2= this->first;

            for(int i=1; i<pos1; i++)
            {
                nAux = nAux->getNext();
            }

            for(int i=1; i<pos2; i++)
            {
                nAux2 = nAux2->getNext();
            }

            info_aux = nAux->getInfo();
            info_aux2 = nAux2->getInfo();
            nAux->setInfo(info_aux2);
            nAux2->setInfo(info_aux);
        }
    }
}

/*
template<class Elem>
void List<Elem>::sort()
{

}
*/

template<class Elem>
void List<Elem>::removeDuplicates()
{
    Node<Elem>* act = this->first;
    Node<Elem>* actAhead = act->getNext();
    Node<Elem>* aux;
    Elem actInfo, actAheadInfo;

    while(act!=NULL && actAhead!= NULL && this->length)
    {
        actInfo = act->getInfo();
        actAheadInfo = actAhead->getInfo();

        if(actInfo == actAheadInfo)
        {
            aux = actAhead->getNext();
            act->setNext(aux);
            delete actAhead;
            this->length -=1;

            actAhead = aux;

        }
        else
        {
            act = act->getNext();
            actAhead = actAhead->getNext();
        }
    }
}

template<class Elem>
void List<Elem>::empty()
{
    while(!this->isEmpty())
    {
        this->deleteElem(1);
    }
}

template<class Elem>
List<Elem>::~List()
{
    this->empty();
}


//          -- Utils --

template<class Elem>
List<Elem>* sortedIntersect(List<Elem>& a, List<Elem>& b)
{
    List<Elem>* res = new List<Elem>;
    List<Elem> opList, compList;

    int aInfo, bInfo;
    bool band = true;

    opList.copy(a);
    compList.copy(b);

    int cont= 1;

    while(band)
    {
        aInfo = compList.consult(1);
        bInfo = opList.consult(1);

        if(aInfo == bInfo)
        {
            if(opList.isEmpty())
            {
                band=false;
            }
            else
            {
                res->insertToEnd(aInfo);
                opList.deleteElem(1);
            }
        }
        else
        {
            if(cont == compList.getLength())
            {
                opList.deleteElem(1);
                cont=1;
            }
            else
            {
                compList.insertToEnd(aInfo);
                compList.deleteElem(1);
                cont++;
            }

        }

    }

    return res;
}

template<class Elem>
bool esEquilibrada(List<Elem>& expr)
{
    bool res=false;
    char curInfo, simbInfo;
    int cont=1;
    List<Elem> simbs;

    while(cont<=expr.getLength())
    {
        curInfo = expr.consult(1);

        if(curInfo=='{' || curInfo=='[' || curInfo=='(')
        {
            simbs.insertToStart(simbs.getLength()+1, curInfo);
        }
        else if(curInfo=='}' || curInfo==']' || curInfo==')')
        {
            simbInfo = simbs.consult(simbs.getLength());

            if(simbInfo == curInfo-2 || simbInfo == curInfo-1)
            {
                simbs.deleteElem(simbs.getLength());
            }
        }

        expr.insertToStart(expr.getLength()+1, curInfo);
        expr.deleteElem(1);

        cont++;
    }

    if(simbs.isEmpty())
    {
        res=true;
    }
    else
    {
        res=false;
    }

    return res;

}

template<class Elem>
void List<Elem>::operator =(List<Elem> &ListToAssign)
{
    this->copy(ListToAssign);
}






