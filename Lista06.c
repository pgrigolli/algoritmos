#include <stdlib.h>
#include <stdio.h>
#include <string.h>




void print_basic(){
    
    char letra = 'A';
    int num = 5;
    double num_grande = 8171238;
    



    printf("%c | %p \n", letra, &letra);
    printf("%d | %p \n", num, &num);
    printf("%f | %p \n", num_grande, &num_grande);

};

void add_basic(int* a, int* b){
    *a += *b;
    printf("%d\n", *a);


};

void print_vet(int n, const int* v){
    int count = 0;

    while(count < n){
        printf("%d ", *v);
        v += 1;
        count++;

    }
    printf("\n");

}

void printf_vet_reversed(int n, const int* v){
    v += n - 1;
    for(int i = 0; i < n; i++){

        printf("%d ", *v);
        v--;
    }

}


void get_min_max(int n, const int* v,int* min, int* max){

    *max = 0;
    *min = 50;
    for(int i = 0; i < n; i++){
        if(*v < *min){
            *min = *v;
        }
            
        if(*v > *max) {
            *max = *v;
        }
        v++;
    }

}

void print_vector2D(int rows, int cols, const int* v){
    int count = 0;
    for(int i = 0; i < (rows * cols); i++){
        if(count == cols){
            printf("\n");
            count = 0;
        }
        printf("%0d ", *v);
        v++;
        count++;
    }
    printf("\n");
}


void reverse_string(char* start, char* end) {
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}


void make_mirrored(char* str){

    for(; *str != '\0'; str++);

    *str = '|';
    char *reversed = str--;

    for(; *reversed != '\0'; reversed--){
        str++;
        *str = *reversed;  
    }

}

int get_humming_distance(const char* str1, const char* str2){

    int humming = 0;

    for(;*str1 != '\0';){
        if(*str1 != *str2){
            humming++;
        }
        str1++;
        str2++;
    }
    printf("%d\n", humming);
    return humming;
}

char* find_most_similar(const char* str, int n, char list[][50]){

        int distance = 0;
        int min = 0;
        int idx = 0;

    for(int i = 0; i < n; i++){
        distance = get_humming_distance(str, list[i]);
        if(min < distance){
            min = distance;
            idx = i;
        }

    }

    return list[idx];


}

struct rect {
int x, y, width, height; // é possível declarar os campos em uma só linha
};
typedef struct rect Rect;


void print_board(Rect* board){
    int count = 0;
    for(int i = 0; i < board->y; i++){
        printf(" \n");
    }

    for(int i = 0; i < board->width; i++){
        for(int j = 0; j < board->x; j++){
            printf(" ");
        }

        for(int k = 0; k < board->width; k++){
            printf("XX");

        }
        printf("\n");
    }


}

struct point {
int x, y; // é possível declarar os campos em uma só linha
char symbol;
};
typedef struct point Point;


void print_board2(Rect* board, Point* ponto){
    int count = 0;
    for(int i = 0; i < board->y; i++){
        printf(" \n");
    }

    for(int i = 0; i < board->width; i++){
        for(int j = 0; j < board->x; j++){
            printf(" ");
        }

        for(int k = 0; k < board->width; k++){
            if(i == ponto->y && k == ponto->x){
                printf("%c%c", ponto->symbol, ponto->symbol);
            }else{

            printf("XX");
            }

        }
        printf("\n");
    }


}


int main(){

    int a = 5;
    int b = 10;
    int *p_a = &a;
    int *p_b = &b;

    int v[] = {1,2,3,4,5};



    int min, max;

    int v2[3][4] = {
                    {1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12}
                    };


    char name[40] = "John Doe";
    
    
    char list[][50] = {"banana","cabana","bacana", "halana", "savana"};

    Rect board = {5,5,10,10};
    Rect * p_board = &board;

    Point ponto = {0,0,'A'};
    Point * p_ponto = &ponto;

    print_board2(p_board, p_ponto);

}