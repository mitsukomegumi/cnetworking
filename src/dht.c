#include <stdlib.h> // Import stdlib
#include <stdio.h> // Import i/o
#include <string.h> // Import strings
#include "dht.h" // Import headers

#define MAX_CLIENTS 5

DHT *newDHT() {
    DHT *dht = malloc(2*MAX_CLIENTS*sizeof(char[15])); // Allocate DHT

    FILE * file = fopen("dht.x", "wb"); // Open file

    if (file != NULL) { // Check is null
        fwrite(dht, sizeof(dht), 1, file); // Init dht
        fclose(file); // Close file
    }

    return dht; // Return initialized DHT
}

// addNode - write node to DHT
void addNode(char address[]) {
    DHT dht = {}; // Init DHT buffer

    FILE * file = fopen("dht.x", "rb"); // Open file

    if (file != NULL) { // Check is null
        fread(&dht, sizeof(dht), 1, file);
        fclose(file);
    }

    int x; // Init incrementor

    for (x = 0; x != MAX_CLIENTS; x++) { // Iterate over nodes
        if (strlen(dht.Nodes[x]->Address) == 0 || x == MAX_CLIENTS - 1) { // Check is empty node or reached end of list
            dht.Nodes[x]->Address = address; // Set address
        }
    }

    FILE * writeFile = fopen("dht.x", "wb"); // Open file

    if (writeFile != NULL) { // Check is null
        fwrite(&dht, sizeof(dht), 1, writeFile); // Write dht
        fclose(writeFile); // Close file
    }
}