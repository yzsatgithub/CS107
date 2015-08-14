using namespace std;
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include "imdb.h"
#include <string.h>
#include <iostream>
#include <stdio.h>

const char *const imdb::kActorFileName = "actordata";
const char *const imdb::kMovieFileName = "moviedata";

imdb::imdb(const string& directory)
{
  const string actorFileName = directory + "/" + kActorFileName;
  const string movieFileName = directory + "/" + kMovieFileName;
  
  actorFile = acquireFileMap(actorFileName, actorInfo);
  movieFile = acquireFileMap(movieFileName, movieInfo);
}

bool imdb::good() const
{
  return !( (actorInfo.fd == -1) || 
	    (movieInfo.fd == -1) ); 
}

// you should be implementing these two methods right here... 

  /**
   * Method: getCredits
   * ------------------
   * Searches for an actor/actress's list of movie credits.  The list 
   * of credits is returned via the second argument, which you'll note
   * is a non-const vector<film> reference.  If the specified actor/actress
   * isn't in the database, then the films vector will be left empty.
   *
   * @param player the name of the actor or actresses being queried.
   * @param films a reference to the vector of films that should be updated
   *              with the list of the specified actor/actress's credits.
   * @return true if and only if the specified actor/actress appeared in the
   *              database, and false otherwise.
   */
bool imdb::getCredits(const string& player, vector<film>& films) const { 
    /*
     * thoughts:
     *      player: const string&
     *      films: vector<film>& 
     *  so, through operating the variable 'actorFile', we implement this function
     */

    int totalPlayerNum = *(int* )actorFile;
    cout << "there are totally " << totalPlayerNum << " players' information in the database." << endl;
    int location = 0;
    char* currName = new char[20];
    for(int i = 0; i < totalPlayerNum; i++){
        location = *((int* )actorFile + (i+1));
        strcpy(currName, (char* )actorFile + location);
        if(!strcmp(player.c_str(), currName)){
            cout << "Found it!\t" ;
            printf("%s\n", currName);
            exit(0);
        }
    }
    delete[] currName;
    int totalMovieNum = *(int* )movieFile;
    cout << totalMovieNum << endl;
    return false; 

}
bool imdb::getCast(const film& movie, vector<string>& players) const { return false; }

imdb::~imdb()
{
  releaseFileMap(actorInfo);
  releaseFileMap(movieInfo);
}

// ignore everything below... it's all UNIXy stuff in place to make a file look like
// an array of bytes in RAM.. 
const void *imdb::acquireFileMap(const string& fileName, struct fileInfo& info)
{
  struct stat stats;
  stat(fileName.c_str(), &stats);
  info.fileSize = stats.st_size;
  info.fd = open(fileName.c_str(), O_RDONLY);
  return info.fileMap = mmap(0, info.fileSize, PROT_READ, MAP_SHARED, info.fd, 0);
}

void imdb::releaseFileMap(struct fileInfo& info)
{
  if (info.fileMap != NULL) munmap((char *) info.fileMap, info.fileSize);
  if (info.fd != -1) close(info.fd);
}
