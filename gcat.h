// Function accepts args as parameter and return 1 to continue the loop() on successful completion with no error
int gcat (char **args){
  if(args[1] == NULL){
    printf("File Name is not entered \n");
    return 1;
  }
  // fd == file descriptor
  int fd;
  char buffer[1024]; 
  fd = open(args[1],O_RDONLY); // Opeining the file in read mode only
  if(fd==-1){ // File do not exsist or cant be opened
    printf("Unable to open the file\n");
    return 1;
  }
  // read() attempts to read up to count bytes from file descriptor fd into the buffer.
  while(read(fd,buffer,sizeof(buffer))>0){
    printf("%s",buffer); //Printing the content present
  }
  printf("\n");
  return 1;
}