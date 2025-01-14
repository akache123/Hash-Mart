# Homework 7 Design Document


------------------------------------------------------------------------------


### Purpose

1) Using the programming language C, I will create a database that allows us tokeep track of our customers as well as information about them. This program will help me understand the usage of hashtables and how they are useful when organizing/accessing large amounts of data after reading data from a file and storing them in hashtables. 

### Layout/Structure of Program

1) Create a struct for customers with an email address (a string), a name (a string), a shoe size (an integer) and a favorite food (a string)

2) Create a main which opens the customers.tsv file reads the file and reads each row as a customer (struct) and loads into Hashtable and close the file as well (assume that it is not blank)

3) Create a function that takes the user’s input about the command they want to perform(add/delete/lookup/list/save/quit); based on commands they choose, the program should perform the respective action.

4) Create a function for each command function: add, lookup, delete, list, save, and quit.  

### Description of Program Parts

1) add() = allow you to add customers to the hash table

2) delete()  = allows you to delete customers in the hash table

3) lookup() = allows you to lookup customer’s email in the hash table; if found, print the rest of their data else print not found

4) list() = allows you to look at all of the customer’s information one by one in the hashtable

5) save() = saves the changes made to your customers.tsv file

6) quit() = frees the memory of the file and quits the program. No need to save any unsaved activities.


