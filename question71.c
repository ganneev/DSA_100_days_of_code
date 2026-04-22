#include <stdio.h>
#include <string.h>

#define EMPTY -1

int main() {
    int m, n;
    
    // Input size of hash table and number of operations
    scanf("%d", &m);
    scanf("%d", &n);
    
    int table[m];
    
    // Initialize hash table with EMPTY
    for(int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }
    
    char operation[10];
    int key;
    
    for(int j = 0; j < n; j++) {
        scanf("%s %d", operation, &key);
        
        int hash = key % m;
        
        if(strcmp(operation, "INSERT") == 0) {
            int i = 0;
            while(i < m) {
                int index = (hash + i * i) % m;
                
                if(table[index] == EMPTY) {
                    table[index] = key;
                    break;
                }
                i++;
            }
        }
        
        else if(strcmp(operation, "SEARCH") == 0) {
            int found = 0;
            int i = 0;
            
            while(i < m) {
                int index = (hash + i * i) % m;
                
                if(table[index] == key) {
                    found = 1;
                    break;
                }
                
                if(table[index] == EMPTY) {
                    break;
                }
                
                i++;
            }
            
            if(found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }
    
    return 0;
}