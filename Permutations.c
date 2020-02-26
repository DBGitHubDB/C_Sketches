// C program to print all permutations with duplicates allowed
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

/* Function to print permutations of string
This function takes three parameters:
1. String
2. Starting index of the string
3. Ending index of the string. */
void permute(char *a, int l, int r, FILE *fp)
{
int i;
if (l == r){
	//printf("%s\n", a);

    //fprintf(fp,"%s\n", a );//0.002507 seconds

    fputs(a,fp);
    fputs("\n",fp); //0.010006 seconds

}

else
{
	for (i = l; i <= r; i++)
	{
		swap((a+l), (a+i));
		permute(a, l+1, r,fp);
		swap((a+l), (a+i)); //backtrack
	}
}
}

/* Driver program to test above functions */
FILE *fp;

int main()
{
    remove("test.txt");
    fp = fopen("test.txt", "a");
    struct timeval  tv1, tv2;
    gettimeofday(&tv1, NULL);
	char str[] = "ABab12";
	int n = strlen(str);
	permute(str, 0, n-1,fp);

	gettimeofday(&tv2, NULL);
	printf ("Total time = %f seconds\n",
    (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
    (double) (tv2.tv_sec - tv1.tv_sec));
	fclose(fp);

	return 0;
}
