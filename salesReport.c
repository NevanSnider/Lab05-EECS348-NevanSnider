//Nevan Snider, KUID 3149896
//Lab05, Sales Report Lab


#include<stdio.h>

#define MAX_LINES 12

int main(void)
{
    //Makes all the initial declarations
    FILE *outputFile;
    FILE *inputFile;
    char inputFileName[20];
    float nums[MAX_LINES] = {0};
    float sixMonthAverages[6];
    float number;
    int i;
    int j;
    int sortedIndexes[MAX_LINES];
    const char *months[] = {
        "January", 
        "February", 
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"};
    
    //asks user for input
    printf("Enter the input file name\n");
    scanf("%s", inputFileName);

    //opens input and output files
    inputFile = fopen(inputFileName, "r");
    outputFile = fopen("outputFile.txt", "w");

    //Scans each line and puts it in the nums array
    for (i = 0; i < MAX_LINES; i++){
        if (fscanf(inputFile, "%f", &number) != 1){
            break;
        }
        nums[i] = number;
    }
    float storedNum = nums[0];

    //Prints all the months with their related value
    fprintf(outputFile, "Monthly Sales Report for 2024\n");
    fprintf(outputFile, "\nMonth\t\tSales\n");
    for (i = 0; i < MAX_LINES; i++){
        fprintf(outputFile, "%-12s\t%.2f\n", months[i], nums[i]);
    }

    fprintf(outputFile, "\nSales Summary Report\n");

    //Finds the smallest value
    int smallestNumberIndex = 0;
    float smallestNumber = nums[0];
    for (i = 0; i < MAX_LINES; i++){
        if (nums[i] < smallestNumber){
            smallestNumber = nums[i];
            smallestNumberIndex = i;
        }
    }

    //Finds the greatest value
    int greatestNumberIndex = 0;
    float greatestNumber = nums[0];
    for (i = 0; i < MAX_LINES; i++){
        if (nums[i] > greatestNumber){
            greatestNumber = nums[i];
            greatestNumberIndex = i;
        }
    }

    //finds the average sales
    float averageSales = 0;
    for (i = 0; i < MAX_LINES; i++){
        averageSales += nums[i];
    }
    averageSales = averageSales/MAX_LINES;

    //prints all the data so far
    fprintf(outputFile, "Minimum Sales:\t%.2f  (%s)\n", smallestNumber, months[smallestNumberIndex]);
    fprintf(outputFile, "Maximum Sales:\t%.2f  (%s)\n", greatestNumber, months[greatestNumberIndex]);
    fprintf(outputFile, "Average Sales:\t%.2f\n", averageSales);


    fprintf(outputFile, "\nSix-Month moving average report:\n");

    //finds the six month averages for each
    for (i = 0; i < 6; i++){
        averageSales = 0;
        for (j = i; j < (i+6); j++){
            averageSales += nums[j];
        }
        averageSales = averageSales/6;
        sixMonthAverages[i] = averageSales;
    }

    averageSales = 0;
    for (j = 6; j < 12; j++){
        averageSales += nums[j];
    }
    averageSales = averageSales/6;
    sixMonthAverages[6] = averageSales;

    //prints the averages
    fprintf(outputFile, "January-June\t%.2f\n", sixMonthAverages[0]);
    fprintf(outputFile, "February-July\t%.2f\n", sixMonthAverages[1]);
    fprintf(outputFile, "March-August\t%.2f\n", sixMonthAverages[2]);
    fprintf(outputFile, "April-September\t%.2f\n", sixMonthAverages[3]);
    fprintf(outputFile, "May-October\t%.2f\n", sixMonthAverages[4]);
    fprintf(outputFile, "June-November\t%.2f\n", sixMonthAverages[5]);
    fprintf(outputFile, "July-December\t%.2f\n", sixMonthAverages[6]);


    //Uses a list of indexes and sorts them to corresnpond with the associated value
    for (i = 0; i < MAX_LINES; i++){
        sortedIndexes[i] = i;
    }

    nums[0] = storedNum;

    //Sorts the indexes from highest to lowest 
    fprintf(outputFile, "\nSales report (highest to lowest)\n");
    for (i = 0; i < MAX_LINES; i++){
        for (j = i+1; j < MAX_LINES; j++){
            if (nums[sortedIndexes[i]] < nums[sortedIndexes[j]]){
                int swapVal = sortedIndexes[i];
                sortedIndexes[i] = sortedIndexes[j];
                sortedIndexes[j] = swapVal;
            }
        }
    }


    //prints the sales report
    fprintf(outputFile, "Month\t\tSales\n");
    for (i = 0; i < MAX_LINES; i++){
        fprintf(outputFile, "%-12s\t%.2f\n", months[sortedIndexes[i]], nums[sortedIndexes[i]]);
    }

    fclose(inputFile);
    fclose(outputFile);

    //when running the program in a command prompt window it would
    //close instantly before I could read anything and so I
    //added this exit so that the window stays open until a key is pressed
    printf("Press enter to exit"); 
    getchar();
    getchar();

    return 0;

}