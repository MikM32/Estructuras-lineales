
#include <iostream>
#include "ListaSimple.cpp"

using namespace std;


int main()
{
    List<int> a, b, c;
    List<char> expr;

    a.insertToStart(1, 1);
    a.insertToStart(2, 3);
    a.insertToStart(3, 4);
    a.insertToStart(4, 5);
    a.insertToStart(5, 6);
    a.insertToStart(6, 7);

    b.insertToEnd(2);
    b.insertToEnd(4);
    b.insertToEnd(5);
    b.insertToEnd(9);
    b.insertToEnd(10);

    a.removeDuplicates();

    c.copy(*sortedIntersect(a, b));

    expr.insertToEnd('{');
    expr.insertToEnd('[');
    expr.insertToEnd('(');
    expr.insertToEnd('1');
    expr.insertToEnd('+');
    expr.insertToEnd('2');
    expr.insertToEnd(']');
    expr.insertToEnd('-');
    expr.insertToEnd('5');
    expr.insertToEnd(')');
    expr.insertToEnd('}');

    cout << esEquilibrada(expr)<< "\n";

    for(int i=1; i<=c.getLength(); i++)
    {
        cout << c.consult(i)<< "\n";
    }

    return 0;
}
