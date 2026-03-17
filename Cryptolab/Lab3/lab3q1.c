//program to generate 16 round key in DES
#include <stdio.h>
#include <string.h>

unsigned char key[8] = {0x13,0x34,0x56,0x78,0x90,0xAB,0xCD,0xEF};
unsigned char roundKeys[16][6];

unsigned char PC1[56] = {
57,49,41,33,25,17,9,1,58,50,42,34,26,18,
10,2,59,51,43,35,27,19,11,3,60,52,44,36,
63,55,47,39,31,23,15,7,62,54,46,38,30,22,
14,6,61,53,45,37,29,21,13,5,28,20,12,4};

unsigned char PC2[48] = {
14,17,11,24,1,5,3,28,15,6,21,10,
23,19,12,4,26,8,16,7,27,20,13,2,
41,52,31,37,47,55,30,40,51,45,33,48,
44,49,39,56,34,53,46,42,50,36,29,32};

unsigned char SHIFT_SCHEDULE[16] =
{1,1,2,2,2,2,1,2,2,2,2,2,1,2,2,1};

unsigned char leftShift(unsigned char value,int shifts)
{
    return ((value<<shifts)|(value>>(8-shifts))) & 0xFF;
}

void permute(unsigned char *input,unsigned char *output,
             unsigned char *permutation,int length)
{
    for(int i=0;i<length;i++)
    {
        int bit=permutation[i]-1;
        output[i/8] |= ((input[bit/8]>>(7-(bit%8)))&1)<<(7-(i%8));
    }
}

void printBinary(unsigned char *data,int bytes)
{
    for(int i=0;i<bytes;i++)
    {
        for(int j=7;j>=0;j--)
        {
            printf("%d",(data[i]>>j)&1);
        }
        printf(" ");
    }
}

void generateRoundKeys()
{
    unsigned char permutedKey[7]={0};
    permute(key,permutedKey,PC1,56);

    printf("\nKey After PC1 Permutation:\n");
    printBinary(permutedKey,7);
    printf("\n\n");

    unsigned char left[4]={0},right[4]={0};

    memcpy(left,permutedKey,4);
    memcpy(right,permutedKey+4,3);

    printf("Initial Left Half:\n");
    printBinary(left,4);
    printf("\n");

    printf("Initial Right Half:\n");
    printBinary(right,4);
    printf("\n\n");

    for(int round=0;round<16;round++)
    {
        left[0]=leftShift(left[0],SHIFT_SCHEDULE[round]);
        right[0]=leftShift(right[0],SHIFT_SCHEDULE[round]);

        unsigned char combined[8]={0};
        memcpy(combined,left,4);
        memcpy(combined+4,right,4);

        permute(combined,roundKeys[round],PC2,48);
    }
}

int main()
{
    printf("Original Key (in Hex): ");
    for(int i=0;i<8;i++)
        printf("%02X ",key[i]);

    printf("\nOriginal Key (in Binary):\n");
    printBinary(key,8);
    printf("\n");

    generateRoundKeys();

    printf("\n---- Round Keys ----\n");
    for(int i=0;i<16;i++)
    {
        printf("Round %2d Key : ",i+1);
        printBinary(roundKeys[i],6);
        printf("\n");
    }
     printf("Name:Anil Pal ROll no:5");
    return 0;
}
