// CRACKING THE CODING INTERVIEW 

#include <iostream>
#include <list>
using namespace std;

class Hash
{
    int BUCKET;
    list<int> *table;
public:
    Hash(int b)
    {
        this->BUCKET = b;
        table = new list<int>[BUCKET];
    }
    
    void insertItem(int key)
    {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void deleteItem(int key)
    {
        int index = hashFunction(key);
        list <int> :: iterator i;
        for (i = table[index].begin(); i != table[index].end(); i++)
        {
            if (*i == key)
                break;
        }
        if (*i == key)
            table[index].erase(i);
    }
    
    int alreadyExists(int key)
    {
        int index = hashFunction(key);
        list <int> :: iterator i;
        for (i = table[index].begin(); i != table[index].end(); i++)
        {
            if (*i == key)
                return 1;
        }
        return 0;
    }
    
    int hashFunction(int x)
    {
        return (x % BUCKET);
    }
    
    void displayHash()
    {
        for (int i = 0; i < BUCKET; i++)
        {
            cout << i;
            for (auto x : table[i])
                cout << " --> " << x;
            cout << endl;
        }
    }
};

class LinkedList
{
    struct Node
    {
        int data;
        bool visited = false;
        Node* next;
    };
public:
    Node *head;
    
    LinkedList()
    {
        head = NULL;
    }
    
    void add(int x)
    {
        Node *newnode = new Node;
        newnode->next = NULL;
        newnode->data = x;
        if(head == NULL)
            head=newnode;
        else
        {
            Node *ptr;
            ptr = head;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = newnode;
        }
    }

    void add_beginning(int x)
    {
        Node *newnode = new Node;
        newnode->next = head;
        newnode->data = x;
        head = newnode;
    }
    
    void removeDups(Hash h)
    {
        Node *ptr, *preptr;
        ptr = head;
        preptr = head;
        while(ptr  != NULL)
        {
            int c = 0;
            int flag = h.alreadyExists(ptr->data);  // 0: doesn't exist, 1: exists
            if(flag == 0)
                h.insertItem(ptr->data);
            else
            {
                preptr->next = ptr->next;
                ptr = ptr->next;
                c = 1;
            }
            if(c == 0)
            {
                preptr = ptr;
                ptr = ptr->next;
            }
        }
    }
    
    int kth_to_last(int k)
    {
        int count = 0;
        Node *ptr = head;
        while(ptr != NULL)
        {
            count++;
            ptr = ptr->next;
        }
        ptr = head;
        for(int i=0; i<count-k; i++)
            ptr = ptr->next;
        return ptr->data;
    }
    
    void delete_middle(int x)
    {
        Node *ptr = head;
        Node *preptr = head;
        while((ptr->data != x) && (ptr != NULL))
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        if(ptr == NULL)
            cout << "Element not found";
        else
        {
            preptr->next = ptr->next;
            delete ptr;
        }
    }
    
    LinkedList sum_linked_list(LinkedList n)
    {
        int carry = 0, temp;
        LinkedList result;
        Node *ptr1 = head, *ptr2 = n.head;
        while((ptr1 != NULL) && (ptr2 != NULL))
        {
            temp = ptr1->data + ptr2->data + carry;
            carry = temp / 10;
            temp = temp % 10;
            result.add(temp);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if((ptr1 == NULL) && (ptr2 != NULL))
        {
            while(ptr2 != NULL)
            {
                temp = ptr2->data + carry;
                carry = temp / 10;
                temp = temp % 10;
                result.add(temp);
                ptr2 = ptr2->next;
            }
        }
        else if((ptr2 == NULL) && (ptr1 != NULL))
        {
            while(ptr1 != NULL)
            {
                temp = ptr1->data + carry;
                carry = temp / 10;
                temp = temp % 10;
                result.add(temp);
                ptr1 = ptr1->next;
            }
        }
        return result;
    }
    
    LinkedList sum_linked_list_reverse(LinkedList n)
    {
        int carry = 0, p, temp, count1 = 0, count2 = 0, max, min;
        LinkedList result;
        Node *ptr = head, *ptr1, *ptr2;
        while(ptr != NULL)
        {
            ptr = ptr->next;
            count1++;
        }
        ptr = n.head;
        while(ptr != NULL)
        {
            ptr = ptr->next;
            count2++;
        }
        if(count1>count2)
        {
            min = count2;
            max = count1;
        }
        else
        {
            min = count1;
            max = count2;
        }
        for(int i = min-1; i>=0; i--)
        {
            if(count1>count2)
            {
                ptr2 = head;
                ptr1 = n.head;
            }
            else
            {
                ptr1 = head;
                ptr2 = n.head;
            }

            for(int j=0; j<i; j++)
                ptr1 = ptr1->next;
            for(int j=0; j<i+max-min; j++)
                ptr2 = ptr2->next;
            
            temp = ptr1->data + ptr2->data + carry;
            carry = temp / 10;
            temp = temp % 10;
            result.add_beginning(temp);
        }
        if(max != min)
        {
            for(int i=max-min-1; i>=0; i--)
            {
                if(count1>count2)
                    ptr2 = head;
                else
                    ptr2 = n.head;

                for(int j=0; j<i; j++)
                    ptr2 = ptr2->next;

                temp = ptr2->data + carry;
                carry = temp / 10;
                temp = temp % 10;
                result.add_beginning(temp);
            }
        }
        if(carry != 0)
            result.add_beginning(carry);
        
        return result;
    }
    
    void palindrome(string str)
    {
        int l = str.length(), flag = 0;
        for(int i=0; i<l; i++)
            add(str[i]);
        Node *ptr1=head, *ptr2=head;
        for(int i=0; i<=l/2; i++)
        {
            for(int j=0; j<l-1-i; j++)
                ptr2 = ptr2->next;
            if(ptr2->data != ptr1->data)
            {
                flag = 1;
                break;
            }    
            ptr1 = ptr1->next;
            ptr2 = head;
        }
        if(flag == 1)
            cout<<"Not a Palindrome";
        else
            cout<<"Palindrome";
    }

    void make_intersect(LinkedList n)
    {
        Node *ptr1=head, *ptr2=n.head;
        for(int i=0; i<4; i++)
            ptr1 = ptr1->next;
        while(ptr2->next != NULL)
            ptr2 = ptr2->next;
        ptr2->next = ptr1;
    }

    void find_intersect(LinkedList n)
    {
        int flag = 0;
        Node *ptr1=head, *ptr2=n.head;
        while(ptr1 != NULL)
        {
            ptr1->visited = true;
            ptr1 = ptr1->next;
        }
        while(ptr2 != NULL)
        {
            if(ptr2->visited == true)
            {
                flag = 1;
                break;
            }
            else
                ptr2 = ptr2->next;
        }
        if(flag == 1)
            cout<<"Intersection Exists.";
        else
            cout<<"No Intersection";
    }

    void make_loop()
    {
        Node *ptr1=head, *ptr2=head;
        for(int i=0; i<4; i++)
            ptr1 = ptr1->next;
        while(ptr2->next != NULL)
            ptr2 = ptr2->next;
        ptr2->next = ptr1;
    }

    void check_loop()
    {
        int flag = 0;
        Node *ptr=head;
        while(ptr->visited != true)
        {
            ptr->visited = true;
            ptr = ptr->next;
            if(ptr == NULL)
            {
                flag = 2;
                break;    
            }
            else if(ptr->visited == true)
                flag = 1;
        }
        if(flag == 1)
            cout<<"Loop Exists.";
        else
            cout<<"No Loop";
    }

    void partition(int p)
    {
        Node *ptr1 = head, *ptr2 = head;
        int count = 1;
        while(ptr2->next != NULL)
        {
            ptr2 = ptr2->next;
            count++;
        }
        while(ptr1 != ptr2)
        {
            if(ptr1->data>=p)
            {
                int temp = ptr2->data;
                ptr2->data = ptr1->data;
                ptr1->data = temp;
                count--;
                ptr2 = head;
                for(int i=0; i<count-1; i++)
                    ptr2 = ptr2->next;
            }
            else
                ptr1 = ptr1->next;
        }
    }

    void displayLinkedList()
    {
        Node *ptr = head;
        while(ptr != NULL)
        {
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
    }
}; 

int main()
{
    /*
    // REMOVE DUPLICATES
    
    int a[] = {8, 15, 11, 10, 4, 3, 8, 4, 14, 8}; // 15, 11, 27, 8, 18, 19, 12, 19, 12, 19, 19
    int m = sizeof(a)/sizeof(a[0]);
    Hash h(7);
    LinkedList n;
    for (int i = 0; i < m; i++)
        n.add(a[i]);
    n.removeDups(h);
    n.displayLinkedList();
    */
    
    /*
    // RETURN Kth TO LAST
    int a[] = {15, 11, 27, 8, 18, 19, 12, 16, 10, 1, 9};
    int m = sizeof(a)/sizeof(a[0]);
    LinkedList n;
    for (int i = 0; i < m; i++)
        n.add(a[i]);
    cout << "Kth to Last: " << n.kth_to_last(4);
    */
    
    /*
    // DELETING A MIDDLE NODE
    int a[] = {15, 11, 27, 8, 18, 19, 12, 16, 10, 1, 9};
    int m = sizeof(a)/sizeof(a[0]);
    LinkedList n;
    for (int i = 0; i < m; i++)
        n.add(a[i]);
    n.delete_middle(12);
    n.displayLinkedList();
    */
    
    /*
    // SUM LISTS
    int a[] = {7, 1, 6};
    int m = sizeof(a)/sizeof(a[0]);
    LinkedList n1;
    for (int i = 0; i < m; i++)
        n1.add(a[i]);
    int b[] = {5, 9, 2};
    m = sizeof(b)/sizeof(b[0]);
    LinkedList n2;
    for (int i = 0; i < m; i++)
        n2.add(b[i]);
    LinkedList n3 = n1.sum_linked_list_reverse(n2);
    n3.displayLinkedList();
    
    int c[] = {1, 1, 6};
    int m = sizeof(c)/sizeof(c[0]);
    LinkedList n4;
    for (int i = 0; i < m; i++)
        n4.add(c[i]);
    int d[] = {1, 5, 9, 2};
    m = sizeof(d)/sizeof(d[0]);
    LinkedList n5;
     for (int i = 0; i < m; i++)
        n5.add(d[i]);
    LinkedList n6 = n4.sum_linked_list_reverse(n5);
    n6.displayLinkedList();
    */

    /*
    // PALINDROME
    string str = "ponnop";
    LinkedList n;
    n.palindrome(str); 
    */

    /*
    // INTERSECTION
    int a[] = {7, 1, 6, 2, 3, 4, 5, 8, 9};
    int m = sizeof(a)/sizeof(a[0]);
    LinkedList n1;
    for (int i = 0; i < m; i++)
        n1.add(a[i]);
    int b[] = {10, 12, 11};
    m = sizeof(b)/sizeof(b[0]);
    LinkedList n2;
    for (int i = 0; i < m; i++)
        n2.add(b[i]);
    n1.make_intersect(n2);
    n1.find_intersect(n2);
    */
    
    /*
    // LOOP
    int a[] = {7, 1, 6, 2, 3, 4, 5, 8, 9};
    int m = sizeof(a)/sizeof(a[0]);
    LinkedList n1;
    for (int i = 0; i < m; i++)
        n1.add(a[i]);
    n1.make_loop();
    n1.check_loop();
    */

    /*
    // PARTITION
    int a[] = {8, 3, 9, 10, 5, 6, 5, 3, 2, 1};
    int m = sizeof(a)/sizeof(a[0]);
    int partition_boundary = 5;
    LinkedList n1;
    for (int i = 0; i < m; i++)
        n1.add(a[i]);
    n1.partition(partition_boundary);
    n1.displayLinkedList();
    */

    return 0;
}
 