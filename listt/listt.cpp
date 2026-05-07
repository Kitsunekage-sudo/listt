#include <iostream>
using namespace std;

template<class T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* previous;

    Node(T value) {
        data = value;
        next = nullptr;
        previous = nullptr;
    }
};

template<class T>
class LinkedList {
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    LinkedList() : head{ nullptr }, tail{ nullptr }, size{ 0 } {}

    // Add to end
    void add_before(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {
            head = tail = newNode;
            size++;
            return;
        }

        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
        size++;
    }

    // Add to beginning
    void add_after(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {
            head = tail = newNode;
            size++;
            return;
        }

        newNode->next = head;
        head->previous = newNode;
        head = newNode;
        size++;
    }

    void print_before() {
        Node<T>* current = head;

        while (current != nullptr) {
            cout << current->data << "\t";
            current = current->next;
        }

        cout << endl;
    }

    void print_after() {
        Node<T>* current = tail;

        while (current != nullptr) {
            cout << current->data << "\t";
            current = current->previous;
        }

        cout << endl;
    }

    // Search element
    bool linear_search(T value) {
        Node<T>* current = head;

        while (current != nullptr) {
            if (current->data == value)
                return true;

            current = current->next;
        }

        return false;
    }

    // Reverse linked list
    void reverse_before() {
        Node<T>* current = head;
        Node<T>* temp = nullptr;

        while (current != nullptr) {
            // swap next and previous
            temp = current->previous;
            current->previous = current->next;
            current->next = temp;

            current = current->previous;
        }

        // swap head and tail
        temp = head;
        head = tail;
        tail = temp;
    }

    // Bubble sort
    void bubble_sort() {
        if (head == nullptr)
            return;

        bool swapped;

        do {
            swapped = false;
            Node<T>* current = head;

            while (current->next != nullptr) {

                if (current->data > current->next->data) {
                    swap(current->data, current->next->data);
                    swapped = true;
                }

                current = current->next;
            }

        } while (swapped);
    }

    // Shift list left by count
    void shift_before(int count) {
        if (head == nullptr || count <= 0)
            return;

        count %= size;

        for (int i = 0; i < count; i++) {

            Node<T>* temp = head;

            head = head->next;
            head->previous = nullptr;

            tail->next = temp;
            temp->previous = tail;

            temp->next = nullptr;
            tail = temp;
        }
    }
};

int main()
{
    LinkedList<int>* list = new LinkedList<int>();

    list->add_before(8);
    list->add_before(7);
    list->add_before(12);
    list->add_before(1);
    list->add_before(3);

    cout << "Original:\n";
    list->print_before();

    cout << "Reverse print:\n";
    list->print_after();

    cout << "\nSearch 12: ";
    cout << (list->linear_search(12) ? "Found" : "Not found") << endl;

    cout << "\nSorted:\n";
    list->bubble_sort();
    list->print_before();

    cout << "\nShift by 2:\n";
    list->shift_before(2);
    list->print_before();

    cout << "\nReversed:\n";
    list->reverse_before();
    list->print_before();

    return 0;
}