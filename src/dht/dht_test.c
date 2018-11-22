#include <stdio.h> // Import standard lib

#include "dht.h" // Import dht headers
#include "../common/common.h" // Import common headers

int main() {
    DHT *dht = newDHT(); // Init DHT

    addNode("localhost"); // Add node

    printf("%s", dht->Nodes[0]->Address); // Log address
}