#include <stdio.h> // Import i/o
#include <string.h> // Import strings

#define MAX_CLIENTS 5

// Node - struct containing node address
typedef struct Node {
    char *Address; // Address - node IP address
} Node;

// DHT - list holding registered nodes
typedef struct DHT {
    Node *Nodes[MAX_CLIENTS]; // All registered nodes of max client size
} DHT;

void newDHT() {
    DHT dht = {}; // Init DHT

    FILE * file = fopen("dht.x", "wb"); // Open file

    if (file != NULL) { // Check is null
        fwrite(&dht, sizeof(dht), 1, file); // Init dht
        fclose(file); // Close file
    }
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