#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *replaceWord(const char *s, const char *oldW ,const char *newW )
{
    char *result;
    int i, cnt = 0;
    int newWlen = strlen(newW);
    int oldWlen = strlen(oldW);
 
    // Counting the number of times old word
    // occur in the string
    for (i = 0; s[i] != '\0'; i++)
    {
        if (strstr(&s[i], oldW) == &s[i])
        {
            cnt++;
 
            // Jumping to index after the old word.
            i += oldWlen - 1;
        }
    }
 
    // Making new string of enough length
    result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1);
 
    i = 0;
    while (*s)
    {
        // compare the substring with the result
        if (strstr(s, oldW) == s)
        {
            strcpy(&result[i], newW);
            i += newWlen;
            s += oldWlen;
        }
        else
            result[i++] = *s++;
    }
 
    result[i] = '\0';
    return result;
}
void printarray(char *ar[], int n)
{
	for(int i=0; i<n; i++)
	{
		printf("%s\n", ar[i]);
	}
}
// Driver Program
int main()
{
    char *str[] = {"We will teach you tomorrow to...", "Move a mountain", "Level a Building", " Erase the past", "Make a million", "...all through C"} ;
    int no_of_elements=6;
    int i=0;
	char str1[20] , str2[20];
   
 
    // oldW string
    printf("Old strings:\n");
    printarray(str, no_of_elements);
    
     printf("\n\nfind:");
    scanf("%s", str1);
    printf("Replace by:\n\n");
    scanf("%s", str2);
    
 	for(int i=0; i<no_of_elements; i++)
	    str[i]=replaceWord(str[i], str1, str2);
    printf("New String: \n");
    printarray(str, no_of_elements);

    return 0;
}
