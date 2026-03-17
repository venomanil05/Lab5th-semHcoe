#include <stdio.h>
#include <string.h>

int main() {
    char pt[100],ct[100],decryptedtext[100];
    int rails, length, row, direction,k=0;

     printf("-----Railfence Cipher-----");
    printf("\nEnter Plaintext: ");
    scanf("%s",pt);


    pt[strcspn(pt, "\n")] = '\0';

    printf("Enter the number of rails: ");
    scanf("%d", &rails);

    length = strlen(pt);

    char rail[rails][length];

    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < length; j++) {
            rail[i][j] = ' ';
        }
    }
    row = 0;
    direction = 1;


    for (int i = 0; i < length; i++) {
        rail[row][i] = pt[i];


        if (row == 0) {
            direction = 1;
        } else if (row == rails - 1) {
            direction = -1;
        }

        row += direction;
    }


    printf("-------------Encryption-----------\n");
    printf("plaintext is:");
    puts(pt);
    printf("railsize is:%d",rails);
    printf("\nCipher text: ");
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < length; j++) {
            if (rail[i][j] != ' ') {
                printf("%c", rail[i][j]);
                ct[k]=rail[i][j];
                k++;
            }
        }
    }
    printf("\n");
    ct[k]='\0';

    //Decryption:
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < length; j++) {
            rail[i][j] = ' ';
        }
    }


    row = 0;
    direction = 1;
    for (int i = 0; i < length; i++) {
        rail[row][i] = '*';
        if (row == 0) direction = 1;
        else if (row == rails - 1) direction = -1;
        row += direction;
    }


    k = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < length; j++) {
            if (rail[i][j] == '*') {
                rail[i][j] = ct[k++];
            }
        }
    }

    row = 0;
    direction = 1;
    k = 0;
    for (int i = 0; i < length; i++) {
        decryptedtext[k++] = rail[row][i];
        if (row == 0) direction = 1;
        else if (row == rails - 1) direction = -1;
        row += direction;
    }
    decryptedtext[k] = '\0';
    printf("-------------Decryption-----------");
    printf("\nciphertext is:");
    puts(ct);
    printf("\nrailsize is:%d",rails);
    printf("\nPlaintext is: %s", decryptedtext);
    return 0;
}
