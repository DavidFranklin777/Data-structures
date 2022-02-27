#include <iostream>

using namespace std;

class Node
{
public:
    int data;                   // integer data that the linked list can hold
    Node *next;                 // this pointer holds the value of the next node

    /*
     * @brief Node
     * @param _data
     *
     */
    // The constructor initializes the two elements of a linked list, i.e data and next pointer
    // This is necessary, otherwise the tail of the linkedlist may not have an ending point which would result in an infinite sweep while reading a linkedlist
    Node (int _data = 0)
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
    int  getSize();
    void appendData(int data);
    void prependData(int data);
    void printList();
    void removeFirstElement();
    void removeLastElement();
    void removeAt(int pos);
};

int LinkedLists::getSize()
{
    return size;
}
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
    cout << "The linked list of size " << size << " is:\n";
    while (NULL != temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
 }

 void LinkedLists::removeFirstElement()
 {
     // Case 1: List is empty
     // Nothing to delete as there is no list

     // Case 2: List is not empty
     // Create a temp node and assign header to it, advance header and delete the temp.

     if (NULL != header)
     {
         Node *temp = header;
         header = header->next;
         delete temp;
     }

     else
     {
         cout << "List is empty. Nothing to delete!\n";
     }

     size--;
 }

 void LinkedLists::removeLastElement()
 {
    // Case 1: Empty list
     if(NULL == header)
     {
         cout << "List is empty. Nothing to remove!\n";
     }
     else if (NULL == header->next)
     {
         removeFirstElement();
     }

     else
     {
         // Create two nodes cur and prev
        Node *cur = header;
        Node *prev;
        while (NULL != cur->next)
        {
            prev = cur;
            cur = cur->next;
        }
        tail = prev;
        prev->next = NULL;
        delete cur;
        size--;
     }

 }

 void LinkedLists::removeAt(int pos)
 {
    if (pos > size)
    {
        cout << "Position greater than size, Invalid\n";
        return;
    }

    else if (NULL != header)
    {
        Node *cur = header;
        Node *prev;
        for (int i =1; i<pos; i++)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        delete cur;
        size--;
    }
 }
int main()
{
    LinkedLists list;
    list.appendData(1);
    list.appendData(2);
    list.appendData(3);
    list.appendData(4);
    list.prependData(10);
//    list.removeFirstElement();
//    list.removeLastElement();
    list.removeAt(2);
    list.printList();


    return 0;
}
