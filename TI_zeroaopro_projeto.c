#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o cpf a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a strings(armazenamentos das strings nesse caso)
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	FILE *file; //Cria o arquivo
	
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file,"CPF: "); //Salva o valor da vari�vel
	fprintf(file,cpf); //Salva o valor da vari�vel
	fclose(file); //Fecha o Arquivo
	
	file = fopen(arquivo, "a"); //Cria o arquivo e o "a" significar adicionar
	fprintf(file,"\nNOME: "); //Salva o valor da vari�vel
	fclose(file); //Fecha o Arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando o nome do usu�rio
	scanf("%s", nome); //Fun��o respons�vel pelo armazenamento do Nome do usu�rio
	
	file = fopen(arquivo, "a");  //Cria o arquivo e o "a" significar adicionar
	fprintf(file,nome); //Salva o valor da vari�vel
	fclose(file); //Fecha o Arquivo
	
	file = fopen(arquivo, "a");  //Cria o arquivo e o "a" significar adicionar
	fprintf(file,"\nSOBRENOME: "); //Salva o valor da vari�vel
	fclose(file); //Fecha o Arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando o sobrenome do usu�rio
	scanf("%s", sobrenome); //Fun��o respons�vel pelo armazenamento do Sobrenome do usu�rio
	
	file = fopen(arquivo, "a");  //Cria o arquivo e o "a" significar adicionar
	fprintf(file,sobrenome); //Salva o valor da vari�vel
	fclose(file); //Fecha o Arquivo
	
	file = fopen(arquivo, "a");  //Cria o arquivo e o "a" significar adicionar
	fprintf(file,"\nCARGO: "); //Salva o valor da vari�vel
	fclose(file); //Fecha o Arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando o cargo do usu�rio
	scanf("%s", cargo); //Fun��o respons�vel pelo armazenamento do Cargo do usu�rio
	
	file = fopen(arquivo, "a");  //Cria o arquivo e o "a" significar adicionar
	fprintf(file,cargo); //Salva o valor da vari�vel
	fprintf(file,"\n\n"); //Exibe um espa�o entre as informa��es
	fclose(file); //Fecha o Arquivo
	
	system("pause"); //Realiza uma pausa no sistema
}


int consulta() //Fun��o respons�vel por consultar usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; //Fun�a� respons�vel por armazenar uma quantia de caracteres
	char conteudo[200]; //Fun�a� respons�vel por armazenar uma quantia de caracteres
	
	printf("Digite o CPF a ser consultado: "); //Consultando o CPF do usu�rio
	scanf("%s",cpf); //Fun�a� respons�vel por procurar o CPF
	
	FILE *file;
	file = fopen(cpf,"r"); //Fun��o respons�vel por abrir um arquivo exixtente ou criara um outro
	
	if (file == NULL) //Fun�a� para se a procura for = a nulo
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n"); //Exibibe uma informa��o de uma negativa caso a procura seje = a nulo
	}
	
		printf("\nEssas s�o as informa��es do usu�rio: \n\n "); //Exibe as informa��es do usu�rio
		
	while(fgets(conteudo, 200, file) != NULL) //Fun�a� respons�vel por executar um ou um conjunto de instru��es enquanto uma condi��o � verdadeira 
	{
		printf("%s", conteudo);
		printf("\n");
		
	}
	
	system("pause"); //Realiza uma pausa no sistema
}

int deletar() //Fun��o respons�vel por deletar usu�rios do sistema
{
	char cpf[40]; //Fun�a� respons�vel por armazenar uma quantia de caracteres
	
	printf("Digite o CPF do us�ario a ser deletado: "); //Deleta o CPF do usu�rio
	scanf("%s",cpf); //Fun�a� respons�vel por procurar o CPF
	
	remove(cpf); //Fun��o que remove o CPF
	
	FILE *file;
	file = fopen(cpf,"r"); //Fun��o respons�vel por abrir um arquivo exixtente ou criara um outro
	
	if(file == NULL) //Se a procura for = a nulo
	{
		printf("O usu�rio n�o se encontra no sistema!.\n"); //Exibi�a� de uma negativa caso a procura seje = a nulo
		system("pause"); //Realiza uma pausa no sistema
	}
}

int main() //Fun��o principal do sistema
{
	int opcao=0; //Definindo variav�is
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); // Respons�vel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2- Consultar nomes\n");
		printf("\t3- Deletar nomes\n");
		printf("Op��o "); //Fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do �suario
		
		system("cls"); // Respons�vel por limpar a tela
		
		switch(opcao) //In�cio da sele��o do menu
		{
		case 1:
		registro();	
		break;
		
		case 2:
		consulta();
		break;
		                  //Chamada de Fun��es
		case 3:
		deletar();
		break;

		default:
		printf("Essa op��o n�o est� dispon�vel.\n");
		system("pause");
		break;
			
		} //Fim da sele��o do menu
	}			
}	
