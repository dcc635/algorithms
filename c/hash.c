#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define TABLE_LENGTH 20
#define MAX_STR_LEN 50

struct hashnode{
    char key[MAX_STR_LEN];
    int value;
    struct hashnode *next;
    struct hashnode *prev;
};
typedef struct hashnode Hashnode;

struct hashtable{
    Hashnode table[TABLE_LENGTH];
};
typedef struct hashtable Hashtable;

void hash_init(Hashtable *myhash){
    int i;
    Hashnode mynode = { "", -1, NULL, NULL };
    for (i = 0; i < TABLE_LENGTH; i++){
        myhash->table[i] = mynode;
    }
}

int hash_function(char *key){
    int i = 0;
    int sum = 0;
    while ('\0' != key[i]){
        sum += key[i];
        i++; 
    }
    return sum % TABLE_LENGTH;
}

void hash_insert(Hashtable *myhash, char *key, int value){
    int i = hash_function(key);
    Hashnode newnode;
    strcpy(newnode.key, key);
    newnode.value = value;
    myhash->table[i] = newnode;
}
    
int hash_search(Hashtable *myhash, char *key){
    int i = hash_function(key);
    return (myhash->table[i]).value;
}

int main(void){
    Hashtable myhash;
    hash_init(&myhash);
    hash_insert(&myhash, "tim", 27);
    hash_insert(&myhash, "james", 24);
    hash_insert(&myhash, "dan", 23);
//    printf("Dan's age: %d", hash_search(&myhash, "dan"));
    printf("Tim's age: %d\n", hash_search(&myhash, "tim"));
    printf("Dan's age: %d\n", hash_search(&myhash, "dan"));
    printf("James' age: %d\n", hash_search(&myhash, "james"));
//    hash_delete(&myhash, "james");
//    printf("James' age: %d", hash_search(&myhash, "james"));
}
