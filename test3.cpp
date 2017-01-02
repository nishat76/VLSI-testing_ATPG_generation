// test3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"


int main ()
{
  FILE * pFile;
  int c, index;
  int ord[5] ;
  int n = 0;
  pFile=fopen ("reza.txt","r");
  if (pFile==NULL) perror ("Error opening file");
  else
  {
    do {
      c = fgetc (pFile);
	  //printf ("%d\n",c);
	  if (c == '(') {c=fgetc (pFile); index=c-48; ord[index]=n; printf ("ord[%d]= %d\n", index, n);n++;}
    } while (c != EOF);
    fclose (pFile);
    //printf ("The file contains %d   breket sign characters ($).\n",n);
  }
  getch();
  return 0;
}

