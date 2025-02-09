#include <iostream>

struct Queue{
    int front, rear, size, capacity;
    int* arr;
};

Queue* createQueue(int capacity){
    Queue* queue = new Queue();
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->arr = new int[queue->capacity];
    return queue;
}

bool isFull(Queue* queue){
    return (queue->size == queue->capacity);
}

bool isEmpty(Queue* queue){
    return(queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        std::cout << "Queue is full\n";
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = item;
    queue->size = queue->size + 1;
    std::cout << item << " enqueued to queue\n";
}

void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        std::cout << "Queue is empty\n";
        return;
    }
    int item = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    std::cout << item << " dequeued from queue\n";
}

void print(Queue* queue) {
    if (isEmpty(queue)) {
        std::cout << "Queue is empty\n";
        return;
    }
    int index = queue->front;
    for (int i = 0; i < queue->size; i++) {
        std::cout << queue->arr[index] << " ";
        index = (index + 1) % queue->capacity;
    }
    std::cout << "\n";
}

int main(){
    Queue* queue = createQueue(3);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    print(queue);
    
    dequeue(queue);
    print(queue);

    enqueue(queue, 40);
    print(queue);

    return 0;
}