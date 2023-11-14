#include <stdio.h>  //biblioteca de comunicacoes com o usuario
#include <stdlib.h>  //bilioteca de alocacoes de espacos de memoria
#include <locale.h>  //biblioteca de alocacoes de texto por regiao
#include <string.h>  //biblioteca responsavel por cuidar das strings
int registro()  //Funcao responsavel por cadastrar os usuario9s no sistema
{
    //Inicio da criacao de variaveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");  //Coletando informacao do usuario
    scanf("%s", cpf);  //%s refere-se a string

    strcpy(arquivo, cpf);  //responsavel por copiar os valores das strings

    FILE *file; 
    file = fopen(arquivo, "w");  //cria o arquivo com "w" de escrever em ingles
    fprintf(file,cpf);  //salva o valor da variavel
    fclose(file);  //fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o Cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);

    system("pause");

}
int consulta()
{
    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf, "r");  //"r" de ler em ingles

    if(file == NULL)
    {
        printf("Nao foi possivel abrir o arquivo, nao localizado!.\n");
    }

    while(fgets(conteudo, 200, file)!=NULL)
    {
        printf("\nEssas sao as informacoes do usuario: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

        system("pause");

}
int deletar()
{
    char cpf[40];  //Funcao para deletar o arquivo

    printf("Digite o CPF do cadastro a ser deletado: ");
    scanf("%s",cpf);

    remove(cpf);

    FILE *file;
    file = fopen(cpf,"r");

    if(file ==NULL)
    {
        printf("O usuario nao se encontra no sistema!\n");
        system("pause");
    }


    
}
int main()
{
    int opcao=0; //Definindo as variaveis
    int laco=1;

    for(laco=1;laco=1;)
    {
        system("cls");

        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

        printf("Cartorio da EBAC \n");  //Inicio do menu
        printf("Escolha a opcao desejada do menu: \n\n");
        printf("\t1 - Registrar os nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("opcao: ");  //Fim do menu

        scanf("%d", &opcao);  //Armazenamento da escolha do usuario
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
            printf("essa opcao nao esta disponivel\n\n");
            system("pause");
            break;
        }


    }
    printf("\t - Esse software e do Arthur\n");
}