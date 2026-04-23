#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ----- Definição de constantes  
#define MAX_LIVROS 50
#define TAM_STRING 100

// ----- Definição da estrutura de dados para os livros
struct Livros{
    char titulo[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
};

// ------Função para limpar o buffer de entrada
void limparBufferentrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ----- Função prinicipal (main)

int main() {
    struct Livros biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

    do {
                // ----- Exibir o menu de opções.
            printf("==============================================\n");
            printf("\n=== Sistema de Gerenciamento de Biblioteca ===\n");
            printf("==============================================\n");
            printf("1. Cadastrar um novo livro\n");
            printf("2. Listar todos os livros\n");
            printf("3. Sair\n");
            printf("----------------------------------------------\n");
            printf("Escolha uma opção: ");

            // ----- Ler a opção do usuário
            scanf("%d", &opcao);
            limparBufferentrada(); // Limpar o buffer de entrada

        // ---- processar a opção escolhida
        switch (opcao) {
            case 1:
             printf("=== Cadastrar um novo livro ===\n");

                if (totalLivros < MAX_LIVROS) {
            
                    printf("Nome do livro: ");
                    fgets(biblioteca[totalLivros].titulo, TAM_STRING, stdin);
                    
                    printf("Digite o autor: ");
                    fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);
            
                    printf("Digite a editora: ");
                    fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

                    biblioteca[totalLivros].titulo[strcspn(biblioteca[totalLivros].titulo, "\n")] = '\0';
                    biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
                    biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';

                    printf("Digite a edição: ");
                    scanf("%d", &biblioteca[totalLivros].edicao);
                    limparBufferentrada(); // Limpar o buffer de entrada

                    totalLivros++;
            
                    printf("Livro cadastrado com sucesso!\n");          
                } else {
                     printf("Capacidade máxima de livros atingida. Não é possível cadastrar mais livros.\n");
                    }

                    printf("\nPressione Enter para continuar...");
                    getchar(); // Esperar o usuário pressionar Enter
                    break;

                    case 2:
                        printf("=== Listar todos os livros ===\n");

                        if (totalLivros == 0) {
                            printf("Nenhum livro cadastrado.\n");
                    } else {
                        for (int i = 0; i < totalLivros; i++) {
                            printf("Livro %d:\n", i + 1);
                            printf("Título: %s\n", biblioteca[i].titulo);
                            printf("Autor: %s\n", biblioteca[i].autor);
                            printf("Editora: %s\n", biblioteca[i].editora);
                            printf("Edição: %d\n", biblioteca[i].edicao);
                            printf("----------------------------------------------\n");
                        }
                    }

                    printf("\nPressione Enter para continuar...");
                    getchar(); // Esperar o usuário pressionar Enter
                    break;

                    case 3:
                    printf("Saindo do programa. Até logo!\n");
                    break;

                    default:
                    printf("Opção inválida. Por favor, escolha uma opção válida.\n");
                    printf("\nPressione Enter para continuar...");
                    getchar(); // Esperar o usuário pressionar Enter
                    break;
        }
    } while (opcao != 3);
}

// --- Executar o programa ---
// gcc biblioteca.c -o biblioteca.exe


