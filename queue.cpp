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
    return q->rear == q->data + MAX - 1;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        throw std::overflow_error("Queue overflow: queue is full");
    }
    q->rear++;
    *(q->rear) = value;
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        throw std::underflow_error("Queue underflow: queue is empty");
    }
    q->front++;
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
