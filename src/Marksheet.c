#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "Marksheet.h"

int i, j, option, error, check = 0;
char name[50], repeat;
int sj[15], n, marks[10], total;
float percent;

// More courses can be added
const char *subjects[15] = {
    "ENG4U", "MHF4U", "MDM4U", "MCV4U", "TGJ4M",
    "SCH4U", "SPH4U", "SBI4U", "HSB4U", "BAT4M",
    "BBB4M", "BOH4M", "FSF4U", "ICS4U", "MAP4C"}; // Course codes

struct Course
{

    const char *code;
    const char *description;
    const char *type;
    const char *prerequisite;
};

// More courses can be added.
struct Course courses[15] = {

    {"ENG4U : Grade 12 English",
     "This course emphasizes the consolidation of literacy, communication, and critical and creative thinking skills necessary for success in academic and daily life.",
     "University Preparation",
     "Prerequisite: ENG3U, Grade 11 English or NBE3U"},
    {"MHF4U : Grade 12 Advanced Functions",
     "MHF4U extends students’ experience with functions. Students will investigate the properties of polynomial, rational, logarithmic, and trigonometric functions.",
     "University Preparation",
     "Prerequisite: MCR3U, Grade 11 Functions or MCT4C, Grade 12 Mathematics for College Technology"},
    {"MDM4U: Grade 12 Mathematics of Data Management",
     "This course broadens students’ understanding of mathematics as it relates to managing data. Students will apply methods for organizing and analysing large amounts of information.",
     "University Preparation",
     "Prerequisite: MCR3U, Grade 11 Functions or MCF3M, Grade 11 Functions and Applications"},
    {"MCV4U : Grade 12 Calculus and Vectors",
     "This course builds on students’ previous experience with functions and their developing understanding of rates of change. Students will solve problems involving geometric and algebraic representations of vectors and representations of lines and planes in three dimensional space.",
     "University Preparationrsity",
     "Prerequisite: Proof of completion or enrollment is MHF4U. Co-requisite: MHF4U, Grade 12 Advanced Functions"},
    {"TGJ4M : Grade 12 Communications Technology",
     "This course enables students to further develop media knowledge and skills while designing and producing projects in the areas of live, recorded, and graphic communications.",
     "University/College Preparation",
     "Prerequisite: TGJ3M, Grade 11 Communications Technology"},
    {
        "SCH4U : Grade 12 Chemistry",
        "This course allows students to deepen their understanding of chemistry through the study of organic chemistry, energy changes and rates of reaction, chemical systems and equilibrium, electrochemistry, and atomic and molecular structure.",
        "University Preparation",
        "Prerequisite: SCH3U, Grade 11 Chemistry",
    },
    {"SPH4U : Grade 12 Physics",
     "This course enables students to deepen their understanding of physics concepts and theories.",
     "University Preparation",
     "Prerequisite: SPH3U, Grade 11 Physics"},
    {"SBI4U : Grade 12 Biology",
     "This course provides students with the opportunity for in-depth study of the concepts and processes associated with biological systems.",
     "University Preparation",
     "Prerequisite: SBI3U, Grade 11 Biology"},
    {"HSB4U : Grade 12 Challenge and Change in Society",
     "This course focuses on the use of social science theories, perspectives, and methodologies to investigate and explain shifts in knowledge, attitudes, beliefs, and behaviour and their impact on society.",
     "University Preparation",
     "Prerequisite: Any Grade 11 or 12 university (U) or university/college (M) preparation course in Social Sciences and Humanities, English, or Canadian and World Studies."},
    {"BAT4M : Grade 12 Financial Accounting Principles",
     "This course introduces students to advanced accounting principles that will prepare them for post-secondary studies in business.",
     "University/College Preparation",
     "Prerequisite: BAF3M, Grade 11 Financial Accounting Fundamentals"},
    {"BBB4M : Grade 12 International Business Fundamentals",
     "This course provides an overview of the importance of international business and trade in the global economy and explores the factors that influence success in international markets.",
     "University/College Preparation",
     "Prerequisite: None"},
    {"BOH4M : Grade 12 Business Leadership",
     "This course focuses on developing the leadership skills used in managing a successful business.",
     "University/College Preparation",
     "Prerequisite: None"},
    {"FSF4U : Grade 12 Core French",
     "This course provides extensive opportunities for students to speak and interact in French independently. Students will develop their listening, speaking, reading, and writing skills.",
     "University Preparation",
     "Prerequisite: FSF3U, Grade 11 Core French"},
    {"ICS4U : Grade 12 Computer Science",
     "This course enables students to further develop knowledge and skills in computer science. Students will use modular design principles to create complex and fully documented programs, according to industry standards.",
     "University Preparation",
     "Prerequisite: ICS3U, Grade 11 Computer Science"},
    {"MAP4C : Grade 12 Foundations for College Mathematics",
     "This course focuses on real-world applications of mathematics. It seeks to prepare students for college programs in areas such as business, health sciences, and human services, and for certain skilled trades.",
     "College Preparation",
     "Prerequisite: MBF3C, Grade 11 Foundations for College Mathematics or MCF3M, Grade 11 Functions and Applications,MCR3U, Grade 11 Functions"}};

#define LENGTH sizeof(subjects) / sizeof(subjects[0])

void title();
void studentDetails();
void subjectDetails();
void marksDetails();
void calculation();
void percentage(float percent);
void Display();
void courseDetails();
void searchStudentGrade(const char *filename, const char *searchName);
void writeStudentDataToFile(FILE *fp);
void viewGradebookContents(const char *filename);
void deleteStudentRecord(const char *filename);

int main()
{

    FILE *fp;
    char filename[] = "gradebook.txt";

    while (1)
    {

        system("cls"); // Clear the console screen
        error = 0;     // Initialize error variable
        title();       // Display program title
        printf("\n\t\t\t\t\t\t     1. Create Gradebook\n");
        printf("\n\n\t\t\t\t\t\t     2. Course Details\n");
        printf("\n\n\t\t\t\t\t\t     3. View Student Records\n");
        printf("\n\n\t\t\t\t\t\t     4. Delete Student Record\n");
        printf("\n\n\t\t\t\t\t\t     5. Exit\n");
        printf("\n\t\t\t\t\t\t\tChoose your option:  ");
        scanf("%d", &option); // Read user's choice

        switch (option)
        {

        case 1:

            do
            {

                studentDetails(); // Get student information
                subjectDetails(); // Get subject information
                marksDetails();   // Get marks details
                calculation();    // Calculate grades
                Display();        // Display the gradebook

                fp = fopen(filename, "a");

                if (fp == NULL)
                {

                    printf("\n\n\t\t\t\t\t\tError: Unable to open file %s for writing.\n", filename);
                    exit(1);
                }

                writeStudentDataToFile(fp);
                fclose(fp);

                printf("\n\n\t\t\t\t\t\tDo you want to continue? (Y/N)  \n");
                scanf(" %c", &repeat);    // Ask if the user wants to continue
                repeat = toupper(repeat); // Convert the input to uppercase

                if (repeat == 'N')
                    exit(0); // Exit the program if 'N' is entered

            } while (repeat != 'Y');

            studentDetails(); // Get student information one more time
            break;

        case 2:

            do
            {

                courseDetails();
                printf("\n\n\t\t\t\t\t\tDo you want to exit this page? (Y)  \n");
                scanf(" %c", &repeat);
                repeat = toupper(repeat);

            } while (repeat != 'Y');

            break;

        case 3:

            do
            {

                viewGradebookContents(filename);
                scanf(" %c", &repeat);
                repeat = toupper(repeat);

            } while (repeat != 'Y');

            break;

        case 4:

            deleteStudentRecord(filename);
            break;

        case 5:

            exit(0); // Exit the program
            break;

        default:

            printf("\n\n\t\t\t\t\t\tError: Please select a valid option (1 or 2).\n");
            printf("\n\n\t\t\t\t\t\t");
            system("pause"); // Pause the program to let the user see the error message
            system("cls");   // Clear the console screen
        }
    }

    return 0;
}

void deleteStudentRecord(const char *filename)
{
    char studentNameToDelete[50];
    printf("\n\t\t\t\t\t\tEnter the name of the student to delete: ");
    scanf("%s", studentNameToDelete);

    FILE *inputFile = fopen(filename, "r");
    if (inputFile == NULL)
    {
        perror("Error opening file");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL)
    {
        perror("Error creating temporary file");
        fclose(inputFile);
        return;
    }

    char line[1000];
    int deleted = 0;

    printf("\n\t\t\t\t\t\tList of students matching '%s':\n", studentNameToDelete);

    while (fgets(line, sizeof(line), inputFile))
    {
        if (strstr(line, studentNameToDelete) != NULL)
        {
            // Display the matching student's record
            printf("\n%s", line);

            // Ask the user if they want to delete this student's record
            char confirmation;
            printf("\n\t\t\t\t\t\tDelete this student's record? (Y/N): ");
            scanf(" %c", &confirmation);
            confirmation = toupper(confirmation);

            if (confirmation != 'Y')
            {
                fputs(line, tempFile); // Keep the student's record
            }
            else
            {
                deleted = 1; // Student record found and deleted
            }
        }
        else
        {
            // Keep the line if it doesn't contain the student name to delete
            fputs(line, tempFile);
        }
    }

    fclose(inputFile);
    fclose(tempFile);

    if (!deleted)
    {
        printf("\n\t\t\t\t\t\tStudent '%s' not found in the gradebook.\n", studentNameToDelete);
    }
    else
    {
        if (remove(filename) != 0)
        {
            perror("Error deleting original file");
        }
        if (rename("temp.txt", filename) != 0)
        {
            perror("Error renaming temporary file");
        }
        printf("\n\t\t\t\t\t\tStudent '%s' deleted successfully.\n", studentNameToDelete);
    }
}

void viewGradebookContents(const char *filename)
{

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {

        perror("Error opening file");
        return;
    }

    char line[1000];
    while (fgets(line, sizeof(line), fp))
    {
        printf("%s", line);
    }
    scanf("%d");

    fclose(fp);

    printf("\n\n\t\t\t\t\t\tDo you want to exit this page? (Y)  \n");
}

void writeStudentDataToFile(FILE *fp)
{

    FILE *file = fopen("gradebook.txt", "a"); // Open the file in append mode

    if (file == NULL)
    {

        perror("Error opening file");
        return;
    }

    // Write student name to the file
    fprintf(file, "Name: %s\n", name);

    // Write subjects and corresponding marks to the file
    fprintf(file, "Subjects: ");

    for (int i = 0; i < n; i++)
    {

        int temp = sj[i];
        fprintf(file, "%s:%d  ", subjects[temp], marks[i]);
    }
    fprintf(file, "\n");

    fclose(file); // Close the file when done
}

void searchStudentGradeInFile(const char *filename, const char *searchName)
{

    FILE *file = fopen(filename, "r"); // Open the file in read mode

    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    char line[1000];
    int studentFound = 0;

    // Read each line in the file
    while (fgets(line, sizeof(line), file))
    {
        // Check if the line contains the student's name
        if (strstr(line, searchName) != NULL)
        {
            studentFound = 1;
            break;
        }
    }

    fclose(file); // Close the file when done

    if (studentFound)
    {
        // Display the student's data (you can extract and format it as needed)
        printf("Student Found: %s", line);
    }
    else
    {
        printf("Student not found\n");
    }
}

void courseDetails()
{

    // Calculate the number of courses in the 'courses' array
    int length = sizeof(courses) / sizeof(courses[0]);

    // Loop through each course and display its details
    for (int i = 0; i < length; i++)
    {

        // Display the course code and description
        printf("\n\n%s: %s", courses[i].code, courses[i].description);
        // Display the course type
        printf("\nCourses Type: %s", courses[i].type);
        // Display the course prerequisite
        printf("\n%s\n", courses[i].prerequisite);
    }
}

void marksDetails()
{

    total = 0;     // Initialize the total marks
    system("cls"); // Clear the console screen
    title();       // Display program title
    printf("\n\n\t\t\t\t\t\t-------------Details--------------\n");
    printf("\n\n\t\t\t\t\t\tEnter Marks : ");

    for (i = 0; i < n; i++)
    { // Iterate through each subject

        int temp = sj[i];                                           // Get the index of the subject from the subject array
        printf("\n\n\t\t\t\t\t\t%d. %s : ", i + 1, subjects[temp]); // Prompt for marks of a subject
        scanf("%d", &marks[i]);                                     // Read marks from the user

        if (marks[i] < 50)
        { // Check if the marks are less than 50

            check = 1; // Set the 'check' variable to 1 to indicate low marks
        }
    }

    printf("\n\n\t\t\t\t\t\t    Calculating......."); // Inform the user that calculations are in progress
    sleep(2);                                         // Sleep for 2 seconds (assuming 'sleep' is defined elsewhere) for a brief pause
}

void calculation()
{

    total = 0; // Initialize the total marks to zero
    for (i = 0; i < n; i++)
    { // Iterate through each subject

        total += marks[i]; // Sum up the marks for all subjects
    }

    int maxMarks = 100 * n;               // Calculate the maximum possible marks for all subjects
    percent = (total * 100.0) / maxMarks; // Calculate the percentage obtained
}

void Display()
{

    system("cls"); // Clear the console screen
    title();       // Display program title
    printf("\n\n\t\t\t\t\t\t------------- Results ------------\n");
    printf("\n\t\t\t\t\t\tName : %s", name); // Display the student's name
    printf("\n\t\t\t\t\t\t=============================================");
    printf("\n\t\t\t\t\t\tSubjects\t\tMarks");
    printf("\n\t\t\t\t\t\t=============================================");

    for (i = 0; i < n; i++)
    {

        int temp = sj[i];
        printf("\n\t\t\t\t\t\t%-10s\t\t%d", subjects[temp], marks[i]); // Display subject names and marks

        if (marks[i] < 35)
        {

            check = 1; // If any subject's marks are less than 35, set 'check' to 1
        }
    }

    printf("\n\t\t\t\t\t\t---------------------------------------------");
    printf("\n\t\t\t\t\t\tTotal\t\t\t%d", total); // Display the total marks

    printf("\n\t\t\t\t\t\tResult\t\t\t");

    if (percent < 50.0)
    {

        printf("FAIL"); // Display "FAIL" if the percentage is less than 50.0
    }
    else
    {

        printf("PASS"); // Display "PASS" if the percentage is greater than or equal to 50.0
    }

    percentage(percent);
    printf("  %0.0f%%", percent);

    if (percent >= 80)
    {

        printf("\n\t\t\t\t\t\tCongratulations %s, you scored %0.0f%%", name, percent);
    }
    else if (percent >= 60 && percent < 80)
    {

        printf("\n\t\t\t\t\t\tGood job %s, you scored %0.0f%%", name, percent);
    }
    else if (percent >= 50 && percent < 60)
    {

        printf("\n\t\t\t\t\t\t%s, you scored %0.0f%%", name, percent);
    }
    else if (percent < 50)
    {

        printf("\n\t\t\t\t\t\tDon't worry %s, try again next time.", name);
        printf("\n\t\t\t\t\t\tYour score is %0.0f%%", percent);
        total = 0;
    }
}

void subjectDetails()
{

    do
    {

        error = 0;     // Initialize the error variable
        system("cls"); // Clear the console screen
        title();       // Display program title
        printf("\n\n\t\t\t\t\t\t-------------Enter Subject Details-----------\n");
        printf("\n\t\t\t\t\t\tEnter the number of subjects : ");
        scanf("%d", &n); // Read the number of subjects from the user
        printf("\n\t\t\t\t\t\t----------------------------------------------");
        printf("\n\n\t\t\t\t\t\tSubjects: ");
        printf("\n\t\t\t\t\t\t");

        for (i = 0; i <= LENGTH - 1; i++)
        { // Display a list of available subjects

            printf("%2d. %-6s", i, subjects[i]);
            if (i == 5 || i == 9 || i == LENGTH - 1)
            {

                printf("\n\t\t\t\t\t\t");
            }
        }
        printf("\n\t\t\t\t\t\t----------------------------------------------");
        printf("\n\n\t\t\t\t\t\tChoose Subjects: ");

        for (i = 0; i < n; i++)
        { // Read the selected subjects from the user

            scanf("%d", &sj[i]);

            if (sj[i] >= LENGTH)
            { // Check if the selected subject index is valid

                printf("\n\t\t\t\t\t\tError : %dth subject does not exist\n", sj[i]);
                error = 1; // Set the error flag to 1
                break;
            }

            for (j = 0; j < i; j++)
            { // Check if the same subject is selected multiple times

                if (sj[i] == sj[j])
                {

                    printf("\n\t\t\t\t\t\tError: You picked the same subject multiple times.\n");
                    error = 1; // Set the error flag to 1
                    break;
                }
            }
        }

        printf("\n\t\t\t\t\t\t");
        system("pause"); // Pause the program to let the user see any error messages

        if (error == 0)
        { // If there are no errors, exit the loop

            break;
        }

    } while (error == 1); // Repeat the process if there are errors
}

void title()
{

    printf("\n\t\t\t\t\t\t=============================================");
    printf("\n\t\t\t\t\t\t         STUDENT GRADEBOOK PROGRAM");
    printf("\n\t\t\t\t\t\t=============================================");
}

void percentage(float percent)
{

    printf("\n\n\t\t\t\t\t\t"); // Display a new line and indentation

    // Convert the sleep time from milliseconds to a timespec structure
    struct timespec delay;
    delay.tv_sec = 0;
    delay.tv_nsec = 19000000; // 19,000,000 nanoseconds (equivalent to 19 milliseconds)

    for (int k = 0; k < percent; k++)
    { // Loop through each percentage point

        if ((k % 2) == 0)
        { // Check if the current percentage is even

            printf("#");             // Display a '#' character to visualize progress
            nanosleep(&delay, NULL); // Use nanosleep to pause for the specified duration
        }
    }
}

void studentDetails()
{

    system("cls"); // Clear the console screen
    title();       // Display program title
    printf("\n\n\t\t\t\t\t\t-------------Enter Student Details-----------\n");
    printf("\n\t\t\t\t\t\tName : ");
    scanf("%s", name); // Read and store the student's name
}
