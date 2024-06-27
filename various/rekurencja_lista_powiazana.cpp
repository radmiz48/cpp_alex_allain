#include <iostream>

struct Node
{
    int val;
    Node* next;
};

void print( Node* head ) {
    while( head != nullptr ) {
        std::cout << head->val << ' ';
        head = head->next;
    }
    std::cout << '\n';
}

Node* find( Node* head, int val_to_find ) {
    // Return NULL if the node is empty
    // or has no such value in the list
    if( head == nullptr ) {
        return nullptr;
    }
    // If the given value is in the list, return this node
    // otherwise keep searching
    if( head->val == val_to_find ) {
        return head;
    } else {
        return find( head->next, val_to_find );
    }
}

int main()
{
    // Create a linked list
    Node* fib = new Node {1};
    Node* fib2 = new Node {1};
    Node* fib3 = new Node {2};
    Node* fib4 = new Node {3};
    Node* fib5 = new Node {5};
    Node* fib6 = new Node {8};
    fib->next = fib2;
    fib2->next = fib3;
    fib3->next = fib4;
    fib4->next = fib5;
    fib5->next = fib6;
    fib6->next = nullptr;

    // Print sequence items
    std::cout << "Fibonacci numbers: ";
    print( fib );

    // Find a number from a sequence
    int num_to_find;
    Node* res = new Node;
    std::cout << "Enter the number to find in the Fibonacci sequence: ";
    std::cin >> num_to_find;
    res = find( fib, num_to_find );
    std::cout << "Number " << num_to_find << ((res == nullptr) ? " is not" : " not") << " on the list." << '\n';

    // Freeing up memory is still needed
    
    return 0;
}