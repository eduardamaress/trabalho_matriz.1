/* Programa que é capaz de resolver sistemas lineares de ordem 2 (2x2) e 3 (3x3) pela regra de Cramer.
O programa entrega as soluções das váriaveis x e y (2x2) e x, y e z(3x3).
Feito por:Eduarda Maressa do Nascimento Martins*/

#include <stdio.h>
#include <math.h>


float det2(float a, float b, float c, float d) {
return (a * d) - (b * c); //aqui usei cramer
}

float det3(float i, float j, float k, 
           float l, float m, float n, 
           float o, float p, float q){
            
        float soma_princ = (i * m * q) + (j * n * o) + (k * l * p);
        float soma_sec = (k * m * o) + (i * n * p) + (j * l * q); //e aqui regra de sarrus

return soma_princ - soma_sec; 
}

void resolver2x2(void) {

    float a1, b1, c1; 
    float a2, b2, c2; 
    float detA, detX, detY; 
    float x, y; 

    printf("\n Sistema 2x2!\n");
    printf("Formato da equacao: a*x + b*y = c\n");

    printf("Digite os valores da Linha 1 (a1 b1 c1): ");
    scanf("%f %f %f", &a1, &b1, &c1);

    printf("Digite os valores da Linha 2 (a2 b2 c2): ");
    scanf("%f %f %f", &a2, &b2, &c2);

detA = det2(a1, b1, a2, b2); // Calculando o determinante da matriz principal


if (detA == 0.0) {
    printf("\nSistema sem solucao unica (det = 0).\n");
    return; // Se o determinante principal for zero,
            //o sistema não tem solução única então encerrei o programa
}


detX = det2(c1, b1, c2, b2); 
detY = det2(a1, c1, a2, c2);  // Substitui a coluna dos resultados nas colunas de
                             //X e Y para calcular detX e detY
    x = detX / detA;
    y = detY / detA;

printf("\nResultados:\n");
printf("x = %.4f\n", x); 
printf("y = %.4f\n", y);
}

void resolver3x3(void) {
    
    float i1, j1, k1, r1;
    float i2, j2, k2, r2; 
    float i3, j3, k3, r3; 
    float detB, detX, detY, detZ; 
    float x, y, z; 

    printf("\n Sistema 3x3!\n ");
    printf("Formato da equacao: i*x + j*y + k*z = r\n");

    printf("Digite a Linha 1 (i1 j1 k1 = r1): ");
    scanf("%f %f %f %f", &i1, &j1, &k1, &r1);

    printf("Digite a Linha 2 (i2 j2 k2 = r2): ");
    scanf("%f %f %f %f", &i2, &j2, &k2, &r2);

    printf("Digite a Linha 3 (i3 j3 k3 = r3): ");
    scanf("%f %f %f %f", &i3, &j3, &k3, &r3);

detB = det3(i1, j1, k1, i2, j2, k2, i3, j3, k3);//detB guarda o resultado retornado de det3.


if (detB == 0.0) {
    printf("\nSistema sem solucao unica (det = 0).\n");
    return; //mesma coisa do outro
}

detX = det3(r1, j1, k1, r2, j2, k2, r3, j3, k3); // Substitui coluna X pelos resultados r e assim por diantee
detY = det3(i1, r1, k1, i2, r2, k2, i3, r3, k3); 
detZ = det3(i1, j1, r1, i2, j2, r2, i3, j3, r3);

x = detX / detB;
y = detY / detB;
z = detZ / detB; // aqui tambem é regra de cramer

printf("\nResultados:\n");
printf("x = %.4f\n", x); 
printf("y = %.4f\n", y);
printf("z = %.4f\n", z);
}

int main(void) {
int opcao;

printf("Escolha o tamanho do sistema:\n");
printf(" 1 - Sistema 2x2 (x e y)\n");
printf(" 2 - Sistema 3x3 (x, y e z)\n");
printf("Opcao: ");
scanf("%d", &opcao);

if (opcao == 1) {
    resolver2x2();
} else if (opcao == 2) {
    resolver3x3(); 
} else {
    printf("Opcao invalida.\n"); // ve se o usuario digirou algo diferente de 1 e 2 
}

printf("\nPrograma encerrado.\n");
return 0; 
}
