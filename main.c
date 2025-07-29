// alma-de-flores/src/main.c

#include <stdio.h>
#include <stdlib.h>         // Para system()
#include "music_manager.h"  // Inclui nosso cabeçalho

// Caminho para o arquivo de dados
#define DATA_FILE "data/songs.dat"

void display_menu()
{
    printf("\n--- Alma de Flores: Gerenciador de Música ---\n");
    printf("1. Plantar Nova Flor (Adicionar Música)\n");
    printf("2. Contemplar o Jardim (Listar Músicas)\n");
    printf("3. Podar Flores (Remover Música - A ser implementado)\n");
    printf("4. Encontrar uma Flor (Buscar Música - A ser implementado)\n");
    printf("5. Regar e Salvar o Jardim\n");
    printf("0. Sair do Jardim\n");
    printf("Escolha sua opção: ");
}

int main()
{
// Garante que o diretório 'data' exista
// Em Windows, use "mkdir data"
// Em Linux/macOS, use "mkdir -p data"
#ifdef _WIN32
    system("mkdir data");
#else
    system("mkdir -p data");
#endif

    init_manager();  // Inicializa o gerenciador, tentando carregar dados

    int choice;
    do {
        display_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Entrada inválida. Por favor, digite um número.\n");
            clear_input_buffer();  // Limpa o buffer após entrada inválida
            continue;
        }
        clear_input_buffer();  // Limpa o buffer após ler o número

        switch (choice) {
            case 1:
                add_music();
                break;
            case 2:
                list_all_music();
                break;
            case 3:
                printf("Funcionalidade 'Podar Flores' em desenvolvimento...\n");
                break;
            case 4:
                printf("Funcionalidade 'Encontrar uma Flor' em desenvolvimento...\n");
                break;
            case 5:
                save_music_data(DATA_FILE);
                break;
            case 0:
                printf("Saindo do jardim 'Alma de Flores'. Até logo!\n");
                break;
            default:
                printf("Opção inválida. Por favor, tente novamente.\n");
        }
    } while (choice != 0);

    return 0;
}