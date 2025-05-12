#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h> // <- để lấy exit code

#define HISTORY_FILE "history.txt"
#define MAX_CMD_LEN 1024
#define MAX_LINE_LEN 2048
int *p = NULL;
void show_stats()
{
    FILE *file = fopen(HISTORY_FILE, "r");
    if (!file)
    {
        perror("fopen");
        return;
    }

    char line[MAX_LINE_LEN];
    char commands[1000][MAX_CMD_LEN];
    int counts[1000] = { 0 };
    int unique = 0;

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "] ") && line[0] == '[')
        {
            char *cmd = strchr(line, ']') + 2;
            char clean_cmd[MAX_CMD_LEN];
            sscanf(cmd, "%[^\n]", clean_cmd);

            char *error_tag = strstr(clean_cmd, " [ERROR]");
            if (error_tag)
            {
                *error_tag = '\0';
            }

            if (strncmp(clean_cmd, "Note:", 5) == 0)
                continue;

            int found = 0;
            for (int i = 0; i < unique; i++)
            {
                if (strcmp(clean_cmd, commands[i]) == 0)
                {
                    counts[i]++;
                    found = 1;
                    break;
                }
            }
            if (!found && unique < 1000)
            {
                strcpy(commands[unique], clean_cmd);
                counts[unique++] = 1;
            }
        }
    }

    fclose(file);

    printf("\nCommand Usage Stats:\n");
    for (int i = 0; i < unique; i++)
    {
        printf("  %s: %d time(s)\n", commands[i], counts[i]);
    }
}

int main()
{
    printf("%p", p);
    show_stats();
    return 0;
}

