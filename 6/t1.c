//t1.c
/* LAB 6 TASK 1 */

/*
  Save the entire array ia into a file called 'filename' in a binary
  file format that can be loaded by intarr_load_binary(). Returns
  zero on success, or a non-zero error code on failure. Arrays of
  length 0 should produce an output file containing an empty array.

  Make sure you validate the parameters before you use them.
*/
#include<stdio.h>
#include<stdlib.h>
#include"intarr.h"
#include<math.h>

int intarr_save_binary( intarr_t* ia, const char* filename ){
 
  if(ia==NULL){
    return -1;
  }
  if(filename==NULL){
    return -1;
  }
  //returning 0 if its succesful
  FILE *new=fopen(filename,"w");
  if(fwrite(ia->data,sizeof(int),ia->len,new)==ia->len){
    
    fclose(new);
    return 0;
 
  }
  else{
    fclose(new);
    return -1;
  }
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.

  Make sure you validate the parameter before you use it.
*/

intarr_t* intarr_load_binary( const char* filename ){
  if(filename==NULL){
    return NULL;
  }
  FILE * file=fopen(filename,"r");
  if(file==NULL){
    return NULL;
  }
  fseek(file,0,SEEK_END);
  int ln;
  ln=ftell(file)/sizeof(int);
  fseek(file,0,SEEK_SET);
  intarr_t *arr=malloc(sizeof(intarr_t));
  arr->len=ln;
  arr->data=malloc(sizeof(int)*arr->len);
  int rlen=fread(arr->data,sizeof(int),ln,file);
  if(rlen==arr->len){
    fclose(file);
    return arr;
  }
  else{
    fclose(file);
    return NULL;
  }
}