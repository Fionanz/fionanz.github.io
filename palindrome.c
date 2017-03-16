#include <stdio.h>
#include <string.h>

#define WORD_LENGTH 51
#define WORDS_DICTIONARY 3

static const char dictionary[WORDS_DICTIONARY][WORD_LENGTH] = 
{
	{"aaaabaaaa"},
	{"gidedgide"},
	{"listen"},
};

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

// anagram analyse
// look up the dictionary
int is_anagram_or_not(char word[], int length)
{
	int i,j,k;
	int len_dic;
	char temp;
	int is_find = 0;

	for (i = 0; i < WORDS_DICTIONARY; i ++)
	{
		// already find an anagram
		if (is_find) break;

		len_dic = get_string_length(dictionary[i]);
		//printf("sizeof dictionary[%d] is %d ***\n", i, len_dic);
		
		// not an anagram 
		if (length != len_dic) continue;

		for (j = 0; j < len_dic; j++)
		{
			is_find = 0;
			for (k = j; k < length; k++)
			{
				//swap word[k] and word[j]
				if (dictionary[i][j] == word[k])
				{
					temp = word[k];
					word[k] = word[j];
					word[j] = temp;
					is_find = 1;
					break;
				}
			}
			if (!is_find)  // did not find the letter
			{
				break;
			}
		}
	}

	return is_find;
}

void analyse(char str[], int len)
{
	if (is_palindrome_or_not(str, len))
	{
		printf("    is true\n");
	}
	else if (is_anagram_or_not(str, len))
	{
		printf("    is true\n");
	}
	else
	{
		printf("    is false\n");
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

	for (i = 0; i < WORDS_DICTIONARY; i++)
	{
		for (j = 0; j < sizeof(dictionary[i]); j++)
		{
			printf("%c", dictionary[i][j]);
			if (0 == dictionary[i][j]) break;
		}
		printf("\n");
	}
	
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