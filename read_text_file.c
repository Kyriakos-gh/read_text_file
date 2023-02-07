/*
    read_text_file.c : Reads a text file and shows its contents line by line
    Kyriakos, 12/1/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_SIZE 20
#define BUFFER_SIZE 200

int main(int argc, char *argv[])
{
    char filename[FILENAME_SIZE];
    char line_buffer[BUFFER_SIZE];
    FILE *fp;

    if(argc != 2) {
        printf("Please enter filename to read: ");
        scanf("%s", &filename);
    }
    else {
        strcpy(filename, argv[1]);
    }

    fp = fopen(filename, "r");
    if(fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    printf("\nContents of file %s :\n\n", filename);
    while(fgets(line_buffer, sizeof(line_buffer), fp)) {
        printf("%s", line_buffer);
    }

    fclose(fp);
    return 0;
}
