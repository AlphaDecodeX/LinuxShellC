// Function accepts args as parameter and return 1 to continue the loop() on successful completion with no error
int count_no_args(char **cmd_list){
    int i=0;
    while(cmd_list[i]!=NULL){
        i++;
    }
    return i;
} // Function to count the no. of arguments present
char *check_path(char **args){
    char *input = args[1];
    char *output = NULL;
    output = strrchr(input, '/');

    if(output != NULL){
        return output+1 ;
    }
    return input;
}

int gmv (char **args){
  int argc = count_no_args(args);
  if(argc<3){
      printf("Format : gmv <file1_path> <directory_name_or_path>\n");
      return 1;
  }
  char *file = check_path(args); // Getting file name from path if it is a path specified by the user
  char *dest= args[2]; // Destination directory 
  char current_dir[50];
  if (args[2]==NULL){
    printf("Enter the destination dir\n");
  }
  else
    {
        if(dest[0]=='/')				//Checking if the destination is a name or path
        {
            strcat(dest,"/");			//Preparing path for the complete path by appending the strings.
            strcat(dest,file);
            if(rename(args[1], dest) == 0) // Moving
                printf("Successful\n");
            else
                printf("Error: Directory not found\n");
        }
        else
        {
            DIR *dir;
            dir = opendir(dest); 				// Opeining the directory

            if(dir==NULL)
            {
                if( rename(args[1],dest)!= 0) 
                    printf("Error: File not moved\n");
                else
                    printf("Successful\n");
            }
            else
            {
                char *ptr;
                ptr = getcwd(current_dir, 50);		// Get CWD. 
                strcat(current_dir,"/");				
                strcat(current_dir,dest);			// Attaching the dest
                strcat(current_dir,"/");
                strcat(current_dir, file);				// Complete path for the File
                if(rename(args[1],ptr)!=-1)
                    printf("Successful\n");
                else
                    printf("Error: Directory not found in CWD\n");
                closedir(dir);
            }
        }
    }
    return 1;
}
