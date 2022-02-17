#include <iostream>

using namespace std;

class Node
{
public:
    int data;                   // integer data that the linked list must hold
    Node *next;                 // this pointer holds the value of the next node

    /*
     * @brief Node
     * @param _data
     *
     */

    // The constructor basically initializes the two elements of a linked list, i.e data and next
    // This is necessary, otherwise the tail of the linkedlist may not have an ending point which would result in an infinite sweep while reading a linkedlist
    Node (int _data)
    {
        data = _data;
        next =  NULL;
    }
};

class LinkedLists
{
public:

    /*
     * @brief LinkedLists
     * @param header - This points to the first block of the linked list
     * @param tail   - This points to the last block of the linked list
     * @size         - Size of the linkedlist
     */

    LinkedLists()
    {
        header = NULL;
        tail   = NULL;
        size   = 0;
    };

    Node *header;
    Node *tail;
    int   size;
    void appendData(int data);
    void prependData(int data);
    void printList();
};

 void LinkedLists::appendData(int data)
 {
     // Create a new node
     Node *newElement = new Node(data);
     // Case 1 List is empty
     if(NULL == header)
     {
        header = newElement;
        tail  = newElement;
     }

     // Case 2 List is not empty
     else
     {
         tail->next = newElement;
         tail = newElement;
     }
     // Increment size of the linkedlist
     size++;

 }

 void LinkedLists::prependData(int data)
 {
     //Create a new node
     Node *newElement = new Node(data);
     Node *temp;

     // Case 1 Empty list
     if(NULL == header)
     {
         header = newElement;
         tail = newElement;
     }

     // Case 2 list not empty
     else
     {
         temp = header;
         header = newElement;
         newElement->next = temp;
     }

     size++;
 }

 void LinkedLists::printList()
 {
    Node *temp = header;

    while (NULL != temp)
    {
        cout << " " << temp->data;
        temp = temp->next;
    }

    cout << endl;
 }



int main()
{
    LinkedLists list;
    list.appendData(1);
    list.appendData(2);
    list.appendData(3);
    list.prependData(10);
    list.printList();


    return 0;
}
