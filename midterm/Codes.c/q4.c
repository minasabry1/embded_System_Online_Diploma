#include <stdio.h>
void reverseSentence();
int main() {
    printf("Enter the Numbers: \r\n");
    reverseSentence();
    printf("\r\n");
    printf("Enter the second Numbers: \r\n");
    reverseSentence();
    return 0;
}

void reverseSentence() {
    char c;
    scanf("%c", &c);
    if (c != '\n') {
        reverseSentence();
        printf("%c", c);
    }
}
