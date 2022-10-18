/*
Given the head node of the singly linked list, return a pointer pointing to the middle of the linked list.
If there are an odd number of elements, return the middle element if there are even elements return the one which is farther from the head node.
For example, let the linked list be 1->2->3->4->null
(Image: add-image)
Since the number of elements in this linked list is 4 so we have 2 middle elements, i.e. 2 and 3, but we return 3 as it is farther from the head node, i.e. 1.
Input Format :
The first line of input contains an integer ‘T’ denoting the number of test cases.

The next ‘2*T’ lines represent the ‘T’ test cases.

The first and only line of each test case contains integers denoting the nodes of the linked list. Each line is guaranteed to have -1 at the end to signify the end of the linked list.

Sample Input 1 :
2
1 2 3 4 5 -1
4 0 32 5 48 6 -1
Sample Output 1 :
3
5
Explanation Of Sample Input 1 :
For the first test case:

The linked List is 1->2->3->4->5->NULL
We can clearly see that there are 5 elements in the linked list and the middle element is 3 hence we return a pointer poiniting to the middle element i.e 3.

For the second test case:

The linked List is : 4->0->32->5->48->6->NULL

We have 6 elements in the linked list. we will have 2 middle elements i.e 32 and 5. Since it is specified to return the element farther from the root node, we return 5.
Sample Input 2 :
2
2 69 7 -1
1 4 5 8 9 6 3 -1
Sample Output 2 :
69
8
*/

#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
// ****************************************************************

    // Following is the class structure of the Node class:

       class Node 
        { 
        public:
            int data;
            Node *next;
            Node(int data) 
            {
               this->data = data;
              this->next = NULL;
            }
        };

// *****************************************************************

Node * getMiddle(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

// when only two node exits in linked list.
    if(head->next->next == NULL){
        return head->next;
    }

    /* slow pointed on first node(jumps one node at a time) and fast pointed to 2 node(jumps 2 node at a time). Approach is if fast takes n time to reach last node then slow takes n/2 times which means middle element that what we want to find  so we will return slow*/
 
   Node* slow = head;
   Node* fast = head->next;

   while(fast != NULL){
      fast = fast->next;
      if(fast != NULL){
        fast = fast->next;

      }

      slow = slow->next;
   }

   return slow;


}

int getLength(Node* head){
    int len = 0;

    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}

Node *findMiddle(Node *head){
    //approach->1
    
    int len = getLength(head);
    int ans = (len/2);

    Node* temp = head;

    int cnt = 0;
    while(cnt < ans){
        temp = temp->next;
        cnt++;
    }
    return temp;

    // //approach->2

    // return getMiddle(head)

}