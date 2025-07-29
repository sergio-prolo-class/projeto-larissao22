// alma-de-flores/src/music_manager.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição e inicialização das variáveis globais
Music collection[MAX_MUSICS];
int music_count = 0;

// Função para limpar o buffer de entrada do teclado
void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// Inicializa o gerenciador (carrega dados existentes)
void init_manager()
{
    printf("Preparando o jardim 'Alma de Flores'...\n");
    load_music_data("data/songs.dat");  // Tenta carregar dados existentes
}

// Adiciona uma nova música (flor)
void add_music()
{
    if (music_count >= MAX_MUSICS) {
        printf("Seu jardim está cheio! Não é possível plantar mais flores por enquanto.\n");
        return;
    }

    printf("\n--- Plantar Nova Flor (Adicionar Música) ---\n");
    printf("Título da Flor: ");
    fgets(collection[music_count].title, MAX_STR_LEN, stdin);
    collection[music_count].title[strcspn(collection[music_count].title, "\n")] = 0;  // Remove newline

    printf("Artista/Jardineiro: ");
    fgets(collection[music_count].artist, MAX_STR_LEN, stdin);
    collection[music_count].artist[strcspn(collection[music_count].artist, "\n")] = 0;

    printf("Álbum/Canteiro: ");
    fgets(collection[music_count].album, MAX_STR_LEN, stdin);
    collection[music_count].album[strcspn(collection[music_count].album, "\n")] = 0;

    printf("Gênero/Tipo de Flor: ");
    fgets(collection[music_count].genre, MAX_STR_LEN, stdin);
    collection[music_count].genre[strcspn(collection[music_count].genre, "\n")] = 0;

    printf("Humor/Essência da Flor (ex: alegre, calma, vibrante): ");
    fgets(collection[music_count].mood, MAX_STR_LEN, stdin);
    collection[music_count].mood[strcspn(collection[music_count].mood, "\n")] = 0;

    // A duração pode ser adicionada depois, por simplicidade inicial
    collection[music_count].duration_seconds = 0;

    music_count++;
    printf("Flor '%s' plantada com sucesso!\n", collection[music_count - 1].title);
    save_music_data("data/songs.dat");  // Salva automaticamente após adicionar
}

// Lista todas as músicas (contempla o jardim)
void list_all_music()
{
    if (music_count == 0) {
        printf("\nSeu jardim está vazio. Comece a plantar flores!\n");
        return;
    }

    printf("\n--- Contemplando o Jardim de Flores Musical ---\n");
    for (int i = 0; i < music_count; i++) {
        printf("\nFlor #%d:\n", i + 1);
        printf("  Título: %s\n", collection[i].title);
        printf("  Artista: %s\n", collection[i].artist);
        printf("  Álbum: %s\n", collection[i].album);
        printf("  Gênero: %s\n", collection[i].genre);
        printf("  Humor: %s\n", collection[i].mood);
        // printf("  Duração: %d segundos\n", collection[i].duration_seconds); // Opcional
    }
    printf("---------------------------------------------\n");
}

// Salva os dados das músicas em um arquivo binário
void save_music_data(const char *filename)
{
    FILE *file = fopen(filename, "wb");  // 'wb' para escrita binária
    if (file == NULL) {
        perror("Erro ao abrir arquivo para salvar");
        return;
    }
    fwrite(&music_count, sizeof(int), 1, file);            // Salva o número de músicas
    fwrite(collection, sizeof(Music), music_count, file);  // Salva o array de músicas
    fclose(file);
    printf("Jardim salvo com sucesso em '%s'.\n", filename);
}

// Carrega os dados das músicas de um arquivo binário
void load_music_data(const char *filename)
{
    FILE *file = fopen(filename, "rb");  // 'rb' para leitura binária
    if (file == NULL) {
        printf("Nenhum jardim salvo encontrado. Começando um novo.\n");
        return;  // Arquivo não existe, inicia vazio
    }
    fread(&music_count, sizeof(int), 1, file);            // Lê o número de músicas
    fread(collection, sizeof(Music), music_count, file);  // Lê o array de músicas
    fclose(file);
    printf("Jardim carregado com %d flores.\n", music_count);
}