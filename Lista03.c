#include <stdio.h>
#include <string.h>

// #include "LISTA02.C"



int print_function(int n, int v[]){
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}


int str_len(char str[]){
    int length = 0; 

    for(int i = 0; str[i] != '\0'; i++){
        length++;
    }

    return length;
}


void print_string(char str[]){
    for (int i = 0; str[i] != '\0'; i++){
        printf("%c ", str[i]);
        printf("\b");
    }
}


void print_string_reversed1(char str[]){
    int len = strlen(str);
    for (int i = len; i >= 0; i--){
        printf("%c", str[i]);
    }
}

void print_string_reversed2(char str[]){
    int i = 0;
    int len = 0;
    while (str[i] != '\0'){
        len++;
        i++;
    }
    for (int j = len; j >= 0; j--){
        printf("%c", str[j]);
    }
}

void print_hyphenated(char str[], char separator){
    for (int i = 0; str[i] != '\0'; i++){
        printf("%c", str[i]);
        printf("%c", separator);

    }
    printf("\b ");


}


void string_report(char str[]){
    int letra = 0;
    int digito = 0;
    int simbolo = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] >= 65 && str[i] <= 90){
            letra++;
        }
        if (str[i] >= 97 && str[i] <= 122){
            letra++;
        }
        if (str[i] >= 48 && str[i] <= 57){
            digito++;
        }
        if (str[i] >= 32 && str[i] <= 47){
            simbolo++;
        }
        if (str[i] >= 58 && str[i] <= 64){
            simbolo++;
        }
        if (str[i] >= 91 && str[i] <= 96){
            simbolo++;
        }
        if (str[i] >= 123 && str[i] <= 126){
            simbolo++;
        }
    }

    printf("%d letras, %d digitos e %d simbolos.", letra, digito, simbolo);

}


char string_to_upper(char str[]){
    for(int i = 0; str[i] != '\0'; i++){
        if (str[i] >= 97 && str[i] <= 122){
            str[i] -= 32;
        }
    }

}

int strcmp_plus(char s1[], char s2[]){

    int max = 0;
    string_to_upper(s1);
    string_to_upper(s2);


    printf("%d", strcmp(s1, s2));

}


int count_words(char str[]){
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == ' ' || str[i] == '\0'){
            count++;
        }
    }
    count++;
    printf("%d", count);
}

int count_words_plus(char str[]){

    int i = 0, word_started = 0, words = 0;


    while (str[i] != '\0'){
        if (word_started == 1 && str[i] == ' '){
            words++;
            word_started = 0;
        }
        else if(str[i] != ' '){
            word_started = 1;
        }
        i++;
    }
    words++;
    printf("%d ", words);
}

void string_capitalize(char str[]){

    int i = 0;

    while(str[i] != 0){

        if (i == 0 && str[i] > 96){
            str[i] -= 32;
        }

        else if (str[i] >= 65 && str[i] <= 90){
            str[i] += 32;
        }

        else if (str[i] != ' ' && str[i - 1] == ' ' && str[i] > 96){
            str[i] -= 32;
        }

        i++;
        
    }

    print_string(str);

}

int string_compare (char str1[], char str2[]){

    string_to_upper(str1);
    string_to_upper(str2);


    for (int i = 0; str1[i] != '\0'; i++){
        if(str1[i] != str2[i]){
            if (str1[i] < str2[i]){
                return -1;
            }
            else{
                return 1;
            }
        }
        else{
            continue;
        }
    }
    return 0;


}



void string_counter(char str[]){
    int count[26] = {0}; // Lista com str posições
    string_to_upper(str);
    int len = 0; 
    float porc = 0;

    for(int j = 0; str[j] != '\0'; j++){
        if (str[j] != ' '){
            len++;
        }
    }
    for (int i = 0; str[i] != '\0'; i++){ // Add qtde de vezes em count
        count[str[i] - 65] += 1;
    }

    for (int l = 0; l < 26; l++){

        porc = (count[l] / (float)len) * 100;

        if (count[l] != 0){   
        printf("%c x%d (%.2f)\n", l + 65, count[l], porc);
        }

    }

}

// void string_trim(char str[]){

//     for(int i = 1; str[i] != '\0'; i++){
//         if (str[i] )
//     }
// }


int find_substring(char str[], char sub[]){
    int i = 0, j = 0;
    while (str[i] != '\0'){

        while (sub[j] != '\0'){

            if (sub[j] != str[i]){
                j = 0;
                break;
            }
            j++;
            i++;
        }
        if (sub[j] == 0){
            return 1;
        }
        i++;
    }
    return 0;
}
int main(){
    char str1[] = "Ola Mundo";
    char sub[] = "Munde";
    printf("%d", find_substring(str1, sub));
}