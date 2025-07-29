// alma-de-flores/src/music_manager.h

#ifndef MUSIC_MANAGER_H
#define MUSIC_MANAGER_H

#define MAX_STR_LEN 100  // Tamanho máximo para strings como título, artista, etc.
#define MAX_MUSICS 50    // Capacidade máxima de músicas no nosso "jardim"

// Estrutura para representar uma música
typedef struct {
    char title[MAX_STR_LEN];
    char artist[MAX_STR_LEN];
    char album[MAX_STR_LEN];
    char genre[MAX_STR_LEN];
    char mood[MAX_STR_LEN];  // Nosso campo criativo: o humor/sentimento da música
    int duration_seconds;    // Duração da música em segundos (opcional, para futuras expansões)
} Music;

// Variáveis globais (ou que serão passadas entre funções)
extern Music collection[MAX_MUSICS];  // Array para armazenar as músicas
extern int music_count;               // Contador de músicas no array

// Protótipos das funções
void init_manager();  // Inicializa o gerenciador de músicas
void add_music();
void list_all_music();
void save_music_data(const char *filename);
void load_music_data(const char *filename);
void clear_input_buffer();  // Função auxiliar para limpar o buffer de entrada

#endif  // MUSIC_MANAGER_H