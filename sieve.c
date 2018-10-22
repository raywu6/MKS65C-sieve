#include <stdlib.h>
#include <math.h>
#include "sieve.h"

int sieve(int n) {
    int ARRAY_SIZE = 1.15 * n * log(n);
	char * sifter = (char *) calloc( ARRAY_SIZE , sizeof(char) );
    int numPrimes = 0;

    for (int index=2 ; index<ARRAY_SIZE ; index++) {

        // if value is 0 (prime)
        if (!sifter[index]) {
            numPrimes++;
            
            if (numPrimes == n) {
                free(sifter);
                return index;
            }

            // mark off all multiples
            // no need to mark off for composites
            for (int j = index*2 ; j<ARRAY_SIZE ; j+=index) {
                if (!sifter[j])
                    sifter[j] = 'x';
            }
        }
    }
    
    free(sifter);
	return -1;
}
