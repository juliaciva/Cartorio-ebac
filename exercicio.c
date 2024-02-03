#include <stdio.h> // bilbioteca de comunicaçao com o usuario
#include <stdlib.h> // biblioteca de alocaçao de espaço em memória
#include <locale.h> //bilbioteca de alocaçoes de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuáios no sistema
{
	//Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado\n"); //Coletendo informação do usuário
	scanf("%s",cpf);//%s refere-se a string/estamos armazenando as string
	
	strcpy(arquivo, cpf); //responsável por copiar os arquivos das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo/ w vem de write escrever
	fprintf(file,cpf);//salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,","); //coloca a virgula
	fclose(file);// fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: \n"); //coletando informações do usuário
	scanf("%s",nome);//armazena a string
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,nome);//salva o valor da variavel/no caso o nome
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");//cria o arquivo
	fprintf(file,",");//coloca a virgula
	fclose(file);//fecha o serviço
	
	printf("Digite o sobrenome a ser cadastrado\n");//coletando informações do usuário
	scanf("%s",sobrenome);// armazena na string
	
	
	file  = fopen(arquivo, "a");//cria o arquivo
	fprintf(file,sobrenome);//salva o valor da variavel/no caso o sobrenome
	fclose(file);//fecha o serviço
	
	file = fopen(arquivo, "a");//cria o arquivo
	fprintf(file,",");//coloca a virgula
	fclose(file);//fecha o serviço
	
	printf ("Digite o cargo a ser cadastrado: \n");//coletando informações do usuário
	scanf("%s",cargo); //armazena na string
	
	file = fopen(arquivo, "a");//cria o arquivo
	fprintf(file,cargo);//salva o valor da variável
	fclose(file);//fecha o serviço
	
	system("pause");//pausa o serviço
			
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	//inicio da criação das variáveis/string
	char cpf[40]; 
	char conteudo[200];
	//fim da crição das variáveis/string
	
	printf("Digite o cpf a ser consultado"); //coletando infrmações dos usuários
	scanf("%s", cpf);//armazena na string
	
	FILE *file; //Entrar na bilbioteca que fala sobre a função file e dentro dela puxar os arquivos
	file = fopen(cpf,"r"); //"r" de read
	
	if(file == NULL) // se a opçao procurada nao existir
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");//informando o usuário de que a opçao é nula	
	}
	
	while(fgets(conteudo,200, file) != NULL); //busca as informações arquivadas diferentes de nulo
	{
		printf("\n Essas são as informções do usuário\n");//informa 
		printf("%s", conteudo); //apresenta a opção armazenada na string
		printf("\n\n"); //espaço
	}
	
	system("pause");// pausa o sistema
		
}

int deletar()
{
		char cpf[40];
		
		printf("Digite o cpf do usuário a ser deletado \n");
		scanf("%s",cpf); // s de string
		
		remove(cpf);
		
		FILE *file;//entrar na bilbioteca que fala sobre a função file e dentro dela puxar os arquivos
		file = fopen(cpf, "r");//r de read
		
		if (file == NULL)
		{
			printf("O USUÁRIO NÃO SE ENCONTRA NO SISTEMA \n");
			system("pause");
		}
		
}



int main ()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=10;)
	{
	
	system("cls");
	 
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar os nomes\n\n");
		printf("\t4 - Sair do sistema\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls");// responsavel por limpar a tela
		
		
		switch(opcao) //inicio da seleção de menu
		{
			case 1:
			registro();//chamada de funções
			break;
			
			case 2: 
			consulta();//chamada de funções
			break;
			
			case 3:
			deletar();//chamada de funções
			break;
			
			case 4:
			printf("Obrigada por utilizar o sistema\n");
			return 0;
			break;
			
	
			
			default:
				printf("essa opçao não está disponivel\n");
			system("pause");
			break;
				
		}//fim da seleção
	
		
	}
}
	
