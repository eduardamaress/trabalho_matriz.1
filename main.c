/* Programa que é capaz de resolver sistemas lineares de ordem 2 ( 2x2) e 3 (3x3) pela regra de Cramer.
O programa entrega as soluções das váriaveis x e y (2x2) e x, y e z(3x3).
Feito por:Eduarda Maressa do Nascimento Martins*/

#include <stdio.h>
#include <math.h>

float det2(float a, float b, /* primeira linha da matriz */
float c, float d) /* segunda linha da matriz */
{
 return a * d - b * c; // fórmula do determinante 2x2 (det = a*d - b*c)
}
 
int main(void)
{
 int opcao; 
 printf("Escolha o tamanho do sistema:\n");
 printf(" 1 - Sistema 2x2 (x e y)\n"); /* opção 1 */
 //printf(" 2 - Sistema 3x3 (x, y e z)\n"); /* opção 2 */
 
 printf("Opcao: "); /* pede a escolha */
 scanf("%d", &opcao); /* lê a opção digitada */
 
 
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
 //Aqui verifiquei o que o usuário digitou 
 if (opcao == 1) {
 resolver2x2(); // aqui chamei a função para quando tiver a de 3 grau 
                //fazer um elseif que chame a função 3x3
 }
 else{
 printf("Opcao invalida.\n"); /* avisa o erro */
 }
 printf("\nPrograma encerrado.\n"); 
 return 0; 
}