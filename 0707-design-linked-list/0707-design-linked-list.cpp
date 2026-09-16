class MyLinkedList {
public:

    struct Node {
        int val;
        Node* next;

        Node(int val) {
            this->val = val;
            this->next = nullptr;
        }
    };

    Node* head;

    MyLinkedList() {
        head = nullptr;
    }

    int get(int index) {

        Node* temp = head;

        for(int i = 0; i < index; i++) {

            if(temp == nullptr)
                return -1;

            temp = temp->next;
        }

        if(temp == nullptr)
            return -1;

        return temp->val;
    }

    void addAtHead(int val) {

        Node* newNode = new Node(val);

        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val) {

        Node* newNode = new Node(val);

        if(head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while(temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void addAtIndex(int index, int val) {

        if(index == 0) {
            addAtHead(val);
            return;
        }

        Node* temp = head;

        for(int i = 0; i < index - 1; i++) {

            if(temp == nullptr)
                return;

            temp = temp->next;
        }

        if(temp == nullptr)
            return;

        Node* newNode = new Node(val);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtIndex(int index) {

        if(head == nullptr)
            return;

        if(index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;

        for(int i = 0; i < index - 1; i++) {

            if(temp == nullptr)
                return;

            temp = temp->next;
        }

        if(temp == nullptr || temp->next == nullptr)
            return;

        Node* deleteNode = temp->next;

        temp->next = deleteNode->next;

        delete deleteNode;
    }
};