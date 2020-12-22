#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    char name[255];
    Node *next, *prev;
} * head, *tail;

Node *createNode(const char *name)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    strcpy(temp->name, name);
    temp->next = temp->prev = NULL;
    return temp;
}

void pushHead(const char *name)
{
    Node *temp = createNode(name);
    if (!head)
    {
        head = tail = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void pushTail(const char *name)
{
    Node *temp = createNode(name);
    if (!head)
    {
        head = tail = temp;
    }
    else
    {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

void popHead()
{
    if (!head)
    {
        return;
    }
    else if (head == tail) //cuman ada 1 node
    {
        head = tail = NULL;
        free(head);
    }
    else //lebih dari 1 node
    {
        Node *temp = head->next;
        head->next = temp->prev = NULL;
        head = NULL;
        free(head);
        head = temp;
    }
}

void popTail()
{
    if (!head)
    {
        return;
    }
    else if (head == tail) //cuman ada 1 node
    {
        head = tail = NULL;
        free(head);
    }
    else //lebih dari 1 node
    {
        Node *temp = tail->prev;
        tail->prev = temp->next = NULL;
        tail = NULL;
        free(tail);
        tail = temp;
    }
}

void pushMid(const char *name)
{
    Node *temp = createNode(name);
    if (!strcmp(name, head->name) < 0) //masukin didepan
    {
        pushHead(name);
    }
    else if (strcmp(name, head->name) < 0)
    {
        pushHead(name);
    }
    else if (strcmp(name, tail->name) > 0) //masukin di belakang
    {
        pushTail(name);
    }
    else //masukin ditengah
    {
        Node *curr = head;
        while (strcmp(name, curr->name) > 0)
        {
            curr = curr->next;
        }
        curr->prev = temp;
        temp->next = curr;
        temp->prev = curr->prev->prev;
        temp->prev->next = temp;
    }
}

void printLinkedList()
{
    Node *curr = head;
    while (curr)
    {
        printf("%s-> ", curr->name);
        curr = curr->next;
    }
}

int main()
{
    pushMid("Asep");
    pushMid("Budi");
    pushMid("Dodi");
    pushMid("Fajar");
    pushMid("Cecep");
    return 0;
}