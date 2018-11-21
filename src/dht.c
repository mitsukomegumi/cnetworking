#define MAX_CLIENTS 5

// Node - struct containing node address
typedef struct Node {
    char *Address; // Address - node IP address
} Node;

// DHT - list holding registered nodes
typedef struct DHT {
    Node *nodes[MAX_CLIENTS]; // All registered nodes of max client size
} DHT;

// addNode - write node to DHT
void addNode(char address[]) {

}