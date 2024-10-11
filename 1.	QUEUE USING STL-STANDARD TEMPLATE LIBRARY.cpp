#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // Adding elements to the queue
q.push(30);
q.push(20);
q.push(10);

    // Print the front element of the queue
cout<< "Front element before pop: " <<q.front() <<endl;

    // Remove the front element from the queue
q.pop();

    // Print the front element after pop
cout<< "Front element after pop: " <<q.front() <<endl;

    return 0;
}
