#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 365 // # slots in hashtable

struct HTElement
{
    int value;
    struct HTElement* next;
}* HT[N];


void insert(struct HTElement *HT[], int idx, int val){

    if (HT[idx] == NULL)
    {
        HT[idx] = malloc(sizeof(struct HTElement));
        HT[idx]->value = val;
        HT[idx]->next = NULL;
    }
    else
    {   
        struct HTElement *q;
        q = malloc(sizeof(struct HTElement));
        q->value = val;
        q->next = HT[idx];
        HT[idx] = q;
    }
}

void randomBDCount(struct HTElement *HT[], int res[], int n){
    // assign people to random Birthdays (HT slots)
    for (int i = 0; i < n; i++)
    {
        int r = rand() % 366;
        insert(HT, r, i);
    }

    // count shared Birthdays
    int peopleCount = 0; // counts how many people share their birthday with someone else
    int dayCount = 0; // counts the days on which more than one person have birthday
    for (int i = 0; i < 356; i++)
    {
        if (HT[i] != NULL)
        {   
            int people = 1;
            struct HTElement *q = HT[i];
            while (q->next != NULL)
            {   
                q = q->next;
                people++;
            }
            if (people > 1)
            {
                peopleCount = peopleCount + people;
                dayCount++;
            }
        }
    }
    res[0] = dayCount;
    res[1] = peopleCount;
}

int main(){
    srand(time(NULL));

    int n = 100; // number of people
    int res[2];
    randomBDCount(HT, res, n);

    printf("Days with shared Birthday: %d\n", res[0]);
    printf("People who share Birthday: %d\n", res[1]);
    
    
    // printf("%d\n", HT[1]->value);
    // printf("%d\n", HT[1]->next);
    // printf("%d\n", HT[1]->next->value);
    // printf("%d\n", HT[1]->next->next);
    // printf("%d\n", HT[1]->next->next->value);
    // printf("%d\n", HT[1]->next->next->next);

    return 0;
}