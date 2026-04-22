#include "queue.h"
#include <stdexcept>

void init(Queue* q) {
    q->front = q->data;
    q->rear  = q->data; 
}

bool isEmpty(const Queue* q) {
    return q->front == q->rear;
}

bool isFull(const Queue* q) {
    const int* next_rear = q->data + ((q->rear - q->data + 1) % MAX);
    return next_rear == q->front;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        throw std::overflow_error("Queue overflow: queue is full");
    }
    *(q->rear) = value;
    q->rear = q->data + ((q->rear - q->data + 1) % MAX);
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        throw std::underflow_error("Queue underflow: queue is empty");
    }
    q->front = q->data + ((q->front - q->data + 1) % MAX);
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
    int prev_index = (q->rear - q->data - 1 + MAX) % MAX;
    return *(q->data + prev_index);
}