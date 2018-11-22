#include <stdlib.h> // Import stdlib
#include <stdio.h> // Import i/o
#include <string.h> // Import strings
#include "dht.h" // Import headers
#include "../common/common.h" // Import common

DHT *newDHT() {
    DHT *dht = malloc(2*MAX_CLIENTS*sizeof(char[15])); // Allocate DHT

    FILE * file = fopen("dht.dht", "wb"); // Open file

    if (file != NULL) { // Check is null
        fwrite(dht, sizeof(dht), 1, file); // Init dht
        fclose(file); // Close file
    }

    return dht; // Return initialized DHT
}

// addNode - write node to DHT
void addNode(char address[]) {
    DHT *dht = malloc(2*MAX_CLIENTS*sizeof(char[15])); // Allocate DHT

    FILE * file = fopen("dht.dht", "rb"); // Open file

    if (file != NULL) { // Check is null
        fread(dht, sizeof(dht), 1, file);
        fclose(file);
    }

    int x; // Init incrementor

    for (x = 0; x != MAX_CLIENTS; x++) { // Iterate over nodes
        if ((*dht).Nodes[x] == NULL || x == MAX_CLIENTS - 1) { // Check is empty node or reached end of list
            Node *node = malloc(sizeof(char[15])); // Allocate node

            (*node).Address = address; // Set address

            (*dht).Nodes[x] = node; // Set node
        }
    }

    FILE * writeFile = fopen("dht.dht", "wb"); // Open file

    if (writeFile != NULL) { // Check is null
        fwrite(&dht, sizeof(dht), 1, writeFile); // Write dht
        fclose(writeFile); // Close file
    }
}