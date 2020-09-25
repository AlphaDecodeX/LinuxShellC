// Very simple function to print the name of the current working dir using system call of getcwd()
int gpwd(char **args){
  char name[1024];

  getcwd(name,sizeof(name));

  printf("\nPath : %s\n",name);
  return 1;

}