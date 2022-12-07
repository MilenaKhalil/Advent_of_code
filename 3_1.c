#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* inp = fopen("3_inp", "r");
    char line[50] = {0};
    char* substr;
    int i = 0, amount = 0, k = 0;
    while (fgets(line, 50, inp))
    {
        printf("line[%04d]: %s", ++i, line);
        char letters[52] = {0};
        substr = &line[strlen(line) / 2];
        for (int j = 0; j < strlen(line) / 2; j++)
        {
            if (line[j] >= 'A' && line[j] <= 'Z')
                letters[line[j] - 'A' + 26] = line[j];
            else
                letters[line[j] - 'a'] = line[j];
        }
        while(k < strlen(line) / 2)
        {
            if ((substr[k] <= 'Z' && substr[k] >= 'A' && letters[substr[k] - 'A' + 26] != 0) 
                || (substr[k] <= 'z' && substr[k] >= 'a' && letters[substr[k] - 'a'] != 0))
                break;
            k++;
        }
        if (substr[k] >= 'A' && substr[k] <= 'Z')
            amount += 1 + substr[k] - 'A' + 26;
        else
            amount += 1 + substr[k] - 'a';
        printf("amount == %d, substr[k] = %c\n", amount, substr[k]);
        k = 0;
    }
    fclose(inp);
    return 0;
}
