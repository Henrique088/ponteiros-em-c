#include <stdio.h>
#include <stdlib.h>


typedef struct ponto {
    int x, y;
}ponto;

int exemplo01();
int exemplo02();
int exemplo03();
int exemplo04();
int exemplo05();
int exemplo06();
int exemplo07();
int exemplo08();
int exemplo09();
int exemplo10();
int exemplo11();
int exemplo12();
int exemplo13();
int exemplo14();
int exemplo15();
int exemplo16();

void imprime_vetor(int *n, int m);
void imprime_matriz(int m[][2], int n);
void imprime_struct_valor(struct ponto p);
void instancia_struct_referencia(struct ponto *p);

    
int main(){
    
    exemplo01();
    return 0;
}


/*
    O objetivo do exemplo abaixo é mostrar a diferença entre os operadores * e &,
    além de ilustrar a aritmética de ponteiros
*/
int exemplo01(){    
    int a = 12;
    int *p;
    
    p = &a;
    
    printf("Conteúdo de p: %p\n",p);
    printf("Endereço de p: %p\n",&p);
    printf("Conteúdo da posição apontada por p: %d\n",*p);
    
    p++;
    
    printf("\n-----------------------------------------------------------------\n");
    printf("Conteúdo de p após p++: %p\n",p);
    printf("Endereço de p após p++: %p\n",&p);
    printf("Conteúdo da posição apontada por p após p++: %d\n",*p);

    p--;
    
    printf("-----------------------------------------------------------------\n");
    printf("Conteúdo de p após p--: %p\n",p);
    printf("Endereço de p após p--: %p\n",&p);
    printf("Conteúdo da posição apontada por p após p--: %d\n",*p);
    
    return 0;
    
    
}
    
/*
    O objetivo do exemplo abaixo é mostrar os cuidados ao acessar o valor 
    apontado por um ponteiro
*/    
int exemplo02(){
    int *ptr, xyz = 20;
    ptr = &xyz;
    printf("Conteudo apontado por ptr (1): %d \n",*ptr);
    printf("Endereço de ptr (1): %p \n",ptr);
    (*ptr)++;
    /*
    se o comando acima for escrito assim: *ptr++ (sem os parênteses) terei um erro
    pois primeiro devo resolver o ponteiro, e depois fazer o incremento do valor
    (neste  caso). Sem os parênteses, o compilador entende que primeiro deve 
    fazer o incremento e só depois resolver o ponteiro (precedências da linguagem)
    Possivelmente teremos falha de segmentação, pois tentaremos acessar uma 
    posição de memória que não está reservada para o programa.
    */
    printf("Endereço de ptr (2): %p \n",ptr);
    printf("Conteudo apontado por ptr (2): %d \n",*ptr);
    *ptr = (*ptr) * 10;
    printf("Conteudo apontado por ptr (3): %d \n",*ptr);
    return 0;
}

/*
    O objetivo do exemplo abaixo é mostrar a possibilidade de comparação de 
    ponteiros
*/
int exemplo03(){
    int *p, *p1, x, y;
    p = &x;
    p1 = &y;
    if(p > p1)
        printf("O ponteiro p aponta para uma posicao a frente de p1\n");
    else
        printf("O ponteiro p NAO aponta para uma posicao a frente de p1\n");
    return 0;
}

/*
    O objetivo do exemplo abaixo é mostrar a possibilidade de comparação de 
    valores apontados por ponteiros, usando o operador * (indireção ou 
    desreferenciação)
*/
int exemplo04(){
    int *p, *p1, x = 10, y = 20;
    p = &x;
    p1 = &y;
    if(*p > *p1)
        printf("O conteudo de p e maior do que o conteudo de p1\n");
    else
        printf("O conteudo de p NAO e maior do que o conteudo de p1\n");
    return 0;
}

/*
    O objetivo do exemplo abaixo é mostrar a possibilidade de usar ponteiros
    para controlar/acessar vetores
*/
int exemplo05(){
    
    int numeros[7] = {10,30,2,4,8,22,50};
    int *ptr_numeros = numeros;
    
    for (int i = 0; i < 7; i++) {
        printf("%d\t",numeros[i]);
    }
    
    printf("\n ------- imprimindo agora os endereços -------\n");
    
    //observe que imprimo os endereços usando aritmética de ponteiros
    for (int c = 0; c < 7; c++) {
        printf("%p\t",ptr_numeros);
        ptr_numeros++;
    }
}

/*
    O exemplo abaixo é o mesmo do exemplo05, mas repare que ao imprimir os
    endereços do vetor, uso uma forma diferente de laço :-P
*/
int exemplo06(){
    
    int numeros[7] = {10,30,2,4,8,22,50};
    int *ptr_numeros = numeros;
    
    for (int i = 0; i < 7; i++) {
        printf("%d\t",numeros[i]);
    }
    
    printf("\n ------- imprimindo agora os endereços -------\n");
    /*
        observe que uso como limite do laço numeros+7 - lembre-se que numeros,
        por definição, é um ponteiro... então estou usando novamente a 
        aritmética de ponteiros
    */
    for (; ptr_numeros != numeros+7; ptr_numeros++) {
        printf("%p\t",ptr_numeros);
    }
}

/*
    O exemplo abaixo é o mesmo do exemplo05 e exemplo06, mas repare que ao 
    atribuir valores faço uso também da aritmética de ponteiros :-D
*/
int exemplo07(){
    int numeros[7] = {10,30,2,4,8,22,50};
    int *ptr_numeros = numeros;
    
    for (; ptr_numeros != numeros+7; ptr_numeros++) {
        printf("%d\t",*ptr_numeros);
    }
    
    printf("\n ------- imprimindo agora os endereços -------\n");
    /*
        No caso do laço a seguir, veja que tenho que reiniciar o ponteiro,
        pois o mesmo foi deslocado em 7 posições pelo laço acima!
    */
    for (ptr_numeros=numeros; ptr_numeros != numeros+7; ptr_numeros++) {
        printf("%p\t",ptr_numeros);
    }
}

/*
    O objetivo do exemplo abaixo é mostrar outras manipulações que posso fazer 
    ao usar ponteiros e vetores, além de reforçar o uso dos operadores & e *
*/
int exemplo08(){
    
    int vet[5] = {1,2,3,4,5};
    int *p, indice = 2;
    p = vet;
    //vet[0] é equivalente a *p;
    printf("\nValor de *p: %d\n",*p);
    printf("É equivalente a vet[0]: %d\n",vet[0]);
    //vet[indice] é equivalente a *(p+indice);
    printf("\nValor de vet[indice]: %d\n",vet[indice]);
    printf("É equivalente a *(p+indice): %d\n",*(p+indice));
    //vet é equivalente a &vet[0];
    printf("\nValor de vet: %p\n",vet);
    printf("É equivalente a &vet[0]: %p\n",&vet[0]);
    //&vet[indice] é equivalente a (vet+indice);
    printf("\nValor de &vet[indice]: %p\n",&vet[indice]);
    printf("É equivalente a (vet+indice): %p\n",(vet+indice));
    return 0;
}

/*
    O objetivo do exemplo abaixo é mostrar o uso de ponteiros aplicados à
    matrizes
*/

int exemplo09(){
    int mat[2][2] = {{1,2},{3,4}};
    int i,j;
    printf("-------- imprimindo arrays multidimensionais da forma tradicional --------\n");
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            printf("%d\n", mat[i][j]);
    
    printf("-------- outra forma, usando ponteiros --------\n");

    /*
        Lembrando que, em memória, não é criada uma matriz como a desenhamos, 
        mas as posições são armazenadas de forma contígua. Assim, o laço abaixo
        itera numa matriz normalmente.
    */
    int *p = &mat[0][0];
    for(i=0;i<4;i++)
        printf("%d\n", *(p+i));
    return 0;
}


/*
    O objetivo do exemplo abaixo é ilustrar o uso de parâmetros por referência,
    que só é possível em C usando ponteiros. Veja que antes de cada parâmetro
    colocamos o asterisco, como na declaração de ponteiros.
*/

int exemplo10(int *n){
    *n=*n+1; //ou poderia ser (*n)++
}

/*
    O objetivo do exemplo abaixo é ilustrar o uso de parâmetros por referência,
    que só é possível em C usando ponteiros. Veja que antes de cada parâmetro
    colocamos o asterisco, como na declaração de ponteiros. A subrotina Troca
    será usada no exemplo11
*/
void Troca(int*a,int*b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/*
    O objetivo do exemplo abaixo é mostrar o uso de subrotinas que possuem
    parâmetros por referência :-)
*/

int exemplo11(){
    int x = 1;
    int y = 3;
    //chamando exemplo10 para incrementar 1 em x
    exemplo10(&x);

    printf("Antes: %d e %d\n",x,y);
    Troca(&x,&y);
    printf("Depois: %d e %d\n",x,y);
    return 0;
}

/*
    O objetivo do exemplo abaixo é mostrar uma subrotina que imprime um vetor
    recebido por parâmetro. Repare que preciso passar um ponteiro para o vetor
    e ainda o seu tamanho, em outro parâmetro (m no caso).
    
    Como meu vetor é passado por referência, todas as alterações que fizermos
    nele serão refletidas na subrotina de chamada.
*/
void imprime_vetor(int *n, int m){
    int i;
    //n = 1000; // ERRADO
    *n = 1000; //*n é o mesmo que primeira posição
    *(n+2) = 2000;
    for (i=0; i<m;i++)
        printf("%d \t", n[i]);
}

/*
    O objetivo do exemplo abaixo é mostrar como usar uma subrotina que imprime
    um vetor usando ponteiros. Repare que, além do ponteiro para o vetor, tenho
    que obrigatoriamente passar um segundo parâmetro, que é o tamanho do vetor.
    Isso é necessário pois o controle efetivo da memória é do programador, ou 
    seja, a linguagem não "sabe" onde termina seu vetor.
    
    Perceba ainda neste exemplo que os elementos que as alterações feitas na 
    subrotina "imprime_vetor" foram refletidos aqui :-O
*/
int exemplo12(){
    int v[5] = {1,2,3,4,5};
    imprime_vetor(v,5);
    
    printf("%d \t", v[0]);
    return 0;
}

/*
    O objetivo do exemplo abaixo é mostrar uma subrotina que imprime uma matriz
    recebida por parâmetro. Repare que preciso passar um ponteiro para a matriz
    e ainda tamanho de todas as dimensões, exceto a primeira.
    
    A razão disso vem da forma em que matrizes de C são representadas na 
    memória. As linhas são colocadas em posições contíguas de memória!
    Quando você acessa o campo (i,j) de uma matriz 2x2, o que o C faz é acessar 
    o campo 2*i + j do "vetor"(posições contíguas de memória). Por isso, o
    compilador tem que saber em tempo de compilação quanta colunas há em cada 
    linha, que é o fator que multiplica o i!
    
    Observe ainda que, como no caso dos vetores, preciso ter um parâmetro 
    indicando a quantidade de linhas da matriz
*/
void imprime_matriz(int m[][2], int n){
    int i,j;
    for (i=0; i<n;i++){
        for (j=0; j<2;j++)
            printf("%d \t", m[i][j]);
        printf("\n");
    }        
}

/*
    O objetivo do exemplo abaixo é ilustrar o uso de um subrotina que recebe
    uma matriz como parâmetro, necessariamente usando ponteiros.
*/
int exemplo13(){
    int mat[3][2] = {{1,2},{3,4},{5,6}};
    imprime_matriz(mat,3);
    return 0;
}

/*
    O objetivo do exemplo abaixo é ilustrar um subrotina que recebe como parâmetro
    uma struct (por valor)
*/
void imprime_struct_valor(ponto p){
    printf("x = %d\n",p.x);
    printf("y = %d\n",p.y);
}

/*
    O objetivo do exemplo abaixo é mostrar como fazer uso de um subrotina que 
    recebe uma struct como parâmetro (por valor)
*/
int exemplo14(){
    ponto p1 = {10,20};
    imprime_struct_valor(p1);
    return 0;
}

/*
    O objetivo do exemplo abaixo é ilustrar um subrotina que recebe como parâmetro
    uma struct (por referência)
*/
void instancia_struct_referencia(ponto *p){

    //observe que primeiro devo "pedir" que o compilador resolva o ponteiro
    //e só então posso acessar o campo da struct
    (*p).x = 10;
    (*p).y = 20;
    
    // outra forma de fazer, muito mais elegante, usando o operador seta ->
    p->x = 10;
    p->y = 20;
    
    /*
    Cuidado! Se eu declaro uma variável do tipo ponto aqui dentro (escopo local),
    o acesso a ela permanece da forma como já conhecemos em Alg.I. Veja:
    */
    
    ponto nova_variavel;
    
    nova_variavel.x = 1;
    nova_variavel.y = 2;
    
    printf("Valor de X: %d - Valor de Y: %d\n\n\n\n",nova_variavel.x, nova_variavel.y);
}

/*
    O objetivo do exemplo abaixo é ilustrar o uso de uma subrotina que recebe 
    como parâmetro uma struct (por referência)
*/
int exemplo15(){
    ponto p1;
    instancia_struct_referencia(&p1);
    printf("x = %d\n",p1.x);
    printf("y = %d\n",p1.y);
    return 0;
}

/*
    O exemplo a seguir mostra que é possível ter ponteiros como campos de uma 
    struct. Veja que a forma de acessar os valores apontados por eles é diferente 
    do que já vimos até aqui!
*/
typedef struct tipo_horario {
    int *pHoras;
    int *pMinutos;
    int *pSegundos;
}tipo_horario;

int exemplo16(){
    tipo_horario hora_atual;
    
    int h = 10;
    int m = 20;
    int s = 30;
    
    hora_atual.pHoras = &h;
    hora_atual.pMinutos = &m;
    hora_atual.pSegundos = &s;
    
    printf("\t\t %d : %d : %d \n\n\n",*hora_atual.pHoras, *hora_atual.pMinutos, *hora_atual.pSegundos);
    
    *hora_atual.pSegundos = 59;
    /*
    Veja que, como o próprio campo da struct é um ponteiro, preciso que o
    compilador resolva primeiro o campo e só depois o ponteiro. Por isso, nesse
    caso em que tem-se um campo de uma struct como um ponteiro, não se usa
    parênteses para acessá-lo
    */

    printf("\t\t %d : %d : %d \n\n\n",*hora_atual.pHoras, *hora_atual.pMinutos, *hora_atual.pSegundos);
    
    return 0;
}
