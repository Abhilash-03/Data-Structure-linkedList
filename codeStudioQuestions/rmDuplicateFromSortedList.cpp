/*
You want to play with your friend, but your friend has pending homework, help him complete that.
You are given a ‘Head’ of a sorted linked list. You can remove some values from the linked list. In the end, you must return a sorted linked list that contains no adjacent values that are equal.
For Example :
If the given linked list is: 1 -> 2 -> 2 -> 3

Then we will delete the duplicate value ‘2’ present in the linked list, and finally return the following list:
1 -> 2 -> 3

Sample Input 1 :
2
1 2 2 3 -1
1 2 3 4 -1
Sample Output 1 :
1 2 3 -1
1 2 3 4 -1
Explanation For Sample Input 1 :
For test case 1, we will return 1 -> 2 -> 3 -> NULL, because : 
We will delete the duplicate value ‘2’ present in the linked list, and finally return the following list:
1 -> 2 -> 3


For test case 2, we will return 1 -> 2 -> 3 -> 4 -> NULL, because the input list contains no duplicates, so we will return it as it is.
Sample Input 2 :
2
1 -1
2 5 5 5 5 -1 
Sample Output 2 :
1 -1
2 5 -1
*/
#include<bits/stdc++.h>
 
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };

Node * uniqueSortedList(Node * head){
    if(head == NULL){
        return NULL;
    }

    Node* curr = head;

    while(curr != NULL && curr->next != NULL){
        if(curr->data == curr->next->data){
            Node* nextOfNext = curr->next->next; //store the data of next node of deleting node.
            Node* deleteDupNode = curr->next;  //which node has to be deleted
            delete(deleteDupNode);   // then deleting the duplicate node.
            curr->next = nextOfNext;  // pointing the current node to node of after the deleting node which is store in nextOfNext.
        }
        else{
             curr = curr->next;  //if next node is not dupicate then we point the next node.
        }
    }
    return head;  //return the list  after removing the duplicates value.
}    