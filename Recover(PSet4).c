#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage: ./recover FILE\n");
        return 1;
    }

    FILE* f = fopen(argv[1],"r");

    if (f == NULL)
    {
        printf("File Not Found!");
        return 1;
    }

    int i = 0; //to keep count of images

    FILE* img = NULL; //a file pointer that will be used to point to newly created jpg files

    char* filename = malloc(8*sizeof(char)); //string for filename

    uint8_t buffer[512]; //uint8_t because we'll read 1 byte at a time(since we have to check first four bytes, individually, to know if file is jpeg or not)

    //go through whole file
    while(fread(buffer,1,512,f)) //reading from f(pointer to file provided) to buffer 1 byte at a time, 512 bytes in total(since 1 block is of size 512 bytes)
    {
        //If file is jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //If new jpg file is found
            if (img != NULL)
            {
                fclose(img); //If img is not null, i.e. it is set to point to some file(in this case, previous jpg file), therefore we will close that file
            }

            sprintf(filename,"%03i.jpg",i++); //making a file

            img = fopen(filename,"w"); //setting img to point to newly created file

            //We will not WRITE into this file here
        }

        if (img != NULL) //To keep writing when no new jpg file is found
        {
            fwrite(buffer,1,512,img); //writing from buffer to jpg file
        }
    }

    //Close all opened files
    fclose(img);

    fclose(f);

    //free memory
    free(filename);

    return 0;
}
