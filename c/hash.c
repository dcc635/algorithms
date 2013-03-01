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

void hashnode_init(Hashnode *mynode){
    memset(mynode->key, 0, MAX_STR_LEN);
    mynode->value = -1;
    mynode->next = NULL;
    mynode->prev = NULL;
}

void hashtable_init(Hashtable *myhash){
    int i;
    for (i = 0; i < TABLE_LENGTH; i++){
        hashnode_init(&(myhash->table[i]));
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
    hashnode_init(&newnode);
    strcpy(newnode.key, key);
    newnode.value = value;
    myhash->table[i] = newnode;
    printf("Inserted entry \"%s\" with value %d.\n", key, value);
}
    
int hash_search(Hashtable *myhash, char *key){
    int i = hash_function(key);
    int value = (myhash->table[i]).value;
    return value;
}

void hash_delete(Hashtable *myhash, char *key){
    int i = hash_function(key);
    hashnode_init(&(myhash->table[i]));
    printf("Deleted entry \"%s\".\n", key);
}

void print_entry(Hashtable *myhash, char *key){
    int age = hash_search(myhash, key);
    if (-1 == age){
        printf("Entry \"%s\" not found.\n", key);
    }
    else {
        printf("%s's age: %d\n", key, age);
    }
}

int main(void){
    Hashtable myhash;
    hashtable_init(&myhash);
    hash_insert(&myhash, "Tim", 27);
    hash_insert(&myhash, "James", 24);
    hash_insert(&myhash, "Dan", 23);
//    printf("Dan's age: %d", hash_search(&myhash, "dan"));
    print_entry(&myhash, "Tim");
    print_entry(&myhash, "Dan");
    print_entry(&myhash, "James");
//    printf("Tim's age: %d\n", hash_search(&myhash, "tim"));
//    printf("Dan's age: %d\n", hash_search(&myhash, "dan"));
//    printf("James' age: %d\n", hash_search(&myhash, "james"));
    hash_delete(&myhash, "James");
    print_entry(&myhash, "James");
//    printf("James' age: %d\n", hash_search(&myhash, "james"));
}
