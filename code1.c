#include <stdio.h>

char userInput[21];
FILE *fptr;
float sales[12];
const char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void getInput() {
    printf("Please enter filename and extension (EX: input.txt; max length 20, no spaces): ");
    scanf("%20s", userInput); // get input file name, limit to 20 chars
    fptr = fopen(userInput, "r");
    for (int i = 0; i < 12; i++) { // read each line and save data into sales array
        fscanf(fptr, "%f", &sales[i]);
    }
    fclose(fptr);
    
}

void salesReport() {
    printf("Monthly Sales Report for 2024\n");
    printf("Month             Sales\n");
    for (int i = 0; i < 12; i++) {
        printf("%-15s %10.2f\n", months[i], sales[i]);
    }
}

int main() {
    getInput();
    salesReport();
    return 0;
}