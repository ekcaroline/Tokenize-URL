#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <syscall.h>

//global variables
char *link;

int main(int argc, char *argv[]) {
//check if arguments are equal to 2
if (argc != 2) {
  printf("INVALID! Please re-enter valid arguments.\n");
  }
  
link = argv[1];  
char *protocol = strtok(link, " :// ");
//take the first three characters of the string
if (strcmp(protocol, "http") == 0) {
  printf("You made it.\n");
} else {
  printf("Error. This is not a link.\n");
  return 0;
  }
  //separates the URL
  char *site = strtok(NULL, " / ");
  char *URL = strtok(NULL, " ");
  printf("%s\n", protocol);
  printf("%s\n", site);
  printf("%s\n", URL);
  
  execlp("/usr/bin/curl", "curl", "-o", "file.txt", site, NULL);
}
