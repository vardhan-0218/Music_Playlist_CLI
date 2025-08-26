Implementing a music playlist using a singly linked list. Each song in the playlist represents a node in the list, containing details such as the song title, artist, and duration.
Operations:
Add Song: Add a new song to the playlist.
Play Next Song: Play the next song in the playlist and remove it from the list.
View Playlist: Display all songs in the playlist.
Search Song: Search for a specific song by its title or artist.
Remove Song: Remove a song from the playlist.

EXPLANATION:
we define a Song struct that contains the song title, artist, duration, and a pointer to the next node in the linked list. We then define several functions to manipulate the linked list, including:
Add Song: This function takes the song title, artist, and duration as parameters. It creates a new song node and adds it to the end of the playlist. And displayed the message that which song is added.
Play NextSong: This function plays the next song in the playlist and removes it from the list. If the playlist is empty, it displays a message.
View Playlist: This function displays all songs in the playlist. If the playlist is empty, it displays a message.
Search Song: This function searches for a song by its title and artist. It returns the song node if found, otherwise NULL.
Remove Song: This function removes a song from the playlist by its title and artist. If the song is not found, it displays a message. If the playlist is empty, it displays a message. if the song removed the removed song was displayed .
In the main function, we use these functions to implement the music playlist. We create an empty linked list and allow the user to choose which operation to perform. If the user chooses to add a song, we create a new Song node with the given title, artist, and duration, and add it to the end of the linked list using the addSong function. If the user chooses to play the next song, we call the playNextSong function to play the first song in the linked list and remove it from the list. If the user chooses to view the playlist, we call the viewPlaylist function to display all songs in the linked list. If the user chooses to search for a song, we call the searchSong function to search for the song in the linked list by title and artist. If the song is found, we display its details. If the user chooses to remove a song, we call the removeSong function to remove the song from the linked list by title and artist.


run in ubunt software
cd -> command for change directory where filr is located 
to run code:

1. cd <directory>
2. gcc <filename.c> -o test
3. ./test
