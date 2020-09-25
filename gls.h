// Function accepts args as parameter and return 1 to continue the loop() on successful completion with no error

int gls(char **args){
  DIR *d; // DIR datatype d from <dirent.h>
  struct dirent *dir; // strcuture is used from <dirent.h>
  if(args[1] != NULL){ // If direcory is given
    d = opendir(args[1]);
  } else{ // If no dir is given or specified in the command
    ssize_t ssize = 500;
    char dir_path[500];
    getcwd(dir_path, ssize); // getcwd() use buffer and size to store the current directory into buff
    d = opendir(dir_path); // open(dir) used dir_path buffer to open the cwd
  } 
  if (d) // If directory exsist
    {
/* 
struct dirent *readdir(DIR *dirp);The readdir() function returns a pointer
to a dirent structure representing the next directory entry in the directory stream pointed to by dirp.  It returns NULL
on reaching the end of the directory stream or if an error occurred.
*/
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d); // Closing the directory
  }else{
        perror("Source Directory Error"); // If dir doesn't exsist
        
  }
  return 1;
}