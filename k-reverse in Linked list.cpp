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
 
ListNode* create(ListNode* head, int k){
    if(head==NULL){
        return NULL;
    }else{
        ListNode *p, *q , *r, *pre;
        p=r=pre=head;
        
        for(int i=0;i<k && p!=NULL;i++){
            pre=p;
            p=p->next;
        }
        pre->next=NULL;
        q==NULL;
        while(r!=NULL){
            ListNode *on = r->next;
            r->next=q;
            q=r;
            r=on;
        }
        head->next = create(p,k);
        return q;
    }
} 
 
ListNode* Solution::reverseList(ListNode* h, int k){
    return create(h,k);
}
