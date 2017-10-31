#include <iostream>

using namespace std;

struct song{
    string songTitle;
    string filename;
    string genre;
    int tracknumber;
    bool fav;
};

void menu();
void enter_song();
void delete_song();
void edit_song();
void display_song();
void display_fav();

int choice, song_count=0;
song tsupod[100];

int main()
{

    choice=-1;

    cout << "Welcome to TsuPod.\n";

    for (;choice!=0;){
        menu();
        switch (choice) {
        case 1: {
            if (song_count<100)
                enter_song();
            else
                cout << "Your TsuPod is full! Please edit songs going forward.";
        }
        break;
        case 2: {
            delete_song();
        }
        break;
        case 3: {
            edit_song();
        }
        break;
        case 4: {
            display_song();
        }
        break;
        case 5: {
            display_fav();
        }
        break;
        }

    }
    cout << "Thank you for using TsuPod!";
    return 0;
}

void menu(){
    cout << "\nPlease select an option:\n\n";
    cout << "1-Enter a new song\n";
    cout << "2-Delete a song\n";
    cout << "3-Edit a song\n";
    cout << "4-Display all songs\n";
    cout << "5-Display favorite songs\n";
    cout << "0-Exit program\n\n";

    cin >> choice;

    for (;choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5&&choice!=0;){
        cin >> choice;
    }
}

void enter_song(){
    int mark = song_count;

    cout << "Please enter the song title:\n";
    cin >> tsupod[mark].songTitle;
    cout << "Please enter the file name:\n";
    cin >> tsupod[mark].filename;
    cout << "Please enter the genre:\n";
    cin >> tsupod[mark].genre;
    cout << "Please enter the track number:\n";
    cin >> tsupod[mark].tracknumber;
    cout << "Is this song a favorite? (1-Yes, 0-No)\n";
    cin >> tsupod[mark].fav;

    song_count++;
}

void delete_song(){
    int x=-1;
    cout << "Which song number do you want to delete?";
    cin >> x;
    tsupod[x].songTitle = "";
    tsupod[x].filename = "";
    tsupod[x].genre = "";
    tsupod[x].tracknumber = 0;
    tsupod[x].fav = false;

    if (tsupod[x].songTitle == "")
        cout << "File deleted successfully\n\n";
}

void edit_song() {
    int mark;

    cout << "Please select which song you would like to edit: \n";
    cin >> mark;
    mark--;

    cout << "Please enter the song title:\n";
    cin >> tsupod[mark].songTitle;
    cout << "Please enter the file name:\n";
    cin >> tsupod[mark].filename;
    cout << "Please enter the genre:\n";
    cin >> tsupod[mark].genre;
    cout << "Please enter the track number:\n";
    cin >> tsupod[mark].tracknumber;
    cout << "Is this song a favorite? (1-Yes, 0-No)\n";
    cin >> tsupod[mark].fav;
}

void display_song() {
    cout << "All Songs:\n\n";

    for (int x=0; x<song_count; x++) {
        if (tsupod[x].songTitle!="") {
            cout << "Song Title: " << tsupod[x].songTitle << endl;
            cout << "File Name: " << tsupod[x].filename << endl;
            cout << "Genre: " << tsupod[x].genre << endl;
            cout << "Track number: " << tsupod[x].tracknumber << endl;
            cout << "Favorite: " << tsupod[x].fav << "\n\n";
        }
    }
}

void display_fav() {
    cout << "Favorite Songs:\n\n";

    for (int x=0; x<song_count; x++) {
        if (tsupod[x].fav==true) {
            cout << "Song Title: " << tsupod[x].songTitle << endl;
            cout << "File Name: " << tsupod[x].filename << endl;
            cout << "Genre: " << tsupod[x].genre << endl;
            cout << "Track number: " << tsupod[x].tracknumber << endl;
            cout << "Favorite: " << tsupod[x].fav << "\n\n";
        }
    }
}
