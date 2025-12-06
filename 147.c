/*Q147: Store employee data in a binary file using fwrite() and read using fread().

/*
Sample Test Cases:
Input 1:
Employee details entered and stored in file.
Output 1:
Displays employee data read from file.

*/
#include <stdio.h>
#include <stdlib.h>

// Define Employee structure
struct Employee {
    char name[50];
    int id;
    int day, month, year; // Joining date
};

int main() {
    struct Employee emp, empRead;
    FILE *fp;

    // Input employee details
    printf("Enter employee name: ");
    scanf("%s", emp.name);

    printf("Enter employee ID: ");
    scanf("%d", &emp.id);

    printf("Enter joining date (dd mm yyyy): ");
    scanf("%d %d %d", &emp.day, &emp.month, &emp.year);

    
    fp = fopen("employee.dat", "wb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    
    fwrite(&emp, sizeof(struct Employee), 1, fp);
    fclose(fp);

    
    fp = fopen("employee.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    
    fread(&empRead, sizeof(struct Employee), 1, fp);
    fclose(fp);

    
    printf("\nEmployee details read from file:\n");
    printf("Name: %s | ID: %d | Joining Date: %02d/%02d/%04d\n",
           empRead.name, empRead.id,
           empRead.day, empRead.month, empRead.year);

    return 0;
}
