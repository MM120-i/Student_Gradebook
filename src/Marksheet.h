#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

extern int i, j, option, error, check;
extern char name[50], repeat;
extern int sj[15], n, marks[10], total;
extern float percent;

// More courses can be added
extern const char *subjects[15];
extern struct Course
{
    const char *code;
    const char *description;
    const char *type;
    const char *prerequisite;
};
extern struct Course courses[15];

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

#endif
