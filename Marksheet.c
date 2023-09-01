#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

int i, j, option, error, check = 0;
char name[50], repeat;
int sj[15], n, marks[10], total;
float percent;

//More courses can be added 
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

int main(){

    while(1){

        system("cls");
        error = 0;
        title();
        printf("\n\t\t\t\t\t\t     1. Create Gradebook\n");
        printf("\n\n\t\t\t\t\t\t     2. Exit\n");
        printf("\n\t\t\t\t\t\t\tChoose your option:  ");
        scanf("%d", &option);
    
        switch (option){
        case 1:

            do{

                studentDetails();
                subjectDetails();
                marksDetails();
                calculation();
                Display();
                printf("\n\n\t\t\t\t\t\tDo you want to continue? (Y/N)  \n");
                scanf("%s", &repeat);
                repeat = toupper(repeat);

                if(repeat == 'N') exit(0);

            }while(repeat == 'Y');

            studentDetails();
            break;

        case 2:

            exit(0);
            break;

        default:

            printf("\n\n\t\t\t\t\t\tError: Please select a valid option (1 or 2).\n");
            printf("\n\n\t\t\t\t\t\t");
            system("pause");
            system("cls");
        }
    }

    return 0;
}

void marksDetails(){

    total = 0;
    system("cls");
    title();
    printf("\n\n\t\t\t\t\t\t-------------Enter Mark Details------------\n");
    printf("\n\n\t\t\t\t\t\tEnter Marks : ");

    for(i = 0; i < n; i++){

        int temp = sj[i];
        printf("\n\n\t\t\t\t\t\t%d. %s : ", i + 1, subjects[temp]);
        scanf("%d", &marks[i]);

        if(marks[i] < 50){
            check = 1;
        }
    }

    printf("\n\n\t\t\t\t\t\t    Calculating.......");
    sleep(2);
}

void calculation() {

    total = 0;
    for (i = 0; i < n; i++) {
        
        total += marks[i];
    }

    int maxMarks = 100 * n;
    percent = (total * 100.0) / maxMarks;

    if (percent < 50.0) {
        check = 1; // Failed
    } else {
        check = 0; // Passed
    }
}


void Display(){
    
    system("cls");
    title();
    printf("\n\n\t\t\t\t\t\t------------- Results ------------\n");
    printf("\n\t\t\t\t\t\tName : %s", name);
    printf("\n\t\t\t\t\t\t=============================================");
    printf("\n\t\t\t\t\t\tSubjects\t\t\tMarks");
    printf("\n\t\t\t\t\t\t=============================================");

    for(i = 0; i < n; i++){

        int temp = sj[i];
        printf("\n\t\t\t\t\t\t%s\t\t\t%d", subjects[temp], marks[i]);

        if(marks[i] < 35){
            check = 1;
        }
    }

    printf("\n\t\t\t\t\t\t--------------------------------------------------");
    printf("\n\t\t\t\t\t\tTotal\t\t\t%d", total);

    if(check == 1){

         printf("\n\t\t\t\t\t\tResult\t\t\tFAIL");
         check = 0;
    }
    else {

        printf("\n\t\t\t\t\t\tResult\t\t\tPASS");
        check = 0;
    }

    percentage(percent);
    printf("  %0.0f%%", percent);

    if(percent >= 80){

        printf("\n\t\t\t\t\t\tContratulations %s, you scored %0.0f%%", name, percent);
    }
    else if(percent >= 60 && percent < 80){
        
        printf("\n\t\t\t\t\t\tGood job %s, you scored %0.0f%%", name, percent);
    }
    else if(percent >= 50 && percent < 60){

        printf("\n\t\t\t\t\t\t%s, you scored %0.0f%%", name, percent);
    }
    else if(percent < 50){

        printf("\n\t\t\t\t\t\tDont worry %s, try again next time.", name);
        printf("\n\t\t\t\t\t\tYour score is %0.0f%%", percent);
        total = 0;
    }
}

void subjectDetails(){

    do{

        error = 0;
        system("cls");

        title();
        printf("\n\n\t\t\t\t\t\t-------------Enter Subject Details------------\n");

        printf("\n\t\t\t\t\t\tEnter the number of subjects : ");
        scanf("%d", &n);
        printf("\n\t\t\t\t\t\t--------------------------------------------------");
        printf("\n\n\t\t\t\t\t\tSubjects: ");
        printf("\n\t\t\t\t\t\t\t");

        for(i = 0; i <= LENGTH - 1; i++){

            printf("%2d. %-6s", i, subjects[i]);
            if(i == 5 || i == 9 || i == LENGTH - 1){

                printf("\n\t\t\t\t\t\t\t");
            }
        }
        printf("\n\t\t\t\t\t\t--------------------------------------------------");
        printf("\n\n\t\t\t\t\t\tChoose Subjects: ");
        
        for(i = 0; i < n; i++) {

            scanf("%d", &sj[i]);

            if(sj[i] > LENGTH) {

                printf("\n\t\t\t\t\t\t\tError : %dth subject does not exist\n", sj[i]);
                error = 1;
                break;
            }

            for(j = 0; j < i; j++) {

                if(sj[i] == sj[j]) {

                    printf("\n\t\t\t\t\t\t\tError: You picked the same subject multiple times.\n");
                    error = 1;
                    break;
                }
            }
        }

        printf("\n\t\t\t\t\t\t\t");
        system("pause");

        if(error == 0){
            break;
        }

    } while (error == 1);
}

void title(){

    printf("\n\t\t\t\t\t\t=============================================");
    printf("\n\t\t\t\t\t\t               STUDENT GRADEBOOK PROGRAM");
    printf("\n\t\t\t\t\t\t=============================================");
}

void percentage(float percent){

    printf("\n\n\t\t\t\t\t\t");

    for(int k = 0; k < percent; k++){

        if((k % 2) == 0){

            printf("#");
            usleep(19000);
        }
    }
}   

void studentDetails(){

    system("cls");

    title();
    printf("\n\n\t\t\t\t\t\t-------------Enter Student Details------------\n");

    printf("\n\t\t\t\t\t\tName : ");
    scanf("%s", &name);
}