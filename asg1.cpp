#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Given two sorted linked lists L1 and L2 of size M and N respectively,
//merge them into one sorted linked list.

struct Node
{
    char name[255];
    int score;
    Node *next;
} * head, *tail;

Node *createNode(const char *name, int score)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;
    return newNode;
}

void pushTail(const char *name, int score)
{
    Node *temp = createNode(name, score);
    if (!head)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void pushHead(const char *name, int score)
{
    Node *temp = createNode(name, score);
    if (!head)
    {
        head = tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

void pushMid(const char *name, int score)
{
    if (!head)
    {
        pushHead(name, score);
    }
    else if (score <= head->score)
    {
        pushHead(name, score);
    }
    else if (score > tail->score)
    {
        pushTail(name, score);
    }
    else
    {
        Node *temp = createNode(name, score);
        Node *target, *prevTarget;
        target = head;
        while (score > target->score)
        {
            prevTarget = target;
            target = target->next;
        }
        prevTarget->next = temp;
        temp->next = target;
    }
}

void printLinkedList()
{
    Node *curr = head;
    while (curr)
    {
        printf("%s %d -> ", curr->name, curr->score);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main()
{
    int n, m;
    printf("Input size of first linked list: ");
    scanf("%d", &n);
    getchar();
    printf("Input elements of the first linkedlist (string, angka)\n");
    char str[255];
    int a;
    for (int i = 0; i < n; i++)
    {
        printf("Elemen ke - %d : ", i);
        scanf("%s %d", str, &a);
        pushHead(str, a);
    }
    puts("");
    printf("\nInput size of second linked list: ");
    scanf("%d", &m);
    printf("Input elements of the second linkedlist (string, angka)\n");
    for (int j = 0; j < m; j++)
    {
        printf("Elemen ke %d : ", j);
        scanf("%s %d", str, &a);
        pushHead(str, a);
    }
    printLinkedList();
    return 0;
}