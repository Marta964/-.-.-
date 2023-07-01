#include "Header.h"

int main() {
    Cache* cache = createCache(MAX_CACHE_SIZE);
  

    while (1) {
        printf("1.Find IP by domain\n2.Find domain by IP\n3. Add record\n4. Print cache\n5.Exit\n");
        int c;
        while (!scanf_s("%d", &c) || c < 1 || c>5 || getchar() != '\n') {
            printf("Input error.Try again.");
            rewind(stdin);
        }

        if (c == 1) findIPByDomain(cache);
        else if (c == 2) findDNSbyIP(cache);
        else if (c == 3) addDns();
        else if (c == 4) printCache(cache);
        else if (c == 5) {
            freeCache(cache);
            return 0;
        }
        if (cache == NULL)
        printf("\n");
    }
}