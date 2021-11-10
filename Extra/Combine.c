#include <stdio.h>
#include "..\code\base\typeConfig.h"

/*
*   small program to combine multiple hex files into one
*   Remember to pass the different filenames in the order 
*   you want them combined (mind the endianness!)
*   argc = number of parameters
*   argv[n] = filenames + resultantfilename
*   remember that argv[0] is always the program name.
*/

int main(int argc, char**argv)
{
    int arrlen = argc - 1;
    FILE *result = fopen(argv[arrlen],"wb");

    for(int i = 1; i < arrlen; ++i){
        FILE *f = fopen(argv[i], "rb");
        printf("Copying %s...\n",argv[i]);
        int c = fgetc(f);
        while(c != EOF){
            fputc(c, result);
            c = fgetc(f);
        }
        fclose(f);
    }
    fclose(result);
    return 0;
}