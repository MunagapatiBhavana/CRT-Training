## 📘 README: Expression Evaluation Using Stacks (Infix, Postfix, Prefix)

## 🔍 What Are Expressions?

An expression is a combination of operands (numbers) and operators (+, -, *, /) that evaluates to a value.

Example:

(3 + 4) * 5 - 6  →  result: 29

## 🧾 Types of Expressions

| Notation    | Example | Description                               |
| ----------- | ------- | ----------------------------------------- |
| **Infix**   | `A + B` | Operators are written between operands    |
| **Postfix** | `A B +` | Operators are written **after** operands  |
| **Prefix**  | `+ A B` | Operators are written **before** operands |

## 📦 Why Use Stacks?
Stacks are Last In First Out (LIFO) structures perfect for handling:

Operator precedence

Parenthesis matching

Order of evaluation

## 📐 Evaluation Algorithms

### 🔸 Infix to Postfix
Steps:

Initialize an empty stack for operators.

Scan the infix expression:

If operand, add to output.

If (, push to stack.

If ), pop till (.

If operator, pop higher precedence ones and push current.

Pop all remaining operators.


### 🔹 Postfix Evaluation
Steps:

Initialize empty operand stack.

Scan from left:

If operand, push.

If operator, pop two operands, evaluate, push result.

Final result will be at top of the stack.

### 🔹 Prefix Evaluation
Steps:

Scan from right to left.

If operand, push.

If operator, pop two operands, evaluate, push result.

Final result is at top.

## ⏱ Time Complexity
| Expression Type    | Time Complexity |
| ------------------ | --------------- |
| Infix to Postfix   | O(n)            |
| Postfix Evaluation | O(n)            |
| Prefix Evaluation  | O(n)            |

## postfix
int evaluatePostfix(char* expr) {

    for (int i = 0; expr[i]; i++) {
        char ch = expr[i];

        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            int val2 = pop();
            int val1 = pop();
            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop();
}

## prefix 
int evaluatePrefix(char* expr) {

    int len = strlen(expr);
    for (int i = len - 1; i >= 0; i--) {
        char ch = expr[i];
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            int op1 = pop();
            int op2 = pop();
            switch (ch) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
    }
    return pop();
}

| Operation        | Stack Usage                        | Complexity |
| ---------------- | ---------------------------------- | ---------- |
| Infix to Postfix | Used for operators and parentheses | O(n)       |
| Postfix Eval     | Stack for operands                 | O(n)       |
| Prefix Eval      | Stack for operands                 | O(n)       |
