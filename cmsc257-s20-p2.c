////////////////////////////////////////////////////////////////////////////////
//
//  File           : cmsc257-s20-p2.c
//  Description    : This is the main source code for for the assignment.
//                   
//
//   Author        : Jayanth Lankalapalli 
//   Last Modified : 4/1/20
//

// Include Files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "p2-support.h"
#define dbSIZE 100
#define idSIZE 6
#define nameSIZE 11
#define emailSIZE 21
// Functions

////////////////////////////////////////////////////////////////////////////////
//
// Functions     : initialize() and main()
// Description  : The main function for the CMSC257 project #1
// 
// Inputs       : None
// Outputs      : Displays a menu which gives the user options to view, sort, search and 
//                  delete from the database (db)

// Function 	: The main function calls the initialize() which allocates memory to the emp array which holds information
//                for each employee. Then sets the total in db to be the size 0 showing there 
//                are currently no entries in the emp array and hence in the db database.
//                Then it calls createRecord() function which has the parameters filled with the
//                  Employee information which then get stored int he database. Then the main
//                  calls displayMenu() for db which will then show the user options to navigate the database.
void
initialize (struct DataBase *db)
{
 db->emp = malloc(sizeof(struct Employee)*dbSIZE); // allocates memory to db->emp, which is the emp array
 db->total = 0; // sets total to 0 to reflect db is empty

// creating entries which are entered into database db
 createRecord ("00306", "Wei", "Martin", "wm@aol.com", 98999.99, db); 
 createRecord ("00307", "Mitch", "Martinez", "mitch@aol.com", 78999.88, db);
 createRecord ("00408", "David", "Boyle", "db@aol.com", 100000.01, db);
 createRecord ("00204", "Christine", "Bluer", "cb@aol.com", 40009.99, db);
 createRecord ("00305", "Stephen", "Black", "sb@aol.com", 8500.01, db);
 createRecord ("00409", "Chris", "Boyle", "cb@aol.com", 200000.01, db);
 createRecord ("00101", "Paula", "Brown", "pb@aol.com", 1000.37, db);
 createRecord ("00102", "Paul", "Green", "pg@aol.com", 2700.45, db);
 createRecord ("00203", "Chris", "Reddy", "cr@aol.com", 2304.67, db);

}
int
main ()
{
 struct DataBase* db;
 db = malloc(sizeof(struct DataBase)); // allocating memory to db
 initialize (db);
 displayMenu(db); // display user menu
 



return 0;
}