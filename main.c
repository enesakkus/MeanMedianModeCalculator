#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int numberGenerator(void);
void mean(int response[], size_t size);
void median(int response[], size_t size);
void mode(int response[], size_t size, int frequency[]);
void printArray(int response[], size_t size);
void bubbleSort(int response[], size_t size);
int frequency[9] = {0};

//Main function of program
int main(void){

    size_t i; //counter
    size_t size; //size of response[] array

    srand(time(NULL)); // Feed for rand() function to create different values for different runs.

    printf("Welcome to Mean-Mode-Median Calculator...\n"
           "This program calculates Mean-Mode-Median of responses which is between 0-9.\n"
           "Numbers generated randomly by the program\n\n"
           "Please enter how many numbers do you want to generate by program (Only Odd numbers): ");

    scanf("%u", &size); // Taking number from user for size value
    int response[size]; // Defining response[] array which has size of "size" (variable-length array)


    for(i = 0; i < size; i++){
        response[i] = numberGenerator(); /* Initializing response array by random numbers
                                          * between 0-9 which created by numberGenerator function
                                          */
    }//end for

    mean(response, size); //Function to calculate mean value of response elements
    median(response, size); //Function to calculate median value of response elements
    mode(response, size, frequency); //Function to calculate mode value and its frequency of response elements

}

void mean(int response[], size_t size){

    size_t i; //Counter
    int total = 0; //variable to hold sum of response elements

    for(i = 0; i < size; i++){
        total += response[i];
    }//end for

    printf("\n%s\n%s\n%s\n",
           "**********", "Mean", "**********");

    printf("The mean is average value of the data\n"
           "items. The mean is equal to the total of\n"
           "all the data items divided by the number\n"
           "of data items (%u). The mean value for\n"
           "this run is: %d / %u = %.4f", size, total, size, (double)total / size);
}

//Sort array and determine median element's value
void median(int response[], size_t size){

    printf("\n\n%s\n%s\n%s\n%s",
           "**********", "Median", "**********",
           "The unsorted array of responses is: ");

    printArray(response, size); //output unsorted array
    puts("");
    bubbleSort(response, size); //sort array

    printf("The sorted array of responses is: ");
    printArray(response, size); // output sorted array

    //display most frequent response
    printf("\n\nThe median is element %u of\n"
           "the sorted %u element array.\n"
           "For this run the median is %d\n\n",
           (size/2) + 1, size, response[size/2]);
}

//Determine most frequent response
void mode(int response[], size_t size, int frequency[]){

    size_t i; //Counter
    int largest = 0; //variable for biggest frequency value of elements
    int modeValue; //variable for most frequent response

    printf("\n\n%s\n%s\n%s\n",
           "**********", "Mode", "**********");
    //Summarize frequencies
    for(i = 0; i < size; i++){
        ++frequency[response[i]];
    } //end for

    //Output Answer, Frequency and Histogram chart
    printf("%s%11s%19s\n", "Answer", "Frequency", "Histogram");

    for(i = 0; i <= 9; i++){

        printf("%3d%7d\t\t\t", i, frequency[i]);
        int z = 1; //Counter
        while(z <= frequency[i]){
            printf("%s", "*");
            z++;
        } //end while

        if(frequency[i] > largest){
            largest = frequency[i];
            modeValue = i;
        } //end if
        puts("");
    } //end for


    //Display the mode value
    printf("\n\nThe mode is the most frequent value.\n"
           "For this run the mode is %u which occured"
           " %u times.\n", modeValue, largest);

} //end function mode

void printArray(int response[], size_t size){

    size_t i; //Counter

    for(i = 0; i < size; i++){
        if((i % 20) == 0){
            puts("");
        } //end if
        printf("%2d", response[i]);
    } //end for
} //end function printArray

//Function that sorts an array with bubble sort algorithm
void bubbleSort(int response[], size_t size){

    int pass;
    size_t i;
    int hold;

    for(pass = 0; pass < size; pass++){
        for(i = 0; i < size - 1; i++){
            if(response[i] > response[i+1]){
                hold = response[i];
                response[i] = response[i+1];
                response[i+1] = hold;
            } //end if
        } //end inner for
    } //end outer for
} //end function bubbleSort

//Function for random number generator
int numberGenerator(void){

    int number;

    number = 0 + (rand() % 10);
    return number;
} //end function numberGenerator
