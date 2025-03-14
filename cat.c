/*
cat - a UNIX command line utility program to concatenate and print files
Date : 13.03.2025
*/
#include "file.h"

int main(int argc, char* argv[]){

	config flag = {
		.FLAG_NO = 1,
		.FLAG_N = 0,
		.FLAG_B = 0,
	};

	if(argc == 1){
		FILE* fd = stdin;
		cat_file(fd,&flag);
		return 0;
	}


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
		config the_config = {
			.path = path,
			.FLAG_NO = flag.FLAG_NO,
			.FLAG_N = flag.FLAG_N,
			.FLAG_B = flag.FLAG_B
		};
    FILE* fd;
    if(strcmp(path,"-")==0){
      fd = stdin;
    }else if(strcmp(path,"-n")==0){
      if(i==argc-1){
        fd = stdin;
      }else{
        continue;
      }
    }else if(strcmp(path,"-b")==0){
      if(i==argc-1){
        fd = stdin;
      }else{
        continue;
      }
    }else{
      if(validate_path(&the_config)!=0)
        return EXIT_FAILURE;
      
      fd = fopen(path,"r");
    }

    if(fd == NULL){
      fprintf(stderr,"cat: %s: unexpected error",path);
      return EXIT_FAILURE;
    }

    cat_file(fd, &the_config);

    if(fd != stdin){
      fclose(fd);
    }
  }
}
