/*Q145: Return a structure containing top student's details from a function.

/*
Sample Test Cases:
Input 1:
3 students: Riya 101 89, Karan 102 96, Meena 103 92
Output 1:
Top Student: Karan | Roll: 102 | Marks: 96

*/
#include <stdio.h>
#include <string.h>


struct Student {
    char name[50];
    int roll;
    int marks;
};

struct Student getTopStudent(struct Student arr[], int n) {
    struct Student top = arr[0];  
    for (int i = 1; i < n; i++) {
        if (arr[i].marks > top.marks) {
            top = arr[i];
        }
    }
    return top;  
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    
    for (int i = 0; i < n; i++) {
        printf("Enter name, roll, marks for student %d: ", i + 1);
        scanf("%s %d %d", students[i].name, &students[i].roll, &students[i].marks);
    }

  
    struct Student topper = getTopStudent(students, n);

    printf("Top Student: %s | Roll: %d | Marks: %d\n", topper.name, topper.roll, topper.marks);

    return 0;
}
