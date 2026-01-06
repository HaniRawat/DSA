/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    if(!A)
        return A;
    RandomListNode* curr = A;
    
    unordered_map<RandomListNode*, RandomListNode*>mp;
    
    while(curr){
        RandomListNode* newNode = new RandomListNode(curr->label);
        mp[curr] = newNode;
        curr = curr->next;
    }
    curr = A;
    while(curr){
        mp[curr]->next = mp[curr->next];
        mp[curr]->random = mp[curr->random];
        curr = curr->next;
    }
    return mp[A];
}