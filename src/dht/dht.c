#include <stdlib.h> // Import stdlib
#include <stdio.h> // Import i/o
#include <string.h> // Import strings

#include "dht.h" // Import headers
#include "../common/common.h" // Import common

// newDHT - init DHT
DHT *newDHT() {
    DHT *dht = malloc(2*MAX_CLIENTS*sizeof(char[15])); // Allocate DHT

    int x; // Init incrementor

    for (x = 0; x != MAX_CLIENTS; x++) { // Iterate over nodes
        (*dht).Nodes[x] = NULL; // Set null
    }

    return dht; // Return initialized DHT
}

// writeDHT - write given DHT to memory
void writeDHT(DHT *dht) {
    int x; // Init incrementor

    FILE *fp = fopen("dht.dht", "ab"); // Open/create file

    for (x = 0; x != MAX_CLIENTS; x++) { // Iterate over nodes
        if ((*dht).Nodes[x]) { // Check is not empty node
            fputs((*dht).Nodes[x]->Address, fp); // Write address to file

            break; // Break loop
        }
    }

    fclose(fp); // Close file
}

// readDHT - read DHT from memory
DHT *readDHT() {
    DHT *dht = malloc(2*MAX_CLIENTS*sizeof(char[15])); // Allocate DHT

    FILE *fp = fopen("dht.dht", "r"); // Open/create file

    char *line = NULL; // Init buffer
    size_t len = 0; // Init buffer
    ssize_t read; // Init buffer
    int x = 0; // Init incrementor
    char *lastLine = NULL; // Init last line buffer

    while ((read = getline(&line, &len, fp)) != -1) {
        if (x > 0) { // Check not 0 index
            lastLine = (*dht).Nodes[x-1]->Address; // Set last
            printf("%s\n", lastLine);
        }

        if (line && strlen(line) != 0 && line != lastLine) { // Check line not nil and not repeated
            printf("%d\n", x);
            printf("%s\n", line);

            Node *node = malloc(sizeof(char[15])); // Allocate node

            (*node).Address = line; // Set address

            (*dht).Nodes[x] = node; // Set node

            x++; // Increment
        }
    }

    fclose(fp); // Close file

    return dht; // Return read DHT
}

// addNode - write node to DHT
void addNode(char address[]) {
    DHT *dht = readDHT(); // Read DHT

    int x; // Init incrementor

    for (x = 0; x != MAX_CLIENTS; x++) { // Iterate over nodes
        if (!(*dht).Nodes[x] || x == MAX_CLIENTS - 1) { // Check is empty node or reached end of list
            Node *node = malloc(sizeof(char[15])); // Allocate node

            (*node).Address = address; // Set address

            (*dht).Nodes[x] = node; // Set node

            break; // Break loop
        }
    }

    writeDHT(dht); // Write DHT

    free(dht); // Free
}