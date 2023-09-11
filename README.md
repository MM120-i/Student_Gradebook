# Student Gradebook

**Project Description: Canadian Grade 12 High School Gradebook**

The Student Management System is designed to assist Canadian high school guidance counselors and teachers in managing grade 12 students' academic records. It provides a user-friendly interface to input and track student information, course details, and grades. The system is primarily intended for use by grade 12 students and can be used by teachers to manage their students' academic progress.

**Key Features:**

1) Student Information Management: The system allows counselors and teachers to input and manage student details, including their names.

2) Course Details: It provides comprehensive information about various grade 12 courses, including course codes, descriptions, types (e.g., University Preparation, College Preparation), and prerequisites.

3) Grade Entry: Users can enter student grades for multiple subjects relevant to their grade 12 curriculum.

4) Grade Calculation: The system calculates the total marks obtained by the student and their overall percentage based on the entered grades.

5) Grade Classification: It classifies students' performance as Pass or Fail and provides a visual progress indicator during percentage calculation.

6) Gradebook Creation: Users can create a gradebook to keep track of individual student records.

7) View and Delete Student Records: The system allows users to view student records and delete them if necessary.

Usage:

1) Create Gradebook: Users can create a new gradebook, enter student details, select subjects, input grades, and calculate the student's overall percentage.

2) Course Details: Provides comprehensive information about available grade 12 courses, helping students and teachers choose appropriate courses.

3) View Student Records: Counselors and teachers can access and review student records, making it easier to monitor academic progress.

4) Delete Student Records: Users can delete specific student records when necessary.

**Technologies Used:**

- **Programming Language**: C
- **User Interface**: Command-line interface (CLI)
- **Data Storage**: Arrays and variables for data storage and processing

**How to Use:**

- The user selects the "Create Gradebook" option to begin.
- They enter their personal details, including name, GPA, and grade.
- They select the number of subjects they want to enter grades for.
- The user enters the course codes for their chosen subjects and the corresponding marks.
- The system calculates the overall percentage and provides feedback on their performance.
- The user can choose to continue entering grades or exit the program.

**Screenshots:**

![image](https://github.com/MM120-i/Student_Gradebook/assets/80307451/7c7fdd15-07f3-44af-a067-44f1a5975c87)

![image](https://github.com/MM120-i/Student_Gradebook/assets/80307451/d1510c13-1faf-4ada-b5c0-c43e1ea8cf13)

![image](https://github.com/MM120-i/Student_Gradebook/assets/80307451/708de85f-cbf1-4b2d-8260-98ea4001750f)

![image](https://github.com/MM120-i/Student_Gradebook/assets/80307451/b807746f-63b3-4280-867a-ef64bbb77022)




Note: Ensure that the necessary dependencies and system requirements are met before running the provided source code. This project simplifies the process of tracking grade 12 student records, making it a valuable tool for guidance counselors and teachers in Canadian high schools.



**Changelog / Updates:**

**September 02, 2023:**
  - Fixed a warning that occurred during compilation.
  - Resolved an issue where the application would incorrectly output 'FAIL' even if the final average is over 50%.
  - Improved code readability by adding more comments for readers.

**September 03, 2023:**
  - Removed redundant '#include' statements.

**September 05, 2023:**

*New Feature*: 
 - Course Details Viewing: Users can now access and view detailed information about available courses, including the course description and prerequisites/corequisites.

*Bug Fix*:
- Compilation Warning Fix: Resolved a compilation warning that occurred due to the use of the sleep function without a proper declaration.

**September 10, 2023**:

*New Feature*:
- Search Student Records: Added the ability to search for student records by name.
- Data Security: Implemented secure storage of student data in a file.
- View Gradebook: Enabled users to easily view the contents of the gradebook.
- Delete Student Records: Added functionality to delete student records.
