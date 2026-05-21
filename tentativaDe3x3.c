
/* Programa que é capaz de resolver sistemas lineares de ordem 2 ( 2x2) e 3 (3x3) pela regra de Cramer.
O programa entrega as soluções das váriaveis x e y (2x2) e x, y e z(3x3).
Feito por:Eduarda Maressa do Nascimento Martins*/

#include <stdio.h>
#include <math.h>

float det2(float a, float b, 
           float c, float d) {
 return a * d - b * c; // fórmula do determinante 2x2 (det = a*d - b*c)
}

float det3(float i, float j, float k,  //| i   j
           float l, float m, float n, //| l   m
           float o, float p, float q){//| o   p
    
  soma_princ i*m*q + j*n*o + k*l*p;
  soma_sec k*m*o + i*n*p + j*l*q;
    
    return soma_princ - soma_sec;
}
    
int main(void)
{
 int opcao; 
 printf("Escolha o tamanho do sistema:\n");
 printf(" 1 - Sistema 2x2 (x e y)\n"); 
 printf(" 2 - Sistema 3x3 (x, y e z)\n"); 
 printf("Opcao: ");
 scanf("%d", &opcao);  
 
 
void resolver2x2(void)
{
 float a1, b1, c1; //coeficientes do sistema a1*x + b1*y = c1
 float a2, b2, c2; //coeficientes a2*x + b2*y = c2
 
 float detA; // determinante da matriz principal
 float detX; //determinante para encontrar x
 float detY; // determinante para encontrar y 
 
 float x, y;//resposta
 
 
 /* Imprime o cabeçalho do sistema */
 printf("\n Sistema 2x2! \n");
 printf("Formato da equação: a*x + b*y = c\n\n");

 printf("Coeficiente de x (a1): "); 
 scanf("%f", &a1); 
 printf("Coeficiente de y (b1): "); 
 scanf("%f", &b1);
 printf("Resultado (= c1): "); 
 scanf("%f", &c1); 
 
 
 printf("Coeficiente de x (a2): "); 
 scanf("%f", &a2); 
 printf("Coeficiente de y (b2): "); 
 scanf("%f", &b2);
 printf("Resultado (= c2): "); 
 scanf("%f", &c2); 
 
 // Matriz A é a que tem SÓ os coeficientes e ignora os resultados
 detA = det2(a1, b1, a2, b2); // Aqui calcula det(A) 
 
 /* Vê se o sistema tem solução única se o detA for 0 não tem */
 if (detA == 0.0) 
 {
 printf("\nSistema sem solucao unica (det = 0).\n");//Dai Cramer não funciona
 return; // encerra tudo
 }
 
 detX = det2(c1, b1,c2, b2); // calcula det(Ax) troca os valores de x pelos resultados
                            // que no caso serão dados pelo usuário.
 detY = det2(a1, c1,a2, c2); // calcula det(Ay)
 
 //Regra de Cramer x = det(Ax) / det(A)  e y = det(Ay) / det(A)
 
 x = detX / detA; 
 y = detY / detA; 
 
 
 printf("x = %.4f\n", x); // imprime as respostas
 printf("y = %.4f\n", y);
}

void resolver3x3(void)
{
 float i1, j1, k1, r1; //coeficientes do sistema i1*x + j1*y + k1*z = r1
 float i2, j2, k2, r2;//coeficientes i2*x + j2*y + k2*z = r2
 float i3, j3, k3, r3;
 
 
 float detB; // determinante da matriz principal
 float detX; 
 float detY; 
 float detZ;
 
 float x, y, z;
 
 printf("\n Sistema 3x3! \n");
 
 printf("Coeficiente de x (i1): "); 
 scanf("%f", &i1); 
 printf("Coeficiente de y (j1): "); 
 scanf("%f", &j1);
 printf("Coeficiente de z (k1): "); 
 scanf("%f", &k1);
 printf("Resultado (=r1): "); 
 scanf("%f", &r1);
 
 
 printf("Coeficiente de x (i2): "); 
 scanf("%f", &i2); 
 printf("Coeficiente de y (j2): "); 
 scanf("%f", &j2);
 printf("Coeficiente de z (k2): "); 
 scanf("%f", &k2);
 printf("Resultado (=r2): "); 
 scanf("%f", &r2);
 

 printf("Coeficiente de x (i3): "); 
 scanf("%f", &i3); 
 printf("Coeficiente de y (j3): "); 
 scanf("%f", &j3);
 printf("Coeficiente de z (k3): "); 
 scanf("%f", &k3);
 printf("Resultado (=r3): "); 
 scanf("%f", &r3);
 
 detB = det3(i1, j1, k1, i2, j2, k2);// soma_princ i*m*q + j*n*o + k*l*p;
                                    //  soma_sec k*m*o + i*n*p + j*l*q;
                                    // fiz essa conta pela diagonal da matriz no papel
                                    
 if (detB == 0.0) 
 {
 printf("\nSistema sem solucao unica (det = 0).\n");
 return;
 }
 
 detX = det3(r1, j1,r2, j2); 
 
 detY = det3(i2, r1,i2, r2); 
 
 //Regra de Cramer x = det(Ax) / det(A)  e y = det(Ay) / det(A)
 
 x = detX / detA; 
 y = detY / detA; 
 
 
 printf("x = %.4f\n", x); // imprime as respostas
 printf("y = %.4f\n", y);
}



 //Aqui verifiquei o que o usuário digitou 
 if (opcao == 1) {
    resolver2x2(); 
 }elseif(Opcao == 2){
    resolver3x3();
 }
 else{
 printf("Opcao invalida.\n");
 }
 printf("\nPrograma encerrado.\n"); 
 
 return 0; 
}