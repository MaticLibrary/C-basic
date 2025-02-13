#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX_EXPR 256
#define MAX_STACK 100

typedef struct { double vals[MAX_STACK]; int top; } NumStack;
typedef struct { char ops[MAX_STACK]; int top; } OpStack;

void initNumStack(NumStack *s) { s->top = -1; }
void initOpStack(OpStack *s) { s->top = -1; }
int isNumStackEmpty(NumStack *s) { return s->top == -1; }
int isOpStackEmpty(OpStack *s) { return s->top == -1; }
void pushNum(NumStack *s, double val) { if (s->top < MAX_STACK - 1) s->vals[++(s->top)] = val; else exit(1); }
void pushOp(OpStack *s, char op) { if (s->top < MAX_STACK - 1) s->ops[++(s->top)] = op; else exit(1); }
double popNum(NumStack *s) { return isNumStackEmpty(s) ? exit(1), 0 : s->vals[(s->top)--]; }
char popOp(OpStack *s) { return isOpStackEmpty(s) ? exit(1), 0 : s->ops[(s->top)--]; }
char peekOp(OpStack *s) { return s->ops[s->top]; }
int precedence(char op) { return (op == '+' || op == '-') ? 1 : (op == '*' || op == '/') ? 2 : (op == '^') ? 3 : 0; }
double applyOp(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return b == 0 ? exit(1), 0 : a / b;
    case '^': return pow(a, b);
    default: exit(1);
    }
}

double evaluate(char *expr) {
    NumStack nums; OpStack ops;
    initNumStack(&nums); initOpStack(&ops);
    int i = 0;
    while (expr[i]) {
        if (expr[i] == ' ') { i++; continue; }
        if (isdigit(expr[i]) || expr[i] == '.') {
            char numBuf[MAX_EXPR]; int j = 0;
            while (isdigit(expr[i]) || expr[i] == '.') numBuf[j++] = expr[i++];
            numBuf[j] = '\0';
            pushNum(&nums, atof(numBuf));
            continue;
        }
        if (expr[i] == '(') pushOp(&ops, expr[i]);
        else if (expr[i] == ')') {
            while (!isOpStackEmpty(&ops) && peekOp(&ops) != '(')
                pushNum(&nums, applyOp(popNum(&nums), popNum(&nums), popOp(&ops)));
            if (!isOpStackEmpty(&ops) && peekOp(&ops) == '(') popOp(&ops);
            else exit(1);
        } else {
            while (!isOpStackEmpty(&ops) && precedence(peekOp(&ops)) >= precedence(expr[i]))
                pushNum(&nums, applyOp(popNum(&nums), popNum(&nums), popOp(&ops)));
            pushOp(&ops, expr[i]);
        }
        i++;
    }
    while (!isOpStackEmpty(&ops))
        pushNum(&nums, applyOp(popNum(&nums), popNum(&nums), popOp(&ops)));
    return popNum(&nums);
}
int main() {
    char expr[MAX_EXPR];
    printf("Enter expression: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = 0;
    printf("Result: %.5f\n", evaluate(expr));
    return 0;
}
