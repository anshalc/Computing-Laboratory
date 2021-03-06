#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
int i = 0; /* word letter index */
int j = 0; /* loop counter */
char word[256] = { 0 }; /* word from input */
int found = 0; /* censored word found */
int ch = getc(stdin); /* read first char */
/* loop to end of file */
while (ch != -1)
{
/* check for word */
if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch == '\''))
{
/* store char in word */
word[i] = (char)ch;
word[++i] = 0;
}
/* white space */
else
{
if (i > 0)
{
/* check for censor word */
found = 0;
for (j = 1; j < argc && found == 0; j++)
{
/* found */
if (strcmp(argv[j], word) == 0)
{
found = 1;
printf("CENSORED");
}
}
/* not found */
if (found == 0) printf("%s", word); //Printing value present in variable word
word[0] = 0; /* new word */
i = 0;
}
putc(ch, stdout); /* put white space */
}
  
ch = getc(stdin); /* get next char */
} /* end while */
return(0);
}