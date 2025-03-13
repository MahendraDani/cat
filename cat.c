/*
cat - a UNIX command line utility program to concatenate and print files
Date : 13.03.2025
*/
#include "file.h"

int main(int argc, char* argv[]){

  // TODO : handle flags (no flag), -n or -b
  flags flag = {1,0,0};
  for(int i=1;i<argc;i++){
    if(strcmp(argv[i],"-n")==0){
      flag.FLAG_N = 1;
    }else if(strcmp(argv[i],"-b")==0){
      flag.FLAG_B = 1;
    }else {
      break;
    }
  }

  for(int i=1;i<argc;i++){
    const char* path = argv[i];

    FILE* fd;
    if(strcmp(path,"-")==0){
      // Read from stdin
      fd = stdin;
    }else if(strcmp(path,"-n")==0){
      if(i==argc-1){
        // $ cmd | ./cat -n
        fd = stdin;
      }else{
        continue;
      }
    }else if(strcmp(path,"-b")==0){
      if(i==argc-1){
        // $ cmd | ./cat -b
        fd = stdin;
      }else{
        continue;
      }
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

    cat_file(fd,&flag);

    if(fd != stdin){
      fclose(fd);
    }
  }
}
