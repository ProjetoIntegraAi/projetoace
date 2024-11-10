#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Fun��es de autentica��o e cadastro
int verificarUsuario(char *nome, char *senha);
void cadastrarUsuario();
int realizarLogin();
void autenticar();

// Fun��es das funcionalidades do aplicativo
void pesquisarEstabelecimento();
void filtrarPorAcessibilidade();
void avaliarEstabelecimento();
void locaisSalvos();
void recomendacoes();

// Fun��o principal
int main() {
    printf("=== Bem-vindo ao aplicativo AcessoJ� ===\n");

    // Chama a fun��o de autentica��o (login ou cadastro)
    autenticar();

    int opcao;
    do {
        printf("\nEscolha uma funcionalidade:\n");
        printf("1. Pesquisar Estabelecimento\n");
        printf("2. Filtrar por Tipo de Acessibilidade\n");
        printf("3. Avaliar Estabelecimento\n");
        printf("4. Locais Salvos\n");
        printf("5. Recomenda��es\n");
        printf("0. Sair\n");
        printf("Op��o: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            pesquisarEstabelecimento();
        } else if (opcao == 2) {
            filtrarPorAcessibilidade();
        } else if (opcao == 3) {
            avaliarEstabelecimento();
        } else if (opcao == 4) {
            locaisSalvos();
        } else if (opcao == 5) {
            recomendacoes();
        } else if (opcao == 0) {
            printf("Saindo do aplicativo...\n");
        } else {
            printf("Op��o inv�lida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

// Fun��o para verificar se o usu�rio j� est� cadastrado
int verificarUsuario(char *nome, char *senha) {
    FILE *arquivo = fopen("usuarios.txt", "r");
    char nomeArquivo[MAX], senhaArquivo[MAX], emailArquivo[MAX];

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    while (fscanf(arquivo, "%s %s %s", nomeArquivo, senhaArquivo, emailArquivo) != EOF) {
        if (strcmp(nome, nomeArquivo) == 0 && strcmp(senha, senhaArquivo) == 0) {
            fclose(arquivo);
            return 1; // Usu�rio encontrado
        }
    }

    fclose(arquivo);
    return 0; // Usu�rio n�o encontrado
}

// Fun��o para cadastrar um novo usu�rio
void cadastrarUsuario() {
    FILE *arquivo = fopen("usuarios.txt", "a");
    char nome[MAX], senha[MAX], email[MAX];

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("=== Cadastro de Usu�rio ===\n");
    printf("Nome: ");
    scanf("%s", nome);
    printf("Senha: ");
    scanf("%s", senha);
    printf("Email: ");
    scanf("%s", email);

    fprintf(arquivo, "%s %s %s\n", nome, senha, email);
    fclose(arquivo);
    printf("Cadastro realizado com sucesso!\n");
}

// Fun��o para realizar o login
int realizarLogin() {
    char nome[MAX], senha[MAX];

    printf("=== Login ===\n");
    printf("Nome: ");
    scanf("%s", nome);
    printf("Senha: ");
    scanf("%s", senha);

    if (verificarUsuario(nome, senha)) {
        printf("Login realizado com sucesso!\n");
        return 1;
    } else {
        printf("Nome ou senha incorretos. Tente novamente.\n");
        return 0;
    }
}

// Fun��o para autenticar o usu�rio (login ou cadastro)
void autenticar() {
	setlocale(LC_ALL, "Portuguese");
    int opcao;
    int acesso = 0; // Controla o acesso do usu�rio

    while (!acesso) {
        printf("\nEscolha uma op��o:\n");
        printf("1. Cadastrar\n");
        printf("2. Login\n");
        printf("3. Entrar como Visitante\n");
        printf("Op��o: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            cadastrarUsuario();
        } else if (opcao == 2) {
            acesso = realizarLogin();
        } else if (opcao == 3) {
            printf("Entrando como visitante...\n");
            acesso = 1;
        } else {
            printf("Op��o inv�lida. Tente novamente.\n");
        }
    }
}

// Fun��o para pesquisar estabelecimentos com filtros
void pesquisarEstabelecimento() {
    int tipo;
    printf("=== Pesquisar Estabelecimento ===\n");
    printf("Escolha o tipo de estabelecimento:\n");
    printf("1. Restaurante\n");
    printf("2. Hotel\n");
    printf("3. Loja\n");
    printf("4. Estacionamento\n");
    printf("Op��o: ");
    scanf("%d", &tipo);

    if (tipo == 1) {
        printf("Exibindo resultados para Restaurantes...\n");
    } else if (tipo == 2) {
        printf("Exibindo resultados para Hot�is...\n");
    } else if (tipo == 3) {
        printf("Exibindo resultados para Lojas...\n");
    } else if (tipo == 4) {
        printf("Exibindo resultados para Estacionamentos...\n");
    } else {
        printf("Tipo de estabelecimento inv�lido.\n");
    }
}

// Fun��o para filtrar estabelecimentos por tipo de acessibilidade
void filtrarPorAcessibilidade() {
    int tipoAcessibilidade;
    printf("=== Filtrar por Tipo de Acessibilidade ===\n");
    printf("Escolha o tipo de acessibilidade:\n");
    printf("1. Acessibilidade para cadeirantes\n");
    printf("2. Acessibilidade para deficientes visuais\n");
    printf("3. Acessibilidade para deficientes auditivos\n");
    printf("4. Acessibilidade para idosos\n");
    printf("Op��o: ");
    scanf("%d", &tipoAcessibilidade);

    if (tipoAcessibilidade == 1) {
        printf("Exibindo resultados para acessibilidade de cadeirantes...\n");
    } else if (tipoAcessibilidade == 2) {
        printf("Exibindo resultados para acessibilidade para deficientes visuais...\n");
    } else if (tipoAcessibilidade == 3) {
        printf("Exibindo resultados para acessibilidade para deficientes auditivos...\n");
    } else if (tipoAcessibilidade == 4) {
        printf("Exibindo resultados para acessibilidade para idosos...\n");
    } else {
        printf("Tipo de acessibilidade inv�lido.\n");
    }
}
// Fun��o para avaliar um estabelecimento com uma nota de 1 a 5 estrelas
void avaliarEstabelecimento() {
    int escolhaEstabelecimento, avaliacao;

    printf("=== Avaliar Estabelecimento ===\n");
    printf("Escolha o estabelecimento que deseja avaliar:\n");
    printf("1. Pet Zoo An�polis\n");
    printf("2. UniEVANG�LICA - Universidade Evang�lica de Goi�s\n");
    printf("3. Coco Bambu An�polis\n");
    printf("4. Brasil Park Shopping\n");
    printf("5. McDonald's\n");
    printf("Op��o: ");
    scanf("%d", &escolhaEstabelecimento);

    // Verificar se a escolha do estabelecimento � v�lida
    if (escolhaEstabelecimento >= 1 && escolhaEstabelecimento <= 5) {
        printf("Escolha uma avalia��o de 1 a 5 estrelas para este estabelecimento:\n");
        printf("Avalia��o: ");
        scanf("%d", &avaliacao);

        // Verificar se a avalia��o est� no intervalo de 1 a 5
        if (avaliacao >= 1 && avaliacao <= 5) {
            printf("Obrigado pela sua avalia��o! Voc� avaliou o estabelecimento com %d estrelas.\n", avaliacao);
        } else {
            printf("Avalia��o inv�lida. Por favor, insira uma nota de 1 a 5 estrelas.\n");
        }
    } else {
        printf("Op��o de estabelecimento inv�lida. Tente novamente.\n");
    }
}

// Fun��o para exibir locais salvos do usu�rio
void locaisSalvos() {
    printf("=== Locais Salvos ===\n");
    printf("1. Restaurante Amigos (4.5)\n");
    printf("2. Hotel Conforto (4.4)\n");
    printf("3. Loja de Conveni�ncia 24h (3.3)\n");
    printf("Esses s�o os locais salvos. Adicione novos locais favoritos no menu de pesquisa.\n");
}

// Fun��o para exibir recomenda��es para o usu�rio
void recomendacoes() {
    printf("=== Recomenda��es para Voc� ===\n");
    printf("1. Restaurante Vista Alegre (acess�vel para cadeirantes)\n");
    printf("2. Museu Cultural (acess�vel para deficientes visuais)\n");
    printf("3. Shopping Central (acess�vel para idosos e cadeirantes)\n");
    printf("Essas s�o as recomenda��es com base no seu hist�rico e prefer�ncias.\n");
}



