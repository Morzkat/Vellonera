#include<iostream>

using namespace std;

// basic struct for a song
struct song
{
    string songName;
    string artistName;
    string songDuration;

    struct song* next;
    struct song* previous;
};

// first and last song objects
song* firstSong = NULL;
song* lastSong = NULL;
song* currentSong = NULL;

// class for actions
class Action
{
public:
    static void menu();
    static void addSong(song *newSong);
    static void showSongs();
    static void showCurrentSong();
    static void createSong();
    static void deleteSong();
    static void nextSong();
    static void previousSong();
    static void EnableRepoductionList();
};

void Action::createSong()
{
    //create a new struct for a song
    song* newSong = new (struct song);

    //get the data for the song
    cout << "Introduzca el titulo de la cancion:" << endl;
    string songName;
    cin >> songName;

    cout << "Introduza el nombre del artista:" << endl;
    string artistName;
    cin >> artistName;

    cout << "Introduza la duracion de la cancion:" << endl;
    string songDuration;
    cin >> songDuration;

    //add the data to the song
    newSong->songName = songName;
    newSong->artistName = artistName;
    newSong->songDuration = songDuration;

    //add the song to the list of items
    addSong(newSong);

    cout << "Cancion Agregada\n";
}

void Action::addSong(song *newSong)
{
    //last song like null
    newSong->next = NULL;

    //doesn't exist first song
    if (firstSong == NULL)
    {
        //the first and the last song are the same
        firstSong = newSong;
        lastSong = newSong;
    }

        //exist a first song
    else
    {
        //the next song (of the penultimate song it'll be the last song)
        lastSong->next = newSong
        //previous song (previous song of the last song)
        newSong->previous = lastSong;
        //the new last song is the latest created
        lastSong = newSong;
    }

    currentSong = newSong;
}

void Action::showSongs()
{
    //show the items if there are
    if (firstSong != NULL)
        {
        song *i = firstSong;

        while (i != NULL) {
            cout << "--------------------------------------------------------\n";
            cout << "Titulo de la cancion: " << i->songName << "\n";
            cout << "Nombre del artista: " << i->artistName << "\n";
            cout << "Duracion de la cancion: " << i->songDuration << "\n";
            cout << "---------------------------------------------------------\n";

            i = i->next;
        }
    }

    //there aren't items
    else
    {
        cout << "La lista esta vacia\n";
    }
}

void Action::menu()
{
    //menu for the options
    cout << "Elige una de las opciones\n";
    cout << "1- Agregar una nueva cancion\n";
    cout << "2- Mostrar todas las canciones\n";
    cout << "3- Mostrat cancion actual\n";
    cout << "4- Proxima Cancion\n";
    cout << "5- Cancion Anterior \n";
    cout << "6- Activar la lista de repoduccion \n";
    cout << "7- Eliminar una cancion\n";
    cout << "8- Salir\n";
    cout << "Elija una opcion =>";
}

void Action::deleteSong()
{
    //if there are song show the items to choose which delete
    if (firstSong != NULL)
    {
        cout << "Selecciona la cancion a eliminar\n";
        //show items
        showSongs();

        //get the song songName
        string songName;
        cin >> songName;

        //object for the loop
        song* i = firstSong;
        //the current song
        song* currentSong = firstSong;
        //the previous song
        song* previousSong = NULL;

        //the loop for search the song
        while(i != NULL && i->songName != songName)
        {
            previousSong = currentSong;
            currentSong = currentSong->next;
            i = i->next;
        }

        //the first the song will be delete
        if (previousSong == NULL)
        {
            firstSong = currentSong->next;
            delete currentSong;
        }

        //other song will be delete
        if (currentSong->songName == songName)
        {
            firstSong->next = currentSong->next;
            delete currentSong;
            cout << "Cancion elimanda\n";
        }
    }

    else
    {
        cout << "La lista esta vacia o no se encontro la cancion";
    }
}

void Action::nextSong()
{
    song* possibleSong = new (struct song);

    possibleSong = (currentSong == firstSong) ? firstSong->next : currentSong->next;
    currentSong = (possibleSong == NULL) ? currentSong : possibleSong;

    cout << "Avanzando a la proxima cancion \n" << endl;
    cout << "Cancion actual:  \n" << endl;
    cout << "--------------------------------------------------------\n";
    cout << "Titulo de la cancion: " << currentSong->songName << "\n";
    cout << "Nombre del artista: " << currentSong->artistName << "\n";
    cout << "Duracion de la cancion: " << currentSong->songDuration << "\n";
    cout << "---------------------------------------------------------\n";
}

void Action::previousSong()
{
    currentSong = (currentSong == firstSong) ? firstSong : currentSong->previous;

    cout << "Retrocediendo a la cancion anterior \n" << endl;
    cout << "Cancion actual:  \n" << endl;
    cout << "--------------------------------------------------------\n";
    cout << "Titulo de la cancion: " << currentSong->songName << "\n";
    cout << "Nombre del artista: " << currentSong->artistName << "\n";
    cout << "Duracion de la cancion: " << currentSong->songDuration << "\n";
    cout << "---------------------------------------------------------\n";
}

void Action::EnableRepoductionList()
{
    cout << "Enabled repoduction list";
}

void Action::showCurrentSong()
{
    cout << "Cancion actual: " << endl;
    cout << "--------------------------------------------------------\n";
    cout << "Titulo de la cancion: " << currentSong->songName << "\n";
    cout << "Nombre del artista: " << currentSong->artistName << "\n";
    cout << "Duracion de la cancion: " << currentSong->songDuration << "\n";
    cout << "---------------------------------------------------------\n";
}


int main()
{
// switch opcion
    short op;

    do
    {
        Action::menu();

        cin >> op;

        switch (op)
        {
            case 1 :
                Action::createSong();
                break;
            case 2:
                Action::showSongs();
                break;
            case 3 :
                Action::showCurrentSong();
                break;
            case 4:
                Action::nextSong();
                break;
            case 5:
                Action::previousSong();
                break;
            case 6:
                Action::EnableRepoductionList();
                break;
            case 7:
                Action::deleteSong();
                break;
        }
    }while (op < 8);
}
