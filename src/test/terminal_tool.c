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

void get_time(char *buffer, size_t size)
{
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, size, "%H:%M:%S", t);
}

void write_history(const char *cmd, const char *note, int is_error)
{
    int fd = open(HISTORY_FILE, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1)
    {
        perror("open");
        return;
    }

    // Lock file
    struct flock lock = { F_WRLCK, SEEK_SET, 0, 0 };
    fcntl(fd, F_SETLKW, &lock);

    FILE *file = fdopen(fd, "a");
    if (!file)
    {
        perror("fdopen");
        close(fd);
        return;
    }

    char timebuf[16];
    get_time(timebuf, sizeof(timebuf));
    fprintf(file, "[%s] %s", timebuf, cmd);
    if (is_error)
    {
        fprintf(file, " [ERROR]");
    }
    fprintf(file, "\n");

    if (note && strlen(note) > 0)
    {
        fprintf(file, " Note: %s\n", note);
    }

    fflush(file);
    fclose(file); // also unlocks
}

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

            // Bỏ phần [ERROR] nếu có
            char *error_tag = strstr(clean_cmd, " [ERROR]");
            if (error_tag)
            {
                *error_tag = '\0'; // Cắt bỏ phần [ERROR]
            }

            // Bỏ qua dòng ghi chú
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
    printf("Command Tool started! Type 'end_tool_command' to stop.\n");

    char input[MAX_CMD_LEN];
    char last_command[MAX_CMD_LEN] = "";

    while (1)
    {
        printf("> ");
        fflush(stdout);

        if (!fgets(input, sizeof(input), stdin))
            break;
        input[strcspn(input, "\n")] = '\0'; // Remove newline

        if (strcmp(input, "end_tool_command") == 0)
        {
            break;
        }
        else if (strcmp(input, "cmt") == 0)
        {
            printf(" Enter note: ");
            char note[MAX_CMD_LEN];
            if (fgets(note, sizeof(note), stdin))
            {
                note[strcspn(note, "\n")] = '\0';
                write_history(last_command, note, 0);
            }
        }
        else
        {
            int ret = system(input);
            int is_error = 0;
            if (WIFEXITED(ret) && WEXITSTATUS(ret) != 0)
            {
                is_error = 1;
            }
            write_history(input, NULL, is_error);
            strcpy(last_command, input);
        }
    }

    show_stats();
    return 0;
}
