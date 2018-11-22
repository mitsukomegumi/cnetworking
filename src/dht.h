#include "common/common.h"

#ifndef DHT_H
#define DHT_H

// Node - struct containing node address
typedef struct Node {
    char *Address; // Address - node IP address
} Node;

// DHT - list holding registered nodes
typedef struct DHT {
    Node *Nodes[MAX_CLIENTS]; // All registered nodes of max client size
} DHT;

DHT *newDHT(); // newDHT - DHT initializer

void addNode(char address[]); // addNode - write node to DHT

#endif