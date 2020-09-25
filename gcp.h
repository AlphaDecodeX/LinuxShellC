int count(char **cmd_list){
    int i=0;
    while(cmd_list[i]!=NULL){
        i++;
    }
    return i;
} // Function to count the no. of arguments present
char *name_extract(char *name_path){
    char *input = name_path;
    char *output = NULL;
    output = strrchr(input, '/');

    if(output != NULL){
        return output+1 ;
    }
    return input;
}// Function to extract the name of the file from the file's path
void copy_file(int argc, char **argv){
    if(argc<4){
       printf("Format : %s -s <source_file_name_or_path> <destinaltion_file_name_or_path>\n",argv[0]);
    }
    FILE *file_ptr1 = fopen(argv[2], "r"); // Open the source file
    FILE *file_ptr2 = fopen(argv[3], "w"); // Open the destination file and create if it doesn't exsist
    char ch; 
    while (1) {
      ch = fgetc(file_ptr1); //reading the chracters until EOF
 
      if (ch == EOF)
         break;
      else
         putc(ch, file_ptr2); // Putting the chracters or strings into destination file
    }
    fclose(file_ptr1);
    fclose(file_ptr2);
    return ;
}

void multi_files_copy(int argc, char ** argv){
    if(argc<5){
       printf("Format : %s -m <source_file1_path> <source_file2_path> ..... <destination_dir_path>\n",argv[0]);
    }
    char dir[500];
    ssize_t size = 500;
    getcwd(dir, size); // Save current directory for reference of in case if complete paths of the files and directory is provided w.r.t the cwd
    int position = 2; // Start from flag+1
    while(position < argc-1){
        // chdir(dir);
        FILE *file_ptr1 = fopen(argv[position], "r"); // Get <source_file[position]>
        chdir(argv[argc-1]); // Change the directory to the destination directory
        char *file_name = name_extract(argv[position]); 
        // printf("%s\n",file_name);
        FILE *file_ptr2 = fopen(file_name,"w"); // Picking up or creating the file with same name of <source_file[position]> as extracted from the above function
        char ch;
        while (1) {
        ch = fgetc(file_ptr1);
 
        if (ch == EOF)
             break;
        else
             putc(ch, file_ptr2);
        }
        chdir(dir);
        fclose(file_ptr1);
        fclose(file_ptr2);
        position ++;
    }
    return ;
}

int gcp(char **argv){
   int argc = count(argv);
   if(argv[1]==NULL){
       printf("Enter one of the following command\n");
       printf("Format : gcp -m <source_file1_path> <source_file2_path> ..... <destination_dir_path>\n");
       printf("Format : gcp -s <source_file_name_or_path> <destinaltion_file_name_or_path>\n");
       return 1;
   }
   if(strcmp(argv[1],"-s")==0){ // Comapare the string flag with -s which indicates single file to single copy
       copy_file(argc, argv);
   }
   if(strcmp(argv[1],"-m")==0){ // Comapare the string flag with -m which indicates multiple file to directory
       multi_files_copy(argc, argv);
   }
   return 1;
}