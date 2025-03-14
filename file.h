#pragma once
#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

typedef struct config {
  const char* path;
  int FLAG_NO;
  int FLAG_N;
  int FLAG_B;
} config;

int validate_path(config* the_config);
void cat_file(FILE *fd, config* the_config);

#endif
