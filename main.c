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
int main(void)
{
 char texto[TAM_BUFFER];
 int opcao;
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
 if (validar_senha(texto) == 1){
     printf("Senha valida\n");
 }
 else{
     printf("Senha invalida\n");
 }
 mostrar_forca_senha(texto);
 break;
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
 printf("0 - Sair\n");
 printf("Escolha uma opcao: ");
}

void mascarar_dados(char *dados)
{
}

int validar_senha(const char *senha)
{
    return 0;
}

void mostrar_forca_senha(const char *senha)
{
}

void cifrar_cesar(char *texto, int deslocamento)
{
}

void descifrar_cesar(char *texto, int deslocamento)
{
}

void aplicar_rot13(char *texto)
{
}

void cifrar_xor(char *texto, int tamanho, char chave)
{
}

void exibir_hex(const char *texto, int tamanho)
{
}

void exibir_codigos_ascii(const char *texto)
{
}
