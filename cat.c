/*
cat - a UNIX command line utility program to concatenate and print files
Date : 13.03.2025
*/
#include "file.h"

int main(int argc, char* argv[]){
  for(int i=1;i<argc;i++){
    const char* path = argv[i];

    FILE* fd;
    if(strcmp(path,"-")==0){
      // Read from stdin
      fd = stdin;
    }else{
      if(validate_path(path)!=0)
        return EXIT_FAILURE;
      
      // Read from path
      fd = fopen(path,"r");
    }

    if(fd == NULL){
      fprintf(stderr,"cat: %s: unexpected error",path);
      return EXIT_FAILURE;
    }

    cat_file(fd);

    if(fd != stdin){
      fclose(fd);
    }
  }
}
