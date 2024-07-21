#include <stdio.h>
#define MAX 100
int stack[MAX], top = -1, n;
void push(void);
void pop(void);
void display(void);
int main() {
 int choice;
 printf("\n Enter the size of STACK[MAX=100]: ");
 scanf("%d", &n);
 // Ensure the stack size is within the allowable range
 if (n <= 0 || n > MAX) {
 printf("Invalid stack size. Please enter a value between 1 and 100.\n");
 return 1;
 }
 printf("\n\t STACK OPERATIONS USING ARRAY");
 printf("\n\t--------------------------------");
 printf("\n\t 1. PUSH\n\t 2. POP\n\t 3. DISPLAY\n\t 4. EXIT");
 do {
 printf("\n Enter the Choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 push();
 break;
 case 2:
 pop();
 break;
 case 3:
 display();
 break;
 case 4:
 printf("\n\t EXIT POINT\n");
 break;
 default:
 printf("\n\t Please Enter a Valid Choice (1/2/3/4)\n");
 break;
 }
 } while (choice != 4);
 return 0;
}
void push() {
 int x;
 if (top >= n - 1) {
 printf("\n\t STACK is overflow\n");
 } else {
 printf(" Enter a value to be pushed: ");
 scanf("%d", &x);
 stack[++top] = x;
 printf("\n\t Value pushed: %d\n", x);
 }
}
void pop() {
 if (top <= -1) {
 printf("\n\t Stack is underflow\n");
 } else {
 printf("\n\t The popped element is %d\n", stack[top--]);
 }
}
void display() {
 if (top >= 0) {
 printf("\n The elements in STACK are:\n");
 for (int i = top; i >= 0; i--) {
 printf("%d\n", stack[i]);
 }
 printf("\n Press Next Choice\n");
 } else {
 printf("\n The STACK is empty\n");
 }
}
