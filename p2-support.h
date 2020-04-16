
////////////////////////////////////////////////////////////////////////////////
//
//  File           : p2-support.h
//  Description    : This is the header file that contains all the methods created to be used by the main file. 
//                   It has all the supporting methods to execute sorting, displaying, deleting, and searching.
//
//   Author        : Jayanth Lankalapalli 
//   Last Modified : 4/1/20

 struct Employee{ // the employee struct which hold information such as their id, first name, last name, email, and salary
    char id[6];
    char firstName[11];
    char lastName[11];
    char email[21];
    double salary;  
};

 struct DataBase{ // databse struct which holds an array of Employee structs and a counter for the size of the array
   struct Employee *emp;
   int total;
};

void sortWithID(struct DataBase *a); // sorts the employees in the Databse struct by their id

int displayMenu(struct DataBase *a); // displays the user menu 

void searchWithID(char *id, struct DataBase *db); //searches the employee with the corresponding id in the database

void searchWithLastName(char *lastName, struct DataBase *db); // searches the employee with corresponding last name in the database

void deleteWithID(char *id, struct DataBase *db);// finds the employee with the corresponding id and removes it from the database

void deleteWithLastName(char *lastName, struct DataBase *db);// finds the employee with the corresponding last name and removes them from the database

void exitProgram(struct DataBase *db); // program to free all the allocated memory

void displayAll(struct DataBase *db);// displays all the employees in the database

void displayEmployee(struct Employee temp, int location);// displays the given employee struct's information and its location in the database

void createRecord(char *id, char *firstName, char *lastName, char *email, double salary, struct DataBase *db); // method to add the records to the database used only in the initialize method
