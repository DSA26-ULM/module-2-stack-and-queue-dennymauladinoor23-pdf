#include "queue.h"
#include <stdexcept>

void init(Queue* q) {
    q->front = q->data;
    q->rear  = q->data - 1; 
}

bool isEmpty(const Queue* q) {
    return q->rear < q->front;
}

bool isFull(const Queue* q) {
    return (q->rear - q->front + 1) == MAX;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        throw std::overflow_error("Queue overflow: queue is full");
    }
    
    if (q->rear == q->data + MAX - 1) {
        int current_size = q->rear - q->front + 1;
        for (int i = 0; i < current_size; i++) {
            q->data[i] = *(q->front + i);
        }
        q->front = q->data;
        q->rear = q->data + current_size - 1;
    }
    
    q->rear++;
    *(q->rear) = value;
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        throw std::underflow_error("Queue underflow: queue is empty");
    }
    q->front++;
    
    if (isEmpty(q)) {
        q->front = q->data;
        q->rear = q->data - 1;
    }
}

int front(const Queue* q) {
    if (isEmpty(q)) {
        throw std::underflow_error("Queue is empty: no front element");
    }
    return *(q->front);
}

int back(const Queue* q) {
    if (isEmpty(q)) {
        throw std::underflow_error("Queue is empty: no back element");
    }
    return *(q->rear);
}