#include <stdio.h>
#include <string.h>

int idx = 0, pos = 0, length, top = -1;
char sym, temp, infix[20], postfix[20], stack[20];

void push(char symbol)
{
    if (top == 19)
        printf("Stack overflow\n");
    else
        stack[++top] = symbol;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return '\0';
    }
    else
        return stack[top--];
}

int pred(char symbol)
{
    switch (symbol)
    {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        case '(': return -1;
        default: return 0;
    }
}

void infixpostfix()
{
    length = strlen(infix);
    push('(');
    infix[length++] = ')';
    infix[length] = '\0';

    while (idx < length)
    {
        sym = infix[idx];

        switch (sym)
        {
            case '(':
                push(sym);
                break;

            case ')':
                temp = pop();
                while (temp != '(')
                {
                    postfix[pos++] = temp;
                    temp = pop();
                }
                break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (pred(sym) <= pred(stack[top]))
                {
                    postfix[pos++] = pop();
                }
                push(sym);
                break;

            default:
                postfix[pos++] = sym;
        }
        idx++;
    }
    postfix[pos] = '\0';
}

int main()
{
    printf("Enter the infix exp: ");
    scanf("%s", infix);

    infixpostfix();

    printf("Postfix exp = %s\n", postfix);
    return 0;
}

