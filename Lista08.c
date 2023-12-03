#include <stdio.h>
#include <stddef.h>
#include <strings.h>



int file_exists(const char* filepath){
    FILE* file = fopen(filepath, "r");
    if (file == NULL){
        printf("ERRO: Arquivo não existe ou não foi encontrado. \n");
        return 0;

    }

    return 1;

}


int check_or_create(const char* filepath){
    FILE* file = fopen(filepath, "a");
    return 1;
}

int print_content(const char* filepath){

    FILE* file = fopen(filepath, "r");
    int a = file_exists(filepath);


    if(a){


        char ch = fgetc(file);

        while(ch != EOF){
            printf("%c", ch);
            ch = fgetc(file);

        }
        printf("\n");

    }



    return a;


}


int count_lines(const char* filepath){

    FILE* file = fopen(filepath, "r");

    char ch = fgetc(file);
    int count = 0;


    while(ch != EOF){
        if(ch == '\n'){
            count++;
        }

        ch = fgetc(file);

    }
    count += 1;
    printf("Este texto tem %d linhas!\n", count);

}


int save_string(const char* filepath, const char* text){

    FILE* file = fopen(filepath, "w");

    for(int i = 0; text[i] != '\0'; i++){
        fputc(text[i], file);

    }
    

}

int append_string(const char* filepath, const char* text){

    FILE* file = fopen(filepath, "a");


    for(int i = 0; text[i] != '\0'; i++){
        fputc(text[i], file);
    }
}



int add_string(const char *filepath, const char** text_lines){
    FILE* file = fopen(filepath, "w+");

    for(int i = 0;  **text_lines != '\0'; i++){
        fputc(**text_lines, file);
        printf("\n");
    }

}


int main(){

    // EX 01 //

    // char filepath[100] = "/home/pedro/Documents/Faculdade/programacao/C/arquivos.txt" ;
    // int d = file_exists(filepath);
    // printf("%d\n", d);

    // EX 02 //

    // char filepath[100] = "/home/pedro/Documents/Faculdade/programacao/C/arquivos.txt" ;
    // int a = check_or_create(filepath);
    // printf("%d\n", a);

    // EX 03 //

    // char filepath[100] = "/home/pedro/Documents/Faculdade/programacao/C/arquivo.txt" ;
    // print_content(filepath);

    // EX 04 //

    // char filepath[100] = "/home/pedro/Documents/Faculdade/programacao/C/arquivo.txt" ;
    // count_lines(filepath);

    // EX 05 //

    // char filepath[100] = "/home/pedro/Documents/Faculdade/programacao/C/arquivo.txt" ;
    // char text[50] = "Olá, mundo!";
    // save_string(filepath, text);

    // EX 06 //

    // char filepath[100] = "/home/pedro/Documents/Faculdade/programacao/C/arquivo.txt" ;
    // char text[50] = "Olá, mundo!";
    // append_string(filepath, text);

    // EX 07 //
    char filepath[100] = "/home/pedro/Documents/Faculdade/programacao/C/arquivo.txt" ;
    char text[50][50] = {"Olá, mundo!","Olá, mundo!","Olá, mundo!","Olá, mundo!","Olá, mundo!","Olá, mundo!","Olá, mundo!","Olá, mundo!","Olá, mundo!","Olá, mundo!","Olá, mundo!","Olá, mundo!"} ;
    add_string(filepath, text);


    return 0;
}