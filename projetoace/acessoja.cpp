#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Funções de autenticação e cadastro
int verificarUsuario(char *nome, char *senha);
void cadastrarUsuario();
int realizarLogin();
void autenticar();

// Funções das funcionalidades do aplicativo
void pesquisarEstabelecimento();
void filtrarPorAcessibilidade();
void avaliarEstabelecimento();
void locaisSalvos();
void recomendacoes();

// Função principal
int main() {
    printf("=== Bem-vindo ao aplicativo AcessoJá ===\n");

    // Chama a função de autenticação (login ou cadastro)
    autenticar();

    int opcao;
    do {
        printf("\nEscolha uma funcionalidade:\n");
        printf("1. Pesquisar Estabelecimento\n");
        printf("2. Filtrar por Tipo de Acessibilidade\n");
        printf("3. Avaliar Estabelecimento\n");
        printf("4. Locais Salvos\n");
        printf("5. Recomendações\n");
        printf("0. Sair\n");
        printf("Opção: ");
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
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

// Função para verificar se o usuário já está cadastrado
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
            return 1; // Usuário encontrado
        }
    }

    fclose(arquivo);
    return 0; // Usuário não encontrado
}

// Função para cadastrar um novo usuário
void cadastrarUsuario() {
    FILE *arquivo = fopen("usuarios.txt", "a");
    char nome[MAX], senha[MAX], email[MAX];

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("=== Cadastro de Usuário ===\n");
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

// Função para realizar o login
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

// Função para autenticar o usuário (login ou cadastro)
void autenticar() {
	setlocale(LC_ALL, "Portuguese");
    int opcao;
    int acesso = 0; // Controla o acesso do usuário

    while (!acesso) {
        printf("\nEscolha uma opção:\n");
        printf("1. Cadastrar\n");
        printf("2. Login\n");
        printf("3. Entrar como Visitante\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            cadastrarUsuario();
        } else if (opcao == 2) {
            acesso = realizarLogin();
        } else if (opcao == 3) {
            printf("Entrando como visitante...\n");
            acesso = 1;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }
}

// Função para pesquisar estabelecimentos com filtros
void pesquisarEstabelecimento() {
    int tipo;
    printf("=== Pesquisar Estabelecimento ===\n");
    printf("Escolha o tipo de estabelecimento:\n");
    printf("1. Restaurante\n");
    printf("2. Hotel\n");
    printf("3. Loja\n");
    printf("4. Estacionamento\n");
    printf("Opção: ");
    scanf("%d", &tipo);

    if (tipo == 1) {
        printf("Exibindo resultados para Restaurantes...\n");
    } else if (tipo == 2) {
        printf("Exibindo resultados para Hotéis...\n");
    } else if (tipo == 3) {
        printf("Exibindo resultados para Lojas...\n");
    } else if (tipo == 4) {
        printf("Exibindo resultados para Estacionamentos...\n");
    } else {
        printf("Tipo de estabelecimento inválido.\n");
    }
}

// Função para filtrar estabelecimentos por tipo de acessibilidade
void filtrarPorAcessibilidade() {
    int tipoAcessibilidade;
    printf("=== Filtrar por Tipo de Acessibilidade ===\n");
    printf("Escolha o tipo de acessibilidade:\n");
    printf("1. Acessibilidade para cadeirantes\n");
    printf("2. Acessibilidade para deficientes visuais\n");
    printf("3. Acessibilidade para deficientes auditivos\n");
    printf("4. Acessibilidade para idosos\n");
    printf("Opção: ");
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
        printf("Tipo de acessibilidade inválido.\n");
    }
}
// Função para avaliar um estabelecimento com uma nota de 1 a 5 estrelas
void avaliarEstabelecimento() {
    int escolhaEstabelecimento, avaliacao;

    printf("=== Avaliar Estabelecimento ===\n");
    printf("Escolha o estabelecimento que deseja avaliar:\n");
    printf("1. Pet Zoo Anápolis\n");
    printf("2. UniEVANGÉLICA - Universidade Evangélica de Goiás\n");
    printf("3. Coco Bambu Anápolis\n");
    printf("4. Brasil Park Shopping\n");
    printf("5. McDonald's\n");
    printf("Opção: ");
    scanf("%d", &escolhaEstabelecimento);

    // Verificar se a escolha do estabelecimento é válida
    if (escolhaEstabelecimento >= 1 && escolhaEstabelecimento <= 5) {
        printf("Escolha uma avaliação de 1 a 5 estrelas para este estabelecimento:\n");
        printf("Avaliação: ");
        scanf("%d", &avaliacao);

        // Verificar se a avaliação está no intervalo de 1 a 5
        if (avaliacao >= 1 && avaliacao <= 5) {
            printf("Obrigado pela sua avaliação! Você avaliou o estabelecimento com %d estrelas.\n", avaliacao);
        } else {
            printf("Avaliação inválida. Por favor, insira uma nota de 1 a 5 estrelas.\n");
        }
    } else {
        printf("Opção de estabelecimento inválida. Tente novamente.\n");
    }
}

// Função para exibir locais salvos do usuário
void locaisSalvos() {
    printf("=== Locais Salvos ===\n");
    printf("1. Restaurante Amigos (4.5)\n");
    printf("2. Hotel Conforto (4.4)\n");
    printf("3. Loja de Conveniência 24h (3.3)\n");
    printf("Esses são os locais salvos. Adicione novos locais favoritos no menu de pesquisa.\n");
}

// Função para exibir recomendações para o usuário
void recomendacoes() {
    printf("=== Recomendações para Você ===\n");
    printf("1. Restaurante Vista Alegre (acessível para cadeirantes)\n");
    printf("2. Museu Cultural (acessível para deficientes visuais)\n");
    printf("3. Shopping Central (acessível para idosos e cadeirantes)\n");
    printf("Essas são as recomendações com base no seu histórico e preferências.\n");
}



