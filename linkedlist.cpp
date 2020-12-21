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
    pushHead("Nama", 95);
    pushTail("yes", 96);
    pushHead("asda", 100);
    pushHead("okko", 10);
    pushTail("namaaa", 92);
    pushTail("ohgitu", 93);
    printLinedList();
    puts("Ini abis di popHead()");
    popHead(); //depan = head = ilang
    printLinedList();
    puts("Ini ke poptail 2x");
    popTail(); //blkg = tail = ilang
    popTail();
    printLinedList();
    return 0;
}