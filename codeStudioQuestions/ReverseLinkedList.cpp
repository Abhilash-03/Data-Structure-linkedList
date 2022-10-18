/*
You are given a Singly Linked List of integers. You need to reverse the Linked List by changing the links between nodes.
Input Format :
The first line of input contains a single integer T, representing the number of test cases or queries to be run. 

The first line of each test case contains the elements of the singly linked list separated by a single space and terminated by -1. Hence, -1 would never be a list element.
Output Format :
For each test case, print the reversed linked list. The elements of the reversed list should be single-space separated, terminated by -1.

Print the output of each test case in a separate line. 

Sample Input 1 :
3
1 -2 3 -1
9 9 -1
4 -1
Sample Output 1 :
3 -2 1 -1
9 9 -1
4 -1
Explanation For Sample Input 1 :
For every test case, the reversed list is printed, terminated by -1.
Sample Input 2 :
2
1 1 1 -1
3 -3 -1
Sample Output 2 :
1 1 1 -1
-3 3 -1
*/

#include <bits/stdc++.h> 
// ***************************************************************

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


// ****************************************************************

Node* rev(Node* &head){
    //base case
        if(head == NULL || head->next == NULL){
            return head;
        }

        Node* smallHead =  rev(head->next);  //it will handle second part (which is 2nd node to last node)only  to point head to last node.

        head->next->next = head; //after reverse the second part then we should handle the first node or first part last node after reverse will be pointed first node. 
        head->next = NULL;  // Now first node point null point 

        return smallHead;
}

//Function for approach 2.
void reverse1(Node* &head, Node* curr, Node* prev){
       
       //base case
       if(curr == NULL){
         head = prev;
         return ;
       }

       Node* forward = curr->next;
       reverse1(head, forward, curr);

       curr->next = prev;
}

Node* reverseLinkedList(Node *head){

    //   Approach->3 ->(Recursive sol 2)

      return rev(head);   

/*    //Approach-> 1.

    //when linked list is empty or only one node is present

      if(head == NULL || head->next == NULL){
        return head;

      }

      Node* curr = head;
      Node* prev = NULL;
      Node* forward = NULL;

      while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;

      }

      return prev;
      */

/*     //Approach-> 2 (Recursive sol.)
    Node* curr = head;
      Node* prev = NULL;
      reverse1(head, curr, prev);
      return head;

      */


}