#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NINF INT_MIN

struct Stack
{
    int top;
    int capacity;
    int *array;
};

struct Stack *create_stack(int capacity)
{
    struct Stack *st = malloc(sizeof(struct Stack));

    st->capacity = capacity;
    st->top = -1;
    st->array = malloc(st->capacity * sizeof(int));

    return st;
}

int size(struct Stack *st)
{
    return st->top + 1;
}

int is_empty(struct Stack *st)
{
    return size(st) == 0;
}

int is_full(struct Stack *st)
{
    return size(st) == st->capacity - 1;
}

void push(struct Stack *st, int data)
{
    if (is_full(st))
    {
        printf("Stack is Already Full!, cannot insert\n");
    }
    else
    {
        st->array[++st->top] = data;
    }
}

int pop(struct Stack *st)
{
    if (is_empty(st))
    {
        printf("Stack is Already Empty!, cannot remove\n");
        return NINF;
    }
    else
    {
        return st->array[st->top--];
    }
}

int give_top(struct Stack *st)
{
    if (is_empty(st))
    {
        printf("Stack is Empty!\n");
        return NINF;
    }
    else
    {
        return st->array[st->top];
    }
}

void delete_stack(struct Stack *st)
{
    free(st->array);
    free(st);
}

void display_stack(struct Stack *st)
{
    if (is_empty(st))
    {
        printf("Stack is Empty\n");
        return;
    }
    else
    {
        printf("Stack : ");
    }
    for (int i = 0; i <= st->top; i++)
    {
        if (i == st->top)
        {
            printf("%d (TOP)\n", st->array[i]);
            continue;
        }
        printf("%d ", st->array[i]);
    }
}

int main()
{
    int capacity = 20;
    struct Stack *stk = create_stack(capacity);

    push(stk, 10);
    push(stk, 20);
    push(stk, 30);

    display_stack(stk);

    if (give_top(stk) != NINF)
    {
        printf("Top element : %d\n", give_top(stk));
    }

    printf("Popped Element : %d\n", pop(stk));
    display_stack(stk);

    delete_stack(stk);
}
