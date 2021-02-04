  #include "sort.h"
/**
 *selection_sort -sorts an array of integers in ascending
 *order using selection sort algorithm
 *@array : pointer to array to be sorted
 *@size : size of array
 *Return: void
 */


void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min;
	int temp;

	/*set the min to the first location*/
	for (i = 0; i < size - 1; i++)
	{
		min = i;

		/*search for the min element in the array*/
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		/*swap*/
		if (array[i] != array[min])
		  {
		    temp = array[i];
		    array[i] = array[min];
		    array[min] = temp;

		    /*print sorted array*/
		    print_array(array, size);
		  }
	}
}



