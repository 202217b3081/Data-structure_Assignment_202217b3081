#include <stdio.h>
int main() {
 int n, a[10], b[10], t[10], w[10], g[10], i;
 float att = 0, awt = 0;
 // Initialize arrays
 for(i = 0; i < 10; i++) {
 a[i] = 0; 
 b[i] = 0; 
 w[i] = 0; 
 g[i] = 0;
 }
 // Input number of processes
 printf("Enter the number of processes: ");
 scanf("%d", &n);
 // Input burst times
 printf("Enter the burst times: ");
 for(i = 0; i < n; i++) {
 scanf("%d", &b[i]);
 }
 // Input arrival times
 printf("Enter the arrival times: ");
 for(i = 0; i < n; i++) {
 scanf("%d", &a[i]);
 }
 // Calculate the completion times (g)
 g[0] = a[0] + b[0]; // The completion time of the first process
 for(i = 1; i < n; i++) {
 if(a[i] > g[i - 1]) {
 g[i] = a[i] + b[i]; // Process starts after it arrives
 } else {
 g[i] = g[i - 1] + b[i]; // Process starts immediately after the previous one finishes
 }
 }
 // Calculate waiting times (w) and turnaround times (t)
 for(i = 0; i < n; i++) {
 t[i] = g[i] - a[i]; // Turnaround time
 w[i] = t[i] - b[i]; // Waiting time
 awt += w[i];
 att += t[i];
 }
 // Calculate averages
 awt /= n;
 att /= n;
 // Print process details
 printf("\n\tProcess\tWaiting Time\tTurnaround Time\n");
 for(i = 0; i < n; i++) {
 printf("\tp%d\t\t%d\t\t%d\n", i, w[i], t[i]);
 }
 // Print average waiting and turnaround times
 printf("The average waiting time is %.2f\n", awt);
 printf("The average turnaround time is %.2f\n", att);
 return 0;
}