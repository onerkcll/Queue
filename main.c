#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
struct queue_element
{
    int val;
    struct queue_element *left;
    struct queue_element *right;
};

struct queue
{
    struct queue_element *first;
};

void init_queue_element(struct queue_element *element, int value)
{
    element->val = value;
    element->left = NULL;
    element->right = NULL;
}
void init_queue(struct queue *queue, struct queue_element *element)
{
    queue->first = element;
}

void enqueue(struct queue_element *standing, struct queue_element *element)
{
    if (standing->right != NULL)
    {
        element->right = standing->right;
    }
    standing->right = element;
}

struct queue_element *dequeue(struct queue *queue)
{
    struct queue_element *front = queue->first;
    if (front)
    {
        queue->first = front->right;
    }

    return front;
}
struct queue queue;

int main(int argc, char **argv)
{
    struct queue_element head;
    init_queue_element(&head, 30);

    init_queue(&queue, &head);

    struct queue_element chloe;
    init_queue_element(&chloe, 97);
    enqueue(&head, &chloe);

    struct queue_element jack;
    init_queue_element(&jack, 27);
    enqueue(&chloe, &jack);
    
    struct queue_element *current = dequeue(&queue);
    printf("Number : %i\n", current->val);
    current = dequeue(&queue);
    printf("Number : %i\n", current->val);
    current = dequeue(&queue);
    printf("Number : %i\n", current->val);

    return 0;
}