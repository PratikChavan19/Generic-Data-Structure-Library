📌 Overview :

This project implements a Generic Data Structure Library in C++ using templates to support multiple data types.

It provides reusable implementations of:

Linked Lists (Singly, Doubly, Circular)
Stack
Queue

The library is designed with modularity, reusability, and type-independence in mind.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

⚙️ Features :

📌 Template-based generic implementation
🔁 Supports multiple data types (int, float, char, etc.)
📚 Multiple data structures in one library
📥 Dynamic memory allocation
📊 Built-in operations (Insert, Delete, Display, Count)
🧩 Modular and reusable design

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

🧱 Data Structures Implemented :

🔹 Linked Lists
    Singly Linear Linked List
    Singly Circular Linked List
    Doubly Linear Linked List
    Doubly Circular Linked List
🔹 Stack (LIFO)
    Push
    Pop
    Display
🔹 Queue (FIFO)
    EnQueue
    DeQueue
    Display

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

🚀 How to Compile & Run :

🔧 Compile
  g++ DS_Library.cpp -o ds

▶️ Run
  ./ds

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

🔄 Example Usage :

SinglyLL<int> obj;
  obj.InsertFirst(10);
  obj.InsertLast(20);
  obj.InsertAtPos(15,2);
  obj.Display();
  
Stack<int> sobj;
  sobj.Push(10);
  sobj.Push(20);
  sobj.Pop();
  
Queue<int> qobj;
  qobj.EnQueue(10);
  qobj.EnQueue(20);
  qobj.DeQueue();

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

🧠 Memory Management & Functions :

🔹 new
    Allocates memory dynamically for nodes
🔹 delete
    Frees allocated memory
🔹 Templates (template<class T>)
    Enables generic programming
    Supports multiple data types

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

⚙️ Core Operations :

Linked List
  InsertFirst(), InsertLast(), InsertAtPos()
  DeleteFirst(), DeleteLast(), DeleteAtPos()
  Display(), Count()
Stack
  Push(), Pop(), IsStackEmpty()
Queue
  EnQueue(), DeQueue(), IsQueueEmpty()

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

📊 Time Complexity :

Operation      	        Complexity
Insert (First)	        O(1)
Insert (Last)	          O(n)
Delete	                O(n)
Search	                O(n)
Stack Push/Pop	        O(1)
Queue Enqueue/Dequeue	  O(n)

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

📊 Sample Output :

Element in LL is :
| 10 | => | 15 | => | 20 | => NULL

Element in stack are :
| 20 | => | 10 | => NULL

Element in Queue is :
| 10 | => | 20 | =>

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

⚠️ Limitations :

No STL usage (custom implementation only)
No exception handling
Queue implementation has O(n) enqueue complexity
No iterator support

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

🔮 Future Enhancements :

📦 Add STL-like iterators
⚡ Optimize Queue using rear pointer
🧵 Thread-safe data structures
📊 Add searching & sorting algorithms
📂 Convert into reusable header library

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
