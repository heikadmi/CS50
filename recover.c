#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE; 
int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage problemcard.raw\n");
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    
    BYTE buffer[512];
    int count = 0;
    char filename[13];
    FILE *img = NULL;
    while (fread(&buffer, sizeof(BYTE), 512, file))
    {

        
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count == 0)
            {
                sprintf(filename, "%03i.jpg", count);
                img = fopen(filename, "w");
                count++;
                fwrite(&buffer, sizeof(BYTE), 512, img);
            }
            else
            {
                fclose(img); 
                sprintf(filename, "%03i.jpg", count);
                img = fopen(filename, "w");
                count++;
                fwrite(&buffer, sizeof(BYTE), 512, img);
            }
        }
        else
        {
            if (!img)
            {
            }
            else
            {        
                fwrite(&buffer, sizeof(BYTE), 512, img);
            }
        }
    }
    fclose(file);
    fclose(img);
}