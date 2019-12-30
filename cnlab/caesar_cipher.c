#include <stdio.h>
#include <string.h>

#define key 2

int main()
{
	int i;
	char str[50], c;
	FILE *fp = fopen("input.txt", "r");

	fgets(str, sizeof(str), fp);
	printf("Original message :\n\t%s\n", str);

	for (i = 0; str[i] != '\0'; i++)
	{
		c = str[i] + key;
		if (str[i] >= 48 && str[i] <= 57)
		{
			if (c > 57)
				c = 47 + (c - 57) % 10;
			str[i] = c;
		}
		else if (str[i] >= 65 && str[i] <= 90)
		{
			if (c > 90)
				c = 64 + (c - 90) % 26;
			str[i] = c;
		}
		else if (str[i] >= 97 && str[i] <= 122)
		{
			if (c > 122)
				c = 96 + (c - 122) % 26;
			str[i] = c;
		}
	}
	printf("Encoded message :\n\t");
	puts(str);

	for (i = 0; str[i] != '\0'; i++)
	{
		c = str[i] - key;
		if (str[i] >= 48 && str[i] <= 57)
		{
			if (c < 48)
				c = 58 - (48 - c) % 10;
			str[i] = c;
		}
		else if (str[i] >= 65 && str[i] <= 90)
		{
			if (c < 65)
				c = 91 - (65 - c) % 26;
			str[i] = c;
		}
		else if (str[i] >= 97 && str[i] <= 122)
		{
			if (c < 97)
				c = 123 - (97 - c) % 26;
			str[i] = c;
		}
	}

	printf("Decoded message :\n\t");
	puts(str);
	fclose(fp);

	return 0;
}
