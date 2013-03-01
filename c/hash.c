#include <stdlib.h>
#include <stdio.h>

#define TABLE_LENGTH 100

struct hashnode{
    char *key;
    int value;
    struct hashnode *next;
    struct hashnode *prev;
};
typedef struct hashnode Hashnode;

struct hashtable{
    Hashnode table[TABLE_LENGTH];
};
typedef struct hashtable Hashtable;

int hash_function(char *key){
    int i = 0;
    int sum = 0;
    while (NULL != key[i]){
        sum += key[i];
        i++; 
    }
    return sum % TABLE_LENGTH;
}

void hash_insert(Hashtable **myhash, char *key, int value){
    i = hash_function(key);
    myhash->table[i] = value;
}
    

int main(void){
    Hashtable myhash;
    hash_insert(&myhash, "tim", 27);
    hash_insert(&myhash, "james", 24);
    hash_insert(&myhash, "dan", 23);
    printf("Dan's age: %d", hash_search(&myhash, "dan"));
    printf("Tim's age: %d", hash_search(&myhash, "tim"));
    printf("James' age: %d", hash_search(&myhash, "james"));
    hash_delete(&myhash, "james");
    printf("James' age: %d", hash_search(&myhash, "james"));
}
