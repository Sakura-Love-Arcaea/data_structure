#include <stdio.h>
#include <string.h>

struct data {
    int number;
    char string[64];
};

struct node {
    struct data data;
    struct node *NEXT;
};

typedef struct data Data;
typedef struct node Node;

Node *pop(Node **const);
Node *push(Node **const HEAD, Node *node);

Node *pop(Node **const HEAD) {
    Node *head = *HEAD; //宣告一個指向top的指標, 來源: 引數,開頭指標的指標    
    if (head == NULL) {
        puts("The stack is empty!");
        return NULL;
    }
    *HEAD = head->NEXT; //把指向開頭指標的指標改成,top所指向的指標
    head->NEXT = NULL;//斷掉top的牽連
    return head;//回傳top
}

Node *push(Node **const HEAD, Node *node) {
    Node *TEMP = *HEAD;//把目前指向top記下來
    *HEAD = node;//修改HEAD的指向,改為指向node
    node->NEXT = TEMP;//修改node的指向,指向top
    return node;
}

int main() {
    Node n1, n2, n3, n4, n5;
    Node p1, p2, p3, p4, p5;
    Node *list_n, *list_p;
    
    list_n = &n1;
    {
    n1.data.number = 1;
    strcpy(n1.data.string, "this is first node");
    n1.NEXT = &n2;

    n2.data.number = 2;
    strcpy(n2.data.string, "this is second node");
    n2.NEXT = &n3;

    n3.data.number = 3;
    strcpy(n3.data.string, "this is third node");
    n3.NEXT = &n4;

    n4.data.number = 4;
    strcpy(n4.data.string, "this is fourth node");
    n4.NEXT = &n5;

    n5.data.number = 5;
    strcpy(n5.data.string, "this is fifth node");
    n5.NEXT = NULL;
    }

    
    Node nn = {{99, "new node"}, NULL};


    push(&list_n, &nn);



    while (list_n) {
        printf("%d %s\n", list_n->data.number, list_n->data.string);
        list_n = list_n->NEXT;
    }
}