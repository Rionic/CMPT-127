#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "point_array.h"

/* ALL THESE FUNCTIONS REQUIRE A VALID POINT_ARRAY_T POINTER AS THEIR
   FIRST PARAMETER. THEY SHOULD FAIL ON ASSERTION IF THIS POINTER IS
   NULL */

/* TASK 1 */

// Safely initalize an empty array structure.

void point_array_init( point_array_t* pa ){
	pa->reserved=0;
	pa->len=0;
	pa->points=NULL;
}

/* TASK 2 */

// Resets the array to be empty, freeing any memory allocated if
// necessary.
void point_array_reset( point_array_t* pa ){
	assert(pa);
	assert(pa->points);
		

	for(int i=0; i<pa->len; i++){
		pa->points[i].x=0;
		pa->points[i].z=0;
		pa->points[i].y=0;
	}
	pa->len=0;
	pa->points=realloc(pa->points,0);
}

/* TASK 3 */

// Append a point to the end of an array. If successful, return 0,
// else return 1;
int point_array_append( point_array_t* pa, point_t* p ){
	if (p==NULL)
		return 0;

	pa->len=pa->len+1;
	pa->points=realloc(pa->points,sizeof(point_t)*pa->len);

	if (pa->points == NULL)	
		return 1;
	
	pa->points[pa->len-1].x=p->x;
	pa->points[pa->len-1].y=p->y;
	pa->points[pa->len-1].z=p->z;
	return 0;
}

/* TASK 4 */

// Remove the point at index i from the array, reducing the size of
// the array by one. The order of points in the array may change.
int point_array_remove( point_array_t* pa, unsigned int i ){
		if (i>pa->len-1 || pa==NULL || pa->points==NULL ||pa->len==0)	
			return 1;
	
	pa->points[i]=pa->points[pa->len-1];	

	pa->len=pa->len-1;
	return 0;
}