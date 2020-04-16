////////////////////////////////////////////////////////////////////////////////
//
//  File           : p2-support.c
//  Description    : This is the support file with all the supporting methods to execute sorting, displaying, deleting, and searching.
//                   Any command used by the user calls a method on this file to be executed.
//
//   Author        : Jayanth Lankalapalli 
//   Last Modified : 4/1/20

//Include Files
#include <stdio.h>
#include "p2-support.h"
#include <string.h>

/* Function: This method displays all the information of the Employee such as their location in the databse, id, first name, last name, email, and salary
    Parameters: The two parameter it takes is the location in the emp array and the Employee struct
    The method also displays the Employee details in the proper format making it easy to read by the user.
*/
void displayEmployee(struct Employee temp, int location){ 
        printf("%-3d ", location);
        printf("%-5s ", temp.id);
        printf("%-10s ", temp.firstName);
        printf("%-10s ", temp.lastName);
        printf("%-20s ", temp.email);
        printf("$%10.2f\n", temp.salary);
}

/* Function: This method sorts all the Employees based on their ID to give an organized database. 
    The method uses the selection sort algorithm to sort the Employees by using a nested for loop.
    Parameters: It takes in the database db

*/
void sortWithID(struct DataBase *db){
int i;
int j;

  for(i = 0; i<(db->total)-1; i++){ // nested for loop
      for(j = i+1; j<db->total; j++){
          struct Employee temp1 = db->emp[i];
          struct Employee temp2 = db->emp[j];
          if(strcmp(temp1.id,temp2.id) > 0){   // compares the id string in both Employee structs and if they return a number > 0 then swap the locations of the values in the db->emp
              db->emp[i] = temp2;
              db->emp[j] = temp1;
          }
      }
  }
}

/* Function: This method finds the Employee coressponding to their ID. It then displays that employee.
Parameters: The parameters are the id and the databse db
*/
void searchWithID(char *id, struct DataBase *db){
        struct Employee temp;
    int i;
    int location;
    printf("No. EmpID Employee Name        Email                Salary    \n");
    printf("--- ----- -------------------- -------------------- ------------\n");

    for(i = 0; i<db->total;i++){
        if(strcmp(db->emp[i].id, id) == 0){ // compares the given id to the id in the database to see if they match
            temp = db->emp[i];
            location = i;
        }
    }


    if(strcmp(temp.id, id) == 0){
       
        displayEmployee(temp, location); // if they match then it displays
    }

    else{
        printf("\nThere is no Employee with ID: %s\n\n"); // if there is no match then display that there is none
    }

    
    
}
/* Function: This method finds the employee information based on their last name
    Parameter: The parameters are the given lastName and the Database
*/

void searchWithLastName(char *lastName, struct DataBase *db){
    struct Employee temp;
    int i;
    int found;
    printf("No. EmpID Employee Name        Email                Salary    \n");
    printf("--- ----- -------------------- -------------------- ------------\n");
    for(i = 0; i<db->total;i++){
        if(strcmp(db->emp[i].lastName, lastName) == 0){ // checks if the given last name and the last name in the databse match
            temp = db->emp[i];
            displayEmployee(temp, i); // if it matches then display the employee's information
            found = 1;
        }
    }
        
    

    if(found == 0){ // if no match then display there is no match for that entered last name
        printf("\nThere is no Employee with Last Name: %s\n\n");
    }

}
/* Function: Deletes the employee with the corresponding ID from the databse
    Parameters: The parameters are the given ID and the Databse
*/

void deleteWithID(char *id, struct DataBase *db){
      int found = 0;
    int i;
    printf("No. EmpID Employee Name        Email                Salary    \n");
    printf("--- ----- -------------------- -------------------- ------------\n");
    for(i = 0; i<db->total; i++){ // loops through each employee int the database
        struct Employee temp = db->emp[i];
        if(strcmp(id,temp.id ) == 0 || found ==1){ 
            if (found == 0)
            {
               
                found = 1;
                displayEmployee(temp,i);
                db->total = db->total - 1;
                struct Employee temptemp = db->emp[i+1]; //after finding it it moves the employee from the next to replace the deleted
                db->emp[i] = temptemp;
                
            }
            else{
                struct Employee temptemp = db->emp[i+1]; // continues to move the array entries back one
                db->emp[i] = temptemp;
            }
            
        }
    }

    if(found == 0){
        printf("\nNot found in DataBase\n"); // if not found display that it is not found
    }
    
}

/* Function: This method removes the employee with the corresponding last name then moves all the remaining entries up one in location
    Parameter: The parameters are the entered last name from user and the Database
*/

void deleteWithLastName(char *lastName, struct DataBase *db){
      int found = 0;
    int i;
    printf("No. EmpID Employee Name        Email                Salary    \n");
    printf("--- ----- -------------------- -------------------- ------------\n");
    for(i = 0; i<db->total; i++){ // loops through the databse to find the first employee with the last name and deletes it from the database
        struct Employee temp = db->emp[i];
        if(strcmp(lastName,temp.lastName ) == 0 || found ==1){ // compares to to find the name or just to move all the array entries to the left 1 if the employee is already found and deleted
            if (found == 0)
            {
                
                found = 1;
                displayEmployee(temp,i);
                db->total = db->total - 1;
                struct Employee temptemp = db->emp[i+1];
                db->emp[i] = temptemp;
                
            }
            else{
                struct Employee temptemp = db->emp[i+1];
                db->emp[i] = temptemp;
            }
            
        }
    }

    if(found == 0){ // if not found then it displays not found
        printf("\nNot found in DataBase\n");
    }
}
/* Function: The method frees all the allocated memory so there are no memory leaks. Only does this before terminating the program
    Parameter: The parameter is the database that will get freed
*/
void exitProgram(struct DataBase *db){


    free(db->emp); // to free the emp array
    free(db); // to free the database struct

}

/* Function: The function displays all the employees in the database.
    Parameter: The parameter is the database given
*/

void displayAll(struct DataBase *db){
    int i;
       printf("No. EmpID Employee Name        Email                Salary    \n"); //What to print formatted 
    printf("--- ----- -------------------- -------------------- ------------\n");
    for(i = 0; i<db->total; i++ ){ // loop to print out every employee's information
        displayEmployee(db->emp[i],i); //displaying each employee at a time
        
    }
    printf("\n\n");
    
}

/* Function: The fucntion creates an Employee struct entry to put into the database
    Parameter: The parameters are the information of the employee such as id, first name, last name, email, salary, and database
*/
void createRecord(char *id, char *firstName, char *lastName, char *email, double salary, struct DataBase *db) 
{
  
    struct Employee temp; // creata temporary employee struct
    //copy all the information given into the temp struct
     strcpy(temp.firstName,firstName); 
    
    strcpy(temp.id,id);
    
    
    strcpy(temp.lastName,lastName);
    strcpy(temp.email,email);
    temp.salary = salary;
   
   // add the temp struct into the emp array 
    db->emp[db->total] = temp;
    // increment the total count by 1
    db->total = db->total + 1;

}
int displayMenu(struct DataBase *db){ // the user menu that will be displayed for the user to call
    int a;
    char lastName[10];
    char firstName[10];
    char email[20];
    char id[5];
    double salary;
    int b = 1;

while(1){ // creating a while loop to display the user menu in a loop until terminated
// all the options the user has which they can execute by entering the corresponding number
 printf("\n*******************************************************************\n");
 printf("****** lankalapalljn Employee Database - Total Employees: %d *******\n", db->total);
  printf("*******************************************************************\n\n");
 printf("Choose one of the menu options below:\n");
 printf("1. Sort with ID\n");
 printf("2. Display all Employees\n");
 printf("3. Search Employee by ID\n");
 printf("4. Search Employee by Last Name\n");
 printf("5. Delete Employee by ID\n");
 printf("6. Delete Employee by Last Name\n");
 printf("7. Create new Employee record\n");
 printf("8. Exit\n");
 printf("Enter your choice: ");
    scanf("%d", &a);
    printf("\n");
 // using switch cases in the loop to determine option the user has selected
        switch ((a))
        {
        case 1: // for sorting
            sortWithID(db);
            
            break;
        
        case 2: // to display all employees
            displayAll(db);
            
            break;

        case 3: // to search for employee by id
            printf("Enter ID: \n");
            scanf("%s", id);
            searchWithID(id, db);
            printf("\n");
            break;

        case 4: // to search for employee by last name
            printf("Enter last name: \n");
            scanf("%s", lastName);
            searchWithLastName(lastName, db);
            printf("\n");
            break;

        case 5: // to delete employee by the id given
            printf("Enter ID: \n");
            scanf("%s", id);
            deleteWithID(id, db);
            printf("\n");
            break;

        case 6: // to delete the employee by the given last name
            printf("Enter last name: \n");
            scanf("%s", lastName);
            deleteWithLastName(lastName, db);
            printf("\n");
            break;
        
        case 7: // to create an new employee in the database
            printf("Enter First Name: \n");
            scanf("%s", firstName);
            printf("Enter Last Name: \n");
            scanf("%s", lastName);
            printf("Enter ID: \n");
            scanf("%s", id);
            printf("Enter email: \n");
            scanf("%s", email);
            printf("Enter Employee salary: \n");
            scanf("%f", salary);
            createRecord(id, firstName, lastName, email, salary, db);
            break;

        case 8: // to exit the program
            exitProgram(db);
            printf("Bye!\n\n");
            return 0;
           
            break;
        
        
        default: printf("Invalid option\n");
            
        }
     //}
     

}

}