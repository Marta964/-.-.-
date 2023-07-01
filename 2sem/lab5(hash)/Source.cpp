#include "Header.h"


/*void get_str(char** string) {
    int size = 0;
    int realSize = 16;
    *string = (char*)malloc(realSize * sizeof(char));
    rewind(stdin);
    char check;
    while (1) {
        check = (char)getchar();
        if (check == '\n') {
            if (size + 1 < realSize) {
                *string = (char*)realloc(*string, (size + 1) * sizeof(char));
            }
            (*string)[size] = '\0';
            return;
        }
        (*string)[size] = check;
        size++;
        if (size + 1 == realSize) {
            realSize *= 2;
            *string = (char*)realloc(*string, realSize * sizeof(char));
        }
    }
}*/



void findIPByDomain(Cache* cache) {
    FILE* f = fopen("dns.txt", "r");
    if (f == NULL) {
        printf("Error opening file\n");
        return;
    }
      
   
        printf("Input domain: ");
        char* domain = calloc(1, 256);
        gets(domain);

        int addNew = 0;
        char* result = findDomainFromFile(cache, f, domain, &addNew);

        if (result != NULL) {
            printf("Result: %s\n", result);
            addToCache(cache, domain, result);
        }
        else {
            printf("No matches in the file.\n");
        }
    fclose(f);
}


void addToCache(Cache* cache, const char* key, const char* value){   //алгоритм LRU
    unsigned int hash = hashFunction(key);
    Node* node = cache->table[hash];
    Node* prev = NULL;
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            if (prev != NULL) {
                prev->next = node->next;
                if (node->next != NULL) {
                    node->next->prev = prev;
                }
                node->prev = NULL;
                node->next = cache->table[hash];
                cache->table[hash]->prev = node;
                cache->table[hash] = node;
            }
            // Обновить позицию в списке
            if (cache->list->head != node) {
                if (node->next != NULL) {
                    node->next->prev = node->prev;
                }
                else {
                    cache->list->tail = node->prev;
                }
                node->prev->next = node->next;
                node->prev = NULL;
                node->next = cache->list->head;
                cache->list->head->prev = node;
                cache->list->head = node;
            }
            return;
        }
        prev = node;
        node = node->next;
    }
    node = (Node*)malloc(sizeof(Node));
    node->key = _strdup(key);
    node->value = _strdup(value);
    node->prev = NULL;
    node->next = cache->table[hash];
    if (node->next != NULL) {
        node->next->prev = node;
    }
    cache->table[hash] = node;
    cache->size++;
    // Добавьте в узел 
    if (cache->list->head != NULL) {
        node->next = cache->list->head;
        cache->list->head->prev = node;
        cache->list->head = node;
    }
    else {
        cache->list->head = node;
        cache->list->tail = node;
    }
    if (cache->size > cache->capacity) {
        Node* LRUNode = cache->list->tail;
        cache->list->tail = LRUNode->prev;
        if (cache->list->tail != NULL) {
            cache->list->tail->next = NULL;
        }
        else {
            cache->list->head = NULL;
        }
        unsigned int LRUHash = hashFunction(LRUNode->key);
        if (cache->table[LRUHash] == LRUNode) {
            cache->table[LRUHash] = NULL;
        }
        free(LRUNode->key);
        free(LRUNode->value);
        free(LRUNode);
        cache->size--;
    }
}

char* findDomainFromFile(Cache* cache, FILE* f, char* key, int* addNew)  //поиск домена в файле
{
    char* result = searchIPFromCache(cache, key);
    if (result != NULL) {
        if (cache->size == 1)
            (*addNew)++;
        return result;
    }
    rewind(f);
    char currentWord[MAX_WORD_LENGTH];
    char prevWord[MAX_WORD_LENGTH];
    int found = 0;
    while (fscanf(f, "%s", currentWord) == 1) {
        if (isdigit(key[0])) {
            if (found) {
                result = _strdup(prevWord);
                break;
            }
            if (strcmp(currentWord, key) == 0) {
                found = 1;
                continue;
            }
            strcpy(prevWord, currentWord);
        }
        if (isalpha(key[0])) {
            if (found) {
                if (isalpha(currentWord[0])) {
                    result = findDomainFromFile(cache, f, currentWord, addNew);
                    break;
                }
                result = _strdup(currentWord);
                break;
            }
            if (strcmp(currentWord, key) == 0) {
                found = 1;
                continue;
            }
        }
    }
    if (strcmp(currentWord, key) == 0) {
        result = _strdup(prevWord);
    }
    return result;
}


void findDNSbyIP(Cache* cache){
    char IP[50];
    printf("Enter IP:\n");
    gets(IP);

    FILE* f = fopen("dns.txt", "r");
    if (f == NULL) {
        printf("Error opening file\n");
        return;
    }
    print_DNS(IP, f,cache);
    fclose(f);
}

void print_DNS(const char* IPAddress, FILE* f,Cache* cache){
    char buffer[MAX_WORD_LENGTH];
    rewind(f);
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        char* savePtr = NULL;
        char* fileDNS = strtok(buffer, " \n");
        const char* IP = strtok(NULL, " \n");
        if (strcmp(IP, IPAddress) == 0) {
            printf("%s\n", fileDNS);
            addToCache(cache, fileDNS, IP);
            long pos = ftell(f);
            print_DNS(fileDNS, f,cache);
            fseek(f, pos, SEEK_SET);
        }
    }
}

unsigned int hashFunction(const char* str)
{
    unsigned int hash = 0;
    int i;
    for (i = 0; i < strlen(str); i++) {
        hash = (hash * 33) + i;
    }
    return hash % MAX_CACHE_SIZE;
}

char* searchIPFromCache(Cache* cache, char* key)
{
    unsigned int hash = hashFunction(key);
    Node* node = cache->table[hash];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            if (cache->list->head != node) {   //перемещает искомый домен в начало списка
                if (node->next != NULL) {
                    node->next->prev = node->prev;
                }
                else {
                    cache->list->tail = node->prev;
                }
                node->prev->next = node->next;
                node->prev = NULL;
                node->next = cache->list->head;
                cache->list->head->prev = node;
                cache->list->head = node;
            }
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}

Cache* createCache(int capacity)
{
    Cache* cache = (Cache*)malloc(sizeof(Cache));
    cache->size = 0;
    cache->capacity = capacity;
    cache->table = (Node**)calloc(MAX_CACHE_SIZE, sizeof(Node*));
    cache->list = (CacheList*)malloc(sizeof(CacheList));
    cache->list->head = NULL;
    cache->list->tail = NULL;
    return cache;
}

void addDns() {
    char dns[50];
    char IP[50];
    printf("Write DNS address: ");
    gets(dns);
    printf("Write IP address: ");
    gets(IP);

    FILE* f = fopen("dns.txt", "a+");
    if (f == NULL) {
        printf("Error opening file\n");
        return;
    }
    fseek(f, 0, SEEK_END);
    long length = ftell(f);
    fseek(f, 0, SEEK_SET);
    char* buffer = calloc(length, 1);

    fread(buffer, 1, length, f);
    if (strstr(buffer, dns)) {
        printf("Record already in file\n");
        return;
    }

    if (checkIPValidation(IP) == 0) {
        printf("Invalid IP Address\n");
        return;
    }

    fseek(f, 0, SEEK_END);
    fprintf(f, "\n%s %s", dns, IP);
    fclose(f);
}

int checkIPValidation(const char* ip)// проверка айпи 
{
    int octet = 0;
    int num_octets = 0;
    char* line = _strdup(ip);

    char* ptr = strtok(line, ".\n");
    while (ptr != NULL) {
        num_octets++;
        octet = atoi(ptr);
        if (octet < 0 || octet > 255 || (num_octets == 1 && octet == 0)) {
            free(line);
            return 0;
        }
        ptr = strtok(NULL, ".\n");
    }
    if (num_octets != 4) {
        free(line);
        return 0;
    }
    free(line);
    free(ptr);
    return 1;
}

void printCache(Cache* cache)
{
    Node* node = cache->list->head;
    printf("Current cache:\n");
    while (node != NULL) {
        printf("%s   %s\n", node->key, node->value);
        node = node->next;
    }
}

void freeCache(Cache* cache)
{
    Node* node = cache->list->head;
    while (node != NULL) {
        Node* next = node->next;
        free(node->key);
        free(node->value);
        free(node);
        node = next;
    }
    free(cache->list);
    free(cache->table);
    free(cache);
}