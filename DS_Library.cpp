#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////
// Structure for Singly Linear and Singly Circular
template <class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

////////////////////////////////////////////////////////////////
// Structure for Doubly Linear and Doubly Circular
template <class T>
struct nodeD
{
    T data;
    struct nodeD *prev;
    struct nodeD *next;
};

////////////////////////////////////////////////////////////////
// Structure for Stack and Queue
template <class T>
struct nodeG
{
    T data;
    struct nodeG *next;
};

////////////////////////////////////////////////////////////////
// Class of Singly Linear Linked List
template <class T>
class SinglyLL
{
    public:
        struct nodeS <T> *First;
        int iCount;

        SinglyLL();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();
};

template <class T>
SinglyLL <T> ::  SinglyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL <T> :: InsertFirst(T No)
{
    struct nodeS<T> *newn = new struct nodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL <T> :: InsertLast(T No)
{
    struct nodeS<T> *newn = new struct nodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct nodeS<T> *temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL <T> :: InsertAtPos(T No, int iPos)
{
    if(iPos < 1 || iPos > iCount + 1)
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        struct nodeS<T> *temp = First;
        struct nodeS<T> *newn = new struct nodeS<T>;

        newn->data = No;
        newn->next = NULL;

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL <T> :: DeleteFirst()
{
    if(First == NULL)
    {
        cout<<"LL is Empty"<<"\n";
        return;
    }
    else if(First ->next == NULL)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        struct nodeS<T> *temp = First;
        First = First->next;
        delete temp;
        iCount--;
    }
}

template <class T>
void SinglyLL <T> :: DeleteLast()
{
    if(First == NULL)
    {
        cout<<"LL is Empty"<<"\n";
        return;
    }
    else if(First ->next == NULL)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        struct nodeS<T> *temp = First;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        iCount--;
    }
}

template <class T>
void SinglyLL <T> :: DeleteAtPos(int iPos)
{
    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeS<T> *temp1 = First;
        struct nodeS<T> *temp2 = NULL;

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
        iCount--;
    }
}

template <class T>
void SinglyLL <T> :: Display()
{
    cout<<"Element in LL is : "<<"\n";

    struct nodeS<T> *temp = First;
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | => ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLL <T> :: Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////
// Class of Singly Circular Linked List

template <class T>
class SinglyCL
{
    public:
        struct nodeS<T> *First;
        struct nodeS<T> *Last;
        int iCount;

        SinglyCL();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();
};

template <class T>
SinglyCL<T> :: SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T> ::InsertFirst(T No)
{
    struct nodeS<T> *newn = new struct nodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
        Last->next = First;
    }
    iCount++;
}

template <class T>
void SinglyCL<T> ::InsertLast(T No)
{
    struct nodeS<T> *newn = new struct nodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last -> next = newn;
        Last = newn;
        Last ->next = First;
    }
    iCount++;
}

template <class T>
void SinglyCL<T> ::InsertAtPos(T No, int iPos)
{
    if(iPos < 1 && iPos > iCount +1)
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        struct nodeS<T> *newn = new struct nodeS<T>;
        struct nodeS<T> *temp = First;

        newn -> data = No;
        newn->next = NULL;

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn ->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void SinglyCL<T> ::DeleteFirst()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Empty LL"<<"\n";
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
        iCount--;
    }
    else
    {
        First = First ->next;
        delete Last->next;
        Last->next = First;
        iCount--;
    }
}

template <class T>
void SinglyCL<T> ::DeleteLast()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Empty LL"<<"\n";
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
        iCount--;
    }
    else
    {
        struct nodeS<T> *temp = First;

        while(temp->next->next != First)
        {
            temp = temp->next;
        }
        Last = temp;
        delete Last->next;
        Last->next = First;
        iCount--;
    }
}

template <class T>
void SinglyCL<T> ::DeleteAtPos(int iPos)
{
    if(iPos < 1 && iPos > iCount )
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeS<T> *temp1 = First;
        struct nodeS<T> *temp2 = NULL;

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2 ->next;
        delete temp2;
        iCount--;
    }
}

template <class T>
void SinglyCL<T> ::Display()
{
    struct nodeS<T> *temp = First;
    cout<<"Element in LL is :"<<"\n";

    do
    {
        cout<<"| "<<temp->data<<" | => ";
        temp = temp->next;
    }while(temp != First);
    
    cout<<"\n";
}

template <class T>
int SinglyCL<T> :: Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////
// Class of Doubly Linear Linked List

template <class T>
class DoublyLL
{
    public:
        struct nodeD<T> *First;
        int iCount;

        DoublyLL();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();
};

template <class T>
DoublyLL<T> :: DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T> :: InsertFirst(T No)
{
    struct nodeD<T> *newn = new struct nodeD<T>;
    
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T> :: InsertLast(T No)
{
    struct nodeD<T> *newn = new struct nodeD<T>;
    
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct nodeD<T> *temp = First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template <class T>
void DoublyLL<T> :: InsertAtPos(T No, int iPos)
{
    if(iPos < 1 || iPos > iCount + 1)
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        struct nodeD<T> *temp = First;
        struct nodeD<T> *newn = new struct nodeD<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
    if(First == NULL)
    {
        cout<<"Empty LL"<<"\n";
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        First = First->next;
        delete First->prev;
        First->prev = NULL;
        iCount--;
    }
}

template <class T>
void DoublyLL<T> :: DeleteLast()
{
    if(First == NULL)
    {
        cout<<"Empty LL"<<"\n";
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        struct nodeD<T> *temp = First;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        iCount--;
    }
}

template <class T>
void DoublyLL<T> :: DeleteAtPos(int iPos)
{
    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeD<T> *temp = First;

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp ->next;
        }
        temp->next =temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        iCount--;
    }
}

template <class T>
void DoublyLL<T> :: Display()
{
    cout<<"Element in LL is : "<<"\n";
    
    struct nodeD<T> *temp = First;
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    cout<<"\n";
}

template <class T>
int DoublyLL<T> :: Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////
// Class of Doubly Circular Linked List

template <class T>
class DoublyCL
{
    public:
        struct nodeD<T> *First;
        struct nodeD<T> *Last;
        int iCount;

        DoublyCL();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();
};

template <class T>
DoublyCL<T> :: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T> :: InsertFirst(T No)
{
    struct nodeD<T> *newn = new struct nodeD<T>;

    newn->data = No;
    newn->prev = NULL;
    newn->next = NULL;

    if(First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
        First->prev = Last;
        Last ->next =First;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
        First->prev = Last;
        Last->next = First;
    }
    iCount++;
}

template <class T>
void DoublyCL<T> :: InsertLast(T No)
{
    struct nodeD<T> *newn = new struct nodeD<T>;

    newn->data = No;
    newn->prev = NULL;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
        Last = newn;
        First->prev = Last;
        Last ->next = First;
    }
    else
    {
        newn->prev = Last;
        Last->next = newn;
        Last = newn;
        Last->next = First;
        First->prev = Last;
    }
    iCount++;
}

template <class T>
void DoublyCL<T> :: InsertAtPos(T No, int iPos)
{
    if(iPos < 1 || iPos > iCount + 1)
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        struct nodeD<T> *temp = First;
        struct nodeD<T> *newn = new struct nodeD<T>;

        newn->data = No;
        newn->prev = NULL;
        newn->next = NULL;

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        temp->next->prev = temp;
        iCount++;
    }  
}

template <class T>
void DoublyCL<T> :: DeleteFirst()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"LL is Empty"<<"\n";
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete Last->next;
        First->prev = Last;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void DoublyCL<T> :: DeleteLast()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"LL is Empty"<<"\n";
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = Last->prev;
        delete Last ->next;
        Last->next = First;
        First->prev = Last;
    }
    iCount--;
}

template <class T>
void DoublyCL<T> :: DeleteAtPos(int iPos)
{
    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeD<T> *temp = First;

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp ->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        iCount--;
    }
}

template <class T>
void DoublyCL<T> :: Display()
{
    cout<<"Element of LL is : "<<"\n";

    struct nodeD<T> *temp = First;
    do
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }while(temp != First);
    cout<<"\n";
}

template <class T>
int DoublyCL<T> :: Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////
// Class of Stack

template <class T>
class Stack
{
    public:
        struct nodeG<T> *First;
        int iCount;
        
        Stack();

        bool IsStackEmpty();
        void Push(T No);
        T Pop();
        void Display();
};

template <class T>
Stack<T> :: Stack()
{
    First = NULL;
    iCount = 0;
}

template <class T>
bool Stack<T> :: IsStackEmpty()
{
    if(iCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void Stack<T> :: Push(T No)
{
    struct nodeG<T> *newn = new struct nodeG<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
T Stack<T> :: Pop()
{
    if(First == NULL)
    {
        cout<<"Stack is Empty"<<"\n";
        return (T) -1;
    }
    else
    {
        struct nodeG<T> *temp = First;
        T Value = First->data;

        First = First->next;
        delete temp;
        iCount--;
        return Value;
    }    
}

template <class T>
void Stack<T> :: Display()
{
    if(First == NULL)
    {
        cout<<"Stack is Empty"<<"\n";
    }
    else
    {
        cout<<"Element in stack are : "<<"\n";
        
        struct nodeG<T> *temp = First;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" | => ";
            temp = temp->next;
        }
        cout<<"NULL"<<"\n";
    }
}

////////////////////////////////////////////////////////////////
// Class of Queue

template <class T>
class Queue
{
    public:
        struct nodeG<T> *First;
        int iCount;

        Queue();

        bool IsQueueEmpty();
        void EnQueue(T No);
        T DeQueue();
        void Display();
};

template <class T>
Queue<T> :: Queue()
{
    First = NULL;
    iCount = 0;
}

template <class T>
bool Queue<T> :: IsQueueEmpty()
{
    if(iCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void Queue<T> :: EnQueue(T No)
{
    struct nodeG<T> *newn = new struct nodeG<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct nodeG<T> *temp = First; 
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
T Queue<T> :: DeQueue()
{
    if(First == NULL)
    {
        cout<<"Queue is Empty"<<"\n";
        return (T) -1;
    }
    else
    {
        T Value = First->data;
        struct nodeG<T> *temp = First;
        First = First->next;
        delete temp;
        iCount--;
        return Value;
    }
}

template <class T>
void Queue<T> :: Display()
{
    if(First == NULL)
    {
        cout<<"Queue is Empty"<<"\n";
    }
    else
    {
        cout<<"Element in Queue is : "<<"\n";
        struct nodeG<T> *temp = First;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" | => ";
            temp = temp->next;
        }
        cout<<"\n";
    }
}

////////////////////////////////////////////////////////////////

int main()
{

    return 0;
}

////////////////////////////////////////////////////////////////