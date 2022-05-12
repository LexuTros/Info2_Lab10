#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define m 20 // Size of Hashtable
#define OCC 0
#define EMP -1
#define DEL -2


struct HTElement
{
    int value;
    int status; // 0: Occupied, -1: Empty, -2: Deleted
} HT[m];

void init(struct HTElement A[]){
    for (int i = 0; i < m; i++)
    {
        A[i].value = 0;
        A[i].status = EMP;
    }
    
}

int hash(int k, int i){
    int m1 = m - 1;
    int hash1 = (k % m) + 1;
    int hash2 = m1 - (k % m1);
    return (hash1 + i*hash2) % m;
}

void insert(struct HTElement A[], int key){
    int i = 0;
    while (A[hash(key, i)].status == OCC && i < m)
    {
        i++;
    }
    if (i >= m) {printf("Error: hash table overflow");}
    else 
    {
        A[hash(key, i)].value = key;
        A[hash(key, i)].status = OCC;
    }
}

void delete(struct HTElement A[], int key){
    int i = 0;
    while (A[hash(key, i)].status != EMP && i < m)
    {
        if (A[hash(key, i)].status == OCC && A[hash(key, i)].value == key)
        {
            A[hash(key, i)].value = 0;
            A[hash(key, i)].status = DEL;
            return;
        }
        i++;
    }
    printf("Error: Element %d not found\n", key);
}

int search(struct HTElement A[], int key){
    int i = 0;
    while (A[hash(key, i)].status != EMP && i < m)
    {
        if (A[hash(key, i)].status == OCC && A[hash(key, i)].value == key)
        {
            return hash(key, i);
        }
        i++;
    }
    return -1;
}

void printHashTable(struct HTElement A[]){
    printf("Table size: %d\n", m);
    for (int i = 0; i < m; i++)
    {
        if (A[i].status == OCC)
        {
            printf("i: %d   key: %d\n", i, A[i].value);
        }
    }
}

int main(){
    init(HT);

    insert(HT, 5);
    insert(HT, 9);
    insert(HT, 2);
    insert(HT, 3);
    insert(HT, 6);

    printHashTable(HT);

    delete(HT, 3);

    printHashTable(HT);

    delete(HT, 3);

    printf("%d\n", search(HT, 5));
    printf("%d\n", search(HT, 4));


    return 0;
}