#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>



struct Point
{
    float x;
    float y;
};
typedef struct Point Ponto;


struct Contact{
    int id;
    char name[51];
    char email[51];
    int type;

};

typedef struct Contact Contato;

struct employee{
    char name[50];
    float salary;
    int type; // 0 - Developer, 1 - Designer, 2 - Manager, 3 - Support
};

typedef struct employee Empregado;

Ponto print_function(int n, Ponto v[]){
    for (int i = 0; i < n; i++){
        printf("Ponto %d: x:%f ", i, v[i].x);
        printf("Ponto %d: y:%f ", i, v[i].y);
        printf("\n");
    }
}


float distance2D(Ponto p1, Ponto p2){

    float distance = sqrt((pow((p2.x - p1.x),2)) + (pow((p2.y - p1.y),2)));

    return distance;
}

float distance_vector(int n, Ponto v[]){

    for(int i = 0; i < n - 1; i++){
        printf("A distancia entre o ponto %0.2f %0.2f e o ponto %0.2f %0.2f é %f\n", v[i].x, v[i].y, v[i + 1].x, v[i + 1].y, distance2D(v[i], v[i + 1]));
        
    }
    printf("\n");
}


void random_points(int n, Ponto v[]){
    for(int i = 0; i < n; i++){
        float random_float_x = (rand()/(float)RAND_MAX) * 100 - 100/2.0f;
        float random_float_y = (rand()/(float)RAND_MAX) * 100 - 100/2.0f;
        v[i].x = random_float_x;
        v[i].y = random_float_y;
    }
    print_function(n, v);
}

void nearest_points(int n, Ponto v[]){

    int i = 0;
    int j = 1;
    float distance_min = INT_MAX;
    int p1 = 0;
    int p2 = 0;

    for(; i < n - 1; i++){
        
        if(distance2D(v[i], v[i]) < distance_min){
            distance_min = distance2D(v[i], v[i + 1]);
            p1 = i;
            p2 = i + 1;

        }

    }
    printf("A menor distancia da lista é entre os pontos %f %f e %f %f, que é %f", v[p1].x, v[p1].y, v[p2].x, v[p2].y, distance_min);

}

void print_contact(Contato c, int n, char type_name[n][50]){

    int tipo = c.type;


    printf("ID: %d\n" 
            "Nome: %s\n" 
            "Email: %s\n" 
            "Tipo: %s\n", c.id, c.name, c.email, type_name[tipo]);

}

void print_contact_list(int n1, Contato list[n1], int n2, char types[n2][50]){
    printf("\n");
    for(int i = 0; i < n2; i++){
        printf("%s\n", types[i]);
        for(int j = 0; j < n1; j++){

        if(list[j].type == i){
            printf("\n");
            printf("    %s\n"  
                   ,list[j].name);

        }

        }
        printf("\n");
    }
}


void employees_report(int n, Empregado v[n]){
    int salario = 0;
    for(int i = 0; i < n; i++){
        salario += v[i].salary;
    }
    float media_salarios = (float)salario/n;

    printf("A media dos salarios é %.2f\n", media_salarios);

    int n1 = 4;
    char tipos[4][50] = {"Developer","Designer","Manager","Support"};

    float media_salario_tipo = 0;
    int count = 0;

    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n; j++){
            if(v[j].type == i){
                media_salario_tipo += v[j].salary;
                count++;

            }
        }
        media_salario_tipo = media_salario_tipo/(float)count;
        count = 0;
        printf("\nMedia %s é %.2f\n", tipos[i], media_salario_tipo);
        media_salario_tipo = 0;
    }

};
void print_best3(int n, Empregado v[n]){

    int m[3] = {0,0,0};
    int max = 0;

    for(int i = 0; i < n; i++){
        if(v[i].salary > max){
        max = v[i].salary;
        m[0] = i;
        }

    }
    max = 0;

    for(int i = 0; i < n; i++){
        if(v[i].salary > max && v[i].salary < v[m[0]].salary){

        max = v[i].salary;
        m[1] = i;
        }

    }
    max = 0;

    for(int i = 0; i < n; i++){
        if(v[i].salary > max && v[i].salary < v[m[1]].salary){

        max = v[i].salary;
        m[2] = i;
        }

    }

    for(int i = 0; i < 3; i++){
        printf("%s\n", v[m[i]].name);
    }

};

int is_upper(char c) {
    return (c >= 'A' && c <= 'Z');
}

int is_lower(char c) {
    return (c >= 'a' && c <= 'z');
}

int is_letter(char c) {
    return is_lower(c) || is_upper(c);
}

void fix_name(char name[]){
    int len = strlen(name);
    int count = 0;
    for (int i = 0; i<len; i++){
        if (is_letter(name[i]) || (name[i]==' ' && is_letter(name[i+1]))){
            count++;
        }
    }
    char temp[count+1];
    temp[count] = '\0';
    /*
    "  JOHn DOE# 32!  "
         i
    " JOH         "
         j   
    */
    int j = 0;
    for (int i = 0; name[i]!='\0'; i++){
        if (is_letter(name[i]) || (name[i]==' ' && is_letter(name[i+1]))){
            temp[j]=name[i];
            j++;
        }
    }
    for (int i = 0; temp[i]!='\0'; i++){
        if (is_upper(temp[i])){ 
            temp[i]+=32;
        }
    }

    for (int i = 0; temp[i]!='\0'; i++){
        if (is_lower(temp[i]) && i > 0 && temp[i-1]==' '){ 
            temp[i]-=32;
        }
    }

    // se primeiro for letra
    if (is_lower(temp[0])){
        temp[0]-=32;
    // se primeiro for espaço
    } else {
        for (int i = 0; temp[i] != 0; i++) {
            temp[i] = temp[i+1];
        }
    }
    strcpy(name,temp);
}




Contato create_contact(int id, char name[], int type){

    Contato novo_contato;

    novo_contato.id = id;

    strcpy(novo_contato.name, name);

    novo_contato.type = type;

    // char name_cpy1[50] = strcpy(name_cpy1, name );

    fix_name(name);

    for(int i = 0; name[i] != '\0'; i++){
        if(name[i] >= 65 && name[i] <= 90){
            name[i] += 32;
        }
    }

    printf("%s", name);

}




int find_by_name(int n1, Contato list[n1], int n2, char names[n2][50]){

    int count = 0;

    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            for(int k = 0; names[j][k] != '\0'; k++){
                if(list[i].name[k] != names[j][k]){
                    break;
                }
            }
                count++;
        }
    }

    return count;
}


int main(){
    Ponto p1 = {-2.0f, 7.5f};
    Ponto p2 = {5.0f, 12.0f};
    Ponto p3 = {4.5f, 3.0f};
    Ponto p4 = {2.0f, 4.5f};

    Ponto v1[4] = {p1, p2, p3, p4};

    Contato c = {1, "John Doe", "johndoe@email.com", 2};

    char type_names[5][50] = {"Familia", "Amigo", "Trabalho", "Escola", "Outros"};

    Contato list[] = {
        {1, "Marcus Fenix", "fenix@gow.com", 2},
        {41, "Blue Mary", "mary@ff3snk.net", 0},
        {17, "Barry Burton", "bburton@re.cap", 0},
        {8, "Charlie Nash", "nash@ssz.com", 2},
        {2, "Ada Wong", "wong@re2.net", 4},
        {5, "Chris Redfield", "crfield@re.cap", 0}
        };

    char names[][50] = {"Marcus Fenix", "Blue Mary", "Ada wong"};


    Empregado names1[] = {
        {"Pedro", 1000, 0},
        {"Julia", 3000, 2},
        {"Kaike", 4000, 1},
        {"Eduardo", 2000, 3},
        {"Kenzo", 2500, 0},
        {"Bornia", 5000, 2},
        {"Victor", 4500, 3}


    };



    int x = find_by_name(6, list, 3, names);
    printf("%d", x);
}