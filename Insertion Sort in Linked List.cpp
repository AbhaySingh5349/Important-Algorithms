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
ListNode* Solution::insertionSortList(ListNode* h){
    ListNode *p, *head, *last;
    p=h;
    head=last=new ListNode(h->val);
    if(p!=NULL) p=p->next;
    
    while(p!=NULL){
        int x=p->val;
        
        ListNode *q,*pre;
        q=pre=head;
        
        while(q!=NULL && q->val>x){
            pre=q;
            q=q->next;
        }
        
        ListNode *t=new ListNode(x);
        if(q==head){
            t->next=head;
            head=t;
        }else if(q==NULL){
            last->next=t;
            last=t;
        }else{
            t->next=q;
            pre->next=t;
        }
        p=p->next;
    }
    
    ListNode *newHead=NULL;
    while(head!=NULL){
        ListNode *on = head->next;
        head->next=newHead;
        newHead=head;
        head=on;
    }
    
    return newHead;
}
