#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode *getMid(ListNode* head){
    ListNode *slow, *fast;
    slow=head;
    fast=head->next;
    
    while(slow!=NULL && fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
        if(fast!=NULL) fast=fast->next;
    }
    return slow;
} 

ListNode *merge(ListNode* head1, ListNode* head2){
    ListNode *newHead, *newLast;
    newHead=newLast=new ListNode(-1);
    
    while(head1!=NULL && head2!=NULL){
        int x=head1->val;
        int y=head2->val;
        if(x<=y){
            newLast->next=head1;
            head1=head1->next;
        }else{
            newLast->next=head2;
            head2=head2->next;
        }
        newLast=newLast->next;
    }
    
    while(head1!=NULL){
        newLast->next=head1;
        head1=head1->next;
        newLast=newLast->next;
    }
    while(head2!=NULL){
        newLast->next=head2;
        head2=head2->next;
        newLast=newLast->next;
    }
    
    return newHead->next;;
}
 
ListNode *mergeSort(ListNode* head){
    if(head->next==NULL){
        return head;
    }
    ListNode *mid=getMid(head);
    ListNode *head2=mid->next;
    mid->next=NULL;
    
    ListNode *left=mergeSort(head);
    ListNode *right=mergeSort(head2);
    
    return merge(left,right);
}
 
ListNode* Solution::sortList(ListNode* head){
    if(head==NULL) return NULL;
    
    return mergeSort(head);
}
