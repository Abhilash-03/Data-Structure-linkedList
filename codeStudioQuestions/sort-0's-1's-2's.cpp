/*
You are given a linked list having N number of nodes and each node will have an integer which can be 0, 1, or 2. You have to sort the given linked list in ascending order.
For Example:
Let the linked list be 1→0→2→1→2. 
The sorted linked list for the given linked list will be 0→1→1→2→2.
Input Format:
The first line of input contains an integer ‘T’, denoting the number of test cases.

The first and only line of each test case will have space-separated integers denoting the elements of the linked list and terminated by -1. Hence, -1 would never be a list element.

Sample Input 1:
2
1 0 2 1 2 -1
0 0 1 2 -1
Sample Output 1:
0 1 1 2 2 -1
0 0 1 2 -1
Explanation Of Sample Input 1:
For the 1st test case:
The smallest element is 0, followed by 1, 1, 2 and 2. Hence the linkedlist returned should be 0->1->1->2->2.

For the 2st test case:
The smallest element is 0, followed by 0, 1, and 2. Hence the linkedlist returned should be 0->0->1->2.
Sample Input 2:
2
2 2 1 0 0 0 -1
1 1 1 1 -1
Sample Output 2:
0 0 0 1 2 2 -1
1 1 1 1 -1

*/
#include<bits/stdc++.h>

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

Node* insertAtTail(Node* &tail, Node* curr){
    tail->next = curr;
    tail = curr;
}

Node* sortList(Node *head){

 //approach-2 without replacing elements.

  Node*zeroHead = new Node(-1);
  Node* zeroTail = zeroHead;
  Node* oneHead = new Node(-1);
  Node* oneTail = oneHead;
  Node* twoHead = new Node(-1);
  Node* twoTail = twoHead;

  Node* curr = head;

  while(curr != NULL){
    int value = curr->data;

    if(value == 0){
        insertAtTail(zeroTail, curr);
    }
    else if(value == 1){
        insertAtTail(oneTail, curr);
    }
    else{
        insertAtTail(twoTail, curr);
    }
    curr = curr->next;
  }

  
      //merge 3 sublist
    
//     1s list in non-empty
    if(oneHead->next != NULL){
         zeroTail->next = oneHead->next;
    }
    else{
           // 1s list is empty
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

   head = zeroHead->next;

   return head; 










 /*   //approach-1 replace the element 

    Node* zeroCnt = 0;
    Node* oneCnt = 0;
    Node* twoCnt = 0;

    Node* temp = head;

    while(temp != NULL){
        int value = temp->data;

        if(value == 0){
            zeroCnt++;
        }
        else if(value == 1){
            oneCnt++;
        }
        else{
            twoCnt++;
        }

        temp = temp->next;
    }

    temp = head;

    while(temp != NULL){
        if(zeroCnt != 0){
            temp->data = 0;
            zeroCnt--;
        }
        else if(oneCnt != 0){
            temp->data = 1;
            oneCnt--;
        }
        else{
            temp->data = 2;
            twoCnt--;
        }

        temp = temp->next;
    }

   

    return head;
    */
}