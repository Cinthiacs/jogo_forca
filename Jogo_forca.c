#include<stdio.h>
#include<string.h>
#include<time.h>
#include<locale.h>
#include <stdlib.h>

// Desenho da forca:
void forca(int estado){
	if(estado==0){
		printf("\n**********");
		printf("\n|        |");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n| ");
	}else if(estado==1){
		printf("\n**********");
		printf("\n|        |");
		printf("\n|        O");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n| ");
	}else if(estado==2){
		printf("\n**********");
		printf("\n|        |");
		printf("\n|        O");
		printf("\n|        |");
		printf("\n|");
		printf("\n|");
		printf("\n| ");
	}else if(estado==3){
		printf("\n**********");
		printf("\n|        |");
		printf("\n|        O");
		printf("\n|        |/");
		printf("\n|");
		printf("\n|");
		printf("\n| ");
	}else if(estado==4){
		printf("\n**********");
		printf("\n|        |");
		printf("\n|        O");
		printf("\n|       \\|/");
		printf("\n|");
		printf("\n|");
		printf("\n| ");
		
		}else if(estado==5){
		printf("\n**********");
		printf("\n|        |");
		printf("\n|        O");
		printf("\n|       \\|/");
		printf("\n|        |");
		printf("\n|");
		printf("\n| ");
		
		}else if(estado==6){
		printf("\n**********");
		printf("\n|        |");
		printf("\n|        O");
		printf("\n|       \\|/");
		printf("\n|        |");
		printf("\n|         \\"); // para conseguir imprimir precisa de 2
		printf("\n| ");
		
		}else if(estado==7){
		printf("\n**********");
		printf("\n|        |");
		printf("\n|        O");
		printf("\n|       \\|/");
		printf("\n|        |");
		printf("\n|       / \\");
		printf("*Game Over*\n");
	}
}
void limpa_Teclado() {
	char c = 0;
	while (1) {
		c = getchar();
		if (c == '\n') {
			break;
		}
	}
}

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	time_t mytime;
	mytime = time(NULL);
    time_t data_ano;
    time(&data_ano);
    struct tm* data = localtime(&data_ano);
    printf(ctime(&mytime));
        
	//Pedir o nome do jogador 1
	char jog1 [20];
	while(1){
	
	printf("Olá caro usuário\r\n"\
	"Digite seu nome: \r\n");
	gets(jog1);
	
	//Pedir ao usuário a palavra chave
	char secret [20];
	char dica [50];

	printf("%s, agora digite uma palavra secreta para o jogo:\r\n",jog1);
	fgets(secret, 20,stdin);
	
	printf("%s, agora digite uma dica para a sua palavra chave:\r\n",jog1);
	gets(dica);
	
	printf("A palavra secreta é: %s",secret);
	
	//-1 Para excluir o enter
	printf("A palavra tem  %lu caracteres\r\n",strlen(secret)-1);
	
	//Pedir informação do jogador 2
	system("cls");
	char jog2 [20];

	printf("Agora jogador 2 digite seu nome:\r\n",jog2);
	gets(jog2);
	printf("%s, segue a dica da palavra chave do jogo:\r\n %s ...\r\n",jog2,dica);
	printf("A palavra tem  %lu caracteres\r\n",strlen(secret)-1);
	
	secret [strlen(secret)-1]='\0'; // Para eliminar o carac enter
	
	char t_sec [20];
	strcpy(t_sec, secret); // copia a palavra secret
	int i = 0;
		
	
	for (i=0; i<strlen(t_sec); i++){
		t_sec[i]='_';
		//puts(t_sec); // imprime o _ no lugar das letras	

	}
		
	int erros = 0;
			
	while(1){
		
		forca(erros);
		printf("\n %s Advinhe: ", jog2);
						
		for(i=0; i<strlen(t_sec); i++){
			printf("%c ", t_sec[i]);
		}
	// Recebe o caracter
	printf("\n %s,tente uma letra:\r\n", jog2);
	char c;
	scanf(" %c", & c);
			
// Comparar a letra com a palavra secreta
		int verifica_erro = 1; // 1=sim 0= não
		
		for(i=0; i<strlen(t_sec); i++){
// se a palavra secreta for certa, atualizo com a palavra cópia da tela
			if(c == secret[i]){
				t_sec[i] = c;
				verifica_erro = 0;				
			}
			
		}
// se nao errou, incrementar os erros
	if(verifica_erro == 1){
		printf("%s, \r\nVoce errou...\r\n", jog2);
		erros++;
	}
// vertifica se palavra da tela = palavra secreta	
	if(strcmp(t_sec, secret) == 0){
		printf("\n %s, \r\nParabéns!! Você Ganhou!", jog2);
		break;
	}
	
	// verifica se o jogo acabou
	if(erros==7){
		forca(erros);
		printf("\nA palavra secreta era:\r\n");
		puts(t_sec);
		break;
		}
	}
	
	printf("\r\n %s, Deseja um novo jogo? (s/n) ", jog2);
	
		char opcao = 0;
		while (1) {                                 
			opcao = getchar();
			limpa_Teclado();			
		
			if (opcao != 'n' && opcao != 'N' && opcao != 's' && opcao != 'S') {
				printf(" * %s, Você digitou um valor incorreto, digite s ou n: ", jog2);
			}
			else {
				break;
			}
		}

		if (opcao == 's' || opcao == 'S') {
			continue;
			system("cls");
		}
		else {
			printf("\r\n * %s, e %s,  Agradecemos por utilizar nosso programa!!\r\n\r\n ",jog1, jog2);
			system("pause");
			break;
		}
	}
}

	




