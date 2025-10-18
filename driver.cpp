#include "ArrayQueue.hpp"

int main() {
    cout << "Testing exception handling with empty list: \n";
    ArrayQueue<int> numbers;
    try {
        numbers.front();
        } catch (const std::string& msg) {
        cout << "Caught expected exception from front(): " << msg << '\n';
    }
    try {
        numbers.back();
    } catch (const std::string& msg) {
        cout << "Caught expected exception from back(): " << msg << '\n';
    }
    try {
        numbers.dequeue();
    } catch (const std::string& msg) {
        cout << "Caught expected exception from dequeue(): " << msg << '\n';
    }

    cout << "\nTesting Array Queue implementation with int: \n";
    numbers.enqueue(10);
    numbers.enqueue(20);
    numbers.enqueue(30);
    cout << "Front number -> " << numbers.front() << '\n';
    cout << "Back number -> " << numbers.back() << '\n';
    numbers.dequeue();
    cout << "After one dequeue: \n";
    cout << "Front changes -> " << numbers.front() << '\n';
    cout << "Back remains -> " << numbers.back() << '\n';
    numbers.enqueue(40);
    numbers.enqueue(50);
    cout << "After enqueue 40,50 \n";
    cout << "Back number -> " << numbers.back() << '\n';

    cout << "\nCopy constructor test: \n";
    ArrayQueue<int> copied(numbers);
    int length = numbers.getLength();
    cout << "Original queue: ";
    for (int i = 0; i < length; i++) {
        cout << numbers.front() << ", ";
        numbers.dequeue();
    }
    int copiedLen = copied.getLength();
    cout << "\nCopied queue: ";
    for (int i = 0; i < copiedLen; i++) {
        cout << copied.front() << ", ";
        copied.dequeue();
    }

    cout << "\nClearing copied list...\n";
    copied.clear();
    if(copied.getLength() == 0){
        cout << "List is empty! \n";
    } else{
        cout << "List is not empty";
    }

    // Test with a different data type (std::string) to ensure template coverage.
    cout << "\nTesting Array Queue implementation with string: \n";
    ArrayQueue<string> words;
    words.enqueue("alpha");
    words.enqueue("beta");
    words.enqueue("gamma");
    cout << "Front word: -> " << words.front() << '\n';
    cout << "Back word: -> " << words.back() << '\n';
    words.dequeue();
    cout << "Front changes: " << words.front() << '\n';
    return 0;
}