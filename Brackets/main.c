#include <stdio.h>
#include <stdlib.h>

typedef enum bracket
{
    BRACKET_NORMAL,   // ()
    BRACKET_COMPOSED, // {}
    BRACKET_SQUARE,   // []
} Bracket;

typedef struct stack_item
{
    Bracket value;
    struct stack_item *next;
} StackItem;

typedef struct stack
{
    StackItem *head;
} Stack;

StackItem *push(Stack *stack, Bracket value)
{
    StackItem *new = malloc(sizeof(StackItem));
    if (new == NULL)
    {
        exit(EXIT_FAILURE);
    }

    new->next = stack->head;
    new->value = value;
    stack->head = new;
}

StackItem *pop(Stack *stack)
{
    StackItem *popped = stack->head;
    stack->head = stack->head->next;

    return popped;
}

int main(int argc, char *argv[])
{
    Stack stack = {
        .head = NULL,
    };

    char c;

    while ((c = getc(stdin)) != EOF)
    {
        switch (c)
        {
        case '(':
            push(&stack, BRACKET_NORMAL);
            break;
        case '[':
            push(&stack, BRACKET_SQUARE);
            break;
        case '{':
            push(&stack, BRACKET_COMPOSED);
            break;
        case ')':
        {
            StackItem *popped = pop(&stack);
            if (popped->value != BRACKET_NORMAL)
            {
                printf("Not ) bracket, failing...");
                return EXIT_FAILURE;
            }
        }
        break;
        case ']':
        {
            StackItem *popped = pop(&stack);
            if (popped->value != BRACKET_SQUARE)
            {
                printf("Not ] bracket, failing...");
                return EXIT_FAILURE;
            }
        }
        break;
        case '}':
        {
            StackItem *popped = pop(&stack);
            if (popped->value != BRACKET_COMPOSED)
            {
                printf("Not } bracket, failing...");
                return EXIT_FAILURE;
            }
        }
        break;
        }
    }

    printf("All okey.");

    return EXIT_SUCCESS;
}
