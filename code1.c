#include <stdio.h>

float sales[12];
const char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void getInput() {
    char userInput[21];
    FILE *fptr;
    printf("Please enter filename and extension (EX: input.txt; max length 20, no spaces): ");
    scanf("%20s", userInput); // get input file name, limit to 20 chars
    fptr = fopen(userInput, "r");
    for (int i = 0; i < 12; i++) { // read each line and save data into sales array
        fscanf(fptr, "%f", &sales[i]);
    }
    fclose(fptr);
}

void salesReport() {
    printf("\nMonthly Sales Report for 2024\n\n");
    printf("Month Sales\n");
    for (int i = 0; i < 12; i++) {
        printf("%s %.2f\n", months[i], sales[i]); // print with formatting and 2 point precision
    }
}

void summaryReport() {
    float min = sales[0]; // find minimum sales
    char min_month = 0;
    float max = sales[0]; // find minimum sales
    char max_month = 0;
    float average = sales[0]; // find average sales
    for (int i = 1; i < 12; i++) {
        if (sales[i] > max) {
            max = sales[i];
            max_month = i;
        }
        if (sales[i] < min) {
            min = sales[i];
            min_month = i;
        }
        average += sales[i];
    }
    average /= 12;

    printf("\nSales summary report:\n\n");
    printf("Minimum sales: %.2f (%s)\n", min, months[min_month]);
    printf("Maximum sales: %.2f (%s)\n", max, months[max_month]);
    printf("Average sales: %.2f\n", average);
}

void movingReport() {
    float moving_average[7] = {0}; // find average for each 6 month span
    for (int i = 0; i <= 6; i++) {
        for (int j = i; j < i+6; j++) {
            moving_average[i] += sales[j];
        }
        moving_average[i] /= 6;
    }
    
    printf("\nSix-Month moving average report:\n\n");
    for (int i = 0; i < 7; i++) {
        printf("%s-%s %.2f\n", months[i], months[i+5], moving_average[i]); // print with formatting and 2 point precision
    }
}

void highToLow() {
    float sales_copy[12]; // copy sales
    for (int i = 0; i < 12; i++) {
        sales_copy[i] = sales[i];
    } // find max month and print
    for (int i = 0; i < 12; i++) {
        float max = -1;
        int max_month = -1;
        for (int j = 0; j < 12; j++) {
            if (sales_copy[j] > max) {
                max = sales_copy[j];
                max_month = j;
            }
        } // reset
        if (max_month != -1) {
            printf("%s $%.2f\n", months[max_month], max);
            sales_copy[max_month] = 0;
        }
    }
}

int main() {
    getInput();
    salesReport();
    summaryReport();
    movingReport();
    highToLow();
    return 0;
}