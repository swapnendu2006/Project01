#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct Order {
    int id;
    char name[50];
    char item[50];
    int quantity;
};

int rear = 0, front = 0, count = 0;
int next_id = 101;

struct Order queue[MAX];

void addorder() {
    if (count == MAX) {
        printf("Order queue is full!\n");
        return;
    }
    struct Order newOrder;
    newOrder.id = next_id;
    
      printf("Enter Customer Name: ");
      scanf(" %[^\n]", newOrder.name); 
    
    printf("Enter Item Ordered: ");
    scanf(" %[^\n]", newOrder.item);
    
    printf("Enter Quantity: ");
    if (scanf("%d", &newOrder.quantity) != 1) {
        printf("Invalid quantity! Order cancelled.\n");
        while(getchar() != '\n'); 
        return;
    }
    queue[rear] = newOrder;
    printf("\n Order %d added successfully for %s!\n", newOrder.id, newOrder.name);
    
    rear = (rear + 1) % MAX;
    count++;
    next_id++;
}

void serveorder() {
    if (count == 0) {
        printf("No pending orders!\n");
        return;
    }
    printf("\n Order %d (%d x %s) for %s is now SERVED.\n", 
           queue[front].id, queue[front].quantity, queue[front].item, queue[front].name);
           
    front = (front + 1) % MAX;
    count--;
}

void display() {
    if (count == 0) {
        printf("No pending orders!\n");
        return;
    }
    printf("\n======================================================\n");
    printf("                  PENDING ORDERS                        \n");
    printf("======================================================\n");
    printf("ID\t | Customer\t\t | Item\t\t | Qty\t");
    printf("\n------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        int index = (front + i) % MAX;
        printf("#%d\t | %s\t\t\t | %s\t\t | %d\t\t\n", 
               queue[index].id, 
               queue[index].name, 
               queue[index].item, 
               queue[index].quantity);
    }
    printf("\n======================================================\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n---- XYZ Restaurant ----\n");
        printf("1. Add Order.\n2. Serve Order.\n3. Display Orders.\n4. Exit.\n");
        printf("Choose an option: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid Input!!!\n");
            while(getchar() != '\n'); 
            continue; 
        }
        
        switch (choice) {
            case 1: addorder();
                    break;
            case 2: serveorder();
                    break;
            case 3: display();
                    break;
            case 4: printf("Exiting system. Goodbye!\n");
                    exit(0);
            default: printf("Please choose a number between 1 and 4.\n");                      
        }
    }
    return 0;
}
