#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "intarr.h"


/* LAB 5 TASK 1 */

// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.
intarr_t* intarr_create( unsigned int len){
	intarr_t* var = NULL;	
	var = malloc(sizeof(intarr_t));
	if (var != NULL){
		var->data = malloc(len * sizeof(int));
		if(var->data == NULL){
			free(var);
		}
		else{
			var->len = len;
		}
	}
	return var;
}


// frees all memory allocated for ia. If the pointer is null, do
// nothing. If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia){
	if (ia == NULL && ia->data != NULL)
		free(ia->data);
	
	else if(ia != NULL)
		free(ia);
	
}

/* LAB 5 TASK 2 */

// If index is valid, set the value at ia->data[index] to val and return
// INTARR_OK. Otherwise, leave the array unmodified and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_set( intarr_t* ia,
			    unsigned int index, int val){
  if( ia == NULL){
    return INTARR_BADARRAY;
  }
  if (index >= 0 && index < ia->len){
    ia->data[index] = val;
    return INTARR_OK;
  }
  else if(index < 0 || index >= ia->len){
    return INTARR_BADINDEX;
  }
  return 0;
}

// If index is valid and i is non-null, set *i to ia->data[index] and return
// INTARR_OK. Otherwise no not modify *i and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get( const intarr_t* ia, 
			    unsigned int index, int* i){
  if ( ia == NULL)
    return INTARR_BADARRAY;

  if (index >= 0 && index < ia->len && i != NULL){
    *i = ia->data[index];
    return INTARR_OK; 
  }
  else
    return INTARR_BADINDEX;
}

/* LAB 5 TASK 3 */

// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer. 
intarr_t* intarr_copy( const intarr_t* ia ){

intarr_t* var = NULL;
 
  var = malloc(sizeof(intarr_t));
  if (var != NULL){

    var->data = malloc(ia->len * sizeof(int));
    if(var->data == NULL)
      free(var);
 
    else   
      var->len = ia->len;
  } 
  return var;
}

/* LAB 5 TASK 4 */

// sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_sort( intarr_t* ia ){

  if (ia==NULL)
    return INTARR_BADARRAY;

  int temp;

  for(int i=0; i<ia->len; i++){
    for(int j=0; j<ia->len; j++)

      if(ia->data[i]<ia->data[j]){
        temp=ia->data[i];
        ia->data[i]=ia->data[j];
        ia->data[j]=temp;
    }
  }
}

/* LAB 5 TASK 5 */

// Find the first occurance of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
intarr_result_t intarr_find( intarr_t* ia, int target, int* i ){

  if (ia==NULL)
    return INTARR_BADARRAY;

  for (int j=0; j<ia->len; j++){
    if(target==ia->data[j] && &i!=NULL){
      *i=j;
      return INTARR_OK;
    }
  }
  return INTARR_NOTFOUND;
}

/* LAB 5 TASK 6 */

// Append val to the end of ia (allocating space for it). If
// successful, return INTARR_OK, otherwise return
// INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_push( intarr_t* ia, int val ){
      if (ia==NULL){
        return INTARR_BADARRAY;
    }
    int len2=ia->len+1;
    ia->len = len2;

    int *data2 = realloc(ia->data, sizeof(int)*(ia->len));

    if(data2){
        data2[len2-1] = val;
        ia->data = data2;
        return INTARR_OK;
    }
    else
        return INTARR_BADALLOC;
    
}

// If the array is not empty, remove the value with the highest index
// from the array, and, if i is non-null, set *i to the removed value,
// then return INTARR_OK. If the array is empty, leave *i unmodified
// and return INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_pop( intarr_t* ia, int* i ){
  if (ia==NULL)
  	return INTARR_BADARRAY;
  if (ia->len!=0){
  	if (i!=NULL){
  		*i=ia->data[ia->len-1];
  		ia->data[ia->len-1]=0;
  		ia->len=ia->len-1;
  		return INTARR_OK;
  	}
  }
  return INTARR_BADINDEX;
}

/* LAB 5 TASK 7 */

// Resize ia to contain newlen values. If newlen is less than the
// original array length, the end of the array is discarded. If newlen
// is greater than the original array length, intialize all the new
// integers to zero. If the allocation is successful, return
// INTARR_OK, otherwise return INTARR_BADALLOC. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen ){
   if (ia == NULL)
        return INTARR_BADARRAY;
  
    int i,len1;

    len1 = ia->len;
    if (newlen >= 0){
        int *data2 = realloc(ia->data,sizeof(int)*newlen);
        ia->len = newlen;
        ia->data = data2;
        if (data2){
            if (newlen>len1){
                for (i=len1; i<newlen; i++)
                    ia->data[i] = 0;        
            }
        }        
        return INTARR_OK;
    }
    return INTARR_BADALLOC;
}

/* LAB 5 TASK 8 */

// Get a deep copy of a portion of ia from index first to index last
// inclusive. If successful, return a pointer to a newly-allocated
// intarr_t containing a copy of the specfied section. If an error
// occurs, i.e. ia is null, first or last are out of bounds, last <
// first, or memory allocation fails, return a null pointer.
intarr_t* intarr_copy_subarray( intarr_t* ia, 
				unsigned int first, 
				unsigned int last ){
  if (ia==NULL || last<first)
  	return NULL;	
  intarr_t* var = NULL;
  var = malloc(sizeof(intarr_t));
  if (var!=NULL){
  	var->data=malloc((last-first+1)*sizeof(int));
  	if (var->data==NULL){
  		free(var);
  		return NULL;
  	}
  	else 
  		var->len=last-first+1;
  	for (int i=first; i<last+1; i++)
  		var->data[i-first]=ia->data[i];
  	return var;

  }
}


/* -------------------------------------------------------------- */

/* LAB 6 TASK 1 */

/*
  Save the entire array ia into a file called 'filename' in a binary
  file format that can be loaded by intarr_load_binary(). Returns
  zero on success, or a non-zero error code on failure. Arrays of
  length 0 should produce an output file containing an empty array.
*/
int intarr_save_binary( intarr_t* ia, const char* filename );

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.
*/
intarr_t* intarr_load_binary( const char* filename );


/* LAB 6 TASK 2 */

/*
  Save the entire array ia into a file called 'filename' in a JSON
  text file array file format that can be loaded by
  intarr_load_json(). Returns zero on success, or a non-zero error
  code on failure. Arrays of length 0 should produce an output file
  containing an empty array.
  
  The JSON output should be human-readable.

  Examples:

  The following line is a valid JSON array:
  [ 100, 200, 300 ]
  
  The following lines are a valid JSON array:
  [ 
   100, 
   200, 
   300 
  ]
*/
int intarr_save_json( intarr_t* ia, const char* filename );

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save(). The file may contain an array
  of length 0. Returns a pointer to a newly-allocated intarr_t on
  success (even if that array has length 0), or NULL on failure.
*/
intarr_t* intarr_load_json( const char* filename );
    
