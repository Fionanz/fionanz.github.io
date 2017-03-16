#include <stdio.h>
#include <string.h>

#define WORD_LENGTH 51


// return string length when meet the first '\0' 
int get_string_length(char word[])
{
	int m;

	for ( m = 0; m < WORD_LENGTH; m++)
	{
		if (word[m] == 0) 
		{
			break;
		}
	}
	return m;
}

// palindrome analyse
int is_palindrome_or_not(char word[], int length) 
{
  int m = 0;
  int n = length;

  for (m = 0; m < n/2; m++) 
  {
      if(word[m] != word[n-m-1]) 
	  {
        return 0;
      }
      else 
	  {
        continue;
      }
  }

  return 1;
}

// an anagram of a palindrome analyse
// look up the dictionary
int is_anagram_of_palindrome_or_not(char word[], int length)
{
	int i,j,k;
	int len_dic;
	char temp;

	int count[26];
	int oddChar = 0;

	memset(count, 0, sizeof(count));

	for (i = 0; i < length; i ++)
	{
		temp = word[i];
		count[temp - 'a']++;
	}
	
	// a~z counter
	for(i = 0; i < 26; i++ )
    {
		if( oddChar > 1) // more than 1 char should have odd frequency
			return 0;
           
        if( count[i] % 2 == 1 )
            oddChar++;
    }

	return 1;
}

void analyse(char str[], int len)
{
	if (is_palindrome_or_not(str, len))
	{
		printf("    is a palindrome\n");
	}
	else if (is_anagram_of_palindrome_or_not(str, len))
	{
		printf("    is an anagram of a palindrome \n");
	}
	else
	{
		printf("    is neither\n");
	}
}

void test()
{
	printf("\"anna\"");
	analyse("anna", sizeof("anna") - 1);

	printf("\"aaaaaaaa\"");
	analyse("aaaaaaaa", sizeof("aaaaaaaa") - 1);

	printf("\"aaaaaaaab\"");
	analyse("aaaaaaaab", sizeof("aaaaaaaab") - 1);

	printf("\"caaaaaaaab\"");
	analyse("caaaaaaaab", sizeof("caaaaaaaab") - 1);

	printf("\"donotbobtonod\"");
	analyse("donotbobtonod", sizeof("donotbobtonod") - 1);

	printf("\"owefhijpfwai\"");
	analyse("owefhijpfwai", sizeof("owefhijpfwai") - 1);

	printf("\"igdedgide\"");
	analyse("igdedgide", sizeof("igdedgide") - 1);

}


void main()
{
	char str[WORD_LENGTH];
	int length;
	int i, j;

	while(1)
	{

		printf("Enter a string(no more than 50 letters) : \n");
		printf("if enter *, automatic test will be executed.\n");
		scanf("%s", str);

		length = get_string_length(str);

		if (1 == length && '*' == str[0]) 
		{
			test();
		}
		else
		{

			printf("You entered: %s, length is %d", str, length);
			analyse(str, length); 
		}
		
	}	
}