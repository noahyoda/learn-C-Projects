#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
void temp()
{
    int a = 320;
    char *ptr;
    ptr = (char *)&a;
    printf("%d", *ptr);
    printf("%d", &a);
}

void scrapewebpage(char *url)
{
    char *cmd = malloc(strlen(url) + strlen("wget -O - ") + 1);
    strcpy(cmd, "wget -O - ");
    strcat(cmd, url);
    printf("%d", cmd);
    system(cmd);
    free(cmd);
}

// function runs windscribe connect cmd and returns the output as a string
char* windscribe_connect(char* server)
{
    char* cmd = malloc(strlen("windscribe connect ") + strlen(server) + 1);
    strcpy(cmd, "windscribe connect ");
    strcat(cmd, server);
    printf("%d", cmd);
    FILE* pipe = popen(cmd, "r");
    if (!pipe)
    {
        return "ERROR";
    }
    char buffer[128];
    char* result = malloc(sizeof(char) * 128);
    while(!feof(pipe))
    {
        if(fgets(buffer, 128, pipe) != NULL)
        {
            strcat(result, buffer);
        }
    }
    pclose(pipe);
    free(cmd);
    return result;
}

// function downloads video from page into local file
void downloadvideo(char *url, char *filename)
{
    char *cmd = malloc(strlen(url) + strlen("wget -O ") + strlen(filename) + 1);
    strcpy(cmd, "wget -O ");
    strcat(cmd, filename);
    strcat(cmd, " ");
    strcat(cmd, url);
    system(cmd);
    free(cmd);
}
*/
// function lists all available com ports on windows device
void listcomports()
{
    char *cmd = malloc(strlen("wmic path Win32_SerialPort get DeviceID") + 1);
    strcpy(cmd, "wmic path Win32_SerialPort get DeviceID");
    printf("%d", cmd);
    FILE* pipe = popen(cmd, "r");
    if (!pipe)
    {
        return;
    }
    char buffer[128];
    while(!feof(pipe))
    {
        if(fgets(buffer, 128, pipe) != NULL)
        {
            printf("%s", buffer);
        }
    }
    pclose(pipe);
    free(cmd);
}

int main()
{
    char ch;
    //windscribe_connect("");
    //listcomports();

    //print newline character
    int i = 0;
    char* str;
    char str2[20];
    printf("give us a number\n");
    scanf("%d", &i);
    printf("you said %d\n", i);

    printf("and a string with a space\n");
    scanf("%s", &str);
    printf("%s\n", &str);

    printf("again please\n");
    fgets(str2, 20, stdin);
    printf("%s", str2);

    //downloadvideo("https://zoro.to/watch/k-project-1461?ep=20460", "test.mp4");
    
    return 0;
}