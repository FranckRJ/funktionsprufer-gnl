#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#include "openFile.hpp"
#include "stdOutputGetter.hpp"

stdOutputGetter::stdOutputGetter(std::string filebufName)
{
  int newId;
  fflush(stdout);
  oldId = dup(1);
  newId = open(filebufName.c_str(), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  dup2(newId, 1);
  close(newId);
}

stdOutputGetter::~stdOutputGetter()
{
  fflush(stdout);
  dup2(oldId, 1);
  close(oldId);
}
