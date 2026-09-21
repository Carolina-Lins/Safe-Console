#include <stdio.h>
#include <string.h>

#define TAM_BUFFER 256

void ler_string(char *destino, int tamanho);
int ler_numero(int *numero);
void exibir_menu(void);
void mascarar_dados(char *dados);
int validar_senha(const char *senha);
void mostrar_forca_senha(const char *senha);
void cifrar_cesar(char *texto, int deslocamento);
void descifrar_cesar(char *texto, int deslocamento);
void aplicar_rot13(char *texto);
void cifrar_xor(char *texto, int tamanho, char chave);
void exibir_hex(const char *texto, int tamanho);
void exibir_codigos_ascii(const char *texto);

int main(void)
{
    char texto[TAM_BUFFER];
    int opcao;
    char linha[TAM_BUFFER];
    int deslocamento;
    int tamanho;
    char chave;

    do
    {
        exibir_menu();
        if (ler_numero(&opcao) == 0)
        {
            opcao = -1;
        }

        switch (opcao)
        {
        case 1:
            printf("Digite o dado sensivel: ");
            ler_string(texto, TAM_BUFFER);
            mascarar_dados(texto);
            printf("Dado mascarado: %s\n", texto);
            break;

        case 2:
            printf("Digite a senha: ");
            ler_string(texto, TAM_BUFFER);
            if (validar_senha(texto) == 1)
            {
                printf("Senha valida\n");
            }
            else
            {
                printf("Senha invalida\n");
            }
            mostrar_forca_senha(texto);
            break;

        case 3:
            printf("Digite a mensagem: ");
            ler_string(texto, TAM_BUFFER);
            printf("Digite o deslocamento: ");
            if (ler_numero(&deslocamento) == 0)
            {
                printf("Deslocamento invalido\n");
                break;
            }
            cifrar_cesar(texto, deslocamento);
            printf("Mensagem cifrada: %s\n", texto);
            break;

        case 4:
            printf("Digite a mensagem cifrada: ");
            ler_string(texto, TAM_BUFFER);
            printf("Digite o deslocamento: ");
            if (ler_numero(&deslocamento) == 0)
            {
                printf("Deslocamento invalido\n");
                break;
            }
            descifrar_cesar(texto, deslocamento);
            printf("Mensagem descifrada: %s\n", texto);
            break;

        case 5:
            printf("Digite a mensagem: ");
            ler_string(texto, TAM_BUFFER);
            printf("Digite a chave (um caractere): ");
            ler_string(linha, TAM_BUFFER);
            if (linha[0] == '\0')
            {
                printf("Chave vazia\n");
                break;
            }
            chave = linha[0];
            tamanho = strlen(texto);
            cifrar_xor(texto, tamanho, chave);
            printf("Payload em hexadecimal: ");
            exibir_hex(texto, tamanho);
            cifrar_xor(texto, tamanho, chave);
            printf("Mensagem recuperada com a mesma chave: %s\n", texto);
            break;

        case 6:
            printf("Digite a mensagem: ");
            ler_string(texto, TAM_BUFFER);
            aplicar_rot13(texto);
            printf("Resultado ROT13: %s\n", texto);
            break;
        
        case 7:
            printf("Digite o texto: ");
            ler_string(texto, TAM_BUFFER);
            exibir_codigos_ascii(texto);
            break

        case 0:
            printf("Encerrando o programa\n");
            break;

        default:
            printf("Opcao invalida\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}

void ler_string(char *destino, int tamanho)
{
    int posicao;
    int c;

    if (fgets(destino, tamanho, stdin) == NULL)
    {
        destino[0] = '\0';
        return;
    }

    posicao = strcspn(destino, "\n");
    if (destino[posicao] == '\0')
    {
        c = getchar();
        while (c != '\n' && c != EOF)
        {
            c = getchar();
        }
    }
    else
    {
        destino[posicao] = '\0';
    }
}

int ler_numero(int *numero)
{
    char linha[TAM_BUFFER];
    ler_string(linha, TAM_BUFFER);
    if (sscanf(linha, "%d", numero) == 1)
    {
        return 1;
    }
    return 0;
}

void exibir_menu(void)
{
    printf("\n===== SAFECONSOLE C =====\n");
    printf("1 - Mascarar dados\n");
    printf("2 - Validar senha\n");
    printf("3 - Cifrar com Cesar\n");
    printf("4 - Descifrar com Cesar\n");
    printf("5 - Cifrar com XOR (saida em hexadecimal)\n");
    printf("6 - ROT13 (extra)\n");
    printf("7 - Codigos ASCII do texto (extra)\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}

void mascarar_dados(char *dados)
{
    int tamanho = (int)strlen(dados);
    int i;

    /* Evita comportamento indefinido se a entrada for menor ou igual a 4 caracteres */
    if (tamanho <= 4)
    {
        for (i = 0; i < tamanho; i++)
        {
            dados[i] = '*';
        }
        return;
    }

    for (i = 0; i < tamanho - 4; i++)
    {
        dados[i] = '*';
    }
}

int validar_senha(const char *senha)
{
    int tamanho = strlen(senha);
    int i;
    int tem_maiuscula = 0;
    int tem_minuscula = 0;
    int tem_numero = 0;

    if (tamanho < 8)
    {
        return 0;
    }

    for (i = 0; i < tamanho; i++)
    {
        if (senha[i] >= 'A' && senha[i] <= 'Z')
        {
            tem_maiuscula = 1;
        }
        if (senha[i] >= 'a' && senha[i] <= 'z')
        {
            tem_minuscula = 1;
        }
        if (senha[i] >= '0' && senha[i] <= '9')
        {
            tem_numero = 1;
        }
    }

    if (tem_maiuscula == 1 && tem_minuscula == 1 && tem_numero == 1)
    {
        return 1;
    }

    return 0;
}

void mostrar_forca_senha(const char *senha)
{
}

void cifrar_cesar(char *texto, int deslocamento)
{
    int tamanho;
    int i;
    deslocamento = ((deslocamento % 26) + 26) % 26;
    tamanho = strlen(texto);

    for (i = 0; i < tamanho; i++)
    {
        if (texto[i] >= 'A' && texto[i] <= 'Z')
        {
            texto[i] = (texto[i] - 'A' + deslocamento) % 26 + 'A';
        }
        else if (texto[i] >= 'a' && texto[i] <= 'z')
        {
            texto[i] = (texto[i] - 'a' + deslocamento) % 26 + 'a';
        }
    }
}

void descifrar_cesar(char *texto, int deslocamento)
{
    int tamanho;
    int i;
    deslocamento = ((deslocamento % 26) + 26) % 26;
    tamanho = strlen(texto);

    for (i = 0; i < tamanho; i++)
    {
        if (texto[i] >= 'A' && texto[i] <= 'Z')
        {
            texto[i] = (texto[i] - 'A' - deslocamento + 26) % 26 + 'A';
        }
        else if (texto[i] >= 'a' && texto[i] <= 'z')
        {
            texto[i] = (texto[i] - 'a' - deslocamento + 26) % 26 + 'a';
        }
    }
}

void aplicar_rot13(char *texto)
{
 cifrar_cesar(texto, 13);
}

void cifrar_xor(char *texto, int tamanho, char chave)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        texto[i] = texto[i] ^ chave;
    }
}

void exibir_hex(const char *texto, int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        printf("%02X ", (unsigned char)texto[i]);
    }
    printf("\n");
}

void exibir_codigos_ascii(const char *texto)
{
    int i;
    int tamanho;
    tamanho = strlen(texto);
    for (i = 0; i < tamanho; i++){
    printf("%c = %d\n", texto[i], (unsigned char)texto[i]);
 }
}
