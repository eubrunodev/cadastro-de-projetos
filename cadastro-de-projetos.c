#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define LIMITE 200 

struct projetoDados{
	int ano, status, codigo;
	char titulo[100];
	char desc[100];
	char gerente[100];
	char objetivo[100];
	char publico[100];
	char resultado[100];
};

struct projetoDados cadProjetos[LIMITE];
int aux, cont, i, tAfazer, tFazendo, tConcluido;

void menu(){ 
	printf("\n\tBEM-VINDO(A) AO SISTEMA DE CADASTRO E VISUALIZAÇÃOO DE PROJETOS.");
	printf("\n\n\t\t-- MENU DE OPÇÕES --\n");
	printf("\n	[1] - Cadastrar Projeto - %d/%d", cont, LIMITE);
	printf("\n	[2] - Listar todos os projetos.");
	printf("\n	[3] - Listar todos os projetos com o Status: A Fazer.");
	printf("\n	[4] - Listar todos os projetos com o Status: Fazendo.");
	printf("\n	[5] - Listar todos os projetos com o Status: Concluído.");
	printf("\n	[6] - Buscar projeto pelo código.");
	printf("\n	[0] - Sair\n");
	printf("\n\tEscolha uma opção: ");
}
void systemsMensagens(){
	system("pause");
	system("cls");
}
void mensagens(){ // mensagens informadas na visualiza��o dos projetos
	printf("\nCódigo: %d", cadProjetos[i].codigo);
	printf("\nTítulo: %s", cadProjetos[i].titulo);
	printf("\nDescrição: %s", cadProjetos[i].desc);
	printf("\nAno: %d", cadProjetos[i].ano);
	printf("\nGerente do projeto: %s", cadProjetos[i].gerente);
	printf("\nObjetivos: %s", cadProjetos[i].objetivo);
	printf("\nPúblico alvo: %s", cadProjetos[i].publico);
	switch(cadProjetos[i].status){
		case 1:
			printf("\nStatus: A Fazer");
	    break;
		case 2:
			printf("\nStatus: Fazendo");
		break;
		case 3:
			printf("\nStatus: Concluído");
		break;
		default:
			printf("Status: Não informado");
	}
	printf("\nResultado: %s", cadProjetos[i].resultado);
	printf("\n------------------------------------\n");
}
void cadastroProjetos(){ // cadastro de projetos com limite definido em uma constante la no inicio!
	system("cls");
	char resp = 's';
	if(cont >= LIMITE){
		system("cls");
		printf("Limite de cadastro atingido");
	} else{
		while(resp == 's' && i < LIMITE){
			cadProjetos[i].codigo = i + 1;
		    
 			printf("\n##################################");
			printf("\n#   CADASTRO DE PROJETOS         #");
			printf("\n#                                #");
			printf("\n#   Limite: %d                  #", LIMITE);
			printf("\n#   Total de Cadastros: %d        #", cont);
			printf("\n#                                #");
			printf("\n##################################\n");
			
			printf("\nInforme o TÍTULO do projeto:\nR: ");
			fflush(stdin);
			gets(cadProjetos[i].titulo);

			printf("\nInforme a DESCRIÇÃO do projeto:\nR: ");
			fflush(stdin);
			gets(cadProjetos[i].desc);
					
			printf("\nInforme o ANO do projeto:\nR: ");
			fflush(stdin);
			scanf("%d", &cadProjetos[i].ano);

			printf("\nInforme o nome do GERENTE do projeto:\nR: ");
			fflush(stdin);
			gets(cadProjetos[i].gerente);

			printf("\nInforme os OBJETIVOS do projeto:\nR: ");
			fflush(stdin);
			gets(cadProjetos[i].objetivo);

			printf("\nInforme o PUBLICO ALVO do projeto:\nR: ");
			fflush(stdin);
			gets(cadProjetos[i].publico);

			printf("\nInforme o STATUS do projeto\n\n[1] - A Fazer | [2] - Fazendo | [3] - Concluído:\nR: ");
			fflush(stdin);
			scanf("%d", &cadProjetos[i].status);

			switch(cadProjetos[i].status){
				case 1:
					tAfazer = 1;
				break;
				case 2:
					tFazendo = 1;
				break;
				case 3:
					tConcluido = 1;
				break;
				default:
					tAfazer = 0;
					tFazendo = 0;
					tConcluido = 0;
				break;	
			}
			
			printf("\nInforme o RESULTADO do projeto:\nR: ");
			fflush(stdin);
			gets(cadProjetos[i].resultado);
			
			printf("\nDeseja cadastrar mais um projeto? [s] Sim, [n] Não:\nR: ");
			fflush(stdin);
			scanf("%c", &resp);
	
			if(resp == 's') {
				if(i < LIMITE){
					i++;	
				}else{
					printf("Limite de cadastro atingido!!!");
					system("pause");
					resp ='n';
				}
			}
			system("cls");									
			aux = 1;
			cont = cont + 1;
		} 
	}
}
void listarTodos(){ // lista todos os projetos cadastrados
	if(aux == 1){
		system("cls");
		printf("Lista de todos os Projetos:\n");
		for(i=0; i<cont; i++){
			printf("\nProjeto %d:\n", i+1);
			mensagens();
		}
		systemsMensagens();
	} else {
		system("cls");
		printf("Error: nenhum projeto cadastrado.\n\n");
		systemsMensagens();
	}	
}
void listarAfazer(){ // todos os projetos com status A FAZER
	if(aux == 1){
		if(tAfazer == 1){	
			system("cls");
			printf("Lista dos projetos com status: **A Fazer**\n");
			for(i=0; i<LIMITE; i++){
				switch(cadProjetos[i].status){
				case 1:
					mensagens();
				break;
				}
			}
			systemsMensagens();
		} else {
			system("cls");
			printf("Error: nenhum projeto cadastrado como (A FAZER)\n\n");
			systemsMensagens();
		}
	} else {
		system("cls");
		printf("Error: nenhum projeto cadastrado.\n\n");
		systemsMensagens();
	}	
}
void listarFazendo(){ // todos os projetos com status FAZENDO
	if(aux == 1){
		if(tFazendo == 1){
			system("cls");
			printf("Lista dos projetos com status: **Fazendo**\n");
			for(i=0; i<LIMITE; i++){
				switch(cadProjetos[i].status){
				case 2:
					mensagens();
				break;
				}
			}
			systemsMensagens();
		} else {
			system("cls");
			printf("Error: nenhum projeto cadastrado como (FAZENDO)\n\n");
			systemsMensagens();
		}
	} else {
		system("cls");
		printf("Error: nenhum projeto cadastrado.\n\n");
		systemsMensagens();
	}	
}
void listarConcluido(){ // todos os projetos com status CONCLUIDO
	if(aux == 1){
		if(tConcluido == 1){
			system("cls");
			printf("Lista dos projetos com status: **Concluído**\n");
			for(i=0; i<LIMITE; i++){
				switch(cadProjetos[i].status){
				case 3:
					mensagens();
				break;
				}
			}
			systemsMensagens();
		} else {
			system("cls");
			printf("Error: nenhum projeto cadastrado como (CONCLUÍDO)\n\n");
			systemsMensagens();
		}
	} else {
		system("cls");
		printf("Error: nenhum projeto cadastrado.\n\n");
		systemsMensagens();
	}	
}
void buscarCodigo(){
	int codigo;
	int achou;
	achou = 0;
	
	if(aux == 1){
		system("cls");
		printf("Informe o CÓDIGO do projeto: \n");
		fflush(stdin);
		scanf("%d", &codigo);
			
		system("cls");
		printf("BUSCA DE PROJETO POR CÓDIGO - Código %d\n", codigo);

		while(achou == 0){
			for(i=0; i<cont; i++){
				if(codigo == cadProjetos[i].codigo){
					printf("\nInformações do projeto:\n");
					mensagens();
					achou = 1;
					systemsMensagens();
				}
			}
			if(achou != 1) {
				system("cls");
				printf("Error: não existe nenhum projeto cadastrado com o código: %d.\n\n", codigo);
				systemsMensagens();
				achou = 1;
			}
		}
	} else {
		system("cls");
		printf("Error: nenhum projeto cadastrado.\n\n");
		systemsMensagens();
	}	
}
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int op;
	aux = 0;
	cont = 0;
	tAfazer = 0;
	tFazendo = 0;
	tConcluido = 0;
	i=0;

	do {
		menu();
		fflush(stdin);
		scanf("%d", &op);
		
		switch(op){
			case 1:
					cadastroProjetos();
			break;
			case 2:
					listarTodos();
			break;
			case 3:
					listarAfazer();
			break;
			case 4:
					listarFazendo();
			break;
			case 5:
					listarConcluido();
			break;
			case 6:
					buscarCodigo();
			break;
			case 0:
					printf("\nFinalizando o programa!");
			break;
			default:
					system("cls");
					printf("Opção inválida!\n\n");
					systemsMensagens();
		}
	} while(op != 0);
	system("pause");
	return (0);
}
