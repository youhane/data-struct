// 4. Given a sorted linked list, remove all the duplicates.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char name[255];
    int score;
    Node *next; //pointer node selanjutnya
} * head, *tail;
//head node pertama
//tail node terakhir

Node *createNode(const char *name, int score)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL; //yg awalnya NULL, biar bisa diisi
    return newNode;
}

void pushTail(const char *name, int score)
{
    Node *temp = createNode(name, score);
    if (!head) //ini 0 node (jadi kosong)
    {
        head = tail = temp; //linkedlist kosong, jadi temp jadi head sama tail
    }
    else //ini ada isinya, (>0)
    {
        tail->next = temp; //tail yg lama jadi next
        tail = temp;       //temp jadi tail
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

void popHead()
{
    if (!head)
    {
        return; //gaada head, gaada tail mau diapain yaudah, return aja, gabisa ngapa2in
    }
    else
    {
        //ngeswap
        Node *temp = head; //diambil
        head = temp->next; //ditaro
        temp->next = NULL; //ytemp ke next bikin gabisa nyambung
        free(temp);        //si temp dibuang
    }
}

void popTail()
{
    if (!head)
    {
        return; //gaada head, gaada tail mau diapain yaudah, return aja, gabisa ngapa2in
    }
    else if (head == tail)
    {
        head = tail = NULL; //soalnya sama aja
        free(head);
    }
    else
    {
        Node *temp = head;
        while (temp->next != tail) //diulang asal itu blm sampe tail, soalnya tail yg mau dibikin NULL
        {
            temp = temp->next; //dicek
        }
        temp->next = NULL; //pas udah dapet tempnya putusin, jd bisa dimasukin sebagai NULL
        free(tail);        //tailnya kosongin
        tail = temp;       //tail masukin temp
    }
}

void printLinedList()
{
    //printnfnya kan start dari head, dari awal
    Node *curr = head; //index yg akan berjalan, patokan
    while (curr)
    {
        printf("%s %d -> ", curr->name, curr->score);
        //abis di print dimajuin, sesuai sama node next
        //jadi maju2 sampe NULL, soalnya NULL kan ga sesuai sama (curr)
        //jadi stop krn udah ga memenuhi
        curr = curr->next;
    }
    printf("NULL\n");
}

int main()
{
    int n;
    printf("Input size of first linked list: ");
    scanf("%d", &n);
    printf("Input elements of the linkedlist (string, angka)\n");
    char str[255];
    int a;
    for (int i = 0; i < n; i++)
    {
        printf("Elemen ke - %d : ", i);
        scanf("%s %d", str, &a);
        pushHead(str, a);
    }
    puts("");
    Node *curr = head;
    while (curr)
    {
        if (curr == curr->next)
        {
            Node *temp = curr;
            head = curr->next;
            curr->next = NULL;
            free(curr);
        }
    }
    printLinedList();
    return 0;
}