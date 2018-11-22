#include "dht.h"
#include "../common/common.h"

int main() {
    printFlush("test"); // Log

    DHT *dht = newDHT(); // Init DHT

    addNode("localhost"); // Add node
}