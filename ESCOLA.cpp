#include <stdio.h>
#include <stdlib.h>

/*


Desenvolver um programa em C que controle o funcionamento de uma Escola. Existem diversas funcionalidades em uma Escola, mas voc� deve focar no que � pedido. Caso tenha interesse voc� pode evoluir sua solu��o para adicionar mais funcionalidades.
Funcionalidades solicitadas:

Cadastro de Alunos (Matr�cula, Nome, Sexo, Data Nascimento, CPF) .
Cadastro de Professores (Matr�cula, Nome, Sexo, Data Nascimento, CPF).
Cadastro de Disciplinas (Nome, C�digo, Semestre, Professor)
Inserir/Excluir aluno de uma disciplina

Relat�rios
Listar Alunos
Listar Professores
Listar Disciplinas (dados da disciplina sem os alunos)
Listar uma disciplina (dados da disciplina e os alunos matriculados)
Listar Alunos por sexo (Masculino/Feminino)
Listar Alunos ordenados por Nome
Listar Alunos ordenados por data de nascimento
Listar Professores por sexo (Masculino/Feminino)
Listar Professores ordenados por Nome
Listar Professores ordenados por data de nascimento
Aniversariantes do m�s
Lista de pessoas (professor/aluno) a partir de uma string de busca. O usu�rio informa no m�nimo tr�s letras e deve ser listado todas as pessoas que contem essas tr�s letras no nome.

Observa��o:
Por Cadastro entenda Incluir, excluir, atualizar
Valide todos os campos necess�rios (ex. Data nascimento, CPF)

*/

typedef struct dma
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{

    char nome[20], cpf[12], sexo, matricula[10];
    Data data_nascimento;

} Fichaaluno;

typedef struct
{

    char nome[20], cpf[12], sexo, matricula[10];
    Data data_nascimento;

} Fichaprofessor;

typedef struct
{

    char nome[20], codigo[10], professor[20];
    int semestre;

} Fichadisciplina;

void flush();

Fichaaluno cadastraAluno();

Fichaprofessor cadastraProfessor();

Fichadisciplina cadastraDisciplina();

void listarAlunos(Fichaaluno *alunos, int qtdAlunos)
{

    int i;

    for (i = 0; i < qtdAlunos; i++)
    {

        printf("\nNOME DO ALUNO: %s", alunos[i].nome);
        printf("CPF DO ALUNO: %s", alunos[i].cpf);
        printf("\nMATRICULA DO ALUNO: %s", alunos[i].matricula);
        printf("SEXO DO ALUNO: %c", alunos[i].sexo);
        printf("DATA DE NASCIMENTO: %d/%d/%d\n", alunos[i].data_nascimento.dia, alunos[i].data_nascimento.mes, alunos[i].data_nascimento.ano);
    }
}

void listarDisciplinas(Fichadisciplina *disciplinas, int qtdDisciplnas)
{
    int i;

    for (i = 0; i < qtdDisciplnas; i++)
    {
        printf("\nNOME DA DISCIPLINA: %s", disciplinas[i].nome);
        printf("CODIGO DA DISCIPLINA: %s", disciplinas[i].codigo);
        printf("NOME DO PROFESSOR: %s", disciplinas[i].professor);
        printf("SEMESTRE DA DISCIPLINA: %d\n", disciplinas[i].semestre);
    }
}

/*void listarProfessores(Fichaprofessor *professores, int qtdProfessor){

    int i;

    for(i=0; i<qtdProfessor; i++){

        printf("\n\nNOME DO PROFESSOR: %s", professores[i].nome);
        printf("CPF DO PROFESSOR: %s", professores[i].cpf);
        printf("\nMATRICULA DO PROFESSOR: %s", professores[i].matricula);
        printf("\nSEXO DO PROFESSOR: %c\n", professores[i].sexo);
        printf("\DATA DE NASCIMENTO: %d/%d/%d\n", professores[i].data_nascimento.dia,professores[i].data_nascimento.mes, professores[i].data_nascimento.ano );
    }
}

*/

int menuInicial();

int main()
{

    int sair = 0, opcao, qtdAlunos = 0, qtdProfessores = 0, qtdDisciplnas = 0, i = 0;
    Fichaaluno alunos[10];
    Fichaprofessor professores[10];
    Fichadisciplina disciplinas[10];

    while (!sair)
    {

        opcao = menuInicial();

        switch (opcao)
        {

        case 1:
        {
            alunos[qtdAlunos] = cadastraAluno();
            qtdAlunos++;
            break;
        }
        case 2:
        {
            professores[qtdProfessores] = cadastraProfessor();
            qtdProfessores++;
            break;
        }
        case 3:
        {
            disciplinas[qtdDisciplnas] = cadastraDisciplina();
            qtdDisciplnas++;
            break;
        }
        case 4:
        {

            listarAlunos(alunos, qtdAlunos);

            break;
        }
        //CHAMAR FUNÇÃO EMITIR RELATÓRIO; -> INICIAR SUBFUNCOES DE RELATORIOS
        case 5:
        {
            listarDisciplinas(disciplinas, qtdDisciplnas);

            break;
        }
        case 6:
        {
            printf("\n| PROJETO ESCOLA FINALIZADO |\n\n");
            sair = 1;
            break;

        default:
        {

            printf("**********\n");
            printf("OPCAO INVALIDA\n");
            printf("**********\n");
            break;
        }
        }
        }
    }

    return 0;
}

void flush()
{
    //funçao excelente para limpar o buffer de entrada.
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n')
    {
    }
}

Fichaaluno cadastraAluno()
{

    Fichaaluno aluno;

    printf("NOME COMPLETO: ");
    flush();
    fgets(aluno.nome, 20, stdin);
    printf("MATRICULA: ");
    fgets(aluno.matricula, 20, stdin);
    printf("CPF: ");
    fgets(aluno.cpf, 12, stdin);
    printf("SEXO: ");
    scanf("%c", &aluno.sexo);
    flush();
    printf("informe o dia de nascimento \n");
    scanf("%d", &aluno.data_nascimento.dia);
    printf("informe o mes de nascimento \n");
    scanf("%d", &aluno.data_nascimento.mes);
    printf("informe o ano de nascimento \n");
    scanf("%d", &aluno.data_nascimento.ano);

    printf("\n| ALUNO CADASTRADO |\n\n");

    return aluno;
}

Fichaprofessor cadastraProfessor()
{

    Fichaprofessor professor;

    printf("NOME COMPLETO: ");
    flush();
    fgets(professor.nome, 20, stdin);
    printf("MATRICULA: ");
    fgets(professor.matricula, 10, stdin);
    printf("CPF: ");
    fgets(professor.cpf, 12, stdin);
    flush();
    printf("SEXO: ");
    scanf("%c", &professor.sexo);
    printf("informe o dia de nascimento \n");
    scanf("%d", &professor.data_nascimento.dia);
    printf("informe o mes de nascimento \n");
    scanf("%d", &professor.data_nascimento.mes);
    printf("informe o ano de nascimento \n");
    scanf("%d", &professor.data_nascimento.ano);

    printf("\n|  PROFESSOR CADASTRADO  |\n");

    return professor;
}

Fichadisciplina cadastraDisciplina()
{

    Fichadisciplina disciplina;

    printf("INFORME O NOME DA DISCIPLINA: ");
    flush();
    fgets(disciplina.nome, 20, stdin);
    printf("INFORME O CODIGO DA DISCIPLINA: ");
    fgets(disciplina.codigo, 10, stdin);
    printf("NOME DO PROFESSOR: ");
    fgets(disciplina.professor, 20, stdin);
    printf("SEMESTRE: ");
    scanf("%d", &disciplina.semestre);

    printf("\n|  DISCIPLINA CADASTRADA  |\n");

    return disciplina;
}

int menuInicial()
{

    int opcao;

    printf("MENU INICIAL\nDIGITE A OPCAO DESEJADA:\n1 - CADASTRAR ALUNO\n2 - CADASTRAR PROFESSOR\n3 - CADASTRAR DISCIPLINA");
    printf("\n4 - EMITIR RELATORIO\n5 - LISTAR DISCIPLINAS\n6 - SAIR\nDigite o numero da opcao:  ");
    scanf("%d", &opcao);

    return opcao;
}
/*
int menuRelatorio(){

    printf("1 - LISTAR ALUNOS\n2 - LISTAR PROFESSORES\n3 - LISTAR DISCIPLINAS ");
}*/
