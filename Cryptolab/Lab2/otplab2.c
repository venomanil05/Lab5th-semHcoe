#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    char pt[100], ct[100], key[100];
    int i, ptlen;

    printf("\n------OTP Cipher------");

    printf("\nEnter Plaintext: ");
    scanf("%s", pt);

    ptlen = strlen(pt);

    srand(time(0));

    for(i=0;i<ptlen;i++)
    {
        key[i] = (rand()%26) + 97;
    }
    key[i]='\0';

    printf("\nRandom Generated Key: %s", key);

    printf("\n----Encryption----");
     printf("\nplaintext is:");
     puts(pt);
    for(i=0;i<ptlen;i++)
    {
        ct[i] = (((pt[i]-97) + (key[i]-97)) % 26) + 97;
    }
    ct[i]='\0';

    printf("Cipher Text: %s", ct);

    printf("\n-----Decryption-----");
     printf("\ncipher text is:");
     puts(ct);
    for(i=0;i<ptlen;i++)
    {
        pt[i] = (((ct[i]-97) - (key[i]-97) + 26) % 26) + 97;
    }
    pt[i]='\0';

    printf("Plaintext is: %s", pt);

    return 0;
}
