#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o cpf a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a strings(armazenamentos das strings nesse caso)
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	FILE *file; //Cria o arquivo
	
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file,"CPF: "); //Salva o valor da variável
	fprintf(file,cpf); //Salva o valor da variável
	fclose(file); //Fecha o Arquivo
	
	file = fopen(arquivo, "a"); //Cria o arquivo e o "a" significar adicionar
	fprintf(file,"\nNOME: "); //Salva o valor da variável
	fclose(file); //Fecha o Arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando o nome do usuário
	scanf("%s", nome); //Função responsável pelo armazenamento do Nome do usuário
	
	file = fopen(arquivo, "a");  //Cria o arquivo e o "a" significar adicionar
	fprintf(file,nome); //Salva o valor da variável
	fclose(file); //Fecha o Arquivo
	
	file = fopen(arquivo, "a");  //Cria o arquivo e o "a" significar adicionar
	fprintf(file,"\nSOBRENOME: "); //Salva o valor da variável
	fclose(file); //Fecha o Arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando o sobrenome do usuário
	scanf("%s", sobrenome); //Função responsável pelo armazenamento do Sobrenome do usuário
	
	file = fopen(arquivo, "a");  //Cria o arquivo e o "a" significar adicionar
	fprintf(file,sobrenome); //Salva o valor da variável
	fclose(file); //Fecha o Arquivo
	
	file = fopen(arquivo, "a");  //Cria o arquivo e o "a" significar adicionar
	fprintf(file,"\nCARGO: "); //Salva o valor da variável
	fclose(file); //Fecha o Arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando o cargo do usuário
	scanf("%s", cargo); //Função responsável pelo armazenamento do Cargo do usuário
	
	file = fopen(arquivo, "a");  //Cria o arquivo e o "a" significar adicionar
	fprintf(file,cargo); //Salva o valor da variável
	fprintf(file,"\n\n"); //Exibe um espaço entre as informações
	fclose(file); //Fecha o Arquivo
	
	system("pause"); //Realiza uma pausa no sistema
}


int consulta() //Função responsável por consultar usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; //Funçaõ responsável por armazenar uma quantia de caracteres
	char conteudo[200]; //Funçaõ responsável por armazenar uma quantia de caracteres
	
	printf("Digite o CPF a ser consultado: "); //Consultando o CPF do usuário
	scanf("%s",cpf); //Funçaõ responsável por procurar o CPF
	
	FILE *file;
	file = fopen(cpf,"r"); //Função responsável por abrir um arquivo exixtente ou criara um outro
	
	if (file == NULL) //Funçaõ para se a procura for = a nulo
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n"); //Exibibe uma informação de uma negativa caso a procura seje = a nulo
	}
	
		printf("\nEssas são as informações do usuário: \n\n "); //Exibe as informações do usuário
		
	while(fgets(conteudo, 200, file) != NULL) //Funçaõ responsável por executar um ou um conjunto de instruções enquanto uma condição é verdadeira 
	{
		printf("%s", conteudo);
		printf("\n");
		
	}
	
	system("pause"); //Realiza uma pausa no sistema
}

int deletar() //Função responsável por deletar usuários do sistema
{
	char cpf[40]; //Funçaõ responsável por armazenar uma quantia de caracteres
	
	printf("Digite o CPF do usúario a ser deletado: "); //Deleta o CPF do usuário
	scanf("%s",cpf); //Funçaõ responsável por procurar o CPF
	
	remove(cpf); //Função que remove o CPF
	
	FILE *file;
	file = fopen(cpf,"r"); //Função responsável por abrir um arquivo exixtente ou criara um outro
	
	if(file == NULL) //Se a procura for = a nulo
	{
		printf("O usuário não se encontra no sistema!.\n"); //Exibiçaõ de uma negativa caso a procura seje = a nulo
		system("pause"); //Realiza uma pausa no sistema
	}
}

int main() //Função principal do sistema
{
	int opcao=0; //Definindo variavéis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); // Responsável por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2- Consultar nomes\n");
		printf("\t3- Deletar nomes\n");
		printf("Opção "); //Fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do úsuario
		
		system("cls"); // Responsável por limpar a tela
		
		switch(opcao) //Início da seleção do menu
		{
		case 1:
		registro();	
		break;
		
		case 2:
		consulta();
		break;
		                  //Chamada de Funções
		case 3:
		deletar();
		break;

		default:
		printf("Essa opção não está disponível.\n");
		system("pause");
		break;
			
		} //Fim da seleção do menu
	}			
}	
