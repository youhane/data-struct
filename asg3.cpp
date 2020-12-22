// 3. Find the middle element of a linked list.
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

// contoh
// 3, 1 doang kan, ya 3 itu head sama tail
//kalo 3 -> 4, itu headnya 3, tailnya 4

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

int n;

void printLinedList()
{
    //printnfnya kan start dari head, dari awal
    Node *curr = head; //index yg akan berjalan, patokan
    int i = n;
    while (i--)
    {
        if (i == n / 2)
        {
            printf("%s %d -> ", curr->name, curr->score);
        }
        curr = curr->next;
    }
    printf("NULL\n");
}

int main()
{
    printf("Input size of first linked list: ");
    scanf("%d", &n);
    getchar();
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
    printLinedList();
    return 0;
}