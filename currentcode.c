#include <stdio.h>
#include <string.h>

//counts frequency
void countFn(int sign, char* Name, int* count){
    int namelen = strlen(Name);
    for(int i=0;i<namelen;i++){
        if (Name[i]<='z' && Name[i]>= 'a')
            count[Name[i] - 'a'] += sign;
        else if (Name[i]<='Z' && Name[i]>= 'A')
            count[Name[i] - 'A'] += sign;
    }
}

//josephus problem
int find_index(int length, int n){
    if (length == 1)
        return 0;
    int survivor_index = (find_index(length - 1, n) + n) % length;
    return survivor_index;
}

int main()
{
    char Name1[50], Name2[50];
    printf("Name1: ");
    fgets(Name1, 50, stdin); // Read input for Name1

    printf("Name2: ");
    fgets(Name2, 50, stdin); // Read input for Name2

    int counts[26];
    countFn(1, Name1, counts); // adds frequency
    countFn(-1, Name2, counts); // subs frequency

    int len = 0;
    for(int i = 0; i < 26; i++)
        len += (counts[i] < 0) ? counts[i] * -1 : counts[i]; // adds only value to get count

    //output
    printf("You will end up as: ");
    int val = find_index(6, len); 
    if (val == 0) printf("Friend");
    else if (val == 1) printf("Love");
    else if (val == 2) printf("Affection");
    else if (val == 3) printf("Marriage");
    else if (val == 4) printf("Enemy");
    else printf("Siblings");
    return 0;
}
