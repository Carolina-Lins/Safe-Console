# Safe-Console C
Projeto prático AV1 de Algoritmos e Estrutura de Dados (Segurança da Informação): ferramenta de linha de comando em C para sanitizaçãoo de dados, cifragem simétrica e registro de logs de auditoria.
## Integrantes
- Jessica do Carmo
- Maria Carolina
- Mina Cordeiro 
## Como compilar
```
gcc main.c -o safe_console
```
## Como executar
```
./safe_console
```
No Windows, use safe_console.exe.
## Funcionalidades
- Leitura segura de texto com fgets, sem risco de buffer overflow;
- Mascaramento de dados sensiveis, mantendo visiveis os 4 últimos caracteres;
- Validador de senha forte (8 caracteres, maiúscula, minúscula e numero);
- Cifra de Cesar com cifragem e descifragem;
- Cifra XOR com chave char e exibição do payload em hexadecimal;
- Menu interativo com do-while e switch;
## Funcionalidades extras
- Classificação da força da senha (Fraca, Média ou Forte);
- ROT13;
- Exibiçãp dos códigos ASCII de um texto.
