#include <stdio.h>
#include <string.h>

struct Pilha {

	int topo; 
	int capa;
	float *pElem;

};

void criarpilha( struct Pilha *p, int c ){

   p->topo = -1;
   p->capa = c;
   p->pElem = (float*) malloc (c * sizeof(float));

}
int estavazia ( struct Pilha *p ){

   if( p-> topo == -1 )

      return 1;   

   else

      return 0;   

}

int estacheia ( struct Pilha *p ){

	if (p->topo == p->capa - 1)

		return 1;

	else

		return 0;

}

void empilhar ( struct Pilha *p, float v){

	p->topo++;
	p->pElem [p->topo] = v;

}

float desempilhar ( struct Pilha *p ){

   float aux = p->pElem [p->topo];
   p->topo--;
   return aux;

}

float retornatopo ( struct Pilha *p ){

   return p->pElem [p->topo];

}

int srtcmp(char, int); 

int main(){

	struct Pilha minhapilha;
	int op, posicao;
	float valor;
  char expressao[30];
  char letra_expressao;

  
  printf("Digite a expressao: ");
  scanf("%s", expressao);
  

	criarpilha (&minhapilha, 30);

 
    posicao = 0;
    int expressao_balanceada = 1;

    while ((expressao[posicao] !='\0') && (expressao_balanceada == 1)) {
      letra_expressao = expressao[posicao];
      
       if(expressao[posicao] == '(' || expressao[posicao] == '[' || expressao[posicao] == '{'){
         empilhar(&minhapilha, expressao[posicao]);
       }

      if(expressao[posicao] == ')') {
        
        if(retornatopo (&minhapilha) == '(') {
          desempilhar(&minhapilha);
        }
        else{
          printf("EXPRESSAO NAO BALANCEADA");
          expressao_balanceada = 0;
        }

      }

      if(expressao[posicao] == ']') {

        if(retornatopo (&minhapilha) == '[') {
          desempilhar(&minhapilha);
        }
        else{
          printf("EXPRESSAO NAO BALANCEADA");
          expressao_balanceada = 0;
        }
        
      }

      if(expressao[posicao] == '}') {

        if(retornatopo (&minhapilha) == '{') {
          desempilhar(&minhapilha);
        }
        else{
          printf("EXPRESSAO NAO BALANCEADA");
          expressao_balanceada = 0;
        }
        
      }

      posicao++;
    }
  
    if ( estavazia (&minhapilha) != 1 ){
      printf("EXPRESSAO NAO BALANCEADA");
    }
    else{
     if (expressao_balanceada == 1){
       printf("EXPRESSAO BALANCEADA"); 
     }
      
    }

	
}