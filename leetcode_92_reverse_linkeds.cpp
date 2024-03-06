#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void solution(ListNode * &begin, ListNode * &end){
        if (begin == end || begin == NULL || end == NULL)
            return;
        if (begin -> next == end){
            int t = begin -> val;
            begin -> val = end -> val;
            end -> val = t;
            return;
        }


        solution(begin -> next, end);

        ListNode * node = new ListNode(begin -> val, end -> next);
        end -> next = node;
        end = end -> next;
        
        ListNode * neededToDele = begin -> next;

        begin -> val = neededToDele -> val;
        begin -> next = neededToDele -> next;
        delete neededToDele;
}
int main(){
    ListNode * head = new ListNode();
    ListNode * node = head;
    for (int i = 1; i <= 4; i++){
        node -> val = i;
        if (i != 4){
            node -> next = new ListNode();
            node = node -> next;
        }
    }
    solution(head, node);


    return 0;
}