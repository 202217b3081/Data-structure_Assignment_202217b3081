#include<stdio.h>
//#include<conio.h> // Not required for standard functionality
#define MAX 10
// Function prototypes
void create();
void insert();
void deletion();
void search();
void display();
int b[MAX], n, pos, e, i; // Global variables
int main() {
 //clrscr(); // Not required for standard functionality
 int ch;
 char g='y';
 
 do {
 printf("\n Main Menu");
 printf("\n 1. Create \n 2. Delete \n 3. Search \n 4. Insert \n 5. Display\n 6. Exit \n");
 printf("\n Enter your Choice: ");
 scanf("%d", &ch);
 switch(ch) {
 case 1:
 create();
 break;
 case 2:
 deletion();
 break;
 case 3:
 search();
 break;
 case 4:
 insert();
 break;
 case 5:
 display();
 break;
 case 6:
 return 0; // Proper way to exit the program
 default:
 printf(" \n Enter the correct choice:");
 }
 
 printf("\n Do you want to continue? (y/n): ");
 scanf(" %c", &g);
 } while(g == 'y' || g == 'Y');
 
 //getch(); // Not required for standard functionality
 return 0;
}
void create() {
 printf("\n Enter the number of elements: ");
 scanf("%d", &n);
 
 for(i = 0; i < n; i++) {
 printf(" Enter element %d: ", i + 1);
 scanf("%d", &b[i]); 
 }
}
void deletion() {
 printf("\n Enter the position to delete: ");
 scanf("%d", &pos);
 
 if(pos >= n || pos < 0) {
 printf("\n Invalid Location!");
 } else {
 for(i = pos; i < n - 1; i++) {
 b[i] = b[i + 1];
 }
 n--;
 
 printf("\n Elements after deletion:");
 display();
 }
}
void search() {
 printf("\n Enter the element to be searched: ");
 scanf("%d", &e);
 
 for(i = 0; i < n; i++) {
 if(b[i] == e) {
 printf(" Value %d is found at position %d", e, i);
 return; // Exit the function after finding the first occurrence
 }
 }
 
 printf(" Value %d is not found in the list.", e);
}
void insert() {
 printf("\n Enter the position to insert: ");
 scanf("%d", &pos);
 
 if(pos < 0 || pos > n) {
 printf("\n Invalid Location!");
 return;
 }
 
 printf("\n Enter the element to insert: ");
 scanf("%d", &b[pos]);
 
 n++;
 
 printf("\n List after insertion:");
 display();
}
void display() {
 printf("\n Elements in the list:");
 for(i = 0; i < n; i++) {
 printf(" %d", b[i]);
 }
 printf("\n");
}