//
// Author: Ridvik Pal
// Student Number: 1008167877
//

typedef struct linkedList
{
    Node *head;
} LinkedList;

Node *searchNode(LinkedList *library, char searchTerm[])
{
    if (library->head == NULL)
    {
        return NULL;
    }

    Node *current = library->head, *previous;

    // check if head node matches
    if (strcmp(current->songName, searchTerm) == 0)
    {
        return current;
    }

    // this loop checks all nodes except for the last one
    while (current != NULL && strcmp(current->songName, searchTerm) != 0)
    {
        previous = current;
        current = current->next;
    }

    // if current = NULL then the element was never found
    if (current == NULL)
    {
        return NULL;
    }

    return current;
}

Node *createNode(char *songName, char *artist, char *genre)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->songName = (char *)malloc(strlen(songName) + 1);
    newNode->artist = (char *)malloc(strlen(artist) + 1);
    newNode->genre = (char *)malloc(strlen(genre) + 1);

    if (newNode != NULL)
    {
        strcpy(newNode->songName, songName);
        strcpy(newNode->artist, artist);
        strcpy(newNode->genre, genre);
        newNode->next = NULL;
        return newNode;
    }
    return NULL;
}

bool insertAlphabetically(LinkedList *library, char *songName, char *artist, char *genre){
    Node *newNode = createNode(songName, artist, genre);

    if (newNode == NULL)
    {
        return false;
    }
    if (searchNode(library, newNode->songName) == NULL)
    {
        if (library->head == NULL || strcmp(newNode->songName, library->head->songName) < 0){
            newNode->next = library->head;
            library->head = newNode;
        }
        else
        {
            Node *current = library->head;

            while (current->next != NULL && strcmp(current->next->songName, songName) < 0)
            {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }

        return true;
    }
    else
    {
        songNameDuplicate(newNode->songName);
        free(newNode);
        return false;
    }
}

void printLibrary(LinkedList *library)
{
    Node *current = library->head;

    if (current == NULL)
    {
        printMusicLibraryEmpty();
    }
    else
    {
        printMusicLibraryTitle();
        while (current != NULL)
        {
            printf("\n%s\n", current->songName);
            printf("%s\n", current->artist);
            printf("%s\n", current->genre);
            current = current->next;
        }
    }
}

bool deleteNode(LinkedList *library, char searchTerm[])
{
    if (library->head == NULL)
    {
        return false;
    }

    Node *current = library->head, *previous;

    // check if head node matches
    if (strcmp(current->songName, searchTerm) == 0)
    {
        library->head = current->next;
        //songNameDeleted(current->songName);
        free(current);
        return true;
    }

    // this loop checks all nodes except for the last one
    while (current != NULL && strcmp(current->songName, searchTerm) != 0)
    {
        previous = current;
        current = current->next;
    }

    // if current = NULL then the element was never found
    if (current == NULL)
    {
        return false;
    }

    previous->next = current->next;
    //songNameDeleted(current->songName);
    free(current);
    return true;
}

void quit(LinkedList *library)
{
    Node *nextAddress;
    while (library->head != NULL)
    {
        nextAddress = library->head->next;
        songNameDeleted(library->head->songName);
        free(library->head);
        library->head = nextAddress;
    }
    printMusicLibraryEmpty();
    library->head = NULL;
}

int main(void)
{
    printf("Personal Music Library.\n\n");
    printf("%s", "Commands are I (insert), D (delete), S (search by song name),\nP (print), Q (quit).\n");

    char response;
    char commandInput[MAX_LENGTH + 1];
    LinkedList musicLibrary;
    musicLibrary.head = NULL;
    do
    {
        inputStringFromUser("\nCommand", commandInput, MAX_LENGTH);
        response = toupper(commandInput[0]);

        if (response == 'I')
        {
            char promptName[MAX_LENGTH + 1];
            inputStringFromUser("Song name", promptName, MAX_LENGTH);
            char promptArtist[MAX_LENGTH + 1];
            inputStringFromUser("Artist", promptArtist, MAX_LENGTH);
            char promptGenre[MAX_LENGTH + 1];
            inputStringFromUser("Genre", promptGenre, MAX_LENGTH);

            insertAlphabetically(&musicLibrary, promptName, promptArtist, promptGenre);
            // printf("head -> %s\n", musicLibrary.head->songName);
        }
        else if (response == 'D')
        {
            char *prompt = "\nEnter the name of the song to be deleted";
            char promptDelete[MAX_LENGTH + 1];
            inputStringFromUser(prompt, promptDelete, MAX_LENGTH);

            if (deleteNode(&musicLibrary, promptDelete)){
                songNameDeleted(promptDelete);
            }
            else
            {
                songNameNotFound(promptDelete);
            }
        }
        else if (response == 'S')
        {
            char *prompt = "\nEnter the name of the song to search for";
            char promptSearch[MAX_LENGTH + 1];
            inputStringFromUser(prompt, promptSearch, MAX_LENGTH);

            Node *foundNode = searchNode(&musicLibrary, promptSearch);

            if (foundNode == NULL)
            {
                songNameNotFound(promptSearch);
            }
            else
            {
                songNameFound(foundNode->songName);
                printf("\n%s\n", foundNode->songName);
                printf("%s\n", foundNode->artist);
                printf("%s\n", foundNode->genre);
            }
        }
        else if (response == 'P')
        {
            printLibrary(&musicLibrary);
        }
        else if (response == 'Q')
        {
            ;
        }
        else
        {
            printf("\nInvalid command.\n");
        }
    } while (response != 'Q');

    quit(&musicLibrary);

    return 0;
}
