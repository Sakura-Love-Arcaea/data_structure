#include <stdio.h>

struct node {
    int data;
    struct node *NEXT;
};
typedef struct node Node;

Node *last(Node *);//最後一個元素的指標
void linked_list_print(Node *);
void linked_list_catenate(Node *, Node *, int);
int linked_list_search(Node *, int);
void linked_list_delete(Node *, int);

Node *last(Node *Node) {
    while (Node->NEXT) {
        Node = Node->NEXT;
    }
    return Node;
}

void linked_list_print(Node *head){//need fix
    while (head) {
        printf("%d ", head->data);
        head = head->NEXT;
    }
    puts(""); 
}
    
void linked_list_catenate(Node *head, Node *insert_Node, int index) {
    for (int i = 0; i < index; i++) {
        if (head->NEXT) {
            head = head->NEXT;
        }else {
            break;
        }
    }
    Node *hold = head->NEXT;
    head->NEXT = insert_Node;
    insert_Node = last(insert_Node);
    insert_Node->NEXT = hold;
}

int linked_list_search(Node *head, int data) {
    int i = 1;
    while (head) {
        if (head->data == data) {
            return i;
        }
        head = head->NEXT;
        i++;
    }
    return -1;
    
}

void linked_list_delete(Node *, int) {
    
}
int main() {
    Node a, b, c;
    
    
    a.data = 1;
    a.NEXT = &b;

    b.data = 2;
    b.NEXT = &c;

    c.data = 4;
    c.NEXT = NULL;

    Node p1, p2, p3;
    p1.data = 100;
    p1.NEXT = &p2;

    p2.data = 200;
    p2.NEXT = &p3;

    p3.data = 300;
    p3.NEXT = NULL;


    Node *link_1 = &a;
    Node *link_2 = &p1;














    //印出all node
    
    printf("%-40s", "印出link_1: ");
    linked_list_print(link_1);
    printf("%-40s", "印出link_2: ");
    linked_list_print(link_2);
    printf("%-40s", "印出link_2 catenate link_1: ");
    linked_list_catenate(link_1, link_2, 5);
    linked_list_print(link_1);
    printf("%d\n", linked_list_search(link_1, 300));

    
    return 0;
}