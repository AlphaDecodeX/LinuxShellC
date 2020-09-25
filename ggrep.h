// Function accepts args as parameter and return 1 to continue the loop() on successful completion with no error

int ggrep(char **args){
  FILE *file; // Defining the File type
  char line[1000]; // Array to store the line
  file = fopen(args[2],"r");
  if(file == NULL){
    printf("Unable to open the file\n");
    return 1;
  }
  while(fscanf(file, "%[^\n]\n" , line) != EOF) // reading the file until \n chracter occurs
  {
    if(strstr(line , args[1]) !=NULL){ // strstr() finds the first occurance of substring in the string
      printf("%s",line);
    }
  }
  printf("\n");
  fclose(file); // It is mandatory.
  return 1;            
}
