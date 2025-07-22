#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSICAS 100  // Capacidade máxima de músicas
#define MAX_STR 100      //  Tamanho máximo para strings de título, artista, etc.

// Estrutura para representar uma música
typedef struct {
    int id;
    char titulo;
    char artista;
    char genero;
    int ano;
} Musica;

// Variáveis Globais
Musica musicas;
int num_musicas = 0;
int proximo_id = 1;  // ID para garantir unicidade das músicas

// Prototópios das Funções
void menu_princiapl();
void cadastrar_msica(const char *titulo, const char *artista, const char *album, int ano);
void listar_musicas();
void editar_musicas();
void buscar_musica();   // Nova função para buscar
void remover_musica();  // Nova função para remover
void salvar_musicas_em_arquivo(const char *nome_arquivo);
void carregar_musicas_em_arquivo(const char *nome_arquivo);
void adicionar_musicas_inicial();  // Função para adicionar a "pior música"

// Função Principal
int main()
{
    carregar_musicas_em_arquivo("luify_data.dat");  // Tenta carregar dados existentes
    if (num_musicas == 0) {                         // Se não houver músicas carregadas, adiciona a inicial
        adicionar_musicas_inicial();
    }
    menu_princiapl();

    salvar_musicas_em_arquivo("luify_data.dat");  // Salva os dados antes de sair
    printf("Obrigado por usar o Luify! Seus dados foram salvos.\n");
    return 0;
}

// Implementação das Funções

// Exibe o menu principal e gerencia as opções
void menu_principal()
{
    int opcao;
    do {
        printf("\n--- Luify: Gerenciador de Músicas (CLI) ---\n");
        printf("1. Cadastrar Nova Música\n");
        printf("2. Listar Todas as Músicas\n");
        printf("3. Editar Música Existente\n");
        printf("4. Buscar Música por Título/Artista\n");
        printf("5. Remover Música\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();  // Consumir o '\n' pendente após scanf

        switch (opcao) {
            case 1:
                // Passa NULL para indicar que os valores serão lidos do usuário
                cadastrar_msica(NULL, NULL, NULL, 0);
                break;
            case 2:
                listar_musicas();
                break;
            case 3:
                editar_musicas();
                break;
            case 4:
                buscar_musica();
                break;
            case 5:
                remover_musica();
                break;
            case 6:
                // A mensagem de saída e salvamento está na main
                break;
            default:
                printf("Opção inválida. Por favor, tente novamente.\n");
        }
    } while (opcao != 6);
}

void cadastrar_musica(const char *titulo_padrao, const char *artista_padrao, const char *album_padrao, int ano_padrao)
{
    if (num_musicas >= MAX_MUSICAS) {
        printf("Limite máximo de músicas atingido! Não é possível adicionar mais.\n");
        return;
    }

    Musica nova_musica;
    nova_musica.id = proximo_id++;

    printf("\n--- Cadastrar Nova Música ---\n");

    if (titulo_padrao) {
        strncpy(nova_musica.titulo, titulo_padrao, MAX_STR - 1);
        nova_musica.titulo[MAX_STR - 1] = '\0';
        printf("Título (Pré-preenchido): %s\n", nova_musica.titulo);
    } else {
        printf("Título: ");
        fgets(nova_musica.titulo, MAX_STR, stdin);
        nova_musica.titulo[strcspn(nova_musica.titulo, "\n")] = '\0';
    }

    if (artista_padrao) {
        strncpy(nova_musica.artista, artista_padrao, MAX_STR - 1);
        nova_musica.artista[MAX_STR - 1] = '\0';
        printf("Artista (Pré-preenchido): %s\n", nova_musica.artista);
    } else {
        printf("Artista: ");
        fgets(nova_musica.artista, MAX_STR, stdin);
        nova_musica.artista[strcspn(nova_musica.artista, "\n")] = '\0';
    }

    if (album_padrao) {
        strncpy(nova_musica.album, album_padrao, MAX_STR - 1);
        nova_musica.album[MAX_STR - 1] = '\0';
        printf("Álbum (Pré-preenchido): %s\n", nova_musica.album);
    } else {
        printf("Álbum: ");
        fgets(nova_musica.album, MAX_STR, stdin);
        nova_musica.album[strcspn(nova_musica.album, "\n")] = '\0';
    }

    if (ano_padrao > 0) {
        nova_musica.ano = ano_padrao;
        printf("Ano (Pré-preenchido): %d\n", nova_musica.ano);
    } else {
        printf("Ano: ");
        scanf("%d", &nova_musica.ano);
        getchar();
    }

    musicas[num_musicas++] = nova_musica;
    printf("Música '%s' (ID: %d) cadastrada com sucesso!\n", nova_musica.titulo, nova_musica.id);
}

void listar_musicas()
{
    if (num_musicas == 0) {
        printf("\nNenhuma música cadastrada ainda no Luify.\n");
        return;
    }

    printf("\n--- Lista de Músicas do Luify ---\n");
    for (int i = 0; i < num_musicas; i++) {
        printf("ID: %d | Título: %s | Artista: %s | Álbum: %s | Ano: %d\n",
               musicas[i].id, musicas[i].titulo, musicas[i].artista, musicas[i].album, musicas[i].ano);
    }
}

void editar_musica()
{
    int id_para_editar;
    printf("\n--- Editar Música ---\n");
    printf("Digite o ID da música que deseja editar: ");
    scanf("%d", &id_para_editar);
    getchar();

    int encontrada = 0;
    for (int i = 0; i < num_musicas; i++) {
        if (musicas[i].id == id_para_editar) {
            encontrada = 1;
            printf("Música encontrada! Editando: '%s' (ID: %d)\n", musicas[i].titulo, musicas[i].id);

            printf("Novo Título (atual: '%s'): ", musicas[i].titulo);
            fgets(musicas[i].titulo, MAX_STR, stdin);
            musicas[i].titulo[strcspn(musicas[i].titulo, "\n")] = '\0';

            printf("Novo Artista (atual: '%s'): ", musicas[i].artista);
            fgets(musicas[i].artista, MAX_STR, stdin);
            musicas[i].artista[strcspn(musicas[i].artista, "\n")] = '\0';

            printf("Novo Álbum (atual: '%s'): ", musicas[i].album);
            fgets(musicas[i].album, MAX_STR, stdin);
            musicas[i].album[strcspn(musicas[i].album, "\n")] = '\0';

            printf("Novo Ano (atual: %d): ", musicas[i].ano);
            scanf("%d", &musicas[i].ano);
            getchar();

            printf("Música '%s' atualizada com sucesso!\n", musicas[i].titulo);
            break;
        }
    }

    if (!encontrada) {
        printf("Música com ID %d não encontrada no Luify.\n", id_para_editar);
    }
}

void buscar_musica()
{
    char termo_busca[MAX_STR];
    printf("\n--- Buscar Música ---\n");
    printf("Digite o título ou artista para buscar: ");
    fgets(termo_busca, MAX_STR, stdin);
    termo_busca[strcspn(termo_busca, "\n")] = '\0';

    int encontrada = 0;
    printf("\nResultados da Busca:\n");
    for (int i = 0; i < num_musicas; i++) {
        // Usa strstr para busca simples (case-sensitive)
        if (strstr(musicas[i].titulo, termo_busca) != NULL || strstr(musicas[i].artista, termo_busca) != NULL) {
            printf("ID: %d | Título: %s | Artista: %s | Álbum: %s | Ano: %d\n",
                   musicas[i].id, musicas[i].titulo, musicas[i].artista, musicas[i].album, musicas[i].ano);
            encontrada = 1;
        }
    }

    if (!encontrada) {
        printf("Nenhuma música encontrada com o termo '%s'.\n", termo_busca);
    }
}

void remover_musica()
{
    int id_para_remover;
    printf("\n--- Remover Música ---\n");
    printf("Digite o ID da música que deseja remover: ");
    scanf("%d", &id_para_remover);
    getchar();

    int indice_removido = -1;
    for (int i = 0; i < num_musicas; i++) {
        if (musicas[i].id == id_para_remover) {
            indice_removido = i;
            break;
        }
    }

    if (indice_removido != -1) {
        printf("Música '%s' (ID: %d) será removida.\n", musicas[indice_removido].titulo, musicas[indice_removido].id);
        for (int i = indice_removido; i < num_musicas - 1; i++) {
            musicas[i] = musicas[i + 1];
        }
        num_musicas--;
        printf("Música removida com sucesso!\n");
    } else {
        printf("Música com ID %d não encontrada no Luify.\n", id_para_remover);
    }
}

void salvar_musicas_em_arquivo(const char *nome_arquivo)
{
    FILE *arquivo = fopen(nome_arquivo, "wb");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo para salvar músicas");
        return;
    }
    fwrite(&num_musicas, sizeof(int), 1, arquivo);
    fwrite(&proximo_id, sizeof(int), 1, arquivo);
    fwrite(musicas, sizeof(Musica), num_musicas, arquivo);
    fclose(arquivo);
    printf("\nDados do Luify salvos em '%s'.\n", nome_arquivo);
}

void carregar_musicas_de_arquivo(const char *nome_arquivo)
{
    FILE *arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        printf("Arquivo '%s' não encontrado. Iniciando Luify com dados vazios ou iniciais.\n", nome_arquivo);
        num_musicas = 0;
        proximo_id = 1;
        return;
    }
    fread(&num_musicas, sizeof(int), 1, arquivo);
    fread(&proximo_id, sizeof(int), 1, arquivo);
    fread(musicas, sizeof(Musica), num_musicas, arquivo);
    fclose(arquivo);
    printf("Dados do Luify carregados de '%s'.\n", nome_arquivo);
}

void adicionar_musica_inicial()
{
    printf("Adicionando a 'pior música que possa imaginar' ao Luify...\n");
    cadastrar_musica("O Grito Silencioso do Caos", "A Orquestra do Desespero", "Fragmentos Incompreensíveis", 2019);
    // Nota: proximo_id já foi incrementado em cadastrar_musica.
    printf("Música inicial adicionada! (ID: %d)\n", proximo_id - 1);
}