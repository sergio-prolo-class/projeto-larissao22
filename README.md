# Luify: Gerenciador de Músicas em C (CLI)

Este repositório contém o código-fonte do **Luify**, um gerenciador de músicas desenvolvido em C para linha de comando (CLI). O projeto serve como um exemplo prático de um sistema CRUD (Create, Read, Update, Delete) de dados, focado no gerenciamento de metadados de músicas.

**Importante:** O Luify é um projeto de demonstração focado em lógica de dados. Ele **não** possui interface gráfica, funcionalidades de reprodução de áudio ou recursos de rede complexos (como streaming).

---
# Luify: Gerenciador de Músicas em C (Linha de Comando)

Este é um projeto simples de um gerenciador de músicas desenvolvido em linguagem C. Ele opera via linha de comando (CLI) e demonstra as funcionalidades básicas de um sistema CRUD (Create, Read, Update, Delete) para metadados de músicas.

**Importante:** Este projeto não inclui interface gráfica, reprodução de áudio ou funcionalidades de rede complexas. Ele é focado no gerenciamento e persistência de dados.

## Funcionalidades

* **Cadastrar Música**: Adicione novas músicas com título, artista, álbum e ano.
* **Listar Músicas**: Visualize todas as músicas cadastradas com seus detalhes.
* **Editar Música**: Modifique as informações de uma música existente usando seu ID.
* **Buscar Música**: Encontre músicas por título ou artista.
* **Remover Música**: Exclua músicas do sistema.
* **Persistência de Dados**: As músicas cadastradas são salvas em um arquivo binário (`luify_data.dat`) e carregadas automaticamente na próxima execução.

## Como Compilar e Executar

Para compilar e executar este projeto, você precisará de um compilador C (como o GCC).

1.  **Baixe o Código**:
    * Clone o repositório:
        ```bash
        git clone [https://github.com/SEU_USUARIO/Luify-Music-Manager-C.git](https://github.com/PROJETO-LARISSAO22/Luify-Music-Manager-C.git)
        ```
    * Ou baixe o ZIP do repositório.

2.  **Navegue até a Pasta do Projeto**:
    ```bash
    cd Luify-Music-Manager-C
    ```

3.  **Compile o Código**:
    No terminal, use o GCC para compilar o arquivo `.c`:
    ```bash
    gcc luify_manager.c -o luify_manager
    ```
    Isso criará um executável chamado `luify_manager` (ou `luify_manager.exe` no Windows).

4.  **Execute o Programa**:
    ```bash
    ./luify_manager
    ```
    (No Windows, você pode precisar digitar `luify_manager.exe` ou apenas `luify_manager`)

### Exemplo de Uso (Pré-carregado)

Ao iniciar pela primeira vez (ou se o arquivo `luify_data.dat` não existir), o Luify incluirá automaticamente uma música de exemplo:

* **Título**: O Grito Silencioso do Caos
* **Artista**: A Orquestra do Desespero
* **Álbum**: Fragmentos Incompreensíveis
* **Ano**: 2019

Você pode usar as opções do menu para interagir com esta música e adicionar outras!

## Contribuição

Sinta-se à vontade para explorar, modificar e melhorar este código. Pull requests são bem-vindos!

## Licença

Este projeto está licenciado sob a licença MIT. Veja o arquivo `LICENSE` para mais detalhes.
## Funcionalidades Implementadas

O Luify oferece as seguintes operações básicas de gerenciamento de músicas:

* **Cadastrar Música**: Adicione novas músicas com informações como título, artista, álbum e ano de lançamento.
* **Listar Músicas**: Visualize todas as músicas cadastradas no sistema.
* **Editar Música**: Modifique os detalhes de uma música existente usando seu ID único.
* **Buscar Música**: Encontre músicas rapidamente pesquisando por título ou artista.
* **Remover Música**: Exclua músicas indesejadas do seu catálogo.
* **Persistência de Dados**: Todas as músicas são salvas automaticamente em um arquivo binário (`luify_data.dat`) e carregadas ao iniciar o programa, garantindo que seus dados não sejam perdidos entre as sessões.

---

## Como Compilar e Executar

Para utilizar o Luify, você precisará de um **compilador C** (como o GCC) instalado em seu sistema operacional.

### Comandos do Terminal

Navegue até o diretório do projeto no seu terminal.

| Comando | Descrição |
| --- | --- |
| `ls` | Lista os arquivos e diretórios |
| `cd <diretório>` | Muda o diretório atual |
| `cd ..` | Volta um diretório |
| `mkdir <diretório>` | Cria um diretório |
| `code <arquivo>` | Abre o arquivo no VS Code |
| `rm <arquivo>` | Remove o arquivo |
| `touch <arquivo>` | Cria um arquivo |
| `clear` | Limpa a tela |

Para compilar e executar um arquivo em C no terminal, use os seguintes comandos:

```bash
gcc <arquivo>.c -o <arquivo>
./<arquivo>
```

*Obs*: se a biblioteca `math.h` for usada, adicione o parâmetro `-lm` no final do comando.

## Teclas de atalho

| Ação | Tecla |
| --- | --- |
| Compilar e executar | `Ctrl-F5` |
| Compilar sem executar | `Ctrl-Shift-B` |
| Depurar | `F5` |
| Indentar automaticamente | `Ctrl-Shift-I` |
