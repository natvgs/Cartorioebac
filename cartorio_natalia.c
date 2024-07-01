#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsálvel por cuidar das string

int registro() //Função responsalvel por cadastrar os usuários no sistema 
{
	//Inicio criação de variáveis/string
     char arquivo[40];
	 char cpf[40];
	 char nome[40];
	 char sobrenome[40];
	 char cargo[40];
	 	//final da criação de variáveis/string
	 
	 printf("Digite o CPF a ser cadastrado: ");//Coletando informação do usuário
	 scanf("%s", cpf);// %s refere-se a string
	 
	 strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	 
	 FILE *file; // cria o arquivo
	 file = fopen(arquivo, "w"); // cria o aquivo e o "w" significa escrever
	 fprintf(file,cpf); // salvo o valor da variavel
	 fclose(file); //fecha o aquivo
	 
	 file = fopen(arquivo, "a");// cria o aquivo
	 fprintf(file, ", nome: ");// salvo o valor da variavel
	 fclose(file);//fecha o aquivo
	 
	 printf("Digite o nome a ser cadastrado: ");//Coletando informação do usuário
	 scanf("%s",nome);
	 
	 file = fopen(arquivo, "a");// cria o aquivo
	 fprintf(file,nome); // salvo o valor da variavel
	 fclose(file);//fecha o aquivo
	 
	 file = fopen(arquivo, "a");// cria o aquivo
	 fprintf(file, ", sobrenome: "); // salvo o valor da variavel
	 fclose(file);//fecha o aquivo     
	 
	 printf("Digite o sobrenome a ser cadastrado: ");//Coletando informação do usuário
	 scanf("%s",sobrenome);
	 
	 file = fopen(arquivo, "a");// cria o aquivo
	 fprintf(file,sobrenome); // salvo o valor da variavel
	 fclose(file);
	 
	 file = fopen(arquivo, "a");// cria o aquivo
	 fprintf(file, ", cargo: "); // salvo o valor da variavel
	 fclose(file); //fecha o aquivo    
	 
	 printf("Digite o cargo a ser cadastrado: ");//Coletando informação do usuário
	 scanf("%s",cargo);
	 
	 file = fopen(arquivo, "a");// cria o aquivo
	 fprintf(file,cargo); // salvo o valor da variavel
	 fclose(file); //fecha o aquivo
	 
	 system("pause");
	 
	 
	 

}

int consulta()
{
      setlocale(LC_ALL, "portuguese"); //Definindo o Linguagem
	
	//Inicio criação de variáveis/string
	 char cpf[40];
     char conteudo[200];
    //final da criação de variáveis/string
     
     printf("Digite o CPF a ser consultado: ");//Coletando informação do usuário
     scanf("%s", cpf);
     
     FILE *file;// cria o arquivo
     file = fopen(cpf,"r");// cria o aquivo
     
     if(file == NULL)
     {
     	printf("Não foi possivel abrir o aquivo, não localizado! .\n");
	 }
	 
	 while(fgets(conteudo, 200, file) != NULL)
	 {
	 	printf("\nEssas são as informações do usuário: ");
	 	printf("%s", conteudo);
	 	printf("\n\n");
	 	
	 }
    system("pause"); 

}

int deletar()
{
	//Inicio criação de variáveis/string
	char cpf[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF do usuário a ser deletado: ");//Coletando informação do usuário
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;// cria o arquivo
	file = fopen(cpf,"r");// cria o aquivo
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!. \n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");
	
	    setlocale(LC_ALL, "portuguese"); //Definindo o Linguagem
	
    	printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n");
    	printf("\t4 - Sair do sistema\n\n");
    	printf("Opção: "); //Final do menu
   
        scanf("%d", &opcao); //armazenamendo a escolha do usuário
    
        system("cls");
        
        switch(opcao)
        {
        	case 1:
            registro();
        	break;
				
        	case 2:
            consulta();
        	break;
        	
        	case 3:
        	deletar();
     		break;
     		
     		case 4:
     		printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break; 	
     		
     		default:
     		printf("Essa opção não está disponivel!\n");
    		system("pause");
    		break;
     

				
	     }
    
       
   }
}
