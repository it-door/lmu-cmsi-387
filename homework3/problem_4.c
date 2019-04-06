#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

void runtime(clock_t begin)
{
    clock_t end = clock();
    double elapsed_time = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Program ran for %fs\n", elapsed_time);
}

int main(int argc, char **argv)
{
    int file = open(argv[1], O_RDONLY, S_IRUSR | S_IWUSR);
    struct stat toRead;

    if (fstat(file, &toRead) == -1)
    {
        perror("Invalid file size. Did you pass in a file as first argument?\n");
    }

    printf("Welcome to our file mapper! We will now check for an X in your file.\n");
    printf("Characters in file: %lld\n", toRead.st_size);

    char *memoryFile = mmap(NULL, toRead.st_size, PROT_READ, MAP_PRIVATE, file, 0);

    clock_t begin = clock();
    for (int i = 0; i < toRead.st_size; i++)
    {
        if (memoryFile[i] == 'X')
        {
            printf("An 'X' was located in the file at character %d! Ending program.\n", i);
            close(file);
            runtime(begin);
            return 0;
        }
    }
    printf("No 'X's found. Ending program.");
    close(file);
    runtime(begin);
    return 0;
}