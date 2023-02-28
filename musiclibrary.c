//
// APS105 Lab 9
//
// This is a program written to maintain a personal music library,
// using a linked list to hold the songs in the library.
//
// Author: <Your Name Goes Here>
// Student Number: <Your Student Number Goes Here>
//

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the linked list

// Each string in the node is declared as a character pointer variable,
// so they need to be dynamically allocated using the malloc() function,
// and deallocated using the free() function after use.

typedef struct node {
  char *artist;
  char *songName;
  char *genre;
  struct node *next;
} Node;

// Declarations of linked list functions
//
// DECLARE YOUR LINKED-LIST FUNCTIONS HERE
//

// Declarations of support functions
// See below the main function for descriptions of what these functions do

void inputStringFromUser(char *prompt, char *s, int arraySize);
void songNameDuplicate(char *songName);
void songNameFound(char *songName);
void songNameNotFound(char *songName);
void songNameDeleted(char *songName);
void artistFound(char *artist);
void artistNotFound(char *artist);
void printMusicLibraryEmpty(void);
void printMusicLibraryTitle(void);

const int MAX_LENGTH = 1024;

int main(void) {
  // Declare the head of the linked list.
  //   ADD YOUR STATEMENT(S) HERE

  // Announce the start of the program
  printf("Personal Music Library.\n\n");
  printf("%s", "Commands are I (insert), D (delete), S (search by song name),\n"
               "P (print), Q (quit).\n");

  char response;
  char input[MAX_LENGTH + 1];
  do {
    inputStringFromUser("\nCommand", input, MAX_LENGTH);

    // Response is the first character entered by user.
    // Convert to uppercase to simplify later comparisons.
    response = toupper(input[0]);

    if (response == 'I') {
      // Insert a song into the linked list.
      // Maintain the list in alphabetical order by song name.
      //   ADD STATEMENT(S) HERE

      // USE THE FOLLOWING STRINGS WHEN PROMPTING FOR DATA:
      //    char *promptName = "Song name" ;
      //    char *promptArtist =  "Artist" ;
      //    char *promptGenre = "Genre" ;

    } else if (response == 'D') {
      // Delete a song from the list.

      char *prompt = "\nEnter the name of the song to be deleted";

      //   ADD STATEMENT(S) HERE

    } else if (response == 'S') {
      // Search for a song by its name.

      char *prompt = "\nEnter the name of the song to search for";

      //   ADD STATEMENT(S) HERE

    } else if (response == 'P') {
      // Print the music library.

      //   ADD STATEMENT(S) HERE

    } else if (response == 'Q') {
      ; // do nothing, we'll catch this below
    } else {
      // do this if no command matched ...
      printf("\nInvalid command.\n");
    }
  } while (response != 'Q');

  // Delete the entire linked list.
  //   ADD STATEMENT(S) HERE

  // Print the linked list to confirm deletion.
  //   ADD STATEMENT(S) HERE

  return 0;
}

// Support Function Definitions

// Prompt the user for a string safely, without buffer overflow
void inputStringFromUser(char *prompt, char *s, int maxStrLength) {
  int i = 0;
  char c;

  printf("%s --> ", prompt);
  while (i < maxStrLength && (c = getchar()) != '\n')
    s[i++] = c;
  s[i] = '\0';
}

// Function to call when the user is trying to insert a song name
// that is already in the personal music library.
void songNameDuplicate(char *songName) {
  printf("\nA song with the name '%s' is already in the music library.\n"
         "No new song entered.\n",
         songName);
}

// Function to call when a song name was found in the personal music library.
void songNameFound(char *songName) {
  printf("\nThe song name '%s' was found in the music library.\n", songName);
}

// Function to call when a song name was not found in the personal music
// library.
void songNameNotFound(char *songName) {
  printf("\nThe song name '%s' was not found in the music library.\n",
         songName);
}

// Function to call when a song name that is to be deleted
// was found in the personal music library.
void songNameDeleted(char *songName) {
  printf("\nDeleting a song with name '%s' from the music library.\n",
         songName);
}

// Function to call when printing an empty music library.
void printMusicLibraryEmpty(void) { 
  printf("\nThe music library is empty.\n"); 
}

// Function to call to print a title when the entire music library is printed.
void printMusicLibraryTitle(void) { 
  printf("\nMy Personal Music Library: \n"); 
}

// Add your functions below this line.

//   ADD STATEMENT(S) HERE
