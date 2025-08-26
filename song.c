#include <stdio.h>

#include <stdlib.h>

#include <string.h>



typedef struct Song 

{

    char title[50];

    char artist[50];

    float duration;

    struct Song *next;

    

} SONG;



SONG *head = NULL;



void addSong(char *title, char *artist, float duration) 

{

    SONG *newSong = (SONG *) malloc(sizeof(struct Song));

    strcpy(newSong->title, title);

    strcpy(newSong->artist, artist);

    

    newSong->duration = duration;

    newSong->next = NULL;



    if (head == NULL)

    {

        head = newSong;

    } 

    else

    {

        SONG *temp = head;

        

        while (temp->next != NULL) 

             temp = temp->next;

        

        temp->next = newSong;

    }

    printf("song added:%s-->%s\n",title,artist);

}



void playNextSong() 

{

    if (head == NULL) 

    {

        printf("Playlist is empty.\n");

        return;

    }



    SONG *temp = head;

    printf("Now playing: %s - %s (%f minutes)\n", temp->title, temp->artist, temp->duration);

    head = head->next;

    free(temp);

}



void viewPlaylist() 

{

    if (head == NULL) 

    {

        printf("Playlist is empty.\n");

        return;

    }



    SONG *temp = head;

    while (temp != NULL) 

    {

        printf("%s --> %s (%f minutes)\n", temp->title, temp->artist, temp->duration);

        temp = temp->next;

    }

}





SONG *searchSong(char *title, char *artist) 

{

    SONG *temp = head;

    

    while (temp != NULL) 

    {

        if ((strcmp(temp->title, title) == 0 && strcmp(temp->artist, artist) == 0) ||

            (strcmp(temp->title, title) == 0) || (strcmp(temp->artist, artist) == 0)) 

    

            return temp;

    

        temp = temp->next;

    }

    return NULL;

}



void removeSong(char *title, char *artist) 

{

    if (head == NULL) 

    {

        printf("Playlist is empty.\n");

        return;

    }



    SONG *temp = searchSong(title, artist);

    if (temp == NULL) 

    {

        printf("Song not found.\n");

        return;

    }



    if (temp == head) 

         head = head->next;

    else 

    {

        SONG *prev = head;

        while (prev->next != temp) 

            prev = prev->next;

    

        prev->next = temp->next;

    }

    printf("song removed:%s-->%s\n",title,artist);

    free(temp);

}



void main() 

{

    int choice;

    char title[50], artist[50];

    float duration;



    for(;;)

    {

        printf("\n1. Add Song\n2. Play Next Song\n3. View Playlist\n4. Search Song\n5. Remove Song\n6. Exit\n");

        

        printf("Enter your choice: ");

        scanf("%d", &choice);



        switch (choice) 

        {

            case 1:

                	printf("Enter song title: ");

                	scanf("%s", title);

                

                	printf("Enter artist name: ");

                	scanf("%s", artist);

                	

                	printf("Enter song duration (in minutes): ");

                	scanf("%f", &duration);

                

                	addSong(title, artist, duration);

                	

                	break;

                

            case 2:

                	playNextSong();

                	break;

                

            case 3:

                	viewPlaylist();

                	break;

               	 

            case 4:

                	printf("Enter song title: ");

                	scanf("%s", title);

                

               		printf("Enter artist name: ");

                	scanf("%s", artist);

                

                	SONG *foundSong = searchSong(title, artist);

        		

                	if (foundSong != NULL) 

                    		printf("Song found: %s - %s (%f minutes)\n", foundSong->title, foundSong->artist, foundSong->duration);

                    

                	else 

                    		printf("Song not found.\n");

                	break;

                

            case 5:

                	printf("Enter song title: ");

                	scanf("%s", title);

                

                	printf("Enter artist name: ");

                	scanf("%s", artist);

                

                	removeSong(title, artist);

                	

                	break;

            case 6:

                	exit(0);

                

            default:

               		printf("Invalid choice. Please try again.\n");

                	

        }

    }

}