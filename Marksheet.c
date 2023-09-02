#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int i, j, option, error, check = 0;
char name[50], repeat;
int sj[15], n, marks[10], total;
float percent;

// More courses can be added
const char *subjects[15] = {
    "ENG4U", "MHF4U", "MDM4U", "MCV4U", "TEJ4M",   
    "SCH4U", "SPH4U", "SBI4U", "HSB4U", "BAT4M", 
    "BBB4M", "BOH4M", "FSF4U", "ICS4U", "MAP4C"
}; // Course codes

#define LENGTH sizeof(subjects) / sizeof(subjects[0])

void title();
void studentDetails();
void subjectDetails();
void marksDetails();
void calculation();
void percentage(float percent);
void Display();

int main() {

    while (1) {

        system("cls");  // Clear the console screen
        error = 0;      // Initialize error variable
        title();        // Display program title
        printf("\n\t\t\t\t\t\t     1. Create Gradebook\n");
        printf("\n\n\t\t\t\t\t\t     2. Exit\n");
        printf("\n\t\t\t\t\t\t\tChoose your option:  ");
        scanf("%d", &option);  // Read user's choice

        switch (option) {

        case 1:

            do {

                studentDetails();   // Get student information
                subjectDetails();   // Get subject information
                marksDetails();     // Get marks details
                calculation();      // Calculate grades
                Display();          // Display the gradebook
                printf("\n\n\t\t\t\t\t\tDo you want to continue? (Y/N)  \n");
                scanf(" %c", &repeat);  // Ask if the user wants to continue
                repeat = toupper(repeat); // Convert the input to uppercase

                if (repeat == 'N') exit(0);  // Exit the program if 'N' is entered

            } while (repeat == 'Y');

            studentDetails();   // Get student information one more time
            break;

        case 2:

            exit(0);  // Exit the program
            break;

        default:

            printf("\n\n\t\t\t\t\t\tError: Please select a valid option (1 or 2).\n");
            printf("\n\n\t\t\t\t\t\t");
            system("pause");  // Pause the program to let the user see the error message
            system("cls");    // Clear the console screen
        }
    }

    return 0;
}

void marksDetails() {

    total = 0;                 // Initialize the total marks
    system("cls");             // Clear the console screen
    title();                   // Display program title
    printf("\n\n\t\t\t\t\t\t-------------Details--------------\n");
    printf("\n\n\t\t\t\t\t\tEnter Marks : ");

    for (i = 0; i < n; i++) {  // Iterate through each subject

        int temp = sj[i];      // Get the index of the subject from the subject array
        printf("\n\n\t\t\t\t\t\t%d. %s : ", i + 1, subjects[temp]);  // Prompt for marks of a subject
        scanf("%d", &marks[i]);  // Read marks from the user

        if (marks[i] < 50) {     // Check if the marks are less than 50

            check = 1;           // Set the 'check' variable to 1 to indicate low marks
        }
    }

    printf("\n\n\t\t\t\t\t\t    Calculating.......");  // Inform the user that calculations are in progress
    sleep(2);  // Sleep for 2 seconds (assuming 'sleep' is defined elsewhere) for a brief pause
}


void calculation() {

    total = 0;                    // Initialize the total marks to zero
    for (i = 0; i < n; i++) {     // Iterate through each subject
    
        total += marks[i];        // Sum up the marks for all subjects
    }

    int maxMarks = 100 * n;       // Calculate the maximum possible marks for all subjects
    percent = (total * 100.0) / maxMarks;  // Calculate the percentage obtained
}


void Display() {

    system("cls");                               // Clear the console screen
    title();                                      // Display program title
    printf("\n\n\t\t\t\t\t\t------------- Results ------------\n");
    printf("\n\t\t\t\t\t\tName : %s", name);     // Display the student's name
    printf("\n\t\t\t\t\t\t=============================================");
    printf("\n\t\t\t\t\t\tSubjects\t\tMarks");
    printf("\n\t\t\t\t\t\t=============================================");

    for (i = 0; i < n; i++) {

        int temp = sj[i];
        printf("\n\t\t\t\t\t\t%-10s\t\t%d", subjects[temp], marks[i]);  // Display subject names and marks

        if (marks[i] < 35) {

            check = 1;                              // If any subject's marks are less than 35, set 'check' to 1
        }
    }

    printf("\n\t\t\t\t\t\t---------------------------------------------");
    printf("\n\t\t\t\t\t\tTotal\t\t\t%d", total);      // Display the total marks

    printf("\n\t\t\t\t\t\tResult\t\t\t");

    if (percent < 50.0) {

        printf("FAIL");  // Display "FAIL" if the percentage is less than 50.0
    } 
    else {

        printf("PASS");  // Display "PASS" if the percentage is greater than or equal to 50.0
    }

    percentage(percent);
    printf("  %0.0f%%", percent);

    if (percent >= 80) {

        printf("\n\t\t\t\t\t\tCongratulations %s, you scored %0.0f%%", name, percent);
    } 
    else if (percent >= 60 && percent < 80) {

        printf("\n\t\t\t\t\t\tGood job %s, you scored %0.0f%%", name, percent);
    } 
    else if (percent >= 50 && percent < 60) {

        printf("\n\t\t\t\t\t\t%s, you scored %0.0f%%", name, percent);
    }
    else if (percent < 50) {

        printf("\n\t\t\t\t\t\tDon't worry %s, try again next time.", name);
        printf("\n\t\t\t\t\t\tYour score is %0.0f%%", percent);
        total = 0;
    }
}


void subjectDetails() {

    do {

        error = 0;                // Initialize the error variable
        system("cls");            // Clear the console screen
        title();                  // Display program title
        printf("\n\n\t\t\t\t\t\t-------------Enter Subject Details-----------\n");
        printf("\n\t\t\t\t\t\tEnter the number of subjects : ");
        scanf("%d", &n);          // Read the number of subjects from the user
        printf("\n\t\t\t\t\t\t----------------------------------------------");
        printf("\n\n\t\t\t\t\t\tSubjects: ");
        printf("\n\t\t\t\t\t\t");

        for (i = 0; i <= LENGTH - 1; i++) {  // Display a list of available subjects
        
            printf("%2d. %-6s", i, subjects[i]);
            if (i == 5 || i == 9 || i == LENGTH - 1) {

                printf("\n\t\t\t\t\t\t");
            }
        }
        printf("\n\t\t\t\t\t\t----------------------------------------------");
        printf("\n\n\t\t\t\t\t\tChoose Subjects: ");

        for (i = 0; i < n; i++) {  // Read the selected subjects from the user

            scanf("%d", &sj[i]);

            if (sj[i] >= LENGTH) {  // Check if the selected subject index is valid

                printf("\n\t\t\t\t\t\tError : %dth subject does not exist\n", sj[i]);
                error = 1;  // Set the error flag to 1
                break;
            }

            for (j = 0; j < i; j++) {  // Check if the same subject is selected multiple times

                if (sj[i] == sj[j]) {

                    printf("\n\t\t\t\t\t\tError: You picked the same subject multiple times.\n");
                    error = 1;  // Set the error flag to 1
                    break;
                }
            }
        }

        printf("\n\t\t\t\t\t\t");
        system("pause");  // Pause the program to let the user see any error messages

        if (error == 0) {  // If there are no errors, exit the loop

            break;
        }

    } while (error == 1);  // Repeat the process if there are errors
}

void title() {

    printf("\n\t\t\t\t\t\t=============================================");
    printf("\n\t\t\t\t\t\t         STUDENT GRADEBOOK PROGRAM");
    printf("\n\t\t\t\t\t\t=============================================");
}

void percentage(float percent) {

    printf("\n\n\t\t\t\t\t\t");  // Display a new line and indentation

    // Convert the sleep time from milliseconds to a timespec structure
    struct timespec delay;
    delay.tv_sec = 0;
    delay.tv_nsec = 19000000; // 19,000,000 nanoseconds (equivalent to 19 milliseconds)

    for (int k = 0; k < percent; k++) {  // Loop through each percentage point

        if ((k % 2) == 0) {  // Check if the current percentage is even

            printf("#");     // Display a '#' character to visualize progress
            nanosleep(&delay, NULL); // Use nanosleep to pause for the specified duration
        }
    }
}

void studentDetails() {

    system("cls");                     // Clear the console screen
    title();                           // Display program title
    printf("\n\n\t\t\t\t\t\t-------------Enter Student Details-----------\n");
    printf("\n\t\t\t\t\t\tName : ");
    scanf("%s", name);                 // Read and store the student's name
}

