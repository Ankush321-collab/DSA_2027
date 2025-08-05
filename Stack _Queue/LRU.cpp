#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

Node* head;
Node* tail;
unordered_map<int, Node*> m;
int cap;

void init(int capacity) {
    cap = capacity;
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
}

void addNode(Node* newnode) {
    Node* temp = head->next;
    newnode->next = temp;
    newnode->prev = head;
    head->next = newnode;
    temp->prev = newnode;
}

void deleteNode(Node* delnode) {
    Node* prevnode = delnode->prev;
    Node* nextnode = delnode->next;
    prevnode->next = nextnode;
    nextnode->prev = prevnode;
}

int get(int key) {
    if (m.find(key) != m.end()) {
        Node* resnode = m[key];
        int ans = resnode->value;

        m.erase(key);
        deleteNode(resnode);
        addNode(resnode);
        m[key] = head->next;

        return ans;
    }
    return -1;
}

void put(int key, int value) {
    if (m.find(key) != m.end()) {
        Node* resnode = m[key];
        m.erase(key);
        deleteNode(resnode);
    }

    if (m.size() == cap) {
        m.erase(tail->prev->key);
        deleteNode(tail->prev);
    }

    Node* newnode = new Node(key, value);
    addNode(newnode);
    m[key] = head->next;
}

int main() {
    init(3); // set LRU capacity

    put(1, 100);
    put(2, 200);
    put(3, 300);

    cout << "Get 2: " << get(2) << endl;  // should return 200
    cout << "Get 1: " << get(1) << endl;  // should return 100

    put(4, 400); // will evict key 3 (least recently used)

    cout << "Get 3: " << get(3) << endl;  // should return -1 (evicted)
    cout << "Get 4: " << get(4) << endl;  // should return 400

    return 0;
}
