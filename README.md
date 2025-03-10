# Minishell



## Sobre o Projeto

O **Minishell** é um projeto desenvolvido em dupla na 42 Rio, com o objetivo de recriar um interpretador de comandos Unix minimalista, similar ao Bash. Esse projeto permite a execução de comandos simples, manipulação de processos e redirecionamento de entrada e saída.

O foco do projeto é aprofundar os conhecimentos em **C**, manipulação de **processos**, **pipes**, **redirecionamento de entrada e saída**, **sinais**, **gestão de memória** e **execução de comandos**.

### Regras da 42 Rio

- Cada linha de código pode ter no máximo **80 caracteres**.
- Cada função pode ter no máximo **25 linhas**.
- Cada arquivo pode conter no máximo **5 funções**.

## Funcionalidades

- Implementa um prompt interativo semelhante ao Bash.
- Suporte a comandos internos (**echo, cd, pwd, export, unset, env, exit**).
- Suporte à execução de comandos externos via **execve**.
- Manipulação de variáveis de ambiente.
- Suporte a operadores lógicos (`&&`, `||` e `;`).
- Suporte a pipes (`|`) e redirecionamento de entrada/saída (`<`, `>` e `>>`).
- Tratamento de sinais (`Ctrl+C`, `Ctrl+D`, `Ctrl+\`).

## Como Compilar e Executar

### Requisitos

- **GCC**
- **Make**

### Instalação

```bash
# Clone o repositório
git clone https://github.com/rubens-maldonado/minishell.git
cd minishell

# Compile o projeto
make

# Execute o Minishell
./minishell
```

## Exemplo de Uso

```bash
$ ./minishell
minishell$ echo "Hello, World!"
Hello, World!
minishell$ ls -l | grep minishell
minishell$ export VAR="42Rio"
minishell$ echo $VAR
42Rio
minishell$ exit
```

## Estrutura do Projeto

```bash
minishell/
├── include/            # Arquivos de cabeçalho
│   ├── libft.h
│   ├── commands.h
│   ├── executor.h
│   ├── expanse.h
│   ├── lexer.h
│   ├── minishell.h
│   ├── parse.h
├── src/                # Arquivos fonte
│   ├── executor/
│   │   ├── builtins/
│   │   │   ├── cd.c
│   │   │   ├── commands.c
│   │   │   ├── echo.c
│   │   │   ├── env.c
│   │   │   ├── env_2.c
│   │   │   ├── export.c
│   │   │   ├── pwd.c
│   │   │   ├── unset.c
│   │   ├── check_dir.c
│   │   ├── executor.c
│   │   ├── executor2.c
│   │   ├── heredoc.c
│   │   ├── pipex.c
│   │   ├── redirects.c
│   │   ├── redirects_2.c
│   │   ├── redirects_utils.c
│   ├── expanser/
│   │   ├── expanser.c
│   │   ├── expanser_path.c
│   │   ├── expanser_str.c
│   │   ├── quotes.c
│   │   ├── simple_quotes.c
│   ├── lexer/
│   │   ├── token.c
│   ├── parse/
│   │   ├── parse.c
│   ├── utils/
│   │   ├── free.c
│   │   ├── free2.c
│   │   ├── utils.c
│   ├── signals.c
│   ├── start.c
├── Makefile            # Script de compilação
├── README.md           # Documentação do projeto
```

## Autores

- **Rubens Maldonado** - [GitHub](https://github.com/rubens-maldonado)
- **[João Vitor]** - [[GitHub](https://github.com/vitorsantanna2)]


