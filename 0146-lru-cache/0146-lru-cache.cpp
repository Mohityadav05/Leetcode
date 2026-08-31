class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> m;

    int limit;

    void addNode(Node* newNode) {
        Node* oldnext = head->next;

        head->next = newNode;
        newNode->prev = head;

        newNode->next = oldnext;
        oldnext->prev = newNode;
    }

    void delNode(Node* oldNode) {
        Node* oldprev = oldNode->prev;
        Node* oldnext = oldNode->next;

        oldprev->next = oldnext;
        oldnext->prev = oldprev;
    }

    LRUCache(int capacity) {
        limit = capacity;

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if (m.find(key) == m.end()) {
            return -1;
        }

        Node* ansNode = m[key];

        int ans = ansNode->val;

        // remove from old position
        delNode(ansNode);

        // move to most recently used position
        addNode(ansNode);

        return ans;
    }

    void put(int key, int value) {

        // key already exists
        if (m.find(key) != m.end()) {

            Node* oldNode = m[key];

            delNode(oldNode);
            m.erase(key);

            delete oldNode;
        }

        // cache is full
        if (m.size() == limit) {

            Node* lruNode = tail->prev;

            m.erase(lruNode->key);

            delNode(lruNode);

            delete lruNode;
        }

        // insert new node
        Node* newNode = new Node(key, value);

        addNode(newNode);

        m[key] = newNode;
    }
};